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


#if !defined(FIT_FILE_CAPABILITIES_MESG_HPP)
#define FIT_FILE_CAPABILITIES_MESG_HPP

#include "fit_mesg.hpp"

namespace fit
{

class FileCapabilitiesMesg : public Mesg
{
   public:
      FileCapabilitiesMesg(void) : Mesg(Profile::MESG_FILE_CAPABILITIES)
      {
      }

      FileCapabilitiesMesg(const Mesg &mesg) : Mesg(mesg)
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
      // Returns type field
      ///////////////////////////////////////////////////////////////////////
      FIT_FILE GetType(void)
      {
         return GetFieldENUMValue(0);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set type field
      ///////////////////////////////////////////////////////////////////////
      void SetType(FIT_FILE type)
      {
         SetFieldENUMValue(0, type);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns flags field
      ///////////////////////////////////////////////////////////////////////
      FIT_FILE_FLAGS GetFlags(void)
      {
         return GetFieldUINT8ZValue(1);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set flags field
      ///////////////////////////////////////////////////////////////////////
      void SetFlags(FIT_FILE_FLAGS flags)
      {
         SetFieldUINT8ZValue(1, flags);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns directory field
      ///////////////////////////////////////////////////////////////////////
      string GetDirectory(void)
      {
         return GetFieldSTRINGValue(2);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set directory field
      ///////////////////////////////////////////////////////////////////////
      void SetDirectory(string directory)
      {
         SetFieldSTRINGValue(2, directory);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_count field
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT16 GetMaxCount(void)
      {
         return GetFieldUINT16Value(3);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_count field
      ///////////////////////////////////////////////////////////////////////
      void SetMaxCount(FIT_UINT16 maxCount)
      {
         SetFieldUINT16Value(3, maxCount);
      }

      ///////////////////////////////////////////////////////////////////////
      // Returns max_size field
      // Units: bytes
      ///////////////////////////////////////////////////////////////////////
      FIT_UINT32 GetMaxSize(void)
      {
         return GetFieldUINT32Value(4);
      }

      ///////////////////////////////////////////////////////////////////////
      // Set max_size field
      // Units: bytes
      ///////////////////////////////////////////////////////////////////////
      void SetMaxSize(FIT_UINT32 maxSize)
      {
         SetFieldUINT32Value(4, maxSize);
      }

};

} // namespace fit

#endif // !defined(FIT_FILE_CAPABILITIES_MESG_HPP)
