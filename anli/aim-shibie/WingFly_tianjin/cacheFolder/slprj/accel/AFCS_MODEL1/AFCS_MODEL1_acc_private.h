#include "__cf_AFCS_MODEL1.h"
#ifndef RTW_HEADER_AFCS_MODEL1_acc_private_h_
#define RTW_HEADER_AFCS_MODEL1_acc_private_h_
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
#include "AFCS_MODEL1_acc.h"
#if !defined(ss_VALIDATE_MEMORY)
#define ss_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(S, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef UCHAR_MAX
#include <limits.h>
#endif
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if 0
#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized ulong_long/long_long. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#endif
#ifndef GRAVITY2_TYPEDEF
typedef enum { WGS84TAYLORSERIES = 1 , WGS84CLOSEAPPROX , WGS84EXACT }
GravityTypeIdx ; typedef enum { METRIC = 1 , ENGLISH } UnitIdx ; typedef enum
{ JANUARY = 1 , FEBRUARY , MARCH , APRIL , MAY , JUNE , JULY , AUGUST ,
SEPTEMBER , OCTOBER , NOVEMBER , DECEMBER } MonthIdx ;
#define GRAVITY2_TYPEDEF
#endif
#ifndef WGS84_DEFINE
#define WGS84_A      6378137.0           
#define WGS84_INV_F  298.257223563          
#define WGS84_W_DEF  7292115.0e-11       
#define WGS84_GM_DEF 3986004.418e+8      
#define WGS84_GM_PRM 3986000.9e+8       
#define WGS84_W_PRM  7292115.1467e-11   
#define WGS84_G_E    9.7803253359       
#define WGS84_K      0.00193185265241   
#define WGS84_E_2    6.69437999014e-3   
#define WGS84_EL     5.2185400842339e+5 
#define WGS84_B      6356752.3142       
#define WGS84_B_A    0.996647189335     
#define M2FT     1.0/0.3048
#define AERO_PI  3.14159265358979323846
#define DEG2RAD  AERO_PI/180.0
#define YEAR2000 2000
#define WGS84_DEFINE 
#endif
void AFCS_MODEL1_acc_BINARYSEARCH_real_T ( uint32_T * piLeft , uint32_T *
piRght , real_T u , const real_T * pData , uint32_T iHi ) ; void
AFCS_MODEL1_acc_LookUp_real_T_real_T ( real_T * pY , const real_T * pYData ,
real_T u , const real_T * pUData , uint32_T iHi ) ; void wgs84_taylor_series
( real_T * h , real_T * phi , real_T opt_m2ft , real_T * y , int_T k ) ;
extern real32_T look1_iflf_binlcpw ( real32_T u0 , const real32_T bp0 [ ] ,
const real32_T table [ ] , uint32_T maxIndex ) ; extern real32_T
look1_iflf_binlxpw ( real32_T u0 , const real32_T bp0 [ ] , const real32_T
table [ ] , uint32_T maxIndex ) ; extern real_T look1_binlxpw ( real_T u0 ,
const real_T bp0 [ ] , const real_T table [ ] , uint32_T maxIndex ) ; extern
real_T look2_binlxpw ( real_T u0 , real_T u1 , const real_T bp0 [ ] , const
real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [ ] ,
uint32_T stride ) ; void mu2kvrtqzt ( knwbmdh2o1 * localB , k52umkce5u *
localDW , dbjdkpcxft * localP ) ; void d0gn4nvn3e ( knwbmdh2o1 * localB ,
k52umkce5u * localDW , dbjdkpcxft * localP ) ; void hztvnhnxrv ( SimStruct *
const S , knwbmdh2o1 * localB , k52umkce5u * localDW ) ; void lvrrs02dbe (
SimStruct * const S , real_T dobvhq0s0w , real_T n3srqvzjme , real_T
okksoyo2mo , real_T k4r0sciaji , const real_T omuypwqqfo [ 3 ] , real_T
czaxhnzy2o , real_T ppnrpfuvi0 , knwbmdh2o1 * localB , k52umkce5u * localDW ,
dbjdkpcxft * localP ) ; void lvrrs02dbeTID2 ( SimStruct * const S , const
real_T omuypwqqfo [ 3 ] , knwbmdh2o1 * localB , k52umkce5u * localDW ,
dbjdkpcxft * localP ) ; void busktusywo ( nlxzdmxpff * localB , mcezkcerxl *
localDW , fvjsblhu4h * localP ) ; void lcmgrp0nqt ( nlxzdmxpff * localB ,
mcezkcerxl * localDW , fvjsblhu4h * localP ) ; void ggcobnfl5g ( SimStruct *
const S , nlxzdmxpff * localB , mcezkcerxl * localDW ) ; void b1bttejwsj (
SimStruct * const S , real_T noteznn2pu , real_T mqv1fmj0h4 , real_T
dbizdu33zh , real_T nwypdkysyt , real_T g5cifgqejv , const real_T fet14bdoje
[ 3 ] , real_T er4fwreuhw , real_T jgnicw2ubu , nlxzdmxpff * localB ,
mcezkcerxl * localDW , fvjsblhu4h * localP ) ; void b1bttejwsjTID2 (
SimStruct * const S , const real_T fet14bdoje [ 3 ] , nlxzdmxpff * localB ,
mcezkcerxl * localDW , fvjsblhu4h * localP ) ; void bieqb4n1n0 ( nqr53r3iar *
localB , bewbuevixx * localDW , fgfesxh13p * localP ) ; void igndwt035f (
nqr53r3iar * localB , bewbuevixx * localDW , fgfesxh13p * localP ) ; void
onr0acfhav ( SimStruct * const S , nqr53r3iar * localB , bewbuevixx * localDW
) ; void dak2bbvhdy ( SimStruct * const S , real_T pm5rlqqzgg , real_T
dj1eg0kba5 , real_T ijr5dtekxq , real_T kt2gyj2sli , real_T bkwbtezauh ,
const real_T gzfuumbstf [ 3 ] , real_T looklzp1sr , real_T elrgqbqmp1 ,
nqr53r3iar * localB , bewbuevixx * localDW , fgfesxh13p * localP ) ; void
dak2bbvhdyTID2 ( SimStruct * const S , const real_T gzfuumbstf [ 3 ] ,
nqr53r3iar * localB , bewbuevixx * localDW , fgfesxh13p * localP ) ; void
h3v44pg0kk ( real_T fmumi05obi , const real_T ppb3dktj10 [ 9 ] , real_T *
madmhz5eqy , real_T pxkeba3ih1 [ 3 ] , k45adr4f5c * localB , grglhn4pya *
localP ) ; void h3v44pg0kkTID2 ( k45adr4f5c * localB , grglhn4pya * localP )
; void iorhdpdmai ( SimStruct * const S , const real_T l0032p1zr2 [ 9 ] ,
real_T * b4ei5neduy , real_T * lerqs0qiln , real_T * hh3qhyha0i , real_T *
n4p4av1cij , gritqy5sso * localB , pef3aehv5o * localDW , dcmchj0dqy * localP
) ; void iorhdpdmaiTID2 ( gritqy5sso * localB , dcmchj0dqy * localP ) ; void
cypz4slwdy ( SimStruct * const S ) ; void irv3p1y3ss ( SimStruct * const S )
; void jtjpxjywrw ( SimStruct * const S ) ; void jtjpxjywrwTID2 ( SimStruct *
const S ) ; void mktyos2lxd ( SimStruct * const S ) ;
#endif
