#include "__cf_AFCS_MODEL1.h"
#include <math.h>
#include "AFCS_MODEL1_acc.h"
#include "AFCS_MODEL1_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_StickGradientDeadZone_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_StickGradientDeadZone_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_PositivePass_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_PositivePass_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_NegativePass_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_NegativePass_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_WashoutFilter_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_WashoutFilter_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_RateLimiter_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_RateLimiter_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_Fader_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_Fader_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_Res180_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_Res180_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_IntegratorLimited_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_IntegratorLimited_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_LeadLagFilter_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_LeadLagFilter_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_Gain_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_Gain_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_SaturationLimiter_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_SaturationLimiter_sf
#endif
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_LagFilter_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_LagFilter_sf
#endif
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME simulink_only_sfcn
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void dffiw3rk3b ( const real_T u0 [ 3 ] , const real_T u1 [ 9 ] ,
real_T y [ 3 ] ) ; void AFCS_MODEL1_acc_BINARYSEARCH_real_T ( uint32_T *
piLeft , uint32_T * piRght , real_T u , const real_T * pData , uint32_T iHi )
{ * piLeft = 0U ; * piRght = iHi ; if ( u <= pData [ 0 ] ) { * piRght = 0U ;
} else if ( u >= pData [ iHi ] ) { * piLeft = iHi ; } else { uint32_T i ;
while ( ( * piRght - * piLeft ) > 1U ) { i = ( * piLeft + * piRght ) >> 1 ;
if ( u < pData [ i ] ) { * piRght = i ; } else { * piLeft = i ; } } } } void
AFCS_MODEL1_acc_LookUp_real_T_real_T ( real_T * pY , const real_T * pYData ,
real_T u , const real_T * pUData , uint32_T iHi ) { uint32_T iLeft ; uint32_T
iRght ; AFCS_MODEL1_acc_BINARYSEARCH_real_T ( & ( iLeft ) , & ( iRght ) , u ,
pUData , iHi ) ; { real_T lambda ; if ( pUData [ iRght ] > pUData [ iLeft ] )
{ real_T num ; real_T den ; den = pUData [ iRght ] ; den -= pUData [ iLeft ]
; num = u ; num -= pUData [ iLeft ] ; lambda = num / den ; } else { lambda =
0.0 ; } { real_T yLeftCast ; real_T yRghtCast ; yLeftCast = pYData [ iLeft ]
; yRghtCast = pYData [ iRght ] ; yLeftCast += lambda * ( yRghtCast -
yLeftCast ) ; ( * pY ) = yLeftCast ; } } } void wgs84_taylor_series ( real_T
* h , real_T * phi , real_T opt_m2ft , real_T * y , int_T k ) { real_T
gamma_ts , m , sinphi , sin2phi ; int_T i ; for ( i = 0 ; i < k ; i ++ ) {
sinphi = muDoubleScalarSin ( phi [ i ] ) ; sin2phi = sinphi * sinphi ;
gamma_ts = ( WGS84_G_E ) * ( 1.0 + ( WGS84_K ) * sin2phi ) / (
muDoubleScalarSqrt ( 1.0 - ( WGS84_E_2 ) * sin2phi ) ) ; m = ( WGS84_A ) * (
WGS84_A ) * ( WGS84_B ) * ( WGS84_W_DEF ) * ( WGS84_W_DEF ) / ( WGS84_GM_DEF
) ; y [ i ] = opt_m2ft * gamma_ts * ( 1.0 - 2.0 * ( 1.0 + 1.0 / ( WGS84_INV_F
) + m - 2.0 * sin2phi / ( WGS84_INV_F ) ) * h [ i ] / ( WGS84_A ) + 3.0 * h [
i ] * h [ i ] / ( ( WGS84_A ) * ( WGS84_A ) ) ) ; } } real32_T
look1_iflf_binlcpw ( real32_T u0 , const real32_T bp0 [ ] , const real32_T
table [ ] , uint32_T maxIndex ) { real32_T frac ; uint32_T iRght ; uint32_T
iLeft ; uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = 0.0F ;
} else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ;
iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) {
iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ;
} frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; }
else { iLeft = maxIndex - 1U ; frac = 1.0F ; } return ( table [ iLeft + 1U ]
- table [ iLeft ] ) * frac + table [ iLeft ] ; } real32_T look1_iflf_binlxpw
( real32_T u0 , const real32_T bp0 [ ] , const real32_T table [ ] , uint32_T
maxIndex ) { real32_T frac ; uint32_T iRght ; uint32_T iLeft ; uint32_T bpIdx
; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / ( bp0 [
1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) { bpIdx = maxIndex
>> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght - iLeft > 1U ) { if (
u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = (
iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) / ( bp0 [ iLeft + 1U
] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ; frac = ( u0 - bp0 [
maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex - 1U ] ) ; } return (
table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [ iLeft ] ; } real_T
look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) { real_T frac ; uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [
0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex ] ) {
bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght -
iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } return ( table [ iLeft + 1U ] - table [ iLeft ] ) * frac + table [
iLeft ] ; } real_T look2_binlxpw ( real_T u0 , real_T u1 , const real_T bp0 [
] , const real_T bp1 [ ] , const real_T table [ ] , const uint32_T maxIndex [
] , uint32_T stride ) { real_T frac ; uint32_T bpIndices [ 2 ] ; real_T
fractions [ 2 ] ; real_T yL_1d ; uint32_T iRght ; uint32_T bpIdx ; uint32_T
iLeft ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 - bp0 [ 0U ] ) / (
bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex [ 0U ] ] ) {
bpIdx = maxIndex [ 0U ] >> 1U ; iLeft = 0U ; iRght = maxIndex [ 0U ] ; while
( iRght - iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else {
iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [
iLeft ] ) / ( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft =
maxIndex [ 0U ] - 1U ; frac = ( u0 - bp0 [ maxIndex [ 0U ] - 1U ] ) / ( bp0 [
maxIndex [ 0U ] ] - bp0 [ maxIndex [ 0U ] - 1U ] ) ; } fractions [ 0U ] =
frac ; bpIndices [ 0U ] = iLeft ; if ( u1 <= bp1 [ 0U ] ) { iLeft = 0U ; frac
= ( u1 - bp1 [ 0U ] ) / ( bp1 [ 1U ] - bp1 [ 0U ] ) ; } else if ( u1 < bp1 [
maxIndex [ 1U ] ] ) { bpIdx = maxIndex [ 1U ] >> 1U ; iLeft = 0U ; iRght =
maxIndex [ 1U ] ; while ( iRght - iLeft > 1U ) { if ( u1 < bp1 [ bpIdx ] ) {
iRght = bpIdx ; } else { iLeft = bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ;
} frac = ( u1 - bp1 [ iLeft ] ) / ( bp1 [ iLeft + 1U ] - bp1 [ iLeft ] ) ; }
else { iLeft = maxIndex [ 1U ] - 1U ; frac = ( u1 - bp1 [ maxIndex [ 1U ] -
1U ] ) / ( bp1 [ maxIndex [ 1U ] ] - bp1 [ maxIndex [ 1U ] - 1U ] ) ; } bpIdx
= iLeft * stride + bpIndices [ 0U ] ; yL_1d = ( table [ bpIdx + 1U ] - table
[ bpIdx ] ) * fractions [ 0U ] + table [ bpIdx ] ; bpIdx += stride ; return (
( ( table [ bpIdx + 1U ] - table [ bpIdx ] ) * fractions [ 0U ] + table [
bpIdx ] ) - yL_1d ) * frac + yL_1d ; } void cypz4slwdy ( SimStruct * const S
) { plshtxiahf * _rtB ; cvqdcwnzy0 * _rtP ; f5cp4dpc1i * _rtDW ; _rtDW = ( (
f5cp4dpc1i * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( cvqdcwnzy0 * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) )
; _rtDW -> k31zamqwau = _rtP -> P_1748 ; _rtDW -> pcas5y24f1 = _rtP -> P_1226
; ssCallAccelRunBlock ( S , 29 , 12 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 25 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 35 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 37 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 45 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 52 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 54 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
_rtDW -> mssvcbjhns = _rtP -> P_1755 ; _rtDW -> eebzwbkqux = _rtP -> P_1241 ;
ssCallAccelRunBlock ( S , 29 , 90 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 102 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 110 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 116 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 134 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 142 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 146 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 161 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 164 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 166 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 174 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 178 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 180 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
_rtDW -> eku14anuxp = _rtP -> P_1764 ; ssCallAccelRunBlock ( S , 29 , 188 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; _rtDW -> b5qdxu3cgk = _rtP -> P_1769 ;
_rtDW -> icjuziyhaa = _rtP -> P_1284 ; ssCallAccelRunBlock ( S , 29 , 200 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; _rtDW -> i4loudfi5t = _rtP -> P_1296 ;
ssCallAccelRunBlock ( S , 29 , 238 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 240 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 241 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 257 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 264 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 266 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 267 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 283 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 290 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 292 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 293 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 308 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 319 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 321 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
_rtDW -> o2svirmeko = _rtP -> P_1781 ; _rtDW -> j20ho5ma0c = _rtP -> P_1319 ;
ssCallAccelRunBlock ( S , 29 , 338 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 344 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 357 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 358 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 379 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 381 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
_rtDW -> oq2egqnko0 = _rtP -> P_1789 ; _rtDW -> no0uqcvsm0 = _rtP -> P_1337 ;
ssCallAccelRunBlock ( S , 29 , 398 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 403 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 420 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 421 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 433 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 440 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 449 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 454 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 455 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 469 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 478 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 481 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 482 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 484 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 492 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
ssCallAccelRunBlock ( S , 29 , 496 , SS_CALL_MDL_INITIALIZE_CONDITIONS ) ;
_rtDW -> orfcazlkjt = _rtP -> P_1795 ; _rtDW -> mn55pcip1b = _rtP -> P_1393 ;
_rtDW -> awidbghbmk = _rtP -> P_1395 ; ssCallAccelRunBlock ( S , 29 , 537 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; ssCallAccelRunBlock ( S , 29 , 543 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; ssCallAccelRunBlock ( S , 29 , 552 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; ssCallAccelRunBlock ( S , 29 , 554 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; ssCallAccelRunBlock ( S , 29 , 574 ,
SS_CALL_MDL_INITIALIZE_CONDITIONS ) ; } void jtjpxjywrw ( SimStruct * const S
) { int8_T fbsmhtaaer ; real32_T tmp ; plshtxiahf * _rtB ; cvqdcwnzy0 * _rtP
; f5cp4dpc1i * _rtDW ; _rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S ) ) ;
_rtP = ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( plshtxiahf * )
_ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
mgq4wwdpfa = _rtP -> P_1744 ; _rtB -> nphuwzdxo1 = _rtP -> P_1746 ; } if (
_rtB -> nxl5ohwsbx > _rtP -> P_1745 ) { fbsmhtaaer = _rtB -> fqurfvkusw ; }
else { fbsmhtaaer = _rtB -> mgq4wwdpfa ; } _rtB -> awprwuqhz0 = ( int8_T ) (
fbsmhtaaer == _rtB -> nphuwzdxo1 ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> eofu2yewky = _rtP -> P_1225 ; _rtB -> jklvgrk3ta = _rtP -> P_1747 ;
_rtB -> agipupt11m = _rtDW -> k31zamqwau ; _rtB -> m24uisj1y3 = ( _rtB ->
jklvgrk3ta > _rtB -> agipupt11m ) ; _rtB -> e0tcwc3ajd = _rtDW -> pcas5y24f1
; if ( _rtB -> m24uisj1y3 ) { _rtB -> lo3cnh5xyj = _rtB -> npfd1fa2f3 [ 5 ] ;
} else { _rtB -> lo3cnh5xyj = _rtB -> e0tcwc3ajd ; } } if ( _rtB ->
nxl5ohwsbx > _rtP -> P_1749 ) { _rtB -> p01we5wcra = _rtB -> e3tqcoo3b5 ; }
else { _rtB -> p01we5wcra = _rtB -> b3afosm4iw [ 3 ] ; } ssCallAccelRunBlock
( S , 29 , 12 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> j2qlcuiqpq = _rtP -> P_1750 ; _rtB -> lfpfcgr0uo = _rtP -> P_1227 ;
_rtB -> jvzwcf4mwq = _rtP -> P_1228 ; _rtB -> geecewrzqi = _rtP -> P_1229 ; }
_rtB -> aimyjresxu = ( fbsmhtaaer == _rtB -> j2qlcuiqpq ) ; _rtB ->
bwfe0lj1qw = ( int8_T ) _rtB -> aimyjresxu ; _rtB -> oy220qugqx = _rtB ->
hmgqxihgml - _rtB -> pgghzidifi ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> pcr4z1jzia = _rtP -> P_1230 ; _rtB -> pzozhxz2mc = _rtP -> P_1231 ; }
ssCallAccelRunBlock ( S , 29 , 22 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mffcqtg4nc = _rtP -> P_1232 ; }
ssCallAccelRunBlock ( S , 29 , 24 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 25 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> aidqniilx5 = _rtP -> P_1233 ; _rtB ->
evrbucrb04 = _rtP -> P_1234 ; _rtB -> ebjuk05mqq = _rtP -> P_1235 ; } _rtB ->
itg3sfsstk = ( _rtB -> lo3cnh5xyj - _rtB -> aidqniilx5 ) - _rtB -> i0frkaixst
; ssCallAccelRunBlock ( S , 29 , 30 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hdh1mputt1 = _rtB -> aidqniilx5 + _rtB -> bcsdxyuh3w ; _rtB -> knbxtmehcc = (
0.0F - _rtB -> aidqniilx5 ) - _rtB -> bcsdxyuh3w ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> ai3pj0qoqy = _rtP -> P_1236 ; } ssCallAccelRunBlock ( S ,
29 , 34 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 35 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> l25vavve3q = ( _rtB -> lfpfcgr0uo + _rtB ->
i0frkaixst ) + _rtB -> bupblu5bao ; ssCallAccelRunBlock ( S , 29 , 37 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
lek52wqjzx = _rtP -> P_1751 ; _rtB -> nzjj3ppvhy = _rtP -> P_1237 ; } _rtB ->
oyzdejqsle = ( fbsmhtaaer == _rtB -> lek52wqjzx ) ; _rtB -> gwgrbs31uj = (
int8_T ) _rtB -> oyzdejqsle ; _rtB -> ipb2jmkt1q = _rtB -> hmgqxihgml - _rtB
-> cxaqvo5102 ; ssCallAccelRunBlock ( S , 29 , 43 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 44 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 45 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> j13v4gp5hn = _rtP -> P_1238 ; } _rtB
-> k4tclpevqc = ( _rtB -> lo3cnh5xyj - _rtB -> f3hznho0ng ) - _rtB ->
j13v4gp5hn ; ssCallAccelRunBlock ( S , 29 , 48 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> iygzjd5bsw = _rtB -> j13v4gp5hn + _rtB -> emvpkqux41 ; _rtB -> lyorby3nno
= ( 0.0F - _rtB -> j13v4gp5hn ) - _rtB -> emvpkqux41 ; ssCallAccelRunBlock (
S , 29 , 51 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 52 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bonsrc2hvv = ( _rtB -> nzjj3ppvhy + _rtB ->
f3hznho0ng ) + _rtB -> jqeqy23zar ; ssCallAccelRunBlock ( S , 29 , 54 ,
SS_CALL_MDL_OUTPUTS ) ; switch ( fbsmhtaaer ) { case 1 : _rtB -> ah0ctnhrkd =
_rtB -> pqzns4hdd5 ; break ; case 2 : _rtB -> ah0ctnhrkd = _rtB -> pljkhw1hrm
; break ; default : _rtB -> ah0ctnhrkd = _rtB -> dakcjuajjg ; break ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> k3120xcrc4 = _rtP -> P_1752 ; _rtB ->
hpyyke3srq = _rtP -> P_1754 ; } if ( _rtB -> nxl5ohwsbx > _rtP -> P_1753 ) {
_rtB -> faoaexww3x = _rtB -> in2east53k ; } else { _rtB -> faoaexww3x = _rtB
-> k3120xcrc4 ; } _rtB -> lri3ms2vtq = ( _rtB -> faoaexww3x == _rtB ->
hpyyke3srq ) ; _rtB -> eenuuhyyrb = ( int8_T ) _rtB -> lri3ms2vtq ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ljp4llnua4 = _rtP -> P_1239 ; _rtB ->
iu0fw3kasf = _rtP -> P_1240 ; _rtB -> aksltyifow = _rtDW -> mssvcbjhns ; _rtB
-> dto5r1sgxl = ( _rtB -> jklvgrk3ta > _rtB -> aksltyifow ) ; _rtB ->
iylrvuc3al = _rtDW -> eebzwbkqux ; if ( _rtB -> dto5r1sgxl ) { _rtB ->
f2dyagzzm4 = _rtB -> iu0fw3kasf ; } else { _rtB -> f2dyagzzm4 = _rtB ->
iylrvuc3al ; } _rtB -> iahdqlu3cj = _rtP -> P_1242 ; _rtB -> nxnmc45uro =
_rtP -> P_1243 ; _rtB -> llf3bosgcd = _rtP -> P_1244 ; _rtB -> af54wboz3g =
_rtP -> P_1245 ; } _rtB -> c5qxbt4u4a = _rtB -> l2i5ftwcqq - _rtB ->
o22lf041rw ; ssCallAccelRunBlock ( S , 29 , 72 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> dsacg0neqs = _rtP -> P_1246 ; }
ssCallAccelRunBlock ( S , 29 , 74 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
iebtux4sot > _rtP -> P_1247 ) { _rtB -> o1xqnh11u2 = _rtP -> P_1247 ; } else
if ( _rtB -> iebtux4sot < _rtP -> P_1248 ) { _rtB -> o1xqnh11u2 = _rtP ->
P_1248 ; } else { _rtB -> o1xqnh11u2 = _rtB -> iebtux4sot ; } _rtB ->
otux03ojwx = _rtP -> P_1249 * _rtB -> o1xqnh11u2 ; _rtB -> h1swdkn3mb =
muSingleScalarCos ( _rtB -> otux03ojwx ) ; _rtB -> itombddt5s =
muSingleScalarAbs ( _rtB -> h1swdkn3mb ) ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> ptz4251kla = _rtP -> P_1250 ; _rtB -> gw2rpdjh0l = _rtP -> P_1251 ;
_rtB -> bd3wisz4cw = _rtP -> P_1252 ; } _rtB -> jomm4z0oq5 = _rtB ->
f2dyagzzm4 * _rtB -> itombddt5s / _rtB -> ptz4251kla ; ssCallAccelRunBlock (
S , 29 , 83 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> gbdqrec5um = _rtB -> l23gmnayat
+ _rtB -> j2n514retq ; _rtB -> cre3qrieuc = _rtB -> gbdqrec5um - _rtB ->
h1h525dcgv ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gmhpidnccj = _rtP
-> P_1253 ; _rtB -> pjoptikb2b = _rtP -> P_1254 ; _rtB -> pcrkaqsoch = _rtP
-> P_1255 ; } ssCallAccelRunBlock ( S , 29 , 89 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 90 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jnkabx2pov = _rtB -> aledout1t1 + _rtB -> h1h525dcgv ; if ( _rtB ->
jnkabx2pov > _rtP -> P_1256 ) { _rtB -> kwwy0zuwzv = _rtP -> P_1256 ; } else
if ( _rtB -> jnkabx2pov < _rtP -> P_1257 ) { _rtB -> kwwy0zuwzv = _rtP ->
P_1257 ; } else { _rtB -> kwwy0zuwzv = _rtB -> jnkabx2pov ; } _rtB ->
kpxa2prvnm = _rtP -> P_1258 * _rtB -> f31wh1hvbz ; if ( _rtB -> nxl5ohwsbx >
_rtP -> P_1756 ) { _rtB -> c3j2kjphvw = _rtB -> fmwca5uacb ; } else { _rtB ->
c3j2kjphvw = _rtB -> kpxa2prvnm ; } _rtB -> jg40ysni0n = _rtP -> P_1259 *
_rtB -> c3j2kjphvw ; _rtB -> pwqycbxhqm = muSingleScalarSin ( _rtB ->
jg40ysni0n ) ; _rtB -> ft3dxeh0fa = _rtB -> pgghzidifi * _rtB -> pwqycbxhqm ;
_rtB -> pvkn5dc5og = ( _rtB -> kwwy0zuwzv - _rtB -> j2n514retq ) + _rtB ->
ft3dxeh0fa ; ssCallAccelRunBlock ( S , 29 , 99 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 100 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
dlm0kquggp = _rtB -> apzdjlsv5o / _rtB -> itombddt5s ; ssCallAccelRunBlock (
S , 29 , 102 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> i53svn4btu =
look1_iflf_binlcpw ( _rtB -> g4rqw1aoxq , _rtP -> P_1261 , _rtP -> P_1260 ,
6U ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> c2fxlwe0fd = _rtP ->
P_1262 ; _rtB -> biloxrriml = _rtP -> P_1265 ; } _rtB -> ku5nw3tnpj = _rtB ->
i53svn4btu * _rtB -> c2fxlwe0fd ; _rtB -> d2wqwjbhgy = look1_iflf_binlcpw (
_rtB -> g4rqw1aoxq , _rtP -> P_1264 , _rtP -> P_1263 , 6U ) ; _rtB ->
lwzxd0ff0f = _rtB -> d2wqwjbhgy * _rtB -> biloxrriml ; ssCallAccelRunBlock (
S , 29 , 109 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 110 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
dotjhn4nxs = _rtP -> P_1757 ; _rtB -> p1tv4qpwbj = _rtP -> P_1266 ; } _rtB ->
l0rrmvyiyb = ( _rtB -> faoaexww3x == _rtB -> dotjhn4nxs ) ; _rtB ->
cdyvzuqglk = ( int8_T ) _rtB -> l0rrmvyiyb ; ssCallAccelRunBlock ( S , 29 ,
115 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 116 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
nvvpqfafvc = _rtP -> P_1758 ; _rtB -> mxbiphvofq = _rtP -> P_1267 ; _rtB ->
opzd1apvy5 = _rtP -> P_1268 ; if ( _rtB -> joh40kiala > _rtP -> P_1759 ) {
_rtB -> gdmxiavdmh = _rtP -> P_1220 ; } else { _rtB -> gdmxiavdmh = _rtP ->
P_1219 ; } } _rtB -> gyux2sz5ka = ( _rtB -> faoaexww3x == _rtB -> nvvpqfafvc
) ; _rtB -> puzjc211d5 = ( int8_T ) _rtB -> gyux2sz5ka ; if ( _rtB ->
nxl5ohwsbx > _rtP -> P_1760 ) { _rtB -> gksc1sspuq = _rtB -> at0odbf5nx ; }
else { _rtB -> gksc1sspuq = _rtB -> kpxa2prvnm + _rtB -> gdmxiavdmh ; } _rtB
-> mrx3s1smkw = _rtB -> gksc1sspuq - _rtB -> i015g3sofk ; ssCallAccelRunBlock
( S , 29 , 128 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> hg5p5c1qle = _rtP -> P_1269 ; _rtB -> j1tstmhoio = _rtP -> P_1270 ; }
ssCallAccelRunBlock ( S , 29 , 131 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> kubm2s35fc = _rtP -> P_1271 ; }
ssCallAccelRunBlock ( S , 29 , 133 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 134 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 135 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> d2pi3dijs2 = _rtB -> fl232yglvc ;
_rtB -> ewp55e23rj = _rtP -> P_1272 ; _rtB -> cw2h4mvgmm = _rtP -> P_1273 ;
_rtB -> pz1f2krlbj = _rtP -> P_1274 ; } _rtB -> iu1z2wkuva = _rtB ->
b1apgnyjax - _rtB -> cw2h4mvgmm ; _rtB -> pl14ja32mh = _rtB -> b1apgnyjax -
_rtB -> pz1f2krlbj ; ssCallAccelRunBlock ( S , 29 , 142 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fnljrndmny = _rtP -> P_1275
; } ssCallAccelRunBlock ( S , 29 , 144 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
g5lekckujw = _rtB -> dyffae1ayr - _rtB -> jo4dyodysw ; ssCallAccelRunBlock (
S , 29 , 146 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> ipflei0rvx = _rtP -> P_1761 ; _rtB -> idwdpt4ehi = _rtP -> P_1277 ;
_rtB -> dr1rbafvpq = _rtP -> P_1278 ; } _rtB -> ppeyq0ebuv = ( _rtB ->
faoaexww3x == _rtB -> ipflei0rvx ) ; _rtB -> hevb1vd3dy = ( int8_T ) _rtB ->
ppeyq0ebuv ; _rtB -> oo42fttlod = _rtP -> P_1279 * _rtB -> c3j2kjphvw ; _rtB
-> jpyst2d35b = muSingleScalarSin ( _rtB -> oo42fttlod ) ; _rtB -> ncs2y4jygo
= _rtB -> pgghzidifi * _rtB -> jpyst2d35b ; _rtB -> et1i2bwxgg = _rtB ->
ncs2y4jygo - _rtB -> j2n514retq ; ssCallAccelRunBlock ( S , 29 , 157 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 158 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
fayua5gr1o = _rtP -> P_1280 ; } ssCallAccelRunBlock ( S , 29 , 160 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 161 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> hny0mmfjex = _rtB -> c0qkqy1dca + _rtB ->
h1nq4uhgew ; _rtB -> lm0usodvej = _rtB -> hny0mmfjex / _rtB -> itombddt5s ;
ssCallAccelRunBlock ( S , 29 , 164 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 165 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 166 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> pk5fx35aer = _rtP -> P_1762 ; } _rtB
-> femfspdar5 = ( _rtB -> faoaexww3x == _rtB -> pk5fx35aer ) ; _rtB ->
iscj0vtzdl = ( int8_T ) _rtB -> femfspdar5 ; _rtB -> ngygrz43ha = _rtB ->
khyrz5hnuy - _rtB -> j2n514retq ; ssCallAccelRunBlock ( S , 29 , 171 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 172 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 173 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 174 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> c4j3qswp34 = _rtB -> obcct4w4r1 + _rtB ->
ovzmqpcxbb ; _rtB -> njqc4ztne4 = _rtP -> P_1281 * _rtB -> itombddt5s ; _rtB
-> kxmdkoblc1 = _rtB -> c4j3qswp34 / _rtB -> njqc4ztne4 ; ssCallAccelRunBlock
( S , 29 , 178 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 179 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 180 ,
SS_CALL_MDL_OUTPUTS ) ; switch ( _rtB -> faoaexww3x ) { case 1 : _rtB ->
o0evy5frin = _rtB -> krp0gvpdzj ; break ; case 2 : _rtB -> o0evy5frin = _rtB
-> feinq0ghp2 ; break ; case 3 : _rtB -> o0evy5frin = _rtB -> aakxfrsuhn ;
break ; case 4 : _rtB -> o0evy5frin = _rtB -> bgkfukondw ; break ; default :
_rtB -> o0evy5frin = _rtB -> dyzeormzn2 ; break ; } if ( ssIsSampleHit ( S ,
1 , 0 ) ) { _rtB -> pywkille4n = _rtP -> P_1763 ; _rtB -> ldtwu1ehvx = _rtDW
-> eku14anuxp ; _rtB -> d0xzog13se = _rtP -> P_1765 ; } _rtB -> p1ud3celr5 =
( _rtB -> nxl5ohwsbx == _rtB -> ldtwu1ehvx ) ; if ( _rtB -> p1ud3celr5 ) {
_rtB -> d24qm4jpii = _rtB -> pywkille4n ; } else { _rtB -> d24qm4jpii = _rtB
-> d0xzog13se ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ipejsl4apz =
_rtP -> P_1282 ; } ssCallAccelRunBlock ( S , 29 , 188 , SS_CALL_MDL_OUTPUTS )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ptbryu5egx = _rtP -> P_1766 ;
_rtB -> k5mbwuziwv = _rtP -> P_1768 ; } if ( _rtB -> nxl5ohwsbx > _rtP ->
P_1767 ) { _rtB -> nbqtyrl0wh = _rtB -> aexpvbgytv ; } else { _rtB ->
nbqtyrl0wh = _rtB -> ptbryu5egx ; } _rtB -> kc4nnimqis = ( _rtB -> nbqtyrl0wh
== _rtB -> k5mbwuziwv ) ; _rtB -> p042l04iee = ( int8_T ) _rtB -> kc4nnimqis
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gxdc5kdwou = _rtP -> P_1283 ;
_rtB -> fmfua2pci4 = _rtDW -> b5qdxu3cgk ; _rtB -> ecpwzhte1f = ( _rtB ->
jklvgrk3ta > _rtB -> fmfua2pci4 ) ; _rtB -> g0pkngj4yc = _rtDW -> icjuziyhaa
; if ( _rtB -> ecpwzhte1f ) { _rtB -> drojuzwlvn = _rtB -> iu0fw3kasf ; }
else { _rtB -> drojuzwlvn = _rtB -> g0pkngj4yc ; } _rtB -> ioivpdzywv = _rtP
-> P_1285 ; } ssCallAccelRunBlock ( S , 29 , 200 , SS_CALL_MDL_OUTPUTS ) ; if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jeybb2ahse = _rtP -> P_1770 ; _rtB
-> infjrmca0l = _rtP -> P_1286 ; _rtB -> fnl32danvj = _rtP -> P_1287 ; } _rtB
-> b5llmsebv0 = ( _rtB -> nbqtyrl0wh == _rtB -> jeybb2ahse ) ; _rtB ->
allun3vwx4 = ( int8_T ) _rtB -> b5llmsebv0 ; if ( _rtB -> nxl5ohwsbx > _rtP
-> P_1771 ) { _rtB -> kbbild32rl = _rtB -> g3mwa1cel2 ; } else { _rtB ->
kbbild32rl = _rtP -> P_1218 * _rtB -> man0rjdp2u ; } _rtB -> mfmqkopgwa =
_rtB -> kbbild32rl - _rtB -> iebtux4sot ; ssCallAccelRunBlock ( S , 29 , 209
, SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
coguo0q1px = _rtP -> P_1288 ; _rtB -> a5f2p0bpyo = _rtP -> P_1289 ; }
ssCallAccelRunBlock ( S , 29 , 212 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ocmsashg2v = _rtP -> P_1290 ; }
ssCallAccelRunBlock ( S , 29 , 214 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
krr3rbgz0k = _rtB -> drojuzwlvn - _rtB -> cwkriiigob ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> l0hokfzfup = _rtP -> P_1291 ; _rtB -> nnt22uinye = _rtP
-> P_1292 ; _rtB -> kruzqjore1 = _rtP -> P_1293 ; } ssCallAccelRunBlock ( S ,
29 , 219 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> pa0jppyjg0 = _rtP -> P_1294 ; _rtB -> dqmtcrq5fe = _rtP -> P_1772 ; _rtB
-> bgo3pmhacn = _rtP -> P_1773 ; } _rtB -> jqim5op3ec = ( _rtB -> azarpgjmdw
== _rtB -> dqmtcrq5fe ) ; _rtB -> hgsrhhxa3j = ( _rtB -> eubvsps4x2 == _rtB
-> bgo3pmhacn ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> m3zfuixou3 =
_rtP -> P_1774 ; _rtB -> lja0r5gxhi = ( _rtB -> hwjnvq2h4q == _rtB ->
m3zfuixou3 ) ; _rtB -> hyqnvw402z = _rtP -> P_1295 ; } _rtB -> pol40qovdb = (
_rtB -> jqim5op3ec || _rtB -> hgsrhhxa3j || _rtB -> lja0r5gxhi ) ; if ( _rtB
-> pol40qovdb ) { _rtB -> mc0ekjdgga = _rtB -> pa0jppyjg0 ; } else { _rtB ->
mc0ekjdgga = _rtB -> hyqnvw402z ; } _rtB -> pkqifsjqld = _rtB -> aawom52oge *
_rtB -> mc0ekjdgga ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> k20rom2gpd
= _rtDW -> i4loudfi5t ; _rtB -> jqxfb5nhr4 = _rtP -> P_1297 ;
ssCallAccelRunBlock ( S , 29 , 233 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
g2ofm02f0d = _rtP -> P_1298 ; } if ( _rtB -> pol40qovdb ) { _rtB ->
jcfqsyl34q = _rtB -> hyqnvw402z ; } else { _rtB -> jcfqsyl34q = _rtB ->
g2ofm02f0d ; } _rtB -> hb5hxpn41s = _rtB -> annu0klotf * _rtB -> jcfqsyl34q ;
_rtB -> iohy3miqc5 = _rtB -> pkqifsjqld - _rtB -> hb5hxpn41s ;
ssCallAccelRunBlock ( S , 29 , 238 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
eyt4gulkbo = _rtB -> cwkriiigob + _rtB -> hscesoihit ; ssCallAccelRunBlock (
S , 29 , 240 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 241 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
plmpvlb42g = _rtP -> P_1775 ; } _rtB -> c5h24pfvva = ( _rtB -> nbqtyrl0wh ==
_rtB -> plmpvlb42g ) ; _rtB -> ogy5uvpt52 = ( int8_T ) _rtB -> c5h24pfvva ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jf1qjmjvda = _rtP -> P_1299 ;
_rtB -> jzwqbf0mfn = _rtP -> P_1300 ; _rtB -> bsij3xn2l4 = _rtB -> drojuzwlvn
/ _rtB -> ocmsashg2v ; ssCallAccelRunBlock ( S , 29 , 248 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> hums40swg0 = ( _rtB -> iebtux4sot + _rtB ->
ovhyr0nyjd ) - _rtB -> kbbild32rl ; _rtB -> oa0nrlyezs = _rtB -> oug4gaxwzn -
_rtB -> axzozhbobc ; ssCallAccelRunBlock ( S , 29 , 251 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fottw5vaqm = _rtP -> P_1301
; _rtB -> efvvg15gu5 = _rtP -> P_1302 ; } ssCallAccelRunBlock ( S , 29 , 254
, SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
cgnzbrvzj3 = _rtP -> P_1303 ; } ssCallAccelRunBlock ( S , 29 , 256 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 257 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> dsrrbemnxf = ( _rtB -> a2pw2azc5l - _rtB ->
iebtux4sot ) + _rtB -> kbbild32rl ; ssCallAccelRunBlock ( S , 29 , 259 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 260 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 261 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
gfuxfp4wzq = _rtP -> P_1304 ; } ssCallAccelRunBlock ( S , 29 , 263 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 264 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jne2e1oyta = _rtB -> ink0paocot + _rtB ->
lg4bz0gnr1 ; ssCallAccelRunBlock ( S , 29 , 266 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 267 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> b0sgj3h100 = _rtP -> P_1776 ; } _rtB
-> kvy5yc3ybp = ( _rtB -> nbqtyrl0wh == _rtB -> b0sgj3h100 ) ; _rtB ->
lghbiq4b1v = ( int8_T ) _rtB -> kvy5yc3ybp ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> ezc41lh3lg = _rtP -> P_1305 ; _rtB -> og0bw4oxii = _rtP -> P_1306
; _rtB -> bzkytto1ge = _rtB -> drojuzwlvn / _rtB -> ocmsashg2v ;
ssCallAccelRunBlock ( S , 29 , 274 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
hdch3aezjm = ( _rtB -> iebtux4sot + _rtB -> pej4po3zda ) - _rtB -> kbbild32rl
; _rtB -> lskemobkh4 = _rtB -> fxy1ga2ryu - _rtB -> biih154ez0 ;
ssCallAccelRunBlock ( S , 29 , 277 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cgpl52rdok = _rtP -> P_1307 ; _rtB ->
ba4ls3ejol = _rtP -> P_1308 ; } ssCallAccelRunBlock ( S , 29 , 280 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
e3lybckacu = _rtP -> P_1309 ; } ssCallAccelRunBlock ( S , 29 , 282 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 283 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 284 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> lo5egb1piv = ( _rtB -> jnitgphvhh - _rtB ->
iebtux4sot ) + _rtB -> kbbild32rl ; ssCallAccelRunBlock ( S , 29 , 286 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 287 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
cb1jepfeag = _rtP -> P_1310 ; } ssCallAccelRunBlock ( S , 29 , 289 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 290 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> fg5l5pojjh = _rtB -> kjtdxh5xpy + _rtB ->
oedmrsrqfo ; ssCallAccelRunBlock ( S , 29 , 292 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 293 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fy5mlhejz3 = _rtP -> P_1777 ; _rtB ->
oc1nvem31t = _rtP -> P_1312 ; _rtB -> jmegcs2bdf = _rtP -> P_1313 ; } _rtB ->
donuol2bqv = ( _rtB -> nbqtyrl0wh == _rtB -> fy5mlhejz3 ) ; _rtB ->
ackbri2i1a = ( int8_T ) _rtB -> donuol2bqv ; _rtB -> ntpacwgimv = _rtB ->
nntkxivcmj - _rtB -> nyy4wjj131 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> itfysnuhka = _rtP -> P_1314 ; _rtB -> cisljholhh = _rtP -> P_1315 ; }
ssCallAccelRunBlock ( S , 29 , 303 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lyf2zr450m = _rtP -> P_1316 ; }
ssCallAccelRunBlock ( S , 29 , 305 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> j2ijwcg2ko = _rtP -> P_1317 ; }
ssCallAccelRunBlock ( S , 29 , 307 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 308 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cuf5bzotyy = _rtB -> jpz5fcclm1 + _rtB -> gou3fl4ste ; _rtB -> kk0pfd22np = (
_rtB -> cuf5bzotyy - _rtB -> biih154ez0 ) + _rtB -> fxy1ga2ryu ;
ssCallAccelRunBlock ( S , 29 , 311 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 312 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 313 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 314 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ehmphdqmr2 = ( _rtB -> modcz0bff2 - _rtB -> iebtux4sot ) + _rtB -> kbbild32rl
; ssCallAccelRunBlock ( S , 29 , 316 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 317 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cfxj2up0ut = _rtB -> c4qljjm1jj ; ssCallAccelRunBlock ( S , 29 , 319 ,
SS_CALL_MDL_OUTPUTS ) ; switch ( _rtB -> nbqtyrl0wh ) { case 1 : _rtB ->
kvslbjzt04 = _rtB -> l5bpewqg2f ; break ; case 2 : _rtB -> kvslbjzt04 = _rtB
-> fx3yvlgw4f ; break ; case 3 : _rtB -> kvslbjzt04 = _rtB -> mfyq43rsv5 ;
break ; case 4 : _rtB -> kvslbjzt04 = _rtB -> ppyauida4x ; break ; default :
_rtB -> kvslbjzt04 = _rtB -> f4me1mqwzo ; break ; } ssCallAccelRunBlock ( S ,
29 , 321 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> nsubagts33 = _rtB -> drojuzwlvn / _rtB -> ocmsashg2v ; ssCallAccelRunBlock
( S , 29 , 323 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> eketwxi0f1 = ( _rtB ->
iebtux4sot + _rtB -> at2b2di414 ) - _rtB -> kbbild32rl ; _rtB -> d1ardcljj1 =
_rtB -> eketwxi0f1 / _rtB -> e3lybckacu ; ssCallAccelRunBlock ( S , 29 , 326
, SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
nbufhgwzrl = _rtP -> P_1778 ; _rtB -> e4tax5uich = _rtP -> P_1780 ; } if (
_rtB -> nxl5ohwsbx > _rtP -> P_1779 ) { _rtB -> hee1k0eaps = _rtB ->
drwv015lkz ; } else { _rtB -> hee1k0eaps = _rtB -> nbufhgwzrl ; } _rtB ->
f5ggfsewpr = ( _rtB -> hee1k0eaps == _rtB -> e4tax5uich ) ; _rtB ->
mlk0yao1up = ( int8_T ) _rtB -> f5ggfsewpr ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> cjq3chbkd4 = _rtP -> P_1318 ; _rtB -> laow3e4cad = _rtDW ->
o2svirmeko ; _rtB -> op0nhjnyqj = ( _rtB -> jklvgrk3ta > _rtB -> laow3e4cad )
; _rtB -> bfpacjyfmx = _rtDW -> j20ho5ma0c ; if ( _rtB -> op0nhjnyqj ) { _rtB
-> jmo3szahxc = _rtB -> iu0fw3kasf ; } else { _rtB -> jmo3szahxc = _rtB ->
bfpacjyfmx ; } _rtB -> hav0zbe130 = _rtP -> P_1320 ; } ssCallAccelRunBlock (
S , 29 , 338 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> iim2qqadv5 = _rtP -> P_1782 ; } _rtB -> kxoyqe3nrh = ( _rtB ->
hee1k0eaps == _rtB -> iim2qqadv5 ) ; _rtB -> mtfeh0jswq = ( int8_T ) _rtB ->
kxoyqe3nrh ; _rtB -> n4d3l4anw3 = _rtP -> P_1321 * _rtB -> id44smfryn ; if (
_rtB -> nxl5ohwsbx > _rtP -> P_1783 ) { _rtB -> pgbfmcna4v = _rtB ->
ljqi4bmnhe ; } else { _rtB -> pgbfmcna4v = _rtB -> n4d3l4anw3 ; }
ssCallAccelRunBlock ( S , 29 , 344 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bafvanugn3 = _rtP -> P_1784 ; _rtB ->
kzchjjbun5 = _rtP -> P_1322 ; _rtB -> csratucu1b = _rtP -> P_1323 ; } _rtB ->
fn3mi0rzwf = ( _rtB -> hee1k0eaps == _rtB -> bafvanugn3 ) ; _rtB ->
drzrn4rdn0 = ( int8_T ) _rtB -> fn3mi0rzwf ; _rtB -> ozulicgyxz = _rtB ->
oug4gaxwzn - _rtB -> axzozhbobc ; ssCallAccelRunBlock ( S , 29 , 351 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
maalysrses = _rtP -> P_1324 ; _rtB -> eozczhfdcc = _rtP -> P_1325 ; }
ssCallAccelRunBlock ( S , 29 , 354 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mg0ajuq1qc = _rtP -> P_1326 ; }
ssCallAccelRunBlock ( S , 29 , 356 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 357 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 358 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> cidenptwtj = _rtP -> P_1785 ; _rtB ->
b1hxngkkuv = _rtP -> P_1327 ; } _rtB -> iaqu20zk4i = ( _rtB -> hee1k0eaps ==
_rtB -> cidenptwtj ) ; _rtB -> jbksg5aitt = ( int8_T ) _rtB -> iaqu20zk4i ;
ssCallAccelRunBlock ( S , 29 , 363 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> pcgj0sktcg = _rtP -> P_1328 ; _rtB ->
i4xfaju0wm = _rtP -> P_1329 ; _rtB -> c12ffrar0i = _rtP -> P_1330 ; _rtB ->
pnbp2kmz40 = _rtP -> P_1331 ; } _rtB -> d0p1nykwqg = _rtB -> nntkxivcmj -
_rtB -> nyy4wjj131 ; ssCallAccelRunBlock ( S , 29 , 369 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> lwgs4ng5c1 = _rtP -> P_1332
; } ssCallAccelRunBlock ( S , 29 , 371 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
auehniio1k = ( _rtB -> aplnfbw255 - _rtB -> biih154ez0 ) + _rtB -> fxy1ga2ryu
; ssCallAccelRunBlock ( S , 29 , 373 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hpqw1jptbv = _rtP -> P_1333 ; _rtB ->
g0tcymzwxi = _rtP -> P_1334 ; } ssCallAccelRunBlock ( S , 29 , 376 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
f3sildyf5e = _rtP -> P_1335 ; } ssCallAccelRunBlock ( S , 29 , 378 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 379 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> ipxagbhwhy = _rtB -> ddngfn2wmd - _rtB ->
l0r5u3l35c ; ssCallAccelRunBlock ( S , 29 , 381 , SS_CALL_MDL_OUTPUTS ) ;
switch ( _rtB -> hee1k0eaps ) { case 1 : _rtB -> l3wp3rwfmv = _rtB ->
ecwni2h0mz ; break ; case 2 : _rtB -> l3wp3rwfmv = _rtB -> bniywyhiav ; break
; case 3 : _rtB -> l3wp3rwfmv = _rtB -> nm0oher0p4 ; break ; default : _rtB
-> l3wp3rwfmv = _rtB -> py0ta3iryc ; break ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { switch ( _rtB -> daz5nmuzin ) { case 1 : _rtB -> jxjxzklt3w = _rtP ->
P_1223 ; _rtB -> jcwphytxee = _rtB -> jxjxzklt3w ; break ; case 2 : _rtB ->
jcwphytxee = _rtP -> P_1222 ; break ; default : _rtB -> jcwphytxee = _rtP ->
P_1221 ; break ; } _rtB -> atoyt0lq4s = _rtP -> P_1786 ; _rtB -> m25ng4kjsm =
_rtP -> P_1788 ; } if ( _rtB -> nxl5ohwsbx > _rtP -> P_1787 ) { _rtB ->
lvne3geggz = _rtB -> cxdul42je5 ; } else { _rtB -> lvne3geggz = _rtB ->
atoyt0lq4s ; } _rtB -> bhyyjl32k4 = ( _rtB -> lvne3geggz == _rtB ->
m25ng4kjsm ) ; _rtB -> l5ln1c5n4p = ( int8_T ) _rtB -> bhyyjl32k4 ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> k0uvfjc5tr = _rtP -> P_1336 ; _rtB ->
iztw0mxfy2 = _rtDW -> oq2egqnko0 ; _rtB -> fslgei0b5u = ( _rtB -> jklvgrk3ta
> _rtB -> iztw0mxfy2 ) ; _rtB -> fibfebpaia = _rtDW -> no0uqcvsm0 ; if ( _rtB
-> fslgei0b5u ) { _rtB -> f3dsq2tdzz = _rtB -> iu0fw3kasf ; } else { _rtB ->
f3dsq2tdzz = _rtB -> fibfebpaia ; } _rtB -> gg1riw35mq = _rtP -> P_1338 ; }
ssCallAccelRunBlock ( S , 29 , 398 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ocpgz1e2gb = _rtP -> P_1790 ; } _rtB
-> lft1iqslwb = ( _rtB -> lvne3geggz == _rtB -> ocpgz1e2gb ) ; _rtB ->
mvnsz3njmu = ( int8_T ) _rtB -> lft1iqslwb ; _rtB -> erjki2cx2r = _rtP ->
P_1339 * _rtB -> n4d3l4anw3 ; ssCallAccelRunBlock ( S , 29 , 403 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
l3534fkwpo = _rtP -> P_1791 ; _rtB -> kkc2iol1mi = _rtP -> P_1340 ; } _rtB ->
ahfbrpmlky = ( _rtB -> lvne3geggz == _rtB -> l3534fkwpo ) ; _rtB ->
fi1nawu05j = ( int8_T ) _rtB -> ahfbrpmlky ; _rtB -> bzv423udpt = _rtB ->
nntkxivcmj - _rtB -> nyy4wjj131 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> aio110n1r4 = _rtP -> P_1341 ; _rtB -> esprbfoqpk = _rtP -> P_1342 ; }
ssCallAccelRunBlock ( S , 29 , 411 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> auqn10vqvb = _rtP -> P_1343 ; }
ssCallAccelRunBlock ( S , 29 , 413 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
hopr1a0v5u = _rtB -> fbeec20fmg - _rtB -> biih154ez0 ; ssCallAccelRunBlock (
S , 29 , 415 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> dnrp5cfxwm = _rtP -> P_1344 ; _rtB -> iosmqodv2v = _rtP -> P_1345 ; }
ssCallAccelRunBlock ( S , 29 , 418 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 419 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 420 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 421 , SS_CALL_MDL_OUTPUTS ) ; switch ( _rtB ->
lvne3geggz ) { case 1 : _rtB -> n5ecdqpk2o = _rtB -> pjimvxagfu ; break ;
case 2 : _rtB -> n5ecdqpk2o = _rtB -> i1y4y3lozz ; break ; default : _rtB ->
n5ecdqpk2o = _rtB -> b5y51gm2ov ; break ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { if ( _rtB -> htegjfjklo == 1 ) { _rtB -> c23xsqxieb = _rtP -> P_1737 ; }
else { _rtB -> c23xsqxieb = _rtP -> P_1736 ; } _rtB -> mpoo20gr3m = _rtP ->
P_1346 ; _rtB -> hwbamm0lip = _rtP -> P_1347 ; _rtB -> fkq4gnbj5x = _rtP ->
P_1348 ; _rtB -> ovz54ohyol = _rtP -> P_1349 ; } if ( _rtB -> lsnspy42zf >
_rtP -> P_1792 ) { _rtB -> dhirk004br = _rtB -> mpoo20gr3m ; } else { if (
_rtB -> eubvsps4x2 > _rtP -> P_1743 ) { _rtB -> fsynezek0y = _rtB ->
hbz0fyvwkm ; } else { _rtB -> fsynezek0y = _rtB -> ah0ctnhrkd ; } _rtB ->
dhirk004br = _rtB -> fsynezek0y ; } ssCallAccelRunBlock ( S , 29 , 432 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 433 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
flcz2bgrty = _rtP -> P_1350 ; _rtB -> glkx0fj2gt = _rtP -> P_1351 ; _rtB ->
eiara5f1eg = _rtP -> P_1352 ; _rtB -> gsarftfczr = _rtP -> P_1355 ; } if (
_rtB -> bd1st2mfi2 > _rtP -> P_1353 ) { _rtB -> our0y40vgp = _rtP -> P_1353 ;
} else if ( _rtB -> bd1st2mfi2 < _rtP -> P_1354 ) { _rtB -> our0y40vgp = _rtP
-> P_1354 ; } else { _rtB -> our0y40vgp = _rtB -> bd1st2mfi2 ; } if ( _rtB ->
pzhfw2fiqz > _rtP -> P_1356 ) { _rtB -> ojm3mcomjv = _rtP -> P_1356 ; } else
if ( _rtB -> pzhfw2fiqz < _rtP -> P_1357 ) { _rtB -> ojm3mcomjv = _rtP ->
P_1357 ; } else { _rtB -> ojm3mcomjv = _rtB -> pzhfw2fiqz ; }
ssCallAccelRunBlock ( S , 29 , 440 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
fjaqoohwzu = _rtB -> our0y40vgp - _rtB -> o5ltllos1l ; _rtB -> bfy1fq0c3w =
look1_iflf_binlxpw ( _rtB -> hkyo0upbra , _rtP -> P_1359 , _rtP -> P_1358 ,
10U ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bm4c0vhcbm = _rtP ->
P_1360 ; } _rtB -> aou5gbr5yc = _rtB -> bfy1fq0c3w * _rtB -> bm4c0vhcbm ;
ssCallAccelRunBlock ( S , 29 , 445 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gmimwr41wa = _rtP -> P_1361 ; }
ssCallAccelRunBlock ( S , 29 , 447 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mdxsjbenwe = _rtP -> P_1362 ; }
ssCallAccelRunBlock ( S , 29 , 449 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ptfvqj4kx5 = _rtP -> P_1363 ; }
ssCallAccelRunBlock ( S , 29 , 451 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> g3ndewoijw = _rtP -> P_1364 ; } if (
_rtB -> i2lsmesory > _rtP -> P_1365 ) { _rtB -> dxdlknsw1h = _rtP -> P_1365 ;
} else if ( _rtB -> i2lsmesory < _rtP -> P_1366 ) { _rtB -> dxdlknsw1h = _rtP
-> P_1366 ; } else { _rtB -> dxdlknsw1h = _rtB -> i2lsmesory ; }
ssCallAccelRunBlock ( S , 29 , 454 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 455 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
kiqmw42xdr = _rtP -> P_1367 * _rtB -> cn05rbh0ww ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> cvaqbdxjiv = _rtP -> P_1368 ; } ssCallAccelRunBlock ( S ,
29 , 458 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> dw5hambekw = _rtB -> ad3hz1mbdf +
_rtB -> i3qcs2jjxi ; _rtB -> camfcgldyu = _rtB -> l3wp3rwfmv - _rtB ->
dw5hambekw ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mloq41g42e = _rtP
-> P_1369 ; } _rtB -> c35zrz4dfj = _rtB -> mloq41g42e * _rtB -> bfy1fq0c3w ;
ssCallAccelRunBlock ( S , 29 , 463 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
lsnspy42zf > _rtP -> P_1793 ) { _rtB -> i3uhxaytqh = _rtB -> glkx0fj2gt ; }
else { if ( _rtB -> eubvsps4x2 > _rtP -> P_1740 ) { _rtB -> bcyl2vsjhi = _rtB
-> fgmcrfte34 ; } else { _rtB -> pf3q4rmy1e = _rtB -> mptye2agn2 + _rtB ->
g3tap01enk ; _rtB -> bcyl2vsjhi = _rtB -> pf3q4rmy1e ; } _rtB -> i3uhxaytqh =
_rtB -> bcyl2vsjhi ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
gy1jixhp2w = _rtP -> P_1370 ; _rtB -> czrot344ei = _rtP -> P_1371 ; }
ssCallAccelRunBlock ( S , 29 , 468 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 469 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ckgzemqdkb = _rtB -> npfd1fa2f3 [ 3 ]
- _rtB -> npfd1fa2f3 [ 2 ] ; _rtB -> j12o5ftuam = _rtP -> P_1372 * _rtB ->
ckgzemqdkb ; _rtB -> ezhmsskyyh = _rtP -> P_1373 ; _rtB -> mb4eiosv5x = _rtP
-> P_1374 ; _rtB -> dg15j0rjva = _rtP -> P_1375 ; } if ( _rtB -> lsnspy42zf >
_rtP -> P_1794 ) { _rtB -> ccq5ygxedn = _rtB -> flcz2bgrty ; } else { if (
_rtB -> eubvsps4x2 > _rtP -> P_1739 ) { _rtB -> j1ybres51n = _rtB ->
nl0pgm3oyk ; } else { _rtB -> j1ybres51n = _rtB -> dyhkgpztqo ; } _rtB ->
ccq5ygxedn = _rtB -> j1ybres51n ; } ssCallAccelRunBlock ( S , 29 , 477 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 478 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ch0jrtkjoy = _rtP -> P_1376 ; _rtB -> ekiekx2gg4 = _rtP -> P_1377 ; }
ssCallAccelRunBlock ( S , 29 , 481 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 482 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> fc1q0wehqz = _rtP -> P_1378 ; }
ssCallAccelRunBlock ( S , 29 , 484 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 485 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> iqedrzt4yb = _rtP -> P_1379 ; }
ssCallAccelRunBlock ( S , 29 , 487 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
bmkrwjzjze = _rtB -> pn254neiev + _rtB -> kpyibwtnjt ; ssCallAccelRunBlock (
S , 29 , 489 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> ov2cqekodr = _rtP -> P_1380 ; } ssCallAccelRunBlock ( S , 29 , 492 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 494 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
in5ycykeo1 = _rtP -> P_1383 ; } ssCallAccelRunBlock ( S , 29 , 496 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
pymhtsl3na = _rtP -> P_1384 ; } ssCallAccelRunBlock ( S , 29 , 498 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> mnqmkbvfk2 = ( _rtB -> pmtf4tkgud + _rtB ->
g4rqw1aoxq ) + _rtB -> a3133tufwl ; _rtB -> c11m3ahrmp = _rtB -> mnqmkbvfk2 -
_rtB -> ov2cqekodr ; ssCallAccelRunBlock ( S , 29 , 501 , SS_CALL_MDL_OUTPUTS
) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> mg11b45z23 = _rtP -> P_1385
; } ssCallAccelRunBlock ( S , 29 , 503 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> otnen4ktmr = _rtP -> P_1386 ; } _rtB
-> abpjprcwes = _rtB -> mnqmkbvfk2 - _rtB -> otnen4ktmr ; _rtB -> ac0jvasinh
= _rtB -> abpjprcwes ; ssCallAccelRunBlock ( S , 29 , 507 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
kuupfnwy0x = _rtP -> P_1387 ; } ssCallAccelRunBlock ( S , 29 , 509 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> lb2hshfrzc = muSingleScalarMax ( _rtB ->
ewgof1wbwl , _rtB -> bmkrwjzjze ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> nggm1mr5b2 = _rtP -> P_1388 ; } ssCallAccelRunBlock ( S , 29 , 512 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bzcmexl5bk = ( ( _rtB -> oaxg0ynnkk + _rtB ->
lb2hshfrzc ) + _rtB -> phahj20kdy ) + _rtB -> jldyqeb4hz ; _rtB -> c1gqe2yz5e
= _rtB -> dcxbdgss4n - _rtB -> bzcmexl5bk ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> kmgvy2tumf = _rtP -> P_1389 ; } _rtB -> iwaylgipse = _rtB ->
kmgvy2tumf * _rtB -> bfy1fq0c3w ; ssCallAccelRunBlock ( S , 29 , 517 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
phqqdx4ey2 = _rtP -> P_1390 ; _rtB -> lqfygbjccw = _rtP -> P_1391 ; }
ssCallAccelRunBlock ( S , 29 , 520 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
nstlhnjb1m = _rtB -> phqqdx4ey2 - _rtB -> e3wr5ajxed ; _rtB -> asyingqbzo =
_rtB -> lqfygbjccw - _rtB -> e3wr5ajxed ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ _rtB -> pywkx3j4qg = _rtB -> npfd1fa2f3 [ 1 ] + _rtB -> npfd1fa2f3 [ 0 ] ;
_rtB -> fkc4zkitp2 = _rtP -> P_1392 * _rtB -> pywkx3j4qg ; _rtB -> hgq54w2ktj
= _rtDW -> orfcazlkjt ; _rtB -> di1vnsncrl = ( _rtB -> jklvgrk3ta > _rtB ->
hgq54w2ktj ) ; _rtB -> bj5d2obln0 = _rtDW -> mn55pcip1b ; if ( _rtB ->
di1vnsncrl ) { _rtB -> lqy3p2oo2d = _rtB -> fkc4zkitp2 ; } else { _rtB ->
lqy3p2oo2d = _rtB -> bj5d2obln0 ; } _rtB -> dchfk45ebz = _rtP -> P_1394 ; }
_rtB -> jr3crrb01f = _rtB -> lqy3p2oo2d - _rtB -> lhs0rvaisn ;
ssCallAccelRunBlock ( S , 29 , 531 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
fyb3bx1lms = _rtB -> fxkvj2g3ds * _rtB -> mc0ekjdgga ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> agifri4so2 = _rtDW -> awidbghbmk ; ssCallAccelRunBlock
( S , 29 , 534 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> oylhyfuqqi = _rtB ->
inxiom4b1q * _rtB -> jcfqsyl34q ; _rtB -> kt3z53wlva = _rtB -> fyb3bx1lms -
_rtB -> oylhyfuqqi ; ssCallAccelRunBlock ( S , 29 , 537 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> p04t4ixajz = _rtB -> lhs0rvaisn + _rtB -> hd1wcppzoy ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> flpo5xlwcb = _rtP -> P_1396 ; } if (
_rtB -> lsnspy42zf > _rtP -> P_1796 ) { _rtB -> jddhnvijk2 = _rtB ->
ch0jrtkjoy ; } else { if ( _rtB -> eubvsps4x2 > _rtP -> P_1741 ) { _rtB ->
jc3yi2gnh5 = _rtB -> dklegaqrvr ; } else { _rtB -> jc3yi2gnh5 = _rtB ->
p04t4ixajz ; } _rtB -> jddhnvijk2 = _rtB -> jc3yi2gnh5 ; }
ssCallAccelRunBlock ( S , 29 , 542 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 543 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> o4lrphikwk = _rtP -> P_1397 ; _rtB ->
hhxlsn1str = _rtP -> P_1398 ; _rtB -> cdg5d3nw2i = _rtP -> P_1399 ; _rtB ->
ecncsdzz01 = _rtP -> P_1400 ; _rtB -> fhmyqpvzs0 = _rtP -> P_1401 ; } if (
_rtB -> lsnspy42zf > _rtP -> P_1797 ) { _rtB -> iw4x30dccx = _rtB ->
o4lrphikwk ; } else { if ( _rtB -> eubvsps4x2 > _rtP -> P_1742 ) { _rtB ->
hldyadxd0n = _rtB -> dklegaqrvr ; } else { _rtB -> hldyadxd0n = _rtB ->
jcwphytxee ; } _rtB -> iw4x30dccx = _rtB -> hldyadxd0n ; }
ssCallAccelRunBlock ( S , 29 , 551 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 552 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
i2lsmesory > _rtP -> P_1402 ) { _rtB -> juqoagetio = _rtP -> P_1402 ; } else
if ( _rtB -> i2lsmesory < _rtP -> P_1403 ) { _rtB -> juqoagetio = _rtP ->
P_1403 ; } else { _rtB -> juqoagetio = _rtB -> i2lsmesory ; }
ssCallAccelRunBlock ( S , 29 , 554 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> och1pet42d = _rtP -> P_1404 ; _rtB ->
jiydf4lyyr = _rtP -> P_1798 ; _rtB -> bmpcqgeovh = _rtP -> P_1799 ; _rtB ->
ot2w0ogldx = _rtP -> P_1405 ; _rtB -> ix4wo0co2h = ( _rtB -> joh40kiala >=
_rtB -> jiydf4lyyr ) ; _rtB -> b2efwu3ell = ( _rtB -> joh40kiala <= _rtB ->
bmpcqgeovh ) ; _rtB -> gqxwtxossi = ( _rtB -> ix4wo0co2h && _rtB ->
b2efwu3ell ) ; _rtB -> ikc3x0ebgd = _rtP -> P_1406 ; _rtB -> gkw0l5vr2c =
_rtP -> P_1407 ; } _rtB -> ksnynlycvc = _rtB -> n5ecdqpk2o - _rtB ->
c5j1tpmyxl ; ssCallAccelRunBlock ( S , 29 , 565 , SS_CALL_MDL_OUTPUTS ) ; if
( _rtB -> lsnspy42zf > _rtP -> P_1800 ) { _rtB -> oqs344pil1 = _rtB ->
och1pet42d ; } else { if ( _rtB -> eubvsps4x2 > _rtP -> P_1738 ) { _rtB ->
keoqngipql = _rtP -> P_1224 * _rtB -> fgmcrfte34 ; _rtB -> ougj4tgotz = _rtB
-> keoqngipql ; } else { if ( _rtB -> gqxwtxossi ) { _rtB -> nstbuexzp1 =
_rtB -> ot2w0ogldx ; } else { _rtB -> nstbuexzp1 = _rtB -> irzw5vhbmt ; }
_rtB -> ougj4tgotz = _rtB -> nstbuexzp1 ; } _rtB -> oqs344pil1 = _rtB ->
ougj4tgotz ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bofyvldalw = _rtP
-> P_1408 ; _rtB -> ieucwqxeox = _rtP -> P_1411 ; } _rtB -> dtynjk3b0i =
look1_iflf_binlxpw ( _rtB -> pgghzidifi , _rtP -> P_1410 , _rtP -> P_1409 ,
9U ) ; _rtB -> iatk0ojfdz = _rtB -> bofyvldalw * _rtB -> dtynjk3b0i ; _rtB ->
h5sfduzxvh = _rtB -> dtynjk3b0i * _rtB -> ieucwqxeox ; ssCallAccelRunBlock (
S , 29 , 573 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 29 , 574 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ol50sxig1a = _rtB -> c23xsqxieb ; _rtB -> c50j2ryyxv = _rtB -> ccxogf2wlb -
_rtB -> llt4bydmv1 ; } _rtB -> p1m1qcw20c = _rtB -> gxqkgpdryz + _rtB ->
btsusgvh4p [ 2 ] ; _rtB -> bxithui4ut = _rtB -> p1m1qcw20c ; if ( _rtB ->
pyn2voco5f > _rtP -> P_1416 ) { _rtB -> iljxukafzh = _rtP -> P_1416 ; } else
if ( _rtB -> pyn2voco5f < _rtP -> P_1417 ) { _rtB -> iljxukafzh = _rtP ->
P_1417 ; } else { _rtB -> iljxukafzh = _rtB -> pyn2voco5f ; } _rtB ->
c3de5ts2be = _rtB -> c50j2ryyxv * _rtB -> iljxukafzh ; _rtB -> nszbtzgdkf =
_rtB -> c3de5ts2be + _rtB -> llt4bydmv1 ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ if ( _rtB -> ol50sxig1a > _rtP -> P_1418 ) { _rtB -> baod5x0bas = _rtP ->
P_1418 ; } else if ( _rtB -> ol50sxig1a < _rtP -> P_1419 ) { _rtB ->
baod5x0bas = _rtP -> P_1419 ; } else { _rtB -> baod5x0bas = _rtB ->
ol50sxig1a ; } _rtB -> ihgw3jra1m = _rtB -> c50j2ryyxv * _rtB -> baod5x0bas ;
_rtB -> l1sd1chafn = _rtB -> ihgw3jra1m + _rtB -> llt4bydmv1 ; } tmp =
muSingleScalarFloor ( _rtB -> nszbtzgdkf ) ; if ( muSingleScalarIsNaN ( tmp )
|| muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp =
muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB -> kfb3pd0zuz = ( uint16_T ) (
tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : (
int32_T ) ( uint16_T ) tmp ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { tmp =
muSingleScalarFloor ( _rtB -> l1sd1chafn ) ; if ( muSingleScalarIsNaN ( tmp )
|| muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp =
muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB -> efxif1y03t = ( uint16_T ) (
tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : (
int32_T ) ( uint16_T ) tmp ) ; } _rtB -> djgcgsvzkf = _rtB -> pnbnulqgr0 +
_rtB -> btsusgvh4p [ 0 ] ; _rtB -> f4kq5qcq2i = look1_iflf_binlxpw ( _rtB ->
djgcgsvzkf , _rtP -> P_1421 , _rtP -> P_1420 , 24U ) ; _rtB -> jbatlen3fj =
look1_iflf_binlxpw ( _rtB -> djgcgsvzkf , _rtP -> P_1423 , _rtP -> P_1422 ,
23U ) ; if ( _rtB -> f4kq5qcq2i > _rtP -> P_1424 ) { _rtB -> fhmlhp4otw =
_rtP -> P_1424 ; } else if ( _rtB -> f4kq5qcq2i < _rtP -> P_1425 ) { _rtB ->
fhmlhp4otw = _rtP -> P_1425 ; } else { _rtB -> fhmlhp4otw = _rtB ->
f4kq5qcq2i ; } tmp = muSingleScalarFloor ( _rtB -> fhmlhp4otw ) ; if (
muSingleScalarIsNaN ( tmp ) || muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; }
else { tmp = muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB -> jxjqxl2rhz = (
uint16_T ) ( tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T )
- tmp : ( int32_T ) ( uint16_T ) tmp ) ; if ( _rtB -> jbatlen3fj > _rtP ->
P_1426 ) { _rtB -> mvexjeqxnf = _rtP -> P_1426 ; } else if ( _rtB ->
jbatlen3fj < _rtP -> P_1427 ) { _rtB -> mvexjeqxnf = _rtP -> P_1427 ; } else
{ _rtB -> mvexjeqxnf = _rtB -> jbatlen3fj ; } tmp = muSingleScalarFloor (
_rtB -> mvexjeqxnf ) ; if ( muSingleScalarIsNaN ( tmp ) ||
muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp = muSingleScalarRem
( tmp , 65536.0F ) ; } _rtB -> be2nq10mqh = ( uint16_T ) ( tmp < 0.0F ? (
int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : ( int32_T ) (
uint16_T ) tmp ) ; _rtB -> inuazd3mp3 = _rtB -> fsmtp1kbix + _rtB ->
btsusgvh4p [ 1 ] ; _rtB -> ibq0givzyw = _rtP -> P_1428 * _rtB -> inuazd3mp3 ;
_rtB -> ojjgfl3aj5 = look1_iflf_binlxpw ( _rtB -> ibq0givzyw , _rtP -> P_1430
, _rtP -> P_1429 , 25U ) ; _rtB -> omowaeb15v = _rtP -> P_1431 * _rtB ->
inuazd3mp3 ; _rtB -> bcgk3ydoap = look1_iflf_binlxpw ( _rtB -> omowaeb15v ,
_rtP -> P_1433 , _rtP -> P_1432 , 35U ) ; if ( _rtB -> bcgk3ydoap > _rtP ->
P_1434 ) { _rtB -> nfyby0skzl = _rtP -> P_1434 ; } else if ( _rtB ->
bcgk3ydoap < _rtP -> P_1435 ) { _rtB -> nfyby0skzl = _rtP -> P_1435 ; } else
{ _rtB -> nfyby0skzl = _rtB -> bcgk3ydoap ; } tmp = muSingleScalarFloor (
_rtB -> nfyby0skzl ) ; if ( muSingleScalarIsNaN ( tmp ) ||
muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp = muSingleScalarRem
( tmp , 65536.0F ) ; } _rtB -> h5uaghw3dw = ( uint16_T ) ( tmp < 0.0F ? (
int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : ( int32_T ) (
uint16_T ) tmp ) ; if ( _rtB -> ojjgfl3aj5 > _rtP -> P_1436 ) { _rtB ->
er3efst3ps = _rtP -> P_1436 ; } else if ( _rtB -> ojjgfl3aj5 < _rtP -> P_1437
) { _rtB -> er3efst3ps = _rtP -> P_1437 ; } else { _rtB -> er3efst3ps = _rtB
-> ojjgfl3aj5 ; } tmp = muSingleScalarFloor ( _rtB -> er3efst3ps ) ; if (
muSingleScalarIsNaN ( tmp ) || muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; }
else { tmp = muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB -> mayosocpio = (
uint16_T ) ( tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T )
- tmp : ( int32_T ) ( uint16_T ) tmp ) ; _rtB -> kabjug22g3 = _rtP -> P_1438
* _rtB -> p1m1qcw20c ; _rtB -> bv0bjngrgt = look1_iflf_binlxpw ( _rtB ->
kabjug22g3 , _rtP -> P_1440 , _rtP -> P_1439 , 23U ) ; if ( _rtB ->
bv0bjngrgt > _rtP -> P_1441 ) { _rtB -> fwu1f55c2f = _rtP -> P_1441 ; } else
if ( _rtB -> bv0bjngrgt < _rtP -> P_1442 ) { _rtB -> fwu1f55c2f = _rtP ->
P_1442 ; } else { _rtB -> fwu1f55c2f = _rtB -> bv0bjngrgt ; } tmp =
muSingleScalarFloor ( _rtB -> fwu1f55c2f ) ; if ( muSingleScalarIsNaN ( tmp )
|| muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp =
muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB -> nqrui2iwmi = ( uint16_T ) (
tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : (
int32_T ) ( uint16_T ) tmp ) ; _rtB -> ka1sbg21s3 = _rtB -> hb3eclkxo2 + _rtB
-> btsusgvh4p [ 4 ] ; _rtB -> fipbb04ank = look1_iflf_binlxpw ( _rtB ->
ka1sbg21s3 , _rtP -> P_1444 , _rtP -> P_1443 , 1U ) ; if ( _rtB -> fipbb04ank
> _rtP -> P_1445 ) { _rtB -> c5ffg3ka5i = _rtP -> P_1445 ; } else if ( _rtB
-> fipbb04ank < _rtP -> P_1446 ) { _rtB -> c5ffg3ka5i = _rtP -> P_1446 ; }
else { _rtB -> c5ffg3ka5i = _rtB -> fipbb04ank ; } tmp = muSingleScalarFloor
( _rtB -> c5ffg3ka5i ) ; if ( muSingleScalarIsNaN ( tmp ) ||
muSingleScalarIsInf ( tmp ) ) { tmp = 0.0F ; } else { tmp = muSingleScalarRem
( tmp , 65536.0F ) ; } _rtB -> falr03z4rm = ( uint16_T ) ( tmp < 0.0F ? (
int32_T ) ( uint16_T ) - ( int16_T ) ( uint16_T ) - tmp : ( int32_T ) (
uint16_T ) tmp ) ; _rtB -> dzuzgktzus = _rtB -> ax3x03s3gg + _rtB ->
btsusgvh4p [ 3 ] ; _rtB -> gmfjbd3vbu = _rtP -> P_1447 * _rtB -> dzuzgktzus ;
_rtB -> gub3qr5zw2 = look1_iflf_binlxpw ( _rtB -> gmfjbd3vbu , _rtP -> P_1449
, _rtP -> P_1448 , 32U ) ; if ( _rtB -> gub3qr5zw2 > _rtP -> P_1450 ) { _rtB
-> cbbmuvqrdq = _rtP -> P_1450 ; } else if ( _rtB -> gub3qr5zw2 < _rtP ->
P_1451 ) { _rtB -> cbbmuvqrdq = _rtP -> P_1451 ; } else { _rtB -> cbbmuvqrdq
= _rtB -> gub3qr5zw2 ; } tmp = muSingleScalarFloor ( _rtB -> cbbmuvqrdq ) ;
if ( muSingleScalarIsNaN ( tmp ) || muSingleScalarIsInf ( tmp ) ) { tmp =
0.0F ; } else { tmp = muSingleScalarRem ( tmp , 65536.0F ) ; } _rtB ->
nq0sdgi24t = ( uint16_T ) ( tmp < 0.0F ? ( int32_T ) ( uint16_T ) - ( int16_T
) ( uint16_T ) - tmp : ( int32_T ) ( uint16_T ) tmp ) ; if ( _rtB ->
kfb3pd0zuz > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 0 ] = _rtP -> P_1721 ; }
else if ( _rtB -> kfb3pd0zuz < _rtP -> P_1722 ) { _rtB -> bzgei0srbk [ 0 ] =
_rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 0 ] = _rtB -> kfb3pd0zuz ; }
if ( _rtB -> jxjqxl2rhz > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 1 ] = _rtP
-> P_1721 ; } else if ( _rtB -> jxjqxl2rhz < _rtP -> P_1722 ) { _rtB ->
bzgei0srbk [ 1 ] = _rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 1 ] = _rtB
-> jxjqxl2rhz ; } if ( _rtB -> be2nq10mqh > _rtP -> P_1721 ) { _rtB ->
bzgei0srbk [ 2 ] = _rtP -> P_1721 ; } else if ( _rtB -> be2nq10mqh < _rtP ->
P_1722 ) { _rtB -> bzgei0srbk [ 2 ] = _rtP -> P_1722 ; } else { _rtB ->
bzgei0srbk [ 2 ] = _rtB -> be2nq10mqh ; } if ( _rtB -> h5uaghw3dw > _rtP ->
P_1721 ) { _rtB -> bzgei0srbk [ 3 ] = _rtP -> P_1721 ; } else if ( _rtB ->
h5uaghw3dw < _rtP -> P_1722 ) { _rtB -> bzgei0srbk [ 3 ] = _rtP -> P_1722 ; }
else { _rtB -> bzgei0srbk [ 3 ] = _rtB -> h5uaghw3dw ; } if ( _rtB ->
mayosocpio > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 4 ] = _rtP -> P_1721 ; }
else if ( _rtB -> mayosocpio < _rtP -> P_1722 ) { _rtB -> bzgei0srbk [ 4 ] =
_rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 4 ] = _rtB -> mayosocpio ; }
if ( _rtB -> nqrui2iwmi > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 5 ] = _rtP
-> P_1721 ; } else if ( _rtB -> nqrui2iwmi < _rtP -> P_1722 ) { _rtB ->
bzgei0srbk [ 5 ] = _rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 5 ] = _rtB
-> nqrui2iwmi ; } if ( _rtB -> falr03z4rm > _rtP -> P_1721 ) { _rtB ->
bzgei0srbk [ 6 ] = _rtP -> P_1721 ; } else if ( _rtB -> falr03z4rm < _rtP ->
P_1722 ) { _rtB -> bzgei0srbk [ 6 ] = _rtP -> P_1722 ; } else { _rtB ->
bzgei0srbk [ 6 ] = _rtB -> falr03z4rm ; } if ( _rtB -> nq0sdgi24t > _rtP ->
P_1721 ) { _rtB -> bzgei0srbk [ 7 ] = _rtP -> P_1721 ; } else if ( _rtB ->
nq0sdgi24t < _rtP -> P_1722 ) { _rtB -> bzgei0srbk [ 7 ] = _rtP -> P_1722 ; }
else { _rtB -> bzgei0srbk [ 7 ] = _rtB -> nq0sdgi24t ; } if ( _rtB ->
efxif1y03t > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 8 ] = _rtP -> P_1721 ; }
else if ( _rtB -> efxif1y03t < _rtP -> P_1722 ) { _rtB -> bzgei0srbk [ 8 ] =
_rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 8 ] = _rtB -> efxif1y03t ; }
if ( _rtB -> efxif1y03t > _rtP -> P_1721 ) { _rtB -> bzgei0srbk [ 9 ] = _rtP
-> P_1721 ; } else if ( _rtB -> efxif1y03t < _rtP -> P_1722 ) { _rtB ->
bzgei0srbk [ 9 ] = _rtP -> P_1722 ; } else { _rtB -> bzgei0srbk [ 9 ] = _rtB
-> efxif1y03t ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> hoxcbrbnca =
_rtP -> P_1452 ; } _rtB -> grc213enjy = _rtB -> b1apgnyjax - _rtB ->
hoxcbrbnca ; ssCallAccelRunBlock ( S , 29 , 627 , SS_CALL_MDL_OUTPUTS ) ; if
( _rtB -> ejvtxiit0x > _rtP -> P_1453 ) { _rtB -> brj1x2vrxy = _rtP -> P_1453
; } else if ( _rtB -> ejvtxiit0x < _rtP -> P_1454 ) { _rtB -> brj1x2vrxy =
_rtP -> P_1454 ; } else { _rtB -> brj1x2vrxy = _rtB -> ejvtxiit0x ; }
ssCallAccelRunBlock ( S , 29 , 629 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 29 , 630 , SS_CALL_MDL_OUTPUTS ) ; } void
jtjpxjywrwTID2 ( SimStruct * const S ) { plshtxiahf * _rtB ; cvqdcwnzy0 *
_rtP ; _rtP = ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
plshtxiahf * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> fao0dbngms = _rtP ->
P_1276 ; _rtB -> ozx0qxdgnl = _rtP -> P_1311 ; _rtB -> e0y4qxx5qs = _rtP ->
P_1381 ; _rtB -> cxxrff4mi4 = _rtP -> P_1382 ; _rtB -> hvyry4pezt = _rtP ->
P_1412 ; _rtB -> db3wnjsw4s = _rtP -> P_1413 ; _rtB -> jeqfuzbocz = _rtP ->
P_1414 ; _rtB -> l3uypkczfm = _rtP -> P_1415 ; _rtB -> lntwswxxgi = _rtB ->
hvyry4pezt ; _rtB -> nbkger11ht = _rtB -> db3wnjsw4s ; _rtB -> gejmefh1bk =
_rtB -> jeqfuzbocz ; _rtB -> l2algtpvrq = _rtB -> l3uypkczfm ; } void
irv3p1y3ss ( SimStruct * const S ) { plshtxiahf * _rtB ; f5cp4dpc1i * _rtDW ;
_rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S ) ) ; _rtB = ( ( plshtxiahf * )
_ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW ->
k31zamqwau = _rtB -> jklvgrk3ta ; _rtDW -> pcas5y24f1 = _rtB -> ah0ctnhrkd ;
} ssCallAccelRunBlock ( S , 29 , 12 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 22 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 24 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 25 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 30 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 34 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 35 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 37 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 43 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 44 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 45 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 48 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 51 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 52 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 54 , SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { _rtDW -> mssvcbjhns = _rtB -> jklvgrk3ta ; _rtDW ->
eebzwbkqux = _rtB -> o0evy5frin ; } ssCallAccelRunBlock ( S , 29 , 72 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 74 , SS_CALL_MDL_UPDATE
) ; ssCallAccelRunBlock ( S , 29 , 83 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 89 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 90 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 99 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 100 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 102 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 109 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 110 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 115 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 116 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 128 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 131 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 133 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 134 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 135 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 142 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 144 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 146 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 157 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 158 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 160 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 161 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 164 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 165 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 166 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 171 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 172 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 173 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 174 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 178 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 179 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 180 , SS_CALL_MDL_UPDATE ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> eku14anuxp = _rtB -> nxl5ohwsbx ; }
ssCallAccelRunBlock ( S , 29 , 188 , SS_CALL_MDL_UPDATE ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> b5qdxu3cgk = _rtB -> jklvgrk3ta ;
_rtDW -> icjuziyhaa = _rtB -> kvslbjzt04 ; } ssCallAccelRunBlock ( S , 29 ,
200 , SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 209 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 212 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 214 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 219 ,
SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW ->
i4loudfi5t = _rtB -> hscesoihit ; ssCallAccelRunBlock ( S , 29 , 233 ,
SS_CALL_MDL_UPDATE ) ; } ssCallAccelRunBlock ( S , 29 , 238 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 240 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 241 ,
SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 29 , 248 , SS_CALL_MDL_UPDATE ) ; }
ssCallAccelRunBlock ( S , 29 , 251 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 254 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 256 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 257 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 259 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 260 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 261 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 263 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 264 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 266 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 267 , SS_CALL_MDL_UPDATE ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 29 , 274 ,
SS_CALL_MDL_UPDATE ) ; } ssCallAccelRunBlock ( S , 29 , 277 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 280 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 282 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 283 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 284 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 286 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 287 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 289 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 290 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 292 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 293 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 303 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 305 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 307 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 308 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 311 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 312 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 313 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 314 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 316 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 317 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 319 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 321 ,
SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 29 , 323 , SS_CALL_MDL_UPDATE ) ; }
ssCallAccelRunBlock ( S , 29 , 326 , SS_CALL_MDL_UPDATE ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> o2svirmeko = _rtB -> jklvgrk3ta ;
_rtDW -> j20ho5ma0c = _rtB -> l3wp3rwfmv ; } ssCallAccelRunBlock ( S , 29 ,
338 , SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 344 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 351 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 354 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 356 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 357 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 358 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 363 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 369 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 371 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 373 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 376 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 378 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 379 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 381 ,
SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW ->
oq2egqnko0 = _rtB -> jklvgrk3ta ; _rtDW -> no0uqcvsm0 = _rtB -> n5ecdqpk2o ;
} ssCallAccelRunBlock ( S , 29 , 398 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 403 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 411 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 413 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 415 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 418 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 419 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 420 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 421 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 432 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 433 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 440 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 445 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 447 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 449 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 451 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 454 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 455 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 458 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 463 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 468 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 469 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 477 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 478 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 481 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 482 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 484 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 485 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 487 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 489 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 492 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 494 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 496 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 498 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 501 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 503 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 507 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 509 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 512 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 517 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 29 , 520 , SS_CALL_MDL_UPDATE ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> orfcazlkjt = _rtB -> jklvgrk3ta ;
_rtDW -> mn55pcip1b = _rtB -> p04t4ixajz ; } ssCallAccelRunBlock ( S , 29 ,
531 , SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW ->
awidbghbmk = _rtB -> hd1wcppzoy ; ssCallAccelRunBlock ( S , 29 , 534 ,
SS_CALL_MDL_UPDATE ) ; } ssCallAccelRunBlock ( S , 29 , 537 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 542 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 543 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 551 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 552 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 554 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 565 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 573 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 574 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 627 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 629 ,
SS_CALL_MDL_UPDATE ) ; ssCallAccelRunBlock ( S , 29 , 630 ,
SS_CALL_MDL_UPDATE ) ; } void mktyos2lxd ( SimStruct * const S ) { plshtxiahf
* _rtB ; f5cp4dpc1i * _rtDW ; _rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S )
) ; _rtB = ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) ) ; { SimStruct * rts
= ssGetSFunction ( S , 7 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 8 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 9 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 10 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 11 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 12 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 13 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 14 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 15 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 16 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 17 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 18 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 19 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 20 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 21 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 22 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 23 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 24 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 25 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 26 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 27 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 28 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 29 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 30 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 31 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 32 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 33 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 34 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 35 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 36 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 37 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 38 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 39 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 40 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 41 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 42 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 43 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 44 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 45 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 46 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 47 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 48 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 49 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 50 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 51 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 52 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 53 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 54 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 55 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 56 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 57 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 58 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 59 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 60 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 61 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 62 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 63 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 64 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 65 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 66 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 67 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 68 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 69 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 70 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 71 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 72 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 73 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 74 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 75 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 76 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 77 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 78 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 79 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 80 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 81 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 82 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 83 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 84 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 85 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 86 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 87 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 88 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 89 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 90 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 91 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 92 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 93 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 94 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 95 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 96 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 97 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 98 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 99 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 100 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 101 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 102 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 103 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 104 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 105 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 106 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 107 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 108 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 109 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 110 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 111 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 112 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 113 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 114 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 115 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 116 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 117 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 118 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 119 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 120 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 121 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 122 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 123 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 124 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 125 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 126 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 127 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 128 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 129 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 130 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 131 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 132 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 133 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 134 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 135 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 136 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 137 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 138 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 139 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 140 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 141 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 142 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 143 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 144 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 145 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 146 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 147 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 148 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 149 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 150 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 151 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 152 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 153 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 154 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 155 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 156 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 157 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 158 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 159 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 160 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 161 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 162 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 163 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 164 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 165 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 166 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 167 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 168 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 169 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 170 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 171 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 172 ) ; sfcnTerminate ( rts ) ; } { SimStruct * rts =
ssGetSFunction ( S , 173 ) ; sfcnTerminate ( rts ) ; } } void mu2kvrtqzt (
knwbmdh2o1 * localB , k52umkce5u * localDW , dbjdkpcxft * localP ) { localDW
-> ckybh0e0eb = localP -> P_7 ; localB -> hbvlhrfocs [ 0 ] = localP -> P_0 [
0 ] ; localB -> cym4dmzcj1 [ 0 ] = localP -> P_0 [ 3 ] ; localB -> hbvlhrfocs
[ 1 ] = localP -> P_0 [ 1 ] ; localB -> cym4dmzcj1 [ 1 ] = localP -> P_0 [ 4
] ; localB -> hbvlhrfocs [ 2 ] = localP -> P_0 [ 2 ] ; localB -> cym4dmzcj1 [
2 ] = localP -> P_0 [ 5 ] ; localB -> ewrsp3oi1w = localP -> P_1 ; } void
d0gn4nvn3e ( knwbmdh2o1 * localB , k52umkce5u * localDW , dbjdkpcxft * localP
) { if ( localDW -> p1f1vrd1v3 ) { localB -> hbvlhrfocs [ 0 ] = localP -> P_0
[ 0 ] ; localB -> cym4dmzcj1 [ 0 ] = localP -> P_0 [ 3 ] ; localB ->
hbvlhrfocs [ 1 ] = localP -> P_0 [ 1 ] ; localB -> cym4dmzcj1 [ 1 ] = localP
-> P_0 [ 4 ] ; localB -> hbvlhrfocs [ 2 ] = localP -> P_0 [ 2 ] ; localB ->
cym4dmzcj1 [ 2 ] = localP -> P_0 [ 5 ] ; localB -> ewrsp3oi1w = localP -> P_1
; localDW -> p1f1vrd1v3 = false ; } } void lvrrs02dbe ( SimStruct * const S ,
real_T dobvhq0s0w , real_T n3srqvzjme , real_T okksoyo2mo , real_T k4r0sciaji
, const real_T omuypwqqfo [ 3 ] , real_T czaxhnzy2o , real_T ppnrpfuvi0 ,
knwbmdh2o1 * localB , k52umkce5u * localDW , dbjdkpcxft * localP ) { int32_T
i ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 129 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; localB -> moawqxdye2 = localP -> P_27 ; localB ->
k5cxkb2v2f = localP -> P_28 ; } localB -> mk3pd43jhs = n3srqvzjme +
dobvhq0s0w ; if ( localB -> mk3pd43jhs > localP -> P_22 ) { localB ->
fpeu1jbeab = localB -> moawqxdye2 ; } else { localB -> fpeu1jbeab = localB ->
k5cxkb2v2f ; } if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsMajorTimeStep ( S ) )
{ if ( localB -> fpeu1jbeab > 0 ) { if ( ! localDW -> p1f1vrd1v3 ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S )
; } localDW -> p1f1vrd1v3 = true ; } } else { if ( localDW -> p1f1vrd1v3 ) {
ssSetSolverNeedsReset ( S ) ; localB -> hbvlhrfocs [ 0 ] = localP -> P_0 [ 0
] ; localB -> cym4dmzcj1 [ 0 ] = localP -> P_0 [ 3 ] ; localB -> hbvlhrfocs [
1 ] = localP -> P_0 [ 1 ] ; localB -> cym4dmzcj1 [ 1 ] = localP -> P_0 [ 4 ]
; localB -> hbvlhrfocs [ 2 ] = localP -> P_0 [ 2 ] ; localB -> cym4dmzcj1 [ 2
] = localP -> P_0 [ 5 ] ; localB -> ewrsp3oi1w = localP -> P_1 ; localDW ->
p1f1vrd1v3 = false ; } } } if ( localDW -> p1f1vrd1v3 ) { localB ->
lrskpa250i [ 0 ] = okksoyo2mo ; localB -> lrskpa250i [ 1 ] = k4r0sciaji ;
localB -> lrskpa250i [ 2 ] = localB -> bhpspqsil2 ; muDoubleScalarSinCos (
localB -> lrskpa250i [ 0 ] , & localB -> lrskpa250i [ 0 ] , & localB ->
p0ao4rgrer [ 0 ] ) ; muDoubleScalarSinCos ( localB -> lrskpa250i [ 1 ] , &
localB -> lrskpa250i [ 1 ] , & localB -> p0ao4rgrer [ 1 ] ) ;
muDoubleScalarSinCos ( localB -> lrskpa250i [ 2 ] , & localB -> lrskpa250i [
2 ] , & localB -> p0ao4rgrer [ 2 ] ) ; localB -> ocphe4nabv [ 0 ] = localB ->
p0ao4rgrer [ 1 ] * localB -> p0ao4rgrer [ 2 ] ; localB -> gksmmkblia = localB
-> p0ao4rgrer [ 2 ] * localB -> lrskpa250i [ 0 ] * localB -> lrskpa250i [ 1 ]
; localB -> egv2a3l0qw = localB -> lrskpa250i [ 2 ] * localB -> p0ao4rgrer [
0 ] ; localB -> ocphe4nabv [ 1 ] = localB -> gksmmkblia - localB ->
egv2a3l0qw ; localB -> cn1klgkrr4 = localB -> lrskpa250i [ 0 ] * localB ->
lrskpa250i [ 2 ] ; localB -> dn5mvhhra1 = localB -> lrskpa250i [ 1 ] * localB
-> p0ao4rgrer [ 0 ] * localB -> p0ao4rgrer [ 2 ] ; localB -> ocphe4nabv [ 2 ]
= localB -> cn1klgkrr4 + localB -> dn5mvhhra1 ; localB -> ocphe4nabv [ 3 ] =
localB -> lrskpa250i [ 2 ] * localB -> p0ao4rgrer [ 1 ] ; localB ->
i4v15k3kcw = localB -> lrskpa250i [ 0 ] * localB -> lrskpa250i [ 1 ] * localB
-> lrskpa250i [ 2 ] ; localB -> aftegkos5r = localB -> p0ao4rgrer [ 0 ] *
localB -> p0ao4rgrer [ 2 ] ; localB -> ocphe4nabv [ 4 ] = localB ->
i4v15k3kcw + localB -> aftegkos5r ; localB -> d2lfjkq0ao = localB ->
lrskpa250i [ 1 ] * localB -> lrskpa250i [ 2 ] * localB -> p0ao4rgrer [ 0 ] ;
localB -> nfi2hzqhx2 = localB -> p0ao4rgrer [ 2 ] * localB -> lrskpa250i [ 0
] ; localB -> ocphe4nabv [ 5 ] = localB -> d2lfjkq0ao - localB -> nfi2hzqhx2
; localB -> ocphe4nabv [ 6 ] = localP -> P_3 * localB -> lrskpa250i [ 1 ] ;
localB -> ocphe4nabv [ 7 ] = localB -> lrskpa250i [ 0 ] * localB ->
p0ao4rgrer [ 1 ] ; localB -> ocphe4nabv [ 8 ] = localB -> p0ao4rgrer [ 0 ] *
localB -> p0ao4rgrer [ 1 ] ; localB -> p0ao4rgrer [ 0 ] = localB ->
ocphe4nabv [ 2 ] ; localB -> p0ao4rgrer [ 1 ] = localB -> ocphe4nabv [ 5 ] ;
localB -> p0ao4rgrer [ 2 ] = localB -> ocphe4nabv [ 8 ] ; localB ->
ck23okrdnx = omuypwqqfo [ 0 ] * localB -> p0ao4rgrer [ 0 ] ; localB ->
crx4hflpjb = omuypwqqfo [ 1 ] * localB -> p0ao4rgrer [ 1 ] ; localB ->
enydpp1esa = ( ( dobvhq0s0w + n3srqvzjme ) - localB -> ck23okrdnx ) - localB
-> crx4hflpjb ; localB -> ksrhxhdcyp = localB -> enydpp1esa / localB ->
p0ao4rgrer [ 2 ] ; localB -> jjz1zgi3hn = omuypwqqfo [ 2 ] - localB ->
ksrhxhdcyp ; if ( localB -> jjz1zgi3hn > localP -> P_4 ) { localB ->
ewrsp3oi1w = localP -> P_4 ; } else if ( localB -> jjz1zgi3hn < localP -> P_5
) { localB -> ewrsp3oi1w = localP -> P_5 ; } else { localB -> ewrsp3oi1w =
localB -> jjz1zgi3hn ; } localB -> jtcrhhocei = localP -> P_6 * localB ->
ewrsp3oi1w ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB -> hmbxqc2nv0 =
localDW -> ckybh0e0eb ; } localB -> mrivkjndgr = localB -> ewrsp3oi1w -
localB -> hmbxqc2nv0 ; localB -> eqpdde051r = localP -> P_8 * localB ->
mrivkjndgr ; localB -> laxjoz41tu = localP -> P_9 * localB -> eqpdde051r ;
localB -> l240t5yqkc = localB -> jtcrhhocei + localB -> laxjoz41tu ; localB
-> p5frfvnpam = localB -> l240t5yqkc / localB -> p0ao4rgrer [ 2 ] ; if (
localB -> p5frfvnpam > localP -> P_10 ) { localB -> i4sht5a3hq = localP ->
P_10 ; } else if ( localB -> p5frfvnpam < localP -> P_11 ) { localB ->
i4sht5a3hq = localP -> P_11 ; } else { localB -> i4sht5a3hq = localB ->
p5frfvnpam ; } localB -> dkfv4wxy5c = localP -> P_12 * localB -> i4sht5a3hq ;
localB -> o01ubzl1vx [ 0 ] = localB -> dkfv4wxy5c * czaxhnzy2o ; localB ->
o01ubzl1vx [ 1 ] = localB -> dkfv4wxy5c * ppnrpfuvi0 ; localB -> o01ubzl1vx [
2 ] = localB -> dkfv4wxy5c ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 128 , 42 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 128 , 43 , SS_CALL_MDL_OUTPUTS ) ; } for ( i = 0 ;
i < 3 ; i ++ ) { localB -> hbvlhrfocs [ i ] = 0.0 ; localB -> hbvlhrfocs [ i
] += localB -> ocphe4nabv [ i ] * localB -> o01ubzl1vx [ 0 ] ; localB ->
hbvlhrfocs [ i ] += localB -> ocphe4nabv [ i + 3 ] * localB -> o01ubzl1vx [ 1
] ; localB -> hbvlhrfocs [ i ] += localB -> ocphe4nabv [ i + 6 ] * localB ->
o01ubzl1vx [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock
( S , 128 , 46 , SS_CALL_MDL_OUTPUTS ) ; localB -> f4g22upeqc [ 0 ] = localP
-> P_13 ; } localB -> f4g22upeqc [ 1 ] = localB -> ksrhxhdcyp ; localB ->
f4g22upeqc [ 2 ] = localB -> nzvnb0rjf2 ; localB -> f4g22upeqc [ 3 ] = localP
-> P_15 * localB -> ksrhxhdcyp ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB
-> f4g22upeqc [ 4 ] = localP -> P_16 ; } localB -> f4g22upeqc [ 5 ] =
omuypwqqfo [ 0 ] ; localB -> f4g22upeqc [ 6 ] = omuypwqqfo [ 1 ] ; localB ->
f4g22upeqc [ 7 ] = localB -> o55ezor0r5 ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ localB -> f4g22upeqc [ 8 ] = localP -> P_18 ; } for ( i = 0 ; i < 3 ; i ++
) { localB -> p0ao4rgrer [ i ] = 0.0 ; localB -> p0ao4rgrer [ i ] += localB
-> f4g22upeqc [ 3 * i ] * localB -> hbvlhrfocs [ 0 ] ; localB -> p0ao4rgrer [
i ] += localB -> f4g22upeqc [ 3 * i + 1 ] * localB -> hbvlhrfocs [ 1 ] ;
localB -> p0ao4rgrer [ i ] += localB -> f4g22upeqc [ 3 * i + 2 ] * localB ->
hbvlhrfocs [ 2 ] ; localB -> cym4dmzcj1 [ i ] = localP -> P_19 [ i ] * localB
-> p0ao4rgrer [ i ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 128 , 61 , SS_CALL_MDL_OUTPUTS ) ; } localB ->
mubivkhwo2 = omuypwqqfo [ 1 ] * localB -> hbvlhrfocs [ 2 ] ; localB ->
pmd4c0jiid = omuypwqqfo [ 2 ] * localB -> hbvlhrfocs [ 0 ] ; localB ->
hq2sbtks10 = omuypwqqfo [ 0 ] * localB -> hbvlhrfocs [ 1 ] ; localB ->
dfrhrvobie = omuypwqqfo [ 2 ] * localB -> hbvlhrfocs [ 1 ] ; localB ->
mrq5dfcdyp = omuypwqqfo [ 0 ] * localB -> hbvlhrfocs [ 2 ] ; localB ->
afvzfn5ban = omuypwqqfo [ 1 ] * localB -> hbvlhrfocs [ 0 ] ; localB ->
p0ao4rgrer [ 0 ] = localB -> mubivkhwo2 - localB -> dfrhrvobie ; localB ->
p0ao4rgrer [ 1 ] = localB -> pmd4c0jiid - localB -> mrq5dfcdyp ; localB ->
p0ao4rgrer [ 2 ] = localB -> hq2sbtks10 - localB -> afvzfn5ban ; localB ->
g2qcm3gmch [ 0 ] = localP -> P_20 * localB -> p0ao4rgrer [ 0 ] ; localB ->
g2qcm3gmch [ 1 ] = localP -> P_20 * localB -> p0ao4rgrer [ 1 ] ; localB ->
g2qcm3gmch [ 2 ] = localP -> P_20 * localB -> p0ao4rgrer [ 2 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 128 , 70 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 128 , 71 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 128 , 72 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 128 , 73 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 128 , 74 ,
SS_CALL_MDL_OUTPUTS ) ; } for ( i = 0 ; i < 3 ; i ++ ) { localB -> dwqhuqjgh3
[ 3 * i ] = localB -> ocphe4nabv [ i ] ; localB -> dwqhuqjgh3 [ 1 + 3 * i ] =
localB -> ocphe4nabv [ i + 3 ] ; localB -> dwqhuqjgh3 [ 2 + 3 * i ] = localB
-> ocphe4nabv [ i + 6 ] ; } localB -> p0ao4rgrer [ 0 ] = omuypwqqfo [ 0 ] ;
localB -> p0ao4rgrer [ 1 ] = omuypwqqfo [ 1 ] ; localB -> p0ao4rgrer [ 2 ] =
localB -> bqmgptg4rq ; for ( i = 0 ; i < 3 ; i ++ ) { localB -> mkwdcgm00i [
i ] = 0.0 ; localB -> mkwdcgm00i [ i ] += localB -> dwqhuqjgh3 [ i ] * localB
-> p0ao4rgrer [ 0 ] ; localB -> mkwdcgm00i [ i ] += localB -> dwqhuqjgh3 [ i
+ 3 ] * localB -> p0ao4rgrer [ 1 ] ; localB -> mkwdcgm00i [ i ] += localB ->
dwqhuqjgh3 [ i + 6 ] * localB -> p0ao4rgrer [ 2 ] ; } localB -> a4fhuo20x3 =
n3srqvzjme - localB -> mkwdcgm00i [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ ssCallAccelRunBlock ( S , 128 , 80 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 128 , 81 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 128 , 82 , SS_CALL_MDL_OUTPUTS ) ; } if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> chuskeyqh4 ) ; } } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 129 , 6 ,
SS_CALL_MDL_OUTPUTS ) ; localB -> hxnoj4hbat = localP -> P_29 ; localB ->
henp3flmsp = localP -> P_30 ; } localB -> kiyb2xg1gz = localP -> P_24 *
localB -> hbvlhrfocs [ 2 ] ; localB -> dpeiotx5dj [ 0 ] = okksoyo2mo ; localB
-> dpeiotx5dj [ 1 ] = k4r0sciaji ; localB -> dpeiotx5dj [ 2 ] = localB ->
ndeqtbydd4 ; muDoubleScalarSinCos ( localB -> dpeiotx5dj [ 0 ] , & localB ->
dpeiotx5dj [ 0 ] , & localB -> k3k4wwxmfq [ 0 ] ) ; muDoubleScalarSinCos (
localB -> dpeiotx5dj [ 1 ] , & localB -> dpeiotx5dj [ 1 ] , & localB ->
k3k4wwxmfq [ 1 ] ) ; muDoubleScalarSinCos ( localB -> dpeiotx5dj [ 2 ] , &
localB -> dpeiotx5dj [ 2 ] , & localB -> k3k4wwxmfq [ 2 ] ) ; localB ->
pgkzyehzu3 [ 0 ] = localB -> k3k4wwxmfq [ 1 ] * localB -> k3k4wwxmfq [ 2 ] ;
localB -> pgkzyehzu3 [ 3 ] = localB -> dpeiotx5dj [ 2 ] * localB ->
k3k4wwxmfq [ 1 ] ; localB -> pgkzyehzu3 [ 6 ] = localP -> P_25 * localB ->
dpeiotx5dj [ 1 ] ; localB -> kwpsmsnbtz = localB -> k3k4wwxmfq [ 2 ] * localB
-> dpeiotx5dj [ 0 ] * localB -> dpeiotx5dj [ 1 ] ; localB -> jxqneueqnx =
localB -> dpeiotx5dj [ 2 ] * localB -> k3k4wwxmfq [ 0 ] ; localB ->
pgkzyehzu3 [ 1 ] = localB -> kwpsmsnbtz - localB -> jxqneueqnx ; localB ->
ey5bi3myzv = localB -> dpeiotx5dj [ 0 ] * localB -> dpeiotx5dj [ 1 ] * localB
-> dpeiotx5dj [ 2 ] ; localB -> gckdbczj3z = localB -> k3k4wwxmfq [ 0 ] *
localB -> k3k4wwxmfq [ 2 ] ; localB -> pgkzyehzu3 [ 4 ] = localB ->
ey5bi3myzv + localB -> gckdbczj3z ; localB -> pgkzyehzu3 [ 7 ] = localB ->
dpeiotx5dj [ 0 ] * localB -> k3k4wwxmfq [ 1 ] ; localB -> paafmbem5j = localB
-> dpeiotx5dj [ 0 ] * localB -> dpeiotx5dj [ 2 ] ; localB -> kioczm5eqq =
localB -> dpeiotx5dj [ 1 ] * localB -> k3k4wwxmfq [ 0 ] * localB ->
k3k4wwxmfq [ 2 ] ; localB -> pgkzyehzu3 [ 2 ] = localB -> paafmbem5j + localB
-> kioczm5eqq ; localB -> b3yvultfcb = localB -> dpeiotx5dj [ 1 ] * localB ->
dpeiotx5dj [ 2 ] * localB -> k3k4wwxmfq [ 0 ] ; localB -> h5jgplvqgx = localB
-> k3k4wwxmfq [ 2 ] * localB -> dpeiotx5dj [ 0 ] ; localB -> pgkzyehzu3 [ 5 ]
= localB -> b3yvultfcb - localB -> h5jgplvqgx ; localB -> pgkzyehzu3 [ 8 ] =
localB -> k3k4wwxmfq [ 0 ] * localB -> k3k4wwxmfq [ 1 ] ; if ( localB ->
kiyb2xg1gz > localP -> P_26 ) { localB -> fxlimhlv2k = localB -> hxnoj4hbat ;
} else { localB -> fxlimhlv2k = localB -> henp3flmsp ; } } void
lvrrs02dbeTID2 ( SimStruct * const S , const real_T omuypwqqfo [ 3 ] ,
knwbmdh2o1 * localB , k52umkce5u * localDW , dbjdkpcxft * localP ) { localB
-> bhpspqsil2 = localP -> P_2 ; ssCallAccelRunBlock ( S , 128 , 44 ,
SS_CALL_MDL_OUTPUTS ) ; localB -> nzvnb0rjf2 = localP -> P_14 * omuypwqqfo [
1 ] ; localB -> o55ezor0r5 = localP -> P_17 * omuypwqqfo [ 0 ] ; localB ->
bqmgptg4rq = localP -> P_21 ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC (
localDW -> chuskeyqh4 ) ; } localB -> ndeqtbydd4 = localP -> P_23 ; } void
hztvnhnxrv ( SimStruct * const S , knwbmdh2o1 * localB , k52umkce5u * localDW
) { if ( localDW -> p1f1vrd1v3 && ssIsSampleHit ( S , 1 , 0 ) ) { localDW ->
ckybh0e0eb = localB -> ewrsp3oi1w ; } } void pq2mo0ucdy ( SimStruct * const S
) { } void busktusywo ( nlxzdmxpff * localB , mcezkcerxl * localDW ,
fvjsblhu4h * localP ) { localDW -> ods5wrpes0 = localP -> P_8 ; localB ->
cbdogvxzxd [ 0 ] = localP -> P_0 [ 0 ] ; localB -> p1qhcdd2xz [ 0 ] = localP
-> P_0 [ 3 ] ; localB -> cbdogvxzxd [ 1 ] = localP -> P_0 [ 1 ] ; localB ->
p1qhcdd2xz [ 1 ] = localP -> P_0 [ 4 ] ; localB -> cbdogvxzxd [ 2 ] = localP
-> P_0 [ 2 ] ; localB -> p1qhcdd2xz [ 2 ] = localP -> P_0 [ 5 ] ; localB ->
kn1lbvvirf = localP -> P_1 ; } void lcmgrp0nqt ( nlxzdmxpff * localB ,
mcezkcerxl * localDW , fvjsblhu4h * localP ) { if ( localDW -> njujzfdimj ) {
localB -> cbdogvxzxd [ 0 ] = localP -> P_0 [ 0 ] ; localB -> p1qhcdd2xz [ 0 ]
= localP -> P_0 [ 3 ] ; localB -> cbdogvxzxd [ 1 ] = localP -> P_0 [ 1 ] ;
localB -> p1qhcdd2xz [ 1 ] = localP -> P_0 [ 4 ] ; localB -> cbdogvxzxd [ 2 ]
= localP -> P_0 [ 2 ] ; localB -> p1qhcdd2xz [ 2 ] = localP -> P_0 [ 5 ] ;
localB -> kn1lbvvirf = localP -> P_1 ; localDW -> njujzfdimj = false ; } }
void b1bttejwsj ( SimStruct * const S , real_T noteznn2pu , real_T mqv1fmj0h4
, real_T dbizdu33zh , real_T nwypdkysyt , real_T g5cifgqejv , const real_T
fet14bdoje [ 3 ] , real_T er4fwreuhw , real_T jgnicw2ubu , nlxzdmxpff *
localB , mcezkcerxl * localDW , fvjsblhu4h * localP ) { int32_T i ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> d0asq21pdp = localP -> P_28 ;
localB -> lf10iytq4i = localP -> P_29 ; localB -> p0eeldyrwq = localP -> P_30
; localB -> mett4ztxow = localP -> P_31 ; } localB -> md10auzb34 = mqv1fmj0h4
+ noteznn2pu ; if ( localB -> md10auzb34 > localP -> P_24 ) { localB ->
gobejw524j = localB -> p0eeldyrwq ; } else { localB -> gobejw524j = localB ->
mett4ztxow ; } if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsMajorTimeStep ( S ) )
{ if ( localB -> gobejw524j > 0 ) { if ( ! localDW -> njujzfdimj ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S )
; } localDW -> njujzfdimj = true ; } } else { if ( localDW -> njujzfdimj ) {
ssSetSolverNeedsReset ( S ) ; localB -> cbdogvxzxd [ 0 ] = localP -> P_0 [ 0
] ; localB -> p1qhcdd2xz [ 0 ] = localP -> P_0 [ 3 ] ; localB -> cbdogvxzxd [
1 ] = localP -> P_0 [ 1 ] ; localB -> p1qhcdd2xz [ 1 ] = localP -> P_0 [ 4 ]
; localB -> cbdogvxzxd [ 2 ] = localP -> P_0 [ 2 ] ; localB -> p1qhcdd2xz [ 2
] = localP -> P_0 [ 5 ] ; localB -> kn1lbvvirf = localP -> P_1 ; localDW ->
njujzfdimj = false ; } } } if ( localDW -> njujzfdimj ) { localB ->
ldfrqzkrm2 [ 0 ] = dbizdu33zh ; localB -> ldfrqzkrm2 [ 1 ] = nwypdkysyt ;
localB -> ldfrqzkrm2 [ 2 ] = localB -> c3hp2edxed ; muDoubleScalarSinCos (
localB -> ldfrqzkrm2 [ 0 ] , & localB -> ldfrqzkrm2 [ 0 ] , & localB ->
h0mr4dnleo [ 0 ] ) ; muDoubleScalarSinCos ( localB -> ldfrqzkrm2 [ 1 ] , &
localB -> ldfrqzkrm2 [ 1 ] , & localB -> h0mr4dnleo [ 1 ] ) ;
muDoubleScalarSinCos ( localB -> ldfrqzkrm2 [ 2 ] , & localB -> ldfrqzkrm2 [
2 ] , & localB -> h0mr4dnleo [ 2 ] ) ; localB -> nyn1idkajg [ 0 ] = localB ->
h0mr4dnleo [ 1 ] * localB -> h0mr4dnleo [ 2 ] ; localB -> biqscoatzt = localB
-> h0mr4dnleo [ 2 ] * localB -> ldfrqzkrm2 [ 0 ] * localB -> ldfrqzkrm2 [ 1 ]
; localB -> c3qkl4hvmn = localB -> ldfrqzkrm2 [ 2 ] * localB -> h0mr4dnleo [
0 ] ; localB -> nyn1idkajg [ 1 ] = localB -> biqscoatzt - localB ->
c3qkl4hvmn ; localB -> kz4fyodqys = localB -> ldfrqzkrm2 [ 0 ] * localB ->
ldfrqzkrm2 [ 2 ] ; localB -> nlq2fe1f5c = localB -> ldfrqzkrm2 [ 1 ] * localB
-> h0mr4dnleo [ 0 ] * localB -> h0mr4dnleo [ 2 ] ; localB -> nyn1idkajg [ 2 ]
= localB -> kz4fyodqys + localB -> nlq2fe1f5c ; localB -> nyn1idkajg [ 3 ] =
localB -> ldfrqzkrm2 [ 2 ] * localB -> h0mr4dnleo [ 1 ] ; localB ->
exjyjrs2va = localB -> ldfrqzkrm2 [ 0 ] * localB -> ldfrqzkrm2 [ 1 ] * localB
-> ldfrqzkrm2 [ 2 ] ; localB -> gmbcqu2ugs = localB -> h0mr4dnleo [ 0 ] *
localB -> h0mr4dnleo [ 2 ] ; localB -> nyn1idkajg [ 4 ] = localB ->
exjyjrs2va + localB -> gmbcqu2ugs ; localB -> d5eg2cpqti = localB ->
ldfrqzkrm2 [ 1 ] * localB -> ldfrqzkrm2 [ 2 ] * localB -> h0mr4dnleo [ 0 ] ;
localB -> op3jjhn30m = localB -> h0mr4dnleo [ 2 ] * localB -> ldfrqzkrm2 [ 0
] ; localB -> nyn1idkajg [ 5 ] = localB -> d5eg2cpqti - localB -> op3jjhn30m
; localB -> nyn1idkajg [ 6 ] = localP -> P_3 * localB -> ldfrqzkrm2 [ 1 ] ;
localB -> nyn1idkajg [ 7 ] = localB -> ldfrqzkrm2 [ 0 ] * localB ->
h0mr4dnleo [ 1 ] ; localB -> nyn1idkajg [ 8 ] = localB -> h0mr4dnleo [ 0 ] *
localB -> h0mr4dnleo [ 1 ] ; for ( i = 0 ; i < 3 ; i ++ ) { localB ->
etxinyuock [ 3 * i ] = localB -> nyn1idkajg [ i ] ; localB -> etxinyuock [ 1
+ 3 * i ] = localB -> nyn1idkajg [ i + 3 ] ; localB -> etxinyuock [ 2 + 3 * i
] = localB -> nyn1idkajg [ i + 6 ] ; } localB -> h0mr4dnleo [ 0 ] =
fet14bdoje [ 0 ] ; localB -> h0mr4dnleo [ 1 ] = fet14bdoje [ 1 ] ; localB ->
h0mr4dnleo [ 2 ] = localB -> c2015yzswk ; for ( i = 0 ; i < 3 ; i ++ ) {
localB -> ldfrqzkrm2 [ i ] = 0.0 ; localB -> ldfrqzkrm2 [ i ] += localB ->
etxinyuock [ i ] * localB -> h0mr4dnleo [ 0 ] ; localB -> ldfrqzkrm2 [ i ] +=
localB -> etxinyuock [ i + 3 ] * localB -> h0mr4dnleo [ 1 ] ; localB ->
ldfrqzkrm2 [ i ] += localB -> etxinyuock [ i + 6 ] * localB -> h0mr4dnleo [ 2
] ; } localB -> cgeyqqunoc = mqv1fmj0h4 - localB -> ldfrqzkrm2 [ 2 ] ; localB
-> k0l3lx1p1l = localB -> cgeyqqunoc + noteznn2pu ; localB -> h0mr4dnleo [ 0
] = localB -> nyn1idkajg [ 2 ] ; localB -> h0mr4dnleo [ 1 ] = localB ->
nyn1idkajg [ 5 ] ; localB -> h0mr4dnleo [ 2 ] = localB -> nyn1idkajg [ 8 ] ;
localB -> fskv1teg1a = localB -> k0l3lx1p1l / localB -> h0mr4dnleo [ 2 ] ;
localB -> bnjtrdly5b = fet14bdoje [ 2 ] - localB -> fskv1teg1a ; if ( localB
-> bnjtrdly5b > localP -> P_5 ) { localB -> kn1lbvvirf = localP -> P_5 ; }
else if ( localB -> bnjtrdly5b < localP -> P_6 ) { localB -> kn1lbvvirf =
localP -> P_6 ; } else { localB -> kn1lbvvirf = localB -> bnjtrdly5b ; }
localB -> a3i2pmnugq = localP -> P_7 * localB -> kn1lbvvirf ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> j5rwirusfh = localDW -> ods5wrpes0
; } localB -> o2x0khdowp = localB -> kn1lbvvirf - localB -> j5rwirusfh ;
localB -> ehlus03oxd = localP -> P_9 * localB -> o2x0khdowp ; localB ->
ogggnz2ltu = localP -> P_10 * localB -> ehlus03oxd ; localB -> h53jwldojm =
localB -> a3i2pmnugq + localB -> ogggnz2ltu ; localB -> kgzlcwtl5g = localB
-> h53jwldojm / localB -> h0mr4dnleo [ 2 ] ; if ( localB -> kgzlcwtl5g >
localP -> P_11 ) { localB -> gnsrmijzla = localP -> P_11 ; } else if ( localB
-> kgzlcwtl5g < localP -> P_12 ) { localB -> gnsrmijzla = localP -> P_12 ; }
else { localB -> gnsrmijzla = localB -> kgzlcwtl5g ; } localB -> gigiwbrysq =
localP -> P_13 * localB -> gnsrmijzla ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 130 , 40 , SS_CALL_MDL_OUTPUTS ) ; } localB ->
iu2tvrgt4g [ 0 ] = localB -> gigiwbrysq * er4fwreuhw ; localB -> iu2tvrgt4g [
1 ] = localB -> gigiwbrysq * jgnicw2ubu ; localB -> iu2tvrgt4g [ 2 ] = localP
-> P_14 * localB -> gigiwbrysq ; for ( i = 0 ; i < 3 ; i ++ ) { localB ->
cbdogvxzxd [ i ] = 0.0 ; localB -> cbdogvxzxd [ i ] += localB -> nyn1idkajg [
i ] * localB -> iu2tvrgt4g [ 0 ] ; localB -> cbdogvxzxd [ i ] += localB ->
nyn1idkajg [ i + 3 ] * localB -> iu2tvrgt4g [ 1 ] ; localB -> cbdogvxzxd [ i
] += localB -> nyn1idkajg [ i + 6 ] * localB -> iu2tvrgt4g [ 2 ] ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 130 , 47 ,
SS_CALL_MDL_OUTPUTS ) ; } localB -> ffqcrkojmw = fet14bdoje [ 0 ] * localB ->
h0mr4dnleo [ 0 ] ; localB -> exyguh3hj5 = fet14bdoje [ 1 ] * localB ->
h0mr4dnleo [ 1 ] ; localB -> bt0l3phhal = ( ( noteznn2pu + mqv1fmj0h4 ) -
localB -> ffqcrkojmw ) - localB -> exyguh3hj5 ; if ( ssIsSampleHit ( S , 1 ,
0 ) ) { ssCallAccelRunBlock ( S , 130 , 51 , SS_CALL_MDL_OUTPUTS ) ; localB
-> e3321l5ujf [ 0 ] = localP -> P_15 ; } localB -> e3321l5ujf [ 1 ] = localB
-> fskv1teg1a ; localB -> e3321l5ujf [ 2 ] = localB -> krvcktpdcv ; localB ->
e3321l5ujf [ 3 ] = localP -> P_17 * localB -> fskv1teg1a ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { localB -> e3321l5ujf [ 4 ] = localP -> P_18 ; } localB ->
e3321l5ujf [ 5 ] = fet14bdoje [ 0 ] ; localB -> e3321l5ujf [ 6 ] = fet14bdoje
[ 1 ] ; localB -> e3321l5ujf [ 7 ] = localB -> h0ehx51y2w ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> e3321l5ujf [ 8 ] = localP -> P_20 ;
} for ( i = 0 ; i < 3 ; i ++ ) { localB -> h0mr4dnleo [ i ] = 0.0 ; localB ->
h0mr4dnleo [ i ] += localB -> e3321l5ujf [ 3 * i ] * localB -> cbdogvxzxd [ 0
] ; localB -> h0mr4dnleo [ i ] += localB -> e3321l5ujf [ 3 * i + 1 ] * localB
-> cbdogvxzxd [ 1 ] ; localB -> h0mr4dnleo [ i ] += localB -> e3321l5ujf [ 3
* i + 2 ] * localB -> cbdogvxzxd [ 2 ] ; } for ( i = 0 ; i < 3 ; i ++ ) {
localB -> p1qhcdd2xz [ i ] = 0.0 ; localB -> p1qhcdd2xz [ i ] += localP ->
P_21 [ i ] * localB -> h0mr4dnleo [ 0 ] ; localB -> p1qhcdd2xz [ i ] +=
localP -> P_21 [ i + 3 ] * localB -> h0mr4dnleo [ 1 ] ; localB -> p1qhcdd2xz
[ i ] += localP -> P_21 [ i + 6 ] * localB -> h0mr4dnleo [ 2 ] ; } localB ->
h0mr4dnleo [ 0 ] = dbizdu33zh + localP -> P_22 [ 0 ] ; localB -> h0mr4dnleo [
1 ] = nwypdkysyt + localP -> P_22 [ 1 ] ; localB -> h0mr4dnleo [ 2 ] =
g5cifgqejv + localP -> P_22 [ 2 ] ; localB -> ldfrqzkrm2 [ 0 ] = localB ->
h0mr4dnleo [ 2 ] ; localB -> ldfrqzkrm2 [ 1 ] = localB -> h0mr4dnleo [ 1 ] ;
localB -> ldfrqzkrm2 [ 2 ] = localB -> h0mr4dnleo [ 0 ] ;
muDoubleScalarSinCos ( localB -> ldfrqzkrm2 [ 0 ] , & localB -> ldfrqzkrm2 [
0 ] , & localB -> h0mr4dnleo [ 0 ] ) ; muDoubleScalarSinCos ( localB ->
ldfrqzkrm2 [ 1 ] , & localB -> ldfrqzkrm2 [ 1 ] , & localB -> h0mr4dnleo [ 1
] ) ; muDoubleScalarSinCos ( localB -> ldfrqzkrm2 [ 2 ] , & localB ->
ldfrqzkrm2 [ 2 ] , & localB -> h0mr4dnleo [ 2 ] ) ; localB -> ezgmoifw0c [ 0
] = localB -> h0mr4dnleo [ 1 ] * localB -> h0mr4dnleo [ 0 ] ; localB ->
ezgmoifw0c [ 1 ] = localB -> ldfrqzkrm2 [ 2 ] * localB -> ldfrqzkrm2 [ 1 ] *
localB -> h0mr4dnleo [ 0 ] - localB -> h0mr4dnleo [ 2 ] * localB ->
ldfrqzkrm2 [ 0 ] ; localB -> ezgmoifw0c [ 2 ] = localB -> h0mr4dnleo [ 2 ] *
localB -> ldfrqzkrm2 [ 1 ] * localB -> h0mr4dnleo [ 0 ] + localB ->
ldfrqzkrm2 [ 2 ] * localB -> ldfrqzkrm2 [ 0 ] ; localB -> ezgmoifw0c [ 3 ] =
localB -> h0mr4dnleo [ 1 ] * localB -> ldfrqzkrm2 [ 0 ] ; localB ->
ezgmoifw0c [ 4 ] = localB -> ldfrqzkrm2 [ 2 ] * localB -> ldfrqzkrm2 [ 1 ] *
localB -> ldfrqzkrm2 [ 0 ] + localB -> h0mr4dnleo [ 2 ] * localB ->
h0mr4dnleo [ 0 ] ; localB -> ezgmoifw0c [ 5 ] = localB -> h0mr4dnleo [ 2 ] *
localB -> ldfrqzkrm2 [ 1 ] * localB -> ldfrqzkrm2 [ 0 ] - localB ->
ldfrqzkrm2 [ 2 ] * localB -> h0mr4dnleo [ 0 ] ; localB -> ezgmoifw0c [ 6 ] =
- localB -> ldfrqzkrm2 [ 1 ] ; localB -> ezgmoifw0c [ 7 ] = localB ->
ldfrqzkrm2 [ 2 ] * localB -> h0mr4dnleo [ 1 ] ; localB -> ezgmoifw0c [ 8 ] =
localB -> h0mr4dnleo [ 2 ] * localB -> h0mr4dnleo [ 1 ] ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> dzvgqeptl5 ) ; } } localB
-> f330bn5iun = localP -> P_25 * localB -> cbdogvxzxd [ 2 ] ; localB ->
nwqgvicavu [ 0 ] = dbizdu33zh ; localB -> nwqgvicavu [ 1 ] = nwypdkysyt ;
localB -> nwqgvicavu [ 2 ] = localB -> dkcbr2j23e ; muDoubleScalarSinCos (
localB -> nwqgvicavu [ 0 ] , & localB -> nwqgvicavu [ 0 ] , & localB ->
p5o42pz5vv [ 0 ] ) ; muDoubleScalarSinCos ( localB -> nwqgvicavu [ 1 ] , &
localB -> nwqgvicavu [ 1 ] , & localB -> p5o42pz5vv [ 1 ] ) ;
muDoubleScalarSinCos ( localB -> nwqgvicavu [ 2 ] , & localB -> nwqgvicavu [
2 ] , & localB -> p5o42pz5vv [ 2 ] ) ; localB -> kyj5hxehnc [ 0 ] = localB ->
p5o42pz5vv [ 1 ] * localB -> p5o42pz5vv [ 2 ] ; localB -> kyj5hxehnc [ 3 ] =
localB -> nwqgvicavu [ 2 ] * localB -> p5o42pz5vv [ 1 ] ; localB ->
kyj5hxehnc [ 6 ] = localP -> P_26 * localB -> nwqgvicavu [ 1 ] ; localB ->
ol03ta01mu = localB -> p5o42pz5vv [ 2 ] * localB -> nwqgvicavu [ 0 ] * localB
-> nwqgvicavu [ 1 ] ; localB -> eydlsvnz3f = localB -> nwqgvicavu [ 2 ] *
localB -> p5o42pz5vv [ 0 ] ; localB -> kyj5hxehnc [ 1 ] = localB ->
ol03ta01mu - localB -> eydlsvnz3f ; localB -> iv0zun1yhs = localB ->
nwqgvicavu [ 0 ] * localB -> nwqgvicavu [ 1 ] * localB -> nwqgvicavu [ 2 ] ;
localB -> f1qrjpwx2f = localB -> p5o42pz5vv [ 0 ] * localB -> p5o42pz5vv [ 2
] ; localB -> kyj5hxehnc [ 4 ] = localB -> iv0zun1yhs + localB -> f1qrjpwx2f
; localB -> kyj5hxehnc [ 7 ] = localB -> nwqgvicavu [ 0 ] * localB ->
p5o42pz5vv [ 1 ] ; localB -> dqha5py0qv = localB -> nwqgvicavu [ 0 ] * localB
-> nwqgvicavu [ 2 ] ; localB -> ioocaupe2d = localB -> nwqgvicavu [ 1 ] *
localB -> p5o42pz5vv [ 0 ] * localB -> p5o42pz5vv [ 2 ] ; localB ->
kyj5hxehnc [ 2 ] = localB -> dqha5py0qv + localB -> ioocaupe2d ; localB ->
hmcadkupuf = localB -> nwqgvicavu [ 1 ] * localB -> nwqgvicavu [ 2 ] * localB
-> p5o42pz5vv [ 0 ] ; localB -> lybjeclf2j = localB -> p5o42pz5vv [ 2 ] *
localB -> nwqgvicavu [ 0 ] ; localB -> kyj5hxehnc [ 5 ] = localB ->
hmcadkupuf - localB -> lybjeclf2j ; localB -> kyj5hxehnc [ 8 ] = localB ->
p5o42pz5vv [ 0 ] * localB -> p5o42pz5vv [ 1 ] ; if ( localB -> f330bn5iun >
localP -> P_27 ) { localB -> pnd0lq04oj = localB -> d0asq21pdp ; } else {
localB -> pnd0lq04oj = localB -> lf10iytq4i ; } } void b1bttejwsjTID2 (
SimStruct * const S , const real_T fet14bdoje [ 3 ] , nlxzdmxpff * localB ,
mcezkcerxl * localDW , fvjsblhu4h * localP ) { localB -> dkcbr2j23e = localP
-> P_23 ; localB -> c3hp2edxed = localP -> P_2 ; localB -> c2015yzswk =
localP -> P_4 ; localB -> krvcktpdcv = localP -> P_16 * fet14bdoje [ 1 ] ;
localB -> h0ehx51y2w = localP -> P_19 * fet14bdoje [ 0 ] ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> dzvgqeptl5 ) ; } } void
ggcobnfl5g ( SimStruct * const S , nlxzdmxpff * localB , mcezkcerxl * localDW
) { if ( localDW -> njujzfdimj && ssIsSampleHit ( S , 1 , 0 ) ) { localDW ->
ods5wrpes0 = localB -> kn1lbvvirf ; } } void kkd2eqkx5k ( SimStruct * const S
) { } void bieqb4n1n0 ( nqr53r3iar * localB , bewbuevixx * localDW ,
fgfesxh13p * localP ) { localDW -> mxrnl1d4wd = localP -> P_7 ; localB ->
elpwly1l1t [ 0 ] = localP -> P_0 [ 0 ] ; localB -> maromz3wf3 [ 0 ] = localP
-> P_0 [ 3 ] ; localB -> elpwly1l1t [ 1 ] = localP -> P_0 [ 1 ] ; localB ->
maromz3wf3 [ 1 ] = localP -> P_0 [ 4 ] ; localB -> elpwly1l1t [ 2 ] = localP
-> P_0 [ 2 ] ; localB -> maromz3wf3 [ 2 ] = localP -> P_0 [ 5 ] ; localB ->
njlp22tpxd = localP -> P_1 ; } void igndwt035f ( nqr53r3iar * localB ,
bewbuevixx * localDW , fgfesxh13p * localP ) { if ( localDW -> b4sy0n55gs ) {
localB -> elpwly1l1t [ 0 ] = localP -> P_0 [ 0 ] ; localB -> maromz3wf3 [ 0 ]
= localP -> P_0 [ 3 ] ; localB -> elpwly1l1t [ 1 ] = localP -> P_0 [ 1 ] ;
localB -> maromz3wf3 [ 1 ] = localP -> P_0 [ 4 ] ; localB -> elpwly1l1t [ 2 ]
= localP -> P_0 [ 2 ] ; localB -> maromz3wf3 [ 2 ] = localP -> P_0 [ 5 ] ;
localB -> njlp22tpxd = localP -> P_1 ; localDW -> b4sy0n55gs = false ; } }
void dak2bbvhdy ( SimStruct * const S , real_T pm5rlqqzgg , real_T dj1eg0kba5
, real_T ijr5dtekxq , real_T kt2gyj2sli , real_T bkwbtezauh , const real_T
gzfuumbstf [ 3 ] , real_T looklzp1sr , real_T elrgqbqmp1 , nqr53r3iar *
localB , bewbuevixx * localDW , fgfesxh13p * localP ) { int32_T i ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> ovk5yq5pkv = localP -> P_28 ;
localB -> bettc5qxxj = localP -> P_29 ; localB -> nvoufl0gfz = localP -> P_30
; localB -> hnq3ippxe3 = localP -> P_31 ; } localB -> fzebh1xhoe = dj1eg0kba5
+ pm5rlqqzgg ; if ( localB -> fzebh1xhoe > localP -> P_24 ) { localB ->
kx1du40q40 = localB -> nvoufl0gfz ; } else { localB -> kx1du40q40 = localB ->
hnq3ippxe3 ; } if ( ssIsSampleHit ( S , 1 , 0 ) && ssIsMajorTimeStep ( S ) )
{ if ( localB -> kx1du40q40 > 0 ) { if ( ! localDW -> b4sy0n55gs ) { if (
ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S )
; } localDW -> b4sy0n55gs = true ; } } else { if ( localDW -> b4sy0n55gs ) {
ssSetSolverNeedsReset ( S ) ; localB -> elpwly1l1t [ 0 ] = localP -> P_0 [ 0
] ; localB -> maromz3wf3 [ 0 ] = localP -> P_0 [ 3 ] ; localB -> elpwly1l1t [
1 ] = localP -> P_0 [ 1 ] ; localB -> maromz3wf3 [ 1 ] = localP -> P_0 [ 4 ]
; localB -> elpwly1l1t [ 2 ] = localP -> P_0 [ 2 ] ; localB -> maromz3wf3 [ 2
] = localP -> P_0 [ 5 ] ; localB -> njlp22tpxd = localP -> P_1 ; localDW ->
b4sy0n55gs = false ; } } } if ( localDW -> b4sy0n55gs ) { localB ->
hdavqp3yah [ 0 ] = ijr5dtekxq ; localB -> hdavqp3yah [ 1 ] = kt2gyj2sli ;
localB -> hdavqp3yah [ 2 ] = localB -> erwgbayc1r ; muDoubleScalarSinCos (
localB -> hdavqp3yah [ 0 ] , & localB -> hdavqp3yah [ 0 ] , & localB ->
prfi4q3ptx [ 0 ] ) ; muDoubleScalarSinCos ( localB -> hdavqp3yah [ 1 ] , &
localB -> hdavqp3yah [ 1 ] , & localB -> prfi4q3ptx [ 1 ] ) ;
muDoubleScalarSinCos ( localB -> hdavqp3yah [ 2 ] , & localB -> hdavqp3yah [
2 ] , & localB -> prfi4q3ptx [ 2 ] ) ; localB -> pirz03oxku [ 0 ] = localB ->
prfi4q3ptx [ 1 ] * localB -> prfi4q3ptx [ 2 ] ; localB -> jlkd03edak = localB
-> prfi4q3ptx [ 2 ] * localB -> hdavqp3yah [ 0 ] * localB -> hdavqp3yah [ 1 ]
; localB -> fzpsaakdgb = localB -> hdavqp3yah [ 2 ] * localB -> prfi4q3ptx [
0 ] ; localB -> pirz03oxku [ 1 ] = localB -> jlkd03edak - localB ->
fzpsaakdgb ; localB -> k5k2v5nxqa = localB -> hdavqp3yah [ 0 ] * localB ->
hdavqp3yah [ 2 ] ; localB -> bnpy3y5pey = localB -> hdavqp3yah [ 1 ] * localB
-> prfi4q3ptx [ 0 ] * localB -> prfi4q3ptx [ 2 ] ; localB -> pirz03oxku [ 2 ]
= localB -> k5k2v5nxqa + localB -> bnpy3y5pey ; localB -> pirz03oxku [ 3 ] =
localB -> hdavqp3yah [ 2 ] * localB -> prfi4q3ptx [ 1 ] ; localB ->
o1lm2pfn4e = localB -> hdavqp3yah [ 0 ] * localB -> hdavqp3yah [ 1 ] * localB
-> hdavqp3yah [ 2 ] ; localB -> k4bhfvyizw = localB -> prfi4q3ptx [ 0 ] *
localB -> prfi4q3ptx [ 2 ] ; localB -> pirz03oxku [ 4 ] = localB ->
o1lm2pfn4e + localB -> k4bhfvyizw ; localB -> flvwmgarg4 = localB ->
hdavqp3yah [ 1 ] * localB -> hdavqp3yah [ 2 ] * localB -> prfi4q3ptx [ 0 ] ;
localB -> dydsben12q = localB -> prfi4q3ptx [ 2 ] * localB -> hdavqp3yah [ 0
] ; localB -> pirz03oxku [ 5 ] = localB -> flvwmgarg4 - localB -> dydsben12q
; localB -> pirz03oxku [ 6 ] = localP -> P_3 * localB -> hdavqp3yah [ 1 ] ;
localB -> pirz03oxku [ 7 ] = localB -> hdavqp3yah [ 0 ] * localB ->
prfi4q3ptx [ 1 ] ; localB -> pirz03oxku [ 8 ] = localB -> prfi4q3ptx [ 0 ] *
localB -> prfi4q3ptx [ 1 ] ; localB -> prfi4q3ptx [ 0 ] = localB ->
pirz03oxku [ 2 ] ; localB -> prfi4q3ptx [ 1 ] = localB -> pirz03oxku [ 5 ] ;
localB -> prfi4q3ptx [ 2 ] = localB -> pirz03oxku [ 8 ] ; localB ->
jfy5g4vjo0 = gzfuumbstf [ 0 ] * localB -> prfi4q3ptx [ 0 ] ; localB ->
dmu1dti3cl = gzfuumbstf [ 1 ] * localB -> prfi4q3ptx [ 1 ] ; localB ->
i1kce5uepk = ( ( pm5rlqqzgg + dj1eg0kba5 ) - localB -> jfy5g4vjo0 ) - localB
-> dmu1dti3cl ; localB -> prcgnatbtx = localB -> i1kce5uepk / localB ->
prfi4q3ptx [ 2 ] ; localB -> oqihj4vgmb = gzfuumbstf [ 2 ] - localB ->
prcgnatbtx ; if ( localB -> oqihj4vgmb > localP -> P_4 ) { localB ->
njlp22tpxd = localP -> P_4 ; } else if ( localB -> oqihj4vgmb < localP -> P_5
) { localB -> njlp22tpxd = localP -> P_5 ; } else { localB -> njlp22tpxd =
localB -> oqihj4vgmb ; } localB -> e4lmvpnfmv = localP -> P_6 * localB ->
njlp22tpxd ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { localB -> dfzkxbufgm =
localDW -> mxrnl1d4wd ; } localB -> ac1el5yqew = localB -> njlp22tpxd -
localB -> dfzkxbufgm ; localB -> hut4ttxvlo = localP -> P_8 * localB ->
ac1el5yqew ; localB -> pmiy52gna1 = localP -> P_9 * localB -> hut4ttxvlo ;
localB -> hgbxi3i0n0 = localB -> e4lmvpnfmv + localB -> pmiy52gna1 ; localB
-> cvg3mttezz = localB -> hgbxi3i0n0 / localB -> prfi4q3ptx [ 2 ] ; if (
localB -> cvg3mttezz > localP -> P_10 ) { localB -> nwq2ulzlwt = localP ->
P_10 ; } else if ( localB -> cvg3mttezz < localP -> P_11 ) { localB ->
nwq2ulzlwt = localP -> P_11 ; } else { localB -> nwq2ulzlwt = localB ->
cvg3mttezz ; } localB -> mtmmsozexf = localP -> P_12 * localB -> nwq2ulzlwt ;
localB -> hv1uspgfop [ 0 ] = localB -> mtmmsozexf * looklzp1sr ; localB ->
hv1uspgfop [ 1 ] = localB -> mtmmsozexf * elrgqbqmp1 ; localB -> hv1uspgfop [
2 ] = localB -> mtmmsozexf ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 132 , 42 , SS_CALL_MDL_OUTPUTS ) ; localB ->
lv4er4qze2 [ 0 ] = localP -> P_13 ; } localB -> lv4er4qze2 [ 1 ] = localB ->
prcgnatbtx ; localB -> lv4er4qze2 [ 2 ] = localB -> j1ee2vnbhn ; localB ->
lv4er4qze2 [ 3 ] = localP -> P_15 * localB -> prcgnatbtx ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { localB -> lv4er4qze2 [ 4 ] = localP -> P_16 ; } localB ->
lv4er4qze2 [ 5 ] = gzfuumbstf [ 0 ] ; localB -> lv4er4qze2 [ 6 ] = gzfuumbstf
[ 1 ] ; localB -> lv4er4qze2 [ 7 ] = localB -> kwrkjys23n ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { localB -> lv4er4qze2 [ 8 ] = localP -> P_18 ;
ssCallAccelRunBlock ( S , 132 , 55 , SS_CALL_MDL_OUTPUTS ) ; } for ( i = 0 ;
i < 3 ; i ++ ) { localB -> elpwly1l1t [ i ] = 0.0 ; localB -> elpwly1l1t [ i
] += localB -> pirz03oxku [ i ] * localB -> hv1uspgfop [ 0 ] ; localB ->
elpwly1l1t [ i ] += localB -> pirz03oxku [ i + 3 ] * localB -> hv1uspgfop [ 1
] ; localB -> elpwly1l1t [ i ] += localB -> pirz03oxku [ i + 6 ] * localB ->
hv1uspgfop [ 2 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { localB -> lwqnhvx3li [ i
] = 0.0 ; localB -> lwqnhvx3li [ i ] += localB -> lv4er4qze2 [ 3 * i ] *
localB -> elpwly1l1t [ 0 ] ; localB -> lwqnhvx3li [ i ] += localB ->
lv4er4qze2 [ 3 * i + 1 ] * localB -> elpwly1l1t [ 1 ] ; localB -> lwqnhvx3li
[ i ] += localB -> lv4er4qze2 [ 3 * i + 2 ] * localB -> elpwly1l1t [ 2 ] ;
localB -> maromz3wf3 [ i ] = localP -> P_19 [ i ] * localB -> lwqnhvx3li [ i
] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 132 , 59
, SS_CALL_MDL_OUTPUTS ) ; } localB -> jsuepbpxob = gzfuumbstf [ 1 ] * localB
-> elpwly1l1t [ 2 ] ; localB -> iagbdgjgrp = gzfuumbstf [ 2 ] * localB ->
elpwly1l1t [ 0 ] ; localB -> btwlkimsn1 = gzfuumbstf [ 0 ] * localB ->
elpwly1l1t [ 1 ] ; localB -> b5k41ai1bd = gzfuumbstf [ 2 ] * localB ->
elpwly1l1t [ 1 ] ; localB -> p2n1yr2ifl = gzfuumbstf [ 0 ] * localB ->
elpwly1l1t [ 2 ] ; localB -> dahpncbia3 = gzfuumbstf [ 1 ] * localB ->
elpwly1l1t [ 0 ] ; localB -> prfi4q3ptx [ 0 ] = localB -> jsuepbpxob - localB
-> b5k41ai1bd ; localB -> prfi4q3ptx [ 1 ] = localB -> iagbdgjgrp - localB ->
p2n1yr2ifl ; localB -> prfi4q3ptx [ 2 ] = localB -> btwlkimsn1 - localB ->
dahpncbia3 ; localB -> kxqrfztx3x [ 0 ] = localP -> P_20 * localB ->
prfi4q3ptx [ 0 ] ; localB -> kxqrfztx3x [ 1 ] = localP -> P_20 * localB ->
prfi4q3ptx [ 1 ] ; localB -> kxqrfztx3x [ 2 ] = localP -> P_20 * localB ->
prfi4q3ptx [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock (
S , 132 , 68 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 132 , 69 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 132 , 70 ,
SS_CALL_MDL_OUTPUTS ) ; } for ( i = 0 ; i < 3 ; i ++ ) { localB -> autt31xhzr
[ 3 * i ] = localB -> pirz03oxku [ i ] ; localB -> autt31xhzr [ 1 + 3 * i ] =
localB -> pirz03oxku [ i + 3 ] ; localB -> autt31xhzr [ 2 + 3 * i ] = localB
-> pirz03oxku [ i + 6 ] ; } localB -> prfi4q3ptx [ 0 ] = gzfuumbstf [ 0 ] ;
localB -> prfi4q3ptx [ 1 ] = gzfuumbstf [ 1 ] ; localB -> prfi4q3ptx [ 2 ] =
localB -> p5y4eolt3m ; for ( i = 0 ; i < 3 ; i ++ ) { localB -> mei35ufh1v [
i ] = 0.0 ; localB -> mei35ufh1v [ i ] += localB -> autt31xhzr [ i ] * localB
-> prfi4q3ptx [ 0 ] ; localB -> mei35ufh1v [ i ] += localB -> autt31xhzr [ i
+ 3 ] * localB -> prfi4q3ptx [ 1 ] ; localB -> mei35ufh1v [ i ] += localB ->
autt31xhzr [ i + 6 ] * localB -> prfi4q3ptx [ 2 ] ; } localB -> ckysukbndz =
dj1eg0kba5 - localB -> mei35ufh1v [ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) )
{ ssCallAccelRunBlock ( S , 132 , 76 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 132 , 77 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 132 , 78 , SS_CALL_MDL_OUTPUTS ) ; } localB ->
prfi4q3ptx [ 0 ] = ijr5dtekxq + localP -> P_22 [ 0 ] ; localB -> prfi4q3ptx [
1 ] = kt2gyj2sli + localP -> P_22 [ 1 ] ; localB -> prfi4q3ptx [ 2 ] =
bkwbtezauh + localP -> P_22 [ 2 ] ; localB -> hdavqp3yah [ 0 ] = localB ->
prfi4q3ptx [ 2 ] ; localB -> hdavqp3yah [ 1 ] = localB -> prfi4q3ptx [ 1 ] ;
localB -> hdavqp3yah [ 2 ] = localB -> prfi4q3ptx [ 0 ] ;
muDoubleScalarSinCos ( localB -> hdavqp3yah [ 0 ] , & localB -> hdavqp3yah [
0 ] , & localB -> prfi4q3ptx [ 0 ] ) ; muDoubleScalarSinCos ( localB ->
hdavqp3yah [ 1 ] , & localB -> hdavqp3yah [ 1 ] , & localB -> prfi4q3ptx [ 1
] ) ; muDoubleScalarSinCos ( localB -> hdavqp3yah [ 2 ] , & localB ->
hdavqp3yah [ 2 ] , & localB -> prfi4q3ptx [ 2 ] ) ; localB -> gitbyl1203 [ 0
] = localB -> prfi4q3ptx [ 1 ] * localB -> prfi4q3ptx [ 0 ] ; localB ->
gitbyl1203 [ 1 ] = localB -> hdavqp3yah [ 2 ] * localB -> hdavqp3yah [ 1 ] *
localB -> prfi4q3ptx [ 0 ] - localB -> prfi4q3ptx [ 2 ] * localB ->
hdavqp3yah [ 0 ] ; localB -> gitbyl1203 [ 2 ] = localB -> prfi4q3ptx [ 2 ] *
localB -> hdavqp3yah [ 1 ] * localB -> prfi4q3ptx [ 0 ] + localB ->
hdavqp3yah [ 2 ] * localB -> hdavqp3yah [ 0 ] ; localB -> gitbyl1203 [ 3 ] =
localB -> prfi4q3ptx [ 1 ] * localB -> hdavqp3yah [ 0 ] ; localB ->
gitbyl1203 [ 4 ] = localB -> hdavqp3yah [ 2 ] * localB -> hdavqp3yah [ 1 ] *
localB -> hdavqp3yah [ 0 ] + localB -> prfi4q3ptx [ 2 ] * localB ->
prfi4q3ptx [ 0 ] ; localB -> gitbyl1203 [ 5 ] = localB -> prfi4q3ptx [ 2 ] *
localB -> hdavqp3yah [ 1 ] * localB -> hdavqp3yah [ 0 ] - localB ->
hdavqp3yah [ 2 ] * localB -> prfi4q3ptx [ 0 ] ; localB -> gitbyl1203 [ 6 ] =
- localB -> hdavqp3yah [ 1 ] ; localB -> gitbyl1203 [ 7 ] = localB ->
hdavqp3yah [ 2 ] * localB -> prfi4q3ptx [ 1 ] ; localB -> gitbyl1203 [ 8 ] =
localB -> prfi4q3ptx [ 2 ] * localB -> prfi4q3ptx [ 1 ] ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> ksd30berzr ) ; } } localB
-> m32hpzj2yk = localP -> P_25 * localB -> elpwly1l1t [ 2 ] ; localB ->
gtcudc20vn [ 0 ] = ijr5dtekxq ; localB -> gtcudc20vn [ 1 ] = kt2gyj2sli ;
localB -> gtcudc20vn [ 2 ] = localB -> dfkbssokoy ; muDoubleScalarSinCos (
localB -> gtcudc20vn [ 0 ] , & localB -> gtcudc20vn [ 0 ] , & localB ->
fs1ucgqrxx [ 0 ] ) ; muDoubleScalarSinCos ( localB -> gtcudc20vn [ 1 ] , &
localB -> gtcudc20vn [ 1 ] , & localB -> fs1ucgqrxx [ 1 ] ) ;
muDoubleScalarSinCos ( localB -> gtcudc20vn [ 2 ] , & localB -> gtcudc20vn [
2 ] , & localB -> fs1ucgqrxx [ 2 ] ) ; localB -> adfsc2iasd [ 0 ] = localB ->
fs1ucgqrxx [ 1 ] * localB -> fs1ucgqrxx [ 2 ] ; localB -> adfsc2iasd [ 3 ] =
localB -> gtcudc20vn [ 2 ] * localB -> fs1ucgqrxx [ 1 ] ; localB ->
adfsc2iasd [ 6 ] = localP -> P_26 * localB -> gtcudc20vn [ 1 ] ; localB ->
kijbkri0qm = localB -> fs1ucgqrxx [ 2 ] * localB -> gtcudc20vn [ 0 ] * localB
-> gtcudc20vn [ 1 ] ; localB -> jvy5zjfyzw = localB -> gtcudc20vn [ 2 ] *
localB -> fs1ucgqrxx [ 0 ] ; localB -> adfsc2iasd [ 1 ] = localB ->
kijbkri0qm - localB -> jvy5zjfyzw ; localB -> pl33oymwz1 = localB ->
gtcudc20vn [ 0 ] * localB -> gtcudc20vn [ 1 ] * localB -> gtcudc20vn [ 2 ] ;
localB -> kan2ikluc1 = localB -> fs1ucgqrxx [ 0 ] * localB -> fs1ucgqrxx [ 2
] ; localB -> adfsc2iasd [ 4 ] = localB -> pl33oymwz1 + localB -> kan2ikluc1
; localB -> adfsc2iasd [ 7 ] = localB -> gtcudc20vn [ 0 ] * localB ->
fs1ucgqrxx [ 1 ] ; localB -> bmqdijm13o = localB -> gtcudc20vn [ 0 ] * localB
-> gtcudc20vn [ 2 ] ; localB -> oosuevdmbd = localB -> gtcudc20vn [ 1 ] *
localB -> fs1ucgqrxx [ 0 ] * localB -> fs1ucgqrxx [ 2 ] ; localB ->
adfsc2iasd [ 2 ] = localB -> bmqdijm13o + localB -> oosuevdmbd ; localB ->
h4j3lbh14x = localB -> gtcudc20vn [ 1 ] * localB -> gtcudc20vn [ 2 ] * localB
-> fs1ucgqrxx [ 0 ] ; localB -> kjhlhyhx23 = localB -> fs1ucgqrxx [ 2 ] *
localB -> gtcudc20vn [ 0 ] ; localB -> adfsc2iasd [ 5 ] = localB ->
h4j3lbh14x - localB -> kjhlhyhx23 ; localB -> adfsc2iasd [ 8 ] = localB ->
fs1ucgqrxx [ 0 ] * localB -> fs1ucgqrxx [ 1 ] ; if ( localB -> m32hpzj2yk >
localP -> P_27 ) { localB -> ltkssyvcf5 = localB -> ovk5yq5pkv ; } else {
localB -> ltkssyvcf5 = localB -> bettc5qxxj ; } } void dak2bbvhdyTID2 (
SimStruct * const S , const real_T gzfuumbstf [ 3 ] , nqr53r3iar * localB ,
bewbuevixx * localDW , fgfesxh13p * localP ) { localB -> dfkbssokoy = localP
-> P_23 ; localB -> erwgbayc1r = localP -> P_2 ; localB -> j1ee2vnbhn =
localP -> P_14 * gzfuumbstf [ 1 ] ; localB -> kwrkjys23n = localP -> P_17 *
gzfuumbstf [ 0 ] ; localB -> p5y4eolt3m = localP -> P_21 ;
ssCallAccelRunBlock ( S , 132 , 79 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> ksd30berzr ) ; } } void
onr0acfhav ( SimStruct * const S , nqr53r3iar * localB , bewbuevixx * localDW
) { if ( localDW -> b4sy0n55gs && ssIsSampleHit ( S , 1 , 0 ) ) { localDW ->
mxrnl1d4wd = localB -> njlp22tpxd ; } } void dkmvj2wfn0 ( SimStruct * const S
) { } void h3v44pg0kk ( real_T fmumi05obi , const real_T ppb3dktj10 [ 9 ] ,
real_T * madmhz5eqy , real_T pxkeba3ih1 [ 3 ] , k45adr4f5c * localB ,
grglhn4pya * localP ) { localB -> o1vqesp0kg = fmumi05obi + localB ->
pdssrqqlkm ; localB -> mpvb3le0jp = muDoubleScalarSqrt ( localB -> o1vqesp0kg
) ; * madmhz5eqy = localP -> P_1 * localB -> mpvb3le0jp ; localB ->
d0tv1dxhll = localP -> P_2 * localB -> mpvb3le0jp ; localB -> lbm2vaamch =
ppb3dktj10 [ 7 ] - ppb3dktj10 [ 5 ] ; localB -> ja0hi4n1mq = ppb3dktj10 [ 2 ]
- ppb3dktj10 [ 6 ] ; localB -> fvvv5dirg5 = ppb3dktj10 [ 3 ] - ppb3dktj10 [ 1
] ; pxkeba3ih1 [ 0 ] = localB -> lbm2vaamch / localB -> d0tv1dxhll ;
pxkeba3ih1 [ 1 ] = localB -> ja0hi4n1mq / localB -> d0tv1dxhll ; pxkeba3ih1 [
2 ] = localB -> fvvv5dirg5 / localB -> d0tv1dxhll ; } void h3v44pg0kkTID2 (
k45adr4f5c * localB , grglhn4pya * localP ) { localB -> pdssrqqlkm = localP
-> P_0 ; } void kwsvntlcfx ( SimStruct * const S ) { } void iorhdpdmai (
SimStruct * const S , const real_T l0032p1zr2 [ 9 ] , real_T * b4ei5neduy ,
real_T * lerqs0qiln , real_T * hh3qhyha0i , real_T * n4p4av1cij , gritqy5sso
* localB , pef3aehv5o * localDW , dcmchj0dqy * localP ) { int8_T rtAction ;
if ( ssIsMajorTimeStep ( S ) ) { if ( ( l0032p1zr2 [ 4 ] > l0032p1zr2 [ 0 ] )
&& ( l0032p1zr2 [ 4 ] > l0032p1zr2 [ 8 ] ) ) { rtAction = 0 ; } else if (
l0032p1zr2 [ 8 ] > l0032p1zr2 [ 0 ] ) { rtAction = 1 ; } else { rtAction = 2
; } localDW -> bkhur3hlqv = rtAction ; } else { rtAction = localDW ->
bkhur3hlqv ; } switch ( rtAction ) { case 0 : localB -> nd2llks0e0 = ( (
l0032p1zr2 [ 4 ] - l0032p1zr2 [ 0 ] ) - l0032p1zr2 [ 8 ] ) + localB ->
dpvym2mupn ; localB -> adllw2ovdp = muDoubleScalarSqrt ( localB -> nd2llks0e0
) ; * hh3qhyha0i = localP -> P_1 * localB -> adllw2ovdp ; localB ->
hklbzr5jrw = l0032p1zr2 [ 1 ] + l0032p1zr2 [ 3 ] ; localB -> btqxld2aer =
l0032p1zr2 [ 5 ] + l0032p1zr2 [ 7 ] ; localB -> glkxc2iwlw = l0032p1zr2 [ 2 ]
- l0032p1zr2 [ 6 ] ; if ( localB -> adllw2ovdp != 0.0 ) { localB ->
lqhd1dhu5t [ 0 ] = localB -> d4rw5s2nwv ; localB -> lqhd1dhu5t [ 1 ] = localB
-> adllw2ovdp ; } else { localB -> lqhd1dhu5t [ 0 ] = localB -> e0mys1kfvr [
0 ] ; localB -> lqhd1dhu5t [ 1 ] = localB -> e0mys1kfvr [ 1 ] ; } localB ->
bg3tehbvub = localB -> lqhd1dhu5t [ 0 ] / localB -> lqhd1dhu5t [ 1 ] ; localB
-> o3cdv4ejqo [ 0 ] = localB -> hklbzr5jrw * localB -> bg3tehbvub ; localB ->
o3cdv4ejqo [ 1 ] = localB -> btqxld2aer * localB -> bg3tehbvub ; localB ->
o3cdv4ejqo [ 2 ] = localB -> glkxc2iwlw * localB -> bg3tehbvub ; * lerqs0qiln
= localP -> P_4 * localB -> o3cdv4ejqo [ 0 ] ; * n4p4av1cij = localP -> P_5 *
localB -> o3cdv4ejqo [ 1 ] ; * b4ei5neduy = localP -> P_6 * localB ->
o3cdv4ejqo [ 2 ] ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
k5txj3pde2 ) ; } break ; case 1 : localB -> ght1xq0omp = ( ( l0032p1zr2 [ 8 ]
- l0032p1zr2 [ 0 ] ) - l0032p1zr2 [ 4 ] ) + localB -> leihpkmh4s ; localB ->
evi5rjpxuf = muDoubleScalarSqrt ( localB -> ght1xq0omp ) ; * n4p4av1cij =
localP -> P_8 * localB -> evi5rjpxuf ; localB -> b0ys550alf = l0032p1zr2 [ 2
] + l0032p1zr2 [ 6 ] ; localB -> pn1wflw3mf = l0032p1zr2 [ 5 ] + l0032p1zr2 [
7 ] ; localB -> n4krmw2qiz = l0032p1zr2 [ 3 ] - l0032p1zr2 [ 1 ] ; if (
localB -> evi5rjpxuf != 0.0 ) { localB -> ldrfftskgt [ 0 ] = localB ->
bkgtthdcav ; localB -> ldrfftskgt [ 1 ] = localB -> evi5rjpxuf ; } else {
localB -> ldrfftskgt [ 0 ] = localB -> huvluiagis [ 0 ] ; localB ->
ldrfftskgt [ 1 ] = localB -> huvluiagis [ 1 ] ; } localB -> iogvcotbpx =
localB -> ldrfftskgt [ 0 ] / localB -> ldrfftskgt [ 1 ] ; localB ->
hwww3ntia3 [ 0 ] = localB -> b0ys550alf * localB -> iogvcotbpx ; localB ->
hwww3ntia3 [ 1 ] = localB -> pn1wflw3mf * localB -> iogvcotbpx ; localB ->
hwww3ntia3 [ 2 ] = localB -> n4krmw2qiz * localB -> iogvcotbpx ; * lerqs0qiln
= localP -> P_11 * localB -> hwww3ntia3 [ 0 ] ; * hh3qhyha0i = localP -> P_12
* localB -> hwww3ntia3 [ 1 ] ; * b4ei5neduy = localP -> P_13 * localB ->
hwww3ntia3 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW ->
f1ylvmwak5 ) ; } break ; case 2 : localB -> c3m5zirlu5 = ( ( l0032p1zr2 [ 0 ]
- l0032p1zr2 [ 4 ] ) - l0032p1zr2 [ 8 ] ) + localB -> beeccavelh ; localB ->
htdl4enqga = muDoubleScalarSqrt ( localB -> c3m5zirlu5 ) ; * lerqs0qiln =
localP -> P_15 * localB -> htdl4enqga ; if ( localB -> htdl4enqga != 0.0 ) {
localB -> fpdrc4u3hv [ 0 ] = localB -> dgprsmy315 ; localB -> fpdrc4u3hv [ 1
] = localB -> htdl4enqga ; } else { localB -> fpdrc4u3hv [ 0 ] = localB ->
k4uz4oonkc [ 0 ] ; localB -> fpdrc4u3hv [ 1 ] = localB -> k4uz4oonkc [ 1 ] ;
} localB -> hd2ru33xnv = localB -> fpdrc4u3hv [ 0 ] / localB -> fpdrc4u3hv [
1 ] ; localB -> issoc5y23s = l0032p1zr2 [ 1 ] + l0032p1zr2 [ 3 ] ; localB ->
kuinqipxly = l0032p1zr2 [ 2 ] + l0032p1zr2 [ 6 ] ; localB -> hnq0pt0f5k =
l0032p1zr2 [ 7 ] - l0032p1zr2 [ 5 ] ; localB -> d02wbbqoz2 [ 0 ] = localB ->
hd2ru33xnv * localB -> issoc5y23s ; localB -> d02wbbqoz2 [ 1 ] = localB ->
hd2ru33xnv * localB -> kuinqipxly ; localB -> d02wbbqoz2 [ 2 ] = localB ->
hd2ru33xnv * localB -> hnq0pt0f5k ; * hh3qhyha0i = localP -> P_18 * localB ->
d02wbbqoz2 [ 0 ] ; * n4p4av1cij = localP -> P_19 * localB -> d02wbbqoz2 [ 1 ]
; * b4ei5neduy = localP -> P_20 * localB -> d02wbbqoz2 [ 2 ] ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( localDW -> ldmwtzjyu0 ) ; } break ;
} } void iorhdpdmaiTID2 ( gritqy5sso * localB , dcmchj0dqy * localP ) {
localB -> dpvym2mupn = localP -> P_0 ; localB -> d4rw5s2nwv = localP -> P_2 ;
localB -> leihpkmh4s = localP -> P_7 ; localB -> bkgtthdcav = localP -> P_9 ;
localB -> beeccavelh = localP -> P_14 ; localB -> dgprsmy315 = localP -> P_16
; localB -> e0mys1kfvr [ 0 ] = localP -> P_3 [ 0 ] ; localB -> huvluiagis [ 0
] = localP -> P_10 [ 0 ] ; localB -> k4uz4oonkc [ 0 ] = localP -> P_17 [ 0 ]
; localB -> e0mys1kfvr [ 1 ] = localP -> P_3 [ 1 ] ; localB -> huvluiagis [ 1
] = localP -> P_10 [ 1 ] ; localB -> k4uz4oonkc [ 1 ] = localP -> P_17 [ 1 ]
; } void h2w1vftlsh ( SimStruct * const S ) { } static void dffiw3rk3b (
const real_T u0 [ 3 ] , const real_T u1 [ 9 ] , real_T y [ 3 ] ) { static
real_T A [ 9 ] ; int32_T r1 ; int32_T r2 ; int32_T r3 ; real_T maxval ;
real_T a21 ; int32_T rtemp ; memcpy ( & A [ 0 ] , & u1 [ 0 ] , 9U * sizeof (
real_T ) ) ; r1 = 1 ; r2 = 2 ; r3 = 3 ; maxval = muDoubleScalarAbs ( u1 [ 0 ]
) ; a21 = muDoubleScalarAbs ( u1 [ 1 ] ) ; if ( a21 > maxval ) { maxval = a21
; r1 = 2 ; r2 = 1 ; } if ( muDoubleScalarAbs ( u1 [ 2 ] ) > maxval ) { r1 = 3
; r2 = 2 ; r3 = 1 ; } A [ r2 - 1 ] = u1 [ r2 - 1 ] / u1 [ r1 - 1 ] ; A [ r3 -
1 ] /= A [ r1 - 1 ] ; A [ r2 + 2 ] -= A [ r2 - 1 ] * A [ r1 + 2 ] ; A [ r3 +
2 ] -= A [ r3 - 1 ] * A [ r1 + 2 ] ; A [ r2 + 5 ] -= A [ r2 - 1 ] * A [ r1 +
5 ] ; A [ r3 + 5 ] -= A [ r3 - 1 ] * A [ r1 + 5 ] ; if ( muDoubleScalarAbs (
A [ r3 + 2 ] ) > muDoubleScalarAbs ( A [ r2 + 2 ] ) ) { rtemp = r2 ; r2 = r3
; r3 = rtemp ; } A [ r3 + 2 ] /= A [ r2 + 2 ] ; A [ r3 + 5 ] -= A [ r3 + 2 ]
* A [ r2 + 5 ] ; y [ r1 - 1 ] = u0 [ 0 ] / A [ r1 - 1 ] ; y [ r2 - 1 ] = u0 [
1 ] - y [ r1 - 1 ] * A [ r1 + 2 ] ; y [ r3 - 1 ] = u0 [ 2 ] - y [ r1 - 1 ] *
A [ r1 + 5 ] ; y [ r2 - 1 ] /= A [ r2 + 2 ] ; y [ r3 - 1 ] -= y [ r2 - 1 ] *
A [ r2 + 5 ] ; y [ r3 - 1 ] /= A [ r3 + 5 ] ; y [ r2 - 1 ] -= y [ r3 - 1 ] *
A [ r3 + 2 ] ; y [ r1 - 1 ] -= y [ r3 - 1 ] * A [ r3 - 1 ] ; y [ r1 - 1 ] -=
y [ r2 - 1 ] * A [ r2 - 1 ] ; } static void mdlOutputs ( SimStruct * S ,
int_T tid ) { static real_T deltaT ; boolean_T resetIntg ; boolean_T
didZcEventOccur ; int8_T rtPrevAction ; int8_T rtAction ; int32_T i ; static
real_T tmp [ 6 ] ; static real_T tmp_p [ 6 ] ; int32_T i_p ; static real_T
tmp_e [ 9 ] ; static real_T tmpForInput ; real32_T u0 ; real_T tmp_i ;
plshtxiahf * _rtB ; cvqdcwnzy0 * _rtP ; aneejwrild * _rtX ; ouvcaqvmj2 *
_rtZCE ; f5cp4dpc1i * _rtDW ; _rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S )
) ; _rtZCE = ( ( ouvcaqvmj2 * ) _ssGetPrevZCSigState ( S ) ) ; _rtX = ( (
aneejwrild * ) ssGetContStates ( S ) ) ; _rtP = ( ( cvqdcwnzy0 * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 71 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; for ( i = 0 ; i < 30 ; i ++ ) { _rtB -> msufdkx32m [
i ] = ( real32_T ) _rtB -> ipnmhbxs0d [ i ] ; } _rtB -> oucmybi2ax = _rtP ->
P_1471 ; _rtB -> bprf4bfsvn = _rtP -> P_1472 ; ssCallAccelRunBlock ( S , 78 ,
0 , SS_CALL_MDL_OUTPUTS ) ; } if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_1074 )
{ _rtB -> c3muk1ao42 = _rtP -> P_1075 ; } else { _rtB -> c3muk1ao42 = _rtP ->
P_1076 ; } _rtB -> kxcbuvrjnx = ( _rtB -> c3muk1ao42 == _rtB -> ogdl4kpko1 )
; _rtB -> eg2ximy4us = _rtB -> kxcbuvrjnx ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> lhgoxpxfln = _rtDW -> e4nz3golqn ; _rtB -> oqanlu0td4 = _rtDW ->
l1klrgmmsl ; _rtB -> mqzov20rea = _rtDW -> ntf50l3qxv ; _rtB -> mzcsggjwrc =
_rtDW -> geqmfi3fte ; _rtB -> n4mseb0piq = _rtDW -> ahjrt4ebav ; _rtB ->
ooaevbajgd = _rtDW -> gecxa4qcyy ; _rtB -> lk4r5fbhoa = _rtDW -> n2wcftxdjs ;
_rtB -> lcrkc130bq = _rtP -> P_1078 ; _rtB -> jgdhwvawjr = _rtP -> P_1079 ;
_rtB -> fknoahnqog = _rtP -> P_1080 ; _rtB -> mvho1khbe4 = ( real32_T ) _rtB
-> fknoahnqog ; _rtB -> bcfbrd2j5f = _rtP -> P_1081 * _rtB -> c4btga4s0w ;
_rtB -> eqyt0iwzwj = ( real32_T ) _rtB -> bcfbrd2j5f ; _rtB -> msdfnt4hdd =
_rtP -> P_1480 ; _rtB -> ofxsalui2x = _rtP -> P_1459 * _rtB -> mqzov20rea ;
_rtB -> mkckazuxl2 = _rtP -> P_1460 ; _rtB -> eenu45zys4 = _rtP -> P_1461 ;
_rtB -> muc01j2m4u = _rtP -> P_1462 ; _rtB -> a343gcpn1q = _rtP -> P_1463 ;
_rtB -> g2fi3apc30 = _rtP -> P_1464 ; _rtB -> pkmm4ersy2 = _rtP -> P_1465 ;
_rtB -> h4su0kqgyf = _rtP -> P_1466 ; _rtB -> nsydkznnvb = _rtP -> P_1467 ;
_rtB -> fx52ufb4dv = _rtP -> P_1468 ; _rtB -> dfmfozch3l = _rtP -> P_1469 ; }
if ( _rtB -> eg2ximy4us > _rtP -> P_1912 ) { _rtB -> jxphnvyw2u [ 0 ] = _rtB
-> lhgoxpxfln ; _rtB -> jxphnvyw2u [ 1 ] = _rtB -> oqanlu0td4 ; _rtB ->
jxphnvyw2u [ 2 ] = _rtB -> oqanlu0td4 ; _rtB -> jxphnvyw2u [ 3 ] = _rtB ->
mqzov20rea ; _rtB -> jxphnvyw2u [ 4 ] = _rtB -> ofxsalui2x ; _rtB ->
jxphnvyw2u [ 5 ] = _rtB -> mzcsggjwrc ; _rtB -> jxphnvyw2u [ 6 ] = _rtB ->
n4mseb0piq ; _rtB -> jxphnvyw2u [ 7 ] = _rtB -> ooaevbajgd ; _rtB ->
jxphnvyw2u [ 8 ] = _rtB -> lk4r5fbhoa ; _rtB -> jxphnvyw2u [ 9 ] = _rtB ->
lk4r5fbhoa ; } else { _rtB -> jxphnvyw2u [ 0 ] = _rtB -> mkckazuxl2 ; _rtB ->
jxphnvyw2u [ 1 ] = _rtB -> eenu45zys4 ; _rtB -> jxphnvyw2u [ 2 ] = _rtB ->
muc01j2m4u ; _rtB -> jxphnvyw2u [ 3 ] = _rtB -> a343gcpn1q ; _rtB ->
jxphnvyw2u [ 4 ] = _rtB -> g2fi3apc30 ; _rtB -> jxphnvyw2u [ 5 ] = _rtB ->
pkmm4ersy2 ; _rtB -> jxphnvyw2u [ 6 ] = _rtB -> h4su0kqgyf ; _rtB ->
jxphnvyw2u [ 7 ] = _rtB -> nsydkznnvb ; _rtB -> jxphnvyw2u [ 8 ] = _rtB ->
fx52ufb4dv ; _rtB -> jxphnvyw2u [ 9 ] = _rtB -> dfmfozch3l ; } for ( i = 0 ;
i < 10 ; i ++ ) { _rtB -> mc2nkfth2u [ i ] = _rtB -> jxphnvyw2u [ i ] ; }
_rtB -> ltstddoqxm = ( _rtB -> eg2ximy4us == _rtB -> iharqyqpn5 ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> dawz0edar2 = _rtP -> P_1043 ; _rtB ->
o50y3uxkfb = _rtP -> P_1044 ; _rtB -> ksbb1ztybt = _rtB -> eqyt0iwzwj ; _rtB
-> khmwcojnzo = _rtP -> P_1045 * _rtB -> ksbb1ztybt ; _rtB -> gy3bwl1ls4 =
_rtP -> P_1046 * _rtB -> lcrkc130bq ; _rtB -> kw5mnvlloi = _rtP -> P_1047 *
_rtB -> jgdhwvawjr ; _rtB -> bxtndmgqmx = ( real_T ) _rtP -> P_1470 * _rtB ->
mvho1khbe4 ; _rtB -> n0y1zxxh2i [ 0 ] = _rtP -> P_1042 [ 0 ] ; _rtB ->
jeetl5x0nz [ 0 ] = _rtP -> P_1048 [ 0 ] ; _rtB -> n0y1zxxh2i [ 1 ] = _rtP ->
P_1042 [ 1 ] ; _rtB -> jeetl5x0nz [ 1 ] = _rtP -> P_1048 [ 1 ] ; _rtB ->
n0y1zxxh2i [ 2 ] = _rtP -> P_1042 [ 2 ] ; _rtB -> jeetl5x0nz [ 2 ] = _rtP ->
P_1048 [ 2 ] ; _rtB -> hdvi031ysj = _rtB -> msdfnt4hdd ; if (
ssIsMajorTimeStep ( S ) ) { if ( _rtB -> ltstddoqxm ) { if ( ! _rtDW ->
h1triskzhg ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S , 119 , 0 ,
SS_CALL_RTW_GENERATED_ENABLE ) ; ssCallAccelRunBlock ( S , 118 , 0 ,
SS_CALL_RTW_GENERATED_ENABLE ) ; ssCallAccelRunBlock ( S , 134 , 0 ,
SS_CALL_RTW_GENERATED_ENABLE ) ; _rtDW -> h1triskzhg = true ; } } else { if (
_rtDW -> h1triskzhg ) { ssSetSolverNeedsReset ( S ) ; _rtDW -> ndgq5lx0fn = -
1 ; ssCallAccelRunBlock ( S , 119 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ;
_rtDW -> onk41eqc3n = - 1 ; d0gn4nvn3e ( & _rtB -> lvrrs02dbel , & _rtDW ->
lvrrs02dbel , ( dbjdkpcxft * ) & _rtP -> lvrrs02dbel ) ; igndwt035f ( & _rtB
-> dak2bbvhdyl , & _rtDW -> dak2bbvhdyl , ( fgfesxh13p * ) & _rtP ->
dak2bbvhdyl ) ; lcmgrp0nqt ( & _rtB -> b1bttejwsj2 , & _rtDW -> b1bttejwsj2 ,
( fvjsblhu4h * ) & _rtP -> b1bttejwsj2 ) ; ssCallAccelRunBlock ( S , 118 , 0
, SS_CALL_RTW_GENERATED_DISABLE ) ; ssCallAccelRunBlock ( S , 134 , 0 ,
SS_CALL_RTW_GENERATED_DISABLE ) ; _rtDW -> e24fv5u4gg = - 1 ; _rtDW ->
h1triskzhg = false ; } } } } if ( _rtDW -> h1triskzhg ) { _rtB -> gqjd5msyxd
= 0.0 ; _rtB -> gqjd5msyxd += _rtP -> P_88 * _rtX -> g2szyo42jj ; _rtB ->
bq3enfnjje = _rtP -> P_89 * _rtB -> gqjd5msyxd ; _rtB -> monv2s5ujm = _rtP ->
P_90 * _rtB -> gqjd5msyxd ; _rtB -> nc1h1p03kh = _rtP -> P_91 * _rtB ->
mc2nkfth2u [ 8 ] ; _rtB -> jk01hhkdro = _rtP -> P_92 * _rtB -> mc2nkfth2u [ 9
] ; _rtB -> fooruvuylr = _rtX -> fn5nnjex4j ; _rtB -> bz3z4mlry4 = _rtP ->
P_94 * _rtB -> fooruvuylr ; if ( _rtB -> mc2nkfth2u [ 1 ] > _rtP -> P_95 ) {
_rtB -> ixl0yoqjuq = _rtP -> P_95 ; } else if ( _rtB -> mc2nkfth2u [ 1 ] <
_rtP -> P_96 ) { _rtB -> ixl0yoqjuq = _rtP -> P_96 ; } else { _rtB ->
ixl0yoqjuq = _rtB -> mc2nkfth2u [ 1 ] ; } if ( _rtX -> gupqkdacwq >= _rtP ->
P_98 ) { if ( _rtX -> gupqkdacwq != _rtP -> P_98 ) { _rtX -> gupqkdacwq =
_rtP -> P_98 ; ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX ->
gupqkdacwq <= _rtP -> P_99 ) && ( _rtX -> gupqkdacwq != _rtP -> P_99 ) ) {
_rtX -> gupqkdacwq = _rtP -> P_99 ; ssSetSolverNeedsReset ( S ) ; } } _rtB ->
pren33n0wb = _rtX -> gupqkdacwq ; _rtB -> bdpipyohtj = _rtB -> ixl0yoqjuq -
_rtB -> pren33n0wb ; if ( _rtB -> bdpipyohtj > _rtP -> P_100 ) { _rtB ->
aaf2pxbu10 = _rtP -> P_100 ; } else if ( _rtB -> bdpipyohtj < _rtP -> P_101 )
{ _rtB -> aaf2pxbu10 = _rtP -> P_101 ; } else { _rtB -> aaf2pxbu10 = _rtB ->
bdpipyohtj ; } _rtB -> bdvo4fjiak = _rtP -> P_102 * _rtB -> aaf2pxbu10 ; _rtB
-> evbbqvdcty = _rtB -> bdvo4fjiak - _rtB -> bz3z4mlry4 ; _rtB -> eaupvfytps
= _rtX -> nuv0yyibvo ; _rtB -> oryjcgvdy2 = _rtP -> P_104 * _rtB ->
eaupvfytps ; if ( _rtB -> mc2nkfth2u [ 2 ] > _rtP -> P_105 ) { _rtB ->
hsezvxn54o = _rtP -> P_105 ; } else if ( _rtB -> mc2nkfth2u [ 2 ] < _rtP ->
P_106 ) { _rtB -> hsezvxn54o = _rtP -> P_106 ; } else { _rtB -> hsezvxn54o =
_rtB -> mc2nkfth2u [ 2 ] ; } if ( _rtX -> ddaf4beo1a >= _rtP -> P_108 ) { if
( _rtX -> ddaf4beo1a != _rtP -> P_108 ) { _rtX -> ddaf4beo1a = _rtP -> P_108
; ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> ddaf4beo1a <= _rtP
-> P_109 ) && ( _rtX -> ddaf4beo1a != _rtP -> P_109 ) ) { _rtX -> ddaf4beo1a
= _rtP -> P_109 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> dwu5ylnrjd = _rtX
-> ddaf4beo1a ; _rtB -> mqghddugbb = _rtB -> hsezvxn54o - _rtB -> dwu5ylnrjd
; if ( _rtB -> mqghddugbb > _rtP -> P_110 ) { _rtB -> ec0imakpdt = _rtP ->
P_110 ; } else if ( _rtB -> mqghddugbb < _rtP -> P_111 ) { _rtB -> ec0imakpdt
= _rtP -> P_111 ; } else { _rtB -> ec0imakpdt = _rtB -> mqghddugbb ; } _rtB
-> k2tbm5se0p = _rtP -> P_112 * _rtB -> ec0imakpdt ; _rtB -> bnpw2vxvzw =
_rtB -> k2tbm5se0p - _rtB -> oryjcgvdy2 ; _rtB -> nomatn2fz3 = _rtX ->
m53fvqufyn ; _rtB -> eqe5nmjzdz = _rtP -> P_114 * _rtB -> nomatn2fz3 ; if (
_rtB -> mc2nkfth2u [ 3 ] > _rtP -> P_115 ) { _rtB -> cww4mfj42l = _rtP ->
P_115 ; } else if ( _rtB -> mc2nkfth2u [ 3 ] < _rtP -> P_116 ) { _rtB ->
cww4mfj42l = _rtP -> P_116 ; } else { _rtB -> cww4mfj42l = _rtB -> mc2nkfth2u
[ 3 ] ; } if ( _rtX -> jzz5v30cof >= _rtP -> P_118 ) { if ( _rtX ->
jzz5v30cof != _rtP -> P_118 ) { _rtX -> jzz5v30cof = _rtP -> P_118 ;
ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> jzz5v30cof <= _rtP ->
P_119 ) && ( _rtX -> jzz5v30cof != _rtP -> P_119 ) ) { _rtX -> jzz5v30cof =
_rtP -> P_119 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> df3urf2ol0 = _rtX
-> jzz5v30cof ; _rtB -> hkeefwkgtc = _rtB -> cww4mfj42l - _rtB -> df3urf2ol0
; if ( _rtB -> hkeefwkgtc > _rtP -> P_120 ) { _rtB -> hpt43y5bl0 = _rtP ->
P_120 ; } else if ( _rtB -> hkeefwkgtc < _rtP -> P_121 ) { _rtB -> hpt43y5bl0
= _rtP -> P_121 ; } else { _rtB -> hpt43y5bl0 = _rtB -> hkeefwkgtc ; } _rtB
-> imjzh2awko = _rtP -> P_122 * _rtB -> hpt43y5bl0 ; _rtB -> exwtxdiv0z =
_rtB -> imjzh2awko - _rtB -> eqe5nmjzdz ; _rtB -> crqshwrbtm = _rtX ->
jycafulcqx ; _rtB -> corzmkx002 = _rtP -> P_124 * _rtB -> crqshwrbtm ; if (
_rtB -> mc2nkfth2u [ 4 ] > _rtP -> P_125 ) { _rtB -> pgbeniih1n = _rtP ->
P_125 ; } else if ( _rtB -> mc2nkfth2u [ 4 ] < _rtP -> P_126 ) { _rtB ->
pgbeniih1n = _rtP -> P_126 ; } else { _rtB -> pgbeniih1n = _rtB -> mc2nkfth2u
[ 4 ] ; } if ( _rtX -> d2alyourid >= _rtP -> P_128 ) { if ( _rtX ->
d2alyourid != _rtP -> P_128 ) { _rtX -> d2alyourid = _rtP -> P_128 ;
ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> d2alyourid <= _rtP ->
P_129 ) && ( _rtX -> d2alyourid != _rtP -> P_129 ) ) { _rtX -> d2alyourid =
_rtP -> P_129 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> jz2cmla1ew = _rtX
-> d2alyourid ; _rtB -> o04sjciolg = _rtB -> pgbeniih1n - _rtB -> jz2cmla1ew
; if ( _rtB -> o04sjciolg > _rtP -> P_130 ) { _rtB -> litelujtzq = _rtP ->
P_130 ; } else if ( _rtB -> o04sjciolg < _rtP -> P_131 ) { _rtB -> litelujtzq
= _rtP -> P_131 ; } else { _rtB -> litelujtzq = _rtB -> o04sjciolg ; } _rtB
-> dws00pzhws = _rtP -> P_132 * _rtB -> litelujtzq ; _rtB -> it3qches1x =
_rtB -> dws00pzhws - _rtB -> corzmkx002 ; _rtB -> nxlljkrvr0 = _rtX ->
b4tooowqob ; _rtB -> am1ge4udr2 = _rtP -> P_134 * _rtB -> nxlljkrvr0 ; if (
_rtB -> mc2nkfth2u [ 5 ] > _rtP -> P_135 ) { _rtB -> f1cqnq5cv4 = _rtP ->
P_135 ; } else if ( _rtB -> mc2nkfth2u [ 5 ] < _rtP -> P_136 ) { _rtB ->
f1cqnq5cv4 = _rtP -> P_136 ; } else { _rtB -> f1cqnq5cv4 = _rtB -> mc2nkfth2u
[ 5 ] ; } if ( _rtX -> bo333uqftn >= _rtP -> P_138 ) { if ( _rtX ->
bo333uqftn != _rtP -> P_138 ) { _rtX -> bo333uqftn = _rtP -> P_138 ;
ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> bo333uqftn <= _rtP ->
P_139 ) && ( _rtX -> bo333uqftn != _rtP -> P_139 ) ) { _rtX -> bo333uqftn =
_rtP -> P_139 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> bamumk3b4m = _rtX
-> bo333uqftn ; _rtB -> dbs5et02oe = _rtB -> f1cqnq5cv4 - _rtB -> bamumk3b4m
; if ( _rtB -> dbs5et02oe > _rtP -> P_140 ) { _rtB -> j5p3qn4kn1 = _rtP ->
P_140 ; } else if ( _rtB -> dbs5et02oe < _rtP -> P_141 ) { _rtB -> j5p3qn4kn1
= _rtP -> P_141 ; } else { _rtB -> j5p3qn4kn1 = _rtB -> dbs5et02oe ; } _rtB
-> d1dpfxic1f = _rtP -> P_142 * _rtB -> j5p3qn4kn1 ; _rtB -> nzno4rtdsn =
_rtB -> d1dpfxic1f - _rtB -> am1ge4udr2 ; _rtB -> cnmo42efk1 = _rtX ->
gdpetm5ycb ; _rtB -> hfkfouijko = _rtP -> P_144 * _rtB -> cnmo42efk1 ; if (
_rtB -> mc2nkfth2u [ 6 ] > _rtP -> P_145 ) { _rtB -> kfyph1lbz4 = _rtP ->
P_145 ; } else if ( _rtB -> mc2nkfth2u [ 6 ] < _rtP -> P_146 ) { _rtB ->
kfyph1lbz4 = _rtP -> P_146 ; } else { _rtB -> kfyph1lbz4 = _rtB -> mc2nkfth2u
[ 6 ] ; } if ( _rtX -> oagjyzakjn >= _rtP -> P_148 ) { if ( _rtX ->
oagjyzakjn != _rtP -> P_148 ) { _rtX -> oagjyzakjn = _rtP -> P_148 ;
ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> oagjyzakjn <= _rtP ->
P_149 ) && ( _rtX -> oagjyzakjn != _rtP -> P_149 ) ) { _rtX -> oagjyzakjn =
_rtP -> P_149 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> hjyik2n22h = _rtX
-> oagjyzakjn ; _rtB -> pubqgwonk2 = _rtB -> kfyph1lbz4 - _rtB -> hjyik2n22h
; if ( _rtB -> pubqgwonk2 > _rtP -> P_150 ) { _rtB -> fhbw0gayaa = _rtP ->
P_150 ; } else if ( _rtB -> pubqgwonk2 < _rtP -> P_151 ) { _rtB -> fhbw0gayaa
= _rtP -> P_151 ; } else { _rtB -> fhbw0gayaa = _rtB -> pubqgwonk2 ; } _rtB
-> ccns2yl4vo = _rtP -> P_152 * _rtB -> fhbw0gayaa ; _rtB -> oukkx3ba3k =
_rtB -> ccns2yl4vo - _rtB -> hfkfouijko ; _rtB -> i3tvu1ajhg = _rtX ->
nrnlh3tixw ; _rtB -> magarz4tdm = _rtP -> P_154 * _rtB -> i3tvu1ajhg ; if (
_rtB -> nc1h1p03kh > _rtP -> P_155 ) { _rtB -> o1kzfocvou = _rtP -> P_155 ; }
else if ( _rtB -> nc1h1p03kh < _rtP -> P_156 ) { _rtB -> o1kzfocvou = _rtP ->
P_156 ; } else { _rtB -> o1kzfocvou = _rtB -> nc1h1p03kh ; } if ( _rtX ->
bkhhqiqzcb >= _rtP -> P_158 ) { if ( _rtX -> bkhhqiqzcb != _rtP -> P_158 ) {
_rtX -> bkhhqiqzcb = _rtP -> P_158 ; ssSetSolverNeedsReset ( S ) ; } } else {
if ( ( _rtX -> bkhhqiqzcb <= _rtP -> P_159 ) && ( _rtX -> bkhhqiqzcb != _rtP
-> P_159 ) ) { _rtX -> bkhhqiqzcb = _rtP -> P_159 ; ssSetSolverNeedsReset ( S
) ; } } _rtB -> ahbyuardts = _rtX -> bkhhqiqzcb ; _rtB -> pbb55nxkm5 = _rtB
-> o1kzfocvou - _rtB -> ahbyuardts ; if ( _rtB -> pbb55nxkm5 > _rtP -> P_160
) { _rtB -> he2owfirze = _rtP -> P_160 ; } else if ( _rtB -> pbb55nxkm5 <
_rtP -> P_161 ) { _rtB -> he2owfirze = _rtP -> P_161 ; } else { _rtB ->
he2owfirze = _rtB -> pbb55nxkm5 ; } _rtB -> gpqziiev5v = _rtP -> P_162 * _rtB
-> he2owfirze ; _rtB -> k23gejr2l2 = _rtB -> gpqziiev5v - _rtB -> magarz4tdm
; _rtB -> hta4ebri2p = _rtX -> euz1cekogw ; _rtB -> hqms0y2rlj = _rtP ->
P_164 * _rtB -> hta4ebri2p ; if ( _rtB -> jk01hhkdro > _rtP -> P_165 ) { _rtB
-> egf4ieawvf = _rtP -> P_165 ; } else if ( _rtB -> jk01hhkdro < _rtP ->
P_166 ) { _rtB -> egf4ieawvf = _rtP -> P_166 ; } else { _rtB -> egf4ieawvf =
_rtB -> jk01hhkdro ; } if ( _rtX -> oq3g2uysed >= _rtP -> P_168 ) { if ( _rtX
-> oq3g2uysed != _rtP -> P_168 ) { _rtX -> oq3g2uysed = _rtP -> P_168 ;
ssSetSolverNeedsReset ( S ) ; } } else { if ( ( _rtX -> oq3g2uysed <= _rtP ->
P_169 ) && ( _rtX -> oq3g2uysed != _rtP -> P_169 ) ) { _rtX -> oq3g2uysed =
_rtP -> P_169 ; ssSetSolverNeedsReset ( S ) ; } } _rtB -> p5jnk01qi0 = _rtX
-> oq3g2uysed ; _rtB -> hrhdwggwd5 = _rtB -> egf4ieawvf - _rtB -> p5jnk01qi0
; if ( _rtB -> hrhdwggwd5 > _rtP -> P_170 ) { _rtB -> hf3a0hajcz = _rtP ->
P_170 ; } else if ( _rtB -> hrhdwggwd5 < _rtP -> P_171 ) { _rtB -> hf3a0hajcz
= _rtP -> P_171 ; } else { _rtB -> hf3a0hajcz = _rtB -> hrhdwggwd5 ; } _rtB
-> cjkok4g41t = _rtP -> P_172 * _rtB -> hf3a0hajcz ; _rtB -> mdpmxxqx3t =
_rtB -> cjkok4g41t - _rtB -> hqms0y2rlj ; _rtB -> g1spufntqt [ 0 ] = _rtB ->
khmwcojnzo ; _rtB -> g1spufntqt [ 1 ] = _rtB -> o50y3uxkfb ; _rtB ->
g1spufntqt [ 2 ] = _rtB -> dawz0edar2 ; muDoubleScalarSinCos ( _rtB ->
g1spufntqt [ 0 ] , & _rtB -> g1spufntqt [ 0 ] , & _rtB -> dlzh5xejq2 [ 0 ] )
; muDoubleScalarSinCos ( _rtB -> g1spufntqt [ 1 ] , & _rtB -> g1spufntqt [ 1
] , & _rtB -> dlzh5xejq2 [ 1 ] ) ; muDoubleScalarSinCos ( _rtB -> g1spufntqt
[ 2 ] , & _rtB -> g1spufntqt [ 2 ] , & _rtB -> dlzh5xejq2 [ 2 ] ) ; _rtB ->
axq11ftd4m [ 0 ] = _rtB -> dlzh5xejq2 [ 1 ] * _rtB -> dlzh5xejq2 [ 0 ] ; _rtB
-> axq11ftd4m [ 1 ] = _rtB -> g1spufntqt [ 2 ] * _rtB -> g1spufntqt [ 1 ] *
_rtB -> dlzh5xejq2 [ 0 ] - _rtB -> dlzh5xejq2 [ 2 ] * _rtB -> g1spufntqt [ 0
] ; _rtB -> axq11ftd4m [ 2 ] = _rtB -> dlzh5xejq2 [ 2 ] * _rtB -> g1spufntqt
[ 1 ] * _rtB -> dlzh5xejq2 [ 0 ] + _rtB -> g1spufntqt [ 2 ] * _rtB ->
g1spufntqt [ 0 ] ; _rtB -> axq11ftd4m [ 3 ] = _rtB -> dlzh5xejq2 [ 1 ] * _rtB
-> g1spufntqt [ 0 ] ; _rtB -> axq11ftd4m [ 4 ] = _rtB -> g1spufntqt [ 2 ] *
_rtB -> g1spufntqt [ 1 ] * _rtB -> g1spufntqt [ 0 ] + _rtB -> dlzh5xejq2 [ 2
] * _rtB -> dlzh5xejq2 [ 0 ] ; _rtB -> axq11ftd4m [ 5 ] = _rtB -> dlzh5xejq2
[ 2 ] * _rtB -> g1spufntqt [ 1 ] * _rtB -> g1spufntqt [ 0 ] - _rtB ->
g1spufntqt [ 2 ] * _rtB -> dlzh5xejq2 [ 0 ] ; _rtB -> axq11ftd4m [ 6 ] = -
_rtB -> g1spufntqt [ 1 ] ; _rtB -> axq11ftd4m [ 7 ] = _rtB -> g1spufntqt [ 2
] * _rtB -> dlzh5xejq2 [ 1 ] ; _rtB -> axq11ftd4m [ 8 ] = _rtB -> dlzh5xejq2
[ 2 ] * _rtB -> dlzh5xejq2 [ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> f1hqbtagcy [ 0 ] = _rtP -> P_175 * _rtB -> gy3bwl1ls4 ; _rtB -> f1hqbtagcy
[ 1 ] = _rtP -> P_175 * _rtB -> kw5mnvlloi ; muDoubleScalarSinCos ( _rtB ->
f1hqbtagcy [ 0 ] , & _rtB -> fbqr4cnphj [ 0 ] , & _rtB -> mkxvhhlafy [ 0 ] )
; muDoubleScalarSinCos ( _rtB -> f1hqbtagcy [ 1 ] , & _rtB -> fbqr4cnphj [ 1
] , & _rtB -> mkxvhhlafy [ 1 ] ) ; _rtB -> gzxpxxi4gl = _rtB -> fbqr4cnphj [
0 ] * _rtB -> mkxvhhlafy [ 1 ] ; _rtB -> ea5bzw1w4q [ 0 ] = - _rtB ->
gzxpxxi4gl ; _rtB -> ea5bzw1w4q [ 1 ] = - _rtB -> fbqr4cnphj [ 1 ] ; _rtB ->
capr4ekmlz = _rtB -> mkxvhhlafy [ 0 ] * _rtB -> mkxvhhlafy [ 1 ] ; _rtB ->
ea5bzw1w4q [ 2 ] = - _rtB -> capr4ekmlz ; _rtB -> cdbdgwxuc0 = _rtB ->
fbqr4cnphj [ 0 ] * _rtB -> fbqr4cnphj [ 1 ] ; _rtB -> ea5bzw1w4q [ 3 ] = -
_rtB -> cdbdgwxuc0 ; _rtB -> ea5bzw1w4q [ 4 ] = _rtB -> mkxvhhlafy [ 1 ] ;
_rtB -> mzwsn1fxrt = _rtB -> fbqr4cnphj [ 1 ] * _rtB -> mkxvhhlafy [ 0 ] ;
_rtB -> ea5bzw1w4q [ 5 ] = - _rtB -> mzwsn1fxrt ; _rtB -> ea5bzw1w4q [ 6 ] =
_rtB -> mkxvhhlafy [ 0 ] ; _rtB -> ea5bzw1w4q [ 7 ] = _rtB -> j21wvbjuhs ;
_rtB -> ea5bzw1w4q [ 8 ] = - _rtB -> fbqr4cnphj [ 0 ] ; } for ( i = 0 ; i < 3
; i ++ ) { for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { _rtB -> aapt0tqbb3 [ i + 3 *
i_p ] = 0.0 ; _rtB -> aapt0tqbb3 [ i + 3 * i_p ] += _rtB -> ea5bzw1w4q [ 3 *
i_p ] * _rtB -> axq11ftd4m [ i ] ; _rtB -> aapt0tqbb3 [ i + 3 * i_p ] += _rtB
-> ea5bzw1w4q [ 3 * i_p + 1 ] * _rtB -> axq11ftd4m [ i + 3 ] ; _rtB ->
aapt0tqbb3 [ i + 3 * i_p ] += _rtB -> ea5bzw1w4q [ 3 * i_p + 2 ] * _rtB ->
axq11ftd4m [ i + 6 ] ; } } _rtB -> jupye1gp2b = ( _rtB -> aapt0tqbb3 [ 0 ] +
_rtB -> aapt0tqbb3 [ 4 ] ) + _rtB -> aapt0tqbb3 [ 8 ] ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> jupye1gp2b >
0.0 ) ; _rtDW -> ndgq5lx0fn = rtAction ; } else { rtAction = _rtDW ->
ndgq5lx0fn ; } switch ( rtAction ) { case 0 : h3v44pg0kk ( _rtB -> jupye1gp2b
, _rtB -> aapt0tqbb3 , & _rtB -> baamqksgfh [ 0 ] , & _rtB -> baamqksgfh [ 1
] , & _rtB -> h3v44pg0kkk , ( grglhn4pya * ) & _rtP -> h3v44pg0kkk ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> h3v44pg0kkk . gqlhiezdbu )
; } break ; case 1 : iorhdpdmai ( S , _rtB -> aapt0tqbb3 , & _rtB ->
baamqksgfh [ 0 ] , & _rtB -> baamqksgfh [ 1 ] , & _rtB -> baamqksgfh [ 2 ] ,
& _rtB -> baamqksgfh [ 3 ] , & _rtB -> iorhdpdmaie , & _rtDW -> iorhdpdmaie ,
( dcmchj0dqy * ) & _rtP -> iorhdpdmaie ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> iorhdpdmaie . jjqsphygwt ) ; } break ; } if ( _rtDW ->
grymb5dts4 != 0 ) { _rtX -> hu4sqeqyp2 [ 0 ] = _rtB -> baamqksgfh [ 0 ] ;
_rtX -> hu4sqeqyp2 [ 1 ] = _rtB -> baamqksgfh [ 1 ] ; _rtX -> hu4sqeqyp2 [ 2
] = _rtB -> baamqksgfh [ 2 ] ; _rtX -> hu4sqeqyp2 [ 3 ] = _rtB -> baamqksgfh
[ 3 ] ; } _rtB -> ov1ecifwqz [ 0 ] = _rtX -> hu4sqeqyp2 [ 0 ] ; _rtB ->
ov1ecifwqz [ 1 ] = _rtX -> hu4sqeqyp2 [ 1 ] ; _rtB -> ov1ecifwqz [ 2 ] = _rtX
-> hu4sqeqyp2 [ 2 ] ; _rtB -> ov1ecifwqz [ 3 ] = _rtX -> hu4sqeqyp2 [ 3 ] ;
_rtB -> nzieep33t3 = _rtB -> ov1ecifwqz [ 0 ] * _rtB -> ov1ecifwqz [ 0 ] ;
_rtB -> hvf4bcuhup = _rtB -> ov1ecifwqz [ 1 ] * _rtB -> ov1ecifwqz [ 1 ] ;
_rtB -> fpibqsmv3j = _rtB -> ov1ecifwqz [ 2 ] * _rtB -> ov1ecifwqz [ 2 ] ;
_rtB -> eik232kmiy = _rtB -> ov1ecifwqz [ 3 ] * _rtB -> ov1ecifwqz [ 3 ] ;
_rtB -> f2dhzuxxzo = ( ( _rtB -> nzieep33t3 + _rtB -> hvf4bcuhup ) + _rtB ->
fpibqsmv3j ) + _rtB -> eik232kmiy ; _rtB -> dszwdhctjl = muDoubleScalarSqrt (
_rtB -> f2dhzuxxzo ) ; _rtB -> kxedwzwf3f = _rtB -> ov1ecifwqz [ 0 ] / _rtB
-> dszwdhctjl ; _rtB -> c3thyqa1ne = _rtB -> kxedwzwf3f * _rtB -> kxedwzwf3f
; _rtB -> not1auplxo = _rtB -> ov1ecifwqz [ 1 ] / _rtB -> dszwdhctjl ; _rtB
-> joksc0l53a = _rtB -> not1auplxo * _rtB -> not1auplxo ; _rtB -> pvuvd24mbi
= _rtB -> ov1ecifwqz [ 2 ] / _rtB -> dszwdhctjl ; _rtB -> gyxjocyjd0 = _rtB
-> pvuvd24mbi * _rtB -> pvuvd24mbi ; _rtB -> o0iymoscjl = _rtB -> ov1ecifwqz
[ 3 ] / _rtB -> dszwdhctjl ; _rtB -> eiex1vfzgv = _rtB -> o0iymoscjl * _rtB
-> o0iymoscjl ; _rtB -> df0qunjvqj [ 0 ] = ( ( _rtB -> c3thyqa1ne + _rtB ->
joksc0l53a ) - _rtB -> gyxjocyjd0 ) - _rtB -> eiex1vfzgv ; _rtB -> i4hyhtluty
= _rtB -> o0iymoscjl * _rtB -> kxedwzwf3f ; _rtB -> eemervz2ad = _rtB ->
not1auplxo * _rtB -> pvuvd24mbi ; _rtB -> leit4ww2ln = _rtB -> eemervz2ad -
_rtB -> i4hyhtluty ; _rtB -> df0qunjvqj [ 1 ] = _rtP -> P_178 * _rtB ->
leit4ww2ln ; _rtB -> nhxkxzcaki = _rtB -> kxedwzwf3f * _rtB -> pvuvd24mbi ;
_rtB -> mybvaysk4h = _rtB -> not1auplxo * _rtB -> o0iymoscjl ; _rtB ->
fdgtmdyyc5 = _rtB -> nhxkxzcaki + _rtB -> mybvaysk4h ; _rtB -> df0qunjvqj [ 2
] = _rtP -> P_179 * _rtB -> fdgtmdyyc5 ; _rtB -> cgjhmfy0zl = _rtB ->
o0iymoscjl * _rtB -> kxedwzwf3f ; _rtB -> fhbyrqjxsd = _rtB -> not1auplxo *
_rtB -> pvuvd24mbi ; _rtB -> oqufgsmftt = _rtB -> cgjhmfy0zl + _rtB ->
fhbyrqjxsd ; _rtB -> df0qunjvqj [ 3 ] = _rtP -> P_180 * _rtB -> oqufgsmftt ;
_rtB -> ccb0q4ur5l = _rtB -> kxedwzwf3f * _rtB -> kxedwzwf3f ; _rtB ->
oit251rk0h = _rtB -> not1auplxo * _rtB -> not1auplxo ; _rtB -> hjnn1gvz5f =
_rtB -> pvuvd24mbi * _rtB -> pvuvd24mbi ; _rtB -> eqjyjplqip = _rtB ->
o0iymoscjl * _rtB -> o0iymoscjl ; _rtB -> df0qunjvqj [ 4 ] = ( ( _rtB ->
ccb0q4ur5l - _rtB -> oit251rk0h ) + _rtB -> hjnn1gvz5f ) - _rtB -> eqjyjplqip
; _rtB -> d0vjl5hbgj = _rtB -> kxedwzwf3f * _rtB -> not1auplxo ; _rtB ->
i1v1sjppqq = _rtB -> pvuvd24mbi * _rtB -> o0iymoscjl ; _rtB -> lpmhtbyrto =
_rtB -> i1v1sjppqq - _rtB -> d0vjl5hbgj ; _rtB -> df0qunjvqj [ 5 ] = _rtP ->
P_181 * _rtB -> lpmhtbyrto ; _rtB -> fzxcrx4nnc = _rtB -> kxedwzwf3f * _rtB
-> pvuvd24mbi ; _rtB -> chq1pvcfrr = _rtB -> not1auplxo * _rtB -> o0iymoscjl
; _rtB -> ikmbxpblbp = _rtB -> chq1pvcfrr - _rtB -> fzxcrx4nnc ; _rtB ->
df0qunjvqj [ 6 ] = _rtP -> P_182 * _rtB -> ikmbxpblbp ; _rtB -> ema3crmfui =
_rtB -> kxedwzwf3f * _rtB -> not1auplxo ; _rtB -> i1fjb5ra2x = _rtB ->
pvuvd24mbi * _rtB -> o0iymoscjl ; _rtB -> joktnhsxyh = _rtB -> ema3crmfui +
_rtB -> i1fjb5ra2x ; _rtB -> df0qunjvqj [ 7 ] = _rtP -> P_183 * _rtB ->
joktnhsxyh ; _rtB -> ivv4vmh5le = _rtB -> kxedwzwf3f * _rtB -> kxedwzwf3f ;
_rtB -> guwvxhzcc5 = _rtB -> not1auplxo * _rtB -> not1auplxo ; _rtB ->
eaercj3mql = _rtB -> pvuvd24mbi * _rtB -> pvuvd24mbi ; _rtB -> k4uowxbjqb =
_rtB -> o0iymoscjl * _rtB -> o0iymoscjl ; _rtB -> df0qunjvqj [ 8 ] = ( ( _rtB
-> ivv4vmh5le - _rtB -> guwvxhzcc5 ) - _rtB -> eaercj3mql ) + _rtB ->
k4uowxbjqb ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> er3ncsjdzf =
muDoubleScalarAbs ( _rtB -> gy3bwl1ls4 ) ; _rtB -> hovrqu2ecr = ( _rtB ->
er3ncsjdzf > _rtB -> j32kvcqopf ) ; if ( _rtB -> hovrqu2ecr ) { _rtB ->
n2dalswsoq = _rtB -> gy3bwl1ls4 + _rtP -> P_81 ; _rtB -> fmicqie4yd =
muDoubleScalarMod ( _rtB -> n2dalswsoq , _rtB -> myq3xki5s1 ) ; _rtB ->
kn45pqlfy2 = _rtB -> fmicqie4yd + _rtP -> P_82 ; _rtB -> hy2sv5lo5u = _rtB ->
kn45pqlfy2 ; } else { _rtB -> hy2sv5lo5u = _rtB -> gy3bwl1ls4 ; } _rtB ->
btd05f2wnw = muDoubleScalarAbs ( _rtB -> hy2sv5lo5u ) ; _rtB -> djd4bpuyg3 =
( _rtB -> btd05f2wnw > _rtB -> mu5crbu440 ) ; if ( _rtB -> djd4bpuyg3 ) {
_rtB -> celrv4xymw = _rtB -> btd05f2wnw + _rtP -> P_78 ; _rtB -> df2phqc1oq =
_rtP -> P_79 * _rtB -> celrv4xymw ; _rtB -> pp03ssfg1q = _rtB -> df2phqc1oq +
_rtP -> P_80 ; _rtB -> pezkb5f1ck = muDoubleScalarSign ( _rtB -> hy2sv5lo5u )
; _rtB -> iuutqupyh2 = _rtB -> pezkb5f1ck * _rtB -> pp03ssfg1q ; _rtB ->
jpi32wqgtj = _rtB -> iuutqupyh2 ; } else { _rtB -> jpi32wqgtj = _rtB ->
hy2sv5lo5u ; } _rtB -> ng1ofeomkr = _rtP -> P_188 * _rtB -> jpi32wqgtj ;
muDoubleScalarSinCos ( _rtB -> ng1ofeomkr , & _rtB -> gasafot1ih , & _rtB ->
gimtz0crbb ) ; _rtB -> fe2ysjp5dp [ 0 ] = _rtB -> itiwdm0sot * _rtB ->
gasafot1ih ; _rtB -> fe2ysjp5dp [ 1 ] = _rtB -> itiwdm0sot * _rtB ->
gimtz0crbb ; _rtB -> jg00tk0ikl = muDoubleScalarTan ( _rtB -> ng1ofeomkr ) ;
_rtB -> ngdxe4quer = _rtB -> jg00tk0ikl * _rtB -> pyeny3b2wi * _rtB ->
pyeny3b2wi ; _rtB -> jobicwevzf = muDoubleScalarAtan2 ( _rtB -> ngdxe4quer ,
_rtB -> glffycbenh ) ; _rtB -> mnrtlxuvqk = _rtP -> P_193 * _rtB ->
jobicwevzf ; _rtB -> bzxoqft1yq = _rtP -> P_194 * _rtB -> mnrtlxuvqk ; _rtB
-> o0fssy5v2z = muDoubleScalarSin ( _rtB -> bzxoqft1yq ) ; _rtB -> iw05xaj1xl
= _rtB -> o0fssy5v2z * _rtB -> o0fssy5v2z * _rtB -> emysekmysw ; _rtB ->
otgokluddz = _rtB -> cbg5ujvbm0 + _rtB -> iw05xaj1xl ; _rtB -> hhjtranlfw =
_rtB -> or0oiotfsp * _rtB -> or0oiotfsp / _rtB -> otgokluddz ; _rtB ->
b4ewqj5yak = muDoubleScalarSqrt ( _rtB -> hhjtranlfw ) ; muDoubleScalarSinCos
( _rtB -> jobicwevzf , & _rtB -> meoky1l0nj , & _rtB -> ni50gildml ) ; _rtB
-> jc3yt5btlw [ 0 ] = _rtB -> b4ewqj5yak * _rtB -> meoky1l0nj ; _rtB ->
jc3yt5btlw [ 1 ] = _rtB -> b4ewqj5yak * _rtB -> ni50gildml ; _rtB ->
f411pbziai [ 0 ] = _rtB -> fe2ysjp5dp [ 0 ] + _rtB -> jc3yt5btlw [ 0 ] ; _rtB
-> f411pbziai [ 1 ] = _rtB -> fe2ysjp5dp [ 1 ] + _rtB -> jc3yt5btlw [ 1 ] ;
_rtB -> bdwpvfvhzn = muDoubleScalarAtan2 ( _rtB -> f411pbziai [ 0 ] , _rtB ->
f411pbziai [ 1 ] ) ; _rtB -> hdpbxdutmm = _rtP -> P_196 * _rtB -> bdwpvfvhzn
; if ( _rtB -> djd4bpuyg3 ) { _rtB -> cieec2r0pb = _rtB -> lbmoyxwvid ; }
else { _rtB -> cieec2r0pb = _rtB -> lhosvxn3ui ; } _rtB -> l2xptt0ct0 = _rtB
-> cieec2r0pb + _rtB -> kw5mnvlloi ; _rtB -> lt0mtxfrya = muDoubleScalarAbs (
_rtB -> l2xptt0ct0 ) ; _rtB -> kgvnnb1i3r = ( _rtB -> lt0mtxfrya > _rtB ->
j3ri0omuep ) ; if ( _rtB -> kgvnnb1i3r ) { _rtB -> dju2hik5wg = _rtB ->
l2xptt0ct0 + _rtP -> P_83 ; _rtB -> pri452qhe3 = muDoubleScalarMod ( _rtB ->
dju2hik5wg , _rtB -> najirmjrgf ) ; _rtB -> hqbygo0334 = _rtB -> pri452qhe3 +
_rtP -> P_84 ; _rtB -> l5hiapwl3g = _rtB -> hqbygo0334 ; } else { _rtB ->
l5hiapwl3g = _rtB -> l2xptt0ct0 ; } _rtB -> hvxwa0vjdb [ 0 ] = _rtP -> P_201
* _rtB -> hdpbxdutmm ; _rtB -> hvxwa0vjdb [ 1 ] = _rtP -> P_201 * _rtB ->
l5hiapwl3g ; muDoubleScalarSinCos ( _rtB -> hvxwa0vjdb [ 0 ] , & _rtB ->
i5sqspx2uu [ 0 ] , & _rtB -> oscuacptt2 [ 0 ] ) ; muDoubleScalarSinCos ( _rtB
-> hvxwa0vjdb [ 1 ] , & _rtB -> i5sqspx2uu [ 1 ] , & _rtB -> oscuacptt2 [ 1 ]
) ; _rtB -> iprmsqqos4 = _rtB -> i5sqspx2uu [ 0 ] * _rtB -> oscuacptt2 [ 1 ]
; _rtB -> lvtcjhqw2y [ 0 ] = - _rtB -> iprmsqqos4 ; _rtB -> lvtcjhqw2y [ 1 ]
= - _rtB -> i5sqspx2uu [ 1 ] ; _rtB -> ejxugros1w = _rtB -> oscuacptt2 [ 0 ]
* _rtB -> oscuacptt2 [ 1 ] ; _rtB -> lvtcjhqw2y [ 2 ] = - _rtB -> ejxugros1w
; _rtB -> epqr2jhkq3 = _rtB -> i5sqspx2uu [ 0 ] * _rtB -> i5sqspx2uu [ 1 ] ;
_rtB -> lvtcjhqw2y [ 3 ] = - _rtB -> epqr2jhkq3 ; _rtB -> lvtcjhqw2y [ 4 ] =
_rtB -> oscuacptt2 [ 1 ] ; _rtB -> o040sh24gw = _rtB -> i5sqspx2uu [ 1 ] *
_rtB -> oscuacptt2 [ 0 ] ; _rtB -> lvtcjhqw2y [ 5 ] = - _rtB -> o040sh24gw ;
_rtB -> lvtcjhqw2y [ 6 ] = _rtB -> oscuacptt2 [ 0 ] ; _rtB -> lvtcjhqw2y [ 7
] = _rtB -> kbrqaz4om2 ; _rtB -> lvtcjhqw2y [ 8 ] = - _rtB -> i5sqspx2uu [ 0
] ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> ivpclliucm [ 3 * i ] = _rtB ->
lvtcjhqw2y [ i ] ; _rtB -> ivpclliucm [ 1 + 3 * i ] = _rtB -> lvtcjhqw2y [ i
+ 3 ] ; _rtB -> ivpclliucm [ 2 + 3 * i ] = _rtB -> lvtcjhqw2y [ i + 6 ] ; }
_rtB -> fycusylamp = _rtP -> P_206 * _rtB -> hdpbxdutmm ; _rtB -> jl0q0uo10q
= muDoubleScalarSin ( _rtB -> fycusylamp ) ; _rtB -> cqjcziaz5c = _rtB ->
jl0q0uo10q * _rtB -> jl0q0uo10q * _rtB -> k0iozxa4ql ; _rtB -> pxcrxu0ozh =
_rtB -> fvxczqwwt1 + _rtB -> cqjcziaz5c ; _rtB -> ap3ojplpvx = _rtB ->
kui2la2leh * _rtB -> kui2la2leh / _rtB -> pxcrxu0ozh ; _rtB -> d5lwtb5r5j =
muDoubleScalarSqrt ( _rtB -> ap3ojplpvx ) ; _rtB -> hhah1xqlfe = - _rtB ->
d5lwtb5r5j ; _rtB -> ie52fam3cz [ 0 ] = _rtB -> eky3v3o0lj ; _rtB ->
ie52fam3cz [ 1 ] = _rtB -> eky3v3o0lj ; _rtB -> ie52fam3cz [ 2 ] = _rtB ->
hhah1xqlfe ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> eyaxxiysr0 [ i ] = 0.0 ;
_rtB -> eyaxxiysr0 [ i ] += _rtB -> ivpclliucm [ i ] * _rtB -> ie52fam3cz [ 0
] ; _rtB -> eyaxxiysr0 [ i ] += _rtB -> ivpclliucm [ i + 3 ] * _rtB ->
ie52fam3cz [ 1 ] ; _rtB -> eyaxxiysr0 [ i ] += _rtB -> ivpclliucm [ i + 6 ] *
_rtB -> ie52fam3cz [ 2 ] ; } _rtB -> ofm2yzw1aa [ 0 ] = _rtP -> P_208 * _rtB
-> jpi32wqgtj ; _rtB -> ofm2yzw1aa [ 1 ] = _rtP -> P_208 * _rtB -> l5hiapwl3g
; muDoubleScalarSinCos ( _rtB -> ofm2yzw1aa [ 0 ] , & _rtB -> dyyyxykpc1 [ 0
] , & _rtB -> ojxd3e5h4u [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> ofm2yzw1aa
[ 1 ] , & _rtB -> dyyyxykpc1 [ 1 ] , & _rtB -> ojxd3e5h4u [ 1 ] ) ; _rtB ->
ezbfg00mns = _rtB -> dyyyxykpc1 [ 0 ] * _rtB -> ojxd3e5h4u [ 1 ] ; _rtB ->
dobsxjqqe1 [ 0 ] = - _rtB -> ezbfg00mns ; _rtB -> dobsxjqqe1 [ 1 ] = - _rtB
-> dyyyxykpc1 [ 1 ] ; _rtB -> lnwjmwc12e = _rtB -> ojxd3e5h4u [ 0 ] * _rtB ->
ojxd3e5h4u [ 1 ] ; _rtB -> dobsxjqqe1 [ 2 ] = - _rtB -> lnwjmwc12e ; _rtB ->
n1ujg1yg2w = _rtB -> dyyyxykpc1 [ 0 ] * _rtB -> dyyyxykpc1 [ 1 ] ; _rtB ->
dobsxjqqe1 [ 3 ] = - _rtB -> n1ujg1yg2w ; _rtB -> dobsxjqqe1 [ 4 ] = _rtB ->
ojxd3e5h4u [ 1 ] ; _rtB -> edou2txjhb = _rtB -> dyyyxykpc1 [ 1 ] * _rtB ->
ojxd3e5h4u [ 0 ] ; _rtB -> dobsxjqqe1 [ 5 ] = - _rtB -> edou2txjhb ; _rtB ->
dobsxjqqe1 [ 6 ] = _rtB -> ojxd3e5h4u [ 0 ] ; _rtB -> dobsxjqqe1 [ 7 ] = _rtB
-> jugsahblew ; _rtB -> dobsxjqqe1 [ 8 ] = - _rtB -> dyyyxykpc1 [ 0 ] ; for (
i = 0 ; i < 3 ; i ++ ) { _rtB -> ivpclliucm [ 3 * i ] = _rtB -> dobsxjqqe1 [
i ] ; _rtB -> ivpclliucm [ 1 + 3 * i ] = _rtB -> dobsxjqqe1 [ i + 3 ] ; _rtB
-> ivpclliucm [ 2 + 3 * i ] = _rtB -> dobsxjqqe1 [ i + 6 ] ; } _rtB ->
lgl2aejzek = - _rtB -> bxtndmgqmx ; _rtB -> ie52fam3cz [ 0 ] = _rtB ->
h1tn5qf4rw ; _rtB -> ie52fam3cz [ 1 ] = _rtB -> h1tn5qf4rw ; _rtB ->
ie52fam3cz [ 2 ] = _rtB -> lgl2aejzek ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB
-> oxze0wbloe [ i ] = 0.0 ; _rtB -> oxze0wbloe [ i ] += _rtB -> ivpclliucm [
i ] * _rtB -> ie52fam3cz [ 0 ] ; _rtB -> oxze0wbloe [ i ] += _rtB ->
ivpclliucm [ i + 3 ] * _rtB -> ie52fam3cz [ 1 ] ; _rtB -> oxze0wbloe [ i ] +=
_rtB -> ivpclliucm [ i + 6 ] * _rtB -> ie52fam3cz [ 2 ] ; _rtB -> d3hqzw0eyy
[ i ] = _rtB -> eyaxxiysr0 [ i ] + _rtB -> oxze0wbloe [ i ] ; } } if ( _rtDW
-> j3ij5dyxsq != 0 ) { _rtX -> h243v3o4jo [ 0 ] = _rtB -> d3hqzw0eyy [ 0 ] ;
_rtX -> h243v3o4jo [ 1 ] = _rtB -> d3hqzw0eyy [ 1 ] ; _rtX -> h243v3o4jo [ 2
] = _rtB -> d3hqzw0eyy [ 2 ] ; } _rtB -> nherqy4wgr [ 0 ] = _rtX ->
h243v3o4jo [ 0 ] ; _rtB -> nherqy4wgr [ 1 ] = _rtX -> h243v3o4jo [ 1 ] ; _rtB
-> nherqy4wgr [ 2 ] = _rtX -> h243v3o4jo [ 2 ] ; _rtB -> darneeluqi = _rtB ->
nherqy4wgr [ 0 ] * _rtB -> nherqy4wgr [ 0 ] ; _rtB -> nny4i5sa1l = _rtB ->
nherqy4wgr [ 1 ] * _rtB -> nherqy4wgr [ 1 ] ; _rtB -> lhmbywgvse = _rtB ->
darneeluqi + _rtB -> nny4i5sa1l ; _rtB -> jax0alwzqv = muDoubleScalarSqrt (
_rtB -> lhmbywgvse ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { rtAction = 1 ; do
{ _rtB -> deqm2bewyq = rtAction ; _rtB -> forn1hy0wt = _rtDW -> e02mdoctpq ;
if ( _rtB -> deqm2bewyq > _rtP -> P_1810 ) { _rtB -> p45ov3ynlt = _rtB ->
forn1hy0wt ; } else { _rtB -> l3umms1xf0 = _rtB -> cdtxgiqtrs * _rtB ->
jax0alwzqv ; _rtB -> lipw43n5mf = muDoubleScalarAtan2 ( _rtB -> nherqy4wgr [
2 ] , _rtB -> l3umms1xf0 ) ; _rtB -> p45ov3ynlt = _rtB -> lipw43n5mf ; }
muDoubleScalarSinCos ( _rtB -> p45ov3ynlt , & _rtB -> efu3500ccg , & _rtB ->
fkzko4ksgy ) ; _rtB -> j4uvpxozv3 = _rtB -> ouxyooqpux * _rtB -> k1jlitjicc *
_rtB -> efu3500ccg * _rtB -> efu3500ccg * _rtB -> efu3500ccg ; _rtB ->
gb0voedq5c = _rtB -> nherqy4wgr [ 2 ] + _rtB -> j4uvpxozv3 ; _rtB ->
kmflqxtubs = _rtB -> fkzko4ksgy * _rtB -> fkzko4ksgy * _rtB -> fkzko4ksgy *
_rtB -> dm51v5wov2 * _rtB -> imkmzsjjhp ; _rtB -> m1sygxgbkr = _rtB ->
jax0alwzqv - _rtB -> kmflqxtubs ; _rtB -> hdjtdeamw2 = muDoubleScalarAtan2 (
_rtB -> gb0voedq5c , _rtB -> m1sygxgbkr ) ; muDoubleScalarSinCos ( _rtB ->
hdjtdeamw2 , & _rtB -> fsnijv5jbt , & _rtB -> mkmt1o0tia ) ; _rtB ->
krpa1w5ct2 = _rtB -> cdtxgiqtrs * _rtB -> fsnijv5jbt ; _rtB -> m3313g02vs =
muDoubleScalarAtan2 ( _rtB -> krpa1w5ct2 , _rtB -> mkmt1o0tia ) ; _rtB ->
j0wqtj40u5 = ( _rtB -> p45ov3ynlt != _rtB -> m3313g02vs ) ; _rtDW ->
e02mdoctpq = _rtB -> m3313g02vs ; rtAction ++ ; } while ( _rtB -> j0wqtj40u5
&& ( rtAction <= 5 ) ) ; } _rtB -> om5mxtc5gq = muDoubleScalarAtan2 ( _rtB ->
nherqy4wgr [ 1 ] , _rtB -> nherqy4wgr [ 0 ] ) ; _rtB -> ip45w0pt0d [ 0 ] =
_rtP -> P_216 * _rtB -> hdjtdeamw2 ; _rtB -> ip45w0pt0d [ 1 ] = _rtP -> P_216
* _rtB -> om5mxtc5gq ; _rtB -> myrhqoifsz [ 0 ] = _rtP -> P_217 * _rtB ->
ip45w0pt0d [ 0 ] ; _rtB -> myrhqoifsz [ 1 ] = _rtP -> P_217 * _rtB ->
ip45w0pt0d [ 1 ] ; muDoubleScalarSinCos ( _rtB -> myrhqoifsz [ 0 ] , & _rtB
-> m14w1nuqbu [ 0 ] , & _rtB -> irr0phjdpv [ 0 ] ) ; muDoubleScalarSinCos (
_rtB -> myrhqoifsz [ 1 ] , & _rtB -> m14w1nuqbu [ 1 ] , & _rtB -> irr0phjdpv
[ 1 ] ) ; _rtB -> b32pavrevh = _rtB -> m14w1nuqbu [ 0 ] * _rtB -> irr0phjdpv
[ 1 ] ; _rtB -> fmw1ib5eoz [ 0 ] = - _rtB -> b32pavrevh ; _rtB -> fmw1ib5eoz
[ 1 ] = - _rtB -> m14w1nuqbu [ 1 ] ; _rtB -> pxkcmcyffl = _rtB -> irr0phjdpv
[ 0 ] * _rtB -> irr0phjdpv [ 1 ] ; _rtB -> fmw1ib5eoz [ 2 ] = - _rtB ->
pxkcmcyffl ; _rtB -> k5mrx0biwd = _rtB -> m14w1nuqbu [ 0 ] * _rtB ->
m14w1nuqbu [ 1 ] ; _rtB -> fmw1ib5eoz [ 3 ] = - _rtB -> k5mrx0biwd ; _rtB ->
fmw1ib5eoz [ 4 ] = _rtB -> irr0phjdpv [ 1 ] ; _rtB -> mi4j31imwq = _rtB ->
m14w1nuqbu [ 1 ] * _rtB -> irr0phjdpv [ 0 ] ; _rtB -> fmw1ib5eoz [ 5 ] = -
_rtB -> mi4j31imwq ; _rtB -> fmw1ib5eoz [ 6 ] = _rtB -> irr0phjdpv [ 0 ] ;
_rtB -> fmw1ib5eoz [ 7 ] = _rtB -> a534g2nzpx ; _rtB -> fmw1ib5eoz [ 8 ] = -
_rtB -> m14w1nuqbu [ 0 ] ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> cqrf5uuv0t
[ 3 * i ] = _rtB -> fmw1ib5eoz [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3 * i ] =
_rtB -> fmw1ib5eoz [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] = _rtB ->
fmw1ib5eoz [ i + 6 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { for ( i_p = 0 ; i_p <
3 ; i_p ++ ) { _rtB -> n0ypjfdw1o [ i + 3 * i_p ] = 0.0 ; _rtB -> n0ypjfdw1o
[ i + 3 * i_p ] += _rtB -> cqrf5uuv0t [ 3 * i_p ] * _rtB -> df0qunjvqj [ i ]
; _rtB -> n0ypjfdw1o [ i + 3 * i_p ] += _rtB -> cqrf5uuv0t [ 3 * i_p + 1 ] *
_rtB -> df0qunjvqj [ i + 3 ] ; _rtB -> n0ypjfdw1o [ i + 3 * i_p ] += _rtB ->
cqrf5uuv0t [ 3 * i_p + 2 ] * _rtB -> df0qunjvqj [ i + 6 ] ; } } if ( (
int32_T ) _rtB -> ncioipx5q4 == 1 ) { _rtB -> ecjahjdyb5 [ 0 ] = _rtB ->
ej3uy1jfql ; _rtB -> ecjahjdyb5 [ 1 ] = _rtB -> ej3uy1jfql ; _rtB ->
ecjahjdyb5 [ 2 ] = _rtB -> ej3uy1jfql ; } else { _rtB -> mcvxhhgdej [ 0 ] = (
( frf5yblmjv * ) ssGetU ( S ) ) -> eysa00zvpi ; _rtB -> mcvxhhgdej [ 1 ] = (
( frf5yblmjv * ) ssGetU ( S ) ) -> iyc5pabhgi ; _rtB -> mcvxhhgdej [ 2 ] = (
( frf5yblmjv * ) ssGetU ( S ) ) -> hd3qg1wx41 ; for ( i = 0 ; i < 3 ; i ++ )
{ _rtB -> mxwtnyzyjt [ i ] = 0.0 ; _rtB -> mxwtnyzyjt [ i ] += _rtB ->
n0ypjfdw1o [ i ] * _rtB -> mcvxhhgdej [ 0 ] ; _rtB -> mxwtnyzyjt [ i ] +=
_rtB -> n0ypjfdw1o [ i + 3 ] * _rtB -> mcvxhhgdej [ 1 ] ; _rtB -> mxwtnyzyjt
[ i ] += _rtB -> n0ypjfdw1o [ i + 6 ] * _rtB -> mcvxhhgdej [ 2 ] ; _rtB ->
ecjahjdyb5 [ i ] = _rtB -> mxwtnyzyjt [ i ] ; } } if ( ssIsSampleHit ( S , 1
, 0 ) ) { muDoubleScalarSinCos ( _rtB -> hdjtdeamw2 , & _rtB -> fmj0uwtkn5 ,
& _rtB -> m3n0igaant ) ; _rtB -> hm5vclymss = _rtB -> fmj0uwtkn5 * _rtB ->
dm51v5wov2 ; _rtB -> gsk1cg0cqe = _rtB -> hm5vclymss * _rtB -> fmj0uwtkn5 ;
_rtB -> njumdrys4l = _rtB -> gb2ohd1r2z - _rtB -> gsk1cg0cqe ; _rtB ->
bi1grae3sa = muDoubleScalarSqrt ( _rtB -> njumdrys4l ) ; _rtB -> g5oojhrcst =
_rtB -> arrntb3df4 / _rtB -> bi1grae3sa ; _rtB -> f23fju40rh = _rtB ->
hm5vclymss * _rtB -> g5oojhrcst ; } _rtB -> cpotle5wkv = _rtB -> nherqy4wgr [
2 ] + _rtB -> f23fju40rh ; _rtB -> evf5hzzosw = _rtB -> fmj0uwtkn5 * _rtB ->
cpotle5wkv ; _rtB -> oyoy4ub5tc = _rtB -> m3n0igaant * _rtB -> jax0alwzqv ;
_rtB -> i1glyxlove = ( _rtB -> evf5hzzosw - _rtB -> g5oojhrcst ) + _rtB ->
oyoy4ub5tc ; _rtB -> biho35zqrj = _rtP -> P_221 * _rtB -> i1glyxlove ; _rtB
-> a1cz2fmjxb = _rtB -> biho35zqrj - _rtB -> hdvi031ysj ; if ( _rtB ->
a1cz2fmjxb > _rtP -> P_222 ) { _rtB -> ekqiytdpmn [ 0 ] = _rtB -> ecjahjdyb5
[ 0 ] ; _rtB -> ekqiytdpmn [ 1 ] = _rtB -> ecjahjdyb5 [ 1 ] ; _rtB ->
ekqiytdpmn [ 2 ] = _rtB -> ecjahjdyb5 [ 2 ] ; } else { if ( _rtB ->
ecjahjdyb5 [ 0 ] > _rtP -> P_73 ) { _rtB -> dxkqxxp0oh [ 0 ] = _rtP -> P_73 ;
} else if ( _rtB -> ecjahjdyb5 [ 0 ] < _rtP -> P_74 ) { _rtB -> dxkqxxp0oh [
0 ] = _rtP -> P_74 ; } else { _rtB -> dxkqxxp0oh [ 0 ] = _rtB -> ecjahjdyb5 [
0 ] ; } _rtB -> ekqiytdpmn [ 0 ] = _rtB -> dxkqxxp0oh [ 0 ] ; if ( _rtB ->
ecjahjdyb5 [ 1 ] > _rtP -> P_73 ) { _rtB -> dxkqxxp0oh [ 1 ] = _rtP -> P_73 ;
} else if ( _rtB -> ecjahjdyb5 [ 1 ] < _rtP -> P_74 ) { _rtB -> dxkqxxp0oh [
1 ] = _rtP -> P_74 ; } else { _rtB -> dxkqxxp0oh [ 1 ] = _rtB -> ecjahjdyb5 [
1 ] ; } _rtB -> ekqiytdpmn [ 1 ] = _rtB -> dxkqxxp0oh [ 1 ] ; if ( _rtB ->
ecjahjdyb5 [ 2 ] > _rtP -> P_73 ) { _rtB -> dxkqxxp0oh [ 2 ] = _rtP -> P_73 ;
} else if ( _rtB -> ecjahjdyb5 [ 2 ] < _rtP -> P_74 ) { _rtB -> dxkqxxp0oh [
2 ] = _rtP -> P_74 ; } else { _rtB -> dxkqxxp0oh [ 2 ] = _rtB -> ecjahjdyb5 [
2 ] ; } _rtB -> ekqiytdpmn [ 2 ] = _rtB -> dxkqxxp0oh [ 2 ] ; } if ( _rtDW ->
bcfg4ee1te == ( rtInf ) ) { _rtB -> isom3ebtib [ 0 ] = _rtB -> ekqiytdpmn [ 0
] ; _rtB -> isom3ebtib [ 1 ] = _rtB -> ekqiytdpmn [ 1 ] ; _rtB -> isom3ebtib
[ 2 ] = _rtB -> ekqiytdpmn [ 2 ] ; } else { deltaT = ssGetTaskTime ( S , 0 )
- _rtDW -> bcfg4ee1te ; tmp_i = deltaT * _rtP -> P_223 ; deltaT *= _rtP ->
P_224 ; tmpForInput = _rtB -> ekqiytdpmn [ 0 ] - _rtDW -> gqsx3hpmt3 [ 0 ] ;
if ( tmpForInput > tmp_i ) { _rtB -> isom3ebtib [ 0 ] = _rtDW -> gqsx3hpmt3 [
0 ] + tmp_i ; } else if ( tmpForInput < deltaT ) { _rtB -> isom3ebtib [ 0 ] =
_rtDW -> gqsx3hpmt3 [ 0 ] + deltaT ; } else { _rtB -> isom3ebtib [ 0 ] = _rtB
-> ekqiytdpmn [ 0 ] ; } tmpForInput = _rtB -> ekqiytdpmn [ 1 ] - _rtDW ->
gqsx3hpmt3 [ 1 ] ; if ( tmpForInput > tmp_i ) { _rtB -> isom3ebtib [ 1 ] =
_rtDW -> gqsx3hpmt3 [ 1 ] + tmp_i ; } else if ( tmpForInput < deltaT ) { _rtB
-> isom3ebtib [ 1 ] = _rtDW -> gqsx3hpmt3 [ 1 ] + deltaT ; } else { _rtB ->
isom3ebtib [ 1 ] = _rtB -> ekqiytdpmn [ 1 ] ; } tmpForInput = _rtB ->
ekqiytdpmn [ 2 ] - _rtDW -> gqsx3hpmt3 [ 2 ] ; if ( tmpForInput > tmp_i ) {
_rtB -> isom3ebtib [ 2 ] = _rtDW -> gqsx3hpmt3 [ 2 ] + tmp_i ; } else if (
tmpForInput < deltaT ) { _rtB -> isom3ebtib [ 2 ] = _rtDW -> gqsx3hpmt3 [ 2 ]
+ deltaT ; } else { _rtB -> isom3ebtib [ 2 ] = _rtB -> ekqiytdpmn [ 2 ] ; } }
if ( _rtDW -> gd0ppilara != 0 ) { _rtX -> newd2wm3dk [ 0 ] = _rtB ->
jeetl5x0nz [ 0 ] ; _rtX -> newd2wm3dk [ 1 ] = _rtB -> jeetl5x0nz [ 1 ] ; _rtX
-> newd2wm3dk [ 2 ] = _rtB -> jeetl5x0nz [ 2 ] ; } _rtB -> dlzh5xejq2 [ 0 ] =
_rtX -> newd2wm3dk [ 0 ] ; _rtB -> gxlqdjspys [ 0 ] = _rtP -> P_225 * _rtB ->
dlzh5xejq2 [ 0 ] ; _rtB -> dkpy3rhwqa [ 0 ] = _rtB -> gxlqdjspys [ 0 ] - _rtB
-> isom3ebtib [ 0 ] ; _rtB -> dlzh5xejq2 [ 1 ] = _rtX -> newd2wm3dk [ 1 ] ;
_rtB -> gxlqdjspys [ 1 ] = _rtP -> P_225 * _rtB -> dlzh5xejq2 [ 1 ] ; _rtB ->
dkpy3rhwqa [ 1 ] = _rtB -> gxlqdjspys [ 1 ] - _rtB -> isom3ebtib [ 1 ] ; _rtB
-> dlzh5xejq2 [ 2 ] = _rtX -> newd2wm3dk [ 2 ] ; _rtB -> gxlqdjspys [ 2 ] =
_rtP -> P_225 * _rtB -> dlzh5xejq2 [ 2 ] ; _rtB -> dkpy3rhwqa [ 2 ] = _rtB ->
gxlqdjspys [ 2 ] - _rtB -> isom3ebtib [ 2 ] ; _rtB -> m42lremod0 = _rtB ->
dkpy3rhwqa [ 0 ] * _rtB -> dkpy3rhwqa [ 0 ] ; _rtB -> idwkoqwesx = _rtB ->
dkpy3rhwqa [ 1 ] * _rtB -> dkpy3rhwqa [ 1 ] ; _rtB -> czxdry1ghv = _rtB ->
dkpy3rhwqa [ 2 ] * _rtB -> dkpy3rhwqa [ 2 ] ; _rtB -> baiex5wrzt = ( _rtB ->
m42lremod0 + _rtB -> idwkoqwesx ) + _rtB -> czxdry1ghv ; ssCallAccelRunBlock
( S , 119 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> dv0khbuamy = _rtB ->
cg0ah2wgfn * _rtB -> hs4hzf4agr ; _rtB -> k2evfpi33c = _rtB -> baiex5wrzt *
_rtB -> dv0khbuamy ; _rtB -> iydo4ipsmn = _rtP -> P_226 * _rtB -> k2evfpi33c
; _rtB -> psvcnamasx = _rtB -> iydo4ipsmn * _rtB -> jj2p1sjakx ; _rtB ->
g1spufntqt [ 0 ] = _rtB -> n0ypjfdw1o [ 3 ] ; _rtB -> a2e100iads [ 0 ] = _rtP
-> P_228 [ 0 ] * _rtB -> g1spufntqt [ 0 ] ; _rtB -> g1spufntqt [ 1 ] = _rtB
-> n0ypjfdw1o [ 0 ] ; _rtB -> a2e100iads [ 1 ] = _rtP -> P_228 [ 1 ] * _rtB
-> g1spufntqt [ 1 ] ; _rtB -> g1spufntqt [ 2 ] = _rtB -> n0ypjfdw1o [ 6 ] ;
_rtB -> a2e100iads [ 2 ] = _rtP -> P_228 [ 2 ] * _rtB -> g1spufntqt [ 2 ] ;
_rtB -> ikiabfna1r [ 0 ] = _rtB -> n0ypjfdw1o [ 7 ] ; _rtB -> a2e100iads [ 3
] = _rtP -> P_229 [ 0 ] * _rtB -> ikiabfna1r [ 0 ] ; _rtB -> a2j44z3f4p [ 0 ]
= _rtB -> n0ypjfdw1o [ 1 ] ; _rtB -> a2e100iads [ 5 ] = _rtP -> P_230 [ 0 ] *
_rtB -> a2j44z3f4p [ 0 ] ; _rtB -> ikiabfna1r [ 1 ] = _rtB -> n0ypjfdw1o [ 8
] ; _rtB -> a2e100iads [ 4 ] = _rtP -> P_229 [ 1 ] * _rtB -> ikiabfna1r [ 1 ]
; _rtB -> a2j44z3f4p [ 1 ] = _rtB -> n0ypjfdw1o [ 4 ] ; _rtB -> a2e100iads [
6 ] = _rtP -> P_230 [ 1 ] * _rtB -> a2j44z3f4p [ 1 ] ; if ( ssIsMajorTimeStep
( S ) ) { rtAction = ( int8_T ) ! ( ( _rtB -> a2e100iads [ 2 ] >= 1.0 ) || (
_rtB -> a2e100iads [ 2 ] <= - 1.0 ) ) ; _rtDW -> onk41eqc3n = rtAction ; }
else { rtAction = _rtDW -> onk41eqc3n ; } switch ( rtAction ) { case 0 : _rtB
-> cip3exm2yt [ 0 ] = muDoubleScalarAtan2 ( _rtB -> a2e100iads [ 5 ] , _rtB
-> a2e100iads [ 6 ] ) ; if ( _rtB -> a2e100iads [ 2 ] > 1.0 ) { tmp_i = 1.0 ;
} else if ( _rtB -> a2e100iads [ 2 ] < - 1.0 ) { tmp_i = - 1.0 ; } else {
tmp_i = _rtB -> a2e100iads [ 2 ] ; } _rtB -> cip3exm2yt [ 1 ] =
muDoubleScalarAsin ( tmp_i ) ; _rtB -> cip3exm2yt [ 2 ] = 0.0 ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> ki0pbgkmrf ) ; } break ;
case 1 : _rtB -> cip3exm2yt [ 0 ] = muDoubleScalarAtan2 ( _rtB -> a2e100iads
[ 0 ] , _rtB -> a2e100iads [ 1 ] ) ; if ( _rtB -> a2e100iads [ 2 ] > 1.0 ) {
tmp_i = 1.0 ; } else if ( _rtB -> a2e100iads [ 2 ] < - 1.0 ) { tmp_i = - 1.0
; } else { tmp_i = _rtB -> a2e100iads [ 2 ] ; } _rtB -> cip3exm2yt [ 1 ] =
muDoubleScalarAsin ( tmp_i ) ; _rtB -> cip3exm2yt [ 2 ] = muDoubleScalarAtan2
( _rtB -> a2e100iads [ 3 ] , _rtB -> a2e100iads [ 4 ] ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> cpnbqlf0jg ) ; } break ; }
if ( _rtB -> gxlqdjspys [ 0 ] > _rtP -> P_231 ) { _rtB -> dz3d0zukpd =
muDoubleScalarAtan2 ( _rtB -> dkpy3rhwqa [ 2 ] , _rtB -> dkpy3rhwqa [ 0 ] ) ;
_rtB -> pgkpwhbsc4 = _rtB -> dz3d0zukpd ; } else { _rtB -> pgkpwhbsc4 = _rtB
-> cip3exm2yt [ 1 ] ; } _rtB -> pm501wbm4q = _rtP -> P_232 * _rtB ->
pgkpwhbsc4 ; if ( _rtB -> pm501wbm4q > _rtP -> P_233 ) { _rtB -> mdjtas5b2i =
_rtP -> P_233 ; } else if ( _rtB -> pm501wbm4q < _rtP -> P_234 ) { _rtB ->
mdjtas5b2i = _rtP -> P_234 ; } else { _rtB -> mdjtas5b2i = _rtB -> pm501wbm4q
; } _rtB -> bqakmyhe5i = _rtP -> P_235 * _rtB -> mdjtas5b2i ; _rtB ->
ao1wzqfqbl = _rtB -> dkpy3rhwqa [ 0 ] * _rtB -> dkpy3rhwqa [ 0 ] ; _rtB ->
cdi51byt3y = _rtB -> dkpy3rhwqa [ 1 ] * _rtB -> dkpy3rhwqa [ 1 ] ; _rtB ->
czty4iqdyl = _rtB -> dkpy3rhwqa [ 2 ] * _rtB -> dkpy3rhwqa [ 2 ] ; _rtB ->
jlz2wgdp4e = ( _rtB -> ao1wzqfqbl + _rtB -> cdi51byt3y ) + _rtB -> czty4iqdyl
; _rtB -> jhde4x05sz = muDoubleScalarSqrt ( _rtB -> jlz2wgdp4e ) ; if ( _rtB
-> gxlqdjspys [ 0 ] > _rtP -> P_237 ) { if ( _rtB -> jhde4x05sz > _rtP ->
P_71 ) { _rtB -> ffji0cb1qz = _rtP -> P_71 ; } else if ( _rtB -> jhde4x05sz <
_rtP -> P_72 ) { _rtB -> ffji0cb1qz = _rtP -> P_72 ; } else { _rtB ->
ffji0cb1qz = _rtB -> jhde4x05sz ; } _rtB -> bxw0ggghtj = _rtB -> dkpy3rhwqa [
1 ] / _rtB -> ffji0cb1qz ; if ( _rtB -> bxw0ggghtj > 1.0 ) { tmp_i = 1.0 ; }
else if ( _rtB -> bxw0ggghtj < - 1.0 ) { tmp_i = - 1.0 ; } else { tmp_i =
_rtB -> bxw0ggghtj ; } _rtB -> nyf351c3uh = muDoubleScalarAsin ( tmp_i ) ;
_rtB -> fylzvybqbu = _rtB -> nyf351c3uh ; } else { _rtB -> fylzvybqbu = _rtB
-> hwjrsdvxqk ; } _rtB -> ck5vofkkim = _rtP -> P_238 * _rtB -> fylzvybqbu ;
if ( _rtB -> ck5vofkkim > _rtP -> P_239 ) { _rtB -> ajyubmph5b = _rtP ->
P_239 ; } else if ( _rtB -> ck5vofkkim < _rtP -> P_240 ) { _rtB -> ajyubmph5b
= _rtP -> P_240 ; } else { _rtB -> ajyubmph5b = _rtB -> ck5vofkkim ; } _rtB
-> mo5335w4ku = _rtP -> P_241 * _rtB -> ajyubmph5b ; _rtB -> f3xkxgniib [ 0 ]
= _rtB -> bqakmyhe5i ; _rtB -> f3xkxgniib [ 1 ] = _rtB -> mo5335w4ku ;
muDoubleScalarSinCos ( _rtB -> f3xkxgniib [ 0 ] , & _rtB -> fbkdlgj4ap [ 0 ]
, & _rtB -> didgbto0lx [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> f3xkxgniib [
1 ] , & _rtB -> fbkdlgj4ap [ 1 ] , & _rtB -> didgbto0lx [ 1 ] ) ; _rtB ->
lnpe1usk1n [ 0 ] = _rtB -> didgbto0lx [ 0 ] * _rtB -> didgbto0lx [ 1 ] ; _rtB
-> e5jv1xrn1z = _rtB -> fbkdlgj4ap [ 1 ] * _rtB -> didgbto0lx [ 0 ] ; _rtB ->
lnpe1usk1n [ 1 ] = - _rtB -> e5jv1xrn1z ; _rtB -> lnpe1usk1n [ 2 ] = - _rtB
-> fbkdlgj4ap [ 0 ] ; _rtB -> lnpe1usk1n [ 3 ] = _rtB -> fbkdlgj4ap [ 1 ] ;
_rtB -> lnpe1usk1n [ 4 ] = _rtB -> didgbto0lx [ 1 ] ; _rtB -> lnpe1usk1n [ 5
] = _rtB -> gltow0ukg4 ; _rtB -> lnpe1usk1n [ 6 ] = _rtB -> fbkdlgj4ap [ 0 ]
* _rtB -> didgbto0lx [ 1 ] ; _rtB -> d0kblocoic = _rtB -> fbkdlgj4ap [ 0 ] *
_rtB -> fbkdlgj4ap [ 1 ] ; _rtB -> lnpe1usk1n [ 7 ] = - _rtB -> d0kblocoic ;
_rtB -> lnpe1usk1n [ 8 ] = _rtB -> didgbto0lx [ 0 ] ; for ( i = 0 ; i < 3 ; i
++ ) { _rtB -> cqrf5uuv0t [ 3 * i ] = _rtB -> lnpe1usk1n [ i ] ; _rtB ->
cqrf5uuv0t [ 1 + 3 * i ] = _rtB -> lnpe1usk1n [ i + 3 ] ; _rtB -> cqrf5uuv0t
[ 2 + 3 * i ] = _rtB -> lnpe1usk1n [ i + 6 ] ; } _rtB -> j5lpxvsb0a = _rtP ->
P_243 * _rtB -> mdjtas5b2i ; _rtB -> bpbc0mvf3l = _rtB -> j5lpxvsb0a * _rtB
-> liiewueqnu ; if ( _rtB -> bpbc0mvf3l > _rtP -> P_245 ) { _rtB ->
hto42ym3um = _rtP -> P_245 ; } else if ( _rtB -> bpbc0mvf3l < _rtP -> P_246 )
{ _rtB -> hto42ym3um = _rtP -> P_246 ; } else { _rtB -> hto42ym3um = _rtB ->
bpbc0mvf3l ; } _rtB -> luhio0syuy = look1_binlxpw ( _rtB -> hto42ym3um , _rtP
-> P_248 , _rtP -> P_247 , 18U ) ; _rtB -> jtkkxvvikq = _rtB -> df3urf2ol0 -
_rtB -> jz2cmla1ew ; _rtB -> ntglmz5qry = _rtP -> P_249 * _rtB -> jtkkxvvikq
; _rtB -> iz2e1tzgnj = _rtP -> P_250 * _rtB -> ntglmz5qry ; _rtB ->
erxq2xl21r = _rtP -> P_251 * _rtB -> iz2e1tzgnj ; _rtB -> ae0l2fzcox = _rtP
-> P_252 * _rtB -> erxq2xl21r ; _rtB -> mgf0zvtxk5 = _rtB -> ae0l2fzcox *
_rtB -> lwhenhqfrt ; if ( _rtB -> mgf0zvtxk5 > _rtP -> P_254 ) { _rtB ->
mvxojrzgzg = _rtP -> P_254 ; } else if ( _rtB -> mgf0zvtxk5 < _rtP -> P_255 )
{ _rtB -> mvxojrzgzg = _rtP -> P_255 ; } else { _rtB -> mvxojrzgzg = _rtB ->
mgf0zvtxk5 ; } _rtB -> iehwerkkea = look2_binlxpw ( _rtB -> hto42ym3um , _rtB
-> mvxojrzgzg , _rtP -> P_257 , _rtP -> P_258 , _rtP -> P_256 , _rtP ->
P_1568 , 19U ) ; _rtB -> lki52xvtwv = _rtP -> P_259 * _rtB -> iz2e1tzgnj ;
_rtB -> jcv42qbx0z = _rtB -> lki52xvtwv * _rtB -> nvek2l3eqj ; if ( _rtB ->
jcv42qbx0z > _rtP -> P_261 ) { _rtB -> geaep4j3d1 = _rtP -> P_261 ; } else if
( _rtB -> jcv42qbx0z < _rtP -> P_262 ) { _rtB -> geaep4j3d1 = _rtP -> P_262 ;
} else { _rtB -> geaep4j3d1 = _rtB -> jcv42qbx0z ; } _rtB -> ohmrlixo25 =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> geaep4j3d1 , _rtP -> P_264 ,
_rtP -> P_265 , _rtP -> P_263 , _rtP -> P_1569 , 19U ) ; _rtB -> eindf3oe00 =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e4nsgkn1dx , _rtP -> P_272 ,
_rtP -> P_273 , _rtP -> P_271 , _rtP -> P_1570 , 19U ) ; _rtB -> p55vtjvkol =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> aroihrbipy , _rtP -> P_279 ,
_rtP -> P_280 , _rtP -> P_278 , _rtP -> P_1571 , 19U ) ; _rtB -> fghbedt1dj =
_rtB -> pren33n0wb + _rtB -> dwu5ylnrjd ; _rtB -> c3gquvcdso = _rtP -> P_281
* _rtB -> fghbedt1dj ; _rtB -> ln3uo2qn23 = _rtP -> P_282 * _rtB ->
c3gquvcdso ; _rtB -> cyqdwgdgz3 = _rtP -> P_283 * _rtB -> ln3uo2qn23 ; _rtB
-> mng0t4cj2r = _rtB -> cyqdwgdgz3 * _rtB -> meyzhnutpf ; if ( _rtB ->
mng0t4cj2r > _rtP -> P_285 ) { _rtB -> pqookhf1xn = _rtP -> P_285 ; } else if
( _rtB -> mng0t4cj2r < _rtP -> P_286 ) { _rtB -> pqookhf1xn = _rtP -> P_286 ;
} else { _rtB -> pqookhf1xn = _rtB -> mng0t4cj2r ; } _rtB -> kfamwt440w =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> pqookhf1xn , _rtP -> P_288 ,
_rtP -> P_289 , _rtP -> P_287 , _rtP -> P_1572 , 19U ) ; _rtB -> ceyt2xtq3j =
_rtP -> P_290 * _rtB -> bamumk3b4m ; _rtB -> f1w1qsnkeu = _rtP -> P_291 *
_rtB -> ceyt2xtq3j ; _rtB -> i1jj31b2j0 = _rtB -> f1w1qsnkeu * _rtB ->
bfba1ogkqu ; if ( _rtB -> i1jj31b2j0 > _rtP -> P_293 ) { _rtB -> e1gvnylftj =
_rtP -> P_293 ; } else if ( _rtB -> i1jj31b2j0 < _rtP -> P_294 ) { _rtB ->
e1gvnylftj = _rtP -> P_294 ; } else { _rtB -> e1gvnylftj = _rtB -> i1jj31b2j0
; } _rtB -> b0tm3im40n = look2_binlxpw ( _rtB -> hto42ym3um , _rtB ->
e1gvnylftj , _rtP -> P_296 , _rtP -> P_297 , _rtP -> P_295 , _rtP -> P_1573 ,
19U ) ; _rtB -> cdvubh1kij = ( ( ( ( ( _rtB -> luhio0syuy + _rtB ->
iehwerkkea ) + _rtB -> ohmrlixo25 ) + _rtB -> eindf3oe00 ) + _rtB ->
p55vtjvkol ) + _rtB -> kfamwt440w ) + _rtB -> b0tm3im40n ; _rtB -> jddhbbhras
= look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> mvxojrzgzg , _rtP -> P_299 ,
_rtP -> P_300 , _rtP -> P_298 , _rtP -> P_1574 , 19U ) ; _rtB -> g4we5otj4v =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> geaep4j3d1 , _rtP -> P_302 ,
_rtP -> P_303 , _rtP -> P_301 , _rtP -> P_1575 , 19U ) ; _rtB -> oqjb2455ws =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e4nsgkn1dx , _rtP -> P_305 ,
_rtP -> P_306 , _rtP -> P_304 , _rtP -> P_1576 , 19U ) ; _rtB -> btg3h2t0wu =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> aroihrbipy , _rtP -> P_308 ,
_rtP -> P_309 , _rtP -> P_307 , _rtP -> P_1577 , 19U ) ; _rtB -> l0nqgf0vop =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e1gvnylftj , _rtP -> P_311 ,
_rtP -> P_312 , _rtP -> P_310 , _rtP -> P_1578 , 19U ) ; _rtB -> ig2huggs1h =
( ( ( _rtB -> jddhbbhras + _rtB -> g4we5otj4v ) + _rtB -> oqjb2455ws ) + _rtB
-> btg3h2t0wu ) + _rtB -> l0nqgf0vop ; _rtB -> erfxlux4pc = look1_binlxpw (
_rtB -> hto42ym3um , _rtP -> P_314 , _rtP -> P_313 , 18U ) ; _rtB ->
l20qjq2v4o = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> pqookhf1xn , _rtP
-> P_316 , _rtP -> P_317 , _rtP -> P_315 , _rtP -> P_1579 , 19U ) ; _rtB ->
gnngglop1z = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> mvxojrzgzg , _rtP
-> P_319 , _rtP -> P_320 , _rtP -> P_318 , _rtP -> P_1580 , 19U ) ; _rtB ->
ck5bear00i = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> geaep4j3d1 , _rtP
-> P_322 , _rtP -> P_323 , _rtP -> P_321 , _rtP -> P_1581 , 19U ) ; _rtB ->
gyqwrt1rwm = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e4nsgkn1dx , _rtP
-> P_325 , _rtP -> P_326 , _rtP -> P_324 , _rtP -> P_1582 , 19U ) ; _rtB ->
p0er5fmd4k = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> aroihrbipy , _rtP
-> P_328 , _rtP -> P_329 , _rtP -> P_327 , _rtP -> P_1583 , 19U ) ; _rtB ->
agr04ao2xx = look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e1gvnylftj , _rtP
-> P_331 , _rtP -> P_332 , _rtP -> P_330 , _rtP -> P_1584 , 19U ) ; _rtB ->
jvq4doxlfp = ( ( ( ( ( _rtB -> erfxlux4pc + _rtB -> l20qjq2v4o ) + _rtB ->
gnngglop1z ) + _rtB -> ck5bear00i ) + _rtB -> gyqwrt1rwm ) + _rtB ->
p0er5fmd4k ) + _rtB -> agr04ao2xx ; _rtB -> fyaxkjv1pn = look2_binlxpw ( _rtB
-> hto42ym3um , _rtB -> mvxojrzgzg , _rtP -> P_334 , _rtP -> P_335 , _rtP ->
P_333 , _rtP -> P_1585 , 19U ) ; _rtB -> k4n2lykkf3 = look2_binlxpw ( _rtB ->
hto42ym3um , _rtB -> geaep4j3d1 , _rtP -> P_337 , _rtP -> P_338 , _rtP ->
P_336 , _rtP -> P_1586 , 19U ) ; _rtB -> goixslzzja = look2_binlxpw ( _rtB ->
hto42ym3um , _rtB -> e1gvnylftj , _rtP -> P_340 , _rtP -> P_341 , _rtP ->
P_339 , _rtP -> P_1587 , 19U ) ; _rtB -> ebv1qa4lkn = look2_binlxpw ( _rtB ->
hto42ym3um , _rtB -> e4nsgkn1dx , _rtP -> P_343 , _rtP -> P_344 , _rtP ->
P_342 , _rtP -> P_1588 , 19U ) ; _rtB -> dv2z2gp4d0 = look2_binlxpw ( _rtB ->
hto42ym3um , _rtB -> aroihrbipy , _rtP -> P_346 , _rtP -> P_347 , _rtP ->
P_345 , _rtP -> P_1589 , 19U ) ; _rtB -> d1sjhixam2 = ( ( ( _rtB ->
fyaxkjv1pn + _rtB -> k4n2lykkf3 ) + _rtB -> goixslzzja ) + _rtB -> ebv1qa4lkn
) + _rtB -> dv2z2gp4d0 ; _rtB -> dob1h1fzfj = look1_binlxpw ( _rtB ->
hto42ym3um , _rtP -> P_349 , _rtP -> P_348 , 18U ) ; _rtB -> mfbxmyfrkc =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> pqookhf1xn , _rtP -> P_351 ,
_rtP -> P_352 , _rtP -> P_350 , _rtP -> P_1590 , 19U ) ; _rtB -> gzeooqwcmm =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> mvxojrzgzg , _rtP -> P_354 ,
_rtP -> P_355 , _rtP -> P_353 , _rtP -> P_1591 , 19U ) ; _rtB -> mvpewmio4m =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> geaep4j3d1 , _rtP -> P_357 ,
_rtP -> P_358 , _rtP -> P_356 , _rtP -> P_1592 , 19U ) ; _rtB -> cjwa3k1vqo =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e4nsgkn1dx , _rtP -> P_360 ,
_rtP -> P_361 , _rtP -> P_359 , _rtP -> P_1593 , 19U ) ; _rtB -> d1iiuhrge3 =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> aroihrbipy , _rtP -> P_363 ,
_rtP -> P_364 , _rtP -> P_362 , _rtP -> P_1594 , 19U ) ; _rtB -> cfwkbj0rua =
look2_binlxpw ( _rtB -> hto42ym3um , _rtB -> e1gvnylftj , _rtP -> P_366 ,
_rtP -> P_367 , _rtP -> P_365 , _rtP -> P_1595 , 19U ) ; _rtB -> jiqx4hqgfv =
( ( ( ( ( _rtB -> dob1h1fzfj + _rtB -> mfbxmyfrkc ) + _rtB -> gzeooqwcmm ) +
_rtB -> mvpewmio4m ) + _rtB -> cjwa3k1vqo ) + _rtB -> d1iiuhrge3 ) + _rtB ->
cfwkbj0rua ; _rtB -> jkjxkrkald = look2_binlxpw ( _rtB -> hto42ym3um , _rtB
-> mvxojrzgzg , _rtP -> P_369 , _rtP -> P_370 , _rtP -> P_368 , _rtP ->
P_1596 , 19U ) ; _rtB -> kp1ouebbmp = look2_binlxpw ( _rtB -> hto42ym3um ,
_rtB -> geaep4j3d1 , _rtP -> P_372 , _rtP -> P_373 , _rtP -> P_371 , _rtP ->
P_1597 , 19U ) ; _rtB -> evlqzpz0tt = look2_binlxpw ( _rtB -> hto42ym3um ,
_rtB -> e1gvnylftj , _rtP -> P_375 , _rtP -> P_376 , _rtP -> P_374 , _rtP ->
P_1598 , 19U ) ; _rtB -> hjrsklk0of = look2_binlxpw ( _rtB -> hto42ym3um ,
_rtB -> e4nsgkn1dx , _rtP -> P_378 , _rtP -> P_379 , _rtP -> P_377 , _rtP ->
P_1599 , 19U ) ; _rtB -> meewd0qjtq = look2_binlxpw ( _rtB -> hto42ym3um ,
_rtB -> aroihrbipy , _rtP -> P_381 , _rtP -> P_382 , _rtP -> P_380 , _rtP ->
P_1600 , 19U ) ; _rtB -> c4sc15g2an = ( ( ( _rtB -> jkjxkrkald + _rtB ->
kp1ouebbmp ) + _rtB -> evlqzpz0tt ) + _rtB -> hjrsklk0of ) + _rtB ->
meewd0qjtq ; _rtB -> onjthscgby = _rtB -> j5lpxvsb0a * _rtB -> mskcrf5jrp ;
if ( _rtB -> onjthscgby > _rtP -> P_384 ) { _rtB -> hetoguwk1m = _rtP ->
P_384 ; } else if ( _rtB -> onjthscgby < _rtP -> P_385 ) { _rtB -> hetoguwk1m
= _rtP -> P_385 ; } else { _rtB -> hetoguwk1m = _rtB -> onjthscgby ; } _rtB
-> djgboligtx = _rtP -> P_386 * _rtB -> ajyubmph5b ; _rtB -> ghkolwkf4l =
_rtB -> djgboligtx * _rtB -> d0b2v5lcny ; if ( _rtB -> ghkolwkf4l > _rtP ->
P_388 ) { _rtB -> gljzr5esw5 = _rtP -> P_388 ; } else if ( _rtB -> ghkolwkf4l
< _rtP -> P_389 ) { _rtB -> gljzr5esw5 = _rtP -> P_389 ; } else { _rtB ->
gljzr5esw5 = _rtB -> ghkolwkf4l ; } _rtB -> agbu5jlwqm = look2_binlxpw ( _rtB
-> hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_391 , _rtP -> P_392 , _rtP ->
P_390 , _rtP -> P_1601 , 19U ) ; _rtB -> ovqfsgrtai = look2_binlxpw ( _rtB ->
hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_394 , _rtP -> P_395 , _rtP ->
P_393 , _rtP -> P_1602 , 19U ) ; _rtB -> lbeqrhwfc1 = look2_binlxpw ( _rtB ->
hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_397 , _rtP -> P_398 , _rtP ->
P_396 , _rtP -> P_1603 , 19U ) ; _rtB -> m1d3clx0aj = look2_binlxpw ( _rtB ->
hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_400 , _rtP -> P_401 , _rtP ->
P_399 , _rtP -> P_1604 , 19U ) ; _rtB -> h2twqplwq2 = look2_binlxpw ( _rtB ->
hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_403 , _rtP -> P_404 , _rtP ->
P_402 , _rtP -> P_1605 , 19U ) ; _rtB -> azfc0mhcgy = look2_binlxpw ( _rtB ->
hetoguwk1m , _rtB -> gljzr5esw5 , _rtP -> P_406 , _rtP -> P_407 , _rtP ->
P_405 , _rtP -> P_1606 , 19U ) ; _rtB -> oemrsamsqh [ 0 ] = _rtB ->
cdvubh1kij + _rtB -> agbu5jlwqm ; _rtB -> oemrsamsqh [ 1 ] = _rtB ->
ig2huggs1h + _rtB -> ovqfsgrtai ; _rtB -> oemrsamsqh [ 2 ] = _rtB ->
jvq4doxlfp + _rtB -> lbeqrhwfc1 ; _rtB -> oemrsamsqh [ 3 ] = _rtB ->
d1sjhixam2 + _rtB -> m1d3clx0aj ; _rtB -> oemrsamsqh [ 4 ] = _rtB ->
jiqx4hqgfv + _rtB -> h2twqplwq2 ; _rtB -> oemrsamsqh [ 5 ] = _rtB ->
c4sc15g2an + _rtB -> azfc0mhcgy ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
ofbjdv240i [ i ] = _rtB -> kdk42taj4a [ i ] ; } _rtB -> p1exhcau50 = _rtB ->
j5lpxvsb0a * _rtB -> finp2j0gwd ; if ( _rtB -> p1exhcau50 > _rtP -> P_415 ) {
_rtB -> lnmufeoaot = _rtP -> P_415 ; } else if ( _rtB -> p1exhcau50 < _rtP ->
P_416 ) { _rtB -> lnmufeoaot = _rtP -> P_416 ; } else { _rtB -> lnmufeoaot =
_rtB -> p1exhcau50 ; } _rtB -> azhqe4oqhh = look1_binlxpw ( _rtB ->
lnmufeoaot , _rtP -> P_418 , _rtP -> P_417 , 18U ) ; _rtB -> i5h1ixpfvw =
look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> pxvkc2esah , _rtP -> P_425 ,
_rtP -> P_426 , _rtP -> P_424 , _rtP -> P_1607 , 19U ) ; _rtB -> ckvjrubuxv =
look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> atpm0s2bpo , _rtP -> P_433 ,
_rtP -> P_434 , _rtP -> P_432 , _rtP -> P_1608 , 19U ) ; _rtB -> ebgtebkzgi =
look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> j3g4x1bbri , _rtP -> P_441 ,
_rtP -> P_442 , _rtP -> P_440 , _rtP -> P_1609 , 19U ) ; _rtB -> h5acziuybj =
look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> cs301wf1ne , _rtP -> P_449 ,
_rtP -> P_450 , _rtP -> P_448 , _rtP -> P_1610 , 19U ) ; _rtB -> gmorjp5clw =
( ( ( _rtB -> azhqe4oqhh + _rtB -> i5h1ixpfvw ) + _rtB -> ckvjrubuxv ) + _rtB
-> ebgtebkzgi ) + _rtB -> h5acziuybj ; _rtB -> nxqxmf3cwm = look2_binlxpw (
_rtB -> lnmufeoaot , _rtB -> pxvkc2esah , _rtP -> P_452 , _rtP -> P_453 ,
_rtP -> P_451 , _rtP -> P_1611 , 19U ) ; _rtB -> j5bqrzvzbf = look2_binlxpw (
_rtB -> lnmufeoaot , _rtB -> atpm0s2bpo , _rtP -> P_455 , _rtP -> P_456 ,
_rtP -> P_454 , _rtP -> P_1612 , 19U ) ; _rtB -> p2f0eku2lx = look2_binlxpw (
_rtB -> lnmufeoaot , _rtB -> cs301wf1ne , _rtP -> P_458 , _rtP -> P_459 ,
_rtP -> P_457 , _rtP -> P_1613 , 19U ) ; _rtB -> ljfzoy5spt = ( _rtB ->
nxqxmf3cwm + _rtB -> j5bqrzvzbf ) + _rtB -> p2f0eku2lx ; _rtB -> pbcce25uvk =
look1_binlxpw ( _rtB -> lnmufeoaot , _rtP -> P_461 , _rtP -> P_460 , 18U ) ;
_rtB -> crkf0mzcfy = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> pxvkc2esah
, _rtP -> P_463 , _rtP -> P_464 , _rtP -> P_462 , _rtP -> P_1614 , 19U ) ;
_rtB -> mdkurmlmmm = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> atpm0s2bpo
, _rtP -> P_466 , _rtP -> P_467 , _rtP -> P_465 , _rtP -> P_1615 , 19U ) ;
_rtB -> cblx2uorqb = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> j3g4x1bbri
, _rtP -> P_469 , _rtP -> P_470 , _rtP -> P_468 , _rtP -> P_1616 , 19U ) ;
_rtB -> aijpt2qjtr = ( ( _rtB -> pbcce25uvk + _rtB -> crkf0mzcfy ) + _rtB ->
mdkurmlmmm ) + _rtB -> cblx2uorqb ; _rtB -> bz1czmln35 = look2_binlxpw ( _rtB
-> lnmufeoaot , _rtB -> pxvkc2esah , _rtP -> P_472 , _rtP -> P_473 , _rtP ->
P_471 , _rtP -> P_1617 , 19U ) ; _rtB -> mc0abdol4w = look2_binlxpw ( _rtB ->
lnmufeoaot , _rtB -> atpm0s2bpo , _rtP -> P_475 , _rtP -> P_476 , _rtP ->
P_474 , _rtP -> P_1618 , 19U ) ; _rtB -> okr1gjvqde = look2_binlxpw ( _rtB ->
lnmufeoaot , _rtB -> cs301wf1ne , _rtP -> P_478 , _rtP -> P_479 , _rtP ->
P_477 , _rtP -> P_1619 , 19U ) ; _rtB -> fdxqwnotmw = ( _rtB -> bz1czmln35 +
_rtB -> mc0abdol4w ) + _rtB -> okr1gjvqde ; _rtB -> e4f4vnqyk1 =
look1_binlxpw ( _rtB -> lnmufeoaot , _rtP -> P_481 , _rtP -> P_480 , 18U ) ;
_rtB -> dxfl3elxua = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> j3g4x1bbri
, _rtP -> P_483 , _rtP -> P_484 , _rtP -> P_482 , _rtP -> P_1620 , 19U ) ;
_rtB -> hj5hil5hql = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> pxvkc2esah
, _rtP -> P_486 , _rtP -> P_487 , _rtP -> P_485 , _rtP -> P_1621 , 19U ) ;
_rtB -> bbibbid5ri = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> atpm0s2bpo
, _rtP -> P_489 , _rtP -> P_490 , _rtP -> P_488 , _rtP -> P_1622 , 19U ) ;
_rtB -> fkpmd4hnjr = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> cs301wf1ne
, _rtP -> P_492 , _rtP -> P_493 , _rtP -> P_491 , _rtP -> P_1623 , 19U ) ;
_rtB -> dp3wmp11cz = ( ( ( _rtB -> e4f4vnqyk1 + _rtB -> dxfl3elxua ) + _rtB
-> hj5hil5hql ) + _rtB -> bbibbid5ri ) + _rtB -> fkpmd4hnjr ; _rtB ->
fmmitectim = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> pxvkc2esah , _rtP
-> P_495 , _rtP -> P_496 , _rtP -> P_494 , _rtP -> P_1624 , 19U ) ; _rtB ->
jaclopnmne = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> atpm0s2bpo , _rtP
-> P_498 , _rtP -> P_499 , _rtP -> P_497 , _rtP -> P_1625 , 19U ) ; _rtB ->
p1i50d355r = look2_binlxpw ( _rtB -> lnmufeoaot , _rtB -> cs301wf1ne , _rtP
-> P_501 , _rtP -> P_502 , _rtP -> P_500 , _rtP -> P_1626 , 19U ) ; _rtB ->
j24504qbid = ( _rtB -> fmmitectim + _rtB -> jaclopnmne ) + _rtB -> p1i50d355r
; _rtB -> hhflzzutxy = _rtB -> j5lpxvsb0a * _rtB -> jhdvplz132 ; if ( _rtB ->
hhflzzutxy > _rtP -> P_504 ) { _rtB -> ic3qnxehbt = _rtP -> P_504 ; } else if
( _rtB -> hhflzzutxy < _rtP -> P_505 ) { _rtB -> ic3qnxehbt = _rtP -> P_505 ;
} else { _rtB -> ic3qnxehbt = _rtB -> hhflzzutxy ; } _rtB -> pddqyory14 =
look1_binlxpw ( _rtB -> ic3qnxehbt , _rtP -> P_507 , _rtP -> P_506 , 18U ) ;
_rtB -> ashi4d3qa2 = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> apgogzarvh
, _rtP -> P_514 , _rtP -> P_515 , _rtP -> P_513 , _rtP -> P_1627 , 19U ) ;
_rtB -> ksphsu2wwv = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> iole1shodp
, _rtP -> P_522 , _rtP -> P_523 , _rtP -> P_521 , _rtP -> P_1628 , 19U ) ;
_rtB -> eaiyz1otav = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> l5cdujkwj1
, _rtP -> P_530 , _rtP -> P_531 , _rtP -> P_529 , _rtP -> P_1629 , 19U ) ;
_rtB -> mrgzl5vdya = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> g1wyyzl2kt
, _rtP -> P_538 , _rtP -> P_539 , _rtP -> P_537 , _rtP -> P_1630 , 19U ) ;
_rtB -> bcb345pxrq = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> mjolrwowzq
, _rtP -> P_546 , _rtP -> P_547 , _rtP -> P_545 , _rtP -> P_1631 , 19U ) ;
_rtB -> pbtor20vvt = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> bcnlk0vhr4
, _rtP -> P_554 , _rtP -> P_555 , _rtP -> P_553 , _rtP -> P_1632 , 19U ) ;
_rtB -> naq324cgs1 = ( ( ( ( ( _rtB -> pddqyory14 + _rtB -> ashi4d3qa2 ) +
_rtB -> ksphsu2wwv ) + _rtB -> eaiyz1otav ) + _rtB -> mrgzl5vdya ) + _rtB ->
bcb345pxrq ) + _rtB -> pbtor20vvt ; _rtB -> npjhhlqohk = look2_binlxpw ( _rtB
-> ic3qnxehbt , _rtB -> apgogzarvh , _rtP -> P_557 , _rtP -> P_558 , _rtP ->
P_556 , _rtP -> P_1633 , 19U ) ; _rtB -> cw0qkubtrs = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> iole1shodp , _rtP -> P_560 , _rtP -> P_561 , _rtP ->
P_559 , _rtP -> P_1634 , 19U ) ; _rtB -> izsqa0ikzj = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> l5cdujkwj1 , _rtP -> P_563 , _rtP -> P_564 , _rtP ->
P_562 , _rtP -> P_1635 , 19U ) ; _rtB -> ldiyqwp2wk = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> g1wyyzl2kt , _rtP -> P_566 , _rtP -> P_567 , _rtP ->
P_565 , _rtP -> P_1636 , 19U ) ; _rtB -> gkikgj04lu = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> bcnlk0vhr4 , _rtP -> P_569 , _rtP -> P_570 , _rtP ->
P_568 , _rtP -> P_1637 , 19U ) ; _rtB -> aewrbsro0l = ( ( ( _rtB ->
npjhhlqohk + _rtB -> cw0qkubtrs ) + _rtB -> izsqa0ikzj ) + _rtB -> ldiyqwp2wk
) + _rtB -> gkikgj04lu ; _rtB -> e2nng42j3w = look1_binlxpw ( _rtB ->
ic3qnxehbt , _rtP -> P_572 , _rtP -> P_571 , 18U ) ; _rtB -> pxwfml4e5e =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> mjolrwowzq , _rtP -> P_574 ,
_rtP -> P_575 , _rtP -> P_573 , _rtP -> P_1638 , 19U ) ; _rtB -> htsp5mj45a =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> apgogzarvh , _rtP -> P_577 ,
_rtP -> P_578 , _rtP -> P_576 , _rtP -> P_1639 , 19U ) ; _rtB -> exxovyydsv =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> iole1shodp , _rtP -> P_580 ,
_rtP -> P_581 , _rtP -> P_579 , _rtP -> P_1640 , 19U ) ; _rtB -> cxoiejocml =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> l5cdujkwj1 , _rtP -> P_583 ,
_rtP -> P_584 , _rtP -> P_582 , _rtP -> P_1641 , 19U ) ; _rtB -> f1iz0jki0r =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> g1wyyzl2kt , _rtP -> P_586 ,
_rtP -> P_587 , _rtP -> P_585 , _rtP -> P_1642 , 19U ) ; _rtB -> mrk2dtjxrf =
look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> bcnlk0vhr4 , _rtP -> P_589 ,
_rtP -> P_590 , _rtP -> P_588 , _rtP -> P_1643 , 19U ) ; _rtB -> hi33daxjbi =
( ( ( ( ( _rtB -> e2nng42j3w + _rtB -> pxwfml4e5e ) + _rtB -> htsp5mj45a ) +
_rtB -> exxovyydsv ) + _rtB -> cxoiejocml ) + _rtB -> f1iz0jki0r ) + _rtB ->
mrk2dtjxrf ; _rtB -> bll4y1lewk = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB
-> apgogzarvh , _rtP -> P_592 , _rtP -> P_593 , _rtP -> P_591 , _rtP ->
P_1644 , 19U ) ; _rtB -> b1ahz3qp4k = look2_binlxpw ( _rtB -> ic3qnxehbt ,
_rtB -> iole1shodp , _rtP -> P_595 , _rtP -> P_596 , _rtP -> P_594 , _rtP ->
P_1645 , 19U ) ; _rtB -> olt04qjzso = look2_binlxpw ( _rtB -> ic3qnxehbt ,
_rtB -> bcnlk0vhr4 , _rtP -> P_598 , _rtP -> P_599 , _rtP -> P_597 , _rtP ->
P_1646 , 19U ) ; _rtB -> miro43y5oe = look2_binlxpw ( _rtB -> ic3qnxehbt ,
_rtB -> l5cdujkwj1 , _rtP -> P_601 , _rtP -> P_602 , _rtP -> P_600 , _rtP ->
P_1647 , 19U ) ; _rtB -> gl05lxj1ps = look2_binlxpw ( _rtB -> ic3qnxehbt ,
_rtB -> g1wyyzl2kt , _rtP -> P_604 , _rtP -> P_605 , _rtP -> P_603 , _rtP ->
P_1648 , 19U ) ; _rtB -> nr4lihjyh3 = ( ( ( _rtB -> bll4y1lewk + _rtB ->
b1ahz3qp4k ) + _rtB -> olt04qjzso ) + _rtB -> miro43y5oe ) + _rtB ->
gl05lxj1ps ; _rtB -> bmso5mjpmr = look1_binlxpw ( _rtB -> ic3qnxehbt , _rtP
-> P_607 , _rtP -> P_606 , 18U ) ; _rtB -> ey5gpvth35 = look2_binlxpw ( _rtB
-> ic3qnxehbt , _rtB -> mjolrwowzq , _rtP -> P_609 , _rtP -> P_610 , _rtP ->
P_608 , _rtP -> P_1649 , 19U ) ; _rtB -> hgdbptudsa = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> apgogzarvh , _rtP -> P_612 , _rtP -> P_613 , _rtP ->
P_611 , _rtP -> P_1650 , 19U ) ; _rtB -> abzyzf2ech = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> iole1shodp , _rtP -> P_615 , _rtP -> P_616 , _rtP ->
P_614 , _rtP -> P_1651 , 19U ) ; _rtB -> nuwvc0tqm2 = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> l5cdujkwj1 , _rtP -> P_618 , _rtP -> P_619 , _rtP ->
P_617 , _rtP -> P_1652 , 19U ) ; _rtB -> h5sv42vlln = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> g1wyyzl2kt , _rtP -> P_621 , _rtP -> P_622 , _rtP ->
P_620 , _rtP -> P_1653 , 19U ) ; _rtB -> j0ubpzmd2p = look2_binlxpw ( _rtB ->
ic3qnxehbt , _rtB -> bcnlk0vhr4 , _rtP -> P_624 , _rtP -> P_625 , _rtP ->
P_623 , _rtP -> P_1654 , 19U ) ; _rtB -> mdoccre1zw = ( ( ( ( ( _rtB ->
bmso5mjpmr + _rtB -> ey5gpvth35 ) + _rtB -> hgdbptudsa ) + _rtB -> abzyzf2ech
) + _rtB -> nuwvc0tqm2 ) + _rtB -> h5sv42vlln ) + _rtB -> j0ubpzmd2p ; _rtB
-> jc5xj4qmkf = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> apgogzarvh ,
_rtP -> P_627 , _rtP -> P_628 , _rtP -> P_626 , _rtP -> P_1655 , 19U ) ; _rtB
-> lcv25bivjn = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> iole1shodp ,
_rtP -> P_630 , _rtP -> P_631 , _rtP -> P_629 , _rtP -> P_1656 , 19U ) ; _rtB
-> cs4wwt4v42 = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> bcnlk0vhr4 ,
_rtP -> P_633 , _rtP -> P_634 , _rtP -> P_632 , _rtP -> P_1657 , 19U ) ; _rtB
-> jmgs10tzbs = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> l5cdujkwj1 ,
_rtP -> P_636 , _rtP -> P_637 , _rtP -> P_635 , _rtP -> P_1658 , 19U ) ; _rtB
-> bogdvpbpdg = look2_binlxpw ( _rtB -> ic3qnxehbt , _rtB -> g1wyyzl2kt ,
_rtP -> P_639 , _rtP -> P_640 , _rtP -> P_638 , _rtP -> P_1659 , 19U ) ; _rtB
-> ngoikf3rze = ( ( ( _rtB -> jc5xj4qmkf + _rtB -> lcv25bivjn ) + _rtB ->
cs4wwt4v42 ) + _rtB -> jmgs10tzbs ) + _rtB -> bogdvpbpdg ; _rtB -> ofbjdv240i
[ 6 ] = _rtB -> gmorjp5clw - _rtB -> naq324cgs1 ; _rtB -> ofbjdv240i [ 7 ] =
_rtB -> ljfzoy5spt - _rtB -> aewrbsro0l ; _rtB -> ofbjdv240i [ 8 ] = _rtB ->
aijpt2qjtr - _rtB -> hi33daxjbi ; _rtB -> ofbjdv240i [ 9 ] = _rtB ->
fdxqwnotmw - _rtB -> nr4lihjyh3 ; _rtB -> ofbjdv240i [ 10 ] = _rtB ->
dp3wmp11cz - _rtB -> mdoccre1zw ; _rtB -> ofbjdv240i [ 11 ] = _rtB ->
j24504qbid - _rtB -> ngoikf3rze ; _rtB -> p1wbk0jiob = _rtB -> j5lpxvsb0a *
_rtB -> ir0cxkmh0q ; if ( _rtB -> p1wbk0jiob > _rtP -> P_642 ) { _rtB ->
ojxn4dgzpc = _rtP -> P_642 ; } else if ( _rtB -> p1wbk0jiob < _rtP -> P_643 )
{ _rtB -> ojxn4dgzpc = _rtP -> P_643 ; } else { _rtB -> ojxn4dgzpc = _rtB ->
p1wbk0jiob ; } _rtB -> lays3mk3qq = look1_binlxpw ( _rtB -> ojxn4dgzpc , _rtP
-> P_645 , _rtP -> P_644 , 18U ) ; _rtB -> kyymhwmilq = look2_binlxpw ( _rtB
-> ojxn4dgzpc , _rtB -> ate4sawz24 , _rtP -> P_650 , _rtP -> P_651 , _rtP ->
P_649 , _rtP -> P_1660 , 19U ) ; _rtB -> bxinmryg2r = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> kwh0pijov4 , _rtP -> P_656 , _rtP -> P_657 , _rtP ->
P_655 , _rtP -> P_1661 , 19U ) ; _rtB -> dmsz4b3uy4 = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> b0a5ga4jkg , _rtP -> P_662 , _rtP -> P_663 , _rtP ->
P_661 , _rtP -> P_1662 , 19U ) ; _rtB -> fieyuyuij5 = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> hi45iwvudw , _rtP -> P_668 , _rtP -> P_669 , _rtP ->
P_667 , _rtP -> P_1663 , 19U ) ; _rtB -> nijuida2ul = ( ( ( _rtB ->
lays3mk3qq + _rtB -> kyymhwmilq ) + _rtB -> bxinmryg2r ) + _rtB -> dmsz4b3uy4
) + _rtB -> fieyuyuij5 ; _rtB -> kzfqskcfck = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> ate4sawz24 , _rtP -> P_671 , _rtP -> P_672 , _rtP ->
P_670 , _rtP -> P_1664 , 19U ) ; _rtB -> hi1v0oopsj = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> kwh0pijov4 , _rtP -> P_674 , _rtP -> P_675 , _rtP ->
P_673 , _rtP -> P_1665 , 19U ) ; _rtB -> nk0pvzd2kn = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> hi45iwvudw , _rtP -> P_677 , _rtP -> P_678 , _rtP ->
P_676 , _rtP -> P_1666 , 19U ) ; _rtB -> pjkt2ho54x = ( _rtB -> kzfqskcfck +
_rtB -> hi1v0oopsj ) + _rtB -> nk0pvzd2kn ; _rtB -> mvokbhjtdp =
look1_binlxpw ( _rtB -> ojxn4dgzpc , _rtP -> P_680 , _rtP -> P_679 , 18U ) ;
_rtB -> juaaemgr3c = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> ate4sawz24
, _rtP -> P_682 , _rtP -> P_683 , _rtP -> P_681 , _rtP -> P_1667 , 19U ) ;
_rtB -> emuvhgue3h = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> kwh0pijov4
, _rtP -> P_685 , _rtP -> P_686 , _rtP -> P_684 , _rtP -> P_1668 , 19U ) ;
_rtB -> l4112dgxpy = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> b0a5ga4jkg
, _rtP -> P_688 , _rtP -> P_689 , _rtP -> P_687 , _rtP -> P_1669 , 19U ) ;
_rtB -> ijnj4pmlsn = ( ( _rtB -> mvokbhjtdp + _rtB -> juaaemgr3c ) + _rtB ->
emuvhgue3h ) + _rtB -> l4112dgxpy ; _rtB -> j4qga0e4n0 = look2_binlxpw ( _rtB
-> ojxn4dgzpc , _rtB -> ate4sawz24 , _rtP -> P_691 , _rtP -> P_692 , _rtP ->
P_690 , _rtP -> P_1670 , 19U ) ; _rtB -> f4omipt0rl = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> kwh0pijov4 , _rtP -> P_694 , _rtP -> P_695 , _rtP ->
P_693 , _rtP -> P_1671 , 19U ) ; _rtB -> ewwv2rwfvq = look2_binlxpw ( _rtB ->
ojxn4dgzpc , _rtB -> hi45iwvudw , _rtP -> P_697 , _rtP -> P_698 , _rtP ->
P_696 , _rtP -> P_1672 , 19U ) ; _rtB -> o0rap52jzu = ( _rtB -> j4qga0e4n0 +
_rtB -> f4omipt0rl ) + _rtB -> ewwv2rwfvq ; _rtB -> dfiw1vvi2j =
look1_binlxpw ( _rtB -> ojxn4dgzpc , _rtP -> P_700 , _rtP -> P_699 , 18U ) ;
_rtB -> lcmwghouvs = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> b0a5ga4jkg
, _rtP -> P_702 , _rtP -> P_703 , _rtP -> P_701 , _rtP -> P_1673 , 19U ) ;
_rtB -> luatxpjn0e = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> ate4sawz24
, _rtP -> P_705 , _rtP -> P_706 , _rtP -> P_704 , _rtP -> P_1674 , 19U ) ;
_rtB -> mc2lmiei0y = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> kwh0pijov4
, _rtP -> P_708 , _rtP -> P_709 , _rtP -> P_707 , _rtP -> P_1675 , 19U ) ;
_rtB -> gnxfewqqn2 = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> hi45iwvudw
, _rtP -> P_711 , _rtP -> P_712 , _rtP -> P_710 , _rtP -> P_1676 , 19U ) ;
_rtB -> iz15eplmtg = ( ( ( _rtB -> dfiw1vvi2j + _rtB -> lcmwghouvs ) + _rtB
-> luatxpjn0e ) + _rtB -> mc2lmiei0y ) + _rtB -> gnxfewqqn2 ; _rtB ->
af14b3r3ck = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> ate4sawz24 , _rtP
-> P_714 , _rtP -> P_715 , _rtP -> P_713 , _rtP -> P_1677 , 19U ) ; _rtB ->
c33wfvo5f4 = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> kwh0pijov4 , _rtP
-> P_717 , _rtP -> P_718 , _rtP -> P_716 , _rtP -> P_1678 , 19U ) ; _rtB ->
nmx5ecphqt = look2_binlxpw ( _rtB -> ojxn4dgzpc , _rtB -> hi45iwvudw , _rtP
-> P_720 , _rtP -> P_721 , _rtP -> P_719 , _rtP -> P_1679 , 19U ) ; _rtB ->
ha2vqgxmih = ( _rtB -> af14b3r3ck + _rtB -> c33wfvo5f4 ) + _rtB -> nmx5ecphqt
; _rtB -> dbjdkesve2 = _rtB -> j5lpxvsb0a * _rtB -> doh5u2deoh ; if ( _rtB ->
dbjdkesve2 > _rtP -> P_723 ) { _rtB -> glj3kddfij = _rtP -> P_723 ; } else if
( _rtB -> dbjdkesve2 < _rtP -> P_724 ) { _rtB -> glj3kddfij = _rtP -> P_724 ;
} else { _rtB -> glj3kddfij = _rtB -> dbjdkesve2 ; } _rtB -> clmuba3030 =
look1_binlxpw ( _rtB -> glj3kddfij , _rtP -> P_726 , _rtP -> P_725 , 18U ) ;
_rtB -> cyq2rvpfvb = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> naxgzpywb4
, _rtP -> P_733 , _rtP -> P_734 , _rtP -> P_732 , _rtP -> P_1680 , 19U ) ;
_rtB -> akvntaelfh = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> pnb5nlrzkf
, _rtP -> P_741 , _rtP -> P_742 , _rtP -> P_740 , _rtP -> P_1681 , 19U ) ;
_rtB -> murmztgmdx = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dx0l0ewqmn
, _rtP -> P_749 , _rtP -> P_750 , _rtP -> P_748 , _rtP -> P_1682 , 19U ) ;
_rtB -> mvbogja13x = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dybezoc5vx
, _rtP -> P_757 , _rtP -> P_758 , _rtP -> P_756 , _rtP -> P_1683 , 19U ) ;
_rtB -> btu0cony3p = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> elaq1ggwed
, _rtP -> P_765 , _rtP -> P_766 , _rtP -> P_764 , _rtP -> P_1684 , 19U ) ;
_rtB -> fhd0en01v2 = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> a0hbuevd0n
, _rtP -> P_773 , _rtP -> P_774 , _rtP -> P_772 , _rtP -> P_1685 , 19U ) ;
_rtB -> ne5qpbnepj = ( ( ( ( ( _rtB -> clmuba3030 + _rtB -> cyq2rvpfvb ) +
_rtB -> akvntaelfh ) + _rtB -> murmztgmdx ) + _rtB -> mvbogja13x ) + _rtB ->
btu0cony3p ) + _rtB -> fhd0en01v2 ; _rtB -> h32vddks0j = look2_binlxpw ( _rtB
-> glj3kddfij , _rtB -> naxgzpywb4 , _rtP -> P_776 , _rtP -> P_777 , _rtP ->
P_775 , _rtP -> P_1686 , 19U ) ; _rtB -> lg4ywsllj3 = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> pnb5nlrzkf , _rtP -> P_779 , _rtP -> P_780 , _rtP ->
P_778 , _rtP -> P_1687 , 19U ) ; _rtB -> dro5hebvko = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> dx0l0ewqmn , _rtP -> P_782 , _rtP -> P_783 , _rtP ->
P_781 , _rtP -> P_1688 , 19U ) ; _rtB -> gjyxfoawup = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> dybezoc5vx , _rtP -> P_785 , _rtP -> P_786 , _rtP ->
P_784 , _rtP -> P_1689 , 19U ) ; _rtB -> cjp1edwcfn = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> a0hbuevd0n , _rtP -> P_788 , _rtP -> P_789 , _rtP ->
P_787 , _rtP -> P_1690 , 19U ) ; _rtB -> gs5qyxqrwk = ( ( ( _rtB ->
h32vddks0j + _rtB -> lg4ywsllj3 ) + _rtB -> dro5hebvko ) + _rtB -> gjyxfoawup
) + _rtB -> cjp1edwcfn ; _rtB -> hns5lfvf2u = look1_binlxpw ( _rtB ->
glj3kddfij , _rtP -> P_791 , _rtP -> P_790 , 18U ) ; _rtB -> gszc43kbbv =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> elaq1ggwed , _rtP -> P_793 ,
_rtP -> P_794 , _rtP -> P_792 , _rtP -> P_1691 , 19U ) ; _rtB -> gmwcedlj2e =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> naxgzpywb4 , _rtP -> P_796 ,
_rtP -> P_797 , _rtP -> P_795 , _rtP -> P_1692 , 19U ) ; _rtB -> jgojckzpjq =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> pnb5nlrzkf , _rtP -> P_799 ,
_rtP -> P_800 , _rtP -> P_798 , _rtP -> P_1693 , 19U ) ; _rtB -> dxmjqwrts0 =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dx0l0ewqmn , _rtP -> P_802 ,
_rtP -> P_803 , _rtP -> P_801 , _rtP -> P_1694 , 19U ) ; _rtB -> hgg1f3dfp1 =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dybezoc5vx , _rtP -> P_805 ,
_rtP -> P_806 , _rtP -> P_804 , _rtP -> P_1695 , 19U ) ; _rtB -> l3h2pmfwbf =
look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> a0hbuevd0n , _rtP -> P_808 ,
_rtP -> P_809 , _rtP -> P_807 , _rtP -> P_1696 , 19U ) ; _rtB -> gizuwcmq2m =
( ( ( ( ( _rtB -> hns5lfvf2u + _rtB -> gszc43kbbv ) + _rtB -> gmwcedlj2e ) +
_rtB -> jgojckzpjq ) + _rtB -> dxmjqwrts0 ) + _rtB -> hgg1f3dfp1 ) + _rtB ->
l3h2pmfwbf ; _rtB -> gmenpnpz5q = look2_binlxpw ( _rtB -> glj3kddfij , _rtB
-> naxgzpywb4 , _rtP -> P_811 , _rtP -> P_812 , _rtP -> P_810 , _rtP ->
P_1697 , 19U ) ; _rtB -> ffssme5lux = look2_binlxpw ( _rtB -> glj3kddfij ,
_rtB -> pnb5nlrzkf , _rtP -> P_814 , _rtP -> P_815 , _rtP -> P_813 , _rtP ->
P_1698 , 19U ) ; _rtB -> ovf4ci3t1n = look2_binlxpw ( _rtB -> glj3kddfij ,
_rtB -> a0hbuevd0n , _rtP -> P_817 , _rtP -> P_818 , _rtP -> P_816 , _rtP ->
P_1699 , 19U ) ; _rtB -> hhd3l5uzbd = look2_binlxpw ( _rtB -> glj3kddfij ,
_rtB -> dx0l0ewqmn , _rtP -> P_820 , _rtP -> P_821 , _rtP -> P_819 , _rtP ->
P_1700 , 19U ) ; _rtB -> fgrfa0bdpn = look2_binlxpw ( _rtB -> glj3kddfij ,
_rtB -> dybezoc5vx , _rtP -> P_823 , _rtP -> P_824 , _rtP -> P_822 , _rtP ->
P_1701 , 19U ) ; _rtB -> eg0ca5iyoo = ( ( ( _rtB -> gmenpnpz5q + _rtB ->
ffssme5lux ) + _rtB -> ovf4ci3t1n ) + _rtB -> hhd3l5uzbd ) + _rtB ->
fgrfa0bdpn ; _rtB -> dv50pvb4uc = look1_binlxpw ( _rtB -> glj3kddfij , _rtP
-> P_826 , _rtP -> P_825 , 18U ) ; _rtB -> fk1h4jlqcf = look2_binlxpw ( _rtB
-> glj3kddfij , _rtB -> elaq1ggwed , _rtP -> P_828 , _rtP -> P_829 , _rtP ->
P_827 , _rtP -> P_1702 , 19U ) ; _rtB -> cqicvwjypu = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> naxgzpywb4 , _rtP -> P_831 , _rtP -> P_832 , _rtP ->
P_830 , _rtP -> P_1703 , 19U ) ; _rtB -> endedeksxu = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> pnb5nlrzkf , _rtP -> P_834 , _rtP -> P_835 , _rtP ->
P_833 , _rtP -> P_1704 , 19U ) ; _rtB -> povu0r0c4h = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> dx0l0ewqmn , _rtP -> P_837 , _rtP -> P_838 , _rtP ->
P_836 , _rtP -> P_1705 , 19U ) ; _rtB -> deo32dozrt = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> dybezoc5vx , _rtP -> P_840 , _rtP -> P_841 , _rtP ->
P_839 , _rtP -> P_1706 , 19U ) ; _rtB -> nskjy0beny = look2_binlxpw ( _rtB ->
glj3kddfij , _rtB -> a0hbuevd0n , _rtP -> P_843 , _rtP -> P_844 , _rtP ->
P_842 , _rtP -> P_1707 , 19U ) ; _rtB -> h3mbntuyiy = ( ( ( ( ( _rtB ->
dv50pvb4uc + _rtB -> fk1h4jlqcf ) + _rtB -> cqicvwjypu ) + _rtB -> endedeksxu
) + _rtB -> povu0r0c4h ) + _rtB -> deo32dozrt ) + _rtB -> nskjy0beny ; _rtB
-> e1b3dfdobg = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> naxgzpywb4 ,
_rtP -> P_846 , _rtP -> P_847 , _rtP -> P_845 , _rtP -> P_1708 , 19U ) ; _rtB
-> frcjlyghbl = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> pnb5nlrzkf ,
_rtP -> P_849 , _rtP -> P_850 , _rtP -> P_848 , _rtP -> P_1709 , 19U ) ; _rtB
-> kmb14prtmp = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> a0hbuevd0n ,
_rtP -> P_852 , _rtP -> P_853 , _rtP -> P_851 , _rtP -> P_1710 , 19U ) ; _rtB
-> krfgnk205a = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dx0l0ewqmn ,
_rtP -> P_855 , _rtP -> P_856 , _rtP -> P_854 , _rtP -> P_1711 , 19U ) ; _rtB
-> ei5ae4efsd = look2_binlxpw ( _rtB -> glj3kddfij , _rtB -> dybezoc5vx ,
_rtP -> P_858 , _rtP -> P_859 , _rtP -> P_857 , _rtP -> P_1712 , 19U ) ; _rtB
-> l01wrh403v = ( ( ( _rtB -> e1b3dfdobg + _rtB -> frcjlyghbl ) + _rtB ->
kmb14prtmp ) + _rtB -> krfgnk205a ) + _rtB -> ei5ae4efsd ; _rtB -> ofbjdv240i
[ 12 ] = _rtB -> nijuida2ul - _rtB -> ne5qpbnepj ; _rtB -> ofbjdv240i [ 13 ]
= _rtB -> pjkt2ho54x - _rtB -> gs5qyxqrwk ; _rtB -> ofbjdv240i [ 14 ] = _rtB
-> ijnj4pmlsn - _rtB -> gizuwcmq2m ; _rtB -> ofbjdv240i [ 15 ] = _rtB ->
o0rap52jzu - _rtB -> eg0ca5iyoo ; _rtB -> ofbjdv240i [ 16 ] = _rtB ->
iz15eplmtg - _rtB -> h3mbntuyiy ; _rtB -> ofbjdv240i [ 17 ] = _rtB ->
ha2vqgxmih - _rtB -> l01wrh403v ; _rtB -> g1spufntqt [ 0 ] = _rtB ->
ofbjdv240i [ 0 ] ; _rtB -> g1spufntqt [ 1 ] = _rtB -> ofbjdv240i [ 6 ] ; _rtB
-> g1spufntqt [ 2 ] = _rtB -> ofbjdv240i [ 12 ] ;
AFCS_MODEL1_acc_LookUp_real_T_real_T ( & ( _rtB -> cbbkiuxgvm ) , & _rtB ->
g1spufntqt [ 0 ] , _rtB -> ekbuyfhagm , & _rtB -> jt1yxszwmh [ 0 ] , 2U ) ;
_rtB -> g1spufntqt [ 0 ] = _rtB -> ofbjdv240i [ 2 ] ; _rtB -> g1spufntqt [ 1
] = _rtB -> ofbjdv240i [ 8 ] ; _rtB -> g1spufntqt [ 2 ] = _rtB -> ofbjdv240i
[ 14 ] ; AFCS_MODEL1_acc_LookUp_real_T_real_T ( & ( _rtB -> d2qebzaiw1 ) , &
_rtB -> g1spufntqt [ 0 ] , _rtB -> ekbuyfhagm , & _rtB -> jt1yxszwmh [ 0 ] ,
2U ) ; _rtB -> g1spufntqt [ 0 ] = _rtB -> ofbjdv240i [ 4 ] ; _rtB ->
g1spufntqt [ 1 ] = _rtB -> ofbjdv240i [ 10 ] ; _rtB -> g1spufntqt [ 2 ] =
_rtB -> ofbjdv240i [ 16 ] ; AFCS_MODEL1_acc_LookUp_real_T_real_T ( & ( _rtB
-> pq3kigfgir ) , & _rtB -> g1spufntqt [ 0 ] , _rtB -> ekbuyfhagm , & _rtB ->
jt1yxszwmh [ 0 ] , 2U ) ; _rtB -> baes3vu2qr = _rtB -> j5lpxvsb0a * _rtB ->
ometiu4anf ; if ( _rtB -> baes3vu2qr > _rtP -> P_864 ) { _rtB -> iu1m41loex =
_rtP -> P_864 ; } else if ( _rtB -> baes3vu2qr < _rtP -> P_865 ) { _rtB ->
iu1m41loex = _rtP -> P_865 ; } else { _rtB -> iu1m41loex = _rtB -> baes3vu2qr
; } _rtB -> hamfgp5sea = _rtB -> djgboligtx * _rtB -> lztp3b3ite ; if ( _rtB
-> hamfgp5sea > _rtP -> P_867 ) { _rtB -> cwbwsniwck = _rtP -> P_867 ; } else
if ( _rtB -> hamfgp5sea < _rtP -> P_868 ) { _rtB -> cwbwsniwck = _rtP ->
P_868 ; } else { _rtB -> cwbwsniwck = _rtB -> hamfgp5sea ; } _rtB ->
a5tv20u5ur = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_870 , _rtP -> P_871 , _rtP -> P_869 , _rtP -> P_1713 , 19U ) ; _rtB ->
dzmjfv03xi = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_873 , _rtP -> P_874 , _rtP -> P_872 , _rtP -> P_1714 , 19U ) ; _rtB ->
bwsh5wisws = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_876 , _rtP -> P_877 , _rtP -> P_875 , _rtP -> P_1715 , 19U ) ; _rtB ->
og2pkfxp2c = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_879 , _rtP -> P_880 , _rtP -> P_878 , _rtP -> P_1716 , 19U ) ; _rtB ->
b1mhwwtvdk = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_882 , _rtP -> P_883 , _rtP -> P_881 , _rtP -> P_1717 , 19U ) ; _rtB ->
h33jsfuj0l = look2_binlxpw ( _rtB -> iu1m41loex , _rtB -> cwbwsniwck , _rtP
-> P_885 , _rtP -> P_886 , _rtP -> P_884 , _rtP -> P_1718 , 19U ) ; _rtB ->
g3mzwjzujn [ 0 ] = _rtB -> cbbkiuxgvm + _rtB -> a5tv20u5ur ; _rtB ->
g3mzwjzujn [ 1 ] = _rtB -> k25snxv2go + _rtB -> dzmjfv03xi ; _rtB ->
g3mzwjzujn [ 2 ] = _rtB -> d2qebzaiw1 + _rtB -> bwsh5wisws ; _rtB ->
g3mzwjzujn [ 3 ] = _rtB -> bm0mjxha4h + _rtB -> og2pkfxp2c ; _rtB ->
g3mzwjzujn [ 4 ] = _rtB -> pq3kigfgir + _rtB -> b1mhwwtvdk ; _rtB ->
g3mzwjzujn [ 5 ] = _rtB -> el1ckdfmje + _rtB -> h33jsfuj0l ; for ( i = 0 ; i
< 6 ; i ++ ) { _rtB -> g3mzwjzujn [ i ] *= _rtB -> nm2rwjmtgu ; _rtB ->
oemrsamsqh [ i ] += _rtB -> g3mzwjzujn [ i ] ; } _rtB -> np4qtvmynx = _rtP ->
P_888 * _rtB -> oemrsamsqh [ 0 ] ; _rtB -> ju2nyrht4d = _rtP -> P_890 * _rtB
-> oemrsamsqh [ 2 ] ; _rtB -> g1spufntqt [ 0 ] = _rtB -> np4qtvmynx ; _rtB ->
g1spufntqt [ 1 ] = _rtB -> mdxqqylize ; _rtB -> g1spufntqt [ 2 ] = _rtB ->
ju2nyrht4d ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> blv5w5yawy [ i ] = 0.0 ;
_rtB -> blv5w5yawy [ i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB -> g1spufntqt [ 0
] ; _rtB -> blv5w5yawy [ i ] += _rtB -> cqrf5uuv0t [ i + 3 ] * _rtB ->
g1spufntqt [ 1 ] ; _rtB -> blv5w5yawy [ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] *
_rtB -> g1spufntqt [ 2 ] ; tmp [ i + 3 ] = _rtB -> oemrsamsqh [ 3 + i ] ; }
tmp [ 0 ] = _rtB -> blv5w5yawy [ 0 ] ; tmp [ 1 ] = _rtB -> oemrsamsqh [ 1 ] ;
tmp [ 2 ] = _rtB -> blv5w5yawy [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB ->
oemrsamsqh [ i ] = tmp [ i ] ; } _rtB -> blv5w5yawy [ 0 ] = _rtP -> P_891 [ 0
] * _rtB -> oemrsamsqh [ 3 ] ; _rtB -> blv5w5yawy [ 0 ] *= _rtB -> psvcnamasx
; _rtB -> g1spufntqt [ 0 ] = _rtB -> oemrsamsqh [ 0 ] * _rtB -> psvcnamasx ;
_rtB -> blv5w5yawy [ 1 ] = _rtP -> P_891 [ 1 ] * _rtB -> oemrsamsqh [ 4 ] ;
_rtB -> blv5w5yawy [ 1 ] *= _rtB -> psvcnamasx ; _rtB -> g1spufntqt [ 1 ] =
_rtB -> oemrsamsqh [ 1 ] * _rtB -> psvcnamasx ; _rtB -> blv5w5yawy [ 2 ] =
_rtP -> P_891 [ 2 ] * _rtB -> oemrsamsqh [ 5 ] ; _rtB -> blv5w5yawy [ 2 ] *=
_rtB -> psvcnamasx ; _rtB -> g1spufntqt [ 2 ] = _rtB -> oemrsamsqh [ 2 ] *
_rtB -> psvcnamasx ; _rtB -> g3mzwjzujn [ 0 ] = _rtB -> hc5x3xtoyu [ 1 ] *
_rtB -> g1spufntqt [ 2 ] ; _rtB -> g3mzwjzujn [ 1 ] = _rtB -> hc5x3xtoyu [ 2
] * _rtB -> g1spufntqt [ 0 ] ; _rtB -> g3mzwjzujn [ 2 ] = _rtB -> hc5x3xtoyu
[ 0 ] * _rtB -> g1spufntqt [ 1 ] ; _rtB -> g3mzwjzujn [ 3 ] = _rtB ->
hc5x3xtoyu [ 2 ] * _rtB -> g1spufntqt [ 1 ] ; _rtB -> g3mzwjzujn [ 4 ] = _rtB
-> hc5x3xtoyu [ 0 ] * _rtB -> g1spufntqt [ 2 ] ; _rtB -> g3mzwjzujn [ 5 ] =
_rtB -> hc5x3xtoyu [ 1 ] * _rtB -> g1spufntqt [ 0 ] ; _rtB -> flvjjegwtm [ 0
] = _rtB -> g3mzwjzujn [ 0 ] - _rtB -> g3mzwjzujn [ 3 ] ; _rtB -> jbans5xopm
[ 0 ] = _rtB -> blv5w5yawy [ 0 ] + _rtB -> flvjjegwtm [ 0 ] ; _rtB ->
flvjjegwtm [ 1 ] = _rtB -> g3mzwjzujn [ 1 ] - _rtB -> g3mzwjzujn [ 4 ] ; _rtB
-> jbans5xopm [ 1 ] = _rtB -> blv5w5yawy [ 1 ] + _rtB -> flvjjegwtm [ 1 ] ;
_rtB -> flvjjegwtm [ 2 ] = _rtB -> g3mzwjzujn [ 2 ] - _rtB -> g3mzwjzujn [ 5
] ; _rtB -> jbans5xopm [ 2 ] = _rtB -> blv5w5yawy [ 2 ] + _rtB -> flvjjegwtm
[ 2 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 152 ,
776 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 777 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 778 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 779 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 780 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 781 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 782 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 783 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 784 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 785 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 786 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 787 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 788 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 789 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 790 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 791 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 792 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 793 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 794 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 795 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 796 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 797 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 798 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 799 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 800 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> ag2hwckw2e = _rtP -> P_898 * _rtB ->
mc2nkfth2u [ 7 ] ; tmp_i = _rtP -> P_899 / 2.0 ; if ( _rtB -> ag2hwckw2e <
_rtDW -> f2mgdridkq - tmp_i ) { _rtB -> hgr3hfctxj = _rtB -> ag2hwckw2e +
tmp_i ; } else if ( _rtB -> ag2hwckw2e <= _rtDW -> f2mgdridkq + tmp_i ) {
_rtB -> hgr3hfctxj = _rtDW -> f2mgdridkq ; } else { _rtB -> hgr3hfctxj = _rtB
-> ag2hwckw2e - tmp_i ; } _rtB -> k1xwqssrzn = _rtP -> P_901 * _rtB ->
cip3exm2yt [ 2 ] ; _rtB -> h30422l2pe = _rtB -> k1xwqssrzn ; _rtB ->
hhsv2t5x0o = _rtP -> P_902 * _rtB -> ip45w0pt0d [ 0 ] ; _rtB -> iv5whrzs4v =
_rtB -> hhsv2t5x0o ; _rtB -> exaxs52yye = _rtP -> P_903 * _rtB -> ip45w0pt0d
[ 1 ] ; _rtB -> lapmd4hzd2 = _rtB -> exaxs52yye ; _rtB -> jfyebtidb5 = _rtP
-> P_904 * _rtB -> biho35zqrj ; _rtB -> o35r2bitza = _rtB -> jfyebtidb5 ; for
( i = 0 ; i < 3 ; i ++ ) { _rtB -> cqrf5uuv0t [ 3 * i ] = _rtB -> n0ypjfdw1o
[ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3 * i ] = _rtB -> n0ypjfdw1o [ i + 3 ] ;
_rtB -> cqrf5uuv0t [ 2 + 3 * i ] = _rtB -> n0ypjfdw1o [ i + 6 ] ; } for ( i =
0 ; i < 3 ; i ++ ) { _rtB -> flvjjegwtm [ i ] = 0.0 ; _rtB -> blv5w5yawy [ i
] = 0.0 ; _rtB -> flvjjegwtm [ i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB ->
gxlqdjspys [ 0 ] ; _rtB -> blv5w5yawy [ i ] += _rtB -> df0qunjvqj [ i ] *
_rtB -> dzma4p13kw [ 0 ] ; _rtB -> flvjjegwtm [ i ] += _rtB -> cqrf5uuv0t [ i
+ 3 ] * _rtB -> gxlqdjspys [ 1 ] ; _rtB -> blv5w5yawy [ i ] += _rtB ->
df0qunjvqj [ i + 3 ] * _rtB -> dzma4p13kw [ 1 ] ; _rtB -> flvjjegwtm [ i ] +=
_rtB -> cqrf5uuv0t [ i + 6 ] * _rtB -> gxlqdjspys [ 2 ] ; _rtB -> blv5w5yawy
[ i ] += _rtB -> df0qunjvqj [ i + 6 ] * _rtB -> dzma4p13kw [ 2 ] ; } _rtB ->
bdi4cutj5c = _rtB -> flvjjegwtm [ 0 ] ; _rtB -> ljpjqcelwl = _rtB ->
flvjjegwtm [ 1 ] ; _rtB -> l2bqvf23sw = _rtB -> flvjjegwtm [ 2 ] ; _rtB ->
b51cvt3ztr = _rtP -> P_905 * _rtB -> cip3exm2yt [ 1 ] ; _rtB -> lo10nterd2 =
_rtB -> b51cvt3ztr ; _rtB -> meqk22yjuj = _rtP -> P_906 * _rtB -> pgkpwhbsc4
; _rtB -> mturxdyo12 = _rtB -> meqk22yjuj ; _rtB -> o5m2ysqkku = _rtP ->
P_907 * _rtB -> fylzvybqbu ; _rtB -> p0clgfvlwp = _rtB -> o5m2ysqkku ; _rtB
-> jvggai4dyf = _rtB -> iydo4ipsmn ; _rtB -> dmiw5yjto3 = _rtB -> jhde4x05sz
; _rtB -> n4mdoksbrv = _rtP -> P_908 * _rtB -> cip3exm2yt [ 0 ] ; _rtB ->
d3345ldqkc = _rtB -> n4mdoksbrv ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
cqrf5uuv0t [ 3 * i ] = _rtB -> n0ypjfdw1o [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3
* i ] = _rtB -> n0ypjfdw1o [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] =
_rtB -> n0ypjfdw1o [ i + 6 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
deth2igh2x [ i ] = 0.0 ; _rtB -> deth2igh2x [ i ] += _rtB -> cqrf5uuv0t [ i ]
* _rtB -> dlzh5xejq2 [ 0 ] ; _rtB -> deth2igh2x [ i ] += _rtB -> cqrf5uuv0t [
i + 3 ] * _rtB -> dlzh5xejq2 [ 1 ] ; _rtB -> deth2igh2x [ i ] += _rtB ->
cqrf5uuv0t [ i + 6 ] * _rtB -> dlzh5xejq2 [ 2 ] ; } _rtB -> jg1r4deb2t = _rtP
-> P_912 * _rtB -> ip45w0pt0d [ 0 ] ; _rtB -> k1k2vct1f5 = muDoubleScalarSin
( _rtB -> jg1r4deb2t ) ; _rtB -> b43n4tcdby = _rtB -> k1k2vct1f5 * _rtB ->
k1k2vct1f5 * _rtB -> nx5lcmjqng ; _rtB -> cjowa0aasb = _rtB -> crjqkvlr0e -
_rtB -> b43n4tcdby ; _rtB -> ogdyvczyl3 = muDoubleScalarSqrt ( _rtB ->
cjowa0aasb ) ; _rtB -> gmhfemswxi = _rtB -> hdzyk5vm2y / _rtB -> ogdyvczyl3 ;
_rtB -> gshkwo1mcj = _rtB -> gmhfemswxi + _rtB -> i1glyxlove ; _rtB ->
d24e5u0qzt = _rtB -> deth2igh2x [ 1 ] / _rtB -> gshkwo1mcj ; if ( ( _rtB ->
cjowa0aasb < 0.0 ) && ( _rtB -> nhhzzfrix1 > muDoubleScalarFloor ( _rtB ->
nhhzzfrix1 ) ) ) { _rtB -> kqdeh0txqk = - muDoubleScalarPower ( - _rtB ->
cjowa0aasb , _rtB -> nhhzzfrix1 ) ; } else { _rtB -> kqdeh0txqk =
muDoubleScalarPower ( _rtB -> cjowa0aasb , _rtB -> nhhzzfrix1 ) ; } _rtB ->
fbttlxu542 = _rtB -> ezm02ovdpr * _rtB -> aa0mufjvdk / _rtB -> kqdeh0txqk ;
_rtB -> e3lnyh5nhk = _rtB -> fbttlxu542 + _rtB -> i1glyxlove ; _rtB ->
oekot0v0p2 = _rtB -> deth2igh2x [ 0 ] / _rtB -> e3lnyh5nhk ; _rtB ->
proa1tr1n4 = _rtP -> P_918 * _rtB -> oekot0v0p2 ; _rtB -> k24ctcs3l3 =
muDoubleScalarTan ( _rtB -> jg1r4deb2t ) ; _rtB -> plizf0x35x = _rtB ->
d24e5u0qzt * _rtB -> k24ctcs3l3 ; _rtB -> ptr1i45bgn = _rtP -> P_919 * _rtB
-> plizf0x35x ; _rtB -> deth2igh2x [ 0 ] = _rtB -> d24e5u0qzt ; _rtB ->
deth2igh2x [ 1 ] = _rtB -> proa1tr1n4 ; _rtB -> deth2igh2x [ 2 ] = _rtB ->
ptr1i45bgn ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> f3c51yhebb [ i ] = 0.0 ;
_rtB -> f3c51yhebb [ i ] += _rtB -> n0ypjfdw1o [ i ] * _rtB -> deth2igh2x [ 0
] ; _rtB -> f3c51yhebb [ i ] += _rtB -> n0ypjfdw1o [ i + 3 ] * _rtB ->
deth2igh2x [ 1 ] ; _rtB -> f3c51yhebb [ i ] += _rtB -> n0ypjfdw1o [ i + 6 ] *
_rtB -> deth2igh2x [ 2 ] ; _rtB -> f3c51yhebb [ i ] += _rtB -> blv5w5yawy [ i
] ; _rtB -> ms0nr2ux2y [ i ] = _rtB -> n0y1zxxh2i [ i ] + _rtB -> f3c51yhebb
[ i ] ; } if ( _rtDW -> nxpmlabht5 != 0 ) { _rtX -> l3tdaf3wuy [ 0 ] = _rtB
-> ms0nr2ux2y [ 0 ] ; _rtX -> l3tdaf3wuy [ 1 ] = _rtB -> ms0nr2ux2y [ 1 ] ;
_rtX -> l3tdaf3wuy [ 2 ] = _rtB -> ms0nr2ux2y [ 2 ] ; } _rtB -> deth2igh2x [
0 ] = _rtX -> l3tdaf3wuy [ 0 ] ; _rtB -> f3c51yhebb [ 0 ] = _rtB ->
deth2igh2x [ 0 ] - _rtB -> f3c51yhebb [ 0 ] ; _rtB -> deth2igh2x [ 1 ] = _rtX
-> l3tdaf3wuy [ 1 ] ; _rtB -> f3c51yhebb [ 1 ] = _rtB -> deth2igh2x [ 1 ] -
_rtB -> f3c51yhebb [ 1 ] ; _rtB -> deth2igh2x [ 2 ] = _rtX -> l3tdaf3wuy [ 2
] ; _rtB -> f3c51yhebb [ 2 ] = _rtB -> deth2igh2x [ 2 ] - _rtB -> f3c51yhebb
[ 2 ] ; _rtB -> bswcsfkhdj = _rtP -> P_920 * _rtB -> f3c51yhebb [ 0 ] ; _rtB
-> apdipb5rvr = _rtB -> bswcsfkhdj ; _rtB -> gb2lvxh0ag = _rtP -> P_921 *
_rtB -> f3c51yhebb [ 1 ] ; _rtB -> nfbrahf0bs = _rtB -> gb2lvxh0ag ; _rtB ->
ooszmdnlz3 = _rtP -> P_922 * _rtB -> f3c51yhebb [ 2 ] ; _rtB -> kq2uh3cg4j =
_rtB -> ooszmdnlz3 ; _rtB -> kwlhbpqe3d [ 0 ] = _rtB -> hhsv2t5x0o ; _rtB ->
kwlhbpqe3d [ 1 ] = _rtB -> exaxs52yye ; _rtB -> kwlhbpqe3d [ 2 ] = _rtB ->
biho35zqrj ; _rtB -> bgkqbxy2fg = _rtB -> kwlhbpqe3d [ 0 ] ; _rtB ->
hurigmfecw = _rtP -> P_923 * _rtB -> bgkqbxy2fg ; _rtB -> prohi4xrdz = _rtB
-> kwlhbpqe3d [ 1 ] ; _rtB -> j24dszv5ia = _rtP -> P_924 * _rtB -> prohi4xrdz
; _rtB -> n24ynkhwtb = _rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> ixbugfutfx = _rtP
-> P_925 * _rtB -> n24ynkhwtb ; { int_T i ; real_T GM , opt_m2ft , deg2rad ;
real_T * phi_ptr , * height_ptr ; boolean_T phi_wrapped = false ; real_T *
phi = ( real_T * ) & _rtDW -> dfvhhken2l ; real_T * h = ( real_T * ) & _rtDW
-> chqj0zj2er ; height_ptr = ( real_T * ) & _rtB -> ixbugfutfx ; phi_ptr = (
real_T * ) & _rtB -> hurigmfecw ; opt_m2ft = 1.0 ; deg2rad = 1.0 ; GM = (
h1hb0k1w0x . faonqlq2ng == 0 ) ? WGS84_GM_DEF : WGS84_GM_PRM ; { for ( i = 0
; i < 1 ; i ++ ) { real_T fphi , pi_2 ; phi [ i ] = phi_ptr [ i ] * deg2rad ;
h [ i ] = height_ptr [ i ] / opt_m2ft ; if ( phi [ i ] > AERO_PI || phi [ i ]
< - AERO_PI ) { phi [ i ] = muDoubleScalarRem ( phi [ i ] + AERO_PI , 2.0 *
AERO_PI ) - AERO_PI ; } fphi = muDoubleScalarAbs ( phi [ i ] ) ; pi_2 =
AERO_PI / 2.0 ; if ( fphi > pi_2 ) { real_T sign = phi [ i ] / fphi ;
phi_wrapped = true ; phi [ i ] = sign * ( pi_2 - ( fphi - pi_2 ) ) ; } else {
phi_wrapped = false ; } } wgs84_taylor_series ( h , phi , opt_m2ft , & _rtB
-> b3d1ja4iju [ 2 ] , 1 ) ; _rtB -> b3d1ja4iju [ 0 ] = _rtDW -> mfrs3ujowr ;
_rtB -> b3d1ja4iju [ 1 ] = _rtDW -> mfrs3ujowr ; } } _rtB -> kwlhbpqe3d [ 0 ]
= _rtP -> P_927 * _rtB -> b3d1ja4iju [ 0 ] ; _rtB -> kwlhbpqe3d [ 1 ] = _rtP
-> P_927 * _rtB -> b3d1ja4iju [ 1 ] ; _rtB -> kwlhbpqe3d [ 2 ] = _rtP ->
P_927 * _rtB -> b3d1ja4iju [ 2 ] ; _rtB -> ik3t1fjxaw = _rtP -> P_930 * _rtB
-> hhsv2t5x0o ; _rtB -> lnoqigyfmi = muDoubleScalarSin ( _rtB -> ik3t1fjxaw )
; _rtB -> gzuow4tdfb = _rtB -> lnoqigyfmi * _rtB -> lnoqigyfmi ; _rtB ->
pwoxj3d051 = _rtB -> hrytix0j05 * _rtB -> gzuow4tdfb ; _rtB -> irl0zjvr3q =
_rtB -> mrvtkhj4gr - _rtB -> pwoxj3d051 ; _rtB -> hhcgy42plc = _rtB ->
irl0zjvr3q / _rtB -> ax45qbmn2q ; _rtB -> eh0voqwhie = _rtB -> flvjjegwtm [ 1
] * _rtB -> hhcgy42plc ; _rtB -> hrv4fzyhfv = _rtB -> lnoqigyfmi * _rtB ->
lnoqigyfmi ; _rtB -> lwdouxajff = _rtB -> caxkb2rdhl * _rtB -> hrv4fzyhfv ;
_rtB -> gqrzx0oamp = _rtP -> P_936 * _rtB -> lwdouxajff ; _rtB -> kxswkqfkhc
= ( _rtB -> ckpoqbckz3 + _rtB -> mxzktzm22b ) - _rtB -> gqrzx0oamp ; _rtB ->
ljugchfigw = _rtB -> kxswkqfkhc / _rtB -> ayzb03i5v1 ; _rtB -> badx14bxhn =
_rtB -> flvjjegwtm [ 0 ] * _rtB -> ljugchfigw ; _rtB -> ivqzqxlczl = _rtP ->
P_938 * _rtB -> badx14bxhn ; _rtB -> buvua0ekyl = muDoubleScalarTan ( _rtB ->
ik3t1fjxaw ) ; _rtB -> eugde0ttb1 = _rtB -> eh0voqwhie * _rtB -> buvua0ekyl ;
_rtB -> jjvksp0o2g = _rtP -> P_939 * _rtB -> eugde0ttb1 ; _rtB -> flvjjegwtm
[ 0 ] = _rtB -> eh0voqwhie ; _rtB -> flvjjegwtm [ 1 ] = _rtB -> ivqzqxlczl ;
_rtB -> flvjjegwtm [ 2 ] = _rtB -> jjvksp0o2g ; for ( i = 0 ; i < 3 ; i ++ )
{ _rtB -> ayyvcvl2i5 [ i ] = 0.0 ; _rtB -> o3ctrxffdt [ i ] = 0.0 ; _rtB ->
ayyvcvl2i5 [ i ] += _rtB -> n0ypjfdw1o [ i ] * _rtB -> kwlhbpqe3d [ 0 ] ;
_rtB -> o3ctrxffdt [ i ] += _rtB -> n0ypjfdw1o [ i ] * _rtB -> flvjjegwtm [ 0
] ; _rtB -> ayyvcvl2i5 [ i ] += _rtB -> n0ypjfdw1o [ i + 3 ] * _rtB ->
kwlhbpqe3d [ 1 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> n0ypjfdw1o [ i + 3 ] *
_rtB -> flvjjegwtm [ 1 ] ; _rtB -> ayyvcvl2i5 [ i ] += _rtB -> n0ypjfdw1o [ i
+ 6 ] * _rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB ->
n0ypjfdw1o [ i + 6 ] * _rtB -> flvjjegwtm [ 2 ] ; } for ( i = 0 ; i < 3 ; i
++ ) { _rtB -> flvjjegwtm [ i ] = 0.0 ; _rtB -> flvjjegwtm [ i ] += _rtB ->
fmw1ib5eoz [ i ] * _rtB -> jfwlh3hopz [ 0 ] ; _rtB -> flvjjegwtm [ i ] +=
_rtB -> fmw1ib5eoz [ i + 3 ] * _rtB -> jfwlh3hopz [ 1 ] ; _rtB -> flvjjegwtm
[ i ] += _rtB -> fmw1ib5eoz [ i + 6 ] * _rtB -> jfwlh3hopz [ 2 ] ; } for ( i
= 0 ; i < 3 ; i ++ ) { _rtB -> f42rmnrcue [ i ] = 0.0 ; _rtB -> f42rmnrcue [
i ] += _rtB -> n0ypjfdw1o [ i ] * _rtB -> flvjjegwtm [ 0 ] ; _rtB ->
f42rmnrcue [ i ] += _rtB -> n0ypjfdw1o [ i + 3 ] * _rtB -> flvjjegwtm [ 1 ] ;
_rtB -> f42rmnrcue [ i ] += _rtB -> n0ypjfdw1o [ i + 6 ] * _rtB -> flvjjegwtm
[ 2 ] ; _rtB -> f42rmnrcue [ i ] *= _rtP -> P_941 ; _rtB -> o3ctrxffdt [ i ]
+= _rtB -> f42rmnrcue [ i ] ; } _rtB -> g3mzwjzujn [ 0 ] = _rtB -> o3ctrxffdt
[ 1 ] * _rtB -> gxlqdjspys [ 2 ] ; _rtB -> g3mzwjzujn [ 1 ] = _rtB ->
o3ctrxffdt [ 2 ] * _rtB -> gxlqdjspys [ 0 ] ; _rtB -> g3mzwjzujn [ 2 ] = _rtB
-> o3ctrxffdt [ 0 ] * _rtB -> gxlqdjspys [ 1 ] ; _rtB -> g3mzwjzujn [ 3 ] =
_rtB -> o3ctrxffdt [ 2 ] * _rtB -> gxlqdjspys [ 1 ] ; _rtB -> g3mzwjzujn [ 4
] = _rtB -> o3ctrxffdt [ 0 ] * _rtB -> gxlqdjspys [ 2 ] ; _rtB -> g3mzwjzujn
[ 5 ] = _rtB -> o3ctrxffdt [ 1 ] * _rtB -> gxlqdjspys [ 0 ] ; _rtB ->
f42rmnrcue [ 0 ] = _rtB -> g3mzwjzujn [ 0 ] - _rtB -> g3mzwjzujn [ 3 ] ; _rtB
-> ayyvcvl2i5 [ 0 ] += _rtB -> f42rmnrcue [ 0 ] ; _rtB -> kwlhbpqe3d [ 0 ] *=
_rtB -> oneisjghjn ; _rtB -> f42rmnrcue [ 1 ] = _rtB -> g3mzwjzujn [ 1 ] -
_rtB -> g3mzwjzujn [ 4 ] ; _rtB -> ayyvcvl2i5 [ 1 ] += _rtB -> f42rmnrcue [ 1
] ; _rtB -> kwlhbpqe3d [ 1 ] *= _rtB -> oneisjghjn ; _rtB -> f42rmnrcue [ 2 ]
= _rtB -> g3mzwjzujn [ 2 ] - _rtB -> g3mzwjzujn [ 5 ] ; _rtB -> ayyvcvl2i5 [
2 ] += _rtB -> f42rmnrcue [ 2 ] ; _rtB -> kwlhbpqe3d [ 2 ] *= _rtB ->
oneisjghjn ; if ( _rtB -> bq3enfnjje > _rtP -> P_945 ) { _rtB -> lggibqt0yi =
_rtP -> P_945 ; } else if ( _rtB -> bq3enfnjje < _rtP -> P_946 ) { _rtB ->
lggibqt0yi = _rtP -> P_946 ; } else { _rtB -> lggibqt0yi = _rtB -> bq3enfnjje
; } _rtB -> dnqbpczydl = look1_binlxpw ( _rtB -> lggibqt0yi , _rtP -> P_948 ,
_rtP -> P_947 , 1U ) ; _rtB -> nivsncjhyn = _rtB -> cszh02bjuh * _rtB ->
dnqbpczydl ; _rtB -> fngc3xoal5 = _rtB -> dfr3xqna51 * _rtB -> nivsncjhyn *
_rtB -> idndsxfdoq ; _rtB -> d30vthhy5z = _rtB -> fngc3xoal5 ; _rtB ->
l4hdaov0k5 = _rtB -> nivsncjhyn * _rtB -> k0usjdu4zg ; _rtB -> ladddfvqoc =
_rtB -> dfr3xqna51 * _rtB -> nivsncjhyn * _rtB -> gwpeufmoux ; _rtB ->
jcidzwntor = _rtP -> P_951 * _rtB -> ladddfvqoc ; if ( _rtB -> monv2s5ujm >
_rtP -> P_955 ) { _rtB -> alamvphbhn = _rtP -> P_955 ; } else if ( _rtB ->
monv2s5ujm < _rtP -> P_956 ) { _rtB -> alamvphbhn = _rtP -> P_956 ; } else {
_rtB -> alamvphbhn = _rtB -> monv2s5ujm ; } _rtB -> ieffz3n42s =
look1_binlxpw ( _rtB -> alamvphbhn , _rtP -> P_958 , _rtP -> P_957 , 1U ) ;
_rtB -> aakfbm01js = _rtB -> beupwafkve * _rtB -> ieffz3n42s ; _rtB ->
ibq1c0nbkg = _rtB -> eu4gwkksjt * _rtB -> aakfbm01js * _rtB -> jbs3at0tih ;
_rtB -> oyyd3cbpdz = _rtB -> ibq1c0nbkg ; _rtB -> cuoswwuj52 = _rtB ->
aakfbm01js * _rtB -> aomahecexm ; _rtB -> cvewdk4ujq = _rtB -> eu4gwkksjt *
_rtB -> aakfbm01js * _rtB -> k4beb24i02 ; _rtB -> hj0qywhol1 = _rtP -> P_961
* _rtB -> cvewdk4ujq ; _rtB -> g3mzwjzujn [ 0 ] = _rtB -> d30vthhy5z + _rtB
-> oyyd3cbpdz ; _rtB -> g3mzwjzujn [ 1 ] = _rtB -> l4hdaov0k5 + _rtB ->
cuoswwuj52 ; _rtB -> g3mzwjzujn [ 2 ] = _rtB -> jcidzwntor + _rtB ->
hj0qywhol1 ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> f42rmnrcue [ i ] = 0.0 ;
_rtB -> f42rmnrcue [ i ] += _rtB -> n0ypjfdw1o [ i ] * _rtB -> kwlhbpqe3d [ 0
] ; _rtB -> f42rmnrcue [ i ] += _rtB -> n0ypjfdw1o [ i + 3 ] * _rtB ->
kwlhbpqe3d [ 1 ] ; _rtB -> f42rmnrcue [ i ] += _rtB -> n0ypjfdw1o [ i + 6 ] *
_rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> g3mzwjzujn [ i + 3 ] = _rtB -> el5uoqjree
[ i ] + _rtB -> mykeqgmrzq [ i ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> a5sgw3semq = _rtP -> P_964 * _rtB -> hdvi031ysj ; } _rtB ->
eiko2atnjr = _rtB -> iqbspnflb4 * _rtB -> gxlqdjspys [ 0 ] ; _rtB ->
lfqol1z3jd = _rtP -> P_968 * _rtB -> eiko2atnjr ; _rtB -> jsdammzyac =
muDoubleScalarExp ( _rtB -> lfqol1z3jd ) ; _rtB -> agssmjvzee = _rtB ->
hzah0n2sf4 * _rtB -> jsdammzyac ; _rtB -> cxqlwsxr0z = _rtB -> agssmjvzee * (
real_T ) _rtB -> pzep4bhyod ; _rtB -> obxm1p4bq1 = _rtB -> cxqlwsxr0z + _rtB
-> nirbpoli3q ; if ( _rtB -> gxlqdjspys [ 0 ] >= _rtP -> P_972 ) { _rtB ->
apq2tszf4x = _rtB -> dvskicmsxu ; } else { _rtB -> lvibd5hj31 = _rtB ->
gxlqdjspys [ 0 ] / _rtB -> oqqrievgsr ; _rtB -> apq2tszf4x = _rtB ->
lvibd5hj31 ; } _rtB -> g433v1434t = _rtB -> obxm1p4bq1 * _rtB -> apq2tszf4x ;
if ( _rtB -> g433v1434t > _rtP -> P_973 ) { _rtB -> a2na0wcqx3 = _rtP ->
P_973 ; } else if ( _rtB -> g433v1434t < _rtP -> P_974 ) { _rtB -> a2na0wcqx3
= _rtP -> P_974 ; } else { _rtB -> a2na0wcqx3 = _rtB -> g433v1434t ; } _rtB
-> giesk4c4uj = _rtB -> a2na0wcqx3 * _rtB -> a2na0wcqx3 ; _rtB -> bxyidrwhma
= _rtB -> nxrdljwvj2 - _rtB -> giesk4c4uj ; _rtB -> lgtjn4ncze =
muDoubleScalarSqrt ( _rtB -> bxyidrwhma ) ; _rtB -> o3ctrxffdt [ 0 ] = _rtB
-> cip3exm2yt [ 2 ] ; _rtB -> o3ctrxffdt [ 1 ] = _rtB -> cip3exm2yt [ 1 ] ;
_rtB -> o3ctrxffdt [ 2 ] = _rtB -> cxd0lvvcve ; muDoubleScalarSinCos ( _rtB
-> o3ctrxffdt [ 0 ] , & _rtB -> o3ctrxffdt [ 0 ] , & _rtB -> kwlhbpqe3d [ 0 ]
) ; muDoubleScalarSinCos ( _rtB -> o3ctrxffdt [ 1 ] , & _rtB -> o3ctrxffdt [
1 ] , & _rtB -> kwlhbpqe3d [ 1 ] ) ; muDoubleScalarSinCos ( _rtB ->
o3ctrxffdt [ 2 ] , & _rtB -> o3ctrxffdt [ 2 ] , & _rtB -> kwlhbpqe3d [ 2 ] )
; _rtB -> ef1qhnuulp [ 0 ] = _rtB -> kwlhbpqe3d [ 1 ] * _rtB -> kwlhbpqe3d [
2 ] ; _rtB -> kagu5ke1zp = _rtB -> kwlhbpqe3d [ 2 ] * _rtB -> o3ctrxffdt [ 0
] * _rtB -> o3ctrxffdt [ 1 ] ; _rtB -> ndxhosawat = _rtB -> o3ctrxffdt [ 2 ]
* _rtB -> kwlhbpqe3d [ 0 ] ; _rtB -> ef1qhnuulp [ 1 ] = _rtB -> kagu5ke1zp -
_rtB -> ndxhosawat ; _rtB -> jitevn0f52 = _rtB -> o3ctrxffdt [ 0 ] * _rtB ->
o3ctrxffdt [ 2 ] ; _rtB -> cx3rbwld1k = _rtB -> o3ctrxffdt [ 1 ] * _rtB ->
kwlhbpqe3d [ 0 ] * _rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> ef1qhnuulp [ 2 ] = _rtB
-> jitevn0f52 + _rtB -> cx3rbwld1k ; _rtB -> ef1qhnuulp [ 3 ] = _rtB ->
o3ctrxffdt [ 2 ] * _rtB -> kwlhbpqe3d [ 1 ] ; _rtB -> n0xnz500so = _rtB ->
o3ctrxffdt [ 0 ] * _rtB -> o3ctrxffdt [ 1 ] * _rtB -> o3ctrxffdt [ 2 ] ; _rtB
-> a4fvxmcz2d = _rtB -> kwlhbpqe3d [ 0 ] * _rtB -> kwlhbpqe3d [ 2 ] ; _rtB ->
ef1qhnuulp [ 4 ] = _rtB -> n0xnz500so + _rtB -> a4fvxmcz2d ; _rtB ->
getc5qtddt = _rtB -> o3ctrxffdt [ 1 ] * _rtB -> o3ctrxffdt [ 2 ] * _rtB ->
kwlhbpqe3d [ 0 ] ; _rtB -> chi0ih4yod = _rtB -> kwlhbpqe3d [ 2 ] * _rtB ->
o3ctrxffdt [ 0 ] ; _rtB -> ef1qhnuulp [ 5 ] = _rtB -> getc5qtddt - _rtB ->
chi0ih4yod ; _rtB -> ef1qhnuulp [ 6 ] = _rtP -> P_977 * _rtB -> o3ctrxffdt [
1 ] ; _rtB -> ef1qhnuulp [ 7 ] = _rtB -> o3ctrxffdt [ 0 ] * _rtB ->
kwlhbpqe3d [ 1 ] ; _rtB -> ef1qhnuulp [ 8 ] = _rtB -> kwlhbpqe3d [ 0 ] * _rtB
-> kwlhbpqe3d [ 1 ] ; _rtB -> kehx1dh4v2 = _rtB -> f3c51yhebb [ 1 ] * _rtB ->
fau2uzx3o2 [ 2 ] ; _rtB -> jzjptqac3i = _rtB -> f3c51yhebb [ 2 ] * _rtB ->
fau2uzx3o2 [ 0 ] ; _rtB -> j3gbn3ukuo = _rtB -> f3c51yhebb [ 0 ] * _rtB ->
fau2uzx3o2 [ 1 ] ; _rtB -> ik4hdq2gk0 = _rtB -> f3c51yhebb [ 2 ] * _rtB ->
fau2uzx3o2 [ 1 ] ; _rtB -> dupoix44e4 = _rtB -> f3c51yhebb [ 0 ] * _rtB ->
fau2uzx3o2 [ 2 ] ; _rtB -> g0ril1xmmb = _rtB -> f3c51yhebb [ 1 ] * _rtB ->
fau2uzx3o2 [ 0 ] ; _rtB -> o3ctrxffdt [ 0 ] = _rtB -> kehx1dh4v2 - _rtB ->
ik4hdq2gk0 ; _rtB -> o3ctrxffdt [ 1 ] = _rtB -> jzjptqac3i - _rtB ->
dupoix44e4 ; _rtB -> o3ctrxffdt [ 2 ] = _rtB -> j3gbn3ukuo - _rtB ->
g0ril1xmmb ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> cqrf5uuv0t [ 3 * i ] =
_rtB -> ef1qhnuulp [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3 * i ] = _rtB ->
ef1qhnuulp [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] = _rtB -> ef1qhnuulp
[ i + 6 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> gxlqdjspys [ i ] ; } for ( i
= 0 ; i < 3 ; i ++ ) { _rtB -> kwlhbpqe3d [ i ] = 0.0 ; _rtB -> kwlhbpqe3d [
i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB -> o3ctrxffdt [ 0 ] ; _rtB ->
kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 3 ] * _rtB -> o3ctrxffdt [ 1 ] ;
_rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] * _rtB -> o3ctrxffdt
[ 2 ] ; } _rtB -> gt1xszzt30 = _rtB -> kwlhbpqe3d [ 0 ] * _rtB -> kwlhbpqe3d
[ 0 ] ; _rtB -> e4rfwjcqx1 = _rtB -> kwlhbpqe3d [ 1 ] * _rtB -> kwlhbpqe3d [
1 ] ; _rtB -> fsnkdi2p3s = _rtB -> kwlhbpqe3d [ 2 ] * _rtB -> kwlhbpqe3d [ 2
] ; _rtB -> om1bt5jaz5 = ( _rtB -> gt1xszzt30 + _rtB -> e4rfwjcqx1 ) + _rtB
-> fsnkdi2p3s ; if ( _rtB -> om1bt5jaz5 < 0.0 ) { _rtB -> jq52ffwcdf = -
muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> om1bt5jaz5 ) ) ; } else {
_rtB -> jq52ffwcdf = muDoubleScalarSqrt ( _rtB -> om1bt5jaz5 ) ; } if ( _rtB
-> jq52ffwcdf > _rtP -> P_978 ) { _rtB -> c3xyfhdxv1 = _rtP -> P_978 ; } else
if ( _rtB -> jq52ffwcdf < _rtP -> P_979 ) { _rtB -> c3xyfhdxv1 = _rtP ->
P_979 ; } else { _rtB -> c3xyfhdxv1 = _rtB -> jq52ffwcdf ; } _rtB ->
nriqkx1fmu = _rtB -> kwlhbpqe3d [ 1 ] / _rtB -> c3xyfhdxv1 ; if ( _rtB ->
nriqkx1fmu > 1.0 ) { tmp_i = 1.0 ; } else if ( _rtB -> nriqkx1fmu < - 1.0 ) {
tmp_i = - 1.0 ; } else { tmp_i = _rtB -> nriqkx1fmu ; } _rtB -> dd0jpplxpd =
muDoubleScalarAsin ( tmp_i ) ; _rtB -> dyimarw2h5 = _rtP -> P_980 * _rtB ->
dd0jpplxpd ; _rtB -> emrva22chl = muDoubleScalarAbs ( _rtB -> dyimarw2h5 ) ;
if ( _rtB -> emrva22chl > _rtP -> P_981 ) { _rtB -> mqsjvia3yo = _rtP ->
P_981 ; } else if ( _rtB -> emrva22chl < _rtP -> P_982 ) { _rtB -> mqsjvia3yo
= _rtP -> P_982 ; } else { _rtB -> mqsjvia3yo = _rtB -> emrva22chl ; } _rtB
-> pqqmfljybl = 0.08 * _rtB -> mqsjvia3yo - 0.003 * muDoubleScalarPower (
_rtB -> mqsjvia3yo , 2.0 ) ; _rtB -> ontiwshwlm = _rtB -> pqqmfljybl * _rtB
-> apq2tszf4x ; _rtB -> i1uw3dkfk5 = ( _rtB -> ontiwshwlm > _rtB ->
lgtjn4ncze ) ; if ( _rtB -> i1uw3dkfk5 ) { _rtB -> es2c5c0vgk = _rtB ->
lgtjn4ncze ; } else { _rtB -> fcbgozq2gf = ( _rtB -> ontiwshwlm < _rtB ->
kjrxl25tgm ) ; if ( _rtB -> fcbgozq2gf ) { _rtB -> e5e1swbsdw = _rtB ->
kjrxl25tgm ; } else { _rtB -> e5e1swbsdw = _rtB -> ontiwshwlm ; } _rtB ->
es2c5c0vgk = _rtB -> e5e1swbsdw ; } _rtB -> cu5dszplxj = muDoubleScalarSign (
_rtB -> dyimarw2h5 ) ; _rtB -> aj3hfw3oaa = _rtB -> es2c5c0vgk * _rtB ->
cu5dszplxj ; _rtB -> c32om5ebyd = _rtB -> aj3hfw3oaa + _rtB -> ebepfuajzv ;
_rtB -> o2wbax5evm = _rtP -> P_985 * _rtB -> c32om5ebyd ; lvrrs02dbe ( S ,
_rtB -> a5sgw3semq , _rtB -> biho35zqrj , _rtB -> cip3exm2yt [ 2 ] , _rtB ->
cip3exm2yt [ 1 ] , _rtB -> fkejxlkcsq , _rtB -> a2na0wcqx3 , _rtB ->
o2wbax5evm , & _rtB -> lvrrs02dbel , & _rtDW -> lvrrs02dbel , ( dbjdkpcxft *
) & _rtP -> lvrrs02dbel ) ; _rtB -> bquatj5nf0 = ( real_T ) _rtB ->
nitrvromjj * _rtB -> agssmjvzee ; _rtB -> mrvyqvfe5b = _rtB -> bquatj5nf0 +
_rtB -> ltperw2ubl ; _rtB -> hkd5c3d5pv = _rtB -> mrvyqvfe5b * _rtB ->
apq2tszf4x ; if ( _rtB -> hkd5c3d5pv > _rtP -> P_987 ) { _rtB -> knlpqgatmd =
_rtP -> P_987 ; } else if ( _rtB -> hkd5c3d5pv < _rtP -> P_988 ) { _rtB ->
knlpqgatmd = _rtP -> P_988 ; } else { _rtB -> knlpqgatmd = _rtB -> hkd5c3d5pv
; } _rtB -> jcyupbk1kz = _rtB -> knlpqgatmd * _rtB -> knlpqgatmd ; _rtB ->
dmszfxfqqj = _rtB -> getxiio5mp - _rtB -> jcyupbk1kz ; _rtB -> mgu2hjjwu5 =
muDoubleScalarSqrt ( _rtB -> dmszfxfqqj ) ; _rtB -> lzg5dsizwf = _rtB ->
f3c51yhebb [ 1 ] * _rtB -> brxxd1u0my [ 2 ] ; _rtB -> m0eemsvqqq = _rtB ->
f3c51yhebb [ 2 ] * _rtB -> brxxd1u0my [ 0 ] ; _rtB -> o0mntwu2rg = _rtB ->
f3c51yhebb [ 0 ] * _rtB -> brxxd1u0my [ 1 ] ; _rtB -> aff5hsdqiu = _rtB ->
f3c51yhebb [ 2 ] * _rtB -> brxxd1u0my [ 1 ] ; _rtB -> ppyobgcynx = _rtB ->
f3c51yhebb [ 0 ] * _rtB -> brxxd1u0my [ 2 ] ; _rtB -> msjrf5fkia = _rtB ->
f3c51yhebb [ 1 ] * _rtB -> brxxd1u0my [ 0 ] ; _rtB -> o3ctrxffdt [ 0 ] = _rtB
-> lzg5dsizwf - _rtB -> aff5hsdqiu ; _rtB -> o3ctrxffdt [ 1 ] = _rtB ->
m0eemsvqqq - _rtB -> ppyobgcynx ; _rtB -> o3ctrxffdt [ 2 ] = _rtB ->
o0mntwu2rg - _rtB -> msjrf5fkia ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
cqrf5uuv0t [ 3 * i ] = _rtB -> ef1qhnuulp [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3
* i ] = _rtB -> ef1qhnuulp [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] =
_rtB -> ef1qhnuulp [ i + 6 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> gxlqdjspys
[ i ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> kwlhbpqe3d [ i ] = 0.0 ;
_rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB -> o3ctrxffdt [ 0
] ; _rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 3 ] * _rtB ->
o3ctrxffdt [ 1 ] ; _rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] *
_rtB -> o3ctrxffdt [ 2 ] ; } _rtB -> mfuwl0v14p = _rtB -> kwlhbpqe3d [ 0 ] *
_rtB -> kwlhbpqe3d [ 0 ] ; _rtB -> lnjhif1d2x = _rtB -> kwlhbpqe3d [ 1 ] *
_rtB -> kwlhbpqe3d [ 1 ] ; _rtB -> irdcie0hxm = _rtB -> kwlhbpqe3d [ 2 ] *
_rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> njp4qbhtbv = ( _rtB -> mfuwl0v14p + _rtB
-> lnjhif1d2x ) + _rtB -> irdcie0hxm ; if ( _rtB -> njp4qbhtbv < 0.0 ) { _rtB
-> avsw3m2mav = - muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> njp4qbhtbv
) ) ; } else { _rtB -> avsw3m2mav = muDoubleScalarSqrt ( _rtB -> njp4qbhtbv )
; } if ( _rtB -> avsw3m2mav > _rtP -> P_990 ) { _rtB -> fjop3vjzzb = _rtP ->
P_990 ; } else if ( _rtB -> avsw3m2mav < _rtP -> P_991 ) { _rtB -> fjop3vjzzb
= _rtP -> P_991 ; } else { _rtB -> fjop3vjzzb = _rtB -> avsw3m2mav ; } _rtB
-> hi1rq3oy5c = _rtB -> kwlhbpqe3d [ 1 ] / _rtB -> fjop3vjzzb ; if ( _rtB ->
hi1rq3oy5c > 1.0 ) { tmp_i = 1.0 ; } else if ( _rtB -> hi1rq3oy5c < - 1.0 ) {
tmp_i = - 1.0 ; } else { tmp_i = _rtB -> hi1rq3oy5c ; } _rtB -> pcfb25yvob =
muDoubleScalarAsin ( tmp_i ) ; _rtB -> ddbc4a4lon = _rtP -> P_992 * _rtB ->
pcfb25yvob ; _rtB -> e4qywviczl = muDoubleScalarAbs ( _rtB -> ddbc4a4lon ) ;
if ( _rtB -> e4qywviczl > _rtP -> P_993 ) { _rtB -> j4zhid3ye5 = _rtP ->
P_993 ; } else if ( _rtB -> e4qywviczl < _rtP -> P_994 ) { _rtB -> j4zhid3ye5
= _rtP -> P_994 ; } else { _rtB -> j4zhid3ye5 = _rtB -> e4qywviczl ; } _rtB
-> hyjxdessea = 0.08 * _rtB -> j4zhid3ye5 - 0.003 * muDoubleScalarPower (
_rtB -> j4zhid3ye5 , 2.0 ) ; _rtB -> aqpfedspht = _rtB -> hyjxdessea * _rtB
-> apq2tszf4x ; _rtB -> pietrf0v4x = ( _rtB -> aqpfedspht > _rtB ->
mgu2hjjwu5 ) ; if ( _rtB -> pietrf0v4x ) { _rtB -> kfecidw2iv = _rtB ->
mgu2hjjwu5 ; } else { _rtB -> exj5o03rdv = ( _rtB -> aqpfedspht < _rtB ->
incajketqw ) ; if ( _rtB -> exj5o03rdv ) { _rtB -> envtlqrath = _rtB ->
incajketqw ; } else { _rtB -> envtlqrath = _rtB -> aqpfedspht ; } _rtB ->
kfecidw2iv = _rtB -> envtlqrath ; } _rtB -> cdxpaod0pr = muDoubleScalarSign (
_rtB -> ddbc4a4lon ) ; _rtB -> k314i3a0bv = _rtB -> kfecidw2iv * _rtB ->
cdxpaod0pr ; _rtB -> paqj5kfy20 = _rtB -> k314i3a0bv ; _rtB -> aqpvkg0xzq =
_rtP -> P_996 * _rtB -> paqj5kfy20 ; dak2bbvhdy ( S , _rtB -> a5sgw3semq ,
_rtB -> biho35zqrj , _rtB -> cip3exm2yt [ 2 ] , _rtB -> cip3exm2yt [ 1 ] ,
_rtB -> cip3exm2yt [ 0 ] , _rtB -> egkz31xsi0 , _rtB -> knlpqgatmd , _rtB ->
aqpvkg0xzq , & _rtB -> dak2bbvhdyl , & _rtDW -> dak2bbvhdyl , ( fgfesxh13p *
) & _rtP -> dak2bbvhdyl ) ; _rtB -> o5rvkx5bbg = _rtB -> b2qgbs4ore * _rtB ->
apq2tszf4x ; if ( _rtB -> o5rvkx5bbg > _rtP -> P_998 ) { _rtB -> izz204iho4 =
_rtP -> P_998 ; } else if ( _rtB -> o5rvkx5bbg < _rtP -> P_999 ) { _rtB ->
izz204iho4 = _rtP -> P_999 ; } else { _rtB -> izz204iho4 = _rtB -> o5rvkx5bbg
; } _rtB -> lrjvvxizif = _rtB -> izz204iho4 * _rtB -> izz204iho4 ; _rtB ->
l0ozg2suv5 = _rtB -> etphalrkq3 - _rtB -> lrjvvxizif ; _rtB -> jetsad15g3 =
_rtB -> f3c51yhebb [ 1 ] * _rtB -> k3wordm2hu [ 2 ] ; _rtB -> c4cg2ud2hb =
_rtB -> f3c51yhebb [ 2 ] * _rtB -> k3wordm2hu [ 0 ] ; _rtB -> gs341p1oc3 =
_rtB -> f3c51yhebb [ 0 ] * _rtB -> k3wordm2hu [ 1 ] ; _rtB -> amxmlj11be =
_rtB -> f3c51yhebb [ 2 ] * _rtB -> k3wordm2hu [ 1 ] ; _rtB -> gvnpflyhey =
_rtB -> f3c51yhebb [ 0 ] * _rtB -> k3wordm2hu [ 2 ] ; _rtB -> na5tjsithb =
_rtB -> f3c51yhebb [ 1 ] * _rtB -> k3wordm2hu [ 0 ] ; _rtB -> o3ctrxffdt [ 0
] = _rtB -> jetsad15g3 - _rtB -> amxmlj11be ; _rtB -> o3ctrxffdt [ 1 ] = _rtB
-> c4cg2ud2hb - _rtB -> gvnpflyhey ; _rtB -> o3ctrxffdt [ 2 ] = _rtB ->
gs341p1oc3 - _rtB -> na5tjsithb ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
cqrf5uuv0t [ 3 * i ] = _rtB -> ef1qhnuulp [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3
* i ] = _rtB -> ef1qhnuulp [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] =
_rtB -> ef1qhnuulp [ i + 6 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> gxlqdjspys
[ i ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> kwlhbpqe3d [ i ] = 0.0 ;
_rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB -> o3ctrxffdt [ 0
] ; _rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 3 ] * _rtB ->
o3ctrxffdt [ 1 ] ; _rtB -> kwlhbpqe3d [ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] *
_rtB -> o3ctrxffdt [ 2 ] ; } _rtB -> n1tm0qzx52 = _rtB -> kwlhbpqe3d [ 0 ] *
_rtB -> kwlhbpqe3d [ 0 ] ; _rtB -> bx1wnpokja = _rtB -> kwlhbpqe3d [ 1 ] *
_rtB -> kwlhbpqe3d [ 1 ] ; _rtB -> j2xdq3jlea = _rtB -> kwlhbpqe3d [ 2 ] *
_rtB -> kwlhbpqe3d [ 2 ] ; _rtB -> et4e03fugs = ( _rtB -> n1tm0qzx52 + _rtB
-> bx1wnpokja ) + _rtB -> j2xdq3jlea ; if ( _rtB -> et4e03fugs < 0.0 ) { _rtB
-> hr05omtunu = - muDoubleScalarSqrt ( muDoubleScalarAbs ( _rtB -> et4e03fugs
) ) ; } else { _rtB -> hr05omtunu = muDoubleScalarSqrt ( _rtB -> et4e03fugs )
; } if ( _rtB -> hr05omtunu > _rtP -> P_1001 ) { _rtB -> oofz4qwgdi = _rtP ->
P_1001 ; } else if ( _rtB -> hr05omtunu < _rtP -> P_1002 ) { _rtB ->
oofz4qwgdi = _rtP -> P_1002 ; } else { _rtB -> oofz4qwgdi = _rtB ->
hr05omtunu ; } _rtB -> nsfucrejzu = _rtB -> kwlhbpqe3d [ 1 ] / _rtB ->
oofz4qwgdi ; if ( _rtB -> nsfucrejzu > 1.0 ) { tmp_i = 1.0 ; } else if ( _rtB
-> nsfucrejzu < - 1.0 ) { tmp_i = - 1.0 ; } else { tmp_i = _rtB -> nsfucrejzu
; } _rtB -> g2ntihtej4 = muDoubleScalarAsin ( tmp_i ) ; _rtB -> pzszf4ofm2 =
_rtP -> P_1003 * _rtB -> g2ntihtej4 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> fyxfokj4hr = _rtDW -> gp1feal4z4 ; _rtB -> ay2zyphh2s = ( int8_T ) (
_rtB -> irowwtyk2h - _rtB -> fyxfokj4hr ) ; _rtB -> diale4vr2q = ( uint8_T )
( _rtB -> ay2zyphh2s > npz4om2cj4 ( S ) -> hgvijj3ega ) ; _rtB -> a2mh2adzun
= ( ( _rtB -> diale4vr2q != 0 ) && ( _rtB -> irowwtyk2h != 0 ) ) ; _rtB ->
gkictbmvj5 = _rtDW -> amvb32hegv ; _rtB -> nhnbw2r1e3 = ( int8_T ) ( _rtB ->
irowwtyk2h - _rtB -> gkictbmvj5 ) ; _rtB -> pyhenvrsjl = ( _rtB -> nhnbw2r1e3
< npz4om2cj4 ( S ) -> lh1snrv1eo ) ; _rtB -> gafksd5kmf = _rtDW -> klycy0wa1d
; } if ( ssIsMajorTimeStep ( S ) ) { resetIntg = false ; didZcEventOccur = (
_rtB -> pyhenvrsjl && ( _rtZCE -> emiybms4uk != POS_ZCSIG ) ) ; _rtZCE ->
emiybms4uk = _rtB -> pyhenvrsjl ; if ( didZcEventOccur || ( _rtDW ->
m33fcwggx1 != 0 ) ) { resetIntg = true ; _rtX -> kvv12h1lmd = _rtB ->
gafksd5kmf ; } if ( resetIntg ) { ssSetSolverNeedsReset ( S ) ; } } if ( _rtX
-> kvv12h1lmd >= _rtP -> P_1005 ) { if ( _rtX -> kvv12h1lmd != _rtP -> P_1005
) { _rtX -> kvv12h1lmd = _rtP -> P_1005 ; ssSetSolverNeedsReset ( S ) ; } }
else { if ( ( _rtX -> kvv12h1lmd <= _rtP -> P_1006 ) && ( _rtX -> kvv12h1lmd
!= _rtP -> P_1006 ) ) { _rtX -> kvv12h1lmd = _rtP -> P_1006 ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> o3mgrn1esk = _rtX -> kvv12h1lmd ;
if ( ssIsMajorTimeStep ( S ) ) { resetIntg = false ; didZcEventOccur = ( _rtB
-> a2mh2adzun && ( _rtZCE -> acmyvkuobt != POS_ZCSIG ) ) ; _rtZCE ->
acmyvkuobt = _rtB -> a2mh2adzun ; if ( didZcEventOccur || ( _rtDW ->
hpqyrum1dh != 0 ) ) { resetIntg = true ; _rtX -> ii2qiixi5h = _rtB ->
o3mgrn1esk ; } if ( resetIntg ) { ssSetSolverNeedsReset ( S ) ; } } if ( _rtX
-> ii2qiixi5h >= _rtP -> P_1007 ) { if ( _rtX -> ii2qiixi5h != _rtP -> P_1007
) { _rtX -> ii2qiixi5h = _rtP -> P_1007 ; ssSetSolverNeedsReset ( S ) ; } }
else { if ( ( _rtX -> ii2qiixi5h <= _rtP -> P_1008 ) && ( _rtX -> ii2qiixi5h
!= _rtP -> P_1008 ) ) { _rtX -> ii2qiixi5h = _rtP -> P_1008 ;
ssSetSolverNeedsReset ( S ) ; } } _rtB -> mkidttpwpi = _rtX -> ii2qiixi5h ;
if ( _rtB -> irowwtyk2h > _rtP -> P_1818 ) { _rtB -> kb5cizhzgc = _rtB ->
mkidttpwpi ; } else { _rtB -> kb5cizhzgc = _rtB -> o3mgrn1esk ; } _rtB ->
e35ylvcmr0 = _rtB -> pzszf4ofm2 - _rtB -> kb5cizhzgc ; _rtB -> b0ewgceda3 =
muDoubleScalarAbs ( _rtB -> e35ylvcmr0 ) ; if ( _rtB -> b0ewgceda3 > _rtP ->
P_1009 ) { _rtB -> jgdecmfmby = _rtP -> P_1009 ; } else if ( _rtB ->
b0ewgceda3 < _rtP -> P_1010 ) { _rtB -> jgdecmfmby = _rtP -> P_1010 ; } else
{ _rtB -> jgdecmfmby = _rtB -> b0ewgceda3 ; } _rtB -> epkx1ucssj = 0.08 *
_rtB -> jgdecmfmby - 0.003 * muDoubleScalarPower ( _rtB -> jgdecmfmby , 2.0 )
; _rtB -> nwo0ctzyd0 = _rtB -> epkx1ucssj * _rtB -> apq2tszf4x ; _rtB ->
jnhqmigulo = ( _rtB -> nwo0ctzyd0 > _rtB -> l0ozg2suv5 ) ; if ( _rtB ->
jnhqmigulo ) { _rtB -> ljekdwf5vq = _rtB -> l0ozg2suv5 ; } else { _rtB ->
exltxrppxr = ( _rtB -> nwo0ctzyd0 < _rtB -> pyqaujjma1 ) ; if ( _rtB ->
exltxrppxr ) { _rtB -> cjbucia2tp = _rtB -> pyqaujjma1 ; } else { _rtB ->
cjbucia2tp = _rtB -> nwo0ctzyd0 ; } _rtB -> ljekdwf5vq = _rtB -> cjbucia2tp ;
} _rtB -> h3dvi0znqe = muDoubleScalarSign ( _rtB -> e35ylvcmr0 ) ; _rtB ->
dq4brccvos = _rtB -> ljekdwf5vq * _rtB -> h3dvi0znqe ; _rtB -> dhdibulbpp =
_rtP -> P_1012 * _rtB -> dq4brccvos ; b1bttejwsj ( S , _rtB -> a5sgw3semq ,
_rtB -> biho35zqrj , _rtB -> cip3exm2yt [ 2 ] , _rtB -> cip3exm2yt [ 1 ] ,
_rtB -> cip3exm2yt [ 0 ] , _rtB -> lygv535h0z , _rtB -> izz204iho4 , _rtB ->
dhdibulbpp , & _rtB -> b1bttejwsj2 , & _rtDW -> b1bttejwsj2 , ( fvjsblhu4h *
) & _rtP -> b1bttejwsj2 ) ; _rtB -> oemrsamsqh [ 0 ] = ( _rtB -> lvrrs02dbel
. hbvlhrfocs [ 0 ] + _rtB -> dak2bbvhdyl . elpwly1l1t [ 0 ] ) + _rtB ->
b1bttejwsj2 . cbdogvxzxd [ 0 ] ; _rtB -> oemrsamsqh [ 3 ] = ( _rtB ->
lvrrs02dbel . cym4dmzcj1 [ 0 ] + _rtB -> dak2bbvhdyl . maromz3wf3 [ 0 ] ) +
_rtB -> b1bttejwsj2 . p1qhcdd2xz [ 0 ] ; tmp_p [ 0 ] = _rtB -> g1spufntqt [ 0
] ; tmp_p [ 3 ] = _rtB -> jbans5xopm [ 0 ] ; _rtB -> oemrsamsqh [ 1 ] = (
_rtB -> lvrrs02dbel . hbvlhrfocs [ 1 ] + _rtB -> dak2bbvhdyl . elpwly1l1t [ 1
] ) + _rtB -> b1bttejwsj2 . cbdogvxzxd [ 1 ] ; _rtB -> oemrsamsqh [ 4 ] = (
_rtB -> lvrrs02dbel . cym4dmzcj1 [ 1 ] + _rtB -> dak2bbvhdyl . maromz3wf3 [ 1
] ) + _rtB -> b1bttejwsj2 . p1qhcdd2xz [ 1 ] ; tmp_p [ 1 ] = _rtB ->
g1spufntqt [ 1 ] ; tmp_p [ 4 ] = _rtB -> jbans5xopm [ 1 ] ; _rtB ->
oemrsamsqh [ 2 ] = ( _rtB -> lvrrs02dbel . hbvlhrfocs [ 2 ] + _rtB ->
dak2bbvhdyl . elpwly1l1t [ 2 ] ) + _rtB -> b1bttejwsj2 . cbdogvxzxd [ 2 ] ;
_rtB -> oemrsamsqh [ 5 ] = ( _rtB -> lvrrs02dbel . cym4dmzcj1 [ 2 ] + _rtB ->
dak2bbvhdyl . maromz3wf3 [ 2 ] ) + _rtB -> b1bttejwsj2 . p1qhcdd2xz [ 2 ] ;
tmp_p [ 2 ] = _rtB -> g1spufntqt [ 2 ] ; tmp_p [ 5 ] = _rtB -> jbans5xopm [ 2
] ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB -> g3mzwjzujn [ i ] = ( tmp_p [ i ] +
_rtB -> g3mzwjzujn [ i ] ) + _rtB -> oemrsamsqh [ i ] ; } _rtB -> f42rmnrcue
[ 0 ] += _rtB -> g3mzwjzujn [ 0 ] ; _rtB -> f42rmnrcue [ 0 ] /= _rtB ->
oneisjghjn ; _rtB -> ayyvcvl2i5 [ 0 ] = _rtB -> f42rmnrcue [ 0 ] - _rtB ->
ayyvcvl2i5 [ 0 ] ; _rtB -> f42rmnrcue [ 1 ] += _rtB -> g3mzwjzujn [ 1 ] ;
_rtB -> f42rmnrcue [ 1 ] /= _rtB -> oneisjghjn ; _rtB -> ayyvcvl2i5 [ 1 ] =
_rtB -> f42rmnrcue [ 1 ] - _rtB -> ayyvcvl2i5 [ 1 ] ; _rtB -> f42rmnrcue [ 2
] += _rtB -> g3mzwjzujn [ 2 ] ; _rtB -> f42rmnrcue [ 2 ] /= _rtB ->
oneisjghjn ; _rtB -> ayyvcvl2i5 [ 2 ] = _rtB -> f42rmnrcue [ 2 ] - _rtB ->
ayyvcvl2i5 [ 2 ] ; _rtB -> lokuksnsb1 = _rtB -> ayyvcvl2i5 [ 0 ] ; _rtB ->
gnrlfvtovj = _rtB -> ayyvcvl2i5 [ 1 ] ; _rtB -> p10ikr1e3o = _rtP -> P_1013 *
_rtB -> ayyvcvl2i5 [ 2 ] ; _rtB -> piqr25abhc = _rtB -> p10ikr1e3o ; _rtB ->
gfig3w3nw0 = _rtB -> dkpy3rhwqa [ 0 ] * _rtB -> dkpy3rhwqa [ 0 ] ; _rtB ->
by5vby5ixg = _rtB -> dkpy3rhwqa [ 1 ] * _rtB -> dkpy3rhwqa [ 1 ] ; _rtB ->
agtqhgukkl = _rtB -> dkpy3rhwqa [ 2 ] * _rtB -> dkpy3rhwqa [ 2 ] ; _rtB ->
aq3ihtrwn5 = ( _rtB -> gfig3w3nw0 + _rtB -> by5vby5ixg ) + _rtB -> agtqhgukkl
; _rtB -> di4jqj3hz1 = muDoubleScalarSqrt ( _rtB -> aq3ihtrwn5 ) ; _rtB ->
kcosrsoleu = _rtB -> di4jqj3hz1 / _rtB -> f5gr0suncf ; ssCallAccelRunBlock (
S , 118 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 152 , 1159 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1160 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1161 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1162 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1163 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1164 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1165 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1166 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1168 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
etivvfvjp0 = 0.0 * _rtB -> izz204iho4 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 152 , 1170 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
ctmledsn54 = 0.0 * _rtB -> dhdibulbpp ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 152 , 1172 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
czgngxycwt = 0.0 * _rtB -> a2na0wcqx3 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 152 , 1174 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1175 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
lwq4mj3bci = _rtB -> pzszf4ofm2 * ( real_T ) _rtB -> b1bttejwsj2 . pnd0lq04oj
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 152 , 1177 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 152 , 1178 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> f0gzv0raiv = _rtB -> hgr3hfctxj * ( real_T
) _rtB -> irowwtyk2h ; _rtB -> g3taobq0q3 = _rtB -> f0gzv0raiv - _rtB ->
gafksd5kmf ; _rtB -> mrqlwuknkm = _rtP -> P_1014 * _rtB -> g3taobq0q3 ; if (
_rtB -> mrqlwuknkm > _rtP -> P_1015 ) { _rtB -> jtvjwugnc1 = _rtP -> P_1015 ;
} else if ( _rtB -> mrqlwuknkm < _rtP -> P_1016 ) { _rtB -> jtvjwugnc1 = _rtP
-> P_1016 ; } else { _rtB -> jtvjwugnc1 = _rtB -> mrqlwuknkm ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 152 , 1184 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> jywlgn4kxd = _rtB -> lwq4mj3bci - _rtB ->
gafksd5kmf ; _rtB -> bavknkf0cl = _rtP -> P_1017 * _rtB -> jywlgn4kxd ; if (
_rtB -> bavknkf0cl > _rtP -> P_1018 ) { _rtB -> hbc3rgueox = _rtP -> P_1018 ;
} else if ( _rtB -> bavknkf0cl < _rtP -> P_1019 ) { _rtB -> hbc3rgueox = _rtP
-> P_1019 ; } else { _rtB -> hbc3rgueox = _rtB -> bavknkf0cl ; } _rtB ->
azrl3kbh4k = 0.0 ; _rtB -> azrl3kbh4k += _rtP -> P_1021 [ 0 ] * _rtX ->
orid2cznzr [ 0 ] ; _rtB -> azrl3kbh4k += _rtP -> P_1021 [ 1 ] * _rtX ->
orid2cznzr [ 1 ] ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> oukyysqf3d =
_rtP -> P_1028 ; } ssCallAccelRunBlock ( S , 134 , 0 , SS_CALL_MDL_OUTPUTS )
; _rtB -> o1wbiq1mg2 [ 0 ] = _rtB -> dued0aafx5 ; _rtB -> o1wbiq1mg2 [ 1 ] =
_rtB -> bs2vlmvids ; _rtB -> o1wbiq1mg2 [ 2 ] = _rtB -> lvqf3wqjdu ; _rtB ->
ktdddqm0je = _rtX -> knizeu3cnz ; _rtB -> lmczjgziky = _rtB -> dryds5iyuk +
_rtB -> ktdddqm0je ; muDoubleScalarSinCos ( _rtB -> lmczjgziky , & _rtB ->
kikmz1k43j , & _rtB -> d4b3y2r4xg ) ; _rtB -> kysthd4tm2 [ 0 ] = _rtB ->
d4b3y2r4xg ; _rtB -> kysthd4tm2 [ 1 ] = _rtB -> kikmz1k43j ; _rtB ->
kysthd4tm2 [ 2 ] = _rtB -> ovqrwhozf3 ; _rtB -> kysthd4tm2 [ 4 ] = _rtB ->
d4b3y2r4xg ; _rtB -> kysthd4tm2 [ 5 ] = _rtB -> ovqrwhozf3 ; _rtB ->
kysthd4tm2 [ 6 ] = _rtB -> ovqrwhozf3 ; _rtB -> kysthd4tm2 [ 7 ] = _rtB ->
ovqrwhozf3 ; _rtB -> kysthd4tm2 [ 8 ] = _rtB -> eteubwukjc ; _rtB ->
kysthd4tm2 [ 3 ] = - _rtB -> kikmz1k43j ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB
-> cqrf5uuv0t [ 3 * i ] = _rtB -> df0qunjvqj [ i ] ; _rtB -> cqrf5uuv0t [ 1 +
3 * i ] = _rtB -> df0qunjvqj [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] =
_rtB -> df0qunjvqj [ i + 6 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
d4yugvwedn [ i ] = 0.0 ; _rtB -> o3ctrxffdt [ i ] = 0.0 ; _rtB -> ayyvcvl2i5
[ i ] = 0.0 ; _rtB -> d4yugvwedn [ i ] += _rtB -> cqrf5uuv0t [ i ] * _rtB ->
gxlqdjspys [ 0 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> dsf4svdctq [ i ] *
_rtB -> deth2igh2x [ 0 ] ; _rtB -> ayyvcvl2i5 [ i ] += _rtB -> pc2kcg4gic [ i
] * _rtB -> deth2igh2x [ 0 ] ; _rtB -> d4yugvwedn [ i ] += _rtB -> cqrf5uuv0t
[ i + 3 ] * _rtB -> gxlqdjspys [ 1 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB ->
dsf4svdctq [ i + 3 ] * _rtB -> deth2igh2x [ 1 ] ; _rtB -> ayyvcvl2i5 [ i ] +=
_rtB -> pc2kcg4gic [ i + 3 ] * _rtB -> deth2igh2x [ 1 ] ; _rtB -> d4yugvwedn
[ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] * _rtB -> gxlqdjspys [ 2 ] ; _rtB ->
o3ctrxffdt [ i ] += _rtB -> dsf4svdctq [ i + 6 ] * _rtB -> deth2igh2x [ 2 ] ;
_rtB -> ayyvcvl2i5 [ i ] += _rtB -> pc2kcg4gic [ i + 6 ] * _rtB -> deth2igh2x
[ 2 ] ; } _rtB -> k21pe0iuq0 = _rtB -> deth2igh2x [ 1 ] * _rtB -> o3ctrxffdt
[ 2 ] ; _rtB -> ndtjjrsdnk = _rtB -> deth2igh2x [ 2 ] * _rtB -> o3ctrxffdt [
0 ] ; _rtB -> pbd55m5po0 = _rtB -> deth2igh2x [ 0 ] * _rtB -> o3ctrxffdt [ 1
] ; _rtB -> a2uowpigib = _rtB -> deth2igh2x [ 2 ] * _rtB -> o3ctrxffdt [ 1 ]
; _rtB -> bbr4c4oewh = _rtB -> deth2igh2x [ 0 ] * _rtB -> o3ctrxffdt [ 2 ] ;
_rtB -> edmtvwl1ke = _rtB -> deth2igh2x [ 1 ] * _rtB -> o3ctrxffdt [ 0 ] ;
_rtB -> o3ctrxffdt [ 0 ] = _rtB -> k21pe0iuq0 - _rtB -> a2uowpigib ; _rtB ->
o3ctrxffdt [ 1 ] = _rtB -> ndtjjrsdnk - _rtB -> bbr4c4oewh ; _rtB ->
o3ctrxffdt [ 2 ] = _rtB -> pbd55m5po0 - _rtB -> edmtvwl1ke ; _rtB ->
ayyvcvl2i5 [ 0 ] = ( _rtB -> g3mzwjzujn [ 3 ] - _rtB -> ayyvcvl2i5 [ 0 ] ) -
_rtB -> o3ctrxffdt [ 0 ] ; _rtB -> ayyvcvl2i5 [ 1 ] = ( _rtB -> g3mzwjzujn [
4 ] - _rtB -> ayyvcvl2i5 [ 1 ] ) - _rtB -> o3ctrxffdt [ 1 ] ; _rtB ->
ayyvcvl2i5 [ 2 ] = ( _rtB -> g3mzwjzujn [ 5 ] - _rtB -> ayyvcvl2i5 [ 2 ] ) -
_rtB -> o3ctrxffdt [ 2 ] ; dffiw3rk3b ( _rtB -> ayyvcvl2i5 , _rtB ->
dsf4svdctq , _rtB -> o3ctrxffdt ) ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
puqqtpd2td [ i ] = _rtB -> o3ctrxffdt [ i ] ; _rtB -> cqrf5uuv0t [ 3 * i ] =
_rtB -> kysthd4tm2 [ i ] ; _rtB -> cqrf5uuv0t [ 1 + 3 * i ] = _rtB ->
kysthd4tm2 [ i + 3 ] ; _rtB -> cqrf5uuv0t [ 2 + 3 * i ] = _rtB -> kysthd4tm2
[ i + 6 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { for ( i_p = 0 ; i_p < 3 ; i_p ++
) { _rtB -> nry1myltoo [ i + 3 * i_p ] = 0.0 ; _rtB -> nry1myltoo [ i + 3 *
i_p ] += _rtB -> cqrf5uuv0t [ 3 * i_p ] * _rtB -> df0qunjvqj [ i ] ; _rtB ->
nry1myltoo [ i + 3 * i_p ] += _rtB -> cqrf5uuv0t [ 3 * i_p + 1 ] * _rtB ->
df0qunjvqj [ i + 3 ] ; _rtB -> nry1myltoo [ i + 3 * i_p ] += _rtB ->
cqrf5uuv0t [ 3 * i_p + 2 ] * _rtB -> df0qunjvqj [ i + 6 ] ; } } for ( i = 0 ;
i < 3 ; i ++ ) { tmp_e [ 3 * i ] = _rtB -> nry1myltoo [ i ] ; tmp_e [ 1 + 3 *
i ] = _rtB -> nry1myltoo [ i + 3 ] ; tmp_e [ 2 + 3 * i ] = _rtB -> nry1myltoo
[ i + 6 ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> lm02pq05rp [ i ] = 0.0 ;
_rtB -> nry1myltoo [ 3 * i ] = tmp_e [ 3 * i ] ; _rtB -> cqrf5uuv0t [ 3 * i ]
= _rtB -> kysthd4tm2 [ i ] ; _rtB -> emaacg5adk [ 3 * i ] = _rtB ->
df0qunjvqj [ i ] ; _rtB -> lm02pq05rp [ i ] += _rtB -> kysthd4tm2 [ i ] *
_rtB -> d3hqzw0eyy [ 0 ] ; _rtB -> nry1myltoo [ 1 + 3 * i ] = tmp_e [ 3 * i +
1 ] ; _rtB -> cqrf5uuv0t [ 1 + 3 * i ] = _rtB -> kysthd4tm2 [ i + 3 ] ; _rtB
-> emaacg5adk [ 1 + 3 * i ] = _rtB -> df0qunjvqj [ i + 3 ] ; _rtB ->
lm02pq05rp [ i ] += _rtB -> kysthd4tm2 [ i + 3 ] * _rtB -> d3hqzw0eyy [ 1 ] ;
_rtB -> nry1myltoo [ 2 + 3 * i ] = tmp_e [ 3 * i + 2 ] ; _rtB -> cqrf5uuv0t [
2 + 3 * i ] = _rtB -> kysthd4tm2 [ i + 6 ] ; _rtB -> emaacg5adk [ 2 + 3 * i ]
= _rtB -> df0qunjvqj [ i + 6 ] ; _rtB -> lm02pq05rp [ i ] += _rtB ->
kysthd4tm2 [ i + 6 ] * _rtB -> d3hqzw0eyy [ 2 ] ; } for ( i = 0 ; i < 3 ; i
++ ) { _rtB -> o3ctrxffdt [ i ] = 0.0 ; _rtB -> ayyvcvl2i5 [ i ] = 0.0 ; _rtB
-> g5vnb24p3z [ i ] = 0.0 ; _rtB -> o3ctrxffdt [ i ] += _rtB -> nry1myltoo [
i ] * _rtB -> dlzh5xejq2 [ 0 ] ; _rtB -> ayyvcvl2i5 [ i ] += _rtB ->
cqrf5uuv0t [ i ] * _rtB -> nmyabhmznp [ 0 ] ; _rtB -> g5vnb24p3z [ i ] +=
_rtB -> emaacg5adk [ i ] * _rtB -> dlzh5xejq2 [ 0 ] ; _rtB -> o3ctrxffdt [ i
] += _rtB -> nry1myltoo [ i + 3 ] * _rtB -> dlzh5xejq2 [ 1 ] ; _rtB ->
ayyvcvl2i5 [ i ] += _rtB -> cqrf5uuv0t [ i + 3 ] * _rtB -> nmyabhmznp [ 1 ] ;
_rtB -> g5vnb24p3z [ i ] += _rtB -> emaacg5adk [ i + 3 ] * _rtB -> dlzh5xejq2
[ 1 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> nry1myltoo [ i + 6 ] * _rtB ->
dlzh5xejq2 [ 2 ] ; _rtB -> ayyvcvl2i5 [ i ] += _rtB -> cqrf5uuv0t [ i + 6 ] *
_rtB -> nmyabhmznp [ 2 ] ; _rtB -> g5vnb24p3z [ i ] += _rtB -> emaacg5adk [ i
+ 6 ] * _rtB -> dlzh5xejq2 [ 2 ] ; } if ( _rtDW -> pbax4pbj0t != 0 ) { _rtX
-> n05o0sy3du [ 0 ] = _rtB -> lm02pq05rp [ 0 ] ; _rtX -> n05o0sy3du [ 1 ] =
_rtB -> lm02pq05rp [ 1 ] ; _rtX -> n05o0sy3du [ 2 ] = _rtB -> lm02pq05rp [ 2
] ; } _rtB -> kwlhbpqe3d [ 0 ] = _rtX -> n05o0sy3du [ 0 ] ; _rtB ->
kwlhbpqe3d [ 1 ] = _rtX -> n05o0sy3du [ 1 ] ; _rtB -> kwlhbpqe3d [ 2 ] = _rtX
-> n05o0sy3du [ 2 ] ; _rtB -> c3apubwnld = _rtB -> kwlhbpqe3d [ 1 ] * _rtB ->
ayyvcvl2i5 [ 2 ] ; _rtB -> lro3xfvd3j = _rtB -> kwlhbpqe3d [ 2 ] * _rtB ->
ayyvcvl2i5 [ 0 ] ; _rtB -> d3mzgqy5ay = _rtB -> kwlhbpqe3d [ 0 ] * _rtB ->
ayyvcvl2i5 [ 1 ] ; _rtB -> kzugz1jqn2 = _rtB -> kwlhbpqe3d [ 2 ] * _rtB ->
ayyvcvl2i5 [ 1 ] ; _rtB -> ckrakjdchw = _rtB -> kwlhbpqe3d [ 0 ] * _rtB ->
ayyvcvl2i5 [ 2 ] ; _rtB -> ecdpt10n5u = _rtB -> kwlhbpqe3d [ 1 ] * _rtB ->
ayyvcvl2i5 [ 0 ] ; _rtB -> ayyvcvl2i5 [ 0 ] = _rtB -> c3apubwnld - _rtB ->
kzugz1jqn2 ; _rtB -> ayyvcvl2i5 [ 1 ] = _rtB -> lro3xfvd3j - _rtB ->
ckrakjdchw ; _rtB -> ayyvcvl2i5 [ 2 ] = _rtB -> d3mzgqy5ay - _rtB ->
ecdpt10n5u ; _rtB -> jl01pawnov [ 0 ] = _rtB -> o3ctrxffdt [ 0 ] - _rtB ->
ayyvcvl2i5 [ 0 ] ; _rtB -> jl01pawnov [ 1 ] = _rtB -> o3ctrxffdt [ 1 ] - _rtB
-> ayyvcvl2i5 [ 1 ] ; _rtB -> jl01pawnov [ 2 ] = _rtB -> o3ctrxffdt [ 2 ] -
_rtB -> ayyvcvl2i5 [ 2 ] ; _rtB -> i5s2twjpia = ( _rtB -> n0ypjfdw1o [ 0 ] +
_rtB -> n0ypjfdw1o [ 4 ] ) + _rtB -> n0ypjfdw1o [ 8 ] ; if (
ssIsMajorTimeStep ( S ) ) { rtAction = ( int8_T ) ! ( _rtB -> i5s2twjpia >
0.0 ) ; _rtDW -> e24fv5u4gg = rtAction ; } else { rtAction = _rtDW ->
e24fv5u4gg ; } switch ( rtAction ) { case 0 : h3v44pg0kk ( _rtB -> i5s2twjpia
, _rtB -> n0ypjfdw1o , & _rtB -> jlfhgatf4n [ 0 ] , & _rtB -> jlfhgatf4n [ 1
] , & _rtB -> hnb3thjcdb , ( grglhn4pya * ) & _rtP -> hnb3thjcdb ) ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> hnb3thjcdb . gqlhiezdbu ) ;
} break ; case 1 : iorhdpdmai ( S , _rtB -> n0ypjfdw1o , & _rtB -> jlfhgatf4n
[ 0 ] , & _rtB -> jlfhgatf4n [ 1 ] , & _rtB -> jlfhgatf4n [ 2 ] , & _rtB ->
jlfhgatf4n [ 3 ] , & _rtB -> k0g5ylghay , & _rtDW -> k0g5ylghay , (
dcmchj0dqy * ) & _rtP -> k0g5ylghay ) ; if ( ssIsMajorTimeStep ( S ) ) {
srUpdateBC ( _rtDW -> k0g5ylghay . jjqsphygwt ) ; } break ; } _rtB ->
g2nsfvxtfp = ( ( _rtB -> ov1ecifwqz [ 0 ] * _rtB -> ov1ecifwqz [ 0 ] + _rtB
-> ov1ecifwqz [ 1 ] * _rtB -> ov1ecifwqz [ 1 ] ) + _rtB -> ov1ecifwqz [ 2 ] *
_rtB -> ov1ecifwqz [ 2 ] ) + _rtB -> ov1ecifwqz [ 3 ] * _rtB -> ov1ecifwqz [
3 ] ; _rtB -> ldxiwvnjrk = _rtB -> cpazwnicb3 - _rtB -> g2nsfvxtfp ; _rtB ->
blv5w5yawy [ 0 ] = _rtB -> deth2igh2x [ 0 ] - _rtB -> blv5w5yawy [ 0 ] ; _rtB
-> blv5w5yawy [ 1 ] = _rtB -> deth2igh2x [ 1 ] - _rtB -> blv5w5yawy [ 1 ] ;
_rtB -> blv5w5yawy [ 2 ] = _rtB -> deth2igh2x [ 2 ] - _rtB -> blv5w5yawy [ 2
] ; _rtB -> mzmkyxa0az = ( ( _rtB -> ov1ecifwqz [ 1 ] * _rtB -> blv5w5yawy [
0 ] + _rtB -> ov1ecifwqz [ 2 ] * _rtB -> blv5w5yawy [ 1 ] ) + _rtB ->
ov1ecifwqz [ 3 ] * _rtB -> blv5w5yawy [ 2 ] ) * - 0.5 + _rtB -> ldxiwvnjrk *
_rtB -> ov1ecifwqz [ 0 ] ; _rtB -> habc1jzdlw = ( ( _rtB -> ov1ecifwqz [ 0 ]
* _rtB -> blv5w5yawy [ 0 ] + _rtB -> ov1ecifwqz [ 2 ] * _rtB -> blv5w5yawy [
2 ] ) - _rtB -> ov1ecifwqz [ 3 ] * _rtB -> blv5w5yawy [ 1 ] ) * 0.5 + _rtB ->
ldxiwvnjrk * _rtB -> ov1ecifwqz [ 1 ] ; _rtB -> gxynvltyfa = ( ( _rtB ->
ov1ecifwqz [ 0 ] * _rtB -> blv5w5yawy [ 1 ] + _rtB -> ov1ecifwqz [ 3 ] * _rtB
-> blv5w5yawy [ 0 ] ) - _rtB -> ov1ecifwqz [ 1 ] * _rtB -> blv5w5yawy [ 2 ] )
* 0.5 + _rtB -> ldxiwvnjrk * _rtB -> ov1ecifwqz [ 2 ] ; _rtB -> iaypcbmsve =
( ( _rtB -> ov1ecifwqz [ 0 ] * _rtB -> blv5w5yawy [ 2 ] + _rtB -> ov1ecifwqz
[ 1 ] * _rtB -> blv5w5yawy [ 1 ] ) - _rtB -> ov1ecifwqz [ 2 ] * _rtB ->
blv5w5yawy [ 0 ] ) * 0.5 + _rtB -> ldxiwvnjrk * _rtB -> ov1ecifwqz [ 3 ] ;
_rtB -> lbu43tdh1g = _rtB -> nmyabhmznp [ 1 ] * _rtB -> nherqy4wgr [ 2 ] ;
_rtB -> cz0qw12xx2 = _rtB -> nmyabhmznp [ 2 ] * _rtB -> nherqy4wgr [ 0 ] ;
_rtB -> m4ijsa4r3i = _rtB -> nmyabhmznp [ 0 ] * _rtB -> nherqy4wgr [ 1 ] ;
_rtB -> fgrnj2locq = _rtB -> nmyabhmznp [ 2 ] * _rtB -> nherqy4wgr [ 1 ] ;
_rtB -> dbzr21tgbs = _rtB -> nmyabhmznp [ 0 ] * _rtB -> nherqy4wgr [ 2 ] ;
_rtB -> b2adscw0yf = _rtB -> nmyabhmznp [ 1 ] * _rtB -> nherqy4wgr [ 0 ] ;
_rtB -> o3ctrxffdt [ 0 ] = _rtB -> lbu43tdh1g - _rtB -> fgrnj2locq ; _rtB ->
o3ctrxffdt [ 1 ] = _rtB -> cz0qw12xx2 - _rtB -> dbzr21tgbs ; _rtB ->
o3ctrxffdt [ 2 ] = _rtB -> m4ijsa4r3i - _rtB -> b2adscw0yf ; _rtB ->
bjq3zdah23 = _rtB -> nmyabhmznp [ 1 ] * _rtB -> o3ctrxffdt [ 2 ] ; _rtB ->
bc5o1nmndi = _rtB -> nmyabhmznp [ 2 ] * _rtB -> o3ctrxffdt [ 0 ] ; _rtB ->
cy31izzmxz = _rtB -> nmyabhmznp [ 0 ] * _rtB -> o3ctrxffdt [ 1 ] ; _rtB ->
mwmioiyry5 = _rtB -> nmyabhmznp [ 2 ] * _rtB -> o3ctrxffdt [ 1 ] ; _rtB ->
lg2rq2wesy = _rtB -> nmyabhmznp [ 0 ] * _rtB -> o3ctrxffdt [ 2 ] ; _rtB ->
m01nk5dcdi = _rtB -> nmyabhmznp [ 1 ] * _rtB -> o3ctrxffdt [ 0 ] ; _rtB ->
o3ctrxffdt [ 0 ] = _rtB -> bjq3zdah23 - _rtB -> mwmioiyry5 ; _rtB ->
o3ctrxffdt [ 1 ] = _rtB -> bc5o1nmndi - _rtB -> lg2rq2wesy ; _rtB ->
o3ctrxffdt [ 2 ] = _rtB -> cy31izzmxz - _rtB -> m01nk5dcdi ; for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> ayyvcvl2i5 [ i ] = 0.0 ; _rtB -> ayyvcvl2i5 [ i ] +=
_rtB -> df0qunjvqj [ i ] * _rtB -> o3ctrxffdt [ 0 ] ; _rtB -> ayyvcvl2i5 [ i
] += _rtB -> df0qunjvqj [ i + 3 ] * _rtB -> o3ctrxffdt [ 1 ] ; _rtB ->
ayyvcvl2i5 [ i ] += _rtB -> df0qunjvqj [ i + 6 ] * _rtB -> o3ctrxffdt [ 2 ] ;
} for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> o3ctrxffdt [ i ] = 0.0 ; _rtB ->
o3ctrxffdt [ i ] += _rtB -> df0qunjvqj [ i ] * _rtB -> nmyabhmznp [ 0 ] ;
_rtB -> o3ctrxffdt [ i ] += _rtB -> df0qunjvqj [ i + 3 ] * _rtB -> nmyabhmznp
[ 1 ] ; _rtB -> o3ctrxffdt [ i ] += _rtB -> df0qunjvqj [ i + 6 ] * _rtB ->
nmyabhmznp [ 2 ] ; _rtB -> deth2igh2x [ i ] += _rtB -> o3ctrxffdt [ i ] ; }
_rtB -> lsxpdy2gy0 = _rtB -> dlzh5xejq2 [ 1 ] * _rtB -> deth2igh2x [ 2 ] ;
_rtB -> a2v2ci3a2a = _rtB -> dlzh5xejq2 [ 2 ] * _rtB -> deth2igh2x [ 0 ] ;
_rtB -> d151hrrrsw = _rtB -> dlzh5xejq2 [ 0 ] * _rtB -> deth2igh2x [ 1 ] ;
_rtB -> dxyfrlcv4u = _rtB -> dlzh5xejq2 [ 2 ] * _rtB -> deth2igh2x [ 1 ] ;
_rtB -> j3f1tvqnqu = _rtB -> dlzh5xejq2 [ 0 ] * _rtB -> deth2igh2x [ 2 ] ;
_rtB -> ekstjjrmns = _rtB -> dlzh5xejq2 [ 1 ] * _rtB -> deth2igh2x [ 0 ] ;
_rtB -> o3ctrxffdt [ 0 ] = _rtB -> lsxpdy2gy0 - _rtB -> dxyfrlcv4u ; _rtB ->
o3ctrxffdt [ 1 ] = _rtB -> a2v2ci3a2a - _rtB -> j3f1tvqnqu ; _rtB ->
o3ctrxffdt [ 2 ] = _rtB -> d151hrrrsw - _rtB -> ekstjjrmns ; _rtB ->
cdw3j2li5c [ 0 ] = ( _rtB -> o3ctrxffdt [ 0 ] - _rtB -> ayyvcvl2i5 [ 0 ] ) +
_rtB -> f42rmnrcue [ 0 ] ; _rtB -> cdw3j2li5c [ 1 ] = ( _rtB -> o3ctrxffdt [
1 ] - _rtB -> ayyvcvl2i5 [ 1 ] ) + _rtB -> f42rmnrcue [ 1 ] ; _rtB ->
cdw3j2li5c [ 2 ] = ( _rtB -> o3ctrxffdt [ 2 ] - _rtB -> ayyvcvl2i5 [ 2 ] ) +
_rtB -> f42rmnrcue [ 2 ] ; _rtB -> psegek4amn = 0.0 ; _rtB -> psegek4amn +=
_rtP -> P_1040 * _rtX -> jlmvybcsjd ; _rtB -> psegek4amn += _rtP -> P_1041 *
_rtB -> pgkpwhbsc4 ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
dn2qcnfz0e ) ; } } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock (
S , 153 , 40 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> oniodj5kfq = _rtP -> P_1063
* _rtB -> o35r2bitza ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 153 , 42 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
c3zsomlozp = _rtP -> P_1064 * _rtB -> bxtndmgqmx ; ssCallAccelRunBlock ( S ,
153 , 44 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> lyufktdgfx = _rtP -> P_1065 * _rtB
-> khmwcojnzo ; _rtB -> lpyg5tiryq = _rtP -> P_1066 * _rtB -> gy3bwl1ls4 ;
tmp_i = muDoubleScalarFloor ( _rtB -> lpyg5tiryq ) ; if ( muDoubleScalarIsNaN
( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> flmm52h1x3 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> n5ebaw1dlw = _rtP -> P_1067 * _rtB -> kw5mnvlloi ; tmp_i =
muDoubleScalarFloor ( _rtB -> n5ebaw1dlw ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> eoybpvfv2z = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
tmp_i = muDoubleScalarFloor ( _rtB -> c3zsomlozp ) ; if ( muDoubleScalarIsNaN
( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> jvteyyw3i0 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> idpqrpva3h = _rtP -> P_1068 * _rtB -> lyufktdgfx ; tmp_i =
muDoubleScalarFloor ( _rtB -> idpqrpva3h ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> juczvicn0a = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; }
if ( _rtB -> eg2ximy4us > _rtP -> P_1914 ) { _rtB -> m5uhzkm1xx = _rtP ->
P_69 * _rtB -> h30422l2pe ; _rtB -> lc02rf42na = _rtP -> P_70 * _rtB ->
m5uhzkm1xx ; tmp_i = muDoubleScalarFloor ( _rtB -> lc02rf42na ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB
-> fvx43vs55t = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T
) ( uint32_T ) tmp_i ; _rtB -> nsyttfxthv = _rtB -> fvx43vs55t ; } else {
_rtB -> fx5piksqux = _rtP -> P_67 * _rtB -> h30422l2pe ; _rtB -> et0gigikv1 =
_rtP -> P_68 * _rtB -> fx5piksqux ; tmp_i = muDoubleScalarFloor ( _rtB ->
et0gigikv1 ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> eby0ddxjye = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> nsyttfxthv =
_rtB -> eby0ddxjye ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1915 ) { _rtB ->
cmo0rbohkq = _rtP -> P_66 * _rtB -> bdi4cutj5c ; tmp_i = muDoubleScalarFloor
( _rtB -> cmo0rbohkq ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> obvia4iyzw = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> kod05ah0tm = _rtB -> obvia4iyzw ; } else { _rtB -> ntjgaeulrt = _rtP
-> P_65 * _rtB -> bdi4cutj5c ; tmp_i = muDoubleScalarFloor ( _rtB ->
ntjgaeulrt ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> n4ynexockw = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> kod05ah0tm =
_rtB -> n4ynexockw ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1916 ) { _rtB ->
bm5xsrn1ds = _rtP -> P_64 * _rtB -> ljpjqcelwl ; tmp_i = muDoubleScalarFloor
( _rtB -> bm5xsrn1ds ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> ldqs5q2fzq = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> hg5cxxqiik = _rtB -> ldqs5q2fzq ; } else { _rtB -> c4tls2mywg = _rtP
-> P_63 * _rtB -> ljpjqcelwl ; tmp_i = muDoubleScalarFloor ( _rtB ->
c4tls2mywg ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> h0qdcwnnwc = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> hg5cxxqiik =
_rtB -> h0qdcwnnwc ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1917 ) { _rtB ->
hv2gipflft = _rtP -> P_62 * _rtB -> l2bqvf23sw ; tmp_i = muDoubleScalarFloor
( _rtB -> hv2gipflft ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> glpr05svj1 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> kzn2ymhvck = _rtB -> glpr05svj1 ; } else { _rtB -> de0y13vzex = _rtP
-> P_61 * _rtB -> l2bqvf23sw ; tmp_i = muDoubleScalarFloor ( _rtB ->
de0y13vzex ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> e1hzlomsxt = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> kzn2ymhvck =
_rtB -> e1hzlomsxt ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1918 ) { _rtB ->
ixo4dr2qnf = _rtP -> P_60 * _rtB -> iv5whrzs4v ; tmp_i = muDoubleScalarFloor
( _rtB -> ixo4dr2qnf ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> cov5hwkdee = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> mqfeggvqw3 = _rtB -> cov5hwkdee ; } else { _rtB -> mqfeggvqw3 = _rtB
-> flmm52h1x3 ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1919 ) { _rtB ->
ky2xieegnc = _rtP -> P_59 * _rtB -> lapmd4hzd2 ; tmp_i = muDoubleScalarFloor
( _rtB -> ky2xieegnc ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> dfyptirnuz = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> feghqjqyx2 = _rtB -> dfyptirnuz ; } else { _rtB -> feghqjqyx2 = _rtB
-> eoybpvfv2z ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1920 ) { tmp_i =
muDoubleScalarFloor ( _rtB -> oniodj5kfq ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> fkf2csegpt = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> ebn2bmfx2o = _rtB -> fkf2csegpt ; } else { _rtB -> ebn2bmfx2o = _rtB
-> jvteyyw3i0 ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1921 ) { _rtB ->
f1bwonopsh = _rtP -> P_58 * _rtB -> mturxdyo12 ; tmp_i = muDoubleScalarFloor
( _rtB -> f1bwonopsh ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> fwbxsyqsk4 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> g15tcxra3w = _rtB -> fwbxsyqsk4 ; } else { _rtB -> k5gppkwt1p = _rtP
-> P_57 * _rtB -> mturxdyo12 ; tmp_i = muDoubleScalarFloor ( _rtB ->
k5gppkwt1p ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> mv2el1t5ye = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> g15tcxra3w =
_rtB -> mv2el1t5ye ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1922 ) { _rtB ->
bfcinyfb1h = _rtP -> P_56 * _rtB -> p0clgfvlwp ; tmp_i = muDoubleScalarFloor
( _rtB -> bfcinyfb1h ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> l1opgzdkvw = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> csn2g21y1q = _rtB -> l1opgzdkvw ; } else { _rtB -> hfwhsrwpgm = _rtP
-> P_55 * _rtB -> p0clgfvlwp ; tmp_i = muDoubleScalarFloor ( _rtB ->
hfwhsrwpgm ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> njobzqwxua = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> csn2g21y1q =
_rtB -> njobzqwxua ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1923 ) { _rtB ->
nxo2oxjgf0 = _rtP -> P_54 * _rtB -> jvggai4dyf ; tmp_i = muDoubleScalarFloor
( _rtB -> nxo2oxjgf0 ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> bmfhhs2mai = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> gdvkohd1nr = _rtB -> bmfhhs2mai ; } else { _rtB -> paqzmlylrb = _rtP
-> P_53 * _rtB -> jvggai4dyf ; tmp_i = muDoubleScalarFloor ( _rtB ->
paqzmlylrb ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> hynvdt5cbd = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> gdvkohd1nr =
_rtB -> hynvdt5cbd ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1924 ) { _rtB ->
mjkoyepisu = _rtP -> P_52 * _rtB -> dmiw5yjto3 ; tmp_i = muDoubleScalarFloor
( _rtB -> mjkoyepisu ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> nhc5widci4 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> l1st3mo1d3 = _rtB -> nhc5widci4 ; } else { _rtB -> nu3sptnci1 = _rtP
-> P_51 * _rtB -> dmiw5yjto3 ; tmp_i = muDoubleScalarFloor ( _rtB ->
nu3sptnci1 ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> d2glnwe1be = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> l1st3mo1d3 =
_rtB -> d2glnwe1be ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1925 ) { _rtB ->
ekianrzr5l = _rtP -> P_49 * _rtB -> lo10nterd2 ; _rtB -> a2hu4txkjg = _rtP ->
P_50 * _rtB -> ekianrzr5l ; tmp_i = muDoubleScalarFloor ( _rtB -> a2hu4txkjg
) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) {
tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ;
} _rtB -> miat3iu142 = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : (
int32_T ) ( uint32_T ) tmp_i ; _rtB -> mhq4af3e3a = _rtB -> miat3iu142 ; }
else { _rtB -> or12sgpt23 = _rtP -> P_47 * _rtB -> lo10nterd2 ; _rtB ->
m2s0u3fdie = _rtP -> P_48 * _rtB -> or12sgpt23 ; tmp_i = muDoubleScalarFloor
( _rtB -> m2s0u3fdie ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> n4pvfm21jm = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> mhq4af3e3a = _rtB -> n4pvfm21jm ; } if ( _rtB -> eg2ximy4us > _rtP ->
P_1926 ) { _rtB -> dlapkzy1hd = _rtP -> P_45 * _rtB -> d3345ldqkc ; _rtB ->
bm4qbgutwt = _rtP -> P_46 * _rtB -> dlapkzy1hd ; tmp_i = muDoubleScalarFloor
( _rtB -> bm4qbgutwt ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> gb145sp4gi = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> hn3ejdom3j = _rtB -> gb145sp4gi ; } else { _rtB -> hn3ejdom3j = _rtB
-> juczvicn0a ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1927 ) { _rtB ->
j5vqizpfc4 = _rtP -> P_43 * _rtB -> apdipb5rvr ; _rtB -> ba1r553gqr = _rtP ->
P_44 * _rtB -> j5vqizpfc4 ; tmp_i = muDoubleScalarFloor ( _rtB -> ba1r553gqr
) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) {
tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ;
} _rtB -> jtcuha1mzp = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : (
int32_T ) ( uint32_T ) tmp_i ; _rtB -> n3sh1juvop = _rtB -> jtcuha1mzp ; }
else { _rtB -> kyhungjy0f = _rtP -> P_41 * _rtB -> apdipb5rvr ; _rtB ->
bjlsebva54 = _rtP -> P_42 * _rtB -> kyhungjy0f ; tmp_i = muDoubleScalarFloor
( _rtB -> bjlsebva54 ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> ksr1lk2xfw = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> n3sh1juvop = _rtB -> ksr1lk2xfw ; } if ( _rtB -> eg2ximy4us > _rtP ->
P_1928 ) { _rtB -> pojnexhoe2 = _rtP -> P_39 * _rtB -> nfbrahf0bs ; _rtB ->
iecvpxsxdl = _rtP -> P_40 * _rtB -> pojnexhoe2 ; tmp_i = muDoubleScalarFloor
( _rtB -> iecvpxsxdl ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> dyb1gkvcts = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> egdsgunxk3 = _rtB -> dyb1gkvcts ; } else { _rtB -> potqwdhq3x = _rtP
-> P_37 * _rtB -> nfbrahf0bs ; _rtB -> lvydewnsdt = _rtP -> P_38 * _rtB ->
potqwdhq3x ; tmp_i = muDoubleScalarFloor ( _rtB -> lvydewnsdt ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB
-> jba0fzhwpk = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T
) ( uint32_T ) tmp_i ; _rtB -> egdsgunxk3 = _rtB -> jba0fzhwpk ; } if ( _rtB
-> eg2ximy4us > _rtP -> P_1929 ) { _rtB -> hxs4su0v2y = _rtP -> P_35 * _rtB
-> kq2uh3cg4j ; _rtB -> nvcxajch1r = _rtP -> P_36 * _rtB -> hxs4su0v2y ;
tmp_i = muDoubleScalarFloor ( _rtB -> nvcxajch1r ) ; if ( muDoubleScalarIsNaN
( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> b5klvdbvy1 = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> nknqzbeotg = _rtB -> b5klvdbvy1 ; } else { _rtB -> hqhm1lwwlu = _rtP
-> P_33 * _rtB -> kq2uh3cg4j ; _rtB -> nudpadrhfc = _rtP -> P_34 * _rtB ->
hqhm1lwwlu ; tmp_i = muDoubleScalarFloor ( _rtB -> nudpadrhfc ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB
-> kvybhgcath = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T
) ( uint32_T ) tmp_i ; _rtB -> nknqzbeotg = _rtB -> kvybhgcath ; } if ( _rtB
-> eg2ximy4us > _rtP -> P_1930 ) { _rtB -> hanyoocucz = _rtP -> P_32 * _rtB
-> lokuksnsb1 ; tmp_i = muDoubleScalarFloor ( _rtB -> hanyoocucz ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB
-> jdwjcphf1x = tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T
) ( uint32_T ) tmp_i ; _rtB -> gtq4uslwd1 = _rtB -> jdwjcphf1x ; } else {
_rtB -> fty2bwu20u = _rtP -> P_31 * _rtB -> lokuksnsb1 ; tmp_i =
muDoubleScalarFloor ( _rtB -> fty2bwu20u ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> if5i4ycqhw = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> gtq4uslwd1 = _rtB -> if5i4ycqhw ; } if ( _rtB -> eg2ximy4us > _rtP ->
P_1931 ) { _rtB -> l23ne1msto = _rtP -> P_30 * _rtB -> gnrlfvtovj ; tmp_i =
muDoubleScalarFloor ( _rtB -> l23ne1msto ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> dagbadj1fd = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> htb2pqmcpw = _rtB -> dagbadj1fd ; } else { _rtB -> n0zyvlak0o = _rtP
-> P_29 * _rtB -> gnrlfvtovj ; tmp_i = muDoubleScalarFloor ( _rtB ->
n0zyvlak0o ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> dbo12ezcuv = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> htb2pqmcpw =
_rtB -> dbo12ezcuv ; } if ( _rtB -> eg2ximy4us > _rtP -> P_1932 ) { _rtB ->
d2wsms2cki = _rtP -> P_28 * _rtB -> piqr25abhc ; tmp_i = muDoubleScalarFloor
( _rtB -> d2wsms2cki ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> gncw4qktxu = tmp_i <
0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ;
_rtB -> ekqwtebx3k = _rtB -> gncw4qktxu ; } else { _rtB -> czv0riowdp = _rtP
-> P_27 * _rtB -> piqr25abhc ; tmp_i = muDoubleScalarFloor ( _rtB ->
czv0riowdp ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i ,
4.294967296E+9 ) ; } _rtB -> azeuyrqdvh = tmp_i < 0.0 ? - ( int32_T ) (
uint32_T ) - tmp_i : ( int32_T ) ( uint32_T ) tmp_i ; _rtB -> ekqwtebx3k =
_rtB -> azeuyrqdvh ; } _rtB -> jwrdzs44fl = _rtB -> feghqjqyx2 ; _rtB ->
c2xzpu5xzk = _rtP -> P_1082 * _rtB -> jwrdzs44fl ; _rtB -> n0gvzmsd1x = _rtB
-> mqfeggvqw3 ; _rtB -> e14bksapzg = _rtP -> P_1083 * _rtB -> n0gvzmsd1x ;
_rtB -> og5ajsvxqd = _rtB -> ebn2bmfx2o ; _rtB -> mygo3tfeep = _rtP -> P_1084
* _rtB -> og5ajsvxqd ; ssCallAccelRunBlock ( S , 79 , 0 , SS_CALL_MDL_OUTPUTS
) ; ssCallAccelRunBlock ( S , 154 , 37 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 38 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
ngzzz0gtcn = ( real32_T ) _rtB -> mygo3tfeep ; ssCallAccelRunBlock ( S , 154
, 40 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> o22lf041rw = _rtB -> ngzzz0gtcn - _rtB
-> oucmybi2ax ; ssCallAccelRunBlock ( S , 154 , 42 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 43 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
d23uygn3y2 = _rtB -> kod05ah0tm ; _rtB -> f4slbqafxh = _rtP -> P_1085 * _rtB
-> d23uygn3y2 ; _rtB -> lb2byb25qd = ( real32_T ) _rtB -> f4slbqafxh ;
ssCallAccelRunBlock ( S , 154 , 47 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
l1ztlqsuvz = _rtB -> hg5cxxqiik ; _rtB -> pbulxg31nh = _rtP -> P_1086 * _rtB
-> l1ztlqsuvz ; _rtB -> fy4tddm1yo = ( real32_T ) _rtB -> pbulxg31nh ;
ssCallAccelRunBlock ( S , 154 , 51 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
c24hfw2yx2 = _rtB -> kzn2ymhvck ; _rtB -> kzi4hol2ob = _rtP -> P_1087 * _rtB
-> c24hfw2yx2 ; _rtB -> bk0tstus21 = _rtP -> P_1088 * _rtB -> kzi4hol2ob ;
_rtB -> j2n514retq = ( real32_T ) _rtB -> bk0tstus21 ; ssCallAccelRunBlock (
S , 154 , 56 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cbeoywyaga = _rtB ->
g15tcxra3w ; _rtB -> hbobzcmhny = _rtP -> P_1089 * _rtB -> cbeoywyaga ; _rtB
-> oayszaxkmu = _rtP -> P_1090 * _rtB -> hbobzcmhny ; _rtB -> g4rqw1aoxq = (
real32_T ) _rtB -> oayszaxkmu ; ssCallAccelRunBlock ( S , 154 , 61 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> en1t3hn23z = _rtB -> csn2g21y1q ; _rtB ->
jizphvlxej = _rtP -> P_1091 * _rtB -> en1t3hn23z ; _rtB -> kinkjvriza = _rtP
-> P_1092 * _rtB -> jizphvlxej ; _rtB -> lsch5ilavg = ( real32_T ) _rtB ->
kinkjvriza ; ssCallAccelRunBlock ( S , 154 , 66 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> hzkjqx32ar = _rtB -> mhq4af3e3a ; _rtB -> asvcpbfdau = _rtP -> P_1093
* _rtB -> hzkjqx32ar ; _rtB -> m3jhdrdkxv = _rtP -> P_1094 * _rtB ->
asvcpbfdau ; _rtB -> i015g3sofk = ( real32_T ) _rtB -> m3jhdrdkxv ;
ssCallAccelRunBlock ( S , 154 , 71 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
gh4p44rxnt = _rtB -> nsyttfxthv ; _rtB -> k4jn5zuu4u = _rtP -> P_1095 * _rtB
-> gh4p44rxnt ; _rtB -> igjglmeiae = _rtP -> P_1096 * _rtB -> k4jn5zuu4u ;
_rtB -> iebtux4sot = ( real32_T ) _rtB -> igjglmeiae ; ssCallAccelRunBlock (
S , 154 , 76 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> g5uge3pyvt = _rtB ->
hn3ejdom3j ; _rtB -> ml1cnwb2id = _rtP -> P_1097 * _rtB -> g5uge3pyvt ; _rtB
-> hevf5or1u1 = _rtP -> P_1098 * _rtB -> ml1cnwb2id ; _rtB -> axzozhbobc = (
real32_T ) _rtB -> hevf5or1u1 ; ssCallAccelRunBlock ( S , 154 , 81 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> o0a0swnwyu = muSingleScalarAtan2 ( _rtB ->
fy4tddm1yo , _rtB -> lb2byb25qd ) ; _rtB -> cdnqpdqorz = _rtP -> P_1481 *
_rtB -> o0a0swnwyu ; ssCallAccelRunBlock ( S , 154 , 84 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> jmmfruqzpc = _rtB -> n3sh1juvop ; _rtB -> pd4bsqpfum = _rtP ->
P_1099 * _rtB -> jmmfruqzpc ; _rtB -> iqctzjjuul = _rtP -> P_1100 * _rtB ->
pd4bsqpfum ; _rtB -> pzhfw2fiqz = ( real32_T ) _rtB -> iqctzjjuul ;
ssCallAccelRunBlock ( S , 154 , 89 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
acti03xoho = _rtB -> egdsgunxk3 ; _rtB -> l1eh5cwlbd = _rtP -> P_1101 * _rtB
-> acti03xoho ; _rtB -> nqoo4mo0rj = _rtP -> P_1102 * _rtB -> l1eh5cwlbd ;
_rtB -> ejvtxiit0x = ( real32_T ) _rtB -> nqoo4mo0rj ; ssCallAccelRunBlock (
S , 154 , 94 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ieoati042q = _rtB ->
nknqzbeotg ; _rtB -> mcnv335ube = _rtP -> P_1103 * _rtB -> ieoati042q ; _rtB
-> dojk3giwx0 = _rtP -> P_1104 * _rtB -> mcnv335ube ; _rtB -> i2lsmesory = (
real32_T ) _rtB -> dojk3giwx0 ; ssCallAccelRunBlock ( S , 154 , 99 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> bki3honqgw = _rtB -> gtq4uslwd1 ; _rtB ->
f1vriqdlfp = _rtP -> P_1105 * _rtB -> bki3honqgw ; _rtB -> nwfmycvwhk = _rtP
-> P_1106 * _rtB -> f1vriqdlfp ; _rtB -> ii2mien4wv = ( real32_T ) _rtB ->
nwfmycvwhk ; ssCallAccelRunBlock ( S , 154 , 104 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> iepwyxogvj = _rtB -> htb2pqmcpw ; _rtB -> dttiqmlrux = _rtP -> P_1107
* _rtB -> iepwyxogvj ; _rtB -> lwjq31asgi = _rtP -> P_1108 * _rtB ->
dttiqmlrux ; _rtB -> cwekfyyy1c = ( real32_T ) _rtB -> lwjq31asgi ;
ssCallAccelRunBlock ( S , 154 , 109 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
o5yshp0fax = _rtB -> ekqwtebx3k ; _rtB -> nuymjdrtq4 = _rtP -> P_1109 * _rtB
-> o5yshp0fax ; _rtB -> ojflmdiaef = _rtP -> P_1110 * _rtB -> nuymjdrtq4 ;
_rtB -> b1apgnyjax = ( real32_T ) _rtB -> ojflmdiaef ; ssCallAccelRunBlock (
S , 154 , 114 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> lvofyymvhi = _rtB ->
lb2byb25qd * _rtB -> lb2byb25qd ; _rtB -> mkixoulhbu = _rtB -> fy4tddm1yo *
_rtB -> fy4tddm1yo ; _rtB -> fefc13wlpp = _rtB -> j2n514retq * _rtB ->
j2n514retq ; _rtB -> orn0byycu3 = ( _rtB -> lvofyymvhi + _rtB -> mkixoulhbu )
+ _rtB -> fefc13wlpp ; _rtB -> efos2jeknq = muSingleScalarSqrt ( _rtB ->
orn0byycu3 ) ; _rtB -> pgghzidifi = _rtB -> efos2jeknq ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { _rtB -> ovfymd0itt = _rtP -> P_1112 ; _rtB -> aygpth4rxt =
_rtP -> P_1819 ; _rtB -> ctrhqhcort = _rtDW -> mk1bzf5kc5 ; _rtB ->
diisufxha0 = ( _rtB -> aygpth4rxt == _rtB -> ctrhqhcort ) ; _rtB ->
gnkbborzyx = _rtP -> P_1821 ; _rtB -> cxurwveome = ( _rtB -> ctrhqhcort ==
_rtB -> gnkbborzyx ) ; _rtB -> jj2lrustak = _rtP -> P_1822 ; _rtB ->
j4vu0zpiod = ( _rtB -> ctrhqhcort == _rtB -> jj2lrustak ) ; _rtB ->
ivdbqwy5ni = ( _rtB -> diisufxha0 || _rtB -> cxurwveome || _rtB -> j4vu0zpiod
) ; _rtB -> d2qc4t0zny = _rtP -> P_1113 ; for ( i = 0 ; i < 30 ; i ++ ) {
_rtB -> me0qesxrdr [ i ] = _rtP -> P_1114 [ i ] ; tmp_i = muDoubleScalarFloor
( _rtB -> me0qesxrdr [ i ] ) ; if ( muDoubleScalarIsNaN ( tmp_i ) ||
muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 4.294967296E+9 ) ; } _rtB -> nq4y224msj [ i ] =
tmp_i < 0.0 ? - ( int32_T ) ( uint32_T ) - tmp_i : ( int32_T ) ( uint32_T )
tmp_i ; } _rtB -> a1t54dacty = _rtP -> P_1823 ; } _rtB -> nfd1nyu2wa = ( _rtB
-> pgghzidifi < _rtB -> d2qc4t0zny ) ; _rtB -> f0pk30mvyq = ( _rtB ->
ivdbqwy5ni && _rtB -> nfd1nyu2wa ) ; if ( ssGetTaskTime ( S , 0 ) < _rtP ->
P_1115 ) { _rtB -> btffunkzkz = _rtP -> P_1116 ; } else { _rtB -> btffunkzkz
= _rtP -> P_1117 ; } _rtB -> p0nvi2d2qb = ( real_T ) _rtB -> a1t54dacty -
_rtB -> btffunkzkz ; tmp_i = muDoubleScalarFloor ( _rtB -> p0nvi2d2qb ) ; if
( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 256.0 ) ; } _rtB ->
ispaxxr3su = ( int8_T ) ( tmp_i < 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) (
uint8_T ) - tmp_i : ( int32_T ) ( int8_T ) ( uint8_T ) tmp_i ) ; _rtB ->
e5xucv32lp = ( _rtB -> ispaxxr3su == _rtB -> jjr1xk2sxt ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { if ( _rtB ->
e5xucv32lp ) { if ( ! _rtDW -> bkjfcdd5xd ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 42 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; _rtDW -> bkjfcdd5xd = true ; } }
else { if ( _rtDW -> bkjfcdd5xd ) { ssSetSolverNeedsReset ( S ) ;
ssCallAccelRunBlock ( S , 42 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ; _rtDW ->
bkjfcdd5xd = false ; } } } if ( _rtDW -> bkjfcdd5xd ) { _rtB -> me0gfqi1xi =
_rtB -> mxcxqjg10g ; ssCallAccelRunBlock ( S , 42 , 0 , SS_CALL_MDL_OUTPUTS )
; memcpy ( & _rtB -> dw5mjylj3q [ 0 ] , & _rtB -> fv3vqb4da1 [ 0 ] , 120U *
sizeof ( real_T ) ) ; if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
ckgmlu3gif ) ; } } _rtB -> pkxyv3cuyj = _rtDW -> ai4ll2tnnp ; }
ssCallAccelRunBlock ( S , 40 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 39 , 0 , SS_CALL_MDL_OUTPUTS ) ;
} ssCallAccelRunBlock ( S , 38 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
k1lgoiummi = ( real32_T ) _rtB -> kgsccfxpx2 ; _rtB -> f1eo5eyixo = (
real32_T ) _rtB -> d452enk4yz ; _rtB -> gppzbm1uw3 = ( real32_T ) _rtB ->
fgmxjckedf ; _rtB -> bruolx4y2o = ( real32_T ) _rtB -> dkdue2vpua ; _rtB ->
jmefmabd5r = ( real32_T ) _rtB -> bmvfdjo1uj ; _rtB -> nzvb4zcmgl = (
real32_T ) _rtB -> lrrrx3ubg5 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ohgdwxd5vf = _rtP -> P_1482 ; _rtB -> gt50kuzpls = _rtDW -> hb0rwwvarv ; }
ssCallAccelRunBlock ( S , 37 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
gt50kuzpls > _rtP -> P_1827 ) { _rtB -> l4jcezyo5f [ 0 ] = _rtB -> fkmbzv245d
; _rtB -> l4jcezyo5f [ 1 ] = _rtB -> ivhuftrk2u ; _rtB -> l4jcezyo5f [ 2 ] =
_rtB -> akpozbykdf ; _rtB -> l4jcezyo5f [ 3 ] = _rtB -> d2v5uhzrvt ; _rtB ->
l4jcezyo5f [ 4 ] = _rtB -> ivhuftrk2u ; _rtB -> l4jcezyo5f [ 5 ] = _rtB ->
ewzkoiuszk ; _rtB -> l4jcezyo5f [ 6 ] = _rtB -> fxu3rnxssr ; } else { _rtB ->
l4jcezyo5f [ 0 ] = _rtB -> mhudf1ck1w ; _rtB -> l4jcezyo5f [ 1 ] = _rtB ->
guvm3a4myq ; _rtB -> l4jcezyo5f [ 2 ] = _rtB -> nskm5dxmzy ; _rtB ->
l4jcezyo5f [ 3 ] = _rtB -> m3i55ibo45 ; _rtB -> l4jcezyo5f [ 4 ] = _rtB ->
guvm3a4myq ; _rtB -> l4jcezyo5f [ 5 ] = _rtB -> jt2b30v351 ; _rtB ->
l4jcezyo5f [ 6 ] = _rtB -> bbznxbks3e ; } _rtB -> dsh0uuglgl = _rtB ->
l4jcezyo5f [ 6 ] ; _rtB -> im2si1phyo = _rtB -> l4jcezyo5f [ 5 ] ; _rtB ->
h3as4hupuz = _rtP -> P_1483 * _rtB -> im2si1phyo ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { ssCallAccelRunBlock ( S , 44 , 0 , SS_CALL_MDL_OUTPUTS ) ; } if (
_rtB -> f0pk30mvyq ) { _rtB -> bybgewuvfp = _rtB -> ovfymd0itt ; } else {
_rtB -> b0dbmebczj = muSingleScalarAtan2 ( _rtB -> dsh0uuglgl , _rtB ->
guiyba43yl ) ; _rtB -> h2ikdnvjds = _rtP -> P_1458 * _rtB -> b0dbmebczj ;
_rtB -> bybgewuvfp = _rtB -> h2ikdnvjds ; } _rtB -> biih154ez0 = ( real32_T )
_rtB -> bybgewuvfp ; _rtB -> nyy4wjj131 = _rtB -> l4jcezyo5f [ 2 ] ; _rtB ->
mv3o514juk = _rtB -> ngzzz0gtcn ; ssCallAccelRunBlock ( S , 36 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
euperd3scl = _rtP -> P_1828 ; } if ( _rtB -> euperd3scl > _rtP -> P_1829 ) {
_rtB -> ok43gvj1ov = _rtP -> P_4 * _rtB -> dfl5bstojz ; _rtB -> l0bgles0vn =
_rtB -> pgghzidifi * _rtB -> pgghzidifi ; _rtB -> iuzbgpfu0s = _rtB ->
l0bgles0vn * _rtB -> ok43gvj1ov ; _rtB -> drgeiomwnt = _rtB -> iuzbgpfu0s ; }
else { _rtB -> dye3rzretb = _rtB -> gdvkohd1nr ; _rtB -> c3voqtllle = _rtP ->
P_3 * _rtB -> dye3rzretb ; _rtB -> drgeiomwnt = _rtB -> c3voqtllle ; } _rtB
-> gssrjaxgcv = ( real32_T ) _rtB -> drgeiomwnt ; _rtB -> hkyo0upbra = _rtP
-> P_1484 * _rtB -> gssrjaxgcv ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
gfuzjb1md3 = _rtP -> P_1485 ; } _rtB -> lrgh3gvwel = _rtB -> dfl5bstojz /
_rtB -> gfuzjb1md3 ; _rtB -> nwddevyreb = muDoubleScalarSqrt ( _rtB ->
lrgh3gvwel ) ; if ( _rtB -> euperd3scl > _rtP -> P_1830 ) { _rtB ->
o3lru22swu = _rtB -> pgghzidifi ; } else { _rtB -> cyfmobacgn = _rtB ->
l1st3mo1d3 ; _rtB -> migukhwj3l = _rtP -> P_5 * _rtB -> cyfmobacgn ; _rtB ->
o3lru22swu = _rtB -> migukhwj3l ; } _rtB -> afqv2lgkv0 = ( real32_T ) _rtB ->
o3lru22swu ; _rtB -> grb4pchyai = _rtB -> nwddevyreb * _rtB -> afqv2lgkv0 ;
_rtB -> cxaqvo5102 = ( real32_T ) _rtB -> grb4pchyai ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> n1vi5fcnhe = _rtP -> P_1486 ; if ( _rtB -> n1vi5fcnhe >
_rtP -> P_1487 ) { _rtB -> fl232yglvc = _rtP -> P_1487 ; } else if ( _rtB ->
n1vi5fcnhe < _rtP -> P_1488 ) { _rtB -> fl232yglvc = _rtP -> P_1488 ; } else
{ _rtB -> fl232yglvc = _rtB -> n1vi5fcnhe ; } _rtB -> cotm3q420f = _rtP ->
P_1831 ; } if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_1119 ) { _rtB ->
fz3xvhlg5u = _rtP -> P_1120 ; } else { _rtB -> fz3xvhlg5u = _rtP -> P_1121 ;
} tmp_i = muDoubleScalarFloor ( _rtB -> fz3xvhlg5u ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 256.0 ) ; } _rtB ->
lfy1l03fbx . StartEngine_qgc = ( int8_T ) ( tmp_i < 0.0 ? ( int32_T ) (
int8_T ) - ( int8_T ) ( uint8_T ) - tmp_i : ( int32_T ) ( int8_T ) ( uint8_T
) tmp_i ) ; tmp_i = muDoubleScalarFloor ( _rtB -> c3muk1ao42 ) ; if (
muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i =
0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 256.0 ) ; } _rtB ->
lfy1l03fbx . TakeoffFg_qgc = ( int8_T ) ( tmp_i < 0.0 ? ( int32_T ) ( int8_T
) - ( int8_T ) ( uint8_T ) - tmp_i : ( int32_T ) ( int8_T ) ( uint8_T ) tmp_i
) ; if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_1124 ) { _rtB -> o4cjlyxwi0 =
_rtP -> P_1125 ; } else { _rtB -> o4cjlyxwi0 = _rtP -> P_1126 ; } tmp_i =
muDoubleScalarFloor ( _rtB -> o4cjlyxwi0 ) ; if ( muDoubleScalarIsNaN ( tmp_i
) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 256.0 ) ; } _rtB -> lfy1l03fbx . INS_switch = (
int8_T ) ( tmp_i < 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) -
tmp_i : ( int32_T ) ( int8_T ) ( uint8_T ) tmp_i ) ; if ( ssGetTaskTime ( S ,
0 ) < _rtP -> P_1127 ) { _rtB -> be4423cc3y = _rtP -> P_1128 ; } else { _rtB
-> be4423cc3y = _rtP -> P_1129 ; } tmp_i = muDoubleScalarFloor ( _rtB ->
be4423cc3y ) ; if ( muDoubleScalarIsNaN ( tmp_i ) || muDoubleScalarIsInf (
tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i = muDoubleScalarRem ( tmp_i , 256.0
) ; } _rtB -> lfy1l03fbx . INSIntegralClear_Fg = ( int8_T ) ( tmp_i < 0.0 ? (
int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) - tmp_i : ( int32_T ) ( int8_T
) ( uint8_T ) tmp_i ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
fxz5v1npll = _rtDW -> ofybqkqhqt ; _rtB -> pdx5levc3x = _rtDW -> ll42raa0oa ;
_rtB -> bd1xqyjhtq = _rtDW -> ekbyf5uzmq ; _rtB -> meoixgyrir = _rtDW ->
dfi5fmg2dj ; _rtB -> djyrw5n05m = ( _rtB -> bd1xqyjhtq != 0 ) ^ ( _rtB ->
meoixgyrir != 0 ) ; _rtB -> llg5tl5k4f = _rtDW -> k00p0ildsb ; _rtB ->
awamssk44j = ( uint32_T ) _rtB -> llg5tl5k4f ; } _rtB -> e4bhidfe03 [ 0 ] =
_rtB -> e14bksapzg ; _rtB -> e4bhidfe03 [ 1 ] = _rtB -> c2xzpu5xzk ; _rtB ->
e4bhidfe03 [ 2 ] = _rtB -> mygo3tfeep ; _rtB -> e4bhidfe03 [ 3 ] = _rtB ->
f4slbqafxh ; _rtB -> e4bhidfe03 [ 4 ] = _rtB -> pbulxg31nh ; _rtB ->
e4bhidfe03 [ 5 ] = _rtB -> kzi4hol2ob ; ssCallAccelRunBlock ( S , 80 , 1 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 82 , 3 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> nimuaueuaa
[ 0 ] = _rtB -> bs5nbgvcnf ; _rtB -> nimuaueuaa [ 1 ] = _rtB -> nwut3djpc0 ;
_rtB -> nimuaueuaa [ 2 ] = _rtB -> i4evt0refb ; ssCallAccelRunBlock ( S , 82
, 5 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> cry0tcymiy = _rtB -> llg5tl5k4f + _rtB
-> jj3avp2qre ; if ( _rtB -> cry0tcymiy > _rtP -> P_1215 ) { _rtB ->
f1ephbjun5 = _rtB -> lslrsz2w5h ; } else { _rtB -> f1ephbjun5 = _rtB ->
cry0tcymiy ; } } ssCallAccelRunBlock ( S , 81 , 0 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> lfy1l03fbx . guidance . altcmd = ( real32_T ) _rtB -> bj4cv2xl11 ;
_rtB -> lfy1l03fbx . guidance . ascmd = ( real32_T ) _rtB -> c3ogplaavk ;
_rtB -> lfy1l03fbx . guidance . targetpoint = ( int8_T ) _rtB -> crajb0qdym ;
_rtB -> lfy1l03fbx . guidance . ytrack = 0.0F ; _rtB -> lfy1l03fbx . guidance
. headingcmd = 0.0F ; _rtB -> lfy1l03fbx . guidance . dtocenter = 0.0F ; _rtB
-> lfy1l03fbx . guidance . dtoTarget = 0.0F ; _rtB -> lfy1l03fbx . guidance .
currentPoint = 0 ; _rtB -> lfy1l03fbx . decl_qgc = _rtB -> njttdzg5pg ; _rtB
-> lfy1l03fbx . dacl_qgc = _rtB -> mb4nzgj5qu ; _rtB -> lfy1l03fbx . drcl_qgc
= _rtB -> hxfb0tmmyu ; _rtB -> lfy1l03fbx . nwscl_qgc = _rtB -> ldjvo1h31f ;
_rtB -> lfy1l03fbx . sbcl_qgc = _rtB -> bccwan41tw ; _rtB -> lfy1l03fbx .
Taxi_Fg = _rtB -> lvh2iu2nbc ; _rtB -> lfy1l03fbx . LockFg_qgc = _rtB ->
dow3opkv5g ; _rtB -> lfy1l03fbx . EmergenReturnFg = 0 ; _rtB -> lfy1l03fbx .
EmergenLandFg = 0 ; _rtB -> lfy1l03fbx . VcVtCutFg = 0 ; _rtB -> lfy1l03fbx .
IniposCalFg = 0 ; _rtB -> iqnui0ziwd = _rtB -> lfy1l03fbx . LockFg_qgc ; _rtB
-> g3uoopeq41 = ( _rtB -> iqnui0ziwd == _rtB -> fvdb0lzwq1 ) ; _rtB ->
cn03muzz4i = ( int8_T ) _rtB -> g3uoopeq41 ; if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> cx0nwyxmxn = _rtP -> P_1836 ; _rtB -> ig4o0wk5nu = _rtP -> P_1837
; } _rtB -> jr0rpv2irz = ( _rtB -> cn03muzz4i == _rtB -> cx0nwyxmxn ) ; if (
_rtB -> jr0rpv2irz ) { _rtB -> azarpgjmdw = _rtB -> cotm3q420f ; } else {
_rtB -> azarpgjmdw = _rtB -> ig4o0wk5nu ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtB -> b45rv03vtx = _rtP -> P_1838 ; } if ( ssGetTaskTime ( S , 0 ) <
_rtP -> P_1132 ) { _rtB -> ea2ch2oeos = _rtP -> P_1133 ; } else { _rtB ->
ea2ch2oeos = _rtP -> P_1134 ; } if ( ssGetTaskTime ( S , 0 ) < _rtP -> P_1135
) { _rtB -> hxlvldjttd = _rtP -> P_1136 ; } else { _rtB -> hxlvldjttd = _rtP
-> P_1137 ; } _rtB -> lyocfmitmo = _rtB -> ea2ch2oeos + _rtB -> hxlvldjttd ;
tmp_i = muDoubleScalarFloor ( _rtB -> lyocfmitmo ) ; if ( muDoubleScalarIsNaN
( tmp_i ) || muDoubleScalarIsInf ( tmp_i ) ) { tmp_i = 0.0 ; } else { tmp_i =
muDoubleScalarRem ( tmp_i , 256.0 ) ; } _rtB -> mgz0ykmi4i = ( int8_T ) (
tmp_i < 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) - tmp_i : (
int32_T ) ( int8_T ) ( uint8_T ) tmp_i ) ; _rtB -> evtyu52lyk = ( _rtB ->
mgz0ykmi4i >= _rtB -> mk4mseeysw ) ; _rtB -> mggsaskpmp = ( int8_T ) _rtB ->
evtyu52lyk ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 6
, 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> b45rv03vtx > _rtP -> P_1840 ) {
_rtB -> bguo5vgtiw = _rtP -> P_1735 ; } else { _rtB -> bguo5vgtiw = _rtB ->
kkc0tdytgr ; } _rtB -> nswcuxh11s = ! ( _rtB -> bguo5vgtiw != 0 ) ; _rtB ->
lupsjt1q4x = _rtP -> P_1841 ; _rtB -> ce5ju5yotp = _rtP -> P_1844 ; } _rtB ->
hkjpbenais = _rtB -> lfy1l03fbx . StartEngine_qgc ; _rtB -> pmdv03ctap = (
_rtB -> hkjpbenais == _rtB -> cpplkk4uwf ) ; if ( _rtB -> pmdv03ctap ) { _rtB
-> ngh1crjcxs = ( int8_T ) ( _rtB -> lfy1l03fbx . TakeoffFg_qgc == _rtB ->
aksw4mqnzr ) ; } else { _rtB -> ngh1crjcxs = _rtB -> ce5ju5yotp ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> aeknljlnbj = _rtDW -> kk1jzqnnxn ;
_rtB -> jpfukp3ig5 = _rtDW -> a0crd4prk2 ; _rtB -> c1jehlmfbl = _rtDW ->
aniqqbzlgr ; _rtB -> ekvuqtwwht = _rtDW -> pmevyjdenu ; _rtB -> hpvr5z2r34 =
_rtDW -> apduj42log ; _rtB -> asyglfl2hv = _rtDW -> octl2ppvtx ; _rtB ->
mydrzyuhr4 = _rtDW -> gfvjsifc4g ; ssCallAccelRunBlock ( S , 46 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> j1ox4kyl0i = _rtP -> P_1852 ; _rtB ->
mjb1vmhccz = ( _rtB -> joh40kiala == _rtB -> j1ox4kyl0i ) ; _rtB ->
bvhhaniosm = _rtP -> P_1853 ; _rtB -> av2t44u2xc = _rtP -> P_1854 ; } _rtB ->
m2bsjsty1f = ( _rtB -> azarpgjmdw == _rtB -> bvhhaniosm ) ; _rtB ->
h1z0uafdyv = ( _rtB -> mjb1vmhccz && _rtB -> m2bsjsty1f ) ; if ( _rtB ->
h1z0uafdyv ) { _rtB -> nxkv1zbpr3 = _rtB -> ngh1crjcxs ; } else { _rtB ->
nxkv1zbpr3 = _rtB -> av2t44u2xc ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB
-> p0spk2psqv = _rtP -> P_1855 ; _rtB -> b1wx55cjjc = _rtP -> P_1856 ; } _rtB
-> b2x3cgxe1g = ( _rtB -> nxkv1zbpr3 == _rtB -> p0spk2psqv ) ; _rtB ->
jfbfwhghur = ( _rtB -> azarpgjmdw == _rtB -> b1wx55cjjc ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> plkmdhym05 = _rtP -> P_1857 ; _rtB ->
j0h2clre4b = ( _rtB -> joh40kiala == _rtB -> plkmdhym05 ) ; _rtB ->
iatiyugaub = _rtP -> P_1858 ; _rtB -> cbsv5mtquy = ( _rtB -> iatiyugaub >=
_rtB -> mhbprhznje ) ; _rtB -> n4qg231lvs = ( int8_T ) _rtB -> cbsv5mtquy ;
ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
b45rv03vtx > _rtP -> P_1860 ) { _rtB -> ciq5ymh5ja = _rtP -> P_1734 ; } else
{ _rtB -> ciq5ymh5ja = _rtB -> nk51r5lqxm ; } _rtB -> gg0bqpudbo = _rtP ->
P_1861 ; _rtB -> ciphz2qj2n = ( _rtB -> ciq5ymh5ja == _rtB -> gg0bqpudbo ) ;
_rtB -> kixjt1gdfh = _rtP -> P_1862 ; } _rtB -> iib0lsxaim = ( _rtB ->
b2x3cgxe1g && _rtB -> jfbfwhghur && _rtB -> j0h2clre4b && _rtB -> ciphz2qj2n
) ; if ( _rtB -> iib0lsxaim ) { _rtB -> eubvsps4x2 = _rtB -> lupsjt1q4x ; }
else { _rtB -> eubvsps4x2 = _rtB -> kixjt1gdfh ; } if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtB -> ngclm4zzxv = _rtP -> P_1863 ; _rtB -> cryv0io0f3 = _rtDW ->
b4jn1iqhjp ; _rtB -> prvmenxii4 = _rtP -> P_1865 ; _rtB -> gfkd03naj4 = (
_rtB -> cryv0io0f3 == _rtB -> prvmenxii4 ) ; _rtB -> fyqkr41ba0 = _rtP ->
P_1866 ; _rtB -> e4khpobiam = ( _rtB -> fyqkr41ba0 == _rtB -> joh40kiala ) ;
_rtB -> jsk3qk05te = ( _rtB -> gfkd03naj4 && _rtB -> e4khpobiam ) ; _rtB ->
jq2c015k1v = _rtP -> P_1867 ; _rtB -> dwi2v43fhf = ( _rtB -> joh40kiala ==
_rtB -> jq2c015k1v ) ; _rtB -> bwmd11egrl = _rtP -> P_1868 ; _rtB ->
lgr0wchjju = ( _rtB -> joh40kiala == _rtB -> bwmd11egrl ) ; _rtB ->
ltwd1thzcc = _rtP -> P_1869 ; _rtB -> ih0nonrote = ( _rtB -> joh40kiala ==
_rtB -> ltwd1thzcc ) ; _rtB -> lys5kwbhy4 = _rtP -> P_1489 ; } _rtB ->
jn54ueoms4 = ( _rtB -> eubvsps4x2 == _rtB -> ngclm4zzxv ) ; _rtB ->
gevrxmvpac = ( _rtB -> nswcuxh11s || _rtB -> jn54ueoms4 ) ; _rtB ->
nxl5ohwsbx = ( int8_T ) _rtB -> gevrxmvpac ; _rtB -> h4ts5av20r = ( _rtB ->
o22lf041rw < _rtB -> lys5kwbhy4 ) ; _rtB -> jv5ewvm1oz = ( _rtB -> ih0nonrote
&& _rtB -> h4ts5av20r ) ; _rtB -> gdftfi0qvc = ( int8_T ) _rtB -> jv5ewvm1oz
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> nbff4tczhs = _rtP -> P_1490 ;
} _rtB -> o5znxbxtos = ( _rtB -> b1apgnyjax > _rtB -> nbff4tczhs ) ; _rtB ->
fmort3sizj = ( int8_T ) _rtB -> o5znxbxtos ; if ( ssIsSampleHit ( S , 1 , 0 )
) { ssCallAccelRunBlock ( S , 70 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cf0hfgnqjl = ( _rtB -> jsk3qk05te || _rtB -> dwi2v43fhf || _rtB -> lgr0wchjju
|| ( _rtB -> occ3y5rmbr != 0 ) ) ; if ( _rtB -> cf0hfgnqjl ) { _rtB ->
i0jjmz0ddo = _rtP -> P_1807 ; _rtB -> hwjnvq2h4q = _rtB -> i0jjmz0ddo ; }
else { _rtB -> g20122nmg2 = _rtP -> P_1806 ; _rtB -> hwjnvq2h4q = _rtB ->
g20122nmg2 ; } _rtB -> iec1vgejcf = _rtP -> P_1491 ; _rtB -> dhcuukgs11 =
_rtP -> P_1138 ; _rtB -> m21u10gy4h = ( real32_T ) _rtB -> dhcuukgs11 ; _rtB
-> fl32os0mgs = _rtB -> m21u10gy4h - _rtB -> dtsgkdxb50 ; _rtB -> ffva2mse0f
= _rtB -> fl32os0mgs / _rtB -> ck4b0pjrym ; if ( _rtB -> ffva2mse0f > _rtP ->
P_1493 ) { _rtB -> paei13hbsp = _rtP -> P_1493 ; } else if ( _rtB ->
ffva2mse0f < _rtP -> P_1494 ) { _rtB -> paei13hbsp = _rtP -> P_1494 ; } else
{ _rtB -> paei13hbsp = _rtB -> ffva2mse0f ; } _rtB -> orkip1a5ha = _rtP ->
P_1141 ; _rtB -> g2qrwhvcah = ( real32_T ) _rtB -> orkip1a5ha ; _rtB ->
olo5bjzdos = _rtB -> g2qrwhvcah - _rtB -> pfgty0dzhn ; _rtB -> nym51fszg2 =
_rtB -> olo5bjzdos / _rtB -> hq1zjwyxqs ; if ( _rtB -> nym51fszg2 > _rtP ->
P_1496 ) { _rtB -> lz3xsaefox = _rtP -> P_1496 ; } else if ( _rtB ->
nym51fszg2 < _rtP -> P_1497 ) { _rtB -> lz3xsaefox = _rtP -> P_1497 ; } else
{ _rtB -> lz3xsaefox = _rtB -> nym51fszg2 ; } _rtB -> gzhfjgzqow = _rtP ->
P_1144 ; _rtB -> cfgeww1yqj = ( real32_T ) _rtB -> gzhfjgzqow ; _rtB ->
n0wdt11ioi = _rtB -> cfgeww1yqj - _rtB -> aoagctkwip ; _rtB -> fkuugn3eyn =
_rtB -> n0wdt11ioi / _rtB -> bjt3xtuwd1 ; if ( _rtB -> fkuugn3eyn > _rtP ->
P_1499 ) { _rtB -> i2b5jwyuqe = _rtP -> P_1499 ; } else if ( _rtB ->
fkuugn3eyn < _rtP -> P_1500 ) { _rtB -> i2b5jwyuqe = _rtP -> P_1500 ; } else
{ _rtB -> i2b5jwyuqe = _rtB -> fkuugn3eyn ; } _rtB -> llt4bydmv1 = _rtP ->
P_1501 ; _rtB -> ccxogf2wlb = _rtP -> P_1502 ; _rtB -> dg5nlby2nd = _rtB ->
ccxogf2wlb - _rtB -> llt4bydmv1 ; } if ( _rtB -> b45rv03vtx > _rtP -> P_1870
) { _rtB -> b3afosm4iw [ 0 ] = _rtB -> iec1vgejcf ; _rtB -> b3afosm4iw [ 1 ]
= _rtB -> iec1vgejcf ; _rtB -> b3afosm4iw [ 2 ] = _rtB -> iec1vgejcf ; _rtB
-> b3afosm4iw [ 3 ] = _rtB -> iec1vgejcf ; } else { _rtB -> b3afosm4iw [ 0 ]
= _rtB -> paei13hbsp ; _rtB -> b3afosm4iw [ 1 ] = _rtB -> lz3xsaefox ; _rtB
-> b3afosm4iw [ 2 ] = _rtB -> i2b5jwyuqe ; if ( ssGetTaskTime ( S , 0 ) <
_rtP -> P_0 ) { tmp_i = _rtP -> P_1 ; } else { tmp_i = _rtP -> P_2 ; } u0 = (
( real32_T ) tmp_i - _rtB -> llt4bydmv1 ) / _rtB -> dg5nlby2nd ; if ( u0 >
_rtP -> P_1216 ) { _rtB -> b3afosm4iw [ 3 ] = _rtP -> P_1216 ; } else if ( u0
< _rtP -> P_1217 ) { _rtB -> b3afosm4iw [ 3 ] = _rtP -> P_1217 ; } else {
_rtB -> b3afosm4iw [ 3 ] = u0 ; } } _rtB -> kopib3mme4 = _rtP -> P_1503 *
_rtB -> b3afosm4iw [ 3 ] ; if ( _rtB -> kopib3mme4 > _rtP -> P_1504 ) { _rtB
-> hbz0fyvwkm = _rtP -> P_1504 ; } else if ( _rtB -> kopib3mme4 < _rtP ->
P_1505 ) { _rtB -> hbz0fyvwkm = _rtP -> P_1505 ; } else { _rtB -> hbz0fyvwkm
= _rtB -> kopib3mme4 ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
la1sie42l1 = _rtP -> P_1506 ; _rtB -> lb142nr4ga = _rtP -> P_1507 ; _rtB ->
nv3mukb1ux = _rtP -> P_1508 ; } ssCallAccelRunBlock ( S , 154 , 354 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gcx2iyqr1n = _rtP -> P_1509 * _rtB ->
f31wh1hvbz ; if ( _rtB -> gcx2iyqr1n > _rtP -> P_1510 ) { _rtB -> dklegaqrvr
= _rtP -> P_1510 ; } else if ( _rtB -> gcx2iyqr1n < _rtP -> P_1511 ) { _rtB
-> dklegaqrvr = _rtP -> P_1511 ; } else { _rtB -> dklegaqrvr = _rtB ->
gcx2iyqr1n ; } ssCallAccelRunBlock ( S , 154 , 357 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> medbpmg54i = _rtP -> P_1512 * _rtB -> man0rjdp2u ; if ( _rtB ->
medbpmg54i > _rtP -> P_1513 ) { _rtB -> nl0pgm3oyk = _rtP -> P_1513 ; } else
if ( _rtB -> medbpmg54i < _rtP -> P_1514 ) { _rtB -> nl0pgm3oyk = _rtP ->
P_1514 ; } else { _rtB -> nl0pgm3oyk = _rtB -> medbpmg54i ; } if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> h5so5yuumq = _rtP -> P_1515 ; _rtB ->
no5wn1yvnc = _rtP -> P_1516 ; } ssCallAccelRunBlock ( S , 154 , 362 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gyrdj2xq0q = _rtP -> P_1517 * _rtB ->
id44smfryn ; if ( _rtB -> gyrdj2xq0q > _rtP -> P_1518 ) { _rtB -> fgmcrfte34
= _rtP -> P_1518 ; } else if ( _rtB -> gyrdj2xq0q < _rtP -> P_1519 ) { _rtB
-> fgmcrfte34 = _rtP -> P_1519 ; } else { _rtB -> fgmcrfte34 = _rtB ->
gyrdj2xq0q ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> peqnqtyflm = _rtP
-> P_1520 ; _rtB -> hqimuqd3nh = _rtP -> P_1521 ; _rtB -> amyigamitt = _rtP
-> P_1522 ; _rtB -> oqk2nxyy5d = _rtP -> P_1523 ; _rtB -> d0hykkxtlb = _rtP
-> P_1524 ; _rtB -> doox0on4ui = _rtP -> P_1525 ; _rtB -> bf01xq4ypq = _rtP
-> P_1526 ; _rtB -> kc543na4re = _rtP -> P_1527 ; _rtB -> npfmdr1b14 = _rtP
-> P_1528 ; _rtB -> bl0gf5hm4j = _rtB -> holqoxikgx ; if ( _rtB -> cf0hfgnqjl
) { _rtB -> fiozotypxk = _rtP -> P_1805 ; _rtB -> ntpnwv0eai = _rtB ->
fiozotypxk ; } else { _rtB -> hoplbml3r0 = _rtP -> P_1804 ; _rtB ->
ntpnwv0eai = _rtB -> hoplbml3r0 ; } _rtB -> oljwnirlkw = _rtP -> P_1529 ;
_rtB -> pcyl5l1vdp = _rtP -> P_1530 ; _rtB -> ay1ginfbui = _rtP -> P_1531 ;
_rtB -> ejlqqgtf2x = _rtP -> P_1532 ; _rtB -> nhcimvcaxm = _rtP -> P_1533 ;
_rtB -> exihjt5ewd = _rtP -> P_1534 ; _rtB -> gy1qhskz3p = _rtP -> P_1871 ; }
_rtB -> joradlbnzx = _rtB -> lfy1l03fbx . decl_qgc ; _rtB -> itdeup1ypp =
_rtB -> lfy1l03fbx . dacl_qgc ; _rtB -> cwskwkp1ie = _rtB -> lfy1l03fbx .
drcl_qgc ; _rtB -> ev0obqedt2 = _rtB -> lfy1l03fbx . nwscl_qgc ; _rtB ->
lpnh1kz54q = _rtB -> lfy1l03fbx . sbcl_qgc ; _rtB -> khyrz5hnuy = ( (
frf5yblmjv * ) ssGetU ( S ) ) -> m3gbfkorzq ; _rtB -> lvwa3b23hh = _rtB ->
j02ajqhpz1 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> oiih20zp3g = _rtP
-> P_1872 ; _rtB -> n5pnwv2gyt = ( _rtB -> oiih20zp3g >= _rtB -> hcte4wigmp )
; _rtB -> ccbgipnd2i = ( int8_T ) _rtB -> n5pnwv2gyt ; ssCallAccelRunBlock (
S , 8 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> c4xsfy1x5z = _rtP -> P_1874 ;
_rtB -> mb11b5vuw5 = _rtP -> P_1875 ; _rtB -> lr33zhu01l = ( ( _rtB ->
c4xsfy1x5z != 0 ) && ( _rtB -> mb11b5vuw5 != 0 ) ) ; _rtB -> lb5yeevzub = !
_rtB -> lr33zhu01l ; _rtB -> mlfircpah5 = ( int8_T ) _rtB -> lb5yeevzub ;
_rtB -> jhn2yddasp = _rtP -> P_1876 ; _rtB -> jdegz4rywq = ( _rtB ->
joh40kiala == _rtB -> jhn2yddasp ) ; if ( _rtB -> jdegz4rywq ) { _rtB ->
p1txw3cewi = ( ( _rtB -> np4gdaano3 != 0 ) || ( _rtB -> mlfircpah5 != 0 ) ) ;
_rtB -> dzgrk4t4bh = ( int8_T ) _rtB -> p1txw3cewi ; _rtB -> edf14loyxx =
_rtB -> dzgrk4t4bh ; } else { _rtB -> d5ii53m3ow = _rtP -> P_1808 ; _rtB ->
edf14loyxx = _rtB -> d5ii53m3ow ; } _rtB -> nsassfuiar = _rtP -> P_1535 ;
_rtB -> gq10smbc5w = _rtP -> P_1536 ; _rtB -> hrvvzgmp4z = _rtP -> P_1537 ;
_rtB -> heh3krga5n = _rtP -> P_1538 ; _rtB -> fjhrnnijtj = _rtP -> P_1539 ;
_rtB -> ogqfooux2e = _rtP -> P_1877 ; _rtB -> jbhv5bm4bn = _rtP -> P_1878 ; }
_rtB -> huf1ioxto3 = _rtB -> l4jcezyo5f [ 3 ] ; _rtB -> ckldhu4zjy = _rtB ->
l4jcezyo5f [ 0 ] ; _rtB -> dgdpvmlgyc = _rtB -> l4jcezyo5f [ 4 ] ; _rtB ->
do2jyznip0 = _rtB -> l4jcezyo5f [ 1 ] ; _rtB -> oqbv5445v4 = ( _rtB ->
azarpgjmdw == _rtB -> jbhv5bm4bn ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> lki0djz1py = _rtP -> P_1879 ; _rtB -> pfqt5eqlg3 = ( _rtB ->
joh40kiala == _rtB -> lki0djz1py ) ; _rtB -> mndr5h51pf = _rtP -> P_1880 ;
_rtB -> jbnl0phzqh = ( _rtB -> mndr5h51pf >= _rtB -> ldgxk2v0et ) ; _rtB ->
doz2r3uelw = ( int8_T ) _rtB -> jbnl0phzqh ; ssCallAccelRunBlock ( S , 10 , 0
, SS_CALL_MDL_OUTPUTS ) ; _rtB -> kflidpj0zd = _rtP -> P_1882 ; _rtB ->
ldroiofwnn = ( _rtB -> aglchr0xwl == _rtB -> kflidpj0zd ) ; _rtB ->
jb12hrsruc = _rtP -> P_1883 ; } _rtB -> jchw3ep00q = ( _rtB -> oqbv5445v4 &&
_rtB -> pfqt5eqlg3 && _rtB -> ldroiofwnn ) ; if ( _rtB -> jchw3ep00q ) { _rtB
-> de54ka51ep = _rtB -> ogqfooux2e ; } else { _rtB -> de54ka51ep = _rtB ->
jb12hrsruc ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> gczkpccfsx = _rtP
-> P_1884 ; ssCallAccelRunBlock ( S , 7 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
otxk4zgwiu = _rtP -> P_1885 ; _rtB -> bd3u3rvl1c = ( _rtB -> joh40kiala ==
_rtB -> otxk4zgwiu ) ; _rtB -> eqi3ghkuhk = _rtP -> P_1886 ; _rtB ->
bkskm5mljo = ( _rtB -> joh40kiala == _rtB -> eqi3ghkuhk ) ; _rtB ->
h51c1d3d2n = ( _rtB -> bd3u3rvl1c || _rtB -> bkskm5mljo ) ; if ( _rtB ->
h51c1d3d2n ) { _rtB -> czyzblgx3e = _rtB -> lvqjyd1stm ; } else { _rtB ->
gokhpdos4x = _rtP -> P_1809 ; _rtB -> czyzblgx3e = _rtB -> gokhpdos4x ; } }
_rtB -> p1tt1h2a5m = _rtB -> lfy1l03fbx . guidance . altcmd ; if ( _rtB ->
p1tt1h2a5m > _rtP -> P_1540 ) { _rtB -> cawiax4a0f = _rtP -> P_1540 ; } else
if ( _rtB -> p1tt1h2a5m < _rtP -> P_1541 ) { _rtB -> cawiax4a0f = _rtP ->
P_1541 ; } else { _rtB -> cawiax4a0f = _rtB -> p1tt1h2a5m ; } _rtB ->
ngc4ljufo0 = _rtB -> lfy1l03fbx . guidance . ascmd ; ssCallAccelRunBlock ( S
, 47 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB -> lwnjvaaads > _rtP -> P_1542 )
{ _rtB -> nc3lnd0ybd = _rtP -> P_1542 ; } else if ( _rtB -> lwnjvaaads < _rtP
-> P_1543 ) { _rtB -> nc3lnd0ybd = _rtP -> P_1543 ; } else { _rtB ->
nc3lnd0ybd = _rtB -> lwnjvaaads ; } _rtB -> fscw52ajp0 = _rtB -> lfy1l03fbx .
guidance . targetpoint ; ssCallAccelRunBlock ( S , 48 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; rtPrevAction = _rtDW -> j5jlgd5vck ; rtAction = - 1 ;
if ( ssIsMajorTimeStep ( S ) ) { switch ( _rtB -> joh40kiala ) { case 0 :
rtAction = 0 ; break ; case 1 : rtAction = 1 ; break ; case 2 : rtAction = 2
; break ; case 3 : rtAction = 3 ; break ; case 4 : rtAction = 4 ; break ;
case 5 : rtAction = 5 ; break ; case 6 : rtAction = 6 ; break ; } _rtDW ->
j5jlgd5vck = rtAction ; } else { rtAction = _rtDW -> j5jlgd5vck ; } if (
rtPrevAction != rtAction ) { switch ( rtPrevAction ) { case 0 :
ssCallAccelRunBlock ( S , 49 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ; break ;
case 1 : ssCallAccelRunBlock ( S , 51 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ;
break ; case 2 : ssCallAccelRunBlock ( S , 53 , 0 ,
SS_CALL_RTW_GENERATED_DISABLE ) ; break ; case 3 : ssCallAccelRunBlock ( S ,
55 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ; break ; case 4 :
ssCallAccelRunBlock ( S , 57 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ; break ;
case 5 : ssCallAccelRunBlock ( S , 59 , 0 , SS_CALL_RTW_GENERATED_DISABLE ) ;
break ; case 6 : ssCallAccelRunBlock ( S , 61 , 0 ,
SS_CALL_RTW_GENERATED_DISABLE ) ; break ; } } switch ( rtAction ) { case 0 :
if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) != ssGetTStart
( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S , 49 , 0 ,
SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 49 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> a0jka1ejm2 ; _rtB -> hmgqxihgml = _rtB -> p1svbl4qgh ;
_rtB -> mlugvwqfjf = _rtB -> has3ixakfo ; _rtB -> ljqi4bmnhe = _rtB ->
k1r4mfrnn3 ; _rtB -> g3mwa1cel2 = _rtB -> ho4qeaplf5 ; _rtB -> at0odbf5nx =
_rtB -> nukxgweth0 ; _rtB -> oug4gaxwzn = _rtB -> c2j0pfkgsd ; _rtB ->
fmwca5uacb = _rtB -> eccuqdy5gz ; _rtB -> l2i5ftwcqq = _rtB -> g0i4az1de1 ;
_rtB -> fxy1ga2ryu = _rtB -> kfmvrdn1lz ; _rtB -> nntkxivcmj = _rtB ->
aciry1kaqx ; _rtB -> fqurfvkusw = _rtB -> jcqdwbv2gr ; _rtB -> aza4qmovfm =
_rtB -> fgezbteobs ; _rtB -> lsnspy42zf = _rtB -> js4xkppms1 ; _rtB ->
caf5uj1c42 = _rtB -> gbbwozbr2k ; _rtB -> me10oyjfnz = _rtB -> j4cekymtyl ;
_rtB -> in2east53k = _rtB -> ez5vmulqzz ; _rtB -> aexpvbgytv = _rtB ->
ilmvotolyf ; _rtB -> drwv015lkz = _rtB -> ak2ea3x2et ; _rtB -> daz5nmuzin =
_rtB -> kjpqzcxdrs ; _rtB -> cxdul42je5 = _rtB -> e0rmkjzayo ; _rtB ->
htegjfjklo = _rtB -> ag1mfcpq2m ; _rtB -> e3tqcoo3b5 = _rtB -> i2unnuztnu ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> bctl3ga1qi ) ; } break
; case 1 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 51 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 51 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> az4iqxgjca ; _rtB -> hmgqxihgml = _rtB -> mntqdj35qs ;
_rtB -> mlugvwqfjf = _rtB -> fo0faayeej ; _rtB -> ljqi4bmnhe = _rtB ->
boedfllnsa ; _rtB -> g3mwa1cel2 = _rtB -> bk1k21oonz ; _rtB -> at0odbf5nx =
_rtB -> aq10evkf5x ; _rtB -> oug4gaxwzn = _rtB -> pgeykxgwk0 ; _rtB ->
fmwca5uacb = _rtB -> caciq3hcob ; _rtB -> l2i5ftwcqq = _rtB -> bk3a1secet ;
_rtB -> fxy1ga2ryu = _rtB -> kmnjy5adrz ; _rtB -> nntkxivcmj = _rtB ->
mhukp5dhzg ; _rtB -> fqurfvkusw = _rtB -> ayt3fmdu5d ; _rtB -> aza4qmovfm =
_rtB -> cuxrvrvsqu ; _rtB -> lsnspy42zf = _rtB -> d3rl33vkqd ; _rtB ->
caf5uj1c42 = _rtB -> mjixjtrkff ; _rtB -> me10oyjfnz = _rtB -> inpmj1pwsy ;
_rtB -> in2east53k = _rtB -> fthkbaebnf ; _rtB -> aexpvbgytv = _rtB ->
cmruyqqgii ; _rtB -> drwv015lkz = _rtB -> bcnzbltqb5 ; _rtB -> daz5nmuzin =
_rtB -> cx1b2gsind ; _rtB -> cxdul42je5 = _rtB -> n5gb0gckdw ; _rtB ->
htegjfjklo = _rtB -> iocw1fcplx ; _rtB -> e3tqcoo3b5 = _rtB -> anflo1aotm ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> hpagqbihsf ) ; } break
; case 2 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 53 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 53 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> hyt1zpl3ln ; _rtB -> hmgqxihgml = _rtB -> hvh0hryqma ;
_rtB -> mlugvwqfjf = _rtB -> ex0dfr2jcr ; _rtB -> ljqi4bmnhe = _rtB ->
pxo14pob4x ; _rtB -> g3mwa1cel2 = _rtB -> gy31kozfys ; _rtB -> at0odbf5nx =
_rtB -> axttmizupp ; _rtB -> oug4gaxwzn = _rtB -> oy13sd1q4y ; _rtB ->
fmwca5uacb = _rtB -> ltjbexi5ni ; _rtB -> l2i5ftwcqq = _rtB -> hzpbp24e1d ;
_rtB -> fxy1ga2ryu = _rtB -> ecog5s53u5 ; _rtB -> nntkxivcmj = _rtB ->
kcr1ewwllg ; _rtB -> fqurfvkusw = _rtB -> jtfcbm5aau ; _rtB -> aza4qmovfm =
_rtB -> bnr3xyo3ns ; _rtB -> lsnspy42zf = _rtB -> igrbxmmrxo ; _rtB ->
caf5uj1c42 = _rtB -> mah3gqumf4 ; _rtB -> me10oyjfnz = _rtB -> cqzhj0wf24 ;
_rtB -> in2east53k = _rtB -> eeagr4hya2 ; _rtB -> aexpvbgytv = _rtB ->
jucqydvuor ; _rtB -> drwv015lkz = _rtB -> l3ymkbxzaj ; _rtB -> daz5nmuzin =
_rtB -> ljxy0wcryx ; _rtB -> cxdul42je5 = _rtB -> ocixvpqqpy ; _rtB ->
htegjfjklo = _rtB -> jmhn5sl0an ; _rtB -> e3tqcoo3b5 = _rtB -> k3hrwkbvxd ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> gfemb4hqrl ) ; } break
; case 3 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 55 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 55 , 0 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 56 , 1 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> njlwoqxpxe ; _rtB -> hmgqxihgml = _rtB -> hnrqnqecm4 ;
_rtB -> mlugvwqfjf = _rtB -> pdjooy0ga4 ; _rtB -> ljqi4bmnhe = _rtB ->
m2rwqlgkxp ; _rtB -> g3mwa1cel2 = _rtB -> lyneikmqki ; _rtB -> at0odbf5nx =
_rtB -> lnllak4sz1 ; _rtB -> oug4gaxwzn = _rtB -> bcslwtqzfv ; _rtB ->
fmwca5uacb = _rtB -> fqcaepwnhc ; _rtB -> l2i5ftwcqq = _rtB -> o4fi3qijvk ;
_rtB -> fxy1ga2ryu = _rtB -> l2w4tcnrup ; _rtB -> nntkxivcmj = _rtB ->
an3twnnair ; _rtB -> fqurfvkusw = _rtB -> chwz2v5bk4 ; _rtB -> aza4qmovfm =
_rtB -> eo1h0e5ya0 ; _rtB -> lsnspy42zf = _rtB -> gqhhipnnld ; _rtB ->
caf5uj1c42 = _rtB -> ll32adeytr ; _rtB -> me10oyjfnz = _rtB -> gzcs5vmkdo ;
_rtB -> in2east53k = _rtB -> psiibimld2 ; _rtB -> aexpvbgytv = _rtB ->
bocnuu0qjg ; _rtB -> drwv015lkz = _rtB -> pkrx4jhmxh ; _rtB -> daz5nmuzin =
_rtB -> mliyd4okkh ; _rtB -> cxdul42je5 = _rtB -> eky140w5kt ; _rtB ->
htegjfjklo = _rtB -> bz5ax2wuab ; _rtB -> e3tqcoo3b5 = _rtB -> e3twmcu4cf ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> ecfghe2lmm ) ; } break
; case 4 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 57 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { _rtB -> h3umjbmwd3 = _rtP -> P_1802 ; } _rtB -> fypbgc45wc = ( int8_T )
( _rtB -> mxcxqjg10g - _rtB -> h3umjbmwd3 ) ; if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 57 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> aql5sow2af ; _rtB -> hmgqxihgml = _rtB -> einoqjay1o ;
_rtB -> mlugvwqfjf = _rtB -> gifbewy3cp ; _rtB -> ljqi4bmnhe = _rtB ->
pc5n1c000f ; _rtB -> g3mwa1cel2 = _rtB -> jgu0ofebhn ; _rtB -> at0odbf5nx =
_rtB -> dr2xxh1hm5 ; _rtB -> oug4gaxwzn = _rtB -> p1tlyw1s5v ; _rtB ->
fmwca5uacb = _rtB -> pc1442ecqg ; _rtB -> l2i5ftwcqq = _rtB -> inazqcde5e ;
_rtB -> fxy1ga2ryu = _rtB -> bsun3zcppf ; _rtB -> nntkxivcmj = _rtB ->
elf2dtin0k ; _rtB -> fqurfvkusw = _rtB -> dtntmskue4 ; _rtB -> aza4qmovfm =
_rtB -> lgbauwwogw ; _rtB -> lsnspy42zf = _rtB -> k1x0mmnf2s ; _rtB ->
caf5uj1c42 = _rtB -> apf0y321gt ; _rtB -> me10oyjfnz = _rtB -> n3fc1xneu2 ;
_rtB -> in2east53k = _rtB -> dd3muex05h ; _rtB -> aexpvbgytv = _rtB ->
b0benyclgg ; _rtB -> drwv015lkz = _rtB -> an2tccmkyu ; _rtB -> daz5nmuzin =
_rtB -> eilwwnbhxy ; _rtB -> cxdul42je5 = _rtB -> nyivliahf1 ; _rtB ->
htegjfjklo = _rtB -> azrxkcsgft ; _rtB -> e3tqcoo3b5 = _rtB -> op2brfqeca ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> h3ulhfkflw ) ; } break
; case 5 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 59 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { _rtB -> enhmlqqia4 = _rtP -> P_1803 ; } _rtB -> hascsjbpjm = ( int8_T )
( _rtB -> mxcxqjg10g - _rtB -> enhmlqqia4 ) ; if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 59 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> k12i2fjwol ; _rtB -> hmgqxihgml = _rtB -> l5migkd22a ;
_rtB -> mlugvwqfjf = _rtB -> bl2qgmypml ; _rtB -> ljqi4bmnhe = _rtB ->
aaeh4xw14h ; _rtB -> g3mwa1cel2 = _rtB -> gohbvs000z ; _rtB -> at0odbf5nx =
_rtB -> hjgimgfepx ; _rtB -> oug4gaxwzn = _rtB -> deeuxe1o41 ; _rtB ->
fmwca5uacb = _rtB -> asdvcxupkl ; _rtB -> l2i5ftwcqq = _rtB -> krb15egqht ;
_rtB -> fxy1ga2ryu = _rtB -> c1xl1uf2jx ; _rtB -> nntkxivcmj = _rtB ->
aeadcetx45 ; _rtB -> fqurfvkusw = _rtB -> jtnvjzvsuz ; _rtB -> aza4qmovfm =
_rtB -> olc3czfkuc ; _rtB -> lsnspy42zf = _rtB -> dc50oda3h4 ; _rtB ->
caf5uj1c42 = _rtB -> jvpbjrvoav ; _rtB -> me10oyjfnz = _rtB -> byjdcp2gsp ;
_rtB -> in2east53k = _rtB -> fvdyfvmdn3 ; _rtB -> aexpvbgytv = _rtB ->
bqwkez0h0g ; _rtB -> drwv015lkz = _rtB -> iufrnlozkk ; _rtB -> daz5nmuzin =
_rtB -> naanpnvlmy ; _rtB -> cxdul42je5 = _rtB -> essr03dmkv ; _rtB ->
htegjfjklo = _rtB -> lz10gq0ryj ; _rtB -> e3tqcoo3b5 = _rtB -> hwby4aazbx ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> gfvksexaw2 ) ; } break
; case 6 : if ( rtAction != rtPrevAction ) { if ( ssGetTaskTime ( S , 0 ) !=
ssGetTStart ( S ) ) { ssSetSolverNeedsReset ( S ) ; } ssCallAccelRunBlock ( S
, 61 , 0 , SS_CALL_RTW_GENERATED_ENABLE ) ; } if ( ssIsSampleHit ( S , 1 , 0
) ) { ssCallAccelRunBlock ( S , 61 , 0 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
epkdwudome = _rtB -> fjd1vw3dyw ; _rtB -> hmgqxihgml = _rtB -> mew4udgqzd ;
_rtB -> mlugvwqfjf = _rtB -> nywp23q5v5 ; _rtB -> ljqi4bmnhe = _rtB ->
kpen13z2gz ; _rtB -> g3mwa1cel2 = _rtB -> ebuwphioga ; _rtB -> at0odbf5nx =
_rtB -> jkxfkoncdi ; _rtB -> oug4gaxwzn = _rtB -> isu4wuvxjt ; _rtB ->
fmwca5uacb = _rtB -> ki0hwimtfp ; _rtB -> l2i5ftwcqq = _rtB -> h1uxtglgln ;
_rtB -> fxy1ga2ryu = _rtB -> fsapoizv5r ; _rtB -> nntkxivcmj = _rtB ->
atoyphqwt2 ; _rtB -> fqurfvkusw = _rtB -> h0sfrwga0x ; _rtB -> aza4qmovfm =
_rtB -> auow2mzsdp ; _rtB -> lsnspy42zf = _rtB -> clj1t0zonb ; _rtB ->
caf5uj1c42 = _rtB -> ez5pjgide4 ; _rtB -> me10oyjfnz = _rtB -> gnlfdbfds0 ;
_rtB -> in2east53k = _rtB -> jbgjhfsx2b ; _rtB -> aexpvbgytv = _rtB ->
o4we1snaym ; _rtB -> drwv015lkz = _rtB -> k2kjgcc0pu ; _rtB -> daz5nmuzin =
_rtB -> klnxvh5sqw ; _rtB -> cxdul42je5 = _rtB -> ej5acsvkjk ; _rtB ->
htegjfjklo = _rtB -> cyqrqbxn42 ; _rtB -> e3tqcoo3b5 = _rtB -> ixlkkt1w53 ;
if ( ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> eicnyqaifw ) ; } break
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ndxg5ovism = _rtB ->
fl232yglvc ; _rtB -> npfd1fa2f3 [ 0 ] = _rtB -> peqnqtyflm ; _rtB ->
npfd1fa2f3 [ 1 ] = _rtB -> hqimuqd3nh ; _rtB -> npfd1fa2f3 [ 2 ] = _rtB ->
amyigamitt ; _rtB -> npfd1fa2f3 [ 3 ] = _rtB -> oqk2nxyy5d ; _rtB ->
npfd1fa2f3 [ 4 ] = _rtB -> d0hykkxtlb ; _rtB -> npfd1fa2f3 [ 5 ] = _rtB ->
doox0on4ui ; } _rtB -> btsusgvh4p [ 0 ] = _rtB -> joradlbnzx ; _rtB ->
btsusgvh4p [ 1 ] = _rtB -> itdeup1ypp ; _rtB -> btsusgvh4p [ 2 ] = _rtB ->
cwskwkp1ie ; _rtB -> btsusgvh4p [ 3 ] = _rtB -> ev0obqedt2 ; _rtB ->
btsusgvh4p [ 4 ] = _rtB -> lpnh1kz54q ; jtjpxjywrw ( S ) ;
ssCallAccelRunBlock ( S , 154 , 478 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 479 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
cns2d41pjo = _rtP -> P_1554 * _rtB -> inuazd3mp3 ; ssCallAccelRunBlock ( S ,
154 , 481 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 482 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 483 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 484 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 485 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 486 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 154 , 487 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 154 , 488 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 489 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 490 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 491 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 492 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 493 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 494 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 497 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 498 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 499 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 500 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 501 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 502 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 503 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 504 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 505 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 506 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 507 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 508 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 509 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 510 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 511 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 512 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 513 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 514 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 515 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 516 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 517 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> jo1erbmysk = _rtP -> P_1149 ; } if (
_rtB -> f0pk30mvyq ) { _rtB -> npfxzwwuwp = _rtB -> jo1erbmysk ; } else { if
( _rtB -> pgghzidifi > _rtP -> P_1455 ) { _rtB -> e0oednh3sr = _rtP -> P_1455
; } else if ( _rtB -> pgghzidifi < _rtP -> P_1456 ) { _rtB -> e0oednh3sr =
_rtP -> P_1456 ; } else { _rtB -> e0oednh3sr = _rtB -> pgghzidifi ; } _rtB ->
kfzwhp3chf = _rtB -> j2n514retq / _rtB -> e0oednh3sr ; if ( _rtB ->
kfzwhp3chf > 1.0F ) { u0 = 1.0F ; } else if ( _rtB -> kfzwhp3chf < - 1.0F ) {
u0 = - 1.0F ; } else { u0 = _rtB -> kfzwhp3chf ; } _rtB -> iksjjxevn5 =
muSingleScalarAsin ( u0 ) ; _rtB -> dgml2mhscx = _rtP -> P_1457 * _rtB ->
iksjjxevn5 ; _rtB -> npfxzwwuwp = _rtB -> dgml2mhscx ; } _rtB -> cuvserl0so =
( real32_T ) _rtB -> npfxzwwuwp ; ssCallAccelRunBlock ( S , 154 , 522 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 523 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 524 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 526 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 527 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 528 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 529 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 530 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 531 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 532 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 533 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 535 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 536 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 538 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 539 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 540 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 541 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 542 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 543 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 545 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 546 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 547 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 548 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 549 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 550 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 154 , 551 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 154 , 552 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 154 , 553 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 554 ,
SS_CALL_MDL_OUTPUTS ) ; } ssCallAccelRunBlock ( S , 154 , 555 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 154 , 556 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 154 , 557 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 558 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 559 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 560 , SS_CALL_MDL_OUTPUTS ) ; if ( _rtB ->
azarpgjmdw > _rtP -> P_1898 ) { _rtB -> a0221uon2j = _rtB -> jrotnppws0 ; }
else { _rtB -> a0221uon2j = _rtB -> pyn2voco5f ; } ssCallAccelRunBlock ( S ,
154 , 563 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 564 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 565 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 566 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 567 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 568 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 569 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
p44ze0vm1u = _rtP -> P_1724 ; _rtB -> j2jcaxtrbo = _rtP -> P_1725 ; _rtB ->
maae2qirye = _rtP -> P_1726 ; _rtB -> l4re3xnlir = _rtP -> P_1727 ; _rtB ->
hv3pvw05xp = _rtP -> P_1728 ; _rtB -> m2fyzpsopc = _rtP -> P_1729 ; _rtB ->
bep34dgzgg = _rtP -> P_1730 ; _rtB -> eu5sgfbgih = _rtP -> P_1731 ; _rtB ->
nj4gonhebv = _rtP -> P_1732 ; _rtB -> g5iu0uamo5 = _rtP -> P_1733 ; } if (
_rtB -> azarpgjmdw > _rtP -> P_1899 ) { _rtB -> j3sam0imkz [ 0 ] = _rtB ->
p44ze0vm1u ; _rtB -> j3sam0imkz [ 1 ] = _rtB -> j2jcaxtrbo ; _rtB ->
j3sam0imkz [ 2 ] = _rtB -> maae2qirye ; _rtB -> j3sam0imkz [ 3 ] = _rtB ->
l4re3xnlir ; _rtB -> j3sam0imkz [ 4 ] = _rtB -> hv3pvw05xp ; _rtB ->
j3sam0imkz [ 5 ] = _rtB -> m2fyzpsopc ; _rtB -> j3sam0imkz [ 6 ] = _rtB ->
bep34dgzgg ; _rtB -> j3sam0imkz [ 7 ] = _rtB -> eu5sgfbgih ; _rtB ->
j3sam0imkz [ 8 ] = _rtB -> nj4gonhebv ; _rtB -> j3sam0imkz [ 9 ] = _rtB ->
g5iu0uamo5 ; } else { _rtB -> j3sam0imkz [ 0 ] = _rtB -> bzgei0srbk [ 0 ] ;
_rtB -> j3sam0imkz [ 1 ] = _rtB -> bzgei0srbk [ 1 ] ; _rtB -> j3sam0imkz [ 2
] = _rtB -> bzgei0srbk [ 2 ] ; _rtB -> j3sam0imkz [ 3 ] = _rtB -> bzgei0srbk
[ 3 ] ; _rtB -> j3sam0imkz [ 4 ] = _rtB -> bzgei0srbk [ 4 ] ; _rtB ->
j3sam0imkz [ 5 ] = _rtB -> bzgei0srbk [ 5 ] ; _rtB -> j3sam0imkz [ 6 ] = _rtB
-> bzgei0srbk [ 6 ] ; _rtB -> j3sam0imkz [ 7 ] = _rtB -> bzgei0srbk [ 7 ] ;
_rtB -> j3sam0imkz [ 8 ] = _rtB -> bzgei0srbk [ 8 ] ; _rtB -> j3sam0imkz [ 9
] = _rtB -> bzgei0srbk [ 9 ] ; } ssCallAccelRunBlock ( S , 154 , 581 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 582 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 583 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 584 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 585 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 586 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 587 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 154 , 588 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 589 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 590 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 591 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 592 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 593 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 594 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 595 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 596 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 597 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 598 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 599 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 600 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 601 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 602 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 603 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 604 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 605 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 606 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 607 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 608 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 609 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 610 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 611 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 612 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 613 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 614 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 615 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 616 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 617 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 618 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 619 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 620 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 621 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 622 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 623 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 624 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 625 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 626 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 627 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 628 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 629 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 630 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 631 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 632 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 633 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 634 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 635 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 636 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 637 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 638 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 639 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 640 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 641 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 642 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 643 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 644 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 645 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 646 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 647 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 648 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 649 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 650 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 651 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 652 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 653 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 654 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 655 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 656 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 657 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 658 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 659 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 660 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 661 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 662 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 663 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 664 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 665 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 666 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 667 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 668 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 669 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 670 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 671 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 672 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 673 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 674 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 675 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 676 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 677 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 678 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 679 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 680 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 4 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 9 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 41 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> akpt2xxopu = ( _rtB -> joh40kiala >= _rtB ->
niu11cubac ) ; _rtB -> cgwsxr4e5x = _rtDW -> ow1wrqv3g4 ; _rtB -> bc1gg4rxr5
= _rtB -> akpt2xxopu ^ _rtB -> cgwsxr4e5x ; _rtB -> g0tyaovqd0 = _rtDW ->
ntglwj5pkh ; ssCallAccelRunBlock ( S , 45 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB
-> i1tzqlrzw0 = _rtDW -> f0e22lzj55 ; _rtB -> l5v54b1lrs = ( _rtB ->
i1tzqlrzw0 != _rtB -> iksrh4iqw2 ) ; _rtB -> ipvemgkdri = ( int8_T ) _rtB ->
l5v54b1lrs ; ssCallAccelRunBlock ( S , 154 , 703 , SS_CALL_MDL_OUTPUTS ) ; }
_rtB -> m12r4ay3mi = _rtP -> P_1152 * _rtB -> gjlpvgfd3k ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 154 , 706 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 154 , 707 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 708 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 709 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 154 , 710 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
i04n2dtkvy = _rtP -> P_1153 * _rtB -> l5an2hno0l [ 1 ] ; _rtB -> in5wyniodi =
_rtP -> P_1154 * _rtB -> l5an2hno0l [ 0 ] ; _rtB -> fwqrkyxaig = _rtB ->
in5wyniodi + _rtB -> db0xe1untb ; _rtB -> ijsiv3nhbw = _rtP -> P_1156 * _rtB
-> fwqrkyxaig ; } _rtB -> pnjyriah10 [ 0 ] = _rtB -> i04n2dtkvy ; _rtB ->
pnjyriah10 [ 1 ] = _rtB -> ijsiv3nhbw ; _rtB -> pnjyriah10 [ 2 ] = _rtB ->
d0umcptuv2 ; muDoubleScalarSinCos ( _rtB -> pnjyriah10 [ 0 ] , & _rtB ->
pnjyriah10 [ 0 ] , & _rtB -> gzg232rcfq [ 0 ] ) ; muDoubleScalarSinCos ( _rtB
-> pnjyriah10 [ 1 ] , & _rtB -> pnjyriah10 [ 1 ] , & _rtB -> gzg232rcfq [ 1 ]
) ; muDoubleScalarSinCos ( _rtB -> pnjyriah10 [ 2 ] , & _rtB -> pnjyriah10 [
2 ] , & _rtB -> gzg232rcfq [ 2 ] ) ; _rtB -> kfud5yrqx3 [ 0 ] = _rtB ->
gzg232rcfq [ 1 ] * _rtB -> gzg232rcfq [ 0 ] ; _rtB -> kfud5yrqx3 [ 1 ] = _rtB
-> pnjyriah10 [ 2 ] * _rtB -> pnjyriah10 [ 1 ] * _rtB -> gzg232rcfq [ 0 ] -
_rtB -> gzg232rcfq [ 2 ] * _rtB -> pnjyriah10 [ 0 ] ; _rtB -> kfud5yrqx3 [ 2
] = _rtB -> gzg232rcfq [ 2 ] * _rtB -> pnjyriah10 [ 1 ] * _rtB -> gzg232rcfq
[ 0 ] + _rtB -> pnjyriah10 [ 2 ] * _rtB -> pnjyriah10 [ 0 ] ; _rtB ->
kfud5yrqx3 [ 3 ] = _rtB -> gzg232rcfq [ 1 ] * _rtB -> pnjyriah10 [ 0 ] ; _rtB
-> kfud5yrqx3 [ 4 ] = _rtB -> pnjyriah10 [ 2 ] * _rtB -> pnjyriah10 [ 1 ] *
_rtB -> pnjyriah10 [ 0 ] + _rtB -> gzg232rcfq [ 2 ] * _rtB -> gzg232rcfq [ 0
] ; _rtB -> kfud5yrqx3 [ 5 ] = _rtB -> gzg232rcfq [ 2 ] * _rtB -> pnjyriah10
[ 1 ] * _rtB -> pnjyriah10 [ 0 ] - _rtB -> pnjyriah10 [ 2 ] * _rtB ->
gzg232rcfq [ 0 ] ; _rtB -> kfud5yrqx3 [ 6 ] = - _rtB -> pnjyriah10 [ 1 ] ;
_rtB -> kfud5yrqx3 [ 7 ] = _rtB -> pnjyriah10 [ 2 ] * _rtB -> gzg232rcfq [ 1
] ; _rtB -> kfud5yrqx3 [ 8 ] = _rtB -> gzg232rcfq [ 2 ] * _rtB -> gzg232rcfq
[ 1 ] ; _rtB -> npflnoy3uq = muDoubleScalarAbs ( _rtB -> e14bksapzg ) ; _rtB
-> hi4jeha42q = ( _rtB -> npflnoy3uq > _rtB -> hedld4sq1s ) ; if ( _rtB ->
hi4jeha42q ) { _rtB -> hotdh02bt0 = _rtB -> e14bksapzg + _rtP -> P_17 ; _rtB
-> edswvdl0jc = muDoubleScalarMod ( _rtB -> hotdh02bt0 , _rtB -> ktocsnkmqn )
; _rtB -> hsx1rgxlyc = _rtB -> edswvdl0jc + _rtP -> P_18 ; _rtB -> lr5imeubxa
= _rtB -> hsx1rgxlyc ; } else { _rtB -> lr5imeubxa = _rtB -> e14bksapzg ; }
_rtB -> eu3xplotne = muDoubleScalarAbs ( _rtB -> lr5imeubxa ) ; _rtB ->
l51yg0z0h1 = ( _rtB -> eu3xplotne > _rtB -> b5bwo4xsl5 ) ; if ( _rtB ->
l51yg0z0h1 ) { _rtB -> mmy5cyf3gr = _rtB -> eu3xplotne + _rtP -> P_14 ; _rtB
-> klpdmyxuom = _rtP -> P_15 * _rtB -> mmy5cyf3gr ; _rtB -> lkjfbttms4 = _rtB
-> klpdmyxuom + _rtP -> P_16 ; _rtB -> gswsb10a5i = muDoubleScalarSign ( _rtB
-> lr5imeubxa ) ; _rtB -> nzuj5fpuea = _rtB -> gswsb10a5i * _rtB ->
lkjfbttms4 ; _rtB -> ga0ob42ces = _rtB -> nzuj5fpuea ; } else { _rtB ->
ga0ob42ces = _rtB -> lr5imeubxa ; } _rtB -> n5kz1j12eo = _rtP -> P_1162 *
_rtB -> ga0ob42ces ; muDoubleScalarSinCos ( _rtB -> n5kz1j12eo , & _rtB ->
eqihkbr2kr , & _rtB -> jndyzfcey1 ) ; _rtB -> d0550lkjrp [ 0 ] = _rtB ->
lgyahwt5az * _rtB -> eqihkbr2kr ; _rtB -> d0550lkjrp [ 1 ] = _rtB ->
lgyahwt5az * _rtB -> jndyzfcey1 ; _rtB -> gdwdfij4qx = muDoubleScalarTan (
_rtB -> n5kz1j12eo ) ; _rtB -> fyxumx0p3u = _rtB -> gdwdfij4qx * _rtB ->
hd0n1hoq5s * _rtB -> hd0n1hoq5s ; _rtB -> k1a3j1o4j4 = muDoubleScalarAtan2 (
_rtB -> fyxumx0p3u , _rtB -> d0vl2rppec ) ; _rtB -> ayr2xw3m5i = _rtP ->
P_1167 * _rtB -> k1a3j1o4j4 ; _rtB -> jc14xrib3q = _rtP -> P_1168 * _rtB ->
ayr2xw3m5i ; _rtB -> lroskxczup = muDoubleScalarSin ( _rtB -> jc14xrib3q ) ;
_rtB -> dhtao1znft = _rtB -> lroskxczup * _rtB -> lroskxczup * _rtB ->
dhi3sqv521 ; _rtB -> n4wjoacu2q = _rtB -> mkvlmyql3w + _rtB -> dhtao1znft ;
_rtB -> hnicepk1c5 = _rtB -> ddvgudknjj * _rtB -> ddvgudknjj / _rtB ->
n4wjoacu2q ; _rtB -> fnvnwzu3jk = muDoubleScalarSqrt ( _rtB -> hnicepk1c5 ) ;
muDoubleScalarSinCos ( _rtB -> k1a3j1o4j4 , & _rtB -> axfikjsuh4 , & _rtB ->
lu5ueplcmw ) ; _rtB -> lnwmqanst5 [ 0 ] = _rtB -> fnvnwzu3jk * _rtB ->
axfikjsuh4 ; _rtB -> lnwmqanst5 [ 1 ] = _rtB -> fnvnwzu3jk * _rtB ->
lu5ueplcmw ; _rtB -> p1cwoz1ing [ 0 ] = _rtB -> d0550lkjrp [ 0 ] + _rtB ->
lnwmqanst5 [ 0 ] ; _rtB -> p1cwoz1ing [ 1 ] = _rtB -> d0550lkjrp [ 1 ] + _rtB
-> lnwmqanst5 [ 1 ] ; _rtB -> fmyw0osk4y = muDoubleScalarAtan2 ( _rtB ->
p1cwoz1ing [ 0 ] , _rtB -> p1cwoz1ing [ 1 ] ) ; _rtB -> cwo2irdvzh = _rtP ->
P_1170 * _rtB -> fmyw0osk4y ; if ( _rtB -> l51yg0z0h1 ) { _rtB -> f4oyjnmlgq
= _rtB -> jeko3oryhk ; } else { _rtB -> f4oyjnmlgq = _rtB -> icyi2fy0un ; }
_rtB -> funldh4gb3 = _rtB -> f4oyjnmlgq + _rtB -> c2xzpu5xzk ; _rtB ->
gx2cfjaqko = muDoubleScalarAbs ( _rtB -> funldh4gb3 ) ; _rtB -> i2fku4amwo =
( _rtB -> gx2cfjaqko > _rtB -> avm1d5ejfb ) ; if ( _rtB -> i2fku4amwo ) {
_rtB -> dfbvlua0k1 = _rtB -> funldh4gb3 + _rtP -> P_19 ; _rtB -> m3z1a3ynh2 =
muDoubleScalarMod ( _rtB -> dfbvlua0k1 , _rtB -> mwcyki0vp1 ) ; _rtB ->
lgqwosj3u3 = _rtB -> m3z1a3ynh2 + _rtP -> P_20 ; _rtB -> l0xl1h2w2h = _rtB ->
lgqwosj3u3 ; } else { _rtB -> l0xl1h2w2h = _rtB -> funldh4gb3 ; } _rtB ->
d3s2cfxxts [ 0 ] = _rtP -> P_1175 * _rtB -> cwo2irdvzh ; _rtB -> d3s2cfxxts [
1 ] = _rtP -> P_1175 * _rtB -> l0xl1h2w2h ; muDoubleScalarSinCos ( _rtB ->
d3s2cfxxts [ 0 ] , & _rtB -> kyldaobqon [ 0 ] , & _rtB -> aiv3lavg1q [ 0 ] )
; muDoubleScalarSinCos ( _rtB -> d3s2cfxxts [ 1 ] , & _rtB -> kyldaobqon [ 1
] , & _rtB -> aiv3lavg1q [ 1 ] ) ; _rtB -> akalxwkr5r = _rtB -> kyldaobqon [
0 ] * _rtB -> aiv3lavg1q [ 1 ] ; _rtB -> endhozkqat [ 0 ] = - _rtB ->
akalxwkr5r ; _rtB -> endhozkqat [ 1 ] = - _rtB -> kyldaobqon [ 1 ] ; _rtB ->
frgj3fvd0c = _rtB -> aiv3lavg1q [ 0 ] * _rtB -> aiv3lavg1q [ 1 ] ; _rtB ->
endhozkqat [ 2 ] = - _rtB -> frgj3fvd0c ; _rtB -> m1oyzwlqds = _rtB ->
kyldaobqon [ 0 ] * _rtB -> kyldaobqon [ 1 ] ; _rtB -> endhozkqat [ 3 ] = -
_rtB -> m1oyzwlqds ; _rtB -> endhozkqat [ 4 ] = _rtB -> aiv3lavg1q [ 1 ] ;
_rtB -> olmmi4idmt = _rtB -> kyldaobqon [ 1 ] * _rtB -> aiv3lavg1q [ 0 ] ;
_rtB -> endhozkqat [ 5 ] = - _rtB -> olmmi4idmt ; _rtB -> endhozkqat [ 6 ] =
_rtB -> aiv3lavg1q [ 0 ] ; _rtB -> endhozkqat [ 7 ] = _rtB -> mvg0q0n5eb ;
_rtB -> endhozkqat [ 8 ] = - _rtB -> kyldaobqon [ 0 ] ; for ( i = 0 ; i < 3 ;
i ++ ) { _rtB -> kb5uqzu12d [ 3 * i ] = _rtB -> endhozkqat [ i ] ; _rtB ->
kb5uqzu12d [ 1 + 3 * i ] = _rtB -> endhozkqat [ i + 3 ] ; _rtB -> kb5uqzu12d
[ 2 + 3 * i ] = _rtB -> endhozkqat [ i + 6 ] ; } _rtB -> mnv35t2lpr = _rtP ->
P_1180 * _rtB -> cwo2irdvzh ; _rtB -> k4fekavzv3 = muDoubleScalarSin ( _rtB
-> mnv35t2lpr ) ; _rtB -> fejffia1rf = _rtB -> k4fekavzv3 * _rtB ->
k4fekavzv3 * _rtB -> jrqmc5rg24 ; _rtB -> n3mn51rqig = _rtB -> ajwaigw2uc +
_rtB -> fejffia1rf ; _rtB -> p4cj0gjzxb = _rtB -> fktwpod13x * _rtB ->
fktwpod13x / _rtB -> n3mn51rqig ; _rtB -> k3xtansgpr = muDoubleScalarSqrt (
_rtB -> p4cj0gjzxb ) ; _rtB -> jo01vavk0e = - _rtB -> k3xtansgpr ; _rtB ->
gzg232rcfq [ 0 ] = _rtB -> mrmlhrmijp ; _rtB -> gzg232rcfq [ 1 ] = _rtB ->
mrmlhrmijp ; _rtB -> gzg232rcfq [ 2 ] = _rtB -> jo01vavk0e ; for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> pnjyriah10 [ i ] = 0.0 ; _rtB -> pnjyriah10 [ i ] +=
_rtB -> kb5uqzu12d [ i ] * _rtB -> gzg232rcfq [ 0 ] ; _rtB -> pnjyriah10 [ i
] += _rtB -> kb5uqzu12d [ i + 3 ] * _rtB -> gzg232rcfq [ 1 ] ; _rtB ->
pnjyriah10 [ i ] += _rtB -> kb5uqzu12d [ i + 6 ] * _rtB -> gzg232rcfq [ 2 ] ;
} _rtB -> emfsxc4et1 [ 0 ] = _rtP -> P_1182 * _rtB -> ga0ob42ces ; _rtB ->
emfsxc4et1 [ 1 ] = _rtP -> P_1182 * _rtB -> l0xl1h2w2h ; muDoubleScalarSinCos
( _rtB -> emfsxc4et1 [ 0 ] , & _rtB -> ivdghfoesg [ 0 ] , & _rtB ->
jkeee2hqds [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> emfsxc4et1 [ 1 ] , & _rtB
-> ivdghfoesg [ 1 ] , & _rtB -> jkeee2hqds [ 1 ] ) ; _rtB -> las12j4fri =
_rtB -> ivdghfoesg [ 0 ] * _rtB -> jkeee2hqds [ 1 ] ; _rtB -> luojlt0bd4 [ 0
] = - _rtB -> las12j4fri ; _rtB -> luojlt0bd4 [ 1 ] = - _rtB -> ivdghfoesg [
1 ] ; _rtB -> m0fi4mhvfc = _rtB -> jkeee2hqds [ 0 ] * _rtB -> jkeee2hqds [ 1
] ; _rtB -> luojlt0bd4 [ 2 ] = - _rtB -> m0fi4mhvfc ; _rtB -> alsm3vjhwv =
_rtB -> ivdghfoesg [ 0 ] * _rtB -> ivdghfoesg [ 1 ] ; _rtB -> luojlt0bd4 [ 3
] = - _rtB -> alsm3vjhwv ; _rtB -> luojlt0bd4 [ 4 ] = _rtB -> jkeee2hqds [ 1
] ; _rtB -> m15lp4f1ep = _rtB -> ivdghfoesg [ 1 ] * _rtB -> jkeee2hqds [ 0 ]
; _rtB -> luojlt0bd4 [ 5 ] = - _rtB -> m15lp4f1ep ; _rtB -> luojlt0bd4 [ 6 ]
= _rtB -> jkeee2hqds [ 0 ] ; _rtB -> luojlt0bd4 [ 7 ] = _rtB -> gtihpno34h ;
_rtB -> luojlt0bd4 [ 8 ] = - _rtB -> ivdghfoesg [ 0 ] ; for ( i = 0 ; i < 3 ;
i ++ ) { _rtB -> kb5uqzu12d [ 3 * i ] = _rtB -> luojlt0bd4 [ i ] ; _rtB ->
kb5uqzu12d [ 1 + 3 * i ] = _rtB -> luojlt0bd4 [ i + 3 ] ; _rtB -> kb5uqzu12d
[ 2 + 3 * i ] = _rtB -> luojlt0bd4 [ i + 6 ] ; } _rtB -> nlap0nqwie = - _rtB
-> mygo3tfeep ; _rtB -> gzg232rcfq [ 0 ] = _rtB -> duc345ncoo ; _rtB ->
gzg232rcfq [ 1 ] = _rtB -> duc345ncoo ; _rtB -> gzg232rcfq [ 2 ] = _rtB ->
nlap0nqwie ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> a53as04cdt [ i ] = 0.0 ;
_rtB -> a53as04cdt [ i ] += _rtB -> kb5uqzu12d [ i ] * _rtB -> gzg232rcfq [ 0
] ; _rtB -> a53as04cdt [ i ] += _rtB -> kb5uqzu12d [ i + 3 ] * _rtB ->
gzg232rcfq [ 1 ] ; _rtB -> a53as04cdt [ i ] += _rtB -> kb5uqzu12d [ i + 6 ] *
_rtB -> gzg232rcfq [ 2 ] ; _rtB -> pnjyriah10 [ i ] += _rtB -> a53as04cdt [ i
] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> owlyasesqc =
muDoubleScalarAbs ( _rtB -> l5an2hno0l [ 0 ] ) ; _rtB -> llrbkdlipd = ( _rtB
-> owlyasesqc > _rtB -> m0gymoot1b ) ; if ( _rtB -> llrbkdlipd ) { _rtB ->
eccn0ze5pd = _rtB -> l5an2hno0l [ 0 ] + _rtP -> P_10 ; _rtB -> fxjcdquec5 =
muDoubleScalarMod ( _rtB -> eccn0ze5pd , _rtB -> e3rukdvq23 ) ; _rtB ->
m4tg3yk5ee = _rtB -> fxjcdquec5 + _rtP -> P_11 ; _rtB -> ecexrnii23 = _rtB ->
m4tg3yk5ee ; } else { _rtB -> ecexrnii23 = _rtB -> l5an2hno0l [ 0 ] ; } _rtB
-> nft3vbu2we = muDoubleScalarAbs ( _rtB -> ecexrnii23 ) ; _rtB -> pq5ayguoj0
= ( _rtB -> nft3vbu2we > _rtB -> civrcr2kdw ) ; if ( _rtB -> pq5ayguoj0 ) {
_rtB -> b0dyjuxc5d = _rtB -> nft3vbu2we + _rtP -> P_7 ; _rtB -> hpde3yynnk =
_rtP -> P_8 * _rtB -> b0dyjuxc5d ; _rtB -> bvgfbjpy2i = _rtB -> hpde3yynnk +
_rtP -> P_9 ; _rtB -> c44y0nhn11 = muDoubleScalarSign ( _rtB -> ecexrnii23 )
; _rtB -> n35yl14ue1 = _rtB -> c44y0nhn11 * _rtB -> bvgfbjpy2i ; _rtB ->
hmae0lpmnc = _rtB -> n35yl14ue1 ; } else { _rtB -> hmae0lpmnc = _rtB ->
ecexrnii23 ; } } _rtB -> l3xddnqz3s = _rtP -> P_1189 * _rtB -> hmae0lpmnc ;
muDoubleScalarSinCos ( _rtB -> l3xddnqz3s , & _rtB -> arfztb0jkc , & _rtB ->
gbaqyl0nwb ) ; _rtB -> j21zzy1ol1 [ 0 ] = _rtB -> gtiun4r12s * _rtB ->
arfztb0jkc ; _rtB -> j21zzy1ol1 [ 1 ] = _rtB -> gtiun4r12s * _rtB ->
gbaqyl0nwb ; _rtB -> emdrnndkxo = muDoubleScalarTan ( _rtB -> l3xddnqz3s ) ;
_rtB -> b1f2ggdgwo = _rtB -> emdrnndkxo * _rtB -> m4hueopc3x * _rtB ->
m4hueopc3x ; _rtB -> ko2arnht3g = muDoubleScalarAtan2 ( _rtB -> b1f2ggdgwo ,
_rtB -> kjj2ddbcta ) ; _rtB -> cohycbddio = _rtP -> P_1194 * _rtB ->
ko2arnht3g ; _rtB -> hhncxwagc2 = _rtP -> P_1195 * _rtB -> cohycbddio ; _rtB
-> juabqhgpdz = muDoubleScalarSin ( _rtB -> hhncxwagc2 ) ; _rtB -> gedussdtda
= _rtB -> juabqhgpdz * _rtB -> juabqhgpdz * _rtB -> h55krfswe5 ; _rtB ->
p3z30vx01k = _rtB -> fwd5fpzz2i + _rtB -> gedussdtda ; _rtB -> cgye2tsq5a =
_rtB -> ojyf1hwri0 * _rtB -> ojyf1hwri0 / _rtB -> p3z30vx01k ; _rtB ->
drah5pdvkn = muDoubleScalarSqrt ( _rtB -> cgye2tsq5a ) ; muDoubleScalarSinCos
( _rtB -> ko2arnht3g , & _rtB -> aill5hdsp2 , & _rtB -> c0kaherj24 ) ; _rtB
-> jnp3xqc2ke [ 0 ] = _rtB -> drah5pdvkn * _rtB -> aill5hdsp2 ; _rtB ->
jnp3xqc2ke [ 1 ] = _rtB -> drah5pdvkn * _rtB -> c0kaherj24 ; _rtB ->
ddgn5gpgbo [ 0 ] = _rtB -> j21zzy1ol1 [ 0 ] + _rtB -> jnp3xqc2ke [ 0 ] ; _rtB
-> ddgn5gpgbo [ 1 ] = _rtB -> j21zzy1ol1 [ 1 ] + _rtB -> jnp3xqc2ke [ 1 ] ;
_rtB -> l5bolyzta3 = muDoubleScalarAtan2 ( _rtB -> ddgn5gpgbo [ 0 ] , _rtB ->
ddgn5gpgbo [ 1 ] ) ; _rtB -> b2grgruprx = _rtP -> P_1197 * _rtB -> l5bolyzta3
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if ( _rtB -> pq5ayguoj0 ) { _rtB ->
ibpgbdyw4k = _rtB -> e0x52cru2p ; } else { _rtB -> ibpgbdyw4k = _rtB ->
c2okuvnfpu ; } _rtB -> kz2drocscv = _rtB -> ibpgbdyw4k + _rtB -> l5an2hno0l [
1 ] ; _rtB -> prlnkppyca = muDoubleScalarAbs ( _rtB -> kz2drocscv ) ; _rtB ->
aiv5zu0wic = ( _rtB -> prlnkppyca > _rtB -> pq21nocpry ) ; if ( _rtB ->
aiv5zu0wic ) { _rtB -> di3syl15pb = _rtB -> kz2drocscv + _rtP -> P_12 ; _rtB
-> i2lzfqkl5c = muDoubleScalarMod ( _rtB -> di3syl15pb , _rtB -> fg5ikfqx5v )
; _rtB -> ppjdncrfl3 = _rtB -> i2lzfqkl5c + _rtP -> P_13 ; _rtB -> l1inspeofr
= _rtB -> ppjdncrfl3 ; } else { _rtB -> l1inspeofr = _rtB -> kz2drocscv ; } }
_rtB -> onxc1vbwre [ 0 ] = _rtP -> P_1202 * _rtB -> b2grgruprx ; _rtB ->
onxc1vbwre [ 1 ] = _rtP -> P_1202 * _rtB -> l1inspeofr ; muDoubleScalarSinCos
( _rtB -> onxc1vbwre [ 0 ] , & _rtB -> d2h02pzzsa [ 0 ] , & _rtB ->
kf1bsdzmxv [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> onxc1vbwre [ 1 ] , & _rtB
-> d2h02pzzsa [ 1 ] , & _rtB -> kf1bsdzmxv [ 1 ] ) ; _rtB -> au0ogiyirr =
_rtB -> d2h02pzzsa [ 0 ] * _rtB -> kf1bsdzmxv [ 1 ] ; _rtB -> ffvzoc2pje [ 0
] = - _rtB -> au0ogiyirr ; _rtB -> ffvzoc2pje [ 1 ] = - _rtB -> d2h02pzzsa [
1 ] ; _rtB -> d1wmzwukyl = _rtB -> kf1bsdzmxv [ 0 ] * _rtB -> kf1bsdzmxv [ 1
] ; _rtB -> ffvzoc2pje [ 2 ] = - _rtB -> d1wmzwukyl ; _rtB -> pkumo5vwja =
_rtB -> d2h02pzzsa [ 0 ] * _rtB -> d2h02pzzsa [ 1 ] ; _rtB -> ffvzoc2pje [ 3
] = - _rtB -> pkumo5vwja ; _rtB -> ffvzoc2pje [ 4 ] = _rtB -> kf1bsdzmxv [ 1
] ; _rtB -> nlonx4h44q = _rtB -> d2h02pzzsa [ 1 ] * _rtB -> kf1bsdzmxv [ 0 ]
; _rtB -> ffvzoc2pje [ 5 ] = - _rtB -> nlonx4h44q ; _rtB -> ffvzoc2pje [ 6 ]
= _rtB -> kf1bsdzmxv [ 0 ] ; _rtB -> ffvzoc2pje [ 7 ] = _rtB -> oqd5hhfrjr ;
_rtB -> ffvzoc2pje [ 8 ] = - _rtB -> d2h02pzzsa [ 0 ] ; for ( i = 0 ; i < 3 ;
i ++ ) { _rtB -> kb5uqzu12d [ 3 * i ] = _rtB -> ffvzoc2pje [ i ] ; _rtB ->
kb5uqzu12d [ 1 + 3 * i ] = _rtB -> ffvzoc2pje [ i + 3 ] ; _rtB -> kb5uqzu12d
[ 2 + 3 * i ] = _rtB -> ffvzoc2pje [ i + 6 ] ; } _rtB -> mrz4zxlfhx = _rtP ->
P_1207 * _rtB -> b2grgruprx ; _rtB -> iuglhuv1xg = muDoubleScalarSin ( _rtB
-> mrz4zxlfhx ) ; _rtB -> ivnwnu02wv = _rtB -> iuglhuv1xg * _rtB ->
iuglhuv1xg * _rtB -> g1miatmxni ; _rtB -> huyb5xqtqv = _rtB -> goqjupftg0 +
_rtB -> ivnwnu02wv ; _rtB -> c3vik1b0vr = _rtB -> kky1e5qkac * _rtB ->
kky1e5qkac / _rtB -> huyb5xqtqv ; _rtB -> dnxrhmrbim = muDoubleScalarSqrt (
_rtB -> c3vik1b0vr ) ; _rtB -> cx2tgii1fd = - _rtB -> dnxrhmrbim ; _rtB ->
a53as04cdt [ 0 ] = _rtB -> ph5vjctp4q ; _rtB -> a53as04cdt [ 1 ] = _rtB ->
ph5vjctp4q ; _rtB -> a53as04cdt [ 2 ] = _rtB -> cx2tgii1fd ; for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> gzg232rcfq [ i ] = 0.0 ; _rtB -> gzg232rcfq [ i ] +=
_rtB -> kb5uqzu12d [ i ] * _rtB -> a53as04cdt [ 0 ] ; _rtB -> gzg232rcfq [ i
] += _rtB -> kb5uqzu12d [ i + 3 ] * _rtB -> a53as04cdt [ 1 ] ; _rtB ->
gzg232rcfq [ i ] += _rtB -> kb5uqzu12d [ i + 6 ] * _rtB -> a53as04cdt [ 2 ] ;
} _rtB -> pag11iif1u [ 0 ] = _rtP -> P_1209 * _rtB -> hmae0lpmnc ; _rtB ->
pag11iif1u [ 1 ] = _rtP -> P_1209 * _rtB -> l1inspeofr ; muDoubleScalarSinCos
( _rtB -> pag11iif1u [ 0 ] , & _rtB -> c4kjlsyq1c [ 0 ] , & _rtB ->
i5nrvtfjqu [ 0 ] ) ; muDoubleScalarSinCos ( _rtB -> pag11iif1u [ 1 ] , & _rtB
-> c4kjlsyq1c [ 1 ] , & _rtB -> i5nrvtfjqu [ 1 ] ) ; _rtB -> hakyoxjtaw =
_rtB -> c4kjlsyq1c [ 0 ] * _rtB -> i5nrvtfjqu [ 1 ] ; _rtB -> e0fywp3coc [ 0
] = - _rtB -> hakyoxjtaw ; _rtB -> e0fywp3coc [ 1 ] = - _rtB -> c4kjlsyq1c [
1 ] ; _rtB -> ondfy4dfqf = _rtB -> i5nrvtfjqu [ 0 ] * _rtB -> i5nrvtfjqu [ 1
] ; _rtB -> e0fywp3coc [ 2 ] = - _rtB -> ondfy4dfqf ; _rtB -> kbbjwk3clk =
_rtB -> c4kjlsyq1c [ 0 ] * _rtB -> c4kjlsyq1c [ 1 ] ; _rtB -> e0fywp3coc [ 3
] = - _rtB -> kbbjwk3clk ; _rtB -> e0fywp3coc [ 4 ] = _rtB -> i5nrvtfjqu [ 1
] ; _rtB -> cjlcfeucyj = _rtB -> c4kjlsyq1c [ 1 ] * _rtB -> i5nrvtfjqu [ 0 ]
; _rtB -> e0fywp3coc [ 5 ] = - _rtB -> cjlcfeucyj ; _rtB -> e0fywp3coc [ 6 ]
= _rtB -> i5nrvtfjqu [ 0 ] ; _rtB -> e0fywp3coc [ 7 ] = _rtB -> cqkghf2ij0 ;
_rtB -> e0fywp3coc [ 8 ] = - _rtB -> c4kjlsyq1c [ 0 ] ; for ( i = 0 ; i < 3 ;
i ++ ) { _rtB -> kb5uqzu12d [ 3 * i ] = _rtB -> e0fywp3coc [ i ] ; _rtB ->
kb5uqzu12d [ 1 + 3 * i ] = _rtB -> e0fywp3coc [ i + 3 ] ; _rtB -> kb5uqzu12d
[ 2 + 3 * i ] = _rtB -> e0fywp3coc [ i + 6 ] ; } if ( ssIsSampleHit ( S , 1 ,
0 ) ) { _rtB -> edjmvwqiop = - _rtB -> l5an2hno0l [ 2 ] ; } _rtB ->
a53as04cdt [ 0 ] = _rtB -> cl30bxzim1 ; _rtB -> a53as04cdt [ 1 ] = _rtB ->
cl30bxzim1 ; _rtB -> a53as04cdt [ 2 ] = _rtB -> edjmvwqiop ; for ( i = 0 ; i
< 3 ; i ++ ) { _rtB -> eoby02cfvv [ i ] = 0.0 ; _rtB -> eoby02cfvv [ i ] +=
_rtB -> kb5uqzu12d [ i ] * _rtB -> a53as04cdt [ 0 ] ; _rtB -> eoby02cfvv [ i
] += _rtB -> kb5uqzu12d [ i + 3 ] * _rtB -> a53as04cdt [ 1 ] ; _rtB ->
eoby02cfvv [ i ] += _rtB -> kb5uqzu12d [ i + 6 ] * _rtB -> a53as04cdt [ 2 ] ;
_rtB -> gzg232rcfq [ i ] += _rtB -> eoby02cfvv [ i ] ; _rtB -> pnjyriah10 [ i
] -= _rtB -> gzg232rcfq [ i ] ; } for ( i = 0 ; i < 3 ; i ++ ) { _rtB ->
eoby02cfvv [ i ] = 0.0 ; _rtB -> eoby02cfvv [ i ] += _rtB -> kfud5yrqx3 [ i ]
* _rtB -> pnjyriah10 [ 0 ] ; _rtB -> eoby02cfvv [ i ] += _rtB -> kfud5yrqx3 [
i + 3 ] * _rtB -> pnjyriah10 [ 1 ] ; _rtB -> eoby02cfvv [ i ] += _rtB ->
kfud5yrqx3 [ i + 6 ] * _rtB -> pnjyriah10 [ 2 ] ; } _rtB -> nmh3llf11i = (
real32_T ) _rtB -> eoby02cfvv [ 0 ] ; _rtB -> gjp4sehozh = ( real32_T ) _rtB
-> eoby02cfvv [ 1 ] ; _rtB -> gjdqvqw4fb = _rtB -> mygo3tfeep - _rtB ->
l5an2hno0l [ 2 ] ; _rtB -> pjynqg3zth = ( real32_T ) _rtB -> gjdqvqw4fb ; if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> bk2bocxnru [ 0 ] = _rtB ->
nmh3llf11i ; _rtB -> bk2bocxnru [ 1 ] = _rtB -> gjp4sehozh ; _rtB ->
bk2bocxnru [ 2 ] = _rtB -> pjynqg3zth ; ssCallAccelRunBlock ( S , 154 , 952 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 953 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 954 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> gasdftwi3k [ 0 ] = _rtB -> fauxc0hfky ; _rtB
-> gasdftwi3k [ 1 ] = _rtB -> fyqkzaa3wm ; _rtB -> gasdftwi3k [ 2 ] = _rtB ->
nqk13a31ic ; ssCallAccelRunBlock ( S , 154 , 956 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> k1un210t13 = _rtDW -> duujaz4uai ; _rtB -> jputtfewjo = ( _rtB ->
k1un210t13 >= _rtB -> a1lerntw2w ) ; _rtB -> iejzkspb2z = _rtDW -> m51fjxae3q
; _rtB -> dxqop3e2vc = _rtB -> jputtfewjo ^ _rtB -> iejzkspb2z ; _rtB ->
a3x0uow3mx = _rtDW -> iwph1szj05 ; ssCallAccelRunBlock ( S , 83 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> kim4qjmzs0 = _rtDW -> iuvcjpvfhs ; _rtB ->
lbrixgpnjw = ( int8_T ) ( _rtB -> ezzt22lrar - _rtB -> kim4qjmzs0 ) ; _rtB ->
ftuk4fcjt4 = ( _rtB -> lbrixgpnjw >= _rtB -> gfp422alsd ) ; _rtB ->
nriuuh1urp = _rtDW -> ob4ovamtdg ; _rtB -> kqhgjvkyjq = ( _rtB -> nriuuh1urp
!= _rtB -> jm05r5j2ba ) ; _rtB -> f3ebime2on = ( int8_T ) _rtB -> kqhgjvkyjq
; _rtB -> kxsum5dcfx = _rtDW -> fnvgqua3dj ; _rtB -> a14tzalrwd = _rtDW ->
nuos132tlm ; _rtB -> axir4cyaiz = _rtDW -> hcrfudqbfl ; _rtB -> bne0vtyaxf =
_rtDW -> by10fuwjxj ; _rtB -> nnwvfdn2v5 = _rtDW -> kxwvu3504s ; _rtB ->
mdkkmptlcq = _rtDW -> aafa1dscct ; _rtB -> hzq0vcu24s = _rtDW -> hqmpkyzcuj ;
_rtB -> pllgjytsyu = _rtDW -> kvuljr155n ; _rtB -> j5jgkdlmup = _rtDW ->
jsbp3m2uj5 ; _rtB -> hzundf2hz5 = _rtP -> P_1566 ; } UNUSED_PARAMETER ( tid )
; } static void mdlOutputsTID2 ( SimStruct * S , int_T tid ) { int32_T i ;
real_T tmp ; plshtxiahf * _rtB ; cvqdcwnzy0 * _rtP ; f5cp4dpc1i * _rtDW ;
_rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( cvqdcwnzy0 * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) )
; memcpy ( & _rtB -> gudxackxtf [ 0 ] , & _rtP -> P_1069 [ 0 ] , 90U * sizeof
( real_T ) ) ; _rtB -> nq1khuzl44 = _rtP -> P_1070 ; _rtB -> eu4440vjzk =
_rtP -> P_1071 ; _rtB -> bc001ajh3x = _rtP -> P_1072 ; _rtB -> ep0riuvili =
_rtP -> P_1073 ; tmp = muDoubleScalarFloor ( _rtB -> nq1khuzl44 ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> mxcxqjg10g = (
int8_T ) ( tmp < 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) - tmp
: ( int32_T ) ( int8_T ) ( uint8_T ) tmp ) ; _rtB -> ogdl4kpko1 = _rtP ->
P_1077 ; _rtB -> gprng4gskl = _rtP -> P_1049 ; _rtB -> lvf30m4aw2 = _rtP ->
P_1050 ; _rtB -> l4p3b4pcf4 = _rtP -> P_1051 ; _rtB -> pgmsz4vyii = _rtP ->
P_1052 ; _rtB -> g2b5rn1zvc = _rtP -> P_1053 ; _rtB -> fnhegzubv4 = _rtP ->
P_1054 ; _rtB -> pdyja52nuz = _rtP -> P_1055 ; _rtB -> hs4hzf4agr = _rtP ->
P_1056 ; _rtB -> cszh02bjuh = _rtP -> P_1057 ; _rtB -> h42a2alt5i = _rtP ->
P_1058 ; _rtB -> lb4r5xac0y = _rtP -> P_1059 ; _rtB -> beupwafkve = _rtP ->
P_1060 ; _rtB -> f0xktl33xd = _rtP -> P_1061 ; _rtB -> d2mfjwuehh = _rtP ->
P_1062 ; _rtB -> iharqyqpn5 = _rtP -> P_1913 ; _rtB -> ncioipx5q4 = _rtP ->
P_173 ; _rtB -> ej3uy1jfql = _rtP -> P_174 ; _rtB -> j21wvbjuhs = _rtP ->
P_176 ; h3v44pg0kkTID2 ( & _rtB -> h3v44pg0kkk , ( grglhn4pya * ) & _rtP ->
h3v44pg0kkk ) ; iorhdpdmaiTID2 ( & _rtB -> iorhdpdmaie , ( dcmchj0dqy * ) &
_rtP -> iorhdpdmaie ) ; _rtB -> itiwdm0sot = _rtP -> P_184 ; _rtB ->
myq3xki5s1 = _rtP -> P_185 ; _rtB -> j32kvcqopf = _rtP -> P_186 ; _rtB ->
mu5crbu440 = _rtP -> P_187 ; _rtB -> or0oiotfsp = _rtP -> P_189 ; _rtB ->
cbg5ujvbm0 = _rtP -> P_190 ; _rtB -> had4mmawmc = _rtP -> P_191 ; _rtB ->
glffycbenh = _rtP -> P_192 ; _rtB -> pyeny3b2wi = _rtB -> glffycbenh - _rtB
-> had4mmawmc ; _rtB -> ih0oo3m5nj = _rtP -> P_195 ; _rtB -> j4x023hwgx =
_rtB -> cbg5ujvbm0 - _rtB -> ih0oo3m5nj ; _rtB -> hhzthv0rhe = _rtB ->
j4x023hwgx * _rtB -> j4x023hwgx ; _rtB -> pwer2plzc3 = _rtB -> cbg5ujvbm0 /
_rtB -> hhzthv0rhe ; _rtB -> emysekmysw = _rtB -> pwer2plzc3 - _rtB ->
cbg5ujvbm0 ; _rtB -> lbmoyxwvid = _rtP -> P_197 ; _rtB -> lhosvxn3ui = _rtP
-> P_198 ; _rtB -> najirmjrgf = _rtP -> P_199 ; _rtB -> j3ri0omuep = _rtP ->
P_200 ; _rtB -> kbrqaz4om2 = _rtP -> P_202 ; _rtB -> eky3v3o0lj = _rtP ->
P_203 ; _rtB -> kui2la2leh = _rtP -> P_204 ; _rtB -> fvxczqwwt1 = _rtP ->
P_205 ; _rtB -> aybj3042lq = _rtP -> P_207 ; _rtB -> oiby1oirgr = _rtB ->
fvxczqwwt1 - _rtB -> aybj3042lq ; _rtB -> mlq5vtau3i = _rtB -> oiby1oirgr *
_rtB -> oiby1oirgr ; _rtB -> d55pvgxrpc = _rtB -> fvxczqwwt1 / _rtB ->
mlq5vtau3i ; _rtB -> k0iozxa4ql = _rtB -> d55pvgxrpc - _rtB -> fvxczqwwt1 ;
_rtB -> jugsahblew = _rtP -> P_209 ; _rtB -> h1tn5qf4rw = _rtP -> P_210 ;
_rtB -> ctbysinhjc = _rtP -> P_211 ; _rtB -> n3nbjx3usb = _rtP -> P_212 ;
_rtB -> azyr1o3nmc = _rtP -> P_213 ; _rtB -> cdtxgiqtrs = _rtB -> n3nbjx3usb
- _rtB -> azyr1o3nmc ; _rtB -> k1jlitjicc = _rtB -> ctbysinhjc * _rtB ->
cdtxgiqtrs ; _rtB -> iiuo4smnyg = _rtP -> P_214 ; _rtB -> bft204m5v1 = _rtB
-> cdtxgiqtrs * _rtB -> cdtxgiqtrs ; _rtB -> dm51v5wov2 = _rtB -> iiuo4smnyg
- _rtB -> bft204m5v1 ; _rtB -> ou2vpg4kt2 = _rtP -> P_215 ; _rtB ->
orea3uyejk = _rtB -> ou2vpg4kt2 - _rtB -> dm51v5wov2 ; _rtB -> ouxyooqpux =
_rtB -> dm51v5wov2 / _rtB -> orea3uyejk ; _rtB -> imkmzsjjhp = _rtP -> P_77 ;
_rtB -> a534g2nzpx = _rtP -> P_218 ; _rtB -> arrntb3df4 = _rtP -> P_219 ;
_rtB -> gb2ohd1r2z = _rtP -> P_220 ; _rtB -> jj2p1sjakx = _rtP -> P_227 ;
_rtB -> hwjrsdvxqk = _rtP -> P_236 ; _rtB -> gltow0ukg4 = _rtP -> P_242 ;
_rtB -> liiewueqnu = _rtP -> P_244 ; _rtB -> lwhenhqfrt = _rtP -> P_253 ;
_rtB -> nvek2l3eqj = _rtP -> P_260 ; _rtB -> ks0xmcgka2 = _rtP -> P_266 ;
_rtB -> cz3amf2b5k = _rtP -> P_267 * _rtB -> ks0xmcgka2 ; _rtB -> atlay2wsu0
= _rtP -> P_268 ; _rtB -> fiebllppun = _rtB -> cz3amf2b5k * _rtB ->
atlay2wsu0 ; if ( _rtB -> fiebllppun > _rtP -> P_269 ) { _rtB -> e4nsgkn1dx =
_rtP -> P_269 ; } else if ( _rtB -> fiebllppun < _rtP -> P_270 ) { _rtB ->
e4nsgkn1dx = _rtP -> P_270 ; } else { _rtB -> e4nsgkn1dx = _rtB -> fiebllppun
; } _rtB -> n2tqqz4siq = _rtP -> P_274 * _rtB -> ks0xmcgka2 ; _rtB ->
kxogdlo0te = _rtP -> P_275 ; _rtB -> cewvvwrttt = _rtB -> n2tqqz4siq * _rtB
-> kxogdlo0te ; if ( _rtB -> cewvvwrttt > _rtP -> P_276 ) { _rtB ->
aroihrbipy = _rtP -> P_276 ; } else if ( _rtB -> cewvvwrttt < _rtP -> P_277 )
{ _rtB -> aroihrbipy = _rtP -> P_277 ; } else { _rtB -> aroihrbipy = _rtB ->
cewvvwrttt ; } _rtB -> meyzhnutpf = _rtP -> P_284 ; _rtB -> bfba1ogkqu = _rtP
-> P_292 ; _rtB -> mskcrf5jrp = _rtP -> P_383 ; _rtB -> d0b2v5lcny = _rtP ->
P_387 ; _rtB -> ayl0oow0l5 = _rtP -> P_408 * _rtB -> ks0xmcgka2 ; _rtB ->
a2xhqgz1eb = _rtP -> P_409 * _rtB -> ayl0oow0l5 ; if ( _rtB -> a2xhqgz1eb >
_rtP -> P_410 ) { _rtB -> ekbuyfhagm = _rtP -> P_410 ; } else if ( _rtB ->
a2xhqgz1eb < _rtP -> P_411 ) { _rtB -> ekbuyfhagm = _rtP -> P_411 ; } else {
_rtB -> ekbuyfhagm = _rtB -> a2xhqgz1eb ; } _rtB -> jt1yxszwmh [ 0 ] = _rtP
-> P_412 [ 0 ] ; _rtB -> jt1yxszwmh [ 1 ] = _rtP -> P_412 [ 1 ] ; _rtB ->
jt1yxszwmh [ 2 ] = _rtP -> P_412 [ 2 ] ; for ( i = 0 ; i < 6 ; i ++ ) { _rtB
-> kdk42taj4a [ i ] = _rtP -> P_413 [ i ] ; } _rtB -> finp2j0gwd = _rtP ->
P_414 ; _rtB -> jyesjhe5az = _rtP -> P_419 ; _rtB -> hriysenspw = _rtP ->
P_420 * _rtB -> jyesjhe5az ; _rtB -> e4ovxog3ir = _rtP -> P_421 ; _rtB ->
lbwwig3cpl = _rtB -> hriysenspw * _rtB -> e4ovxog3ir ; if ( _rtB ->
lbwwig3cpl > _rtP -> P_422 ) { _rtB -> pxvkc2esah = _rtP -> P_422 ; } else if
( _rtB -> lbwwig3cpl < _rtP -> P_423 ) { _rtB -> pxvkc2esah = _rtP -> P_423 ;
} else { _rtB -> pxvkc2esah = _rtB -> lbwwig3cpl ; } _rtB -> ov0mqicwg2 =
_rtP -> P_427 ; _rtB -> bp31ri52yv = _rtP -> P_428 * _rtB -> ov0mqicwg2 ;
_rtB -> pkn3f144vi = _rtP -> P_429 ; _rtB -> gemtwyefqa = _rtB -> bp31ri52yv
* _rtB -> pkn3f144vi ; if ( _rtB -> gemtwyefqa > _rtP -> P_430 ) { _rtB ->
atpm0s2bpo = _rtP -> P_430 ; } else if ( _rtB -> gemtwyefqa < _rtP -> P_431 )
{ _rtB -> atpm0s2bpo = _rtP -> P_431 ; } else { _rtB -> atpm0s2bpo = _rtB ->
gemtwyefqa ; } _rtB -> j3egg2jhgv = _rtP -> P_435 ; _rtB -> p4e04iha5n = _rtP
-> P_436 * _rtB -> j3egg2jhgv ; _rtB -> lbebzz11xo = _rtP -> P_437 ; _rtB ->
aqkc42nc5q = _rtB -> p4e04iha5n * _rtB -> lbebzz11xo ; if ( _rtB ->
aqkc42nc5q > _rtP -> P_438 ) { _rtB -> j3g4x1bbri = _rtP -> P_438 ; } else if
( _rtB -> aqkc42nc5q < _rtP -> P_439 ) { _rtB -> j3g4x1bbri = _rtP -> P_439 ;
} else { _rtB -> j3g4x1bbri = _rtB -> aqkc42nc5q ; } _rtB -> ochx1eu4q3 =
_rtP -> P_443 ; _rtB -> nkoraauagu = _rtP -> P_444 * _rtB -> ochx1eu4q3 ;
_rtB -> a2rnfqe4ss = _rtP -> P_445 ; _rtB -> g1qn0onsuo = _rtB -> nkoraauagu
* _rtB -> a2rnfqe4ss ; if ( _rtB -> g1qn0onsuo > _rtP -> P_446 ) { _rtB ->
cs301wf1ne = _rtP -> P_446 ; } else if ( _rtB -> g1qn0onsuo < _rtP -> P_447 )
{ _rtB -> cs301wf1ne = _rtP -> P_447 ; } else { _rtB -> cs301wf1ne = _rtB ->
g1qn0onsuo ; } _rtB -> jhdvplz132 = _rtP -> P_503 ; _rtB -> jx4t0uxrap = _rtP
-> P_508 ; _rtB -> fanghhh3yp = _rtP -> P_509 * _rtB -> jx4t0uxrap ; _rtB ->
h0olg5ii5l = _rtP -> P_510 ; _rtB -> e1xadpeqe1 = _rtB -> fanghhh3yp * _rtB
-> h0olg5ii5l ; if ( _rtB -> e1xadpeqe1 > _rtP -> P_511 ) { _rtB ->
apgogzarvh = _rtP -> P_511 ; } else if ( _rtB -> e1xadpeqe1 < _rtP -> P_512 )
{ _rtB -> apgogzarvh = _rtP -> P_512 ; } else { _rtB -> apgogzarvh = _rtB ->
e1xadpeqe1 ; } _rtB -> jke0au1ogo = _rtP -> P_516 ; _rtB -> jgcnm2e532 = _rtP
-> P_517 * _rtB -> jke0au1ogo ; _rtB -> nrz2jhuzzv = _rtP -> P_518 ; _rtB ->
cwiec2t5n5 = _rtB -> jgcnm2e532 * _rtB -> nrz2jhuzzv ; if ( _rtB ->
cwiec2t5n5 > _rtP -> P_519 ) { _rtB -> iole1shodp = _rtP -> P_519 ; } else if
( _rtB -> cwiec2t5n5 < _rtP -> P_520 ) { _rtB -> iole1shodp = _rtP -> P_520 ;
} else { _rtB -> iole1shodp = _rtB -> cwiec2t5n5 ; } _rtB -> jduwdwwe5o =
_rtP -> P_524 ; _rtB -> gggf4rq2nk = _rtP -> P_525 * _rtB -> jduwdwwe5o ;
_rtB -> d2vyiiu0wq = _rtP -> P_526 ; _rtB -> omrh510025 = _rtB -> gggf4rq2nk
* _rtB -> d2vyiiu0wq ; if ( _rtB -> omrh510025 > _rtP -> P_527 ) { _rtB ->
l5cdujkwj1 = _rtP -> P_527 ; } else if ( _rtB -> omrh510025 < _rtP -> P_528 )
{ _rtB -> l5cdujkwj1 = _rtP -> P_528 ; } else { _rtB -> l5cdujkwj1 = _rtB ->
omrh510025 ; } _rtB -> fjsadantvj = _rtP -> P_532 ; _rtB -> gxyo2gku5n = _rtP
-> P_533 * _rtB -> fjsadantvj ; _rtB -> at2wxqpqai = _rtP -> P_534 ; _rtB ->
fk20fu0f40 = _rtB -> gxyo2gku5n * _rtB -> at2wxqpqai ; if ( _rtB ->
fk20fu0f40 > _rtP -> P_535 ) { _rtB -> g1wyyzl2kt = _rtP -> P_535 ; } else if
( _rtB -> fk20fu0f40 < _rtP -> P_536 ) { _rtB -> g1wyyzl2kt = _rtP -> P_536 ;
} else { _rtB -> g1wyyzl2kt = _rtB -> fk20fu0f40 ; } _rtB -> ottjwazjyv =
_rtP -> P_540 ; _rtB -> dxfo1fcude = _rtP -> P_541 * _rtB -> ottjwazjyv ;
_rtB -> ibvxb0keis = _rtP -> P_542 ; _rtB -> czcpnamwd3 = _rtB -> dxfo1fcude
* _rtB -> ibvxb0keis ; if ( _rtB -> czcpnamwd3 > _rtP -> P_543 ) { _rtB ->
mjolrwowzq = _rtP -> P_543 ; } else if ( _rtB -> czcpnamwd3 < _rtP -> P_544 )
{ _rtB -> mjolrwowzq = _rtP -> P_544 ; } else { _rtB -> mjolrwowzq = _rtB ->
czcpnamwd3 ; } _rtB -> fcqqtyynfl = _rtP -> P_548 ; _rtB -> cfybucutqe = _rtP
-> P_549 * _rtB -> fcqqtyynfl ; _rtB -> gnoucodud3 = _rtP -> P_550 ; _rtB ->
okzqufyog0 = _rtB -> cfybucutqe * _rtB -> gnoucodud3 ; if ( _rtB ->
okzqufyog0 > _rtP -> P_551 ) { _rtB -> bcnlk0vhr4 = _rtP -> P_551 ; } else if
( _rtB -> okzqufyog0 < _rtP -> P_552 ) { _rtB -> bcnlk0vhr4 = _rtP -> P_552 ;
} else { _rtB -> bcnlk0vhr4 = _rtB -> okzqufyog0 ; } _rtB -> ir0cxkmh0q =
_rtP -> P_641 ; _rtB -> mkatec5kct = _rtP -> P_646 ; _rtB -> dgk3zazm5k =
_rtB -> hriysenspw * _rtB -> mkatec5kct ; if ( _rtB -> dgk3zazm5k > _rtP ->
P_647 ) { _rtB -> ate4sawz24 = _rtP -> P_647 ; } else if ( _rtB -> dgk3zazm5k
< _rtP -> P_648 ) { _rtB -> ate4sawz24 = _rtP -> P_648 ; } else { _rtB ->
ate4sawz24 = _rtB -> dgk3zazm5k ; } _rtB -> id3vn1esfy = _rtP -> P_652 ; _rtB
-> kjdhv54ib2 = _rtB -> bp31ri52yv * _rtB -> id3vn1esfy ; if ( _rtB ->
kjdhv54ib2 > _rtP -> P_653 ) { _rtB -> kwh0pijov4 = _rtP -> P_653 ; } else if
( _rtB -> kjdhv54ib2 < _rtP -> P_654 ) { _rtB -> kwh0pijov4 = _rtP -> P_654 ;
} else { _rtB -> kwh0pijov4 = _rtB -> kjdhv54ib2 ; } _rtB -> fb00kmwvdo =
_rtP -> P_658 ; _rtB -> jamzer4yyu = _rtB -> p4e04iha5n * _rtB -> fb00kmwvdo
; if ( _rtB -> jamzer4yyu > _rtP -> P_659 ) { _rtB -> b0a5ga4jkg = _rtP ->
P_659 ; } else if ( _rtB -> jamzer4yyu < _rtP -> P_660 ) { _rtB -> b0a5ga4jkg
= _rtP -> P_660 ; } else { _rtB -> b0a5ga4jkg = _rtB -> jamzer4yyu ; } _rtB
-> khxs5uxoio = _rtP -> P_664 ; _rtB -> ekocij1lo0 = _rtB -> nkoraauagu *
_rtB -> khxs5uxoio ; if ( _rtB -> ekocij1lo0 > _rtP -> P_665 ) { _rtB ->
hi45iwvudw = _rtP -> P_665 ; } else if ( _rtB -> ekocij1lo0 < _rtP -> P_666 )
{ _rtB -> hi45iwvudw = _rtP -> P_666 ; } else { _rtB -> hi45iwvudw = _rtB ->
ekocij1lo0 ; } _rtB -> doh5u2deoh = _rtP -> P_722 ; _rtB -> bv30nzhq21 = _rtP
-> P_727 ; _rtB -> ixd5f4vcp4 = _rtP -> P_728 * _rtB -> bv30nzhq21 ; _rtB ->
eslvem1hei = _rtP -> P_729 ; _rtB -> anp2gzbodp = _rtB -> ixd5f4vcp4 * _rtB
-> eslvem1hei ; if ( _rtB -> anp2gzbodp > _rtP -> P_730 ) { _rtB ->
naxgzpywb4 = _rtP -> P_730 ; } else if ( _rtB -> anp2gzbodp < _rtP -> P_731 )
{ _rtB -> naxgzpywb4 = _rtP -> P_731 ; } else { _rtB -> naxgzpywb4 = _rtB ->
anp2gzbodp ; } _rtB -> okvyp5yiny = _rtP -> P_735 ; _rtB -> ir4s3tnamb = _rtP
-> P_736 * _rtB -> okvyp5yiny ; _rtB -> pox5s1gktf = _rtP -> P_737 ; _rtB ->
eidpbnv0ce = _rtB -> ir4s3tnamb * _rtB -> pox5s1gktf ; if ( _rtB ->
eidpbnv0ce > _rtP -> P_738 ) { _rtB -> pnb5nlrzkf = _rtP -> P_738 ; } else if
( _rtB -> eidpbnv0ce < _rtP -> P_739 ) { _rtB -> pnb5nlrzkf = _rtP -> P_739 ;
} else { _rtB -> pnb5nlrzkf = _rtB -> eidpbnv0ce ; } _rtB -> okbgboetoq =
_rtP -> P_743 ; _rtB -> p5gvqilh21 = _rtP -> P_744 * _rtB -> okbgboetoq ;
_rtB -> fve0yt3ziu = _rtP -> P_745 ; _rtB -> ee3imb1zop = _rtB -> p5gvqilh21
* _rtB -> fve0yt3ziu ; if ( _rtB -> ee3imb1zop > _rtP -> P_746 ) { _rtB ->
dx0l0ewqmn = _rtP -> P_746 ; } else if ( _rtB -> ee3imb1zop < _rtP -> P_747 )
{ _rtB -> dx0l0ewqmn = _rtP -> P_747 ; } else { _rtB -> dx0l0ewqmn = _rtB ->
ee3imb1zop ; } _rtB -> kkxueid14w = _rtP -> P_751 ; _rtB -> d1d24x4kc0 = _rtP
-> P_752 * _rtB -> kkxueid14w ; _rtB -> naowrfnbr5 = _rtP -> P_753 ; _rtB ->
lhltxdmneb = _rtB -> d1d24x4kc0 * _rtB -> naowrfnbr5 ; if ( _rtB ->
lhltxdmneb > _rtP -> P_754 ) { _rtB -> dybezoc5vx = _rtP -> P_754 ; } else if
( _rtB -> lhltxdmneb < _rtP -> P_755 ) { _rtB -> dybezoc5vx = _rtP -> P_755 ;
} else { _rtB -> dybezoc5vx = _rtB -> lhltxdmneb ; } _rtB -> ljlr2lukyw =
_rtP -> P_759 ; _rtB -> iwgoygf40t = _rtP -> P_760 * _rtB -> ljlr2lukyw ;
_rtB -> kdpi2v5ent = _rtP -> P_761 ; _rtB -> hgg1qtet5f = _rtB -> iwgoygf40t
* _rtB -> kdpi2v5ent ; if ( _rtB -> hgg1qtet5f > _rtP -> P_762 ) { _rtB ->
elaq1ggwed = _rtP -> P_762 ; } else if ( _rtB -> hgg1qtet5f < _rtP -> P_763 )
{ _rtB -> elaq1ggwed = _rtP -> P_763 ; } else { _rtB -> elaq1ggwed = _rtB ->
hgg1qtet5f ; } _rtB -> atvwvv5ld4 = _rtP -> P_767 ; _rtB -> p1o5rx3mlv = _rtP
-> P_768 * _rtB -> atvwvv5ld4 ; _rtB -> eii0yezu2j = _rtP -> P_769 ; _rtB ->
ey5rcjzwf1 = _rtB -> p1o5rx3mlv * _rtB -> eii0yezu2j ; if ( _rtB ->
ey5rcjzwf1 > _rtP -> P_770 ) { _rtB -> a0hbuevd0n = _rtP -> P_770 ; } else if
( _rtB -> ey5rcjzwf1 < _rtP -> P_771 ) { _rtB -> a0hbuevd0n = _rtP -> P_771 ;
} else { _rtB -> a0hbuevd0n = _rtB -> ey5rcjzwf1 ; } _rtB -> k25snxv2go =
_rtP -> P_860 ; _rtB -> bm0mjxha4h = _rtP -> P_861 ; _rtB -> el1ckdfmje =
_rtP -> P_862 ; _rtB -> ometiu4anf = _rtP -> P_863 ; _rtB -> lztp3b3ite =
_rtP -> P_866 ; _rtB -> nm2rwjmtgu = _rtP -> P_887 ; _rtB -> mdxqqylize =
_rtP -> P_889 ; _rtB -> n4udnwcm13 = _rtP -> P_892 ; _rtB -> eut2vwpdjb =
_rtP -> P_893 ; _rtB -> j2nt5hzamw = _rtB -> eut2vwpdjb * _rtB -> lvf30m4aw2
; _rtB -> gkf4lhx5zz = _rtB -> n4udnwcm13 + _rtB -> j2nt5hzamw ; _rtB ->
hpvu2fsbhj = _rtP -> P_894 ; _rtB -> moqfpirtr0 = _rtB -> hpvu2fsbhj + _rtB
-> l4p3b4pcf4 ; _rtB -> bjfsxjubzz = _rtP -> P_895 ; _rtB -> nwciyzbla5 =
_rtB -> bjfsxjubzz + _rtB -> pgmsz4vyii ; _rtB -> hqe3oxf1o3 [ 0 ] = _rtP ->
P_896 [ 0 ] ; _rtB -> hqe3oxf1o3 [ 0 ] = _rtB -> gkf4lhx5zz - _rtB ->
hqe3oxf1o3 [ 0 ] ; _rtB -> hqe3oxf1o3 [ 1 ] = _rtP -> P_896 [ 1 ] ; _rtB ->
hqe3oxf1o3 [ 1 ] = _rtB -> moqfpirtr0 - _rtB -> hqe3oxf1o3 [ 1 ] ; _rtB ->
hqe3oxf1o3 [ 2 ] = _rtP -> P_896 [ 2 ] ; _rtB -> hqe3oxf1o3 [ 2 ] = _rtB ->
nwciyzbla5 - _rtB -> hqe3oxf1o3 [ 2 ] ; _rtB -> hdzyk5vm2y = _rtP -> P_910 ;
_rtB -> crjqkvlr0e = _rtP -> P_911 ; _rtB -> iwcflboyob = _rtP -> P_913 ;
_rtB -> afk1mdymlp = _rtP -> P_914 ; _rtB -> dpey5hjmc5 = _rtB -> afk1mdymlp
- _rtB -> iwcflboyob ; _rtB -> bljlrdjz4w = _rtB -> dpey5hjmc5 * _rtB ->
dpey5hjmc5 ; _rtB -> nx5lcmjqng = _rtB -> afk1mdymlp - _rtB -> bljlrdjz4w ;
_rtB -> ezm02ovdpr = _rtP -> P_915 ; _rtB -> gl20br0wtz = _rtP -> P_916 ;
_rtB -> aa0mufjvdk = _rtB -> gl20br0wtz - _rtB -> nx5lcmjqng ; _rtB ->
nhhzzfrix1 = _rtP -> P_917 ; _rtB -> fvns152su4 = _rtP -> P_926 ; _rtB ->
mrvtkhj4gr = _rtP -> P_928 ; _rtB -> hrytix0j05 = _rtP -> P_929 ; _rtB ->
ax45qbmn2q = _rtP -> P_931 ; _rtB -> dknxeg1huj = _rtP -> P_932 ; _rtB ->
ckpoqbckz3 = _rtP -> P_933 * _rtB -> dknxeg1huj ; _rtB -> mxzktzm22b = _rtP
-> P_934 ; _rtB -> caxkb2rdhl = _rtP -> P_935 ; _rtB -> ayzb03i5v1 = _rtP ->
P_937 ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> hc5x3xtoyu [ i ] = 0.0 ; _rtB
-> hc5x3xtoyu [ i ] += _rtP -> P_897 [ i ] * _rtB -> hqe3oxf1o3 [ 0 ] ; _rtB
-> hc5x3xtoyu [ i ] += _rtP -> P_897 [ i + 3 ] * _rtB -> hqe3oxf1o3 [ 1 ] ;
_rtB -> hc5x3xtoyu [ i ] += _rtP -> P_897 [ i + 6 ] * _rtB -> hqe3oxf1o3 [ 2
] ; _rtB -> dzma4p13kw [ i ] = _rtP -> P_909 [ i ] ; _rtB -> jfwlh3hopz [ i ]
= _rtP -> P_940 [ i ] ; } _rtB -> gi3kxmw4gf = _rtP -> P_942 ; _rtB ->
oneisjghjn = _rtB -> gi3kxmw4gf * _rtB -> gprng4gskl ; _rtB -> ih5kw3ko34 =
_rtP -> P_943 ; _rtB -> lvwzfg122i = _rtB -> h42a2alt5i + _rtB -> ih5kw3ko34
; _rtB -> b3xscd53ba = _rtP -> P_944 * _rtB -> lvwzfg122i ; _rtB ->
dfr3xqna51 = muDoubleScalarCos ( _rtB -> b3xscd53ba ) ; _rtB -> nrcik020ip =
_rtP -> P_949 ; _rtB -> nxanjhuz3g = _rtB -> lb4r5xac0y + _rtB -> nrcik020ip
; _rtB -> gum1lfh5hs = _rtP -> P_950 * _rtB -> nxanjhuz3g ; _rtB ->
idndsxfdoq = muDoubleScalarCos ( _rtB -> gum1lfh5hs ) ; _rtB -> k0usjdu4zg =
muDoubleScalarSin ( _rtB -> b3xscd53ba ) ; _rtB -> gwpeufmoux =
muDoubleScalarSin ( _rtB -> gum1lfh5hs ) ; _rtB -> hletofsksk = _rtP -> P_952
; _rtB -> el5uoqjree [ 0 ] = 0.0 ; _rtB -> el5uoqjree [ 1 ] = _rtB ->
hletofsksk ; _rtB -> el5uoqjree [ 2 ] = _rtB -> hletofsksk ; _rtB ->
cpzjy4rxeg = _rtP -> P_953 ; _rtB -> kxlfsi2nv2 = _rtB -> f0xktl33xd + _rtB
-> cpzjy4rxeg ; _rtB -> ljqw2ayqq4 = _rtP -> P_954 * _rtB -> kxlfsi2nv2 ;
_rtB -> eu4gwkksjt = muDoubleScalarCos ( _rtB -> ljqw2ayqq4 ) ; _rtB ->
bb3t1igibb = _rtP -> P_959 ; _rtB -> fgek5gnvrj = _rtB -> d2mfjwuehh + _rtB
-> bb3t1igibb ; _rtB -> gmikys2u1f = _rtP -> P_960 * _rtB -> fgek5gnvrj ;
_rtB -> jbs3at0tih = muDoubleScalarCos ( _rtB -> gmikys2u1f ) ; _rtB ->
aomahecexm = muDoubleScalarSin ( _rtB -> ljqw2ayqq4 ) ; _rtB -> k4beb24i02 =
muDoubleScalarSin ( _rtB -> gmikys2u1f ) ; _rtB -> b3sfflswhu = _rtP -> P_962
* 0.0 ; _rtB -> ng4ypc2bw2 = _rtP -> P_963 ; _rtB -> mykeqgmrzq [ 0 ] = _rtB
-> b3sfflswhu ; _rtB -> mykeqgmrzq [ 1 ] = _rtB -> ng4ypc2bw2 ; _rtB ->
mykeqgmrzq [ 2 ] = _rtB -> ng4ypc2bw2 ; memcpy ( & _rtB -> dupz5lwskr [ 0 ] ,
& _rtP -> P_965 [ 0 ] , 9U * sizeof ( real_T ) ) ; _rtB -> hzah0n2sf4 = _rtP
-> P_966 ; _rtB -> iqbspnflb4 = _rtP -> P_967 ; _rtB -> pzep4bhyod = _rtP ->
P_1811 ; _rtB -> nirbpoli3q = _rtP -> P_969 ; _rtB -> dvskicmsxu = _rtP ->
P_970 ; _rtB -> oqqrievgsr = _rtP -> P_971 ; _rtB -> isp2av5ay3 = _rtP ->
P_975 ; _rtB -> nxrdljwvj2 = _rtB -> isp2av5ay3 * _rtB -> isp2av5ay3 ; _rtB
-> cxd0lvvcve = _rtP -> P_976 ; _rtB -> fkejxlkcsq [ 0 ] = _rtB -> dupz5lwskr
[ 0 ] ; _rtB -> fau2uzx3o2 [ 0 ] = _rtB -> dupz5lwskr [ 0 ] ; _rtB ->
fkejxlkcsq [ 1 ] = _rtB -> dupz5lwskr [ 1 ] ; _rtB -> fau2uzx3o2 [ 1 ] = _rtB
-> dupz5lwskr [ 1 ] ; _rtB -> fkejxlkcsq [ 2 ] = _rtB -> dupz5lwskr [ 2 ] ;
_rtB -> fau2uzx3o2 [ 2 ] = _rtB -> dupz5lwskr [ 2 ] ; _rtB -> kjrxl25tgm =
_rtP -> P_983 ; _rtB -> ebepfuajzv = _rtP -> P_984 ; lvrrs02dbeTID2 ( S ,
_rtB -> fkejxlkcsq , & _rtB -> lvrrs02dbel , & _rtDW -> lvrrs02dbel , (
dbjdkpcxft * ) & _rtP -> lvrrs02dbel ) ; _rtB -> nitrvromjj = _rtP -> P_1812
; _rtB -> ltperw2ubl = _rtP -> P_986 ; _rtB -> kxffgc0x4f = _rtP -> P_989 ;
_rtB -> getxiio5mp = _rtB -> kxffgc0x4f * _rtB -> kxffgc0x4f ; _rtB ->
egkz31xsi0 [ 0 ] = _rtB -> dupz5lwskr [ 3 ] ; _rtB -> brxxd1u0my [ 0 ] = _rtB
-> dupz5lwskr [ 3 ] ; _rtB -> egkz31xsi0 [ 1 ] = _rtB -> dupz5lwskr [ 4 ] ;
_rtB -> brxxd1u0my [ 1 ] = _rtB -> dupz5lwskr [ 4 ] ; _rtB -> egkz31xsi0 [ 2
] = _rtB -> dupz5lwskr [ 5 ] ; _rtB -> brxxd1u0my [ 2 ] = _rtB -> dupz5lwskr
[ 5 ] ; _rtB -> incajketqw = _rtP -> P_995 ; dak2bbvhdyTID2 ( S , _rtB ->
egkz31xsi0 , & _rtB -> dak2bbvhdyl , & _rtDW -> dak2bbvhdyl , ( fgfesxh13p *
) & _rtP -> dak2bbvhdyl ) ; _rtB -> b2qgbs4ore = _rtP -> P_997 ; _rtB ->
nru1lpts5q = _rtP -> P_1000 ; _rtB -> etphalrkq3 = _rtB -> nru1lpts5q * _rtB
-> nru1lpts5q ; _rtB -> lygv535h0z [ 0 ] = _rtB -> dupz5lwskr [ 6 ] ; _rtB ->
k3wordm2hu [ 0 ] = _rtB -> dupz5lwskr [ 6 ] ; _rtB -> lygv535h0z [ 1 ] = _rtB
-> dupz5lwskr [ 7 ] ; _rtB -> k3wordm2hu [ 1 ] = _rtB -> dupz5lwskr [ 7 ] ;
_rtB -> lygv535h0z [ 2 ] = _rtB -> dupz5lwskr [ 8 ] ; _rtB -> k3wordm2hu [ 2
] = _rtB -> dupz5lwskr [ 8 ] ; _rtB -> irowwtyk2h = _rtP -> P_1813 ; _rtB ->
pyqaujjma1 = _rtP -> P_1011 ; b1bttejwsjTID2 ( S , _rtB -> lygv535h0z , &
_rtB -> b1bttejwsj2 , & _rtDW -> b1bttejwsj2 , ( fvjsblhu4h * ) & _rtP ->
b1bttejwsj2 ) ; ssCallAccelRunBlock ( S , 152 , 1158 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 152 , 1167 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 152 , 1183 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
l3ssotn1bc = _rtP -> P_1022 ; _rtB -> pkqtcha15g = _rtP -> P_1023 ; _rtB ->
perdw4sbln = _rtP -> P_1024 ; _rtB -> a0sjxervj4 = _rtP -> P_1025 ; _rtB ->
jqkysumo2i = _rtP -> P_1026 ; _rtB -> evngdvyvp1 = _rtP -> P_1027 ; _rtB ->
aqkswihdvo = _rtB -> pkqtcha15g * _rtB -> pdyja52nuz ; _rtB -> mbt30wd3i5 =
_rtB -> l3ssotn1bc * _rtB -> fnhegzubv4 ; _rtB -> h3sehwcn2d = _rtB ->
evngdvyvp1 * _rtB -> g2b5rn1zvc ; _rtB -> dsf4svdctq [ 0 ] = _rtB ->
h3sehwcn2d ; _rtB -> aexz5verqf = - _rtB -> a0sjxervj4 ; _rtB -> dsf4svdctq [
1 ] = _rtB -> aexz5verqf ; _rtB -> nypiq5135k = - _rtB -> perdw4sbln ; _rtB
-> dsf4svdctq [ 2 ] = _rtB -> nypiq5135k ; _rtB -> dsf4svdctq [ 3 ] = _rtB ->
aexz5verqf ; _rtB -> dsf4svdctq [ 4 ] = _rtB -> mbt30wd3i5 ; _rtB ->
ch23bzjzcm = - _rtB -> jqkysumo2i ; _rtB -> dsf4svdctq [ 5 ] = _rtB ->
ch23bzjzcm ; _rtB -> dsf4svdctq [ 6 ] = _rtB -> nypiq5135k ; _rtB ->
dsf4svdctq [ 7 ] = _rtB -> ch23bzjzcm ; _rtB -> dsf4svdctq [ 8 ] = _rtB ->
aqkswihdvo ; _rtB -> lowxwmy1d5 = _rtP -> P_1029 ; _rtB -> dryds5iyuk = _rtP
-> P_1030 * _rtB -> lowxwmy1d5 ; _rtB -> ovqrwhozf3 = _rtP -> P_1032 ; _rtB
-> eteubwukjc = _rtP -> P_1033 ; memcpy ( & _rtB -> pc2kcg4gic [ 0 ] , & _rtP
-> P_1034 [ 0 ] , 9U * sizeof ( real_T ) ) ; _rtB -> nmyabhmznp [ 0 ] = _rtP
-> P_1035 [ 0 ] ; _rtB -> nmyabhmznp [ 1 ] = _rtP -> P_1035 [ 1 ] ; _rtB ->
nmyabhmznp [ 2 ] = _rtP -> P_1035 [ 2 ] ; h3v44pg0kkTID2 ( & _rtB ->
hnb3thjcdb , ( grglhn4pya * ) & _rtP -> hnb3thjcdb ) ; iorhdpdmaiTID2 ( &
_rtB -> k0g5ylghay , ( dcmchj0dqy * ) & _rtP -> k0g5ylghay ) ; _rtB ->
cpazwnicb3 = _rtP -> P_1037 ; _rtB -> pvkyynno3r = _rtP -> P_1038 ; if (
ssIsMajorTimeStep ( S ) ) { srUpdateBC ( _rtDW -> dn2qcnfz0e ) ; } _rtB ->
lsflo3diem = _rtP -> P_1111 ; ssCallAccelRunBlock ( S , 154 , 116 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 117 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 118 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 154 , 119 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> jjr1xk2sxt = _rtP -> P_1824 ; _rtB ->
m00rigfror = _rtP -> P_1118 ; _rtB -> njttdzg5pg = ( real32_T ) _rtB ->
m00rigfror ; _rtB -> mb4nzgj5qu = ( real32_T ) _rtB -> m00rigfror ; _rtB ->
hxfb0tmmyu = ( real32_T ) _rtB -> m00rigfror ; _rtB -> ldjvo1h31f = (
real32_T ) _rtB -> m00rigfror ; _rtB -> bccwan41tw = ( real32_T ) _rtB ->
m00rigfror ; _rtB -> mt5wovjfqr = _rtP -> P_1122 ; tmp = muDoubleScalarFloor
( _rtB -> mt5wovjfqr ) ; if ( muDoubleScalarIsNaN ( tmp ) ||
muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem
( tmp , 256.0 ) ; } _rtB -> lvh2iu2nbc = ( int8_T ) ( tmp < 0.0 ? ( int32_T )
( int8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T ) ( int8_T ) ( uint8_T
) tmp ) ; _rtB -> pmv3smrc3x = _rtP -> P_1123 ; tmp = muDoubleScalarFloor (
_rtB -> pmv3smrc3x ) ; if ( muDoubleScalarIsNaN ( tmp ) ||
muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem
( tmp , 256.0 ) ; } _rtB -> dow3opkv5g = ( int8_T ) ( tmp < 0.0 ? ( int32_T )
( int8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T ) ( int8_T ) ( uint8_T
) tmp ) ; _rtB -> ilvleumvf4 = _rtP -> P_1130 ; _rtB -> fgredvb3ez = _rtP ->
P_1131 ; _rtB -> jj3avp2qre = _rtP -> P_1213 ; _rtB -> lslrsz2w5h = _rtP ->
P_1214 ; _rtB -> fvdb0lzwq1 = _rtP -> P_1835 ; _rtB -> mk4mseeysw = _rtP ->
P_1839 ; _rtB -> aksw4mqnzr = _rtP -> P_1842 ; _rtB -> cpplkk4uwf = _rtP ->
P_1843 ; _rtB -> mhbprhznje = _rtP -> P_1859 ; _rtB -> jhhye5i3sl = _rtP ->
P_1139 ; _rtB -> csrddaexjd = ( real32_T ) _rtB -> jhhye5i3sl ; _rtB ->
mr5f15h2wp = _rtP -> P_1140 ; _rtB -> adh0jiltxj = ( real32_T ) _rtB ->
mr5f15h2wp ; _rtB -> flxqhvkcb5 = _rtB -> csrddaexjd + _rtB -> adh0jiltxj ;
_rtB -> dtsgkdxb50 = _rtP -> P_1492 * _rtB -> flxqhvkcb5 ; _rtB -> ck4b0pjrym
= _rtB -> dtsgkdxb50 - _rtB -> adh0jiltxj ; _rtB -> kph14pxxdi = _rtP ->
P_1142 ; _rtB -> nmxwzij5cq = ( real32_T ) _rtB -> kph14pxxdi ; _rtB ->
d3eljial21 = _rtP -> P_1143 ; _rtB -> h1rwhjydfk = ( real32_T ) _rtB ->
d3eljial21 ; _rtB -> h2ae0eqtm3 = _rtB -> nmxwzij5cq + _rtB -> h1rwhjydfk ;
_rtB -> pfgty0dzhn = _rtP -> P_1495 * _rtB -> h2ae0eqtm3 ; _rtB -> hq1zjwyxqs
= _rtB -> pfgty0dzhn - _rtB -> h1rwhjydfk ; _rtB -> eqniezg0km = _rtP ->
P_1145 ; _rtB -> jo0m3e42da = ( real32_T ) _rtB -> eqniezg0km ; _rtB ->
lpitruyuqj = _rtP -> P_1146 ; _rtB -> lacff13ap5 = ( real32_T ) _rtB ->
lpitruyuqj ; _rtB -> f01tcevdud = _rtB -> jo0m3e42da + _rtB -> lacff13ap5 ;
_rtB -> aoagctkwip = _rtP -> P_1498 * _rtB -> f01tcevdud ; _rtB -> bjt3xtuwd1
= _rtB -> aoagctkwip - _rtB -> lacff13ap5 ; _rtB -> hcte4wigmp = _rtP ->
P_1873 ; _rtB -> ldgxk2v0et = _rtP -> P_1881 ; _rtB -> psrnnkw0zr = _rtP ->
P_1147 ; _rtB -> hnqt423fge = _rtP -> P_1148 ; _rtB -> k2rfvwaud4 = ( _rtB ->
psrnnkw0zr >= _rtB -> hnqt423fge ) ; _rtB -> ohscboqbmt = ( int8_T ) _rtB ->
k2rfvwaud4 ; jtjpxjywrwTID2 ( S ) ; _rtB -> gktbammvhu [ 0 ] = ( real32_T )
0.0 ; _rtB -> gktbammvhu [ 1 ] = ( real32_T ) 0.0 ; _rtB -> gktbammvhu [ 2 ]
= ( real32_T ) 0.0 ; _rtB -> gktbammvhu [ 3 ] = ( real32_T ) 0.0 ;
ssCallAccelRunBlock ( S , 154 , 496 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
jrotnppws0 = _rtP -> P_1556 ; _rtB -> jblfxapt5t = 0.0 ; tmp =
muDoubleScalarFloor ( _rtB -> jblfxapt5t ) ; if ( muDoubleScalarIsNaN ( tmp )
|| muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp =
muDoubleScalarRem ( tmp , 256.0 ) ; } _rtB -> cofatgbomn = ( int8_T ) ( tmp <
0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) - tmp : ( int32_T ) (
int8_T ) ( uint8_T ) tmp ) ; _rtB -> etr4wm3uxq = _rtP -> P_1900 ; _rtB ->
e2zjbxe4nc = ( _rtB -> cofatgbomn >= _rtB -> etr4wm3uxq ) ; _rtB ->
bbhtgsnftr = ( int8_T ) _rtB -> e2zjbxe4nc ; _rtB -> gh25tmlh4a = _rtP ->
P_1150 ; _rtB -> amjcjvwcc3 = _rtP -> P_1151 ; _rtB -> hduhysvp2t = ( _rtB ->
gh25tmlh4a >= _rtB -> amjcjvwcc3 ) ; _rtB -> d20k0pudk1 = ( int8_T ) _rtB ->
hduhysvp2t ; _rtB -> iksrh4iqw2 = _rtP -> P_1901 ; _rtB -> niu11cubac = _rtP
-> P_1902 ; _rtB -> db0xe1untb = _rtP -> P_1155 ; _rtB -> d0umcptuv2 = _rtP
-> P_1157 ; _rtB -> lgyahwt5az = _rtP -> P_1158 ; _rtB -> ktocsnkmqn = _rtP
-> P_1159 ; _rtB -> hedld4sq1s = _rtP -> P_1160 ; _rtB -> b5bwo4xsl5 = _rtP
-> P_1161 ; _rtB -> ddvgudknjj = _rtP -> P_1163 ; _rtB -> mkvlmyql3w = _rtP
-> P_1164 ; _rtB -> nkq1ticwxm = _rtP -> P_1165 ; _rtB -> d0vl2rppec = _rtP
-> P_1166 ; _rtB -> hd0n1hoq5s = _rtB -> d0vl2rppec - _rtB -> nkq1ticwxm ;
_rtB -> aistetkjw4 = _rtP -> P_1169 ; _rtB -> apazdn1yqj = _rtB -> mkvlmyql3w
- _rtB -> aistetkjw4 ; _rtB -> apg5ow0wgf = _rtB -> apazdn1yqj * _rtB ->
apazdn1yqj ; _rtB -> nxjyhfbcdx = _rtB -> mkvlmyql3w / _rtB -> apg5ow0wgf ;
_rtB -> dhi3sqv521 = _rtB -> nxjyhfbcdx - _rtB -> mkvlmyql3w ; _rtB ->
jeko3oryhk = _rtP -> P_1171 ; _rtB -> icyi2fy0un = _rtP -> P_1172 ; _rtB ->
mwcyki0vp1 = _rtP -> P_1173 ; _rtB -> avm1d5ejfb = _rtP -> P_1174 ; _rtB ->
mvg0q0n5eb = _rtP -> P_1176 ; _rtB -> mrmlhrmijp = _rtP -> P_1177 ; _rtB ->
fktwpod13x = _rtP -> P_1178 ; _rtB -> ajwaigw2uc = _rtP -> P_1179 ; _rtB ->
gdpwk11j03 = _rtP -> P_1181 ; _rtB -> muf2vsp0dq = _rtB -> ajwaigw2uc - _rtB
-> gdpwk11j03 ; _rtB -> imcho3kaea = _rtB -> muf2vsp0dq * _rtB -> muf2vsp0dq
; _rtB -> pr20sqc335 = _rtB -> ajwaigw2uc / _rtB -> imcho3kaea ; _rtB ->
jrqmc5rg24 = _rtB -> pr20sqc335 - _rtB -> ajwaigw2uc ; _rtB -> gtihpno34h =
_rtP -> P_1183 ; _rtB -> duc345ncoo = _rtP -> P_1184 ; _rtB -> gtiun4r12s =
_rtP -> P_1185 ; _rtB -> e3rukdvq23 = _rtP -> P_1186 ; _rtB -> m0gymoot1b =
_rtP -> P_1187 ; _rtB -> civrcr2kdw = _rtP -> P_1188 ; _rtB -> ojyf1hwri0 =
_rtP -> P_1190 ; _rtB -> fwd5fpzz2i = _rtP -> P_1191 ; _rtB -> bbbtgkb3gv =
_rtP -> P_1192 ; _rtB -> kjj2ddbcta = _rtP -> P_1193 ; _rtB -> m4hueopc3x =
_rtB -> kjj2ddbcta - _rtB -> bbbtgkb3gv ; _rtB -> pm45nvouzt = _rtP -> P_1196
; _rtB -> f2i5iuhv1e = _rtB -> fwd5fpzz2i - _rtB -> pm45nvouzt ; _rtB ->
mur0vyyxfb = _rtB -> f2i5iuhv1e * _rtB -> f2i5iuhv1e ; _rtB -> ltwsxq11rv =
_rtB -> fwd5fpzz2i / _rtB -> mur0vyyxfb ; _rtB -> h55krfswe5 = _rtB ->
ltwsxq11rv - _rtB -> fwd5fpzz2i ; _rtB -> e0x52cru2p = _rtP -> P_1198 ; _rtB
-> c2okuvnfpu = _rtP -> P_1199 ; _rtB -> fg5ikfqx5v = _rtP -> P_1200 ; _rtB
-> pq21nocpry = _rtP -> P_1201 ; _rtB -> oqd5hhfrjr = _rtP -> P_1203 ; _rtB
-> ph5vjctp4q = _rtP -> P_1204 ; _rtB -> kky1e5qkac = _rtP -> P_1205 ; _rtB
-> goqjupftg0 = _rtP -> P_1206 ; _rtB -> lbvw4avjxe = _rtP -> P_1208 ; _rtB
-> ky330hcdr2 = _rtB -> goqjupftg0 - _rtB -> lbvw4avjxe ; _rtB -> oks25ugmla
= _rtB -> ky330hcdr2 * _rtB -> ky330hcdr2 ; _rtB -> lqohllvrch = _rtB ->
goqjupftg0 / _rtB -> oks25ugmla ; _rtB -> g1miatmxni = _rtB -> lqohllvrch -
_rtB -> goqjupftg0 ; _rtB -> cqkghf2ij0 = _rtP -> P_1210 ; _rtB -> cl30bxzim1
= _rtP -> P_1211 ; _rtB -> a1lerntw2w = _rtP -> P_1907 ; _rtB -> gfp422alsd =
_rtP -> P_1910 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { plshtxiahf * _rtB ;
f5cp4dpc1i * _rtDW ; _rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1
, 0 ) ) { _rtDW -> e4nz3golqn = _rtB -> j5jgkdlmup ; _rtDW -> l1klrgmmsl =
_rtB -> djgcgsvzkf ; _rtDW -> ntf50l3qxv = _rtB -> inuazd3mp3 ; _rtDW ->
geqmfi3fte = _rtB -> bxithui4ut ; _rtDW -> ahjrt4ebav = _rtB -> ka1sbg21s3 ;
_rtDW -> gecxa4qcyy = _rtB -> dzuzgktzus ; _rtDW -> n2wcftxdjs = _rtB ->
ol50sxig1a ; } if ( _rtDW -> h1triskzhg ) { _rtDW -> grymb5dts4 = 0 ; _rtDW
-> j3ij5dyxsq = 0 ; _rtDW -> gqsx3hpmt3 [ 0 ] = _rtB -> isom3ebtib [ 0 ] ;
_rtDW -> gqsx3hpmt3 [ 1 ] = _rtB -> isom3ebtib [ 1 ] ; _rtDW -> gqsx3hpmt3 [
2 ] = _rtB -> isom3ebtib [ 2 ] ; _rtDW -> bcfg4ee1te = ssGetTaskTime ( S , 0
) ; _rtDW -> gd0ppilara = 0 ; _rtDW -> f2mgdridkq = _rtB -> hgr3hfctxj ;
_rtDW -> nxpmlabht5 = 0 ; hztvnhnxrv ( S , & _rtB -> lvrrs02dbel , & _rtDW ->
lvrrs02dbel ) ; onr0acfhav ( S , & _rtB -> dak2bbvhdyl , & _rtDW ->
dak2bbvhdyl ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> gp1feal4z4 =
_rtB -> irowwtyk2h ; _rtDW -> amvb32hegv = _rtB -> irowwtyk2h ; _rtDW ->
klycy0wa1d = _rtB -> kb5cizhzgc ; } _rtDW -> m33fcwggx1 = 0 ; _rtDW ->
hpqyrum1dh = 0 ; ggcobnfl5g ( S , & _rtB -> b1bttejwsj2 , & _rtDW ->
b1bttejwsj2 ) ; _rtDW -> pbax4pbj0t = 0 ; } if ( ssIsSampleHit ( S , 1 , 0 )
) { _rtDW -> mk1bzf5kc5 = _rtB -> joh40kiala ; _rtDW -> ai4ll2tnnp = _rtB ->
caf5uj1c42 ; _rtDW -> hb0rwwvarv = _rtB -> me10oyjfnz ; _rtDW -> ofybqkqhqt =
_rtB -> ftuk4fcjt4 ; _rtDW -> ll42raa0oa = _rtB -> ib3c1q5rew ; _rtDW ->
ekbyf5uzmq = _rtB -> meoixgyrir ; _rtDW -> dfi5fmg2dj = _rtB -> ngh1crjcxs ;
_rtDW -> k00p0ildsb = _rtB -> f1ephbjun5 ; _rtDW -> kk1jzqnnxn = _rtB ->
n13p2el25f ; _rtDW -> a0crd4prk2 = _rtB -> lr13p00not ; _rtDW -> aniqqbzlgr =
_rtB -> mx3dqajete ; _rtDW -> pmevyjdenu = _rtB -> bfqunkspeq ; _rtDW ->
apduj42log = _rtB -> blzmzxfk0t ; _rtDW -> octl2ppvtx = _rtB -> c0rffbrqdd ;
_rtDW -> gfvjsifc4g = _rtB -> h3ss2zo004 ; _rtDW -> b4jn1iqhjp = _rtB ->
j5m1bekokx ; } ssCallAccelRunBlock ( S , 154 , 354 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 154 , 357 , SS_CALL_MDL_UPDATE ) ;
ssCallAccelRunBlock ( S , 154 , 362 , SS_CALL_MDL_UPDATE ) ; irv3p1y3ss ( S )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtDW -> ow1wrqv3g4 = _rtB ->
akpt2xxopu ; _rtDW -> ntglwj5pkh = _rtB -> ipvemgkdri ; _rtDW -> f0e22lzj55 =
_rtB -> iksrh4iqw2 ; _rtDW -> duujaz4uai = _rtB -> joh40kiala ; _rtDW ->
m51fjxae3q = _rtB -> jputtfewjo ; _rtDW -> iwph1szj05 = _rtB -> f3ebime2on ;
_rtDW -> iuvcjpvfhs = _rtB -> ezzt22lrar ; _rtDW -> ob4ovamtdg = _rtB ->
jm05r5j2ba ; _rtDW -> fnvgqua3dj = _rtB -> a0221uon2j ; _rtDW -> nuos132tlm =
_rtB -> kxsum5dcfx ; _rtDW -> hcrfudqbfl = _rtB -> a14tzalrwd ; _rtDW ->
by10fuwjxj = _rtB -> axir4cyaiz ; _rtDW -> kxwvu3504s = _rtB -> bne0vtyaxf ;
_rtDW -> aafa1dscct = _rtB -> nnwvfdn2v5 ; _rtDW -> hqmpkyzcuj = _rtB ->
mdkkmptlcq ; _rtDW -> kvuljr155n = _rtB -> hzq0vcu24s ; _rtDW -> jsbp3m2uj5 =
_rtB -> pllgjytsyu ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { boolean_T lsat ; boolean_T
usat ; plshtxiahf * _rtB ; cvqdcwnzy0 * _rtP ; aneejwrild * _rtX ; g3u2dpkjkc
* _rtXdot ; f5cp4dpc1i * _rtDW ; _rtDW = ( ( f5cp4dpc1i * ) ssGetRootDWork (
S ) ) ; _rtXdot = ( ( g3u2dpkjkc * ) ssGetdX ( S ) ) ; _rtX = ( ( aneejwrild
* ) ssGetContStates ( S ) ) ; _rtP = ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) )
; _rtB = ( ( plshtxiahf * ) _ssGetModelBlockIO ( S ) ) ; if ( _rtDW ->
h1triskzhg ) { _rtXdot -> g2szyo42jj = 0.0 ; _rtXdot -> g2szyo42jj += _rtP ->
P_87 * _rtX -> g2szyo42jj ; _rtXdot -> g2szyo42jj += _rtB -> mc2nkfth2u [ 0 ]
; _rtXdot -> fn5nnjex4j = _rtB -> evbbqvdcty ; lsat = ( _rtX -> gupqkdacwq <=
_rtP -> P_99 ) ; usat = ( _rtX -> gupqkdacwq >= _rtP -> P_98 ) ; if ( ( ( !
lsat ) && ( ! usat ) ) || ( lsat && ( _rtB -> fooruvuylr > 0.0 ) ) || ( usat
&& ( _rtB -> fooruvuylr < 0.0 ) ) ) { _rtXdot -> gupqkdacwq = _rtB ->
fooruvuylr ; } else { _rtXdot -> gupqkdacwq = 0.0 ; } _rtXdot -> nuv0yyibvo =
_rtB -> bnpw2vxvzw ; lsat = ( _rtX -> ddaf4beo1a <= _rtP -> P_109 ) ; usat =
( _rtX -> ddaf4beo1a >= _rtP -> P_108 ) ; if ( ( ( ! lsat ) && ( ! usat ) )
|| ( lsat && ( _rtB -> eaupvfytps > 0.0 ) ) || ( usat && ( _rtB -> eaupvfytps
< 0.0 ) ) ) { _rtXdot -> ddaf4beo1a = _rtB -> eaupvfytps ; } else { _rtXdot
-> ddaf4beo1a = 0.0 ; } _rtXdot -> m53fvqufyn = _rtB -> exwtxdiv0z ; lsat = (
_rtX -> jzz5v30cof <= _rtP -> P_119 ) ; usat = ( _rtX -> jzz5v30cof >= _rtP
-> P_118 ) ; if ( ( ( ! lsat ) && ( ! usat ) ) || ( lsat && ( _rtB ->
nomatn2fz3 > 0.0 ) ) || ( usat && ( _rtB -> nomatn2fz3 < 0.0 ) ) ) { _rtXdot
-> jzz5v30cof = _rtB -> nomatn2fz3 ; } else { _rtXdot -> jzz5v30cof = 0.0 ; }
_rtXdot -> jycafulcqx = _rtB -> it3qches1x ; lsat = ( _rtX -> d2alyourid <=
_rtP -> P_129 ) ; usat = ( _rtX -> d2alyourid >= _rtP -> P_128 ) ; if ( ( ( !
lsat ) && ( ! usat ) ) || ( lsat && ( _rtB -> crqshwrbtm > 0.0 ) ) || ( usat
&& ( _rtB -> crqshwrbtm < 0.0 ) ) ) { _rtXdot -> d2alyourid = _rtB ->
crqshwrbtm ; } else { _rtXdot -> d2alyourid = 0.0 ; } _rtXdot -> b4tooowqob =
_rtB -> nzno4rtdsn ; lsat = ( _rtX -> bo333uqftn <= _rtP -> P_139 ) ; usat =
( _rtX -> bo333uqftn >= _rtP -> P_138 ) ; if ( ( ( ! lsat ) && ( ! usat ) )
|| ( lsat && ( _rtB -> nxlljkrvr0 > 0.0 ) ) || ( usat && ( _rtB -> nxlljkrvr0
< 0.0 ) ) ) { _rtXdot -> bo333uqftn = _rtB -> nxlljkrvr0 ; } else { _rtXdot
-> bo333uqftn = 0.0 ; } _rtXdot -> gdpetm5ycb = _rtB -> oukkx3ba3k ; lsat = (
_rtX -> oagjyzakjn <= _rtP -> P_149 ) ; usat = ( _rtX -> oagjyzakjn >= _rtP
-> P_148 ) ; if ( ( ( ! lsat ) && ( ! usat ) ) || ( lsat && ( _rtB ->
cnmo42efk1 > 0.0 ) ) || ( usat && ( _rtB -> cnmo42efk1 < 0.0 ) ) ) { _rtXdot
-> oagjyzakjn = _rtB -> cnmo42efk1 ; } else { _rtXdot -> oagjyzakjn = 0.0 ; }
_rtXdot -> nrnlh3tixw = _rtB -> k23gejr2l2 ; lsat = ( _rtX -> bkhhqiqzcb <=
_rtP -> P_159 ) ; usat = ( _rtX -> bkhhqiqzcb >= _rtP -> P_158 ) ; if ( ( ( !
lsat ) && ( ! usat ) ) || ( lsat && ( _rtB -> i3tvu1ajhg > 0.0 ) ) || ( usat
&& ( _rtB -> i3tvu1ajhg < 0.0 ) ) ) { _rtXdot -> bkhhqiqzcb = _rtB ->
i3tvu1ajhg ; } else { _rtXdot -> bkhhqiqzcb = 0.0 ; } _rtXdot -> euz1cekogw =
_rtB -> mdpmxxqx3t ; lsat = ( _rtX -> oq3g2uysed <= _rtP -> P_169 ) ; usat =
( _rtX -> oq3g2uysed >= _rtP -> P_168 ) ; if ( ( ( ! lsat ) && ( ! usat ) )
|| ( lsat && ( _rtB -> hta4ebri2p > 0.0 ) ) || ( usat && ( _rtB -> hta4ebri2p
< 0.0 ) ) ) { _rtXdot -> oq3g2uysed = _rtB -> hta4ebri2p ; } else { _rtXdot
-> oq3g2uysed = 0.0 ; } _rtXdot -> hu4sqeqyp2 [ 0 ] = _rtB -> mzmkyxa0az ;
_rtXdot -> hu4sqeqyp2 [ 1 ] = _rtB -> habc1jzdlw ; _rtXdot -> hu4sqeqyp2 [ 2
] = _rtB -> gxynvltyfa ; _rtXdot -> hu4sqeqyp2 [ 3 ] = _rtB -> iaypcbmsve ;
_rtXdot -> h243v3o4jo [ 0 ] = _rtB -> g5vnb24p3z [ 0 ] ; _rtXdot ->
newd2wm3dk [ 0 ] = _rtB -> cdw3j2li5c [ 0 ] ; _rtXdot -> l3tdaf3wuy [ 0 ] =
_rtB -> puqqtpd2td [ 0 ] ; _rtXdot -> h243v3o4jo [ 1 ] = _rtB -> g5vnb24p3z [
1 ] ; _rtXdot -> newd2wm3dk [ 1 ] = _rtB -> cdw3j2li5c [ 1 ] ; _rtXdot ->
l3tdaf3wuy [ 1 ] = _rtB -> puqqtpd2td [ 1 ] ; _rtXdot -> h243v3o4jo [ 2 ] =
_rtB -> g5vnb24p3z [ 2 ] ; _rtXdot -> newd2wm3dk [ 2 ] = _rtB -> cdw3j2li5c [
2 ] ; _rtXdot -> l3tdaf3wuy [ 2 ] = _rtB -> puqqtpd2td [ 2 ] ; lsat = ( _rtX
-> kvv12h1lmd <= _rtP -> P_1006 ) ; usat = ( _rtX -> kvv12h1lmd >= _rtP ->
P_1005 ) ; if ( ( ( ! lsat ) && ( ! usat ) ) || ( lsat && ( _rtB ->
hbc3rgueox > 0.0 ) ) || ( usat && ( _rtB -> hbc3rgueox < 0.0 ) ) ) { _rtXdot
-> kvv12h1lmd = _rtB -> hbc3rgueox ; } else { _rtXdot -> kvv12h1lmd = 0.0 ; }
lsat = ( _rtX -> ii2qiixi5h <= _rtP -> P_1008 ) ; usat = ( _rtX -> ii2qiixi5h
>= _rtP -> P_1007 ) ; if ( ( ( ! lsat ) && ( ! usat ) ) || ( lsat && ( _rtB
-> jtvjwugnc1 > 0.0 ) ) || ( usat && ( _rtB -> jtvjwugnc1 < 0.0 ) ) ) {
_rtXdot -> ii2qiixi5h = _rtB -> jtvjwugnc1 ; } else { _rtXdot -> ii2qiixi5h =
0.0 ; } _rtXdot -> orid2cznzr [ 0 ] = 0.0 ; _rtXdot -> orid2cznzr [ 0 ] +=
_rtP -> P_1020 [ 0 ] * _rtX -> orid2cznzr [ 0 ] ; _rtXdot -> orid2cznzr [ 1 ]
= 0.0 ; _rtXdot -> orid2cznzr [ 0 ] += _rtP -> P_1020 [ 1 ] * _rtX ->
orid2cznzr [ 1 ] ; _rtXdot -> orid2cznzr [ 1 ] += _rtX -> orid2cznzr [ 0 ] ;
_rtXdot -> knizeu3cnz = _rtB -> pvkyynno3r ; _rtXdot -> n05o0sy3du [ 0 ] =
_rtB -> jl01pawnov [ 0 ] ; _rtXdot -> n05o0sy3du [ 1 ] = _rtB -> jl01pawnov [
1 ] ; _rtXdot -> n05o0sy3du [ 2 ] = _rtB -> jl01pawnov [ 2 ] ; _rtXdot ->
jlmvybcsjd = 0.0 ; _rtXdot -> jlmvybcsjd += _rtP -> P_1039 * _rtX ->
jlmvybcsjd ; _rtXdot -> jlmvybcsjd += _rtB -> pgkpwhbsc4 ; } else { { real_T
* dx ; int_T i ; dx = & ( ( ( g3u2dpkjkc * ) ssGetdX ( S ) ) -> g2szyo42jj )
; for ( i = 0 ; i < 39 ; i ++ ) { dx [ i ] = 0.0 ; } } } } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 1779671968U
) ; ssSetChecksumVal ( S , 1 , 2896930358U ) ; ssSetChecksumVal ( S , 2 ,
2109515472U ) ; ssSetChecksumVal ( S , 3 , 576329692U ) ; { mxArray *
slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString ( "simulink" ) ;
char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat , 1
, & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat = mxGetField
( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == NULL ) { status = 1 ; }
else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; } }
mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "8.7" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != sizeof ( f5cp4dpc1i ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( plshtxiahf ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofU ( S ) != sizeof
( frf5yblmjv ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal ExternalInputs sizes do "
"not match for accelerator mex file." ) ; ssSetErrorStatus ( S , msg ) ; } if
( ssGetSizeofY ( S ) != sizeof ( gwbzu4fejp ) ) { static char msg [ 256 ] ;
sprintf ( msg , "Unexpected error: Internal ExternalOutputs sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
cvqdcwnzy0 ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & gn4phjciai ) ; _ssSetConstBlockIO ( S , & n1hzb5bzwi ) ; rt_InitInfAndNaN
( sizeof ( real_T ) ) ; ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) -> P_71 =
rtInf ; ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) -> P_978 = rtInf ; ( (
cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) -> P_990 = rtInf ; ( ( cvqdcwnzy0 * )
ssGetModelRtp ( S ) ) -> P_1001 = rtInf ; ( ( cvqdcwnzy0 * ) ssGetModelRtp (
S ) ) -> dak2bbvhdyl . P_10 = rtInf ; ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S )
) -> b1bttejwsj2 . P_11 = rtInf ; ( ( cvqdcwnzy0 * ) ssGetModelRtp ( S ) ) ->
lvrrs02dbel . P_10 = rtInf ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { { SimStruct * childS ; SysOutputFcn * callSysFcns ; childS
= ssGetSFunction ( S , 0 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 1 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 2 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 3 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 4 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 5 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 6 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 174 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 175 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 176 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 177 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 178 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 179 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 180 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 181 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 182 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 183 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 184 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 185 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 186 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 187 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 188 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 189 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 190 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 191 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 192 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 193 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 194 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 195 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 196 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 197 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 198 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 199 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 200 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 201 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; childS =
ssGetSFunction ( S , 202 ) ; callSysFcns = ssGetCallSystemOutputFcnList (
childS ) ; callSysFcns [ 3 + 0 ] = ( SysOutputFcn ) ( NULL ) ; }
slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ; } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
