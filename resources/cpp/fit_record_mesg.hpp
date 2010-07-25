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


#if !defined(FIT_RECORD_MESG_HPP)
#define FIT_RECORD_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class RecordMesg : public Mesg
{
   public:
      RecordMesg(void) : Mesg(Profile::MESG_RECORD)
      {
      }

      RecordMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      FIT_DATE_TIME GetTimestamp(void)
      {
         return GetFieldUINT32Value(253);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set timestamp field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      void SetTimestamp(FIT_DATE_TIME timestamp)
      {
         SetFieldUINT32Value(253, timestamp);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetPositionLat(void)
      {
         return GetFieldSINT32Value(0);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set position_lat field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetPositionLat(FIT_SINT32 positionLat)
      {
         SetFieldSINT32Value(0, positionLat);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT32 GetPositionLong(void)
      {
         return GetFieldSINT32Value(1);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set position_long field
      // Units: semicircles
      ///////////////////////////////////////////////////////////////////////
      void SetPositionLong(FIT_SINT32 positionLong)
      {
         SetFieldSINT32Value(1, positionLong);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns altitude field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetAltitude(void)
      {
         return GetFieldFLOAT32Value(2);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set altitude field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetAltitude(FIT_FLOAT32 altitude)
      {
         SetFieldFLOAT32Value(2, altitude);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetHeartRate(void)
      {
         return GetFieldUINT8Value(3);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set heart_rate field
      // Units: bpm
      ///////////////////////////////////////////////////////////////////////
      void SetHeartRate(FIT_UINT8 heartRate)
      {
         SetFieldUINT8Value(3, heartRate);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetCadence(void)
      {
         return GetFieldUINT8Value(4);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cadence field
      // Units: rpm
      ///////////////////////////////////////////////////////////////////////
      void SetCadence(FIT_UINT8 cadence)
      {
         SetFieldUINT8Value(4, cadence);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetDistance(void)
      {
         return GetFieldFLOAT32Value(5);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set distance field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetDistance(FIT_FLOAT32 distance)
      {
         SetFieldFLOAT32Value(5, distance);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetSpeed(void)
      {
         return GetFieldFLOAT32Value(6);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set speed field
      // Units: m/s
      ///////////////////////////////////////////////////////////////////////
      void SetSpeed(FIT_FLOAT32 speed)
      {
         SetFieldFLOAT32Value(6, speed);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetPower(void)
      {
         return GetFieldUINT16Value(7);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set power field
      // Units: watts
      ///////////////////////////////////////////////////////////////////////
      void SetPower(FIT_UINT16 power)
      {
         SetFieldUINT16Value(7, power);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns number of compressed_speed_distance
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetNumCompressedSpeedDistance(void)
      {
         return GetFieldNumValues(8);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns compressed_speed_distance field
      ///////////////////////////////////////////////////////////////////////
      FIT_BYTE GetCompressedSpeedDistance(FIT_UINT8 index)
      {
         return GetFieldBYTEValue(8, index);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set compressed_speed_distance field
      ///////////////////////////////////////////////////////////////////////
      void SetCompressedSpeedDistance(FIT_UINT8 index, FIT_BYTE compressedSpeedDistance)
      {
         SetFieldBYTEValue(8, compressedSpeedDistance, index);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns grade field
      // Units: %
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetGrade(void)
      {
         return GetFieldFLOAT32Value(9);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set grade field
      // Units: %
      ///////////////////////////////////////////////////////////////////////
      void SetGrade(FIT_FLOAT32 grade)
      {
         SetFieldFLOAT32Value(9, grade);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns resistance field
      // Comment: Relative. 0 is none  254 is Max.
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetResistance(void)
      {
         return GetFieldUINT8Value(10);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set resistance field
      // Comment: Relative. 0 is none  254 is Max.
      ///////////////////////////////////////////////////////////////////////
      void SetResistance(FIT_UINT8 resistance)
      {
         SetFieldUINT8Value(10, resistance);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns time_from_course field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetTimeFromCourse(void)
      {
         return GetFieldFLOAT32Value(11);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set time_from_course field
      // Units: s
      ///////////////////////////////////////////////////////////////////////
      void SetTimeFromCourse(FIT_FLOAT32 timeFromCourse)
      {
         SetFieldFLOAT32Value(11, timeFromCourse);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns cycle_length field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      FIT_FLOAT32 GetCycleLength(void)
      {
         return GetFieldFLOAT32Value(12);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set cycle_length field
      // Units: m
      ///////////////////////////////////////////////////////////////////////
      void SetCycleLength(FIT_FLOAT32 cycleLength)
      {
         SetFieldFLOAT32Value(12, cycleLength);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns temperature field
      // Units: °C
      ///////////////////////////////////////////////////////////////////////
      FIT_SINT8 GetTemperature(void)
      {
         return GetFieldSINT8Value(13);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set temperature field
      // Units: °C
      ///////////////////////////////////////////////////////////////////////
      void SetTemperature(FIT_SINT8 temperature)
      {
         SetFieldSINT8Value(13, temperature);
      }

};

} // namespace fit

#endif // !defined(FIT_RECORD_MESG_HPP)
