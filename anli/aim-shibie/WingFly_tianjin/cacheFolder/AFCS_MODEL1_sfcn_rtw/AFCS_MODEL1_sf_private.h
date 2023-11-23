/*
 * AFCS_MODEL1_sf_private.h
 *
 * Code generation for model "AFCS_MODEL1_sf".
 *
 * Model version              : 1.995
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Aug 11 17:17:39 2021
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AFCS_MODEL1_sf_private_h_
#define RTW_HEADER_AFCS_MODEL1_sf_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_LagFilter_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_LagFilter_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "LagFilter_sfcn_rtw/LagFilter_sf.h"
#include "LagFilter_sfcn_rtw/LagFilter_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_SaturationLimiter_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_SaturationLimiter_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "SaturationLimiter_sfcn_rtw/SaturationLimiter_sf.h"
#include "SaturationLimiter_sfcn_rtw/SaturationLimiter_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_Gain_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_Gain_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Gain_sfcn_rtw/Gain_sf.h"
#include "Gain_sfcn_rtw/Gain_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_LeadLagFilter_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_LeadLagFilter_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "LeadLagFilter_sfcn_rtw/LeadLagFilter_sf.h"
#include "LeadLagFilter_sfcn_rtw/LeadLagFilter_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_IntegratorLimited_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_IntegratorLimited_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "IntegratorLimited_sfcn_rtw/IntegratorLimited_sf.h"
#include "IntegratorLimited_sfcn_rtw/IntegratorLimited_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_Res180_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_Res180_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Res180_sfcn_rtw/Res180_sf.h"
#include "Res180_sfcn_rtw/Res180_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_Fader_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_Fader_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Fader_sfcn_rtw/Fader_sf.h"
#include "Fader_sfcn_rtw/Fader_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_RateLimiter_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_RateLimiter_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "RateLimiter_sfcn_rtw/RateLimiter_sf.h"
#include "RateLimiter_sfcn_rtw/RateLimiter_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_WashoutFilter_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_WashoutFilter_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "WashoutFilter_sfcn_rtw/WashoutFilter_sf.h"
#include "WashoutFilter_sfcn_rtw/WashoutFilter_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_NegativePass_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_NegativePass_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "NegativePass_sfcn_rtw/NegativePass_sf.h"
#include "NegativePass_sfcn_rtw/NegativePass_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_PositivePass_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_PositivePass_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "PositivePass_sfcn_rtw/PositivePass_sf.h"
#include "PositivePass_sfcn_rtw/PositivePass_sf_private.h"
#endif

#if !defined(RTW_GNERATED_SFCN_NOT_PRIVATE_StickGradientDeadZone_sf)
#define RTW_GNERATED_SFCN_NOT_PRIVATE_StickGradientDeadZone_sf
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "StickGradientDeadZone_sfcn_rtw/StickGradientDeadZone_sf.h"
#include "StickGradientDeadZone_sfcn_rtw/StickGradientDeadZone_sf_private.h"
#endif

#include "AFCS_MODEL1_sf.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
 ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
 }
#endif

#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((ptr));\
 (ptr) = (NULL);\
 }
#else

/* Visual and other windows compilers declare free without const */
#define rt_FREE(ptr)                   if((ptr) != (NULL)) {\
 free((void *)(ptr));\
 (ptr) = (NULL);\
 }
#endif
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if 0

/* Skip this size verification because of preprocessor limitation */
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

#ifndef GRAVITY2_TYPEDEF

typedef enum { WGS84TAYLORSERIES = 1, WGS84CLOSEAPPROX,
  WGS84EXACT } GravityTypeIdx;

typedef enum { METRIC = 1, ENGLISH } UnitIdx;

typedef enum { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY,
  AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER } MonthIdx;

#define GRAVITY2_TYPEDEF
#endif                                 /* GRAVITY2_TYPEDEF */

#ifndef WGS84_DEFINE
#define WGS84_A                        6378137.0                 /* Semi-major Axis (m) */
#define WGS84_INV_F                    298.257223563             /* Reciprocal of Flattening */
#define WGS84_W_DEF                    7292115.0e-11             /* WGS 84 Angular Velocity of Earth (rad/sec)*/
#define WGS84_GM_DEF                   3986004.418e+8            /* Earth's Gravitational Const. (m^3/sec^2) */
#define WGS84_GM_PRM                   3986000.9e+8              /* Earth's Grav. Const. (m^3/sec^2) [no atmos]*/
#define WGS84_W_PRM                    7292115.1467e-11          /* IAU Angular Velocity of Earth (rad/sec) */
#define WGS84_G_E                      9.7803253359              /* Theoretical (Normal) Gravity at the Equator
                                                                    (on the Ellipsoid) (m/s^2) */
#define WGS84_K                        0.00193185265241          /* Theoretical (Normal) Gravity Formula Const.*/
#define WGS84_E_2                      6.69437999014e-3          /* First Eccentricity Squared */
#define WGS84_EL                       5.2185400842339e+5        /* Linear Eccentricity */
#define WGS84_B                        6356752.3142              /* Semi-minor Axis (m) */
#define WGS84_B_A                      0.996647189335            /* Axis Ratio */
#define M2FT                           1.0/0.3048
#define AERO_PI                        3.14159265358979323846
#define DEG2RAD                        AERO_PI/180.0
#define YEAR2000                       2000
#define WGS84_DEFINE
#endif                                 /* WGS84_DEFINE */

void AFCS_MODEL1_sf_LookUpE_4Ol9QRGv(real_T *pY, const real_T *pYData, real_T u,
  real_T valueLo, uint32_T iHi, real_T uSpacing);
void wgs84_taylor_series(real_T *h, real_T *phi, real_T opt_m2ft, real_T *y,
  int_T k);
extern real32_T AFCS_MODEL1_look1_iflf_binlcpw(real32_T u0, const real32_T bp0[],
  const real32_T table[], uint32_T maxIndex);
extern real32_T AFCS_MODEL1_look1_iflf_binlxpw(real32_T u0, const real32_T bp0[],
  const real32_T table[], uint32_T maxIndex);
extern real_T AFCS_MODEL1_look1_binlxpw(real_T u0, const real_T bp0[], const
  real_T table[], uint32_T maxIndex);
extern real_T AFCS_MODEL1_look2_binlxpw(real_T u0, real_T u1, const real_T bp0[],
  const real_T bp1[], const real_T table[], const uint32_T maxIndex[], uint32_T
  stride);
extern void LagFilter_sf(SimStruct *childS);
extern void SaturationLimiter_sf(SimStruct *childS);
extern void Gain_sf(SimStruct *childS);
extern void LeadLagFilter_sf(SimStruct *childS);
extern void IntegratorLimited_sf(SimStruct *childS);
extern void Res180_sf(SimStruct *childS);
extern void Fader_sf(SimStruct *childS);
extern void RateLimiter_sf(SimStruct *childS);
extern void WashoutFilter_sf(SimStruct *childS);
extern void NegativePass_sf(SimStruct *childS);
extern void PositivePass_sf(SimStruct *childS);
extern void StickGradientDeadZone_sf(SimStruct *childS);
void AFCS_MODEL1_LMainGearGeometryForcesandMoments_Init(SimStruct * const S,
  B_LMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_LMainGearGeometryForcesandMoments_Start(SimStruct * const S);
void AFCS_MODEL1_LMainGearGeometryForcesandMoments_Disable(SimStruct * const S,
  B_LMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_LMainGearGeometryForcesandMoments_Update(SimStruct * const S,
  B_LMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_LMainGearGeometryForcesandMoments(SimStruct * const S, real_T
  rtu_ground_z_m, real_T rtu_plant, real_T rtu_plant_d, real_T rtu_plant_f,
  const real_T rtu_GearLoc[3], real_T rtu_FricCoeff, real_T rtu_FricCoeff_g,
  B_LMainGearGeometryForcesandM_T *localB, ConstB_LMainGearGeometryForce_T
  *localC);
void AFCS_MODEL1_NoseGearGeometryForcesandMoments_Init(SimStruct * const S,
  B_NoseGearGeometryForcesandMo_T *localB);
void AFCS_MODEL1_NoseGearGeometryForcesandMoments_Start(SimStruct * const S);
void AFCS_MODEL1_NoseGearGeometryForcesandMoments_Disable(SimStruct * const S,
  B_NoseGearGeometryForcesandMo_T *localB);
void AFCS_MODEL1_NoseGearGeometryForcesandMoments_Update(SimStruct * const S,
  B_NoseGearGeometryForcesandMo_T *localB);
void AFCS_MODEL1_NoseGearGeometryForcesandMoments(SimStruct * const S, real_T
  rtu_ground_z_m, real_T rtu_plant, real_T rtu_plant_a, real_T rtu_plant_j,
  const real_T rtu_GearLoc[3], real_T rtu_FricCoeff, real_T rtu_FricCoeff_j,
  const real_T rtu_Euler[3], B_NoseGearGeometryForcesandMo_T *localB,
  ConstB_NoseGearGeometryForces_T *localC);
void AFCS_MODEL1_RMainGearGeometryForcesandMoments_Init(SimStruct * const S,
  B_RMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_RMainGearGeometryForcesandMoments_Start(SimStruct * const S);
void AFCS_MODEL1_RMainGearGeometryForcesandMoments_Disable(SimStruct * const S,
  B_RMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_RMainGearGeometryForcesandMoments_Update(SimStruct * const S,
  B_RMainGearGeometryForcesandM_T *localB);
void AFCS_MODEL1_RMainGearGeometryForcesandMoments(SimStruct * const S, real_T
  rtu_ground_z_m, real_T rtu_plant, real_T rtu_plant_k, real_T rtu_plant_b,
  const real_T rtu_GearLoc[3], real_T rtu_FricCoeff, real_T rtu_FricCoeff_k,
  const real_T rtu_Euler[3], B_RMainGearGeometryForcesandM_T *localB,
  ConstB_RMainGearGeometryForce_T *localC);

#if defined(MULTITASKING)
#  error Model (AFCS_MODEL1_sf) was built in \
SingleTasking solver mode, however the MULTITASKING define is \
present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \
defined on the Code Generation page of Simulation parameter dialog, please \
remove it and on the Solver page, select solver mode \
MultiTasking. If the Simulation parameter dialog is configured \
correctly, please verify that your template makefile is \
configured correctly.
#endif
#endif                                 /* RTW_HEADER_AFCS_MODEL1_sf_private_h_ */
