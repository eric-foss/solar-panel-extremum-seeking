/*
 * prescribed_time_ES_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[]{
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[]{
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[]{
  { (char_T *)(&prescribed_time_ES_B.Product3), 0, 0, 18 },

  { (char_T *)(&prescribed_time_ES_B.sf_MATLABFunction1_p.y), 0, 0, 1 },

  { (char_T *)(&prescribed_time_ES_B.sf_MATLABFunction1_h.y), 0, 0, 1 },

  { (char_T *)(&prescribed_time_ES_B.sf_MATLABFunction1.y), 0, 0, 1 }
  ,

  { (char_T *)(&prescribed_time_ES_DW.Scope4_PWORK.LoggedData), 11, 0, 12 },

  { (char_T *)(&prescribed_time_ES_DW.sfEvent), 6, 0, 4 },

  { (char_T *)(&prescribed_time_ES_DW.doneDoubleBufferReInit), 8, 0, 4 },

  { (char_T *)(&prescribed_time_ES_DW.sf_MATLABFunction1_p.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&prescribed_time_ES_DW.sf_MATLABFunction1_p.doneDoubleBufferReInit), 8, 0,
    1 },

  { (char_T *)(&prescribed_time_ES_DW.sf_MATLABFunction1_h.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&prescribed_time_ES_DW.sf_MATLABFunction1_h.doneDoubleBufferReInit), 8, 0,
    1 },

  { (char_T *)(&prescribed_time_ES_DW.sf_MATLABFunction1.sfEvent), 6, 0, 1 },

  { (char_T *)(&prescribed_time_ES_DW.sf_MATLABFunction1.doneDoubleBufferReInit),
    8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable{
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[]{
  { (char_T *)(&prescribed_time_ES_P.T), 0, 0, 11 },

  { (char_T *)(&prescribed_time_ES_P.AnalogInputs_Channels[0]), 6, 0, 5 },

  { (char_T *)(&prescribed_time_ES_P.Constant_Value), 0, 0, 12 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable{
  3U,
  rtPTransitions
};

/* [EOF] prescribed_time_ES_dt.h */
