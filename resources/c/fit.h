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
// Product = 'SDK'
// Alignment = '4'
////////////////////////////////////////////////////////////////////////////////


#if !defined(FIT_H)
#define FIT_H

#include "fit_config.h"

#if defined(__cplusplus)
   extern "C" {
#endif


///////////////////////////////////////////////////////////////////////
// Version
///////////////////////////////////////////////////////////////////////

#define FIT_PROTOCOL_VERSION_MAJOR           1 // Non-backwards compatible changes. Decode compatible with this version and earlier.
#define FIT_PROTOCOL_VERSION_MINOR           0 // Backwards compatible changes.
#define FIT_PROTOCOL_VERSION_MAJOR_SHIFT     4
#define FIT_PROTOCOL_VERSION_MAJOR_MASK      ((FIT_UINT8) (0x0F << FIT_PROTOCOL_VERSION_MAJOR_SHIFT))
#define FIT_PROTOCOL_VERSION_MINOR_MASK      ((FIT_UINT8) 0x0F)
#define FIT_PROTOCOL_VERSION                 ((FIT_UINT8) (FIT_PROTOCOL_VERSION_MAJOR << FIT_PROTOCOL_VERSION_MAJOR_SHIFT) | FIT_PROTOCOL_VERSION_MINOR)      

#define FIT_PROFILE_VERSION_MAJOR            1
#define FIT_PROFILE_VERSION_MINOR            0
#define FIT_PROFILE_VERSION_SCALE			 100
#define FIT_PROFILE_VERSION					 ((FIT_UINT16) (FIT_PROFILE_VERSION_MAJOR * 100 + FIT_PROFILE_VERSION_MINOR))


///////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_ANTFS_FILE_DATA_TYPE    128

#define FIT_BASE_TYPE_ENDIAN_FLAG   ((FIT_UINT8)0x80)
#define FIT_BASE_TYPE_RESERVED      ((FIT_UINT8)0x60)
#define FIT_BASE_TYPE_NUM_MASK      ((FIT_UINT8)0x1F)

typedef unsigned char FIT_ENUM;
#define FIT_ENUM_INVALID            ((FIT_ENUM)0xFF)
#define FIT_BASE_TYPE_ENUM          ((FIT_UINT8)0x00)

typedef signed char FIT_SINT8;
#define FIT_SINT8_INVALID           ((FIT_SINT8)0x7F)
#define FIT_BASE_TYPE_SINT8         ((FIT_UINT8)0x01)

typedef unsigned char FIT_UINT8;
#define FIT_UINT8_INVALID           ((FIT_UINT8)0xFF)
#define FIT_BASE_TYPE_UINT8         ((FIT_UINT8)0x02)

typedef signed short FIT_SINT16;
#define FIT_SINT16_INVALID          ((FIT_SINT16)0x7FFF)
#define FIT_BASE_TYPE_SINT16        ((FIT_UINT8)0x83)

typedef unsigned short FIT_UINT16;
#define FIT_UINT16_INVALID   ((FIT_UINT16)0xFFFF)
#define FIT_BASE_TYPE_UINT16 ((FIT_UINT8)0x84)

typedef signed long FIT_SINT32;
#define FIT_SINT32_INVALID   ((FIT_SINT32)0x7FFFFFFF)
#define FIT_BASE_TYPE_SINT32 ((FIT_UINT8)0x85)

typedef unsigned long FIT_UINT32;
#define FIT_UINT32_INVALID   ((FIT_UINT32)0xFFFFFFFF)
#define FIT_BASE_TYPE_UINT32 ((FIT_UINT8)0x86)
                                                                            
typedef char FIT_STRING; // UTF-8 null terminated string
#define FIT_STRING_INVALID   ((FIT_STRING)0x00)
#define FIT_BASE_TYPE_STRING ((FIT_UINT8)0x07)

typedef float FIT_FLOAT32;
#define FIT_FLOAT32_INVALID   ((FIT_FLOAT32)0xFFFFFFFF)
#define FIT_BASE_TYPE_FLOAT32 ((FIT_UINT8)0x88)

typedef double FIT_FLOAT64;
#define FIT_FLOAT64_INVALID   ((FIT_FLOAT64)0xFFFFFFFFFFFFFFFFull)
#define FIT_BASE_TYPE_FLOAT64 ((FIT_UINT8)0x89)

typedef unsigned char FIT_UINT8Z;
#define FIT_UINT8Z_INVALID   ((FIT_UINT8Z)0x00)
#define FIT_BASE_TYPE_UINT8Z ((FIT_UINT8)0x0A)

typedef unsigned short FIT_UINT16Z;
#define FIT_UINT16Z_INVALID   ((FIT_UINT16Z)0x0000)
#define FIT_BASE_TYPE_UINT16Z ((FIT_UINT8)0x8B)

typedef unsigned long FIT_UINT32Z;
#define FIT_UINT32Z_INVALID   ((FIT_UINT32Z)0x00000000)
#define FIT_BASE_TYPE_UINT32Z ((FIT_UINT8)0x8C)

typedef unsigned char FIT_BYTE;
#define FIT_BYTE_INVALID   ((FIT_BYTE)0xFF) // Field is invalid if all bytes are invalid.
#define FIT_BASE_TYPE_BYTE ((FIT_UINT8)0x0D)

#define FIT_BASE_TYPES    14

typedef FIT_ENUM FIT_BOOL;
#define FIT_BOOL_INVALID      FIT_ENUM_INVALID
#define FIT_BOOL_FALSE        ((FIT_BOOL)0)
#define FIT_BOOL_TRUE         ((FIT_BOOL)1)
#define FIT_FALSE             FIT_BOOL_FALSE
#define FIT_TRUE              FIT_BOOL_TRUE
#define FIT_NULL              ((void *) 0)

typedef FIT_UINT32 (*FIT_READ_BYTES_FUNC)(void *, FIT_UINT32, FIT_UINT32);
#define FIT_MESG_DEF_HEADER_SIZE  FIT_STRUCT_OFFSET(fields, FIT_MESG_DEF)


///////////////////////////////////////////////////////////////////////
// File Header
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT8 header_size; // FIT_FILE_HDR_SIZE (size of this structure)
   FIT_UINT8 protocol_version; // FIT_PROTOCOL_VERSION
   FIT_UINT16 profile_version; // FIT_PROFILE_VERSION
   FIT_UINT32 data_size; // Does not include file header or crc.  Little endian format.
   FIT_UINT8 data_type[4]; // ".FIT"
} FIT_FILE_HDR;

#define FIT_FILE_HDR_SIZE         12

///////////////////////////////////////////////////////////////////////
// Record Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_HDR_SIZE               1
#define FIT_HDR_TIME_REC_BIT      ((FIT_UINT8) 0x80)
#define FIT_HDR_TIME_TYPE_MASK    ((FIT_UINT8) 0x60)
#define FIT_HDR_TIME_TYPE_SHIFT   5
#define FIT_HDR_TIME_OFFSET_MASK  ((FIT_UINT8) 0x1F)
#define FIT_HDR_TYPE_DEF_BIT      ((FIT_UINT8) 0x40)
#define FIT_HDR_TYPE_MASK         ((FIT_UINT8) 0x0F)
#define FIT_MAX_LOCAL_MESGS       (FIT_HDR_TYPE_MASK + 1)


///////////////////////////////////////////////////////////////////////
// Message Definitions
///////////////////////////////////////////////////////////////////////

typedef struct
{
   FIT_UINT8 field_def_num;
   FIT_UINT8 size;
   FIT_UINT8 base_type;
} FIT_FIELD_DEF;

#define FIT_FIELD_DEF_SIZE  3

typedef struct
{
   FIT_UINT8 reserved_1;
   FIT_UINT8 arch;
   FIT_UINT16 global_mesg_num;
   FIT_UINT8 num_fields;
   FIT_UINT8 fields[1];
} FIT_MESG_DEF;

#define FIT_MAX_MESG_SIZE         ((FIT_UINT8)255)

#define FIT_ARCH_ENDIAN_MASK      ((FIT_UINT8)0x01)
#define FIT_ARCH_ENDIAN_LITTLE    ((FIT_UINT8)0)
#define FIT_ARCH_ENDIAN_BIG       ((FIT_UINT8)1)


///////////////////////////////////////////////////////////////////////
// Field Definitions
///////////////////////////////////////////////////////////////////////

#define FIT_MAX_FIELD_SIZE             ((FIT_UINT8)255)
#define FIT_FIELD_NUM_INVALID          ((FIT_UINT8)0xFF)
#define FIT_MESSAGE_INDEX_FIELD_NUM    ((FIT_UINT8)254)
#define FIT_TIMESTAMP_FIELD_NUM        ((FIT_UINT8)253)


///////////////////////////////////////////////////////////////////////
// Macros
///////////////////////////////////////////////////////////////////////

#define FIT_STRUCT_OFFSET(MEMBER, STRUCT_TYPE)                                 ( ((FIT_UINT8 *) &(((STRUCT_TYPE *) FIT_NULL)->MEMBER)) - ((FIT_UINT8 *) (FIT_NULL)) ) // Computes the byte offset of a member in a file.  Compiles to a constant.

// Offset of message in file, not including file header.
#define FIT_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE)              (FIT_STRUCT_OFFSET(MESG_MEMBER, FILE) + MESG_INDEX * (FIT_HDR_SIZE + MESG_SIZE) + FIT_HDR_SIZE) // Computes the byte offset of a message in a file structure.  Compiles to a constant.
#define FIT_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE)                             (FIT_STRUCT_OFFSET(MESG_DEF_MEMBER, FILE) + FIT_HDR_SIZE) // Computes the byte offset of a message definition in a file structure.  Compiles to a constant.
#define FIT_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX)                   (FIT_STRUCT_OFFSET(FIELD_MEMBER, FIT_FIELD_DEF) + FIT_FIELD_DEF_SIZE * FIELD_INDEX) // Computes the byte offset of a field definition member.  Compiles to a constant.

// Offset of message in file including file header.
#define FIT_FILE_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE)         (FIT_FILE_HDR_SIZE + FIT_MESG_OFFSET(MESG_MEMBER, MESG_INDEX, MESG_SIZE, FILE))
#define FIT_FILE_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE)                        (FIT_MESG_DEF_OFFSET(MESG_DEF_MEMBER, FILE))
#define FIT_FILE_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX)              (FIT_MESG_DEF_FIELD_OFFSET(FIELD_MEMBER, FIELD_INDEX))


///////////////////////////////////////////////////////////////////////
// Public Constants
///////////////////////////////////////////////////////////////////////

const extern FIT_UINT8 fit_base_type_sizes[FIT_BASE_TYPES];
const extern FIT_UINT8 *fit_base_type_invalids[FIT_BASE_TYPES];


///////////////////////////////////////////////////////////////////////
// Public Functions
///////////////////////////////////////////////////////////////////////

FIT_UINT8 Fit_GetArch(void);
///////////////////////////////////////////////////////////////////////
// Returns architecture type.
// Includes runtime check for little or big endian.
// See FIT_MESG_DEF->arch and FIT_ARCH_*.
///////////////////////////////////////////////////////////////////////

const FIT_MESG_DEF *Fit_GetMesgDef(FIT_UINT16 global_mesg_num);
///////////////////////////////////////////////////////////////////////
// Returns message definition corresponding to global message number.
///////////////////////////////////////////////////////////////////////

FIT_UINT16 Fit_GetMesgDefSize(const FIT_MESG_DEF *mesg_def);
///////////////////////////////////////////////////////////////////////
// Returns the size of message definition.
///////////////////////////////////////////////////////////////////////

FIT_UINT8 Fit_GetMesgSize(FIT_UINT16 global_mesg_num);
///////////////////////////////////////////////////////////////////////
// Returns the size of message corresponding to global message number.
///////////////////////////////////////////////////////////////////////

FIT_BOOL Fit_InitMesg(const FIT_MESG_DEF *mesg_def, void *mesg);
///////////////////////////////////////////////////////////////////////
// Initializes message with invalids.
// Returns 1 if successful, otherwise 0.
///////////////////////////////////////////////////////////////////////

FIT_UINT8 Fit_GetFieldOffset(const FIT_MESG_DEF *mesg_def, FIT_UINT8 field_def_num);
///////////////////////////////////////////////////////////////////////
// Returns the byte offset of a field in a message.
///////////////////////////////////////////////////////////////////////

FIT_FIELD_DEF Fit_GetFieldDef(const FIT_MESG_DEF *mesg_def, FIT_UINT8 field_def_num);
///////////////////////////////////////////////////////////////////////
// Returns the definition for a field in a message.
// field_def_num is set to FIT_FIELD_NUM_INVALID if field is not found in message.
///////////////////////////////////////////////////////////////////////

FIT_UINT8 Fit_LookupMessage(FIT_UINT16 global_mesg_num, FIT_UINT16 message_index, FIT_UINT32 *offset, FIT_READ_BYTES_FUNC read_bytes_func);
///////////////////////////////////////////////////////////////////////
// Finds the byte offset of a message with the given message index in a FIT file
// Requires a pointer to a function which can read a given number of bytes from a provided offset in a FIT file.
// Returns the local message number if successful, or FIT_UINT8_INVALID if unsuccessful.
///////////////////////////////////////////////////////////////////////

#if defined(__cplusplus)
   }
#endif

#endif // !defined(FIT_H)
