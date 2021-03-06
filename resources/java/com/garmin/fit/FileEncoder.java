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

import java.io.File;
import java.io.RandomAccessFile;
import java.util.List;

/**
 * Encodes message objects into a FIT binary file.
 * 
 */
public class FileEncoder implements MesgListener, MesgDefinitionListener {
   private RandomAccessFile file;
   private MesgDefinition lastMesgDefinition[] = new MesgDefinition[Fit.MAX_LOCAL_MESGS];
   private long dataSize;

   public FileEncoder() {
   }

   public FileEncoder(File file) {
      open(file);
   }

   /**
    * Opens file for writing. If the file already exists it will be overwritten.
    * 
    * @param file
    *           file to write
    */
   public void open(File file) {
      try {
         file.delete();
         this.file = new RandomAccessFile(file, "rw");
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      }

      dataSize = 0;
      writeFileHeader();
   }

   /**
    * Writes the file header. 
    */
   private void writeFileHeader() {
      if (file == null)
         throw new FitRuntimeException("File not open.");

      try {
         file.seek(0);
         file.writeByte(Fit.FILE_HDR_SIZE);
         file.writeByte(Fit.PROTOCOL_VERSION);
         file.writeByte(Fit.PROFILE_VERSION & 0xFF);
         file.writeByte(Fit.PROFILE_VERSION >> 8);
         file.writeByte((int) (dataSize & 0xFF));
         file.writeByte((int) ((dataSize >> 8) & 0xFF));
         file.writeByte((int) ((dataSize >> 16) & 0xFF));
         file.writeByte((int) ((dataSize >> 24) & 0xFF));
         file.writeByte('.');
         file.writeByte('F');
         file.writeByte('I');
         file.writeByte('T');
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      }
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
    * Writes a message definition to the file.
    * Does not write if the same message is already defined in the file.
    * 
    * @param mesgDefinition
    *           message definition object to write
    */
   public void write(MesgDefinition mesgDefinition) {
      if (file == null)
         throw new FitRuntimeException("File not open.");

      if (!mesgDefinition.equals(lastMesgDefinition[mesgDefinition.localNum])) {
         lastMesgDefinition[mesgDefinition.localNum] = mesgDefinition;
         dataSize += mesgDefinition.write(file);
      }
   }
   
   /**
    * Writes a message to the file.
    * 
    * @param mesg
    *           message object to write
    */
   public void write(Mesg mesg) {
      if (file == null)
         throw new FitRuntimeException("File not open.");

      write(new MesgDefinition(mesg));
      dataSize += mesg.write(file);
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
    * Updates the data size in the file header, writes the CRC, and closes the file.
    */
   public void close() {
      if (file == null)
         throw new FitRuntimeException("File not open.");

      // Set the data size in the file header.
      writeFileHeader();
      dataSize += Fit.FILE_HDR_SIZE;

      try {
         if (dataSize != file.length()) {
            throw new FitRuntimeException("Invalid file length " + file.length() + ". Expected" + dataSize + ".");
         }

         // Compute the CRC.
         file.seek(0);
         int crc = 0;
         for (int i = 0; i < dataSize; i++) {
            crc = CRC.get16(crc, (byte) file.read());
         }

         // Write the CRC.
         file.writeByte((int) (crc & 0xFF));
         file.writeByte((int) ((crc >> 8) & 0xFF));

         file.close();
      } catch (java.io.IOException e) {
         throw new FitRuntimeException(e);
      }
   }
}
