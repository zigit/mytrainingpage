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

import java.io.DataOutput;
import java.util.ArrayList;

public class MesgDefinition {
   protected int num;
   protected int localNum;
   protected int arch;
   protected ArrayList<FieldDefinition> fields;

   protected MesgDefinition() {
      num = MesgNum.INVALID;
      localNum = 0;
      arch = Fit.ARCH_ENDIAN_BIG;
      fields = new ArrayList<FieldDefinition>(); 
    }
   
   public MesgDefinition(final Mesg mesg) {
      num = mesg.num;
      localNum = mesg.localNum;
      arch = Fit.ARCH_ENDIAN_BIG;

      if (localNum >= Fit.MAX_LOCAL_MESGS)
         throw new FitRuntimeException("Invalid local message number " + localNum + ".  Local message number must be < " + Fit.MAX_LOCAL_MESGS + ".");
      
      fields = new ArrayList<FieldDefinition>();
      
      for (Field field : mesg.fields) {
         fields.add(new FieldDefinition(field));
      }
   }
   
   public int getNum() {
      return num;
   }

   public int getLocalNum() {
      return localNum;
   }
   
   public int getArch() {
      return arch;
   }
   
   public ArrayList<FieldDefinition> getFields() {
      return fields;
   }
   
   public int write(DataOutput out) {
      int mesg_size = 6;

      try {
         out.writeByte(Fit.HDR_TYPE_DEF_BIT | (localNum & Fit.HDR_TYPE_MASK)); // Message definition record header.
         out.writeByte(0); // Reserved
         out.writeByte(Fit.ARCH_ENDIAN_BIG);
         out.writeShort(num);
         out.writeByte(fields.size());
      } catch (java.io.IOException e) {
         return 0;
      }

      for (FieldDefinition field : fields) {
         int field_size = field.write(out);

         if (field_size == 0)
            return 0;

         mesg_size += field_size;
      }

      return mesg_size;
   }
   
   public boolean equals(Object o) {
      if (this == o)
         return true;

      if (!(o instanceof MesgDefinition))
         return false;
      
      MesgDefinition other = (MesgDefinition)o;
      
      if (num != other.num)
         return false;
      
      if (localNum != other.localNum)
         return false;
      
      if (!fields.equals(other.fields))
         return false;
      
      return true;
   }
   
   public int hashCode() {
      int hashCode = 1;
      
      hashCode = (hashCode * 31) + new Integer(num).hashCode();
      hashCode = (hashCode * 47) + new Integer(localNum).hashCode();
      hashCode = (hashCode * 19) + fields.hashCode();
      
      return hashCode;
   }
}
