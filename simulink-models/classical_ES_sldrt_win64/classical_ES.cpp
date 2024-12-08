/*
 * classical_ES.cpp
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
#include <cmath>
#include "rtwtypes.h"
#include "classical_ES_private.h"
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "classical_ES_dt.h"

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
B_classical_ES_T classical_ES_B;

/* Continuous states */
X_classical_ES_T classical_ES_X;

/* Disabled State Vector */
XDis_classical_ES_T classical_ES_XDis;

/* Block states (default storage) */
DW_classical_ES_T classical_ES_DW;

/* Real-time model */
RT_MODEL_classical_ES_T classical_ES_M_{ };

RT_MODEL_classical_ES_T *const classical_ES_M{ &classical_ES_M_ };

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
  (classical_ES_M->Timing.TaskCounters.TID[2])++;
  if ((classical_ES_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    classical_ES_M->Timing.TaskCounters.TID[2] = 0;
  }

  classical_ES_M->Timing.sampleHits[2] =
    (classical_ES_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
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
  classical_ES_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  classical_ES_output();
  classical_ES_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  classical_ES_output();
  classical_ES_derivatives();

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

/* Model output function */
void classical_ES_output(void)
{
  real_T Product_tmp;
  real_T Product_tmp_0;
  if (rtmIsMajorTimeStep(classical_ES_M)) {
    /* set solver stop time */
    if (!(classical_ES_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&classical_ES_M->solverInfo,
                            ((classical_ES_M->Timing.clockTickH0 + 1) *
        classical_ES_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&classical_ES_M->solverInfo,
                            ((classical_ES_M->Timing.clockTick0 + 1) *
        classical_ES_M->Timing.stepSize0 + classical_ES_M->Timing.clockTickH0 *
        classical_ES_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(classical_ES_M)) {
    classical_ES_M->Timing.t[0] = rtsiGetT(&classical_ES_M->solverInfo);
  }

  /* Product: '<S5>/Product4' incorporates:
   *  Constant: '<S1>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S5>/Integrator'
   */
  classical_ES_B.Product4 = classical_ES_P.CutoffFrequencyrads_Value *
    classical_ES_X.Integrator_CSTATE_m;

  /* Clock: '<Root>/Clock1' incorporates:
   *  Clock: '<Root>/Clock2'
   */
  Product_tmp = classical_ES_M->Timing.t[0];

  /* Sin: '<Root>/Sine Wave1' incorporates:
   *  Sin: '<Root>/Sine Wave'
   */
  Product_tmp_0 = classical_ES_P.w * classical_ES_M->Timing.t[0];

  /* Product: '<Root>/Product' incorporates:
   *  Clock: '<Root>/Clock1'
   *  Gain: '<Root>/Gain1'
   *  Math: '<Root>/Math Function'
   *  Product: '<Root>/Product1'
   *  Sin: '<Root>/Sine Wave1'
   *  TransferFcn: '<Root>/Transfer Fcn'
   *
   * About '<Root>/Math Function':
   *  Operator: exp
   */
  classical_ES_B.Product = (std::sin(Product_tmp_0 +
    classical_ES_P.SineWave1_Phase) * (2.0 / classical_ES_P.a) +
    classical_ES_P.SineWave1_Bias) * std::exp(classical_ES_P.Gain1_Gain *
    Product_tmp) * (classical_ES_P.TransferFcn_C *
                    classical_ES_X.TransferFcn_CSTATE +
                    classical_ES_P.TransferFcn_D * classical_ES_B.Product4);

  /* Product: '<S7>/Product4' incorporates:
   *  Constant: '<S1>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S7>/Integrator'
   */
  classical_ES_B.Product4_j = classical_ES_P.CutoffFrequencyrads_Value *
    classical_ES_X.Integrator_CSTATE_a;
  if (rtmIsMajorTimeStep(classical_ES_M) &&
      classical_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<S1>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S6>/Integrator'
   */
  classical_ES_B.Product4_f = classical_ES_P.CutoffFrequencyrads_Value *
    classical_ES_X.Integrator_CSTATE_e;
  if (rtmIsMajorTimeStep(classical_ES_M) &&
      classical_ES_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(classical_ES_M) &&
      classical_ES_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtai): '<S1>/Analog Inputs' */
    /* S-Function Block: <S1>/Analog Inputs */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) classical_ES_P.AnalogInputs_RangeMode;
      parm.rangeidx = classical_ES_P.AnalogInputs_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                     classical_ES_P.AnalogInputs_Channels,
                     &classical_ES_B.AnalogInputs[0], &parm);
    }

    /* Gain: '<S1>/Gain' */
    classical_ES_B.Gain = classical_ES_P.Gain_Gain *
      classical_ES_B.AnalogInputs[1];

    /* Product: '<S1>/Product' */
    classical_ES_B.Product_d = classical_ES_B.AnalogInputs[0] *
      classical_ES_B.Gain;
  }

  /* Sum: '<S5>/Sum2' */
  classical_ES_B.Sum2 = classical_ES_B.Product_d - classical_ES_B.Product4;

  /* Sum: '<S6>/Sum2' */
  classical_ES_B.Sum2_j = classical_ES_B.AnalogInputs[0] -
    classical_ES_B.Product4_f;

  /* Sum: '<S7>/Sum2' */
  classical_ES_B.Sum2_b = classical_ES_B.Gain - classical_ES_B.Product4_j;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<Root>/Gain'
   *  Gain: '<Root>/Gain2'
   *  Integrator: '<Root>/Integrator'
   *  Math: '<Root>/Math Function1'
   *  Product: '<Root>/Product2'
   *  Sin: '<Root>/Sine Wave'
   *  Sum: '<Root>/Sum'
   *
   * About '<Root>/Math Function1':
   *  Operator: exp
   */
  classical_ES_B.Sum1 = ((std::sin(Product_tmp_0 + classical_ES_P.SineWave_Phase)
    * classical_ES_P.a + classical_ES_P.SineWave_Bias) * std::exp
    (classical_ES_P.Gain2_Gain * Product_tmp) + classical_ES_P.k *
    classical_ES_X.Integrator_CSTATE) + classical_ES_P.Constant_Value;

  /* Saturate: '<S1>/Saturation' */
  if (classical_ES_B.Sum1 > classical_ES_P.Saturation_UpperSat) {
    /* Saturate: '<S1>/Saturation' */
    classical_ES_B.Saturation = classical_ES_P.Saturation_UpperSat;
  } else if (classical_ES_B.Sum1 < classical_ES_P.Saturation_LowerSat) {
    /* Saturate: '<S1>/Saturation' */
    classical_ES_B.Saturation = classical_ES_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S1>/Saturation' */
    classical_ES_B.Saturation = classical_ES_B.Sum1;
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(classical_ES_M) &&
      classical_ES_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtqo): '<S1>/PWM Output' */
    /* S-Function Block: <S1>/PWM Output */
    {
      {
        RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                       &classical_ES_P.PWMOutput_Channels,
                       &classical_ES_P.PWMOutput_Frequency, ((real_T*)
          (&classical_ES_B.Saturation)));
      }
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  classical_ES_B.TransferFcn1 = classical_ES_P.TransferFcn1_C *
    classical_ES_X.TransferFcn1_CSTATE;
}

/* Model update function */
void classical_ES_update(void)
{
  if (rtmIsMajorTimeStep(classical_ES_M)) {
    rt_ertODEUpdateContinuousStates(&classical_ES_M->solverInfo);
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
  if (!(++classical_ES_M->Timing.clockTick0)) {
    ++classical_ES_M->Timing.clockTickH0;
  }

  classical_ES_M->Timing.t[0] = rtsiGetSolverStopTime
    (&classical_ES_M->solverInfo);

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
    if (!(++classical_ES_M->Timing.clockTick1)) {
      ++classical_ES_M->Timing.clockTickH1;
    }

    classical_ES_M->Timing.t[1] = classical_ES_M->Timing.clockTick1 *
      classical_ES_M->Timing.stepSize1 + classical_ES_M->Timing.clockTickH1 *
      classical_ES_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(classical_ES_M) &&
      classical_ES_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++classical_ES_M->Timing.clockTick2)) {
      ++classical_ES_M->Timing.clockTickH2;
    }

    classical_ES_M->Timing.t[2] = classical_ES_M->Timing.clockTick2 *
      classical_ES_M->Timing.stepSize2 + classical_ES_M->Timing.clockTickH2 *
      classical_ES_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void classical_ES_derivatives(void)
{
  XDot_classical_ES_T *_rtXdot;
  _rtXdot = ((XDot_classical_ES_T *) classical_ES_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = classical_ES_B.TransferFcn1;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = classical_ES_B.Sum2;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = classical_ES_P.TransferFcn_A *
    classical_ES_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += classical_ES_B.Product4;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = classical_ES_B.Sum2_b;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = classical_ES_B.Sum2_j;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = classical_ES_P.TransferFcn1_A *
    classical_ES_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += classical_ES_B.Product;
}

/* Model initialize function */
void classical_ES_initialize(void)
{
  /* Start for S-Function (sldrtqo): '<S1>/PWM Output' */

  /* S-Function Block: <S1>/PWM Output */

  /* no initial value should be set */

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  classical_ES_X.Integrator_CSTATE = classical_ES_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  classical_ES_X.Integrator_CSTATE_m = classical_ES_P.Integrator_IC_l;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  classical_ES_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  classical_ES_X.Integrator_CSTATE_a = classical_ES_P.Integrator_IC_k;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  classical_ES_X.Integrator_CSTATE_e = classical_ES_P.Integrator_IC_e;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  classical_ES_X.TransferFcn1_CSTATE = 0.0;
}

/* Model terminate function */
void classical_ES_terminate(void)
{
  /* Terminate for S-Function (sldrtqo): '<S1>/PWM Output' */

  /* S-Function Block: <S1>/PWM Output */

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
  classical_ES_output();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  classical_ES_update();
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
  classical_ES_initialize();
}

extern "C" void MdlTerminate(void)
{
  classical_ES_terminate();
}

/* Registration function */
extern "C" RT_MODEL_classical_ES_T *classical_ES(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&classical_ES_M->solverInfo,
                          &classical_ES_M->Timing.simTimeStep);
    rtsiSetTPtr(&classical_ES_M->solverInfo, &rtmGetTPtr(classical_ES_M));
    rtsiSetStepSizePtr(&classical_ES_M->solverInfo,
                       &classical_ES_M->Timing.stepSize0);
    rtsiSetdXPtr(&classical_ES_M->solverInfo, &classical_ES_M->derivs);
    rtsiSetContStatesPtr(&classical_ES_M->solverInfo, (real_T **)
                         &classical_ES_M->contStates);
    rtsiSetNumContStatesPtr(&classical_ES_M->solverInfo,
      &classical_ES_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&classical_ES_M->solverInfo,
      &classical_ES_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&classical_ES_M->solverInfo,
      &classical_ES_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&classical_ES_M->solverInfo,
      &classical_ES_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&classical_ES_M->solverInfo, (boolean_T**)
      &classical_ES_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&classical_ES_M->solverInfo, (&rtmGetErrorStatus
      (classical_ES_M)));
    rtsiSetRTModelPtr(&classical_ES_M->solverInfo, classical_ES_M);
  }

  rtsiSetSimTimeStep(&classical_ES_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&classical_ES_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&classical_ES_M->solverInfo, false);
  classical_ES_M->intgData.y = classical_ES_M->odeY;
  classical_ES_M->intgData.f[0] = classical_ES_M->odeF[0];
  classical_ES_M->intgData.f[1] = classical_ES_M->odeF[1];
  classical_ES_M->intgData.f[2] = classical_ES_M->odeF[2];
  classical_ES_M->contStates = ((real_T *) &classical_ES_X);
  classical_ES_M->contStateDisabled = ((boolean_T *) &classical_ES_XDis);
  classical_ES_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&classical_ES_M->solverInfo, static_cast<void *>
                    (&classical_ES_M->intgData));
  rtsiSetSolverName(&classical_ES_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap { classical_ES_M->Timing.sampleTimeTaskIDArray };

    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "classical_ES_M points to
       static memory which is guaranteed to be non-NULL" */
    classical_ES_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    classical_ES_M->Timing.sampleTimes =
      (&classical_ES_M->Timing.sampleTimesArray[0]);
    classical_ES_M->Timing.offsetTimes =
      (&classical_ES_M->Timing.offsetTimesArray[0]);

    /* task periods */
    classical_ES_M->Timing.sampleTimes[0] = (0.0);
    classical_ES_M->Timing.sampleTimes[1] = (0.0001);
    classical_ES_M->Timing.sampleTimes[2] = (0.001);

    /* task offsets */
    classical_ES_M->Timing.offsetTimes[0] = (0.0);
    classical_ES_M->Timing.offsetTimes[1] = (0.0);
    classical_ES_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(classical_ES_M, &classical_ES_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits{ classical_ES_M->Timing.sampleHitArray };

    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    classical_ES_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(classical_ES_M, 30.0);
  classical_ES_M->Timing.stepSize0 = 0.0001;
  classical_ES_M->Timing.stepSize1 = 0.0001;
  classical_ES_M->Timing.stepSize2 = 0.001;

  /* External mode info */
  classical_ES_M->Sizes.checksums[0] = (3895207995U);
  classical_ES_M->Sizes.checksums[1] = (2227114686U);
  classical_ES_M->Sizes.checksums[2] = (512526455U);
  classical_ES_M->Sizes.checksums[3] = (4149387412U);

  {
    static const sysRanDType rtAlwaysEnabled{ SUBSYS_RAN_BC_ENABLE };

    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    classical_ES_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(classical_ES_M->extModeInfo,
      &classical_ES_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(classical_ES_M->extModeInfo,
                        classical_ES_M->Sizes.checksums);
    rteiSetTPtr(classical_ES_M->extModeInfo, rtmGetTPtr(classical_ES_M));
  }

  classical_ES_M->solverInfoPtr = (&classical_ES_M->solverInfo);
  classical_ES_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&classical_ES_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&classical_ES_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  classical_ES_M->blockIO = ((void *) &classical_ES_B);
  (void) std::memset((static_cast<void *>(&classical_ES_B)), 0,
                     sizeof(B_classical_ES_T));

  /* parameters */
  classical_ES_M->defaultParam = ((real_T *)&classical_ES_P);

  /* states (continuous) */
  {
    real_T *x{ (real_T *) &classical_ES_X };

    classical_ES_M->contStates = (x);
    (void) std::memset(static_cast<void *>(&classical_ES_X), 0,
                       sizeof(X_classical_ES_T));
  }

  /* disabled states */
  {
    boolean_T *xdis{ (boolean_T *) &classical_ES_XDis };

    classical_ES_M->contStateDisabled = (xdis);
    (void) std::memset(static_cast<void *>(&classical_ES_XDis), 0,
                       sizeof(XDis_classical_ES_T));
  }

  /* states (dwork) */
  classical_ES_M->dwork = ((void *) &classical_ES_DW);
  (void) std::memset(static_cast<void *>(&classical_ES_DW), 0,
                     sizeof(DW_classical_ES_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    classical_ES_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  classical_ES_M->Sizes.numContStates = (6);/* Number of continuous states */
  classical_ES_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  classical_ES_M->Sizes.numY = (0);    /* Number of model outputs */
  classical_ES_M->Sizes.numU = (0);    /* Number of model inputs */
  classical_ES_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  classical_ES_M->Sizes.numSampTimes = (3);/* Number of sample times */
  classical_ES_M->Sizes.numBlocks = (41);/* Number of blocks */
  classical_ES_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  classical_ES_M->Sizes.numBlockPrms = (33);/* Sum of parameter "widths" */
  return classical_ES_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
