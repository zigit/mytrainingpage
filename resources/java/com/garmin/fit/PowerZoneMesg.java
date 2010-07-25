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


public class PowerZoneMesg extends Mesg {


   public PowerZoneMesg() {
      super(Factory.createMesg(MesgNum.POWER_ZONE));
   }

   public PowerZoneMesg(final Mesg mesg) {
      super(mesg);
   }
   
   /**
    * Get message_index field
    *
    * @return message_index
    */
   public Integer getMessageIndex() {
      return getFieldIntegerValue(254);
   }

   /**
    * Set message_index field
    *
    * @param messageIndex
    */
   public void setMessageIndex(Integer messageIndex) {
      setFieldValue("message_index", messageIndex);
   }   
   /**
    * Get high_value field
    * Units: watts
    *
    * @return high_value
    */
   public Integer getHighValue() {
      return getFieldIntegerValue(1);
   }

   /**
    * Set high_value field
    * Units: watts
    *
    * @param highValue
    */
   public void setHighValue(Integer highValue) {
      setFieldValue("high_value", highValue);
   }   
   /**
    * Get name field
    *
    * @return name
    */
   public String getName() {
      return getFieldStringValue(2);
   }

   /**
    * Set name field
    *
    * @param name
    */
   public void setName(String name) {
      setFieldValue("name", name);
   }

}
