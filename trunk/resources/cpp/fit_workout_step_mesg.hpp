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


#if !defined(FIT_WORKOUT_STEP_MESG_HPP)
#define FIT_WORKOUT_STEP_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class WorkoutStepMesg : public Mesg
{
   public:
      WorkoutStepMesg(void) : Mesg(Profile::MESG_WORKOUT_STEP)
      {
      }

      WorkoutStepMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns message_index field
      ///////////////////////////////////////////////////////////////////////
      FIT_MESSAGE_INDEX GetMessageIndex(void)
      {
         return GetFieldUINT16Value(254);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set message_index field
      ///////////////////////////////////////////////////////////////////////
      void SetMessageIndex(FIT_MESSAGE_INDEX messageIndex)
      {
         SetFieldUINT16Value(254, messageIndex);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns wkt_step_name field
      ///////////////////////////////////////////////////////////////////////
      string GetWktStepName(void)
      {
         return GetFieldSTRINGValue(0);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set wkt_step_name field
      ///////////////////////////////////////////////////////////////////////
      void SetWktStepName(string wktStepName)
      {
         SetFieldSTRINGValue(0, wktStepName);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns duration_type field
      ///////////////////////////////////////////////////////////////////////
      FIT_WKT_STEP_DURATION GetDurationType(void)
      {
         return GetFieldENUMValue(1);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set duration_type field
      ///////////////////////////////////////////////////////////////////////
      void SetDurationType(FIT_WKT_STEP_DURATION durationType)
      {
         SetFieldENUMValue(1, durationType);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns duration_value field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetDurationValue(void)
      {
         return GetFieldUINT32Value(2);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set duration_value field
      ///////////////////////////////////////////////////////////////////////
      void SetDurationValue(FIT_UINT32 durationValue)
      {
         SetFieldUINT32Value(2, durationValue);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns target_type field
      ///////////////////////////////////////////////////////////////////////
      FIT_WKT_STEP_TARGET GetTargetType(void)
      {
         return GetFieldENUMValue(3);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set target_type field
      ///////////////////////////////////////////////////////////////////////
      void SetTargetType(FIT_WKT_STEP_TARGET targetType)
      {
         SetFieldENUMValue(3, targetType);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns target_value field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetTargetValue(void)
      {
         return GetFieldUINT32Value(4);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set target_value field
      ///////////////////////////////////////////////////////////////////////
      void SetTargetValue(FIT_UINT32 targetValue)
      {
         SetFieldUINT32Value(4, targetValue);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns custom_target_value_low field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetCustomTargetValueLow(void)
      {
         return GetFieldUINT32Value(5);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set custom_target_value_low field
      ///////////////////////////////////////////////////////////////////////
      void SetCustomTargetValueLow(FIT_UINT32 customTargetValueLow)
      {
         SetFieldUINT32Value(5, customTargetValueLow);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns custom_target_value_high field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetCustomTargetValueHigh(void)
      {
         return GetFieldUINT32Value(6);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set custom_target_value_high field
      ///////////////////////////////////////////////////////////////////////
      void SetCustomTargetValueHigh(FIT_UINT32 customTargetValueHigh)
      {
         SetFieldUINT32Value(6, customTargetValueHigh);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns intensity field
      ///////////////////////////////////////////////////////////////////////
      FIT_INTENSITY GetIntensity(void)
      {
         return GetFieldENUMValue(7);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set intensity field
      ///////////////////////////////////////////////////////////////////////
      void SetIntensity(FIT_INTENSITY intensity)
      {
         SetFieldENUMValue(7, intensity);
      }

};

} // namespace fit

#endif // !defined(FIT_WORKOUT_STEP_MESG_HPP)
