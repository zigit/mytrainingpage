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


#if !defined(FIT_FILE_CREATOR_MESG_HPP)
#define FIT_FILE_CREATOR_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class FileCreatorMesg : public Mesg
{
   public:
      FileCreatorMesg(void) : Mesg(Profile::MESG_FILE_CREATOR)
      {
      }

      FileCreatorMesg(const Mesg &mesg) : Mesg(mesg)
      {
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns software_version field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetSoftwareVersion(void)
      {
         return GetFieldUINT16Value(0);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set software_version field
      ///////////////////////////////////////////////////////////////////////
      void SetSoftwareVersion(FIT_UINT16 softwareVersion)
      {
         SetFieldUINT16Value(0, softwareVersion);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns hardware_version field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT8 GetHardwareVersion(void)
      {
         return GetFieldUINT8Value(1);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set hardware_version field
      ///////////////////////////////////////////////////////////////////////
      void SetHardwareVersion(FIT_UINT8 hardwareVersion)
      {
         SetFieldUINT8Value(1, hardwareVersion);
      }

};

} // namespace fit

#endif // !defined(FIT_FILE_CREATOR_MESG_HPP)
