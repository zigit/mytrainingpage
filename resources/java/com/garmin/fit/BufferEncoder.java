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

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.util.List;

/**
 * Encodes message objects into a FIT binary file buffer.
 */
public class BufferEncoder implements MesgListener, MesgDefinitionListener {
   private ByteArrayOutputStream byteOutStream;
   private DataOutputStream dataOutStream;
   private MesgDefinition lastMesgDefinition[] = new MesgDefinition[Fit.MAX_LOCAL_MESGS];
   private int dataSize;

   public BufferEncoder() {
      byteOutStream = new ByteArrayOutputStream();
      dataOutStream = new DataOutputStream(byteOutStream);
      open();
   }
   
   /**
    * Resets the output stream and writes the file header.
    */
   public void open() {
      byteOutStream.reset();
      dataSize = 0;
      writeFileHeader();      
   }

   /**
    * Writes the file header. 
    */
   private void writeFileHeader() {
      byteOutStream.write(Fit.FILE_HDR_SIZE);
      byteOutStream.write(Fit.PROTOCOL_VERSION);
      byteOutStream.write(Fit.PROFILE_VERSION & 0xFF);
      byteOutStream.write(Fit.PROFILE_VERSION >> 8);
      byteOutStream.write(0); // Data size.
      byteOutStream.write(0);
      byteOutStream.write(0);
      byteOutStream.write(0);
      byteOutStream.write('.');
      byteOutStream.write('F');
      byteOutStream.write('I');
      byteOutStream.write('T');
   }

   /**
    * MesgListener interface. 
    */
   public void onMesg(Mesg mesg) {
      write(mesg);
   }

   /**
    * MesgDefinitionListener interface. 
    */
   public void onMesgDefinition(MesgDefinition mesgDefinition) {
      write(mesgDefinition);
   }
   
   /**
    * Writes a message definition to the buffer.
    * Does not write if the same message is already defined in the file.
    * 
    * @param mesgDefinition
    *           message definition object to write
    */
   public void write(MesgDefinition mesgDefinition) {
      if (!mesgDefinition.equals(lastMesgDefinition[mesgDefinition.localNum])) {
         lastMesgDefinition[mesgDefinition.localNum] = mesgDefinition;
         dataSize += mesgDefinition.write(dataOutStream);
      }
   }
   
   /**
    * Writes a message to the buffer.
    * 
    * @param mesg
    *           message object to write
    */
   public void write(Mesg mesg) {
      write(new MesgDefinition(mesg));
      dataSize += mesg.write(dataOutStream);
   }

   /**
    * Writes a list of messages to the file.
    * 
    * @param mesgs
    *           list message objects to write
    */
   public void write(List<Mesg> mesgs) {
      for (Mesg mesg : mesgs) {
         write(mesg);
      }
   }

   /**
    * Updates the data size in the file header, writes the CRC, and returns the buffer.
    * The output stream buffer is discarded and re-initialized to start encoding a new file.
    * 
    * @return file buffer
    */
   public byte[] close() {

      // Write two dummy bytes as place holder for the CRC.
      byteOutStream.write(0);
      byteOutStream.write(0);

      // Get the buffer of the file.
      byte[] buffer = byteOutStream.toByteArray();
      
      // Set the data size in the file header.
      buffer[4] = (byte) (dataSize & 0xFF);
      buffer[5] = (byte) ((dataSize >> 8) & 0xFF);
      buffer[6] = (byte) ((dataSize >> 16) & 0xFF);
      buffer[7] = (byte) ((dataSize >> 24) & 0xFF);

      // Compute the CRC.
      int crc = 0;
      dataSize += Fit.FILE_HDR_SIZE;
      for (int i = 0; i < dataSize; i++) {
         crc = CRC.get16(crc, buffer[i]);
      }

      // Set the CRC in the file buffer.
      buffer[dataSize++] = (byte) (crc & 0xFF);
      buffer[dataSize++] = (byte) ((crc >> 8) & 0xFF);

      // Discard the output stream and re-initialize.
      open();
      
      return buffer;
   }
}
