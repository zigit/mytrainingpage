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


#include "string.h"
#include "fit_product.h"


///////////////////////////////////////////////////////////////////////
// Messages
///////////////////////////////////////////////////////////////////////

const static FIT_FILE_ID_MESG_DEF file_id_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_FILE_ID, // global_mesg_num
   6, // num_fields
   {
   // Def#, size,                                 base_type
        3, (sizeof(FIT_UINT32Z)*1), FIT_BASE_TYPE_UINT32Z,
        4, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        1, (sizeof(FIT_MANUFACTURER)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        5, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_FILE)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_FILE_CREATOR_MESG_DEF file_creator_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_FILE_CREATOR, // global_mesg_num
   2, // num_fields
   {
   // Def#, size,                                 base_type
        0, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_SOFTWARE_MESG_DEF software_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_SOFTWARE, // global_mesg_num
   3, // num_fields
   {
   // Def#, size,                                 base_type
        5, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
   }
};

const static FIT_CAPABILITIES_MESG_DEF capabilities_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_CAPABILITIES, // global_mesg_num
   1, // num_fields
   {
   // Def#, size,                                 base_type
       21, (sizeof(FIT_WORKOUT_CAPABILITIES)*1), FIT_BASE_TYPE_UINT32Z,
   }
};

const static FIT_FILE_CAPABILITIES_MESG_DEF file_capabilities_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_FILE_CAPABILITIES, // global_mesg_num
   6, // num_fields
   {
   // Def#, size,                                 base_type
        2, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
        4, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_FILE)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_FILE_FLAGS)*1), FIT_BASE_TYPE_UINT8Z,
   }
};

const static FIT_MESG_CAPABILITIES_MESG_DEF mesg_capabilities_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_MESG_CAPABILITIES, // global_mesg_num
   5, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_MESG_NUM)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_FILE)*1), FIT_BASE_TYPE_ENUM,
        2, (sizeof(FIT_MESG_COUNT)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_FIELD_CAPABILITIES_MESG_DEF field_capabilities_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_FIELD_CAPABILITIES, // global_mesg_num
   5, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_MESG_NUM)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_FILE)*1), FIT_BASE_TYPE_ENUM,
        2, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_DEVICE_SETTINGS_MESG_DEF device_settings_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_DEVICE_SETTINGS, // global_mesg_num
   1, // num_fields
   {
   // Def#, size,                                 base_type
        1, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
   }
};

const static FIT_USER_PROFILE_MESG_DEF user_profile_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_USER_PROFILE, // global_mesg_num
   19, // num_fields
   {
   // Def#, size,                                 base_type
        0, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        4, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_GENDER)*1), FIT_BASE_TYPE_ENUM,
        2, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        3, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        5, (sizeof(FIT_LANGUAGE)*1), FIT_BASE_TYPE_ENUM,
        6, (sizeof(FIT_DISPLAY_MEASURE)*1), FIT_BASE_TYPE_ENUM,
        7, (sizeof(FIT_DISPLAY_MEASURE)*1), FIT_BASE_TYPE_ENUM,
        8, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        9, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       10, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       11, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       12, (sizeof(FIT_DISPLAY_HEART)*1), FIT_BASE_TYPE_ENUM,
       13, (sizeof(FIT_DISPLAY_MEASURE)*1), FIT_BASE_TYPE_ENUM,
       14, (sizeof(FIT_DISPLAY_MEASURE)*1), FIT_BASE_TYPE_ENUM,
       16, (sizeof(FIT_DISPLAY_POWER)*1), FIT_BASE_TYPE_ENUM,
       17, (sizeof(FIT_ACTIVITY_CLASS)*1), FIT_BASE_TYPE_ENUM,
       18, (sizeof(FIT_DISPLAY_POSITION)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_HRM_PROFILE_MESG_DEF hrm_profile_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_HRM_PROFILE, // global_mesg_num
   3, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT16Z)*1), FIT_BASE_TYPE_UINT16Z,
        0, (sizeof(FIT_BOOL)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_ZONES_TARGET_MESG_DEF zones_target_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_ZONES_TARGET, // global_mesg_num
   5, // num_fields
   {
   // Def#, size,                                 base_type
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        2, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        5, (sizeof(FIT_HR_ZONE_CALC)*1), FIT_BASE_TYPE_ENUM,
        7, (sizeof(FIT_PWR_ZONE_CALC)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_SPORT_MESG_DEF sport_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_SPORT, // global_mesg_num
   3, // num_fields
   {
   // Def#, size,                                 base_type
        3, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
        0, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_SUB_SPORT)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_HR_ZONE_MESG_DEF hr_zone_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_HR_ZONE, // global_mesg_num
   3, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        2, (sizeof(FIT_STRING)*1), FIT_BASE_TYPE_STRING,
   }
};

const static FIT_POWER_ZONE_MESG_DEF power_zone_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_POWER_ZONE, // global_mesg_num
   3, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_STRING)*1), FIT_BASE_TYPE_STRING,
   }
};

const static FIT_MET_ZONE_MESG_DEF met_zone_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_MET_ZONE, // global_mesg_num
   4, // num_fields
   {
   // Def#, size,                                 base_type
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        3, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_TRAINING_GOALS_MESG_DEF training_goals_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_TRAINING_GOALS, // global_mesg_num
   12, // num_fields
   {
   // Def#, size,                                 base_type
        2, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        3, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        5, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        7, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        9, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_SUB_SPORT)*1), FIT_BASE_TYPE_ENUM,
        4, (sizeof(FIT_GOAL)*1), FIT_BASE_TYPE_ENUM,
        6, (sizeof(FIT_BOOL)*1), FIT_BASE_TYPE_ENUM,
        8, (sizeof(FIT_GOAL_RECURRENCE)*1), FIT_BASE_TYPE_ENUM,
       10, (sizeof(FIT_BOOL)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_ACTIVITY_MESG_DEF activity_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_ACTIVITY, // global_mesg_num
   8, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        0, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        5, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        1, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_ACTIVITY)*1), FIT_BASE_TYPE_ENUM,
        3, (sizeof(FIT_EVENT)*1), FIT_BASE_TYPE_ENUM,
        4, (sizeof(FIT_EVENT_TYPE)*1), FIT_BASE_TYPE_ENUM,
        6, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_SESSION_MESG_DEF session_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_SESSION, // global_mesg_num
   34, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        2, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        3, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        4, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        7, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        8, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        9, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
       10, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
       29, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
       30, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
       31, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
       32, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
       11, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       13, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       14, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       15, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       20, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       21, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       22, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       23, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       25, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       26, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_EVENT)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_EVENT_TYPE)*1), FIT_BASE_TYPE_ENUM,
        5, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
        6, (sizeof(FIT_SUB_SPORT)*1), FIT_BASE_TYPE_ENUM,
       16, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       17, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       18, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       19, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       24, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       27, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       28, (sizeof(FIT_SESSION_TRIGGER)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_LAP_MESG_DEF lap_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_LAP, // global_mesg_num
   29, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        2, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        3, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        4, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        5, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        6, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        7, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        8, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        9, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
       10, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
       11, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       12, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       13, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       14, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       19, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       20, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       21, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       22, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_EVENT)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_EVENT_TYPE)*1), FIT_BASE_TYPE_ENUM,
       15, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       16, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       17, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       18, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       23, (sizeof(FIT_INTENSITY)*1), FIT_BASE_TYPE_ENUM,
       24, (sizeof(FIT_LAP_TRIGGER)*1), FIT_BASE_TYPE_ENUM,
       25, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
       26, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_RECORD_MESG_DEF record_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_RECORD, // global_mesg_num
   15, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        0, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        1, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        5, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
       11, (sizeof(FIT_SINT32)*1), FIT_BASE_TYPE_SINT32,
        8, (sizeof(FIT_BYTE)*3), FIT_BASE_TYPE_BYTE,
        3, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        6, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        7, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        9, (sizeof(FIT_SINT16)*1), FIT_BASE_TYPE_SINT16,
        4, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       10, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       12, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       13, (sizeof(FIT_SINT8)*1), FIT_BASE_TYPE_SINT8,
   }
};

const static FIT_EVENT_MESG_DEF event_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_EVENT, // global_mesg_num
   6, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        3, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_EVENT)*1), FIT_BASE_TYPE_ENUM,
        1, (sizeof(FIT_EVENT_TYPE)*1), FIT_BASE_TYPE_ENUM,
        4, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_DEVICE_INFO_MESG_DEF device_info_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_DEVICE_INFO, // global_mesg_num
   11, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        3, (sizeof(FIT_UINT32Z)*1), FIT_BASE_TYPE_UINT32Z,
        7, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        2, (sizeof(FIT_MANUFACTURER)*1), FIT_BASE_TYPE_UINT16,
        4, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        5, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       10, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        0, (sizeof(FIT_DEVICE_INDEX)*1), FIT_BASE_TYPE_UINT8,
        1, (sizeof(FIT_DEVICE_TYPE)*1), FIT_BASE_TYPE_UINT8,
        6, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       11, (sizeof(FIT_BATTERY_STATUS)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_WORKOUT_MESG_DEF workout_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_WORKOUT, // global_mesg_num
   4, // num_fields
   {
   // Def#, size,                                 base_type
        5, (sizeof(FIT_WORKOUT_CAPABILITIES)*1), FIT_BASE_TYPE_UINT32Z,
        8, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
        6, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        4, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_WORKOUT_STEP_MESG_DEF workout_step_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_WORKOUT_STEP, // global_mesg_num
   9, // num_fields
   {
   // Def#, size,                                 base_type
        0, (sizeof(FIT_STRING)*16), FIT_BASE_TYPE_STRING,
        2, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        4, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        5, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        6, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_WKT_STEP_DURATION)*1), FIT_BASE_TYPE_ENUM,
        3, (sizeof(FIT_WKT_STEP_TARGET)*1), FIT_BASE_TYPE_ENUM,
        7, (sizeof(FIT_INTENSITY)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_TOTALS_MESG_DEF totals_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_TOTALS, // global_mesg_num
   6, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        0, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        1, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
        2, (sizeof(FIT_UINT32)*1), FIT_BASE_TYPE_UINT32,
      254, (sizeof(FIT_MESSAGE_INDEX)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_SPORT)*1), FIT_BASE_TYPE_ENUM,
   }
};

const static FIT_WEIGHT_SCALE_MESG_DEF weight_scale_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_WEIGHT_SCALE, // global_mesg_num
   13, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        0, (sizeof(FIT_WEIGHT)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        4, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        5, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        7, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        9, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
       12, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        8, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       10, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
       11, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
   }
};

const static FIT_BLOOD_PRESSURE_MESG_DEF blood_pressure_mesg_def =
{
   0, // reserved_1
   FIT_ARCH_ENDIAN, // arch
   FIT_MESG_NUM_BLOOD_PRESSURE, // global_mesg_num
   11, // num_fields
   {
   // Def#, size,                                 base_type
      253, (sizeof(FIT_DATE_TIME)*1), FIT_BASE_TYPE_UINT32,
        0, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        1, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        2, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        3, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        4, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        5, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        9, (sizeof(FIT_UINT16)*1), FIT_BASE_TYPE_UINT16,
        6, (sizeof(FIT_UINT8)*1), FIT_BASE_TYPE_UINT8,
        7, (sizeof(FIT_HR_TYPE)*1), FIT_BASE_TYPE_ENUM,
        8, (sizeof(FIT_BP_STATUS)*1), FIT_BASE_TYPE_ENUM,
   }
};


const FIT_MESG_DEF *fit_mesg_defs[] =
{
   (FIT_MESG_DEF *) &file_id_mesg_def,
   (FIT_MESG_DEF *) &file_creator_mesg_def,
   (FIT_MESG_DEF *) &software_mesg_def,
   (FIT_MESG_DEF *) &capabilities_mesg_def,
   (FIT_MESG_DEF *) &file_capabilities_mesg_def,
   (FIT_MESG_DEF *) &mesg_capabilities_mesg_def,
   (FIT_MESG_DEF *) &field_capabilities_mesg_def,
   (FIT_MESG_DEF *) &device_settings_mesg_def,
   (FIT_MESG_DEF *) &user_profile_mesg_def,
   (FIT_MESG_DEF *) &hrm_profile_mesg_def,
   (FIT_MESG_DEF *) &zones_target_mesg_def,
   (FIT_MESG_DEF *) &sport_mesg_def,
   (FIT_MESG_DEF *) &hr_zone_mesg_def,
   (FIT_MESG_DEF *) &power_zone_mesg_def,
   (FIT_MESG_DEF *) &met_zone_mesg_def,
   (FIT_MESG_DEF *) &training_goals_mesg_def,
   (FIT_MESG_DEF *) &activity_mesg_def,
   (FIT_MESG_DEF *) &session_mesg_def,
   (FIT_MESG_DEF *) &lap_mesg_def,
   (FIT_MESG_DEF *) &record_mesg_def,
   (FIT_MESG_DEF *) &event_mesg_def,
   (FIT_MESG_DEF *) &device_info_mesg_def,
   (FIT_MESG_DEF *) &workout_mesg_def,
   (FIT_MESG_DEF *) &workout_step_mesg_def,
   (FIT_MESG_DEF *) &totals_mesg_def,
   (FIT_MESG_DEF *) &weight_scale_mesg_def,
   (FIT_MESG_DEF *) &blood_pressure_mesg_def,
};