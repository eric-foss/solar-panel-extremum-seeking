/*
 * prescribed_time_ES.cpp
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
#include "rtwtypes.h"
#include "prescribed_time_ES_private.h"
#include <cmath>
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "prescribed_time_ES_dt.h"

/* Named constants for MATLAB Function: '<S1>/MATLAB Function1' */
const int32_T prescribed_time_ES_CALL_EVENT{ -1 };

/* Named constants for MATLAB Function: '<Root>/MATLAB Function1' */
const int32_T prescribed_time_ES_CALL_EVENT_f{ -1 };

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0,
  0.0,
  0.0,
  3.0,
  3.0,
};

/* list of Simulink Desktop Real-Time timers */
extern "C" const int SLDRTTimerCount = 1;
extern "C" const double SLDRTTimers[2] =
{
  0.0001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
extern "C" const int SLDRTBoardCount = 1;
extern "C" SLDRTBOARD SLDRTBoards[1] =
{
  {
    "National_Instruments/PCI-6251", 4294967295U, 5, SLDRTBoardOptions0
  },
};

/* Block signals (default storage) */
B_prescribed_time_ES_T prescribed_time_ES_B;

/* Continuous states */
X_prescribed_time_ES_T prescribed_time_ES_X;

/* Disabled State Vector */
XDis_prescribed_time_ES_T prescribed_time_ES_XDis;

/* Block states (default storage) */
DW_prescribed_time_ES_T prescribed_time_ES_DW;

/* Real-time model */
RT_MODEL_prescribed_time_ES_T prescribed_time_ES_M_{ };

RT_MODEL_prescribed_time_ES_T *const prescribed_time_ES_M{ &
  prescribed_time_ES_M_ };

static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (prescribed_time_ES_M->Timing.TaskCounters.TID[2])++;
  if ((prescribed_time_ES_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    prescribed_time_ES_M->Timing.TaskCounters.TID[2] = 0;
  }

  prescribed_time_ES_M->Timing.sampleHits[2] =
    (prescribed_time_ES_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 6 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  prescribed_time_ES_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  prescribed_time_ES_output();
  prescribed_time_ES_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  prescribed_time_ES_output();
  prescribed_time_ES_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S1>/MATLAB Function1'
 *    '<S2>/MATLAB Function1'
 *    '<S3>/MATLAB Function1'
 */
void prescribed_time_ES_MATLABFunction1_Init
  (DW_MATLABFunction1_prescribed_time_ES_T *localDW)
{
  localDW->doneDoubleBufferReInit = false;
  localDW->sfEvent = prescribed_time_ES_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function1'
 *    '<S2>/MATLAB Function1'
 *    '<S3>/MATLAB Function1'
 */
void prescribed_time_ES_MATLABFunction1(real_T rtu_u,
  B_MATLABFunction1_prescribed_time_ES_T *localB,
  DW_MATLABFunction1_prescribed_time_ES_T *localDW)
{
  localDW->sfEvent = prescribed_time_ES_CALL_EVENT;
  localB->y = prescribed_time_ES_P.T / (prescribed_time_ES_P.T - rtu_u);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (std::isinf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = (rtNaN);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void prescribed_time_ES_output(void)
{
  /* local block i/o variables */
  real_T rtb_Clock1_e;
  real_T rtb_Clock1_d;
  real_T rtb_Clock1_l;
  real_T y_d_tmp;
  real_T y_d_tmp_0;
  real_T y_d_tmp_tmp;
  if (rtmIsMajorTimeStep(prescribed_time_ES_M)) {
    /* set solver stop time */
    if (!(prescribed_time_ES_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&prescribed_time_ES_M->solverInfo,
                            ((prescribed_time_ES_M->Timing.clockTickH0 + 1) *
        prescribed_time_ES_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&prescribed_time_ES_M->solverInfo,
                            ((prescribed_time_ES_M->Timing.clockTick0 + 1) *
        prescribed_time_ES_M->Timing.stepSize0 +
        prescribed_time_ES_M->Timing.clockTickH0 *
        prescribed_time_ES_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(prescribed_time_ES_M)) {
    prescribed_time_ES_M->Timing.t[0] = rtsiGetT
      (&prescribed_time_ES_M->solverInfo);
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  prescribed_time_ES_DW.sfEvent_k = prescribed_time_ES_CALL_EVENT_f;

  /* Clock: '<Root>/Clock1' incorporates:
   *  Clock: '<S1>/Clock1'
   *  Clock: '<S2>/Clock1'
   *  Clock: '<S3>/Clock1'
   */
  y_d_tmp = prescribed_time_ES_M->Timing.t[0];

  /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
   *  Clock: '<Root>/Clock1'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   *  MATLAB Function: '<Root>/MATLAB Function4'
   */
  y_d_tmp_tmp = prescribed_time_ES_P.T - y_d_tmp;
  y_d_tmp_0 = prescribed_time_ES_P.T / y_d_tmp_tmp;
  prescribed_time_ES_B.y_d = rt_powd_snf(y_d_tmp_0, -prescribed_time_ES_P.lambda
    * prescribed_time_ES_P.T);
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Clock: '<S1>/Clock1' */
  rtb_Clock1_e = y_d_tmp;

  /* MATLAB Function: '<S1>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1(rtb_Clock1_e,
    &prescribed_time_ES_B.sf_MATLABFunction1,
    &prescribed_time_ES_DW.sf_MATLABFunction1);

  /* Product: '<S1>/Product3' incorporates:
   *  Gain: '<S1>/Gain'
   *  Integrator: '<S3>/Integrator1'
   */
  prescribed_time_ES_B.Product3 = prescribed_time_ES_P.k *
    prescribed_time_ES_X.Integrator1_CSTATE *
    prescribed_time_ES_B.sf_MATLABFunction1.y;

  /* Clock: '<S2>/Clock1' */
  rtb_Clock1_d = y_d_tmp;
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtai): '<S8>/Analog Inputs' */
    /* S-Function Block: <S8>/Analog Inputs */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) prescribed_time_ES_P.AnalogInputs_RangeMode;
      parm.rangeidx = prescribed_time_ES_P.AnalogInputs_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     prescribed_time_ES_P.AnalogInputs_Channels,
                     &prescribed_time_ES_B.AnalogInputs[0], &parm);
    }

    /* Gain: '<S8>/Gain' */
    prescribed_time_ES_B.Gain = prescribed_time_ES_P.Gain_Gain *
      prescribed_time_ES_B.AnalogInputs[1];

    /* Product: '<S8>/Product' */
    prescribed_time_ES_B.Product = prescribed_time_ES_B.AnalogInputs[0] *
      prescribed_time_ES_B.Gain;

    /* Gain: '<S2>/Gain3' */
    prescribed_time_ES_B.Gain3 = prescribed_time_ES_P.wh *
      prescribed_time_ES_B.Product;
  }

  /* MATLAB Function: '<S2>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1(rtb_Clock1_d,
    &prescribed_time_ES_B.sf_MATLABFunction1_h,
    &prescribed_time_ES_DW.sf_MATLABFunction1_h);

  /* Product: '<S2>/Product3' incorporates:
   *  Gain: '<S2>/Gain1'
   *  Integrator: '<S2>/Integrator1'
   *  Sum: '<S2>/Sum1'
   */
  prescribed_time_ES_B.Product3_m = (-prescribed_time_ES_P.wh *
    prescribed_time_ES_X.Integrator1_CSTATE_h + prescribed_time_ES_B.Gain3) *
    prescribed_time_ES_B.sf_MATLABFunction1_h.y;

  /* Clock: '<S3>/Clock1' */
  rtb_Clock1_l = y_d_tmp;

  /* MATLAB Function: '<Root>/MATLAB Function3' */
  prescribed_time_ES_DW.sfEvent_d = prescribed_time_ES_CALL_EVENT_f;

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1(rtb_Clock1_l,
    &prescribed_time_ES_B.sf_MATLABFunction1_p,
    &prescribed_time_ES_DW.sf_MATLABFunction1_p);

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function2'
   */
  y_d_tmp = std::sin(prescribed_time_ES_P.w * prescribed_time_ES_P.T * std::log
                     (y_d_tmp_0));

  /* Product: '<S3>/Product3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S3>/Gain1'
   *  Gain: '<S3>/Gain3'
   *  Integrator: '<S2>/Integrator1'
   *  Integrator: '<S3>/Integrator1'
   *  MATLAB Function: '<Root>/MATLAB Function3'
   *  Product: '<Root>/Divide'
   *  Product: '<Root>/Product'
   *  Product: '<Root>/Product1'
   *  Sum: '<S2>/Sum2'
   *  Sum: '<S3>/Sum1'
   */
  prescribed_time_ES_B.Product3_c = (2.0 / prescribed_time_ES_P.a * y_d_tmp *
    (prescribed_time_ES_P.Constant_Value / prescribed_time_ES_B.y_d) *
    (prescribed_time_ES_B.Product - prescribed_time_ES_X.Integrator1_CSTATE_h) *
    prescribed_time_ES_P.wh + -prescribed_time_ES_P.wh *
    prescribed_time_ES_X.Integrator1_CSTATE) *
    prescribed_time_ES_B.sf_MATLABFunction1_p.y;

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  prescribed_time_ES_DW.sfEvent_o = prescribed_time_ES_CALL_EVENT_f;

  /* Product: '<S17>/Product4' incorporates:
   *  Constant: '<S8>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S17>/Integrator'
   */
  prescribed_time_ES_B.Product4 = prescribed_time_ES_P.CutoffFrequencyrads_Value
    * prescribed_time_ES_X.Integrator_CSTATE_a;
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S16>/Product4' incorporates:
   *  Constant: '<S8>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S16>/Integrator'
   */
  prescribed_time_ES_B.Product4_b =
    prescribed_time_ES_P.CutoffFrequencyrads_Value *
    prescribed_time_ES_X.Integrator_CSTATE_p;
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S15>/Product4' incorporates:
   *  Constant: '<S8>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S15>/Integrator'
   */
  prescribed_time_ES_B.Product4_c =
    prescribed_time_ES_P.CutoffFrequencyrads_Value *
    prescribed_time_ES_X.Integrator_CSTATE_k;
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[2] == 0) {
  }

  /* Sum: '<S15>/Sum2' */
  prescribed_time_ES_B.Sum2 = prescribed_time_ES_B.Product -
    prescribed_time_ES_B.Product4_c;

  /* Sum: '<S16>/Sum2' */
  prescribed_time_ES_B.Sum2_i = prescribed_time_ES_B.AnalogInputs[0] -
    prescribed_time_ES_B.Product4_b;

  /* Sum: '<S17>/Sum2' */
  prescribed_time_ES_B.Sum2_h = prescribed_time_ES_B.Gain -
    prescribed_time_ES_B.Product4;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Integrator: '<Root>/Integrator'
   *  MATLAB Function: '<Root>/MATLAB Function2'
   *  Product: '<Root>/Product2'
   *  Sum: '<Root>/Sum'
   */
  prescribed_time_ES_B.Sum1 = (prescribed_time_ES_P.a * y_d_tmp *
    prescribed_time_ES_B.y_d + prescribed_time_ES_X.Integrator_CSTATE) +
    prescribed_time_ES_P.Constant1_Value;

  /* Saturate: '<S8>/Saturation' */
  if (prescribed_time_ES_B.Sum1 > prescribed_time_ES_P.Saturation_UpperSat) {
    /* Saturate: '<S8>/Saturation' */
    prescribed_time_ES_B.Saturation = prescribed_time_ES_P.Saturation_UpperSat;
  } else if (prescribed_time_ES_B.Sum1 <
             prescribed_time_ES_P.Saturation_LowerSat) {
    /* Saturate: '<S8>/Saturation' */
    prescribed_time_ES_B.Saturation = prescribed_time_ES_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S8>/Saturation' */
    prescribed_time_ES_B.Saturation = prescribed_time_ES_B.Sum1;
  }

  /* End of Saturate: '<S8>/Saturation' */
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtqo): '<S8>/PWM Output' */
    /* S-Function Block: <S8>/PWM Output */
    {
      {
        RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                       &prescribed_time_ES_P.PWMOutput_Channels,
                       &prescribed_time_ES_P.PWMOutput_Frequency, ((real_T*)
          (&prescribed_time_ES_B.Saturation)));
      }
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function4' */
  prescribed_time_ES_DW.sfEvent = prescribed_time_ES_CALL_EVENT_f;
  prescribed_time_ES_B.y = prescribed_time_ES_P.T * prescribed_time_ES_P.T *
    prescribed_time_ES_P.w / (y_d_tmp_tmp * y_d_tmp_tmp);
  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }
}

/* Model update function */
void prescribed_time_ES_update(void)
{
  if (rtmIsMajorTimeStep(prescribed_time_ES_M)) {
    rt_ertODEUpdateContinuousStates(&prescribed_time_ES_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++prescribed_time_ES_M->Timing.clockTick0)) {
    ++prescribed_time_ES_M->Timing.clockTickH0;
  }

  prescribed_time_ES_M->Timing.t[0] = rtsiGetSolverStopTime
    (&prescribed_time_ES_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++prescribed_time_ES_M->Timing.clockTick1)) {
      ++prescribed_time_ES_M->Timing.clockTickH1;
    }

    prescribed_time_ES_M->Timing.t[1] = prescribed_time_ES_M->Timing.clockTick1 *
      prescribed_time_ES_M->Timing.stepSize1 +
      prescribed_time_ES_M->Timing.clockTickH1 *
      prescribed_time_ES_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(prescribed_time_ES_M) &&
      prescribed_time_ES_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++prescribed_time_ES_M->Timing.clockTick2)) {
      ++prescribed_time_ES_M->Timing.clockTickH2;
    }

    prescribed_time_ES_M->Timing.t[2] = prescribed_time_ES_M->Timing.clockTick2 *
      prescribed_time_ES_M->Timing.stepSize2 +
      prescribed_time_ES_M->Timing.clockTickH2 *
      prescribed_time_ES_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void prescribed_time_ES_derivatives(void)
{
  XDot_prescribed_time_ES_T *_rtXdot;
  _rtXdot = ((XDot_prescribed_time_ES_T *) prescribed_time_ES_M->derivs);

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = prescribed_time_ES_B.Product3_c;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_h = prescribed_time_ES_B.Product3_m;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = prescribed_time_ES_B.Product3;

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = prescribed_time_ES_B.Sum2_h;

  /* Derivatives for Integrator: '<S16>/Integrator' */
  _rtXdot->Integrator_CSTATE_p = prescribed_time_ES_B.Sum2_i;

  /* Derivatives for Integrator: '<S15>/Integrator' */
  _rtXdot->Integrator_CSTATE_k = prescribed_time_ES_B.Sum2;
}

/* Model initialize function */
void prescribed_time_ES_initialize(void)
{
  /* Start for S-Function (sldrtqo): '<S8>/PWM Output' */

  /* S-Function Block: <S8>/PWM Output */

  /* no initial value should be set */

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  prescribed_time_ES_X.Integrator1_CSTATE = prescribed_time_ES_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  prescribed_time_ES_X.Integrator1_CSTATE_h =
    prescribed_time_ES_P.Integrator1_IC_f;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  prescribed_time_ES_X.Integrator_CSTATE = prescribed_time_ES_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S17>/Integrator' */
  prescribed_time_ES_X.Integrator_CSTATE_a =
    prescribed_time_ES_P.Integrator_IC_i;

  /* InitializeConditions for Integrator: '<S16>/Integrator' */
  prescribed_time_ES_X.Integrator_CSTATE_p =
    prescribed_time_ES_P.Integrator_IC_a;

  /* InitializeConditions for Integrator: '<S15>/Integrator' */
  prescribed_time_ES_X.Integrator_CSTATE_k =
    prescribed_time_ES_P.Integrator_IC_j;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
  prescribed_time_ES_DW.doneDoubleBufferReInit_b = false;
  prescribed_time_ES_DW.sfEvent_k = prescribed_time_ES_CALL_EVENT_f;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1_Init
    (&prescribed_time_ES_DW.sf_MATLABFunction1);

  /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1_Init
    (&prescribed_time_ES_DW.sf_MATLABFunction1_h);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function3' */
  prescribed_time_ES_DW.doneDoubleBufferReInit_n = false;
  prescribed_time_ES_DW.sfEvent_d = prescribed_time_ES_CALL_EVENT_f;

  /* SystemInitialize for MATLAB Function: '<S3>/MATLAB Function1' */
  prescribed_time_ES_MATLABFunction1_Init
    (&prescribed_time_ES_DW.sf_MATLABFunction1_p);

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function2' */
  prescribed_time_ES_DW.doneDoubleBufferReInit_j = false;
  prescribed_time_ES_DW.sfEvent_o = prescribed_time_ES_CALL_EVENT_f;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function4' */
  prescribed_time_ES_DW.doneDoubleBufferReInit = false;
  prescribed_time_ES_DW.sfEvent = prescribed_time_ES_CALL_EVENT_f;
}

/* Model terminate function */
void prescribed_time_ES_terminate(void)
{
  /* Terminate for S-Function (sldrtqo): '<S8>/PWM Output' */

  /* S-Function Block: <S8>/PWM Output */

  /* no final value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

extern "C" void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

extern "C" void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

extern "C" void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

extern "C" void MdlOutputs(int_T tid)
{
  prescribed_time_ES_output();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  prescribed_time_ES_update();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlInitializeSizes(void)
{
}

extern "C" void MdlInitializeSampleTimes(void)
{
}

extern "C" void MdlInitialize(void)
{
}

extern "C" void MdlStart(void)
{
  prescribed_time_ES_initialize();
}

extern "C" void MdlTerminate(void)
{
  prescribed_time_ES_terminate();
}

/* Registration function */
extern "C" RT_MODEL_prescribed_time_ES_T *prescribed_time_ES(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&prescribed_time_ES_M->solverInfo,
                          &prescribed_time_ES_M->Timing.simTimeStep);
    rtsiSetTPtr(&prescribed_time_ES_M->solverInfo, &rtmGetTPtr
                (prescribed_time_ES_M));
    rtsiSetStepSizePtr(&prescribed_time_ES_M->solverInfo,
                       &prescribed_time_ES_M->Timing.stepSize0);
    rtsiSetdXPtr(&prescribed_time_ES_M->solverInfo,
                 &prescribed_time_ES_M->derivs);
    rtsiSetContStatesPtr(&prescribed_time_ES_M->solverInfo, (real_T **)
                         &prescribed_time_ES_M->contStates);
    rtsiSetNumContStatesPtr(&prescribed_time_ES_M->solverInfo,
      &prescribed_time_ES_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&prescribed_time_ES_M->solverInfo,
      &prescribed_time_ES_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&prescribed_time_ES_M->solverInfo,
      &prescribed_time_ES_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&prescribed_time_ES_M->solverInfo,
      &prescribed_time_ES_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&prescribed_time_ES_M->solverInfo, (boolean_T**)
      &prescribed_time_ES_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&prescribed_time_ES_M->solverInfo, (&rtmGetErrorStatus
      (prescribed_time_ES_M)));
    rtsiSetRTModelPtr(&prescribed_time_ES_M->solverInfo, prescribed_time_ES_M);
  }

  rtsiSetSimTimeStep(&prescribed_time_ES_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&prescribed_time_ES_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&prescribed_time_ES_M->solverInfo, false);
  prescribed_time_ES_M->intgData.y = prescribed_time_ES_M->odeY;
  prescribed_time_ES_M->intgData.f[0] = prescribed_time_ES_M->odeF[0];
  prescribed_time_ES_M->intgData.f[1] = prescribed_time_ES_M->odeF[1];
  prescribed_time_ES_M->intgData.f[2] = prescribed_time_ES_M->odeF[2];
  prescribed_time_ES_M->contStates = ((real_T *) &prescribed_time_ES_X);
  prescribed_time_ES_M->contStateDisabled = ((boolean_T *)
    &prescribed_time_ES_XDis);
  prescribed_time_ES_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&prescribed_time_ES_M->solverInfo, static_cast<void *>
                    (&prescribed_time_ES_M->intgData));
  rtsiSetSolverName(&prescribed_time_ES_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap { prescribed_time_ES_M->Timing.sampleTimeTaskIDArray };

    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "prescribed_time_ES_M points to
       static memory which is guaranteed to be non-NULL" */
    prescribed_time_ES_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    prescribed_time_ES_M->Timing.sampleTimes =
      (&prescribed_time_ES_M->Timing.sampleTimesArray[0]);
    prescribed_time_ES_M->Timing.offsetTimes =
      (&prescribed_time_ES_M->Timing.offsetTimesArray[0]);

    /* task periods */
    prescribed_time_ES_M->Timing.sampleTimes[0] = (0.0);
    prescribed_time_ES_M->Timing.sampleTimes[1] = (0.0001);
    prescribed_time_ES_M->Timing.sampleTimes[2] = (0.001);

    /* task offsets */
    prescribed_time_ES_M->Timing.offsetTimes[0] = (0.0);
    prescribed_time_ES_M->Timing.offsetTimes[1] = (0.0);
    prescribed_time_ES_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(prescribed_time_ES_M, &prescribed_time_ES_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits{ prescribed_time_ES_M->Timing.sampleHitArray };

    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    prescribed_time_ES_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(prescribed_time_ES_M, 5.0);
  prescribed_time_ES_M->Timing.stepSize0 = 0.0001;
  prescribed_time_ES_M->Timing.stepSize1 = 0.0001;
  prescribed_time_ES_M->Timing.stepSize2 = 0.001;

  /* External mode info */
  prescribed_time_ES_M->Sizes.checksums[0] = (3504663762U);
  prescribed_time_ES_M->Sizes.checksums[1] = (1385644302U);
  prescribed_time_ES_M->Sizes.checksums[2] = (4177617401U);
  prescribed_time_ES_M->Sizes.checksums[3] = (2568436805U);

  {
    static const sysRanDType rtAlwaysEnabled{ SUBSYS_RAN_BC_ENABLE };

    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    prescribed_time_ES_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(prescribed_time_ES_M->extModeInfo,
      &prescribed_time_ES_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(prescribed_time_ES_M->extModeInfo,
                        prescribed_time_ES_M->Sizes.checksums);
    rteiSetTPtr(prescribed_time_ES_M->extModeInfo, rtmGetTPtr
                (prescribed_time_ES_M));
  }

  prescribed_time_ES_M->solverInfoPtr = (&prescribed_time_ES_M->solverInfo);
  prescribed_time_ES_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&prescribed_time_ES_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&prescribed_time_ES_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  prescribed_time_ES_M->blockIO = ((void *) &prescribed_time_ES_B);
  (void) std::memset((static_cast<void *>(&prescribed_time_ES_B)), 0,
                     sizeof(B_prescribed_time_ES_T));

  /* parameters */
  prescribed_time_ES_M->defaultParam = ((real_T *)&prescribed_time_ES_P);

  /* states (continuous) */
  {
    real_T *x{ (real_T *) &prescribed_time_ES_X };

    prescribed_time_ES_M->contStates = (x);
    (void) std::memset(static_cast<void *>(&prescribed_time_ES_X), 0,
                       sizeof(X_prescribed_time_ES_T));
  }

  /* disabled states */
  {
    boolean_T *xdis{ (boolean_T *) &prescribed_time_ES_XDis };

    prescribed_time_ES_M->contStateDisabled = (xdis);
    (void) std::memset(static_cast<void *>(&prescribed_time_ES_XDis), 0,
                       sizeof(XDis_prescribed_time_ES_T));
  }

  /* states (dwork) */
  prescribed_time_ES_M->dwork = ((void *) &prescribed_time_ES_DW);
  (void) std::memset(static_cast<void *>(&prescribed_time_ES_DW), 0,
                     sizeof(DW_prescribed_time_ES_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    prescribed_time_ES_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  prescribed_time_ES_M->Sizes.numContStates = (6);/* Number of continuous states */
  prescribed_time_ES_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  prescribed_time_ES_M->Sizes.numY = (0);/* Number of model outputs */
  prescribed_time_ES_M->Sizes.numU = (0);/* Number of model inputs */
  prescribed_time_ES_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  prescribed_time_ES_M->Sizes.numSampTimes = (3);/* Number of sample times */
  prescribed_time_ES_M->Sizes.numBlocks = (66);/* Number of blocks */
  prescribed_time_ES_M->Sizes.numBlockIO = (22);/* Number of block outputs */
  prescribed_time_ES_M->Sizes.numBlockPrms = (28);/* Sum of parameter "widths" */
  return prescribed_time_ES_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
