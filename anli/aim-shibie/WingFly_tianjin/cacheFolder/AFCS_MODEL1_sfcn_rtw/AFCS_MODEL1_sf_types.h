/*
 * AFCS_MODEL1_sf_types.h
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

#ifndef RTW_HEADER_AFCS_MODEL1_sf_types_h_
#define RTW_HEADER_AFCS_MODEL1_sf_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "LagFilter_sfcn_rtw/LagFilter_sf.h"
#include "LagFilter_sfcn_rtw/LagFilter_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "SaturationLimiter_sfcn_rtw/SaturationLimiter_sf.h"
#include "SaturationLimiter_sfcn_rtw/SaturationLimiter_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Gain_sfcn_rtw/Gain_sf.h"
#include "Gain_sfcn_rtw/Gain_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "LeadLagFilter_sfcn_rtw/LeadLagFilter_sf.h"
#include "LeadLagFilter_sfcn_rtw/LeadLagFilter_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "IntegratorLimited_sfcn_rtw/IntegratorLimited_sf.h"
#include "IntegratorLimited_sfcn_rtw/IntegratorLimited_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Res180_sfcn_rtw/Res180_sf.h"
#include "Res180_sfcn_rtw/Res180_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "Fader_sfcn_rtw/Fader_sf.h"
#include "Fader_sfcn_rtw/Fader_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "RateLimiter_sfcn_rtw/RateLimiter_sf.h"
#include "RateLimiter_sfcn_rtw/RateLimiter_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "WashoutFilter_sfcn_rtw/WashoutFilter_sf.h"
#include "WashoutFilter_sfcn_rtw/WashoutFilter_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "NegativePass_sfcn_rtw/NegativePass_sf.h"
#include "NegativePass_sfcn_rtw/NegativePass_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "PositivePass_sfcn_rtw/PositivePass_sf.h"
#include "PositivePass_sfcn_rtw/PositivePass_sf_private.h"
#endif

#if !defined(MATLAB_MEX_FILE)
#undef S_FUNCTION_NAME
#include "StickGradientDeadZone_sfcn_rtw/StickGradientDeadZone_sf.h"
#include "StickGradientDeadZone_sfcn_rtw/StickGradientDeadZone_sf_private.h"
#endif

#ifndef SS_INT64
#define SS_INT64                       36
#endif

#ifndef SS_UINT64
#define SS_UINT64                      37
#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNCrc_
#define DEFINED_TYPEDEF_FOR_BUS_GNCrc_

typedef struct {
  real32_T RollCH;
  real32_T PitchCH;
  real32_T ThrustCH;
  real32_T YawCH;
  int8_T LockSW;
  int8_T TakeoffSW;
  int8_T SwcheckSW;
  int8_T ManualSW;
  int8_T EmlandSW;
  int8_T StopTakeoffSW;
  int8_T GoaroundSW;
  int8_T Rc_lost;
} BUS_GNCrc;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_Routedata_
#define DEFINED_TYPEDEF_FOR_BUS_Routedata_

typedef struct {
  real_T routeLon[30];
  real_T routeLat[30];
  real32_T routeAlt[30];
  int32_T routeFG[30];
} BUS_Routedata;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNCupload_
#define DEFINED_TYPEDEF_FOR_BUS_GNCupload_

typedef struct {
  int8_T TaxiTestFg;
  uint8_T sl_padding0[7];
  BUS_Routedata Routedata;
  int8_T NumPoint;
  uint8_T sl_padding1[3];
  real32_T Hrw;
  real32_T VcDr;
  real32_T VcLiftWheel;
  real32_T ThrustTakeoff;
  real32_T ThetaLiftWheel;
  real32_T GamaClimb;
  real32_T GamaGlide;
  real32_T DetaDrange;
  real32_T VcCruise;
  real32_T GamaLand;
  real32_T VcLand;
  real32_T mAHLow;
  real32_T Rmax;
  int8_T airLineUpdateFlag;
  uint8_T sl_padding2[3];
  real32_T kyrwLnws;
  real32_T kpsdLnws;
  real32_T krnws;
  real32_T StopTFDistance;
  real32_T TaxiVc;
} BUS_GNCupload;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_Sensor_
#define DEFINED_TYPEDEF_FOR_BUS_AC_Sensor_

typedef struct {
  real_T Quaternions[4];
  real_T phiL;
  real_T thetaL;
  real_T psiL;
  real_T p;
  real_T q;
  real_T r;
  real_T Abx;
  real_T Aby;
  real_T Abz;
  real_T Lat;
  real_T Lon;
  real_T Altitude;
  real_T GPS_vnorth;
  real_T GPS_veast;
  real_T GPS_vdown;
  real_T GPS_eph;
  real_T GPS_epv;
  int8_T GPS_Valid;
  int8_T Local_HValid;
  uint8_T sl_padding0[6];
  real_T Mach;
  real_T Alfa;
  real_T Beta;
  real_T Qbar;
  real_T Va;
  int8_T AirspeedFailfg;
  int8_T EnLowFlag;
  int8_T WOWL;
  int8_T WOWR;
  int8_T WOWN;
  uint8_T sl_padding1[3];
} BUS_AC_Sensor;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_guidance_
#define DEFINED_TYPEDEF_FOR_BUS_AC_guidance_

typedef struct {
  real32_T ytrack;
  real32_T altcmd;
  real32_T headingcmd;
  real32_T ascmd;
  real32_T dtocenter;
  real32_T dtoTarget;
  int8_T currentPoint;
  int8_T targetpoint;
  uint8_T sl_padding0[6];
} BUS_AC_guidance;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_QGC_
#define DEFINED_TYPEDEF_FOR_BUS_AC_QGC_

typedef struct {
  real32_T decl_qgc;
  real32_T dacl_qgc;
  real32_T drcl_qgc;
  real32_T nwscl_qgc;
  real32_T sbcl_qgc;
  int8_T StartEngine_qgc;
  int8_T TakeoffFg_qgc;
  int8_T Taxi_Fg;
  int8_T LockFg_qgc;
  int8_T INS_switch;
  int8_T INSIntegralClear_Fg;
  int8_T EmergenReturnFg;
  int8_T EmergenLandFg;
  int8_T VcVtCutFg;
  int8_T IniposCalFg;
  uint8_T sl_padding0[2];
  BUS_AC_guidance guidance;
} BUS_AC_QGC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_ModelInput_
#define DEFINED_TYPEDEF_FOR_BUS_ModelInput_

typedef struct {
  BUS_GNCrc RCinput;
  BUS_GNCupload upload;
  BUS_AC_Sensor sensor;
  BUS_AC_QGC dx_qgc;
} BUS_ModelInput;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNCuplink_
#define DEFINED_TYPEDEF_FOR_BUS_GNCuplink_

typedef struct {
  real32_T RollUL;
  real32_T PitchUL;
  real32_T YawUL;
  real32_T TpUL;
  int8_T LockUL;
  int8_T TakeoffUL;
  int8_T SwcheckUL;
  int8_T ManualUL;
  int8_T EmlandUL;
  int8_T StopTakeoffUL;
  int8_T GoaroundUL;
  uint8_T sl_padding0;
} BUS_GNCuplink;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_NAV_
#define DEFINED_TYPEDEF_FOR_BUS_NAV_

typedef struct {
  real32_T vt;
  real32_T altitude;
  real32_T vnorth;
  real32_T veast;
  real32_T mhdot;
  uint8_T sl_padding0[4];
  real_T Lon;
  real_T Lat;
  real32_T gama;
  real32_T psd;
  real32_T yrw;
  real32_T xrw;
  real32_T vxrw;
  real32_T vyrw;
  real32_T drange;
  real32_T mh;
  real32_T Quaternions[4];
  int32_T VxdNest;
  real32_T phiL;
  real32_T thetaL;
  real32_T psiL;
  real32_T p;
  real32_T q;
  real32_T r;
  real32_T Nx;
  real32_T Ny;
  real32_T Nz;
  real32_T Va;
  real32_T Alfa;
  real32_T Beta;
  real32_T Qbar;
  real32_T Vc;
  real32_T href;
  real32_T PSDref;
  real32_T HrefAL;
  real32_T DetaPsiEm;
  real32_T DireFg;
  int8_T IndexAL;
  uint8_T sl_padding1[3];
  real32_T DtoStart;
} BUS_NAV;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_LogicCmd_
#define DEFINED_TYPEDEF_FOR_BUS_LogicCmd_

typedef struct {
  int8_T configure;
  int8_T apthL;
  int8_T aplonL;
  int8_T aplatL;
  int8_T apyawL;
  int8_T apsbL;
  int8_T apnwsL;
  int8_T apbrkL;
  real32_T thrustcmd;
  real32_T vtcmd;
  real32_T nzcmd;
  real32_T nycmd;
  real32_T phiLcmd;
  real32_T thetaLcmd;
  real32_T psiLcmd;
  real32_T gamacmd;
  real32_T hcmd;
  real32_T psdcmd;
  real32_T yrwcmd;
  int8_T apcheck;
  int8_T apfix;
  int8_T K;
  int8_T StartEmNav;
} BUS_LogicCmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNC_SETUP_
#define DEFINED_TYPEDEF_FOR_BUS_GNC_SETUP_

typedef struct {
  int8_T LockFlag;
  int8_T TakeoffFlag;
  int8_T EmlandFg;
  int8_T GoaroundFg;
  int8_T SWAUTO;
  int8_T Swcheck;
  int8_T GPSFail;
  int8_T EnLowFlag;
  int8_T StopTakeoffFg;
  int8_T WOW;
  int8_T WOWNS;
  uint8_T sl_padding0[5];
} BUS_GNC_SETUP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_PilotCmd_
#define DEFINED_TYPEDEF_FOR_BUS_PilotCmd_

typedef struct {
  real32_T Tpdlp;
  real32_T Pitchdlp;
  real32_T Rolldlp;
  real32_T Yawdlp;
  real32_T Tp;
  real32_T Pitchp;
  real32_T Rollp;
  real32_T Yawp;
} BUS_PilotCmd;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNCmid_
#define DEFINED_TYPEDEF_FOR_BUS_GNCmid_

typedef struct {
  real32_T deint;
  real32_T daint;
  real32_T drint;
  real32_T dtCAS;
} BUS_GNCmid;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GNC_OUT_CONF_
#define DEFINED_TYPEDEF_FOR_BUS_GNC_OUT_CONF_

typedef struct {
  BUS_GNCmid Midoutput;
  real32_T thrust;
  real32_T decl;
  real32_T drcl;
  real32_T dacl;
  real32_T sbcl;
  real32_T nwscl;
  real32_T brkcl;
  real32_T apthrust;
  real32_T appc;
  real32_T aprc;
  real32_T apyc;
  real32_T apnwsc;
  int8_T apbrkc;
  uint8_T sl_padding0[3];
  real32_T Swint;
  real32_T Swcom;
  real32_T dfalcl;
  real32_T dfarcl;
  real32_T dfcl;
  real32_T gearcl;
  uint8_T sl_padding1[4];
} BUS_GNC_OUT_CONF;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_Simin_
#define DEFINED_TYPEDEF_FOR_BUS_Simin_

typedef struct {
  uint8_T takeoff;
  uint8_T sl_padding0[3];
  real32_T thrust;
  real32_T Decl;
  real32_T Dacl;
  real32_T Drcl;
  real32_T Dsbcl;
  real32_T Dnwscl;
  real32_T Dbrkcl;
  real_T Lat0;
  real_T Lon0;
  real32_T Alt0;
  uint8_T startEngine;
  uint8_T sl_padding1[3];
  real32_T psi_ini;
  real32_T hrw;
  real32_T WindValue;
  real32_T WindAngle;
  real32_T dfalcl;
  real32_T dfarcl;
  real32_T dfcl;
  real32_T gearcl;
} BUS_Simin;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_INIT_
#define DEFINED_TYPEDEF_FOR_BUS_AC_INIT_

typedef struct {
  real_T Pqr0[3];
  real_T Euler0[3];
  real_T mulh0[3];
  real_T uvw0[3];
  real_T Hrw;
} BUS_AC_INIT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_Monte_
#define DEFINED_TYPEDEF_FOR_BUS_AC_Monte_

typedef struct {
  real_T Koffset_Mass;
  real_T Koffset_Xcg;
  real_T Doffset_Ycg;
  real_T Doffset_Zcg;
  real_T Koffset_Ixx;
  real_T Koffset_Iyy;
  real_T Koffset_Izz;
  real_T Koffset_CLalfa;
  real_T Koffset_Cmalfa;
  real_T Koffset_Cnbeta;
  real_T Koffset_Crbeta;
  real_T Koffset_Cmq;
  real_T Koffset_Cmalfadot;
  real_T Koffset_Cnr;
  real_T Koffset_Cnp;
  real_T Koffset_Clp;
  real_T Koffset_Clr;
  real_T Koffset_Cmde;
  real_T Koffset_Cndr;
  real_T Koffset_Cldr;
  real_T Koffset_Clda;
  real_T Koffset_Cnda;
  real_T Doffset_Va;
  real_T Doffset_Alfa;
  real_T Doffset_Beta;
  real_T Doffset_p;
  real_T Doffset_q;
  real_T Doffset_r;
  real_T Doffset_nz;
  real_T Doffset_nx;
  real_T Doffset_ny;
  real_T Doffset_theta;
  real_T Doffset_phi;
  real_T Koffset_Rou;
  real_T Koffset_FpR;
  real_T Doffset_DETApR;
  real_T Doffset_KESIpR;
  real_T Koffset_FpL;
  real_T Doffset_DETApL;
  real_T Doffset_KESIpL;
} BUS_AC_Monte;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_Simout_
#define DEFINED_TYPEDEF_FOR_BUS_Simout_

typedef struct {
  int32_T phiL;
  int32_T thetaL;
  int32_T psiL;
  int32_T p;
  int32_T q;
  int32_T r;
  int32_T Abx;
  int32_T Aby;
  int32_T Abz;
  int32_T Vn;
  int32_T Ve;
  int32_T Vd;
  int32_T Lat;
  int32_T Lon;
  int32_T Alt;
  int32_T Ndefine1;
  int32_T Ndefine2;
  int32_T Ndefine3;
  int32_T Va;
  int32_T Vc;
} BUS_Simout;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_ACT_
#define DEFINED_TYPEDEF_FOR_BUS_AC_ACT_

typedef struct {
  real_T rthrust;
  real_T lthrust;
  real_T rde;
  real_T lde;
  real_T rda;
  real_T lda;
  real_T dr;
  real_T sb;
  real_T NwsAngle;
  real_T BRKR;
  real_T BRKL;
} BUS_AC_ACT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_Devond_
#define DEFINED_TYPEDEF_FOR_BUS_AC_Devond_

typedef struct {
  real_T Mach;
  real_T Alfa;
  real_T Beta;
  real_T Qbar;
  real_T Qc;
  real_T Va;
  real_T Vc;
  real_T Alfadot;
} BUS_AC_Devond;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_AC_Param_
#define DEFINED_TYPEDEF_FOR_BUS_AC_Param_

typedef struct {
  real_T Quaternions[4];
  real_T Euler[3];
  real_T Pqr[3];
  real_T Pqrdot[3];
  real_T Lat;
  real_T Lon;
  real_T Alt;
  real_T Vb[3];
  real_T Ab[3];
  real_T DCMbe[9];
  real_T Ve[3];
  real_T Xe[3];
} BUS_AC_Param;

#endif
#endif                                 /* RTW_HEADER_AFCS_MODEL1_sf_types_h_ */
