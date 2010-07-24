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


package com.garmin.fit.csv;

import com.garmin.fit.*;

import java.util.Collection;
import java.util.Iterator;

public class MesgCSVWriter implements MesgListener, MesgDefinitionListener {
   private CSVWriter csv;

   public MesgCSVWriter(String fileName) {
      this.csv = new CSVWriter(fileName);
   }

   public void close() {
      csv.close();
   }

   public void onMesgDefinition(MesgDefinition mesgDef) {
      Collection<FieldDefinition> fields = mesgDef.getFields();
      Iterator<FieldDefinition> fieldsIterator;
      int fieldNum;
      Mesg mesg = Factory.createMesg(mesgDef.getNum());

      csv.clear();
      csv.set("Type", "Definition");
      csv.set("Local Number", mesgDef.getLocalNum());

      if (mesg == null)
      {
         csv.set("Message", "unknown");
      }
      else
      {
         csv.set("Message", mesg.getName());
      }
      
      fieldNum = 0;
      fieldsIterator = fields.iterator();
      
      while (fieldsIterator.hasNext()) {
         FieldDefinition fieldDef = fieldsIterator.next();
         Field field = Factory.createField(mesgDef.getNum(), fieldDef.getNum());
         fieldNum++;
         
         if (field == null)
         {
            csv.set("Field " + fieldNum, "unknown");
         }
         else
         {
            csv.set("Field " + fieldNum, field.getName());
         }

         csv.set("Value " + fieldNum, fieldDef.getSize() / Fit.baseTypeSizes[fieldDef.getType() & Fit.BASE_TYPE_NUM_MASK]);
         csv.set("Units " + fieldNum, "");
      }

      csv.writeln();
   }
   
   public void onMesg(Mesg mesg) {
      Collection<Field> fields = mesg.getFields();
      Iterator<Field> fieldsIterator;
      int fieldNum;
      
      csv.clear();
      csv.set("Type", "Data");
      csv.set("Local Number", mesg.getLocalNum());
      csv.set("Message", mesg.getName());

      fieldNum = 0;
      fieldsIterator = fields.iterator();
      
      while (fieldsIterator.hasNext()) {
         Field field = fieldsIterator.next();

         fieldNum++;
         
         csv.set("Field " + fieldNum, field.getName());

         String value = field.getStringValue(0);
         for (int fieldElement = 1; fieldElement < field.getNumValues(); fieldElement++) {
            value += "|" + field.getStringValue(fieldElement);
         }
         csv.set("Value " + fieldNum, value);

         csv.set("Units " + fieldNum, field.getUnits());
      }

      csv.writeln();
   }
}
