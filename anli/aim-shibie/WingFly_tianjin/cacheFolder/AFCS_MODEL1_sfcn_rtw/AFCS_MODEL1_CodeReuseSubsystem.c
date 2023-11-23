/*
 * Code generation for system system '<S22>/CodeReuseSubsystem'
 *
 * Model                      : AFCS_MODEL1_sf
 * Model version              : 1.995
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Wed Aug 11 17:17:39 2021
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "AFCS_MODEL1_CodeReuseSubsystem.h"

/* Include model header file for global data */
#include "AFCS_MODEL1_sf.h"
#include "AFCS_MODEL1_sf_private.h"

/* System initialize for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem_Init(SimStruct * const S)
{
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 373))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 146))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 3);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 6);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 7);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 10);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 13);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 14);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S115>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 388))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S115>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 161))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 19);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 22);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 24);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 26);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 30);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 32);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 34);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 38);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 39);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 41);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 45);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 46);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 48);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 415))[0] = 1;

  /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 49);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 416))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 188))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 50);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 191))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 56);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 57);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 58);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 63);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 68);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 69);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 70);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 75);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 80);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 81);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 82);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 86);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 93);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 94);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 445))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 218))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 97);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 98);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 102);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 103);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 110);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 111);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 458))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 231))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 112);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 113);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 119);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 120);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 122);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 123);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 126);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 128);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 129);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 133);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 135);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 136);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 137);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 138);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 142);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 144);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 491))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 261))[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S247>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 262))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 155);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 157);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 159);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 160);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 163);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* System reset for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem_Reset(SimStruct * const S)
{
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 373))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S175>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 146))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 3);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 6);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 7);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 10);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 13);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 14);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S115>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 388))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S115>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 161))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 19);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 22);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 24);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 26);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 30);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 32);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 34);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 38);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 39);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 41);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 45);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 46);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 48);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S56>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 415))[0] = 1;

  /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 49);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 416))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 188))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 50);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 191))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 56);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 57);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 58);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 63);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 68);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 69);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 70);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 75);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 80);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 81);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 82);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 86);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 93);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 94);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 445))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 218))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 97);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 98);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 102);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 103);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 110);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 111);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 458))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S73>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 231))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 112);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 113);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 119);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 120);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 122);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 123);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 126);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 128);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 129);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 133);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 135);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 136);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 137);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 138);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 142);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 144);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay' */
  ((int8_T *)ssGetDWork(S, 491))[0] = 0;

  /* InitializeConditions for UnitDelay: '<S273>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 261))[0] = 0.0F;

  /* InitializeConditions for UnitDelay: '<S247>/Unit Delay1' */
  ((real32_T *)ssGetDWork(S, 262))[0] = 0.0F;

  /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 155);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 157);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 159);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 160);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 163);
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Start for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem_Start(SimStruct * const S)
{
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));

  /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S186>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 1);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S188>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 2);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 3);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S187>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 4);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S189>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 5);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 6);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 7);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S179>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 8);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S181>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 9);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 10);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S180>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 11);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S182>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 12);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 13);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 14);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S92>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 15);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S96>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 16);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S93>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 17);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S97>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 18);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 19);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S91>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 20);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S95>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 21);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 22);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S94>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 23);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 24);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S114>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 25);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 26);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S86>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 27);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S119>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 28);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S121>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 29);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 30);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S120>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 31);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 32);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S122>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 33);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 34);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S102>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 35);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S104>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 36);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S105>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 37);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 38);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 39);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S103>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 40);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 41);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S109>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 42);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S111>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 43);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S112>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 44);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 45);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 46);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S110>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 47);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 48);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 49);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 50);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S125>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 51);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S134>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 52);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S135>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 53);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S136>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 54);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S137>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 55);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 56);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 57);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 58);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S155>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 59);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 60);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S154>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 61);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S158>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 62);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 63);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 64);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S153>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 65);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S156>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 66);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S157>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 67);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 68);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 69);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 70);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S145>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 71);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 72);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S144>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 73);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S148>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 74);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 75);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S143>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 76);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 77);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S146>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 78);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S147>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 79);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 80);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 81);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 82);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S164>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 83);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S168>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 84);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S169>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 85);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 86);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 87);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S162>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 88);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S167>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 89);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S161>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 90);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 91);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S166>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 92);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 93);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 94);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S163>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 95);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S165>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 96);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 97);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 98);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S193>/Generated S-Function' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 99);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S198>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 100);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S199>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 101);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 102);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 103);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S204>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 104);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S203>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 105);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S206>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 106);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S194>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 107);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S202>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 108);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S205>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 109);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 110);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 111);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 112);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 113);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S77>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 114);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S79>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 115);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S72>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 116);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S76>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 117);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S78>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 118);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 119);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 120);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S209>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 121);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 122);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 123);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S245>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 124);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S246>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 125);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 126);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S242>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 127);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 128);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 129);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S244>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 130);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S243>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 131);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S225>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 132);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 133);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S226>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 134);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 135);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 136);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 137);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 138);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S259>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 139);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S260>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 140);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S255>/Generated S-Function9' (NegativePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 141);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 142);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S268>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 143);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 144);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S269>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 145);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S267>/Generated S-Function' (NegativePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 146);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S270>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 147);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S272>/Generated S-Function' (PositivePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 148);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S271>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 149);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S261>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 150);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S262>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 151);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S258>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 152);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S263>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 153);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S264>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 154);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 155);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S250>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 156);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 157);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S275>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 158);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 159);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 160);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S218>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 161);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S217>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 162);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 163);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S279>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 164);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S280>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 165);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* RTW Generated Level2 S-Function Block: '<S281>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 166);
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Outputs for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem(SimStruct * const S)
{
  int8_T rtb_Switch;
  real32_T tmp;
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S175>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 373))[0];

    /* RelationalOperator: '<S175>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S175>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 146))[0];

    /* Switch: '<S175>/Switch' */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_k = _rtB->TmpSignalConversionAtCodeReus_b[5];
    } else {
      _rtB->Switch_k = _rtB->Add8;
    }

    /* End of Switch: '<S175>/Switch' */
  }

  if (1) {
    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S56>/Constant1'
     */
    if (_rtB->SWAUTO > 0) {
      rtb_Switch = _rtB->apthL;
    } else {
      rtb_Switch = 1;
    }

    /* End of Switch: '<S56>/Switch' */

    /* DataTypeConversion: '<S66>/Data Type Conversion3' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S66>/Relational Operator'
     */
    _rtB->DataTypeConversion3_h = (int8_T)(rtb_Switch == 1);

    /* Switch: '<S56>/Switch4' */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch4 = _rtB->thrustcmd;
    } else {
      _rtB->Switch4 = _rtB->Switch_lo[3];
    }

    /* End of Switch: '<S56>/Switch4' */

    /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 0);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S66>/Relational Operator1' incorporates:
     *  Constant: '<S66>/Constant1'
     */
    _rtB->LogicalOperator1_m = (rtb_Switch == 2);

    /* DataTypeConversion: '<S66>/Data Type Conversion1' */
    _rtB->DataTypeConversion1_j = (int8_T)_rtB->LogicalOperator1_m;

    /* Sum: '<S173>/Sum' */
    _rtB->Sum_hq = _rtB->vtcmd - _rtB->vt;

    /* RTW Generated Level2 S-Function Block: '<S186>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 1);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S188>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 2);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 3);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S173>/Add2' incorporates:
     *  Constant: '<S173>/Constant3'
     */
    _rtB->Add2 = (_rtB->Switch_k - 0.5F) - _rtB->GeneratedSFunction_n;

    /* RTW Generated Level2 S-Function Block: '<S187>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 4);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S173>/Add' incorporates:
     *  Constant: '<S173>/Constant3'
     */
    _rtB->Add_g1 = 0.5F + _rtB->Product1_g;

    /* Sum: '<S173>/Add1' incorporates:
     *  Constant: '<S173>/Constant3'
     */
    _rtB->Add1 = -0.5F - _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S189>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 5);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 6);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S173>/Sum1' incorporates:
     *  Constant: '<S173>/Constant'
     */
    _rtB->Sum1_b = (0.5F + _rtB->GeneratedSFunction_n) + _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 7);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S66>/Relational Operator2' incorporates:
     *  Constant: '<S66>/Constant2'
     */
    _rtB->LogicalOperator1_m = (rtb_Switch == 3);

    /* DataTypeConversion: '<S66>/Data Type Conversion2' */
    _rtB->DataTypeConversion2_lt = (int8_T)_rtB->LogicalOperator1_m;

    /* Sum: '<S172>/Sum' */
    _rtB->Sum_mj = _rtB->vtcmd - _rtB->Vc_p;

    /* RTW Generated Level2 S-Function Block: '<S179>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 8);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S181>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 9);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 10);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S172>/Add2' incorporates:
     *  Constant: '<S172>/Constant3'
     */
    _rtB->Add2_d = (_rtB->Switch_k - _rtB->GeneratedSFunction_e) - 0.5F;

    /* RTW Generated Level2 S-Function Block: '<S180>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 11);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S172>/Add' incorporates:
     *  Constant: '<S172>/Constant3'
     */
    _rtB->Add_l = 0.5F + _rtB->Product1_g;

    /* Sum: '<S172>/Add1' incorporates:
     *  Constant: '<S172>/Constant3'
     */
    _rtB->Add1_g = -0.5F - _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S182>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 12);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 13);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S172>/Sum1' incorporates:
     *  Constant: '<S172>/Constant1'
     */
    _rtB->Sum1_a = (0.5F + _rtB->GeneratedSFunction_e) + _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 14);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MultiPortSwitch: '<S66>/Multiport Switch2' */
    switch (rtb_Switch) {
     case 1:
      _rtB->apthrust = _rtB->GeneratedSFunction;
      break;

     case 2:
      _rtB->apthrust = _rtB->GeneratedSFunction_k;
      break;

     default:
      _rtB->apthrust = _rtB->GeneratedSFunction_m;
      break;
    }

    /* End of MultiPortSwitch: '<S66>/Multiport Switch2' */

    /* Switch: '<S56>/Switch1' incorporates:
     *  Constant: '<S56>/Constant2'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch1_p = _rtB->aplonL;
    } else {
      _rtB->Switch1_p = 2;
    }

    /* End of Switch: '<S56>/Switch1' */

    /* RelationalOperator: '<S63>/Relational Operator3' incorporates:
     *  Constant: '<S63>/Constant3'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch1_p == 4);

    /* DataTypeConversion: '<S63>/Data Type Conversion3' */
    _rtB->DataTypeConversion3_c = (int8_T)_rtB->LogicalOperator1_m;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S115>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 388))[0];

    /* RelationalOperator: '<S115>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S115>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 161))[0];

    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S56>/Constant6'
     */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_aj = 0.0F;
    } else {
      _rtB->Switch_aj = _rtB->Add8;
    }

    /* End of Switch: '<S115>/Switch' */
  }

  if (1) {
    /* Sum: '<S80>/Sum6' */
    _rtB->Sum6 = _rtB->hcmd - _rtB->mh_j;

    /* RTW Generated Level2 S-Function Block: '<S92>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 15);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S96>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 16);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Saturate: '<S56>/Saturation' */
    if (_rtB->phiL_n > 60.0F) {
      _rtB->Product1_g = 60.0F;
    } else if (_rtB->phiL_n < -60.0F) {
      _rtB->Product1_g = -60.0F;
    } else {
      _rtB->Product1_g = _rtB->phiL_n;
    }

    /* End of Saturate: '<S56>/Saturation' */

    /* Gain: '<S56>/Gain' */
    _rtB->Product1_g *= 0.0174520072F;

    /* Trigonometry: '<S56>/Trigonometric Function' */
    _rtB->Product1_g = (real32_T)cos(_rtB->Product1_g);

    /* Abs: '<S56>/Abs' */
    _rtB->Product1_g = (real32_T)fabs(_rtB->Product1_g);

    /* Product: '<S80>/Divide2' incorporates:
     *  Constant: '<S68>/Constant13'
     */
    _rtB->Divide2 = _rtB->Switch_aj * _rtB->Product1_g / 2.8F;

    /* RTW Generated Level2 S-Function Block: '<S93>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 17);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S80>/Sum7' */
    _rtB->Switch6_d += _rtB->mhdot;

    /* Sum: '<S80>/Sum8' */
    _rtB->Sum8 = _rtB->Switch6_d - _rtB->GeneratedSFunction_o;

    /* RTW Generated Level2 S-Function Block: '<S97>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 18);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 19);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S80>/Sum5' */
    _rtB->Switch6_d += _rtB->GeneratedSFunction_o;

    /* Saturate: '<S80>/Saturation' */
    if (_rtB->Switch6_d > 5.0F) {
      _rtB->Switch6_d = 5.0F;
    } else {
      if (_rtB->Switch6_d < -5.0F) {
        _rtB->Switch6_d = -5.0F;
      }
    }

    /* End of Saturate: '<S80>/Saturation' */

    /* Gain: '<S56>/Gain1' */
    _rtB->Gain1_mb = 10.0F * _rtB->GeneratedSFunction15;

    /* Switch: '<S56>/Switch8' */
    if (_rtB->SWAUTO > 0) {
      _rtB->MinMax = _rtB->gamacmd;
    } else {
      _rtB->MinMax = _rtB->Gain1_mb;
    }

    /* End of Switch: '<S56>/Switch8' */

    /* Gain: '<S88>/Unit Conversion' */
    _rtB->Saturation8 = 0.0174532924F * _rtB->MinMax;

    /* Trigonometry: '<S80>/Trigonometric Function' */
    _rtB->Saturation8 = (real32_T)sin(_rtB->Saturation8);

    /* Product: '<S80>/Product' */
    _rtB->Saturation8 *= _rtB->vt;

    /* Sum: '<S80>/Sum1' */
    _rtB->Sum1_j = (_rtB->Switch6_d - _rtB->mhdot) + _rtB->Saturation8;

    /* RTW Generated Level2 S-Function Block: '<S91>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 20);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S95>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 21);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Product: '<S80>/Divide' */
    _rtB->Divide = _rtB->Saturation8 / _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 22);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Lookup_n-D: '<S68>/1-D Lookup Table' */
    _rtB->Saturation8 = AFCS_MODEL1_look1_iflf_binlcpw(_rtB->Alfa_j,
      AFCS_MODEL1_ConstP.pooled118, AFCS_MODEL1_ConstP.uDLookupTable_tableData,
      6U);

    /* Product: '<S68>/Product1' incorporates:
     *  Constant: '<S68>/Constant49'
     */
    _rtB->Product1_m = _rtB->Saturation8 * 10.0F;

    /* Lookup_n-D: '<S68>/1-D Lookup Table1' */
    _rtB->Saturation8 = AFCS_MODEL1_look1_iflf_binlcpw(_rtB->Alfa_j,
      AFCS_MODEL1_ConstP.pooled118, AFCS_MODEL1_ConstP.uDLookupTable1_tableData,
      6U);

    /* Product: '<S68>/Product' incorporates:
     *  Constant: '<S68>/Constant50'
     */
    _rtB->Product_pp = _rtB->Saturation8 * -10.0F;

    /* RTW Generated Level2 S-Function Block: '<S94>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 23);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 24);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S63>/Relational Operator4' incorporates:
     *  Constant: '<S63>/Constant4'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch1_p == 1);

    /* DataTypeConversion: '<S63>/Data Type Conversion' */
    _rtB->DataTypeConversion_gv = (int8_T)_rtB->LogicalOperator1_m;

    /* RTW Generated Level2 S-Function Block: '<S114>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 25);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 26);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S63>/Relational Operator1' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch1_p == 2);

    /* DataTypeConversion: '<S63>/Data Type Conversion1' */
    _rtB->DataTypeConversion1_p = (int8_T)_rtB->LogicalOperator1_m;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Switch: '<S56>/Switch13' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S56>/Constant14'
     */
    if (_rtB->fmphase > 1) {
      _rtB->Switch13 = 3.0F;
    } else {
      _rtB->Switch13 = 0.0F;
    }

    /* End of Switch: '<S56>/Switch13' */
  }

  if (1) {
    /* Switch: '<S56>/Switch5' incorporates:
     *  Sum: '<S56>/Sum'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Saturation8 = _rtB->thetaLcmd;
    } else {
      _rtB->Saturation8 = _rtB->Gain1_mb + _rtB->Switch13;
    }

    /* End of Switch: '<S56>/Switch5' */

    /* Sum: '<S86>/Sum1' */
    _rtB->Sum1_f = _rtB->Saturation8 - _rtB->thetaL_k;

    /* RTW Generated Level2 S-Function Block: '<S86>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 27);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S119>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 28);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S121>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 29);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 30);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S120>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 31);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Inport: '<S55>/dtCAS' */
    _rtB->dtCAS = _rtB->Saturation1_g;
  }

  if (1) {
    /* Sum: '<S247>/Sum1' incorporates:
     *  Constant: '<S247>/Constant'
     */
    _rtB->Sum1_e = _rtB->Nz - 1.0F;

    /* Sum: '<S86>/Sum2' incorporates:
     *  Constant: '<S86>/Constant'
     */
    _rtB->Sum2_eb = _rtB->Nz - 1.0F;

    /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 32);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S122>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 33);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S86>/Sum3' */
    _rtB->Sum3_l = _rtB->Saturation8 - _rtB->Switch6_d;

    /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 34);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S63>/Relational Operator2' incorporates:
     *  Constant: '<S63>/Constant2'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch1_p == 3);

    /* DataTypeConversion: '<S63>/Data Type Conversion2' */
    _rtB->DataTypeConversion2_c = (int8_T)_rtB->LogicalOperator1_m;

    /* Gain: '<S99>/Unit Conversion' */
    _rtB->MinMax *= 0.0174532924F;

    /* Trigonometry: '<S82>/Trigonometric Function' */
    _rtB->MinMax = (real32_T)sin(_rtB->MinMax);

    /* Product: '<S82>/Product' */
    _rtB->MinMax *= _rtB->vt;

    /* Sum: '<S82>/Sum1' */
    _rtB->Sum1_l = _rtB->MinMax - _rtB->mhdot;

    /* RTW Generated Level2 S-Function Block: '<S102>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 35);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S104>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 36);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S105>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 37);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 38);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S82>/Sum3' */
    _rtB->Saturation8 += _rtB->GeneratedSFunction_b1;

    /* Product: '<S82>/Divide' */
    _rtB->Divide_e = _rtB->Saturation8 / _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 39);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S103>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 40);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 41);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S63>/Relational Operator5' incorporates:
     *  Constant: '<S63>/Constant5'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch1_p == 5);

    /* DataTypeConversion: '<S63>/Data Type Conversion4' */
    _rtB->DataTypeConversion4_k = (int8_T)_rtB->LogicalOperator1_m;

    /* Sum: '<S83>/Sum1' */
    _rtB->Sum1_i = _rtB->CMD_Hdotc - _rtB->mhdot;

    /* RTW Generated Level2 S-Function Block: '<S109>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 42);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S111>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 43);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S112>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 44);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 45);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S83>/Sum3' */
    _rtB->Saturation8 += _rtB->GeneratedSFunction_nx;

    /* Product: '<S83>/Divide' */
    _rtB->Divide_ez = _rtB->Saturation8 / _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 46);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S110>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 47);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 48);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MultiPortSwitch: '<S63>/Multiport Switch2' */
    switch (_rtB->Switch1_p) {
     case 1:
      _rtB->MultiportSwitch2 = _rtB->GeneratedSFunction_p;
      break;

     case 2:
      _rtB->MultiportSwitch2 = _rtB->GeneratedSFunction4_f;
      break;

     case 3:
      _rtB->MultiportSwitch2 = _rtB->GeneratedSFunction4_c;
      break;

     case 4:
      _rtB->MultiportSwitch2 = _rtB->GeneratedSFunction4;
      break;

     default:
      _rtB->MultiportSwitch2 = _rtB->GeneratedSFunction4_n;
      break;
    }

    /* End of MultiPortSwitch: '<S63>/Multiport Switch2' */
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S56>/Unit Delay' */
    _rtB->UnitDelay_m = ((int8_T *)ssGetDWork(S, 415))[0];
  }

  if (1) {
    /* RelationalOperator: '<S56>/Relational Operator' */
    _rtB->LogicalOperator1_m = (_rtB->SWAUTO == _rtB->UnitDelay_m);

    /* Switch: '<S56>/Switch9' */
    _rtB->Switch9 = (int8_T)!_rtB->LogicalOperator1_m;

    /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 49);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Switch: '<S56>/Switch2' incorporates:
     *  Constant: '<S56>/Constant3'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch2_a = _rtB->aplatL;
    } else {
      _rtB->Switch2_a = 2;
    }

    /* End of Switch: '<S56>/Switch2' */

    /* RelationalOperator: '<S64>/Relational Operator5' incorporates:
     *  Constant: '<S64>/Constant5'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch2_a == 1);

    /* DataTypeConversion: '<S64>/Data Type Conversion5' */
    _rtB->DataTypeConversion5_n = (int8_T)_rtB->LogicalOperator1_m;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S138>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 416))[0];

    /* RelationalOperator: '<S138>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S138>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 188))[0];

    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S56>/Constant6'
     */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_bg = 0.0F;
    } else {
      _rtB->Switch_bg = _rtB->Add8;
    }

    /* End of Switch: '<S138>/Switch' */
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 50);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S64>/Relational Operator1' incorporates:
     *  Constant: '<S64>/Constant1'
     */
    _rtB->LogicalOperator1_m = (_rtB->Switch2_a == 2);

    /* DataTypeConversion: '<S64>/Data Type Conversion3' */
    _rtB->DataTypeConversion3_d = (int8_T)_rtB->LogicalOperator1_m;

    /* Switch: '<S56>/Switch6' incorporates:
     *  Gain: '<S56>/Gain3'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Saturation8 = _rtB->phiLcmd;
    } else {
      _rtB->Saturation8 = 30.0F * _rtB->GeneratedSFunction15_i;
    }

    /* End of Switch: '<S56>/Switch6' */

    /* Sum: '<S125>/Sum1' */
    _rtB->Sum1_lf = _rtB->Saturation8 - _rtB->phiL_n;

    /* RTW Generated Level2 S-Function Block: '<S125>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 51);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S134>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 52);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S135>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 53);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S125>/Sum2' */
    _rtB->Sum2_c = _rtB->Switch_bg - _rtB->GeneratedSFunction_hw;

    /* RTW Generated Level2 S-Function Block: '<S136>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 54);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S59>/Relational Operator2' incorporates:
     *  Constant: '<S59>/Constant2'
     */
    _rtB->LogicalOperator1_m = (_rtB->LockFlag == 1);

    /* RelationalOperator: '<S59>/Relational Operator1' incorporates:
     *  Constant: '<S59>/Constant1'
     */
    _rtB->RelationalOperator1_c = (_rtB->Swcheck == 1);
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* RelationalOperator: '<S59>/Relational Operator7' incorporates:
     *  Constant: '<S59>/Constant9'
     */
    _rtB->RelationalOperator7 = (_rtB->Switch6_j == 1);
  }

  if (1) {
    /* Logic: '<S59>/Logical Operator1' */
    _rtB->LogicalOperator1_m = (_rtB->LogicalOperator1_m ||
      _rtB->RelationalOperator1_c || _rtB->RelationalOperator7);

    /* Switch: '<S59>/Switch6' */
    _rtB->Switch6_d = (real32_T)!_rtB->LogicalOperator1_m;

    /* Product: '<S125>/Product' */
    _rtB->MinMax *= _rtB->Switch6_d;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S125>/Unit Delay1' */
    _rtB->UnitDelay1_k = ((real32_T *)ssGetDWork(S, 191))[0];

    /* RTW Generated Level2 S-Function Block: '<S137>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 55);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* Switch: '<S59>/Switch1' */
    _rtB->Product1_g = _rtB->LogicalOperator1_m;

    /* Product: '<S125>/Product1' */
    _rtB->Saturation2_p = _rtB->GeneratedSFunction_a * _rtB->Product1_g;

    /* Sum: '<S125>/Sum11' */
    _rtB->Sum11 = _rtB->MinMax - _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 56);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S125>/Sum' */
    _rtB->Sum_c = _rtB->GeneratedSFunction_hw + _rtB->GeneratedSFunction3;

    /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 57);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 58);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S64>/Relational Operator2' incorporates:
     *  Constant: '<S64>/Constant2'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch2_a == 3);

    /* DataTypeConversion: '<S64>/Data Type Conversion1' */
    _rtB->DataTypeConversion1_h = (int8_T)_rtB->RelationalOperator1_c;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Product: '<S128>/Divide' incorporates:
     *  Constant: '<S68>/Constant15'
     */
    _rtB->Divide_c = _rtB->Switch_bg / 3.0F;

    /* RTW Generated Level2 S-Function Block: '<S155>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 59);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* Sum: '<S128>/Sum4' */
    _rtB->Sum4_d = (_rtB->phiL_n + _rtB->GeneratedSFunction1_o) -
      _rtB->Saturation8;

    /* Sum: '<S128>/Sum3' */
    _rtB->Sum3_g = _rtB->psiLcmd - _rtB->psiL_d;

    /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 60);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S154>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 61);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S158>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 62);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 63);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S128>/Sum1' */
    _rtB->Sum1_g = (_rtB->Saturation2_p - _rtB->phiL_n) + _rtB->Saturation8;

    /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 64);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S153>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 65);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S156>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 66);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S157>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 67);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 68);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S128>/Sum' */
    _rtB->Sum_d = _rtB->GeneratedSFunction_ex + _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 69);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 70);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S64>/Relational Operator3' incorporates:
     *  Constant: '<S64>/Constant3'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch2_a == 4);

    /* DataTypeConversion: '<S64>/Data Type Conversion2' */
    _rtB->DataTypeConversion2_p = (int8_T)_rtB->RelationalOperator1_c;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Product: '<S127>/Divide' incorporates:
     *  Constant: '<S68>/Constant15'
     */
    _rtB->Divide_l = _rtB->Switch_bg / 3.0F;

    /* RTW Generated Level2 S-Function Block: '<S145>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 71);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* Sum: '<S127>/Sum4' */
    _rtB->Sum4_i = (_rtB->phiL_n + _rtB->GeneratedSFunction1_p) -
      _rtB->Saturation8;

    /* Sum: '<S127>/Sum3' */
    _rtB->Sum3_c = _rtB->psdcmd - _rtB->psd;

    /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 72);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S144>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 73);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S148>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 74);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 75);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S143>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 76);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S127>/Sum1' */
    _rtB->Sum1_ga = (_rtB->Saturation2_p - _rtB->phiL_n) + _rtB->Saturation8;

    /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 77);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S146>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 78);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S147>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 79);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 80);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S127>/Sum' */
    _rtB->Sum_mz = _rtB->GeneratedSFunction_ma + _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 81);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 82);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S64>/Relational Operator4' incorporates:
     *  Constant: '<S64>/Constant4'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch2_a == 5);

    /* DataTypeConversion: '<S64>/Data Type Conversion4' */
    _rtB->DataTypeConversion4_g = (int8_T)_rtB->RelationalOperator1_c;

    /* Sum: '<S129>/Sum2' */
    _rtB->Sum2_hh = _rtB->yrwcmd - _rtB->yrw;

    /* RTW Generated Level2 S-Function Block: '<S164>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 83);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S168>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 84);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S169>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 85);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 86);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S129>/Sum5' */
    _rtB->Saturation2_p += _rtB->GeneratedSFunction_fb;

    /* Sum: '<S129>/Sum3' */
    _rtB->Sum3_cy = (_rtB->Saturation2_p - _rtB->psd) + _rtB->psdcmd;

    /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 87);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S162>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 88);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S167>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 89);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S161>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 90);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S129>/Sum1' */
    _rtB->Sum1_lk = (_rtB->Saturation2_p - _rtB->phiL_n) + _rtB->Saturation8;

    /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 91);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S166>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 92);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S129>/Sum' */
    _rtB->Sum_oh = _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 93);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MultiPortSwitch: '<S64>/Multiport Switch2' */
    switch (_rtB->Switch2_a) {
     case 1:
      _rtB->MultiportSwitch2_k = _rtB->GeneratedSFunction4_b;
      break;

     case 2:
      _rtB->MultiportSwitch2_k = _rtB->GeneratedSFunction4_m;
      break;

     case 3:
      _rtB->MultiportSwitch2_k = _rtB->GeneratedSFunction4_dc;
      break;

     case 4:
      _rtB->MultiportSwitch2_k = _rtB->GeneratedSFunction4_cg;
      break;

     default:
      _rtB->MultiportSwitch2_k = _rtB->GeneratedSFunction4_mj;
      break;
    }

    /* End of MultiPortSwitch: '<S64>/Multiport Switch2' */

    /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 94);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Product: '<S129>/Divide' incorporates:
     *  Constant: '<S68>/Constant15'
     */
    _rtB->Divide_c2 = _rtB->Switch_bg / 3.0F;

    /* RTW Generated Level2 S-Function Block: '<S163>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 95);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* Sum: '<S129>/Sum4' */
    _rtB->Saturation8 = (_rtB->phiL_n + _rtB->GeneratedSFunction1_nk) -
      _rtB->Saturation8;

    /* Product: '<S129>/Divide1' incorporates:
     *  Constant: '<S68>/Constant38'
     */
    _rtB->Divide1_d = _rtB->Saturation8 / 3.0F;

    /* RTW Generated Level2 S-Function Block: '<S165>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 96);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Switch: '<S56>/Switch3' incorporates:
     *  Constant: '<S56>/Constant4'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch3_n = _rtB->apyawL;
    } else {
      _rtB->Switch3_n = 4;
    }

    /* End of Switch: '<S56>/Switch3' */

    /* RelationalOperator: '<S67>/Relational Operator4' incorporates:
     *  Constant: '<S67>/Constant4'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch3_n == 1);

    /* DataTypeConversion: '<S67>/Data Type Conversion' */
    _rtB->DataTypeConversion_f = (int8_T)_rtB->RelationalOperator1_c;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S195>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 445))[0];

    /* RelationalOperator: '<S195>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S195>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 218))[0];

    /* Switch: '<S195>/Switch' incorporates:
     *  Constant: '<S56>/Constant6'
     */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_jf = 0.0F;
    } else {
      _rtB->Switch_jf = _rtB->Add8;
    }

    /* End of Switch: '<S195>/Switch' */
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 97);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S67>/Relational Operator3' incorporates:
     *  Constant: '<S67>/Constant5'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch3_n == 4);

    /* DataTypeConversion: '<S67>/Data Type Conversion3' */
    _rtB->DataTypeConversion3_l = (int8_T)_rtB->RelationalOperator1_c;

    /* Gain: '<S56>/Gain2' */
    _rtB->Saturation2_p = 20.0F * _rtB->GeneratedSFunction15_e;

    /* Switch: '<S56>/Switch7' */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch7 = _rtB->nycmd;
    } else {
      _rtB->Switch7 = _rtB->Saturation2_p;
    }

    /* End of Switch: '<S56>/Switch7' */

    /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 98);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S67>/Relational Operator1' incorporates:
     *  Constant: '<S67>/Constant1'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch3_n == 2);

    /* DataTypeConversion: '<S67>/Data Type Conversion1' */
    _rtB->DataTypeConversion1_e = (int8_T)_rtB->RelationalOperator1_c;

    /* Sum: '<S193>/Sum3' */
    _rtB->Sum3_g5 = _rtB->psiLcmd - _rtB->psiL_d;

    /* RTW Generated Level2 S-Function Block: '<S193>/Generated S-Function' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 99);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S198>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 100);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S199>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 101);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 102);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 103);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S67>/Relational Operator2' incorporates:
     *  Constant: '<S67>/Constant2'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch3_n == 3);

    /* DataTypeConversion: '<S67>/Data Type Conversion2' */
    _rtB->DataTypeConversion2_j = (int8_T)_rtB->RelationalOperator1_c;

    /* RTW Generated Level2 S-Function Block: '<S204>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 104);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S194>/Sum2' */
    _rtB->Sum2_eo = _rtB->yrwcmd - _rtB->yrw;

    /* RTW Generated Level2 S-Function Block: '<S203>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 105);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S206>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 106);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S194>/Sum3' */
    _rtB->Sum3_k = (_rtB->MinMax - _rtB->psd) + _rtB->psdcmd;

    /* RTW Generated Level2 S-Function Block: '<S194>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 107);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S202>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 108);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S205>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 109);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 110);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S194>/Sum1' */
    _rtB->Sum1_k = _rtB->MinMax - _rtB->Saturation8;

    /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 111);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MultiPortSwitch: '<S67>/Multiport Switch2' */
    switch (_rtB->Switch3_n) {
     case 1:
      _rtB->apyc = _rtB->GeneratedSFunction4_k;
      break;

     case 2:
      _rtB->apyc = _rtB->GeneratedSFunction4_a;
      break;

     case 3:
      _rtB->apyc = _rtB->GeneratedSFunction4_j;
      break;

     default:
      _rtB->apyc = _rtB->GeneratedSFunction4_p;
      break;
    }

    /* End of MultiPortSwitch: '<S67>/Multiport Switch2' */

    /* Switch: '<S56>/Switch10' incorporates:
     *  Constant: '<S56>/Constant5'
     */
    if (_rtB->SWAUTO > 0) {
      _rtB->Switch10 = _rtB->apnwsL;
    } else {
      _rtB->Switch10 = 3;
    }

    /* End of Switch: '<S56>/Switch10' */

    /* RelationalOperator: '<S62>/Relational Operator4' incorporates:
     *  Constant: '<S62>/Constant4'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch10 == 1);

    /* DataTypeConversion: '<S62>/Data Type Conversion' */
    _rtB->DataTypeConversion_p = (int8_T)_rtB->RelationalOperator1_c;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* MultiPortSwitch: '<S65>/Multiport Switch2' incorporates:
     *  Constant: '<S65>/Constant'
     *  Constant: '<S65>/Constant3'
     *  Constant: '<S65>/Constant5'
     */
    switch (_rtB->apsbL) {
     case 1:
      _rtB->MultiportSwitch2_n = 0.0F;
      break;

     case 2:
      _rtB->MultiportSwitch2_n = 0.5F;
      break;

     default:
      _rtB->MultiportSwitch2_n = 1.0F;
      break;
    }

    /* End of MultiPortSwitch: '<S65>/Multiport Switch2' */

    /* UnitDelay: '<S73>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 458))[0];

    /* RelationalOperator: '<S73>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S73>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 231))[0];

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S56>/Constant6'
     */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_fz = 0.0F;
    } else {
      _rtB->Switch_fz = _rtB->Add8;
    }

    /* End of Switch: '<S73>/Switch' */
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 112);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S62>/Relational Operator2' incorporates:
     *  Constant: '<S62>/Constant2'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch10 == 3);

    /* DataTypeConversion: '<S62>/Data Type Conversion2' */
    _rtB->DataTypeConversion2_b = (int8_T)_rtB->RelationalOperator1_c;

    /* Gain: '<S62>/Gain' */
    _rtB->Gain_k = 3.0F * _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 113);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RelationalOperator: '<S62>/Relational Operator1' incorporates:
     *  Constant: '<S62>/Constant1'
     */
    _rtB->RelationalOperator1_c = (_rtB->Switch10 == 2);

    /* DataTypeConversion: '<S62>/Data Type Conversion1' */
    _rtB->DataTypeConversion1_jy = (int8_T)_rtB->RelationalOperator1_c;

    /* Sum: '<S72>/Sum2' */
    _rtB->Sum2_b = _rtB->yrwcmd - _rtB->yrw;

    /* RTW Generated Level2 S-Function Block: '<S77>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 114);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S79>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 115);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S72>/Sum3' */
    _rtB->Sum3_ca = _rtB->Saturation2_p - _rtB->psd;

    /* RTW Generated Level2 S-Function Block: '<S72>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 116);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S76>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 117);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S78>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 118);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 119);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 120);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MultiPortSwitch: '<S62>/Multiport Switch2' */
    switch (_rtB->Switch10) {
     case 1:
      _rtB->MultiportSwitch2_p = _rtB->GeneratedSFunction4_pd;
      break;

     case 2:
      _rtB->MultiportSwitch2_p = _rtB->GeneratedSFunction4_cw;
      break;

     default:
      _rtB->MultiportSwitch2_p = _rtB->GeneratedSFunction4_h;
      break;
    }

    /* End of MultiPortSwitch: '<S62>/Multiport Switch2' */
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* MultiPortSwitch: '<S61>/Multiport Switch2' incorporates:
     *  Constant: '<S61>/Constant'
     *  Constant: '<S61>/Constant2'
     */
    if (_rtB->apbrkL == 1) {
      _rtB->MultiportSwitch2_d = 0;
    } else {
      _rtB->MultiportSwitch2_d = 1;
    }

    /* End of MultiPortSwitch: '<S61>/Multiport Switch2' */
  }

  if (1) {
    /* Switch: '<S214>/Switch' incorporates:
     *  Constant: '<S57>/Constant2'
     *  Switch: '<S57>/Switch'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_lr = 0.0F;
    } else {
      if (_rtB->Swcheck > 0) {
        /* Switch: '<S57>/Switch' */
        _rtB->Switch_gn = _rtB->Saturation_n;
      } else {
        /* Switch: '<S57>/Switch' */
        _rtB->Switch_gn = _rtB->apthrust;
      }

      _rtB->Switch_lr = _rtB->Switch_gn;
    }

    /* End of Switch: '<S214>/Switch' */

    /* RTW Generated Level2 S-Function Block: '<S209>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 121);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 122);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Saturate: '<S211>/Saturation' */
    if (_rtB->aprc > 100.0F) {
      _rtB->Saturation2_p = 100.0F;
    } else if (_rtB->aprc < -100.0F) {
      _rtB->Saturation2_p = -100.0F;
    } else {
      _rtB->Saturation2_p = _rtB->aprc;
    }

    /* End of Saturate: '<S211>/Saturation' */

    /* Saturate: '<S227>/Saturation' */
    if (_rtB->p_c > 150.0F) {
      _rtB->Saturation_ll = 150.0F;
    } else if (_rtB->p_c < -150.0F) {
      _rtB->Saturation_ll = -150.0F;
    } else {
      _rtB->Saturation_ll = _rtB->p_c;
    }

    /* End of Saturate: '<S227>/Saturation' */

    /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 123);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S227>/Sum' */
    _rtB->Sum_ot = _rtB->Saturation2_p - _rtB->Saturation8;

    /* Lookup_n-D: '<S210>/1-D Lookup Table' */
    _rtB->Saturation2_p = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Qbar_d,
      AFCS_MODEL1_ConstP.uDLookupTable_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable_tableData_i, 10U);

    /* Product: '<S210>/Product' incorporates:
     *  Constant: '<S210>/Constant20'
     */
    _rtB->Product_pf = _rtB->Saturation2_p * -0.21F;

    /* RTW Generated Level2 S-Function Block: '<S245>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 124);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S246>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 125);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 126);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S242>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 127);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Saturate: '<S227>/Saturation1' */
    if (_rtB->r_n > 150.0F) {
      _rtB->Saturation1_o = 150.0F;
    } else if (_rtB->r_n < -150.0F) {
      _rtB->Saturation1_o = -150.0F;
    } else {
      _rtB->Saturation1_o = _rtB->r_n;
    }

    /* End of Saturate: '<S227>/Saturation1' */

    /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 128);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 129);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S244>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 130);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S227>/Sum2' */
    _rtB->Saturation8 += _rtB->MinMax;

    /* Sum: '<S227>/Sum5' */
    _rtB->Sum5 = _rtB->apyc - _rtB->Saturation8;

    /* Product: '<S210>/Product2' */
    _rtB->Product2_d = -_rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S243>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 131);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Switch: '<S229>/Switch' incorporates:
     *  Constant: '<S211>/Constant1'
     *  Switch: '<S211>/Switch6'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_dd = 0.0F;
    } else {
      if (_rtB->Swcheck > 0) {
        /* Switch: '<S211>/Switch6' */
        _rtB->Switch6_f = _rtB->Saturation3_f;
      } else {
        /* Switch: '<S211>/Switch6' incorporates:
         *  Sum: '<S227>/Sum1'
         */
        _rtB->Switch6_f = _rtB->GeneratedSFunction_gq +
          _rtB->GeneratedSFunction_dc;
      }

      _rtB->Switch_dd = _rtB->Switch6_f;
    }

    /* End of Switch: '<S229>/Switch' */

    /* RTW Generated Level2 S-Function Block: '<S225>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 132);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 133);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Sum: '<S58>/Add6' */
    _rtB->Add8 = _rtB->TmpSignalConversionAtCodeReus_b[3] -
      _rtB->TmpSignalConversionAtCodeReus_b[2];

    /* Gain: '<S58>/Gain1' */
    _rtB->Gain1_o = 0.5F * _rtB->Add8;
  }

  if (1) {
    /* Switch: '<S228>/Switch' incorporates:
     *  Constant: '<S211>/Constant'
     *  Switch: '<S211>/Switch5'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_c = 0.0F;
    } else if (_rtB->Swcheck > 0) {
      /* Switch: '<S211>/Switch5' */
      _rtB->Switch_c = _rtB->Saturation2_o;
    } else {
      _rtB->Switch_c = _rtB->GeneratedSFunction_fe;
    }

    /* End of Switch: '<S228>/Switch' */

    /* RTW Generated Level2 S-Function Block: '<S226>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 134);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 135);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 136);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 137);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 138);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S259>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 139);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S260>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 140);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S247>/Sum2' */
    _rtB->Sum2_hd = _rtB->MinMax + _rtB->Saturation7;

    /* RTW Generated Level2 S-Function Block: '<S255>/Generated S-Function9' (NegativePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 141);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 142);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S268>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 143);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 144);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S269>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 145);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S256>/Sum1' */
    _rtB->MinMax = (_rtB->MinMax + _rtB->Alfa_j) + _rtB->GeneratedSFunction7_o1;

    /* Sum: '<S256>/Sum12' incorporates:
     *  Constant: '<S210>/Constant36'
     */
    _rtB->Sum12 = _rtB->MinMax - -4.0F;

    /* RTW Generated Level2 S-Function Block: '<S267>/Generated S-Function' (NegativePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 146);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S270>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 147);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S256>/Sum8' incorporates:
     *  Constant: '<S210>/Constant37'
     */
    _rtB->MinMax -= 8.0F;

    /* Sum: '<S256>/Sum2' */
    _rtB->Sum2_n = _rtB->MinMax;

    /* RTW Generated Level2 S-Function Block: '<S272>/Generated S-Function' (PositivePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 148);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S271>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 149);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* MinMax: '<S247>/MinMax' */
    if (!((_rtB->MinMax >= _rtB->Sum2_hd) || rtIsNaNF(_rtB->Sum2_hd))) {
      _rtB->MinMax = _rtB->Sum2_hd;
    }

    /* End of MinMax: '<S247>/MinMax' */

    /* RTW Generated Level2 S-Function Block: '<S261>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 150);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S247>/Sum5' */
    _rtB->GeneratedSFunction7_o1 = ((_rtB->GeneratedSFunction7_o1 + _rtB->MinMax)
      + _rtB->Saturation7) + _rtB->Saturation9;

    /* Sum: '<S247>/Sum6' */
    _rtB->Sum6_j = _rtB->appc - _rtB->GeneratedSFunction7_o1;

    /* Product: '<S210>/Product1' incorporates:
     *  Constant: '<S210>/Constant8'
     */
    _rtB->Product1_j = -0.55F * _rtB->Saturation2_p;

    /* RTW Generated Level2 S-Function Block: '<S262>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 151);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S258>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 152);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S247>/Add4' incorporates:
     *  Constant: '<S210>/Constant16'
     */
    _rtB->Add4 = 25.0F - _rtB->Saturation9;

    /* Sum: '<S247>/Add5' incorporates:
     *  Constant: '<S210>/Constant17'
     */
    _rtB->Add5 = -25.0F - _rtB->Saturation9;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Sum: '<S58>/Add4' */
    _rtB->Add8 = _rtB->TmpSignalConversionAtCodeReus_b[1] +
      _rtB->TmpSignalConversionAtCodeReus_b[0];

    /* Gain: '<S58>/Gain' */
    _rtB->Gain_i = 0.5F * _rtB->Add8;

    /* UnitDelay: '<S273>/Unit Delay' */
    _rtB->UnitDelay_p = ((int8_T *)ssGetDWork(S, 491))[0];

    /* RelationalOperator: '<S273>/Relational Operator' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    _rtB->RelationalOperator_g = (1 > _rtB->UnitDelay_p);

    /* UnitDelay: '<S273>/Unit Delay1' */
    _rtB->Add8 = ((real32_T *)ssGetDWork(S, 261))[0];

    /* Switch: '<S273>/Switch' */
    if (_rtB->RelationalOperator_g) {
      _rtB->Switch_lrl = _rtB->Gain_i;
    } else {
      _rtB->Switch_lrl = _rtB->Add8;
    }

    /* End of Switch: '<S273>/Switch' */
  }

  if (1) {
    /* Sum: '<S247>/Sum4' */
    _rtB->Sum4_iv = _rtB->Switch_lrl - _rtB->GeneratedSFunction_l;

    /* RTW Generated Level2 S-Function Block: '<S263>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 153);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Product: '<S247>/Product' */
    _rtB->Saturation9 *= _rtB->Switch6_d;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* UnitDelay: '<S247>/Unit Delay1' */
    _rtB->UnitDelay1_c = ((real32_T *)ssGetDWork(S, 262))[0];

    /* RTW Generated Level2 S-Function Block: '<S264>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 154);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* Product: '<S247>/Product1' */
    _rtB->Product1_g *= _rtB->GeneratedSFunction_mt;

    /* Sum: '<S247>/Sum11' */
    _rtB->Sum11_c = _rtB->Saturation9 - _rtB->Product1_g;

    /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 155);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S247>/Sum3' */
    _rtB->Sum3_lx = _rtB->GeneratedSFunction_l + _rtB->deint;

    /* Switch: '<S251>/Switch' incorporates:
     *  Constant: '<S212>/Constant'
     *  Switch: '<S212>/Switch2'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_m = 0.0F;
    } else {
      if (_rtB->Swcheck > 0) {
        /* Switch: '<S212>/Switch2' */
        _rtB->Switch2 = _rtB->Saturation1_f;
      } else {
        /* Switch: '<S212>/Switch2' */
        _rtB->Switch2 = _rtB->Sum3_lx;
      }

      _rtB->Switch_m = _rtB->Switch2;
    }

    /* End of Switch: '<S251>/Switch' */

    /* RTW Generated Level2 S-Function Block: '<S250>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 156);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 157);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Switch: '<S276>/Switch' incorporates:
     *  Constant: '<S213>/Constant1'
     *  Switch: '<S213>/Switch6'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_i = 0.0F;
    } else {
      if (_rtB->Swcheck > 0) {
        /* Switch: '<S213>/Switch6' */
        _rtB->Switch6 = _rtB->Saturation1_f;
      } else {
        /* Switch: '<S213>/Switch6' */
        _rtB->Switch6 = _rtB->MultiportSwitch2_n;
      }

      _rtB->Switch_i = _rtB->Switch6;
    }

    /* End of Switch: '<S276>/Switch' */

    /* RTW Generated Level2 S-Function Block: '<S275>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 158);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 159);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Saturate: '<S207>/Saturation' */
    if (_rtB->r_n > 150.0F) {
      _rtB->Saturation_p = 150.0F;
    } else if (_rtB->r_n < -150.0F) {
      _rtB->Saturation_p = -150.0F;
    } else {
      _rtB->Saturation_p = _rtB->r_n;
    }

    /* End of Saturate: '<S207>/Saturation' */

    /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 160);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* RelationalOperator: '<S207>/Relational Operator' incorporates:
     *  Constant: '<S207>/Constant2'
     */
    _rtB->RelationalOperator_g = (_rtB->fmphase >= 2);

    /* RelationalOperator: '<S207>/Relational Operator1' incorporates:
     *  Constant: '<S207>/Constant3'
     */
    _rtB->RelationalOperator1_f = (_rtB->fmphase <= 4);

    /* Logic: '<S207>/Logical Operator' */
    _rtB->LogicalOperator_o = (_rtB->RelationalOperator_g &&
      _rtB->RelationalOperator1_f);
  }

  if (1) {
    /* Sum: '<S207>/Sum' */
    _rtB->Sum_b = _rtB->MultiportSwitch2_p - _rtB->GeneratedSFunction7_o1;

    /* RTW Generated Level2 S-Function Block: '<S218>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 161);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Switch: '<S219>/Switch' incorporates:
     *  Constant: '<S207>/Constant1'
     *  Switch: '<S207>/Switch1'
     *  Switch: '<S207>/Switch6'
     */
    if (_rtB->apfix > 0) {
      _rtB->Switch_bw = 0.0F;
    } else if (_rtB->Swcheck > 0) {
      /* Switch: '<S207>/Switch6' incorporates:
       *  Gain: '<S207>/Gain3'
       */
      _rtB->Switch_bw = -0.5F * _rtB->Saturation3_f;
    } else if (_rtB->LogicalOperator_o) {
      /* Switch: '<S207>/Switch1' incorporates:
       *  Constant: '<S207>/Constant4'
       *  Switch: '<S207>/Switch6'
       */
      _rtB->Switch_bw = 0.0F;
    } else {
      /* Switch: '<S207>/Switch6' incorporates:
       *  Switch: '<S207>/Switch1'
       */
      _rtB->Switch_bw = _rtB->GeneratedSFunction_ka;
    }

    /* End of Switch: '<S219>/Switch' */

    /* Lookup_n-D: '<S210>/1-D Lookup Table1' */
    _rtB->GeneratedSFunction7_o1 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->vt,
      AFCS_MODEL1_ConstP.uDLookupTable1_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable1_tableData_l, 9U);

    /* Product: '<S210>/Product4' incorporates:
     *  Constant: '<S210>/Constant10'
     */
    _rtB->Product4_o = 15.0F * _rtB->GeneratedSFunction7_o1;

    /* Product: '<S210>/Product3' incorporates:
     *  Constant: '<S210>/Constant43'
     */
    _rtB->Product3_d = _rtB->GeneratedSFunction7_o1 * -15.0F;

    /* RTW Generated Level2 S-Function Block: '<S217>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 162);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 163);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Sum: '<S55>/Sum2' */
    _rtB->Saturation8 += _rtB->TmpSignalConversionAtCodeReus_i[2];

    /* DataTypeConversion: '<S55>/Data Type Conversion' */
    _rtB->drcl = _rtB->Saturation8;
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* DataTypeConversion: '<S207>/Data Type Conversion' */
    _rtB->DataTypeConversion_e = _rtB->MultiportSwitch2_d;

    /* Sum: '<S60>/Add13' incorporates:
     *  Constant: '<S21>/Constant3'
     *  Constant: '<S21>/Constant6'
     */
    _rtB->Add13 = 800.0F;
  }

  if (1) {
    /* Saturate: '<S60>/Saturation' */
    if (_rtB->GeneratedSFunction_o1 > 1.0F) {
      _rtB->Saturation7 = 1.0F;
    } else if (_rtB->GeneratedSFunction_o1 < 0.0F) {
      _rtB->Saturation7 = 0.0F;
    } else {
      _rtB->Saturation7 = _rtB->GeneratedSFunction_o1;
    }

    /* End of Saturate: '<S60>/Saturation' */

    /* Product: '<S60>/Product' */
    _rtB->Saturation7 *= _rtB->Add13;

    /* Sum: '<S60>/Add1' incorporates:
     *  Constant: '<S21>/Constant6'
     */
    _rtB->Saturation7 += 1100.0F;

    /* DataTypeConversion: '<S60>/Data Type Conversion' */
    tmp = (real32_T)floor(_rtB->Saturation7);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion_h = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion' */
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Saturate: '<S60>/Saturation6' */
    if (_rtB->DataTypeConversion_e > 1.0F) {
      _rtB->Add8 = 1.0F;
    } else if (_rtB->DataTypeConversion_e < 0.0F) {
      _rtB->Add8 = 0.0F;
    } else {
      _rtB->Add8 = _rtB->DataTypeConversion_e;
    }

    /* End of Saturate: '<S60>/Saturation6' */

    /* Product: '<S60>/Product9' */
    _rtB->Add8 *= _rtB->Add13;

    /* Sum: '<S60>/Add8' incorporates:
     *  Constant: '<S21>/Constant6'
     */
    _rtB->Add8 += 1100.0F;

    /* DataTypeConversion: '<S60>/Data Type Conversion9' */
    tmp = (real32_T)floor(_rtB->Add8);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion9_o = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion9' */
  }

  if (1) {
    /* Sum: '<S55>/Sum' */
    _rtB->decl = _rtB->daint + _rtB->TmpSignalConversionAtCodeReus_i[0];

    /* Lookup_n-D: '<S60>/1-D Lookup Table2' */
    _rtB->Saturation7 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->decl,
      AFCS_MODEL1_ConstP.uDLookupTable2_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable2_tableData, 24U);

    /* Lookup_n-D: '<S60>/1-D Lookup Table3' */
    _rtB->Saturation2_p = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->decl,
      AFCS_MODEL1_ConstP.uDLookupTable3_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable3_tableData, 23U);

    /* Saturate: '<S60>/Saturation1' */
    if (_rtB->Saturation7 > 2000.0F) {
      _rtB->Saturation7 = 2000.0F;
    } else {
      if (_rtB->Saturation7 < 1000.0F) {
        _rtB->Saturation7 = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation1' */

    /* DataTypeConversion: '<S60>/Data Type Conversion1' */
    tmp = (real32_T)floor(_rtB->Saturation7);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion1_l = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion1' */

    /* Saturate: '<S60>/Saturation3' */
    if (_rtB->Saturation2_p > 2000.0F) {
      _rtB->Saturation2_p = 2000.0F;
    } else {
      if (_rtB->Saturation2_p < 1000.0F) {
        _rtB->Saturation2_p = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation3' */

    /* DataTypeConversion: '<S60>/Data Type Conversion2' */
    tmp = (real32_T)floor(_rtB->Saturation2_p);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion2 = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion2' */

    /* Sum: '<S55>/Sum1' */
    _rtB->dacl = _rtB->drint + _rtB->TmpSignalConversionAtCodeReus_i[1];

    /* Gain: '<S60>/Gain' */
    _rtB->Saturation7 = -_rtB->dacl;

    /* Lookup_n-D: '<S60>/1-D Lookup Table' */
    _rtB->Saturation7 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Saturation7,
      AFCS_MODEL1_ConstP.uDLookupTable_bp01Data_p,
      AFCS_MODEL1_ConstP.uDLookupTable_tableData_k, 25U);

    /* Gain: '<S60>/Gain4' */
    _rtB->Saturation2_p = -_rtB->dacl;

    /* Lookup_n-D: '<S60>/1-D Lookup Table1' */
    _rtB->Saturation2_p = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Saturation2_p,
      AFCS_MODEL1_ConstP.uDLookupTable1_bp01Data_f,
      AFCS_MODEL1_ConstP.uDLookupTable1_tableData_d, 35U);

    /* Saturate: '<S60>/Saturation2' */
    if (_rtB->Saturation2_p > 2000.0F) {
      _rtB->Saturation2_p = 2000.0F;
    } else {
      if (_rtB->Saturation2_p < 1000.0F) {
        _rtB->Saturation2_p = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation2' */

    /* DataTypeConversion: '<S60>/Data Type Conversion3' */
    tmp = (real32_T)floor(_rtB->Saturation2_p);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion3 = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion3' */

    /* Saturate: '<S60>/Saturation7' */
    if (_rtB->Saturation7 > 2000.0F) {
      _rtB->Saturation7 = 2000.0F;
    } else {
      if (_rtB->Saturation7 < 1000.0F) {
        _rtB->Saturation7 = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation7' */

    /* DataTypeConversion: '<S60>/Data Type Conversion4' */
    tmp = (real32_T)floor(_rtB->Saturation7);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion4_i = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion4' */

    /* Gain: '<S60>/Gain5' */
    _rtB->Saturation8 = -_rtB->Saturation8;

    /* Lookup_n-D: '<S60>/1-D Lookup Table4' */
    _rtB->Saturation8 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Saturation8,
      AFCS_MODEL1_ConstP.uDLookupTable4_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable4_tableData, 23U);

    /* Saturate: '<S60>/Saturation8' */
    if (_rtB->Saturation8 > 2000.0F) {
      _rtB->Saturation8 = 2000.0F;
    } else {
      if (_rtB->Saturation8 < 1000.0F) {
        _rtB->Saturation8 = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation8' */

    /* DataTypeConversion: '<S60>/Data Type Conversion5' */
    tmp = (real32_T)floor(_rtB->Saturation8);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion5 = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion5' */

    /* Sum: '<S55>/Sum3' */
    _rtB->Sum3_kf = _rtB->Saturation9 + _rtB->TmpSignalConversionAtCodeReus_i[4];

    /* Lookup_n-D: '<S60>/1-D Lookup Table6' */
    _rtB->Saturation9 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Sum3_kf,
      AFCS_MODEL1_ConstP.uDLookupTable6_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable6_tableData, 1U);

    /* Saturate: '<S60>/Saturation4' */
    if (_rtB->Saturation9 > 2000.0F) {
      _rtB->Saturation9 = 2000.0F;
    } else {
      if (_rtB->Saturation9 < 1000.0F) {
        _rtB->Saturation9 = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation4' */

    /* DataTypeConversion: '<S60>/Data Type Conversion7' */
    tmp = (real32_T)floor(_rtB->Saturation9);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion7 = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion7' */

    /* Sum: '<S55>/Sum4' */
    _rtB->Sum4_h = _rtB->GeneratedSFunction7_o1 +
      _rtB->TmpSignalConversionAtCodeReus_i[3];

    /* Gain: '<S60>/Gain6' */
    _rtB->Saturation9 = -_rtB->Sum4_h;

    /* Lookup_n-D: '<S60>/1-D Lookup Table5' */
    _rtB->Saturation9 = AFCS_MODEL1_look1_iflf_binlxpw(_rtB->Saturation9,
      AFCS_MODEL1_ConstP.uDLookupTable5_bp01Data,
      AFCS_MODEL1_ConstP.uDLookupTable5_tableData, 32U);

    /* Saturate: '<S60>/Saturation9' */
    if (_rtB->Saturation9 > 2000.0F) {
      _rtB->Saturation9 = 2000.0F;
    } else {
      if (_rtB->Saturation9 < 1000.0F) {
        _rtB->Saturation9 = 1000.0F;
      }
    }

    /* End of Saturate: '<S60>/Saturation9' */

    /* DataTypeConversion: '<S60>/Data Type Conversion6' */
    tmp = (real32_T)floor(_rtB->Saturation9);
    if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
      tmp = 0.0F;
    } else {
      tmp = (real32_T)fmod(tmp, 65536.0F);
    }

    _rtB->DataTypeConversion6_e = (uint16_T)(tmp < 0.0F ? (int32_T)(uint16_T)
      -(int16_T)(uint16_T)-tmp : (int32_T)(uint16_T)tmp);

    /* End of DataTypeConversion: '<S60>/Data Type Conversion6' */

    /* Saturate: '<S55>/Saturation' */
    if (_rtB->DataTypeConversion_h > 2000) {
      _rtB->Saturation_h4[0] = 2000U;
    } else if (_rtB->DataTypeConversion_h < 1000) {
      _rtB->Saturation_h4[0] = 1000U;
    } else {
      _rtB->Saturation_h4[0] = _rtB->DataTypeConversion_h;
    }

    if (_rtB->DataTypeConversion1_l > 2000) {
      _rtB->Saturation_h4[1] = 2000U;
    } else if (_rtB->DataTypeConversion1_l < 1000) {
      _rtB->Saturation_h4[1] = 1000U;
    } else {
      _rtB->Saturation_h4[1] = _rtB->DataTypeConversion1_l;
    }

    if (_rtB->DataTypeConversion2 > 2000) {
      _rtB->Saturation_h4[2] = 2000U;
    } else if (_rtB->DataTypeConversion2 < 1000) {
      _rtB->Saturation_h4[2] = 1000U;
    } else {
      _rtB->Saturation_h4[2] = _rtB->DataTypeConversion2;
    }

    if (_rtB->DataTypeConversion3 > 2000) {
      _rtB->Saturation_h4[3] = 2000U;
    } else if (_rtB->DataTypeConversion3 < 1000) {
      _rtB->Saturation_h4[3] = 1000U;
    } else {
      _rtB->Saturation_h4[3] = _rtB->DataTypeConversion3;
    }

    if (_rtB->DataTypeConversion4_i > 2000) {
      _rtB->Saturation_h4[4] = 2000U;
    } else if (_rtB->DataTypeConversion4_i < 1000) {
      _rtB->Saturation_h4[4] = 1000U;
    } else {
      _rtB->Saturation_h4[4] = _rtB->DataTypeConversion4_i;
    }

    if (_rtB->DataTypeConversion5 > 2000) {
      _rtB->Saturation_h4[5] = 2000U;
    } else if (_rtB->DataTypeConversion5 < 1000) {
      _rtB->Saturation_h4[5] = 1000U;
    } else {
      _rtB->Saturation_h4[5] = _rtB->DataTypeConversion5;
    }

    if (_rtB->DataTypeConversion7 > 2000) {
      _rtB->Saturation_h4[6] = 2000U;
    } else if (_rtB->DataTypeConversion7 < 1000) {
      _rtB->Saturation_h4[6] = 1000U;
    } else {
      _rtB->Saturation_h4[6] = _rtB->DataTypeConversion7;
    }

    if (_rtB->DataTypeConversion6_e > 2000) {
      _rtB->Saturation_h4[7] = 2000U;
    } else if (_rtB->DataTypeConversion6_e < 1000) {
      _rtB->Saturation_h4[7] = 1000U;
    } else {
      _rtB->Saturation_h4[7] = _rtB->DataTypeConversion6_e;
    }

    if (_rtB->DataTypeConversion9_o > 2000) {
      _rtB->Saturation_h4[8] = 2000U;
    } else if (_rtB->DataTypeConversion9_o < 1000) {
      _rtB->Saturation_h4[8] = 1000U;
    } else {
      _rtB->Saturation_h4[8] = _rtB->DataTypeConversion9_o;
    }

    if (_rtB->DataTypeConversion9_o > 2000) {
      _rtB->Saturation_h4[9] = 2000U;
    } else if (_rtB->DataTypeConversion9_o < 1000) {
      _rtB->Saturation_h4[9] = 1000U;
    } else {
      _rtB->Saturation_h4[9] = _rtB->DataTypeConversion9_o;
    }

    /* End of Saturate: '<S55>/Saturation' */

    /* Sum: '<S278>/Sum1' incorporates:
     *  Constant: '<S278>/Constant'
     */
    _rtB->Sum1_o = _rtB->Nz - 1.0F;

    /* RTW Generated Level2 S-Function Block: '<S279>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 164);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Saturate: '<S278>/Saturation' */
    if (_rtB->q_k > 150.0F) {
      _rtB->Saturation_bq = 150.0F;
    } else if (_rtB->q_k < -150.0F) {
      _rtB->Saturation_bq = -150.0F;
    } else {
      _rtB->Saturation_bq = _rtB->q_k;
    }

    /* End of Saturate: '<S278>/Saturation' */

    /* RTW Generated Level2 S-Function Block: '<S280>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 165);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S281>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 166);
      sfcnOutputs(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }
}

/* Update for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem_Update(SimStruct * const S)
{
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));
  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S175>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 373))[0] = 1;

    /* Update for UnitDelay: '<S175>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 146))[0] = _rtB->apthrust;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 0);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S186>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 1);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S188>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 2);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 3);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S187>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 4);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S189>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 5);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 6);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 7);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S179>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 8);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S181>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 9);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 10);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S180>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 11);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S182>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 12);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 13);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 14);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S115>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 388))[0] = 1;

    /* Update for UnitDelay: '<S115>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 161))[0] = _rtB->MultiportSwitch2;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S92>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 15);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S96>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 16);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S93>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 17);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S97>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 18);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 19);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S91>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 20);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S95>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 21);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 22);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S94>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 23);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 24);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S114>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 25);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 26);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S86>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 27);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S119>/Generated S-Function' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 28);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S121>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 29);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 30);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S120>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 31);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 32);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S122>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 33);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 34);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S102>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 35);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S104>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 36);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S105>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 37);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 38);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 39);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S103>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 40);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 41);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S109>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 42);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S111>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 43);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S112>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 44);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 45);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 46);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S110>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 47);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 48);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S56>/Unit Delay' */
    ((int8_T *)ssGetDWork(S, 415))[0] = _rtB->SWAUTO;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 49);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S138>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 416))[0] = 1;

    /* Update for UnitDelay: '<S138>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 188))[0] = _rtB->MultiportSwitch2_k;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 50);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S125>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 51);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S134>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 52);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S135>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 53);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S136>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 54);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S125>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 191))[0] = _rtB->GeneratedSFunction3;

    /* RTW Generated Level2 S-Function Block: '<S137>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 55);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 56);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 57);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 58);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* RTW Generated Level2 S-Function Block: '<S155>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 59);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 60);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S154>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 61);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S158>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 62);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 63);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 64);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S153>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 65);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S156>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 66);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S157>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 67);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 68);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 69);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 70);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* RTW Generated Level2 S-Function Block: '<S145>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 71);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 72);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S144>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 73);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S148>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 74);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 75);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S143>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 76);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 77);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S146>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 78);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S147>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 79);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 80);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 81);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 82);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S164>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 83);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S168>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 84);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S169>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 85);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 86);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 87);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S162>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 88);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S167>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 89);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S161>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 90);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function1' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 91);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S166>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 92);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 93);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 94);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* RTW Generated Level2 S-Function Block: '<S163>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 95);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S165>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 96);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S195>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 445))[0] = 1;

    /* Update for UnitDelay: '<S195>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 218))[0] = _rtB->apyc;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 97);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 98);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S193>/Generated S-Function' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 99);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S198>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 100);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S199>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 101);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 102);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 103);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S204>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 104);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S203>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 105);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S206>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 106);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S194>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 107);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S202>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 108);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S205>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 109);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 110);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 111);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S73>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 458))[0] = 1;

    /* Update for UnitDelay: '<S73>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 231))[0] = _rtB->MultiportSwitch2_p;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 112);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 113);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S77>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 114);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S79>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 115);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S72>/Generated S-Function6' (Res180_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 116);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S76>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 117);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S78>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 118);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 119);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 120);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S209>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 121);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 122);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 123);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S245>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 124);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S246>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 125);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 126);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S242>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 127);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 128);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 129);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S244>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 130);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S243>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 131);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S225>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 132);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 133);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S226>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 134);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 135);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 136);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 137);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 138);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S259>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 139);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S260>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 140);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S255>/Generated S-Function9' (NegativePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 141);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 142);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S268>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 143);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 144);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S269>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 145);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S267>/Generated S-Function' (NegativePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 146);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S270>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 147);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S272>/Generated S-Function' (PositivePass_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 148);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S271>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 149);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S261>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 150);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S262>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 151);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S258>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 152);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S273>/Unit Delay' incorporates:
     *  Constant: '<S55>/Constant4'
     */
    ((int8_T *)ssGetDWork(S, 491))[0] = 1;

    /* Update for UnitDelay: '<S273>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 261))[0] = _rtB->Sum3_lx;
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S263>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 153);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (ssIsSampleHit(S, 1, 0)) {
    /* Update for UnitDelay: '<S247>/Unit Delay1' */
    ((real32_T *)ssGetDWork(S, 262))[0] = _rtB->deint;

    /* RTW Generated Level2 S-Function Block: '<S264>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 154);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }

  if (1) {
    /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 155);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S250>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 156);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 157);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S275>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 158);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 159);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 160);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S218>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 161);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S217>/Generated S-Function1' (SaturationLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 162);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 163);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S279>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 164);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S280>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 165);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* RTW Generated Level2 S-Function Block: '<S281>/Generated S-Function' (Gain_sf) */
    {
      SimStruct *rts = ssGetSFunction(S, 166);
      sfcnUpdate(rts, 0);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }
  }
}

/* Termination for atomic system: '<S22>/CodeReuseSubsystem' */
void AFCS_MODEL1_CodeReuseSubsystem_Term(SimStruct * const S)
{
  B_AFCS_MODEL1_T *_rtB;
  _rtB = ((B_AFCS_MODEL1_T *) ssGetLocalBlockIO(S));

  /* RTW Generated Level2 S-Function Block: '<S174>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 0);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S186>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 1);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S188>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 2);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S185>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 3);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S187>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 4);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S189>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 5);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S184>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 6);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S183>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 7);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S179>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 8);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S181>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 9);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S178>/Generated S-Function' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 10);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S180>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 11);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S182>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 12);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S177>/Generated S-Function' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 13);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S176>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 14);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S92>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 15);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S96>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 16);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S93>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 17);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S97>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 18);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S89>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 19);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S91>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 20);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S95>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 21);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S90>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 22);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S94>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 23);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S87>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 24);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S114>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 25);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S113>/Generated S-Function' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 26);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S86>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 27);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S119>/Generated S-Function' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 28);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S121>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 29);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S118>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 30);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S120>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 31);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S117>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 32);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S122>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 33);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S116>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 34);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S102>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 35);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S104>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 36);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S105>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 37);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S100>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 38);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S101>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 39);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S103>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 40);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S98>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 41);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S109>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 42);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S111>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 43);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S112>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 44);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S107>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 45);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S108>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 46);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S110>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 47);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S106>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 48);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S81>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 49);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S130>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 50);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S125>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 51);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S134>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 52);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S135>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 53);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S136>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 54);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S137>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 55);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S132>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 56);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S133>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 57);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S131>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 58);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S155>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 59);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 60);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S154>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 61);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S158>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 62);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S152>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 63);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S128>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 64);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S153>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 65);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S156>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 66);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S157>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 67);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S150>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 68);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S151>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 69);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S149>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 70);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S145>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 71);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 72);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S144>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 73);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S148>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 74);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S142>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 75);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S143>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 76);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S127>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 77);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S146>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 78);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S147>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 79);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S140>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 80);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S141>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 81);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S139>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 82);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S164>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 83);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S168>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 84);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S169>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 85);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S160>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 86);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 87);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S162>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 88);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S167>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 89);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S161>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 90);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S129>/Generated S-Function1' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 91);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S166>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 92);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S159>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 93);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S123>/Generated S-Function5' (Fader_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 94);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S163>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 95);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S165>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 96);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S190>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 97);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S191>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 98);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S193>/Generated S-Function' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 99);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S198>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 100);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S199>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 101);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S197>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 102);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S196>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 103);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S204>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 104);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S203>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 105);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S206>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 106);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S194>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 107);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S202>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 108);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S205>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 109);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S201>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 110);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S200>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 111);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S69>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 112);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S70>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 113);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S77>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 114);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S79>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 115);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S72>/Generated S-Function6' (Res180_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 116);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S76>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 117);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S78>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 118);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S75>/Generated S-Function2' (LeadLagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 119);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S74>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 120);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S209>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 121);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S208>/Generated S-Function' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 122);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S241>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 123);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S245>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 124);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S246>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 125);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S239>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 126);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S242>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 127);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S240>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 128);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S238>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 129);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S244>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 130);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S243>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 131);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S225>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 132);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S223>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 133);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S226>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 134);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S224>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 135);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S252>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 136);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S253>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 137);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S254>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 138);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S259>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 139);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S260>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 140);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S255>/Generated S-Function9' (NegativePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 141);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S266>/Generated S-Function' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 142);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S268>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 143);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S265>/Generated S-Function8' (WashoutFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 144);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S269>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 145);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S267>/Generated S-Function' (NegativePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 146);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S270>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 147);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S272>/Generated S-Function' (PositivePass_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 148);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S271>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 149);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S261>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 150);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S262>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 151);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S258>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 152);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S263>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 153);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S264>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 154);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S257>/Generated S-Function3' (IntegratorLimited_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 155);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S250>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 156);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S249>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 157);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S275>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 158);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S274>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 159);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S215>/Generated S-Function4' (LagFilter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 160);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S218>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 161);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S217>/Generated S-Function1' (SaturationLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 162);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S216>/Generated S-Function7' (RateLimiter_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 163);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S279>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 164);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S280>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 165);
    sfcnTerminate(rts);
  }

  /* RTW Generated Level2 S-Function Block: '<S281>/Generated S-Function' (Gain_sf) */
  {
    SimStruct *rts = ssGetSFunction(S, 166);
    sfcnTerminate(rts);
  }
}
