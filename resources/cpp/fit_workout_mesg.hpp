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


#if !defined(FIT_WORKOUT_MESG_HPP)
#define FIT_WORKOUT_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class WorkoutMesg : public Mesg
{
   public:
      WorkoutMesg(void) : Mesg(Profile::MESG_WORKOUT)
      {
      }

      WorkoutMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns sport field
      ///////////////////////////////////////////////////////////////////////
      FIT_SPORT GetSport(void)
      {
         return GetFieldENUMValue(4);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set sport field
      ///////////////////////////////////////////////////////////////////////
      void SetSport(FIT_SPORT sport)
      {
         SetFieldENUMValue(4, sport);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns capabilities field
      ///////////////////////////////////////////////////////////////////////
      FIT_WORKOUT_CAPABILITIES GetCapabilities(void)
      {
         return GetFieldUINT32ZValue(5);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set capabilities field
      ///////////////////////////////////////////////////////////////////////
      void SetCapabilities(FIT_WORKOUT_CAPABILITIES capabilities)
      {
         SetFieldUINT32ZValue(5, capabilities);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns num_valid_steps field
      // Comment: number of valid steps
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetNumValidSteps(void)
      {
         return GetFieldUINT16Value(6);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set num_valid_steps field
      // Comment: number of valid steps
      ///////////////////////////////////////////////////////////////////////
      void SetNumValidSteps(FIT_UINT16 numValidSteps)
      {
         SetFieldUINT16Value(6, numValidSteps);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns wkt_name field
      ///////////////////////////////////////////////////////////////////////
      string GetWktName(void)
      {
         return GetFieldSTRINGValue(8);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set wkt_name field
      ///////////////////////////////////////////////////////////////////////
      void SetWktName(string wktName)
      {
         SetFieldSTRINGValue(8, wktName);
      }

};

} // namespace fit

#endif // !defined(FIT_WORKOUT_MESG_HPP)
