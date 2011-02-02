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


public class FileIdMesg extends Mesg {


   public FileIdMesg() {
      super(Factory.createMesg(MesgNum.FILE_ID));
   }

   public FileIdMesg(final Mesg mesg) {
      super(mesg);
   }
   
   /**
    * Get type field
    *
    * @return type
    */
   public File getType() {
      Short value = getFieldShortValue(0);
     if (value == null)
        return null;
      return File.getByValue(value);
   }

   /**
    * Set type field
    *
    * @param type
    */
   public void setType(File type) {
      setFieldValue("type", type.value);
   }   
   /**
    * Get manufacturer field
    *
    * @return manufacturer
    */
   public Integer getManufacturer() {
      return getFieldIntegerValue(1);
   }

   /**
    * Set manufacturer field
    *
    * @param manufacturer
    */
   public void setManufacturer(Integer manufacturer) {
      setFieldValue("manufacturer", manufacturer);
   }   
   /**
    * Get product field
    *
    * @return product
    */
   public Integer getProduct() {
      return getFieldIntegerValue(2);
   }

   /**
    * Set product field
    *
    * @param product
    */
   public void setProduct(Integer product) {
      setFieldValue("product", product);
   }   
   /**
    * Get garmin_product field
    *
    * @return garmin_product
    */
   public Integer getGarminProduct() {
      return getFieldIntegerValue("garmin_product");
   }

   /**
    * Set garmin_product field
    *
    * @param garminProduct
    */
   public void setGarminProduct(Integer garminProduct) {
      setFieldValue("garmin_product", garminProduct);
   }   
   /**
    * Get serial_number field
    *
    * @return serial_number
    */
   public Long getSerialNumber() {
      return getFieldLongValue(3);
   }

   /**
    * Set serial_number field
    *
    * @param serialNumber
    */
   public void setSerialNumber(Long serialNumber) {
      setFieldValue("serial_number", serialNumber);
   }   
   /**
    * Get time_created field
    * Comment: Only set for files that are can be created/erased.
    *
    * @return time_created
    */
   public DateTime getTimeCreated() {
      return timestampToDateTime(getFieldLongValue(4));
   }

   /**
    * Set time_created field
    * Comment: Only set for files that are can be created/erased.
    *
    * @param timeCreated
    */
   public void setTimeCreated(DateTime timeCreated) {
      setFieldValue("time_created", timeCreated.getTimestamp());
   }   
   /**
    * Get number field
    * Comment: Only set for files that are not created/erased.
    *
    * @return number
    */
   public Integer getNumber() {
      return getFieldIntegerValue(5);
   }

   /**
    * Set number field
    * Comment: Only set for files that are not created/erased.
    *
    * @param number
    */
   public void setNumber(Integer number) {
      setFieldValue("number", number);
   }

}