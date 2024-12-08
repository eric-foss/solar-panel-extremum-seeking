/*
 * classical_ES_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "classical_ES".
 *
 * Model version              : 5.16
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Dec  8 11:30:02 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "classical_ES.h"

/* Block parameters (default storage) */
P_classical_ES_T classical_ES_P{
  /* Variable: a
   * Referenced by:
   *   '<Root>/Sine Wave'
   *   '<Root>/Sine Wave1'
   */
  0.05,

  /* Variable: k
   * Referenced by: '<Root>/Gain'
   */
  0.005,

  /* Variable: w
   * Referenced by:
   *   '<Root>/Sine Wave'
   *   '<Root>/Sine Wave1'
   */
  5.0,

  /* Mask Parameter: PWMOutput_Frequency
   * Referenced by: '<S1>/PWM Output'
   */
  200000.0,

  /* Mask Parameter: AnalogInputs_MaxMissedTicks
   * Referenced by: '<S1>/Analog Inputs'
   */
  100.0,

  /* Mask Parameter: PWMOutput_MaxMissedTicks
   * Referenced by: '<S1>/PWM Output'
   */
  100000.0,

  /* Mask Parameter: AnalogInputs_YieldWhenWaiting
   * Referenced by: '<S1>/Analog Inputs'
   */
  0.0,

  /* Mask Parameter: PWMOutput_YieldWhenWaiting
   * Referenced by: '<S1>/PWM Output'
   */
  0.0,

  /* Mask Parameter: AnalogInputs_Channels
   * Referenced by: '<S1>/Analog Inputs'
   */
  { 0, 1 },

  /* Mask Parameter: PWMOutput_Channels
   * Referenced by: '<S1>/PWM Output'
   */
  0,

  /* Mask Parameter: AnalogInputs_RangeMode
   * Referenced by: '<S1>/Analog Inputs'
   */
  0,

  /* Mask Parameter: AnalogInputs_VoltRange
   * Referenced by: '<S1>/Analog Inputs'
   */
  0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Constant'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Gain2'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S1>/Cutoff Frequency [rad//s]'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -3.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  -3.0,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<Root>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S1>/Gain'
   */
  2.0,

  /* Expression: 0.9
   * Referenced by: '<S1>/Saturation'
   */
  0.9,

  /* Expression: 0.2
   * Referenced by: '<S1>/Saturation'
   */
  0.2,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  -3.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<Root>/Transfer Fcn1'
   */
  3.0
};
