/*
 * Code generation for system system '<S22>/CodeReuseSubsystem'
 * For more details, see corresponding source file AFCS_MODEL1_CodeReuseSubsystem.c
 *
 */

#ifndef RTW_HEADER_AFCS_MODEL1_CodeReuseSubsystem_h_
#define RTW_HEADER_AFCS_MODEL1_CodeReuseSubsystem_h_
#include <stddef.h>
#include <math.h>
#ifndef AFCS_MODEL1_sf_COMMON_INCLUDES_
# define AFCS_MODEL1_sf_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_LEVEL               2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#if !defined(MATLAB_MEX_FILE)
#include "rt_matrx.h"
#endif

#if !defined(RTW_SFUNCTION_DEFINES)
#define RTW_SFUNCTION_DEFINES

typedef struct {
  void *blockIO;
  void *defaultParam;
  void *nonContDerivSig;
} LocalS;

#define ssSetLocalBlockIO(S, io)       ((LocalS *)ssGetUserData(S))->blockIO = ((void *)(io))
#define ssGetLocalBlockIO(S)           ((LocalS *)ssGetUserData(S))->blockIO
#define ssSetLocalDefaultParam(S, paramVector) ((LocalS *)ssGetUserData(S))->defaultParam = (paramVector)
#define ssGetLocalDefaultParam(S)      ((LocalS *)ssGetUserData(S))->defaultParam
#define ssSetLocalNonContDerivSig(S, pSig) ((LocalS *)ssGetUserData(S))->nonContDerivSig = (pSig)
#define ssGetLocalNonContDerivSig(S)   ((LocalS *)ssGetUserData(S))->nonContDerivSig
#endif
#endif                                 /* AFCS_MODEL1_sf_COMMON_INCLUDES_ */

#include "AFCS_MODEL1_sf_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

void AFCS_MODEL1_CodeReuseSubsystem_Init(SimStruct * const S);
void AFCS_MODEL1_CodeReuseSubsystem_Reset(SimStruct * const S);
void AFCS_MODEL1_CodeReuseSubsystem_Start(SimStruct * const S);
void AFCS_MODEL1_CodeReuseSubsystem_Update(SimStruct * const S);
void AFCS_MODEL1_CodeReuseSubsystem(SimStruct * const S);
void AFCS_MODEL1_CodeReuseSubsystem_Term(SimStruct * const S);

#endif                                 /* RTW_HEADER_AFCS_MODEL1_CodeReuseSubsystem_h_ */
