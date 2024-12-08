/*
 * prescribed_time_ES_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "prescribed_time_ES".
 *
 * Model version              : 5.2
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Dec  8 11:55:49 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef prescribed_time_ES_private_h_
#define prescribed_time_ES_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "prescribed_time_ES.h"
#include "prescribed_time_ES_types.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);
extern void prescribed_time_ES_MATLABFunction1_Init
  (DW_MATLABFunction1_prescribed_time_ES_T *localDW);
extern void prescribed_time_ES_MATLABFunction1(real_T rtu_u,
  B_MATLABFunction1_prescribed_time_ES_T *localB,
  DW_MATLABFunction1_prescribed_time_ES_T *localDW);

/* private model entry point functions */
extern void prescribed_time_ES_derivatives(void);

#endif                                 /* prescribed_time_ES_private_h_ */
