////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2008 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 1.0Release
// Tag = $Name: AKW1_000 $
////////////////////////////////////////////////////////////////////////////////


package com.garmin.fit;

import java.util.ArrayList;
import java.io.ByteArrayInputStream;
import java.io.InputStream;

/**
 * Decodes binary to java objects.
 * 
 */
public class Decode {
   // Public Variables
   public enum RETURN {
      CONTINUE, MESG, MESG_DEF, END_OF_FILE
   }

   // Private Variables
   private enum STATE {
      FILE_HDR, RECORD, RESERVED1, ARCH, MESG_NUM_0, MESG_NUM_1, NUM_FIELDS, FIELD_NUM, FIELD_SIZE, FIELD_TYPE, FIELD_DATA, FILE_CRC_HIGH
   }

   private class AccumulatedField {
      int mesgNum;
      int fieldNum;
      int componentNum;
      long lastValue;
      long accumulatedValue;

      AccumulatedField(int mesgNum, int fieldNum, int componentNum) {
         this.mesgNum = mesgNum;
         this.fieldNum = fieldNum;
         this.componentNum = componentNum;
         this.lastValue = 0;
         this.accumulatedValue = 0;
      }

      public long accumulate(long value, int bits) {
         long mask = ((long) 1 << bits) - 1;

         accumulatedValue += (value - lastValue) & mask;
         lastValue = value;

         return accumulatedValue;
      }
   }

   private class Accumulator {
      ArrayList<AccumulatedField> fields;

      Accumulator() {
         fields = new ArrayList<AccumulatedField>();
      }

      public long accumulate(int mesgNum, int fieldNum, int componentNum, long value, int bits) {
         AccumulatedField field = null;
         int i;

         for (i = 0; i < fields.size(); i++) {
            field = fields.get(i);

            if ((field.mesgNum == mesgNum) && (field.fieldNum == fieldNum) && (field.componentNum == componentNum))
               break;
         }

         if (i == fields.size()) {
            field = new AccumulatedField(mesgNum, fieldNum, componentNum);
            fields.add(field);
         }

         return field.accumulate(value, bits);

      }
   }

   private STATE state;
   private byte fileHdrOffset;
   private byte fileHdrSize;
   private long fileDataSize;
   private long fileBytesLeft;
   private int crc;
   private Mesg mesg;
   private int localMesgIndex;
   private MesgDefinition localMesgDefs[] = new MesgDefinition[Fit.MAX_LOCAL_MESGS];
   private int numFields;
   private int fieldIndex;
   private int fieldDataIndex;
   private int fieldBytesLeft;
   private byte fieldData[] = new byte[Fit.MAX_FIELD_SIZE];
   private int lastTimeOffset;
   private long timestamp;
   private long systemTimeOffset;
   private Accumulator accumulator = new Accumulator();
   private boolean pause;
   private InputStream in;
   private ArrayList<MesgListener> mesgListeners = new ArrayList<MesgListener>();
   private ArrayList<MesgDefinitionListener> mesgDefListeners = new ArrayList<MesgDefinitionListener>();
   

   public Decode() {
      fileBytesLeft = 3; // Header byte + CRC.
      fileHdrOffset = 0;
      crc = 0;
      state = STATE.FILE_HDR;
      lastTimeOffset = 0;
      systemTimeOffset = 0;
      pause = false;

      if (Fit.debug) {
         System.out.printf("Fit.Decode: Starting decode...\n");
      }
   }
   
   public void addListener(MesgListener mesgListener) {
      if ((mesgListener != null) && !mesgListeners.contains(mesgListener))
         mesgListeners.add(mesgListener);      
   }
   
   public void addListener(MesgDefinitionListener mesgDefinitionListener) {
      if ((mesgDefinitionListener != null) && !mesgDefListeners.contains(mesgDefinitionListener))
         mesgDefListeners.add(mesgDefinitionListener);      
   }

   public void setSystemTimeOffset(long systemTimeOffset) {
      this.systemTimeOffset = systemTimeOffset;
   }

   /**
    * Reads a FIT binary file.
    * 
    * @param in
    *           file input stream
    * @param mesgListener
    *           message listener
    * @return true if finished reading file
    */
   public boolean read(final InputStream in, final MesgListener mesgListener) {
      addListener(mesgListener);
      return read(in);
   }
   
   public boolean read(final InputStream in) {
      this.in = in;
      return resume();
   }

   public void pause() {
      pause = true;
   }

   /**
    * Resumes reading the file.
    * 
    * @return true if finished reading file
    */
   public boolean resume() {
      int data;

      pause = false;

      try {
         while ((data = in.read()) >= 0) {
            if (pause)
               return false;

            Decode.RETURN decodeReturn = read((byte) data);

            switch (decodeReturn) {
               case CONTINUE:
                  break;

               case MESG:
                  for (MesgListener mesgListener : mesgListeners)
                  {
                     mesgListener.onMesg(mesg);
                  }
                  break;

               case MESG_DEF:
                  for (MesgDefinitionListener mesgDefListener : mesgDefListeners)
                  {
                     mesgDefListener.onMesgDefinition(localMesgDefs[localMesgIndex]);
                  }
                  break;

               case END_OF_FILE:
                  return true;

               default:
                  throw new FitRuntimeException("FIT decode error: " + decodeReturn);
            }
         }
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      }

      throw new FitRuntimeException("FIT decode error: Unexpected end of input stream.");
   }

   /**
    * Reads the header to detirmine if the file is FIT.
    * 
    * @param in
    *           file input stream
    * 
    * @return true if file is FIT
    */
   static public boolean isFit(final InputStream in) {
      Decode decode = new Decode();
      int data;

      try {
         while ((data = in.read()) >= 0) {
            switch (decode.read((byte) data)) {
               case CONTINUE:
               case MESG:
               case MESG_DEF:
                  break;

               case END_OF_FILE:
                  return true;

               default:
                  return false;
            }
            
            if (decode.state != STATE.FILE_HDR)
               return true;
         }
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      } catch (FitRuntimeException e) {
         // Fall through and return as not FIT.
      }

      return false;
   }

   /**
    * Reads the FIT binary file header and crc to check compatibility and integrity.
    * 
    * @param in
    *           file input stream
    * 
    * @return true if file is ok (not corrupt)
    */
   static public boolean checkIntegrity(final InputStream in) {
      Decode decode = new Decode();
      int data;

      try {
         while ((data = in.read()) >= 0) {
            switch (decode.read((byte) data)) {
               case CONTINUE:
               case MESG:
               case MESG_DEF:
                  break;

               case END_OF_FILE:
                  return true;

               default:
                  return false;
            }
         }
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      } catch (FitRuntimeException e) {
         // Fall through and return integrity failure.
      }

      
      return false;
   }

   public RETURN read(byte data) {
      if (Fit.debug) {
         if (fileBytesLeft == 2)
            System.out.printf("Fit.Decode: Expecting next 2 bytes to be end of file CRC = 0x%04X\n", crc);

         System.out.printf("Fit.Decode: 0x%02X - %s\n", data & 0xFF, state.toString());
      }

      if (fileBytesLeft > 0) {
         crc = CRC.get16(crc, data);

         fileBytesLeft--;

         if (fileBytesLeft == 1) // CRC low byte.
         {
            if (state != STATE.RECORD) {
               throw new FitRuntimeException("FIT decode error: Decoder not in correct state after last data byte in file.  Check message definitions.");
            }

            return RETURN.CONTINUE; // Next byte.
         } else if (fileBytesLeft == 0) // CRC high byte.
         {
            if (crc != 0) {
               throw new FitRuntimeException("FIT decode error: File CRC failed.");
            }

            return RETURN.END_OF_FILE;
         }
      }

      switch (state) {
         case FILE_HDR:
            switch (fileHdrOffset++) {
               case 0:
                  fileHdrSize = data;
                  fileBytesLeft = fileHdrSize + 2;
                  break;
               case 1:
                  if ((data & Fit.PROTOCOL_VERSION_MAJOR_MASK) > (Fit.PROTOCOL_VERSION_MAJOR << Fit.PROTOCOL_VERSION_MAJOR_SHIFT)) {
                     throw new FitRuntimeException("FIT decode error: Protocol version " + ((data & Fit.PROTOCOL_VERSION_MAJOR_MASK) >> Fit.PROTOCOL_VERSION_MAJOR_SHIFT) + "." + (data & Fit.PROTOCOL_VERSION_MINOR_MASK) + " not supported.  Must be " + Fit.PROTOCOL_VERSION_MAJOR + ".15 or earlier.");
                  }
                  break;
               case 4:
                  fileDataSize = data & 0xFF;
                  break;
               case 5:
                  fileDataSize |= (long) (data & 0xFF) << 8;
                  break;
               case 6:
                  fileDataSize |= (long) (data & 0xFF) << 16;
                  break;
               case 7:
                  fileDataSize |= (long) (data & 0xFF) << 24;
                  break;
               case 8:
                  if (data != '.') {
                     throw new FitRuntimeException("FIT decode error: File is not FIT format.  Check file header data type.");
                  }
                  break;
               case 9:
                  if (data != 'F') {
                     throw new FitRuntimeException("FIT decode error: File is not FIT format.  Check file header data type.");
                  }
                  break;
               case 10:
                  if (data != 'I') {
                     throw new FitRuntimeException("FIT decode error: File is not FIT format.  Check file header data type.");
                  }
                  break;
               case 11:
                  if (data != 'T') {
                     throw new FitRuntimeException("FIT decode error: File is not FIT format.  Check file header data type.");
                  }
                  break;
               default:
                  break;
            }

            if (fileHdrOffset == fileHdrSize) {
               fileBytesLeft = fileDataSize + 2; // include crc
               state = STATE.RECORD;
            }
            break;

         case RECORD:
            fieldIndex = 0;
            fieldBytesLeft = 0;

            if (fileBytesLeft > 1) {
               if ((data & Fit.HDR_TIME_REC_BIT) != 0) {
                  Field timestampField = Factory.createField("record", "timestamp");
                  int timeOffset = data & Fit.HDR_TIME_OFFSET_MASK;

                  timestamp += (timeOffset - lastTimeOffset) & Fit.HDR_TIME_OFFSET_MASK;
                  lastTimeOffset = timeOffset;
                  timestampField.setValue(timestamp);

                  localMesgIndex = (data & Fit.HDR_TIME_TYPE_MASK) >> Fit.HDR_TIME_TYPE_SHIFT;

                  if (localMesgDefs[localMesgIndex] == null) {
                     throw new FitRuntimeException("FIT decode error: Missing message definition for local message number " + localMesgIndex + ".");
                  }

                  mesg = Factory.createMesg(localMesgDefs[localMesgIndex].num);
                  mesg.localNum = localMesgIndex;
                  mesg.systemTimeOffset = systemTimeOffset;
                  mesg.addField(timestampField);

                  if (localMesgDefs[localMesgIndex].fields.size() == 0)
                     return RETURN.MESG;

                  state = STATE.FIELD_DATA;
               } else {
                  localMesgIndex = data & Fit.HDR_TYPE_MASK;

                  if ((data & Fit.HDR_TYPE_DEF_BIT) != 0) {
                     localMesgDefs[localMesgIndex] = new MesgDefinition();
                     localMesgDefs[localMesgIndex].localNum = localMesgIndex;
                     state = STATE.RESERVED1;
                  
                  } else {
                     if (localMesgDefs[localMesgIndex] == null) {
                        throw new FitRuntimeException("FIT decode error: Missing message definition for local message number " + localMesgIndex + ".");
                     }

                     mesg = Factory.createMesg(localMesgDefs[localMesgIndex].num);
                     mesg.localNum = localMesgIndex;
                     mesg.systemTimeOffset = systemTimeOffset;
                     
                     if (localMesgDefs[localMesgIndex].fields.size() == 0)
                        return RETURN.MESG;

                     state = STATE.FIELD_DATA;
                  }
               }
            } else {
               // We just got the low byte of the crc.
               state = STATE.FILE_CRC_HIGH;
            }
            break;

         case RESERVED1:
            state = STATE.ARCH;
            break;

         case ARCH:
            localMesgDefs[localMesgIndex].arch = ((int) data & 0xFF);
            state = STATE.MESG_NUM_0;
            break;

         case MESG_NUM_0:
            // Read the global message number bytes in as if they are in little
            // endian format.
            localMesgDefs[localMesgIndex].num = ((int) data & 0xFF);
            state = STATE.MESG_NUM_1;
            break;

         case MESG_NUM_1:
            localMesgDefs[localMesgIndex].num |= (((int) data & 0xFF) << 8);

            // We have to check for endianness.
            if (localMesgDefs[localMesgIndex].arch == Fit.ARCH_ENDIAN_BIG) {
               localMesgDefs[localMesgIndex].num = (localMesgDefs[localMesgIndex].num >> 8) | ((localMesgDefs[localMesgIndex].num & 0xFF) << 8);
            } else if (localMesgDefs[localMesgIndex].arch != Fit.ARCH_ENDIAN_LITTLE) {
               throw new FitRuntimeException("FIT decode error: Endian " + localMesgDefs[localMesgIndex].arch + " not supported.");
            }

            state = STATE.NUM_FIELDS;
            break;

         case NUM_FIELDS:
            numFields = ((int) data & 0xFF);

            if (numFields == 0) {
               state = STATE.RECORD;
               break;
            }

            state = STATE.FIELD_NUM;
            break;

         case FIELD_NUM:
            localMesgDefs[localMesgIndex].fields.add(new FieldDefinition());
            localMesgDefs[localMesgIndex].fields.get(fieldIndex).num = ((int) data & 0xFF);
            state = STATE.FIELD_SIZE;
            break;

         case FIELD_SIZE:
            localMesgDefs[localMesgIndex].fields.get(fieldIndex).size = ((int) data & 0xFF);
            state = STATE.FIELD_TYPE;
            break;

         case FIELD_TYPE:
            localMesgDefs[localMesgIndex].fields.get(fieldIndex).type = ((int) data & 0xFF);

            if (++fieldIndex >= numFields) {
               state = STATE.RECORD;
               return RETURN.MESG_DEF;
            } else {
               state = STATE.FIELD_NUM;
            }
            break;

         case FIELD_DATA: {
            FieldDefinition fieldDef = localMesgDefs[localMesgIndex].fields.get(fieldIndex);

            if (fieldBytesLeft == 0) {
               fieldDataIndex = 0;
               fieldBytesLeft = fieldDef.size;
            }

            fieldData[fieldDataIndex++] = data;
            fieldBytesLeft--;

            if (fieldBytesLeft == 0) {
               Field field;
               int typeSize;
               int elements;

               if ((fieldDef.type & Fit.BASE_TYPE_NUM_MASK) < Fit.BASE_TYPES) { // Ignore field if base type not supported.
                  typeSize = Fit.baseTypeSizes[(fieldDef.type & Fit.BASE_TYPE_NUM_MASK)];
                  elements = fieldDef.size / typeSize;
   
                  if (((fieldDef.type & Fit.BASE_TYPE_ENDIAN_FLAG) != 0) && ((localMesgDefs[localMesgIndex].arch & Fit.ARCH_ENDIAN_MASK) != Fit.ARCH_ENDIAN_BIG)) {
                     // Swap the bytes for each element.
                     for (int element = 0; element < elements; element++) {
                        for (int i = 0; i < (typeSize / 2); i++) {
                           byte tmp = fieldData[element * typeSize + i];
                           fieldData[element * typeSize + i] = fieldData[element * typeSize + typeSize - i - 1];
                           fieldData[element * typeSize + typeSize - i - 1] = tmp;
                        }
                     }
                  }
   
                  field = Factory.createField(mesg.num, fieldDef.num);
   
                  if (field != null) {
                     field.read(new ByteArrayInputStream(fieldData), fieldDef.size);
   
                     if (fieldDef.num == Fit.TIMESTAMP_FIELD_NUM) {
                        Long fieldTimestamp = field.getLongValue();
   
                        if (fieldTimestamp != null) {
                           timestamp = fieldTimestamp.longValue();
                           lastTimeOffset = (int) (timestamp & Fit.HDR_TIME_OFFSET_MASK);
                        }
                     }
   
                     if (field.getNumValues() > 0) {
                        if (field.components.size() > 0) {
                           int offset = 0;
                           int i;
   
                           for (i = 0; i < field.components.size(); i++) {
                              FieldComponent component = field.components.get(i);
                              
                              if (component.fieldNum != Fit.FIELD_NUM_INVALID) {
                                 Field componentField = Factory.createField(mesg.num, component.fieldNum);
                                 Long bitsValue;
                                 Double value;
      
                                 bitsValue = field.getBitsValue(offset, component.bits, componentField.isSignedInteger());
      
                                 if (bitsValue == null)
                                    break; // No more data for components.
      
                                 if (component.accumulate)
                                    bitsValue = accumulator.accumulate(mesg.num, field.num, i, bitsValue, component.bits);
      
                                 value = (((bitsValue / component.scale) - component.offset) + componentField.offset) * componentField.scale;
      
                                 if (mesg.hasField(componentField.num)) {
                                    mesg.getField(componentField.num).addValue(value);
                                 } else {
                                    componentField.addValue(value);
                                    mesg.addField(componentField);
                                 }
                              }
                              
                              offset += component.bits;
                           }
                        }
                        
                        mesg.addField(field);
                     }
                  }
               }
               
               fieldIndex++;
            
               if (fieldIndex >= localMesgDefs[localMesgIndex].fields.size()) {
                  Factory.mapSubFields(mesg);
                  state = STATE.RECORD;
                  return RETURN.MESG;
               }
            }
            break;
         }

         default:
            break;
      }

      return RETURN.CONTINUE;
   }

   public Mesg getMesg() {
      return mesg;
   }
}
