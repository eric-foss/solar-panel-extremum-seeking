/*
 * PV_curve_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PV_curve".
 *
 * Model version              : 1.12
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Sun Dec  8 10:55:20 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PV_curve.h"

/* Block parameters (default storage) */
P_PV_curve_T PV_curve_P{
  /* Mask Parameter: PWMOutput_Frequency
   * Referenced by: '<Root>/PWM Output'
   */
  200000.0,

  /* Mask Parameter: DutyCycleRamp_InitialOutput
   * Referenced by: '<S1>/Constant1'
   */
  0.9,

  /* Mask Parameter: AnalogInputs_MaxMissedTicks
   * Referenced by: '<Root>/Analog Inputs'
   */
  5000.0,

  /* Mask Parameter: PWMOutput_MaxMissedTicks
   * Referenced by: '<Root>/PWM Output'
   */
  100.0,

  /* Mask Parameter: AnalogInputs_YieldWhenWaiting
   * Referenced by: '<Root>/Analog Inputs'
   */
  0.0,

  /* Mask Parameter: PWMOutput_YieldWhenWaiting
   * Referenced by: '<Root>/PWM Output'
   */
  0.0,

  /* Mask Parameter: DutyCycleRamp_slope
   * Referenced by: '<S1>/Step'
   */
  -0.07,

  /* Mask Parameter: DutyCycleRamp_start
   * Referenced by:
   *   '<S1>/Constant'
   *   '<S1>/Step'
   */
  0.0,

  /* Mask Parameter: AnalogInputs_Channels
   * Referenced by: '<Root>/Analog Inputs'
   */
  { 0, 1 },

  /* Mask Parameter: PWMOutput_Channels
   * Referenced by: '<Root>/PWM Output'
   */
  0,

  /* Mask Parameter: AnalogInputs_RangeMode
   * Referenced by: '<Root>/Analog Inputs'
   */
  0,

  /* Mask Parameter: AnalogInputs_VoltRange
   * Referenced by: '<Root>/Analog Inputs'
   */
  0,

  /* Expression: 5
   * Referenced by: '<Root>/Cutoff Frequency [rad//s]'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Gain'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S1>/Step'
   */
  0.0,

  /* Expression: 0.9
   * Referenced by: '<Root>/Saturation'
   */
  0.9,

  /* Expression: 0.2
   * Referenced by: '<Root>/Saturation'
   */
  0.2
};
