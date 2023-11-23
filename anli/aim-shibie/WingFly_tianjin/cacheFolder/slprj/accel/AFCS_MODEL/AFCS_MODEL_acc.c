#include "__cf_AFCS_MODEL.h"
#include <math.h>
#include "AFCS_MODEL_acc.h"
#include "AFCS_MODEL_acc_private.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#undef S_FUNCTION_NAME
#if !defined(RTW_GENERATED_SFCN_TUNABLE_PRMS_AFCS_MODEL1_sf)
#define RTW_GENERATED_SFCN_TUNABLE_PRMS_AFCS_MODEL1_sf
#endif
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME simulink_only_sfcn
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T currentTime ;
kktc5xrd4p * _rtB ; e32vbio03z * _rtP ; krl4qqmdcd * _rtDW ; _rtDW = ( (
krl4qqmdcd * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( e32vbio03z * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( kktc5xrd4p * ) _ssGetModelBlockIO ( S ) )
; currentTime = ssGetTaskTime ( S , 0 ) ; if ( currentTime < _rtP -> P_0 ) {
_rtB -> llvoqfk5gp = _rtP -> P_1 ; } else { _rtB -> llvoqfk5gp = _rtP -> P_2
; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 2 ,
SS_CALL_MDL_OUTPUTS ) ; } currentTime = muDoubleScalarFloor ( _rtB ->
llvoqfk5gp ) ; if ( muDoubleScalarIsNaN ( currentTime ) ||
muDoubleScalarIsInf ( currentTime ) ) { currentTime = 0.0 ; } else {
currentTime = muDoubleScalarRem ( currentTime , 256.0 ) ; } _rtB ->
ah2nzkvh34 = ( int8_T ) ( currentTime < 0.0 ? ( int32_T ) ( int8_T ) - (
int8_T ) ( uint8_T ) - currentTime : ( int32_T ) ( int8_T ) ( uint8_T )
currentTime ) ; currentTime = ssGetTaskTime ( S , 0 ) ; if ( currentTime <
_rtP -> P_3 ) { currentTime = muDoubleScalarFloor ( _rtP -> P_4 ) ; if (
muDoubleScalarIsNaN ( currentTime ) || muDoubleScalarIsInf ( currentTime ) )
{ currentTime = 0.0 ; } else { currentTime = muDoubleScalarRem ( currentTime
, 256.0 ) ; } _rtB -> npqbz3fkfl = ( int8_T ) ( currentTime < 0.0 ? ( int32_T
) ( int8_T ) - ( int8_T ) ( uint8_T ) - currentTime : ( int32_T ) ( int8_T )
( uint8_T ) currentTime ) ; } else { currentTime = muDoubleScalarFloor ( _rtP
-> P_5 ) ; if ( muDoubleScalarIsNaN ( currentTime ) || muDoubleScalarIsInf (
currentTime ) ) { currentTime = 0.0 ; } else { currentTime =
muDoubleScalarRem ( currentTime , 256.0 ) ; } _rtB -> npqbz3fkfl = ( int8_T )
( currentTime < 0.0 ? ( int32_T ) ( int8_T ) - ( int8_T ) ( uint8_T ) -
currentTime : ( int32_T ) ( int8_T ) ( uint8_T ) currentTime ) ; }
ssCallAccelRunBlock ( S , 1 , 19 , SS_CALL_MDL_OUTPUTS ) ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { ssCallAccelRunBlock ( S , 1 , 20 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 21 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 22 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 23 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 24 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 25 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 26 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 27 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 28 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 29 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 30 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 31 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 32 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 33 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 34 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 35 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 36 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 37 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 38 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 39 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 40 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 41 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 42 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 43 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 44 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 45 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 46 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 47 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 48 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 49 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 50 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 51 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 52 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> eklljozh1z
[ 0 ] = _rtB -> gytpmq4u34 ; _rtB -> eklljozh1z [ 1 ] = _rtB -> oabkhhradg ;
} UNUSED_PARAMETER ( tid ) ; } static void mdlOutputsTID2 ( SimStruct * S ,
int_T tid ) { kktc5xrd4p * _rtB ; e32vbio03z * _rtP ; _rtP = ( ( e32vbio03z *
) ssGetModelRtp ( S ) ) ; _rtB = ( ( kktc5xrd4p * ) _ssGetModelBlockIO ( S )
) ; _rtB -> b2zokxi0lx = ( real32_T ) _rtP -> P_6 ; _rtB -> pu3rwkep5z = (
real32_T ) _rtP -> P_7 ; _rtB -> kwbfcwo4w5 = ( real32_T ) _rtP -> P_8 ; _rtB
-> okzz1il5ky = _rtP -> P_9 ; _rtB -> kvul55kpjx = _rtP -> P_10 ; _rtB ->
fkk4jjftez = _rtP -> P_11 ; memcpy ( & _rtB -> ev5b1q0bl5 [ 0 ] , & _rtP ->
P_12 [ 0 ] , 90U * sizeof ( real_T ) ) ; _rtB -> ni1skwxgto = _rtP -> P_13 ;
_rtB -> l11qa3fkuc = _rtP -> P_14 ; _rtB -> dpod1fyvcr = _rtP -> P_15 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { kktc5xrd4p * _rtB ;
krl4qqmdcd * _rtDW ; _rtDW = ( ( krl4qqmdcd * ) ssGetRootDWork ( S ) ) ; _rtB
= ( ( kktc5xrd4p * ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 1
, 19 , SS_CALL_MDL_UPDATE ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_UPDATE ) ; } UNUSED_PARAMETER (
tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { kktc5xrd4p * _rtB ; krl4qqmdcd
* _rtDW ; _rtDW = ( ( krl4qqmdcd * ) ssGetRootDWork ( S ) ) ; _rtB = ( (
kktc5xrd4p * ) _ssGetModelBlockIO ( S ) ) ; ssCallAccelRunBlock ( S , 1 , 19
, SS_CALL_MDL_DERIVATIVES ) ; } static void mdlInitializeSizes ( SimStruct *
S ) { ssSetChecksumVal ( S , 0 , 297637803U ) ; ssSetChecksumVal ( S , 1 ,
1766649349U ) ; ssSetChecksumVal ( S , 2 , 1898392539U ) ; ssSetChecksumVal (
S , 3 , 465158027U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat
= mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.7" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
krl4qqmdcd ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( kktc5xrd4p ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
e32vbio03z ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & opmaxpa1xq ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { slAccRegPrmChangeFcn ( S ,
mdlOutputsTID2 ) ; } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
