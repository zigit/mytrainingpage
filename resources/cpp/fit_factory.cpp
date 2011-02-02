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


#include "fit_factory.hpp"
#include "fit_file_id_mesg.hpp"
#include "fit_file_creator_mesg.hpp"
#include "fit_software_mesg.hpp"
#include "fit_capabilities_mesg.hpp"
#include "fit_file_capabilities_mesg.hpp"
#include "fit_mesg_capabilities_mesg.hpp"
#include "fit_field_capabilities_mesg.hpp"
#include "fit_device_settings_mesg.hpp"
#include "fit_user_profile_mesg.hpp"
#include "fit_hrm_profile_mesg.hpp"
#include "fit_zones_target_mesg.hpp"
#include "fit_sport_mesg.hpp"
#include "fit_hr_zone_mesg.hpp"
#include "fit_power_zone_mesg.hpp"
#include "fit_met_zone_mesg.hpp"
#include "fit_training_goals_mesg.hpp"
#include "fit_activity_mesg.hpp"
#include "fit_session_mesg.hpp"
#include "fit_lap_mesg.hpp"
#include "fit_record_mesg.hpp"
#include "fit_event_mesg.hpp"
#include "fit_device_info_mesg.hpp"
#include "fit_workout_mesg.hpp"
#include "fit_workout_step_mesg.hpp"
#include "fit_totals_mesg.hpp"
#include "fit_weight_scale_mesg.hpp"
#include "fit_blood_pressure_mesg.hpp"

namespace fit
{

Mesg Factory::CreateMesg(Mesg mesg)
{
   switch (mesg.GetNum())
   {
      case FIT_MESG_NUM_FILE_ID:
         return FileIdMesg(mesg);
      case FIT_MESG_NUM_FILE_CREATOR:
         return FileCreatorMesg(mesg);
      case FIT_MESG_NUM_SOFTWARE:
         return SoftwareMesg(mesg);
      case FIT_MESG_NUM_CAPABILITIES:
         return CapabilitiesMesg(mesg);
      case FIT_MESG_NUM_FILE_CAPABILITIES:
         return FileCapabilitiesMesg(mesg);
      case FIT_MESG_NUM_MESG_CAPABILITIES:
         return MesgCapabilitiesMesg(mesg);
      case FIT_MESG_NUM_FIELD_CAPABILITIES:
         return FieldCapabilitiesMesg(mesg);
      case FIT_MESG_NUM_DEVICE_SETTINGS:
         return DeviceSettingsMesg(mesg);
      case FIT_MESG_NUM_USER_PROFILE:
         return UserProfileMesg(mesg);
      case FIT_MESG_NUM_HRM_PROFILE:
         return HrmProfileMesg(mesg);
      case FIT_MESG_NUM_ZONES_TARGET:
         return ZonesTargetMesg(mesg);
      case FIT_MESG_NUM_SPORT:
         return SportMesg(mesg);
      case FIT_MESG_NUM_HR_ZONE:
         return HrZoneMesg(mesg);
      case FIT_MESG_NUM_POWER_ZONE:
         return PowerZoneMesg(mesg);
      case FIT_MESG_NUM_MET_ZONE:
         return MetZoneMesg(mesg);
      case FIT_MESG_NUM_TRAINING_GOALS:
         return TrainingGoalsMesg(mesg);
      case FIT_MESG_NUM_ACTIVITY:
         return ActivityMesg(mesg);
      case FIT_MESG_NUM_SESSION:
         return SessionMesg(mesg);
      case FIT_MESG_NUM_LAP:
         return LapMesg(mesg);
      case FIT_MESG_NUM_RECORD:
         return RecordMesg(mesg);
      case FIT_MESG_NUM_EVENT:
         return EventMesg(mesg);
      case FIT_MESG_NUM_DEVICE_INFO:
         return DeviceInfoMesg(mesg);
      case FIT_MESG_NUM_WORKOUT:
         return WorkoutMesg(mesg);
      case FIT_MESG_NUM_WORKOUT_STEP:
         return WorkoutStepMesg(mesg);
      case FIT_MESG_NUM_TOTALS:
         return TotalsMesg(mesg);
      case FIT_MESG_NUM_WEIGHT_SCALE:
         return WeightScaleMesg(mesg);
      case FIT_MESG_NUM_BLOOD_PRESSURE:
         return BloodPressureMesg(mesg);
      default:
         break;
   }
   return mesg;
}


} // namespace fit
