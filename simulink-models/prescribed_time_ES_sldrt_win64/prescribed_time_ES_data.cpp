/*
 * prescribed_time_ES_data.cpp
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

#include "prescribed_time_ES.h"

/* Block parameters (default storage) */
P_prescribed_time_ES_T prescribed_time_ES_P{
  /* Variable: T
   * Referenced by:
   *   '<Root>/MATLAB Function1'
   *   '<Root>/MATLAB Function2'
   *   '<Root>/MATLAB Function3'
   *   '<Root>/MATLAB Function4'
   *   '<S1>/MATLAB Function1'
   *   '<S2>/MATLAB Function1'
   *   '<S3>/MATLAB Function1'
   */
  5.3,

  /* Variable: a
   * Referenced by:
   *   '<Root>/MATLAB Function2'
   *   '<Root>/MATLAB Function3'
   *   '<Root>/MATLAB Function4'
   */
  0.05,

  /* Variable: k
   * Referenced by: '<S1>/Gain'
   */
  0.005,

  /* Variable: lambda
   * Referenced by: '<Root>/MATLAB Function1'
   */
  0.05,

  /* Variable: w
   * Referenced by:
   *   '<Root>/MATLAB Function2'
   *   '<Root>/MATLAB Function3'
   *   '<Root>/MATLAB Function4'
   */
  5.0,

  /* Variable: wh
   * Referenced by:
   *   '<S2>/Gain1'
   *   '<S2>/Gain3'
   *   '<S3>/Gain1'
   *   '<S3>/Gain3'
   */
  3.0,

  /* Mask Parameter: PWMOutput_Frequency
   * Referenced by: '<S8>/PWM Output'
   */
  200000.0,

  /* Mask Parameter: AnalogInputs_MaxMissedTicks
   * Referenced by: '<S8>/Analog Inputs'
   */
  100.0,

  /* Mask Parameter: PWMOutput_MaxMissedTicks
   * Referenced by: '<S8>/PWM Output'
   */
  100000.0,

  /* Mask Parameter: AnalogInputs_YieldWhenWaiting
   * Referenced by: '<S8>/Analog Inputs'
   */
  0.0,

  /* Mask Parameter: PWMOutput_YieldWhenWaiting
   * Referenced by: '<S8>/PWM Output'
   */
  0.0,

  /* Mask Parameter: AnalogInputs_Channels
   * Referenced by: '<S8>/Analog Inputs'
   */
  { 0, 1 },

  /* Mask Parameter: PWMOutput_Channels
   * Referenced by: '<S8>/PWM Output'
   */
  0,

  /* Mask Parameter: AnalogInputs_RangeMode
   * Referenced by: '<S8>/Analog Inputs'
   */
  0,

  /* Mask Parameter: AnalogInputs_VoltRange
   * Referenced by: '<S8>/Analog Inputs'
   */
  0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Constant1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S8>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S8>/Cutoff Frequency [rad//s]'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S17>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S16>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<S8>/Saturation'
   */
  0.9,

  /* Expression: 0.2
   * Referenced by: '<S8>/Saturation'
   */
  0.2
};
