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


#include <sstream>

#include "fit_field.hpp"
#include "fit_mesg.hpp"

using namespace std;

namespace fit
{

Field::Field(void) :
   profile(NULL)
{
}

Field::Field(const Field &field) :
   profile(field.profile), profileIndex(field.profileIndex), values(field.values)
{
}

Field::Field(Profile::MESG_INDEX mesgIndex, FIT_UINT16 fieldIndex) :
   profile(&Profile::mesgs[mesgIndex]), profileIndex(fieldIndex)
{
}

Field::Field(FIT_UINT16 mesgNum, FIT_UINT8 fieldNum) :
   profile(Profile::GetMesg(mesgNum)), profileIndex(Profile::GetFieldIndex(mesgNum, fieldNum))
{
}

Field::Field(string mesgName, string fieldName) :
   profile(Profile::GetMesg(mesgName)), profileIndex(Profile::GetFieldIndex(mesgName, fieldName))
{
}

FIT_BOOL Field::IsValid(void)
{
   return profileIndex != FIT_UINT16_INVALID;
}

FIT_UINT16 Field::GetIndex(void)
{
   return profileIndex;
}

string Field::GetName(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return "unknown";
   return profile->fields[profileIndex].name;
}

FIT_UINT8 Field::GetNum(void) const
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return FIT_FIELD_NUM_INVALID;
   return profile->fields[profileIndex].num;
}

FIT_UINT8 Field::GetType(void) const
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return FIT_UINT8_INVALID;
   return profile->fields[profileIndex].type;
}

FIT_BOOL Field::IsSignedInteger(void)
{
   switch (GetType()) {
      case FIT_BASE_TYPE_SINT8:
      case FIT_BASE_TYPE_SINT16:
      case FIT_BASE_TYPE_SINT32:
         return FIT_TRUE;

      default:
         break;
   }

   return FIT_FALSE;
}

string Field::GetUnits(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return "";
   return profile->fields[profileIndex].units;
}

FIT_FLOAT32 Field::GetScale(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return 1;
   return profile->fields[profileIndex].scale;
}

FIT_FLOAT32 Field::GetOffset(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return 0;
   return profile->fields[profileIndex].offset;
}

FIT_UINT8 Field::GetNumComponents(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return 0;
   return profile->fields[profileIndex].numComponents;
}

const Profile::FIELD_COMPONENT* Field::GetComponent(FIT_UINT8 component)
{
   if (component >= GetNumComponents())
      return NULL;
   return &profile->fields[profileIndex].components[component];
}

FIT_UINT8 Field::GetSize(void) const
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return 0;

   return (FIT_UINT8) values.size() * baseTypeSizes[profile->fields[profileIndex].type & FIT_BASE_TYPE_NUM_MASK];
}

FIT_UINT8 Field::GetNumValues(void)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return 0;

   if ((profile->fields[profileIndex].type == FIT_BASE_TYPE_STRING) && (values.size() > 0))
      return 1; // String is array of characters values.

   return (FIT_UINT8) values.size();
}

FIT_UINT32 Field::GetBitsValue(FIT_UINT16 offset, FIT_UINT8 bits)
{
   FIT_UINT32 value = 0;
   FIT_UINT8 bitsInValue = 0;
   FIT_SINT16 bitsInData;
   FIT_UINT8 index = 0;
   FIT_UINT8 data;
   FIT_UINT8 mask;

   if (values.size() == 0)
      return FIT_UINT32_INVALID;

   while (bitsInValue < bits)
   {
      if (index >= values.size())
         return FIT_UINT32_INVALID;

      data = GetUINT8Value(index++);
      data >>= offset;
      bitsInData = 8 - offset;
      offset -= 8;

      if (bitsInData > 0)
      {
         offset = 0;

         if (bitsInData > (bits - bitsInValue))
            bitsInData = bits - bitsInValue;

         mask = (1 << bitsInData) - 1;
         value |= (FIT_UINT32)(data & mask) << bitsInValue;
         bitsInValue += bitsInData;
      }
   }

   return value;
}

FIT_SINT32 Field::GetBitsSignedValue(FIT_UINT16 offset, FIT_UINT8 bits)
{
   FIT_UINT32 value;
   FIT_SINT32 signedValue;

   value = GetBitsValue(offset, bits);

   if (value == FIT_UINT32_INVALID)
      return FIT_SINT32_INVALID;

   signedValue = (1L << (bits - 1));

   if ((value & signedValue) != 0) // sign bit set
   {
      signedValue = -signedValue + (value & (signedValue - 1));
   }
   else
   {
      signedValue = value;
   }

   return signedValue;
}

FIT_ENUM Field::GetENUMValue(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_ENUM)))
      return FIT_ENUM_INVALID;

   return values[index][0];
}

FIT_BYTE Field::GetBYTEValue(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_BYTE)))
      return FIT_BYTE_INVALID;

   return values[index][0];
}

FIT_SINT8 Field::GetSINT8Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_SINT8)))
      return FIT_SINT8_INVALID;

   return values[index][0];
}

FIT_UINT8 Field::GetUINT8Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT8)))
      return FIT_UINT8_INVALID;

   return values[index][0];
}

FIT_UINT8Z Field::GetUINT8ZValue(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT8Z)))
      return FIT_UINT8Z_INVALID;

   return values[index][0];
}

FIT_SINT16 Field::GetSINT16Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_SINT16)))
      return FIT_SINT16_INVALID;

   return ((FIT_SINT16) values[index][1] << 8) | values[index][0];
}

FIT_UINT16 Field::GetUINT16Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT16)))
      return FIT_UINT16_INVALID;

   return ((FIT_UINT16) values[index][1] << 8) | values[index][0];
}

FIT_UINT16Z Field::GetUINT16ZValue(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT16Z)))
      return FIT_UINT16Z_INVALID;

   return ((FIT_UINT16Z) values[index][1] << 8) | values[index][0];
}

FIT_SINT32 Field::GetSINT32Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_SINT32)))
      return FIT_SINT32_INVALID;

   return ((FIT_SINT32) values[index][3] << 24) | ((FIT_SINT32) values[index][2] << 16) | ((FIT_SINT32) values[index][1] << 8) | values[index][0];
}

FIT_UINT32 Field::GetUINT32Value(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT32)))
      return FIT_UINT32_INVALID;

   return ((FIT_UINT32) values[index][3] << 24) | ((FIT_UINT32) values[index][2] << 16) | ((FIT_UINT32) values[index][1] << 8) | values[index][0];
}

FIT_UINT32Z Field::GetUINT32ZValue(FIT_UINT8 index)
{
   if ((index >= values.size()) || (values[index].size() < sizeof(FIT_UINT32Z)))
      return FIT_UINT32Z_INVALID;

   return ((FIT_UINT32Z) values[index][3] << 24) | ((FIT_UINT32Z) values[index][2] << 16) | ((FIT_UINT32Z) values[index][1] << 8) | values[index][0];
}

FIT_FLOAT32 Field::GetFLOAT32Value(FIT_UINT8 index)
{
   FIT_FLOAT32 float32Value;

   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return FIT_FLOAT32_INVALID;

   switch (profile->fields[profileIndex].type) {
      case FIT_BASE_TYPE_BYTE:
         {
            FIT_BYTE byteValue = GetBYTEValue(index);

            if (byteValue == FIT_BYTE_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = byteValue;
            break;
         }

      case FIT_BASE_TYPE_ENUM:
         {
            FIT_ENUM enumValue = GetENUMValue(index);

            if (enumValue == FIT_ENUM_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = enumValue;
            break;
         }

      case FIT_BASE_TYPE_SINT8:
         {
            FIT_SINT8 sint8Value = GetSINT8Value(index);

            if (sint8Value == FIT_SINT8_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = sint8Value;
            break;
         }

      case FIT_BASE_TYPE_UINT8:
         {
            FIT_UINT8 uint8Value = GetUINT8Value(index);

            if (uint8Value == FIT_UINT8_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = uint8Value;
            break;
         }

      case FIT_BASE_TYPE_UINT8Z:
         {
            FIT_UINT8Z uint8zValue = GetUINT8ZValue(index);

            if (uint8zValue == FIT_UINT8Z_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = uint8zValue;
            break;
         }

      case FIT_BASE_TYPE_SINT16:
         {
            FIT_SINT16 sint16Value = GetSINT16Value(index);

            if (sint16Value == FIT_SINT16_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = sint16Value;
            break;
         }

      case FIT_BASE_TYPE_UINT16:
         {
            FIT_UINT16 uint16Value = GetUINT16Value(index);

            if (uint16Value == FIT_UINT16_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = uint16Value;
            break;
         }

      case FIT_BASE_TYPE_UINT16Z:
         {
            FIT_UINT16Z uint16zValue = GetUINT16ZValue(index);

            if (uint16zValue == FIT_UINT16Z_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = uint16zValue;
            break;
         }

      case FIT_BASE_TYPE_SINT32:
         {
            FIT_SINT32 sint32Value = GetSINT32Value(index);

            if (sint32Value == FIT_SINT32_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = (FIT_FLOAT32) sint32Value;
            break;
         }

      case FIT_BASE_TYPE_UINT32:
         {
            FIT_UINT32 uint32Value = GetUINT32Value(index);

            if (uint32Value == FIT_UINT32_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = (FIT_FLOAT32) uint32Value;
            break;
         }

      case FIT_BASE_TYPE_UINT32Z:
         {
            FIT_UINT32Z uint32zValue = GetUINT32ZValue(index);

            if (uint32zValue == FIT_UINT32Z_INVALID)
               return FIT_FLOAT32_INVALID;

            float32Value = (FIT_FLOAT32) uint32zValue;
            break;
         }

      case FIT_BASE_TYPE_FLOAT32:
         {
            FIT_SINT32 sint32Value = GetSINT32Value(index);

            if (sint32Value == FIT_SINT32_INVALID)
               return FIT_FLOAT32_INVALID;

            memcpy(&float32Value, &sint32Value, sizeof(FIT_FLOAT32));
            break;
         }

      case FIT_BASE_TYPE_FLOAT64:
         return (FIT_FLOAT32) GetFLOAT32Value(index);
         break;

      default:
         return FIT_FLOAT32_INVALID;
   }

   return float32Value / profile->fields[profileIndex].scale - profile->fields[profileIndex].offset;
}

FIT_FLOAT64 Field::GetFLOAT64Value(FIT_UINT8 index)
{
   FIT_FLOAT64 float64Value;

   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return FIT_FLOAT64_INVALID;

   switch (profile->fields[profileIndex].type) {
      case FIT_BASE_TYPE_BYTE:
         {
            FIT_BYTE byteValue = GetBYTEValue(index);

            if (byteValue == FIT_BYTE_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = byteValue;
            break;
         }

      case FIT_BASE_TYPE_ENUM:
         {
            FIT_ENUM enumValue = GetENUMValue(index);

            if (enumValue == FIT_ENUM_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = enumValue;
            break;
         }

      case FIT_BASE_TYPE_SINT8:
         {
            FIT_SINT8 sint8Value = GetSINT8Value(index);

            if (sint8Value == FIT_SINT8_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = sint8Value;
            break;
         }

      case FIT_BASE_TYPE_UINT8:
         {
            FIT_UINT8 uint8Value = GetUINT8Value(index);

            if (uint8Value == FIT_UINT8_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint8Value;
            break;
         }

      case FIT_BASE_TYPE_UINT8Z:
         {
            FIT_UINT8Z uint8zValue = GetUINT8ZValue(index);

            if (uint8zValue == FIT_UINT8Z_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint8zValue;
            break;
         }

      case FIT_BASE_TYPE_SINT16:
         {
            FIT_SINT16 sint16Value = GetSINT16Value(index);

            if (sint16Value == FIT_SINT16_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = sint16Value;
            break;
         }

      case FIT_BASE_TYPE_UINT16:
         {
            FIT_UINT16 uint16Value = GetUINT16Value(index);

            if (uint16Value == FIT_UINT16_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint16Value;
            break;
         }

      case FIT_BASE_TYPE_UINT16Z:
         {
            FIT_UINT16Z uint16zValue = GetUINT16ZValue(index);

            if (uint16zValue == FIT_UINT16Z_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint16zValue;
            break;
         }

      case FIT_BASE_TYPE_SINT32:
         {
            FIT_SINT32 sint32Value = GetSINT32Value(index);

            if (sint32Value == FIT_SINT32_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = sint32Value;
            break;
         }

      case FIT_BASE_TYPE_UINT32:
         {
            FIT_UINT32 uint32Value = GetUINT32Value(index);

            if (uint32Value == FIT_UINT32_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint32Value;
            break;
         }

      case FIT_BASE_TYPE_UINT32Z:
         {
            FIT_UINT32Z uint32zValue = GetUINT32ZValue(index);

            if (uint32zValue == FIT_UINT32Z_INVALID)
               return FIT_FLOAT64_INVALID;

            float64Value = uint32zValue;
            break;
         }

      case FIT_BASE_TYPE_FLOAT32:
         return (FIT_FLOAT64) GetFLOAT32Value(index);
         break;

      case FIT_BASE_TYPE_FLOAT64:
         {
            unsigned long long uint64Value;

            if ((index >= values.size()) || (values[index].size() < sizeof(FIT_FLOAT64)))
               return FIT_FLOAT64_INVALID;

            uint64Value = ((unsigned long long) values[index][7] << 56) | ((unsigned long long) values[index][6] << 48) | ((unsigned long long) values[index][5] << 40)
                  | ((unsigned long long) values[index][4] << 32) | ((unsigned long long) values[index][3] << 24) | ((unsigned long long) values[index][2] << 16)
                  | ((unsigned long long) values[index][1] << 8) | values[index][0];
            memcpy(&float64Value, &uint64Value, sizeof(FIT_FLOAT64));
            break;
         }

      default:
         return FIT_FLOAT64_INVALID;
   }

   return float64Value / profile->fields[profileIndex].scale - profile->fields[profileIndex].offset;
}

string Field::GetSTRINGValue(FIT_UINT8 index)
{
   string value;

   if ((profile == NULL) || (profileIndex >= profile->numFields) || (index >= values.size()))
      return "";

   if (profile->fields[profileIndex].type == FIT_BASE_TYPE_STRING)
   {
      FIT_UINT8 i = 0;

      i = 0;
      while ((i < values[index].size()) && (values[index][i] != 0))
      {
         value += values[index][i];
         i++;
      }
   }
   else
   {
      ostringstream valueStream;
      valueStream.precision(9);
      valueStream << GetFLOAT64Value(index);
      value = valueStream.str();
   }

   return value;
}

void Field::SetENUMValue(FIT_ENUM value, FIT_UINT8 index)
{
   SetUINT8Value(value, index);
}

void Field::SetBYTEValue(FIT_BYTE value, FIT_UINT8 index)
{
   SetUINT8Value(value, index);
}

void Field::SetSINT8Value(FIT_SINT8 value, FIT_UINT8 index)
{
   SetUINT8Value(value, index);
}

void Field::SetUINT8Value(FIT_UINT8 value, FIT_UINT8 index)
{
   while (values.size() <= index)
   {
      vector<FIT_BYTE> newValue;
      values.push_back(newValue);
   }

   values[index].clear();
   values[index].push_back((FIT_BYTE) value);
}

void Field::SetUINT8ZValue(FIT_UINT8 value, FIT_UINT8 index)
{
   SetUINT8Value(value, index);
}

void Field::SetSINT16Value(FIT_SINT16 value, FIT_UINT8 index)
{
   SetUINT16Value(value, index);
}

void Field::SetUINT16Value(FIT_UINT16 value, FIT_UINT8 index)
{
   while (values.size() <= index)
   {
      vector<FIT_BYTE> newValue;
      values.push_back(newValue);
   }

   values[index].clear();
   values[index].push_back((FIT_BYTE) value);
   values[index].push_back((FIT_BYTE)(value >> 8));
}

void Field::SetUINT16ZValue(FIT_UINT16Z value, FIT_UINT8 index)
{
   SetUINT16Value(value, index);
}

void Field::SetSINT32Value(FIT_SINT32 value, FIT_UINT8 index)
{
   SetUINT32Value(value, index);
}

void Field::SetUINT32Value(FIT_UINT32 value, FIT_UINT8 index)
{
   while (values.size() <= index)
   {
      vector<FIT_BYTE> newValue;
      values.push_back(newValue);
   }

   values[index].clear();
   values[index].push_back((FIT_BYTE) value);
   values[index].push_back((FIT_BYTE)(value >> 8));
   values[index].push_back((FIT_BYTE)(value >> 16));
   values[index].push_back((FIT_BYTE)(value >> 24));
}

void Field::SetUINT32ZValue(FIT_UINT32Z value, FIT_UINT8 index)
{
   SetUINT32Value(value, index);
}

void Field::SetFLOAT32Value(FIT_FLOAT32 value, FIT_UINT8 index)
{
   SetFLOAT64Value(value, index);
}

void Field::SetFLOAT64Value(FIT_FLOAT64 value, FIT_UINT8 index)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return;

   value = (value + profile->fields[profileIndex].offset) * profile->fields[profileIndex].scale;

   switch (profile->fields[profileIndex].type) {
      case FIT_BASE_TYPE_BYTE:
      case FIT_BASE_TYPE_ENUM:
      case FIT_BASE_TYPE_SINT8:
      case FIT_BASE_TYPE_UINT8:
      case FIT_BASE_TYPE_UINT8Z:
         SetUINT8Value((FIT_UINT8) value, index);
         break;

      case FIT_BASE_TYPE_SINT16:
      case FIT_BASE_TYPE_UINT16:
      case FIT_BASE_TYPE_UINT16Z:
         SetUINT16Value((FIT_UINT16) value, index);
         break;

      case FIT_BASE_TYPE_SINT32:
      case FIT_BASE_TYPE_UINT32:
      case FIT_BASE_TYPE_UINT32Z:
         SetUINT32Value((FIT_UINT32) value, index);
         break;

      case FIT_BASE_TYPE_FLOAT32:
         {
            FIT_FLOAT32 float32Value = (FIT_FLOAT32)value;
            FIT_UINT32 uint32Value;
            memcpy(&uint32Value, &float32Value, sizeof(FIT_FLOAT32));
            SetUINT32Value(uint32Value, index);
            break;
         }

      case FIT_BASE_TYPE_FLOAT64:
         while (values.size() <= index)
         {
            vector<FIT_BYTE> newValue;
            values.push_back(newValue);
         }

         values[index].clear();
         values[index].push_back(*((FIT_BYTE *) &value));
         values[index].push_back(*(((FIT_BYTE *) &value) + 1));
         values[index].push_back(*(((FIT_BYTE *) &value) + 2));
         values[index].push_back(*(((FIT_BYTE *) &value) + 3));
         values[index].push_back(*(((FIT_BYTE *) &value) + 4));
         values[index].push_back(*(((FIT_BYTE *) &value) + 5));
         values[index].push_back(*(((FIT_BYTE *) &value) + 6));
         values[index].push_back(*(((FIT_BYTE *) &value) + 7));
         break;

      default:
         break;
   }
}

void Field::SetSTRINGValue(string value, FIT_UINT8 index)
{
   if ((profile == NULL) || (profileIndex >= profile->numFields))
      return;

   if (profile->fields[profileIndex].type != FIT_BASE_TYPE_STRING)
      return;

   values[index].clear();

   for (int i = 0; i < (int) value.length(); i++)
   {
      values[index].push_back(value[i]);
   }

   values[index].push_back(0); // null terminate
}

FIT_BOOL Field::Read(const void *data, FIT_UINT8 size)
{
   int bytesLeft = size;
   FIT_UINT8 typeSize = baseTypeSizes[profile->fields[profileIndex].type & FIT_BASE_TYPE_NUM_MASK];
   FIT_BYTE *byteData = (FIT_BYTE *) data;

   values.clear();
   
   switch (profile->fields[profileIndex].type)
   {
      case FIT_BASE_TYPE_STRING:
         {
            vector<FIT_BYTE> value;

            while (bytesLeft-- > 0)
            {
               FIT_BYTE byte = *byteData++;

               if (byte == '\0')
                  break;

               value.push_back(byte);
            }

            values.push_back(value);
         }
         break;

      case FIT_BASE_TYPE_BYTE:
         {
            FIT_BOOL invalid = FIT_TRUE;

            while (bytesLeft-- > 0)
            {
               vector<FIT_BYTE> value;
               value.push_back(*byteData++);
               values.push_back(value);

               if (value[0] != FIT_BYTE_INVALID)
                  invalid = FIT_FALSE;
            }

            if (invalid)
               values.clear();
         }
         break;

      default:
         while (bytesLeft > 0)
         {
            if (memcmp(byteData, baseTypeInvalids[profile->fields[profileIndex].type & FIT_BASE_TYPE_NUM_MASK], typeSize) != 0)
            {
               vector<FIT_BYTE> value;

               for (int i = 0; i < typeSize; i++)
               {
                  value.push_back(*byteData++);
               }

               values.push_back(value);
            }
            bytesLeft -= typeSize;
         }
         break;
   }

   return FIT_TRUE;
}

FIT_UINT8 Field::Write(ostream &file)
{
   for (FIT_UINT8 valueIndex = 0; valueIndex < values.size(); valueIndex++)
   {
      for (FIT_UINT8 valueOffset = 0; valueOffset < values[valueIndex].size(); valueOffset++)
      {
         file.put(values[valueIndex][valueOffset]);
      }
   }

   return GetSize();
}

} // namespace fit
