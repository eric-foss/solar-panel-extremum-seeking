/*
 * PV_curve.cpp
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
#include "rtwtypes.h"
#include "PV_curve_private.h"
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "PV_curve_dt.h"

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
B_PV_curve_T PV_curve_B;

/* Continuous states */
X_PV_curve_T PV_curve_X;

/* Disabled State Vector */
XDis_PV_curve_T PV_curve_XDis;

/* Block states (default storage) */
DW_PV_curve_T PV_curve_DW;

/* Real-time model */
RT_MODEL_PV_curve_T PV_curve_M_{ };

RT_MODEL_PV_curve_T *const PV_curve_M{ &PV_curve_M_ };

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
  (PV_curve_M->Timing.TaskCounters.TID[2])++;
  if ((PV_curve_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    PV_curve_M->Timing.TaskCounters.TID[2] = 0;
  }

  PV_curve_M->Timing.sampleHits[2] = (PV_curve_M->Timing.TaskCounters.TID[2] ==
    0) ? 1 : 0;
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
  int_T nXc { 3 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PV_curve_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PV_curve_output();
  PV_curve_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PV_curve_output();
  PV_curve_derivatives();

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
void PV_curve_output(void)
{
  real_T tmp;
  if (rtmIsMajorTimeStep(PV_curve_M)) {
    /* set solver stop time */
    if (!(PV_curve_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PV_curve_M->solverInfo,
                            ((PV_curve_M->Timing.clockTickH0 + 1) *
        PV_curve_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PV_curve_M->solverInfo,
                            ((PV_curve_M->Timing.clockTick0 + 1) *
        PV_curve_M->Timing.stepSize0 + PV_curve_M->Timing.clockTickH0 *
        PV_curve_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PV_curve_M)) {
    PV_curve_M->Timing.t[0] = rtsiGetT(&PV_curve_M->solverInfo);
  }

  /* Product: '<S7>/Product4' incorporates:
   *  Constant: '<Root>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S7>/Integrator'
   */
  PV_curve_B.Product4 = PV_curve_P.CutoffFrequencyrads_Value *
    PV_curve_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S6>/Product4' incorporates:
   *  Constant: '<Root>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S6>/Integrator'
   */
  PV_curve_B.Product4_c = PV_curve_P.CutoffFrequencyrads_Value *
    PV_curve_X.Integrator_CSTATE_d;
  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Product: '<S5>/Product4' incorporates:
   *  Constant: '<Root>/Cutoff Frequency [rad//s]'
   *  Integrator: '<S5>/Integrator'
   */
  PV_curve_B.Product4_f = PV_curve_P.CutoffFrequencyrads_Value *
    PV_curve_X.Integrator_CSTATE_h;
  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[1] == 0) {
  }

  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[2] == 0) {
    /* S-Function (sldrtai): '<Root>/Analog Inputs' */
    /* S-Function Block: <Root>/Analog Inputs */
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) PV_curve_P.AnalogInputs_RangeMode;
      parm.rangeidx = PV_curve_P.AnalogInputs_VoltRange;
      RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2, PV_curve_P.AnalogInputs_Channels,
                     &PV_curve_B.AnalogInputs[0], &parm);
    }

    /* Gain: '<Root>/Gain' */
    PV_curve_B.Gain = PV_curve_P.Gain_Gain * PV_curve_B.AnalogInputs[1];

    /* Product: '<Root>/Product' */
    PV_curve_B.Product = PV_curve_B.AnalogInputs[0] * PV_curve_B.Gain;
  }

  /* Sum: '<S5>/Sum2' */
  PV_curve_B.Sum2 = PV_curve_B.Product - PV_curve_B.Product4_f;

  /* Sum: '<S6>/Sum2' */
  PV_curve_B.Sum2_d = PV_curve_B.AnalogInputs[0] - PV_curve_B.Product4_c;

  /* Sum: '<S7>/Sum2' */
  PV_curve_B.Sum2_n = PV_curve_B.Gain - PV_curve_B.Product4;

  /* Step: '<S1>/Step' */
  if (PV_curve_M->Timing.t[0] < PV_curve_P.DutyCycleRamp_start) {
    tmp = PV_curve_P.Step_Y0;
  } else {
    tmp = PV_curve_P.DutyCycleRamp_slope;
  }

  /* Sum: '<S1>/Output' incorporates:
   *  Clock: '<S1>/Clock'
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Product: '<S1>/Product'
   *  Step: '<S1>/Step'
   *  Sum: '<S1>/Sum'
   */
  PV_curve_B.Output = (PV_curve_M->Timing.t[0] - PV_curve_P.DutyCycleRamp_start)
    * tmp + PV_curve_P.DutyCycleRamp_InitialOutput;
  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[1] == 0) {
  }

  /* Saturate: '<Root>/Saturation' */
  if (PV_curve_B.Output > PV_curve_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    PV_curve_B.Saturation = PV_curve_P.Saturation_UpperSat;
  } else if (PV_curve_B.Output < PV_curve_P.Saturation_LowerSat) {
    /* Saturate: '<Root>/Saturation' */
    PV_curve_B.Saturation = PV_curve_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    PV_curve_B.Saturation = PV_curve_B.Output;
  }

  /* End of Saturate: '<Root>/Saturation' */
  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtqo): '<Root>/PWM Output' */
    /* S-Function Block: <Root>/PWM Output */
    {
      {
        RTBIO_DriverIO(0, FREQUENCYOUTPUT, IOWRITE, 1,
                       &PV_curve_P.PWMOutput_Channels,
                       &PV_curve_P.PWMOutput_Frequency, ((real_T*)
          (&PV_curve_B.Saturation)));
      }
    }
  }
}

/* Model update function */
void PV_curve_update(void)
{
  if (rtmIsMajorTimeStep(PV_curve_M)) {
    rt_ertODEUpdateContinuousStates(&PV_curve_M->solverInfo);
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
  if (!(++PV_curve_M->Timing.clockTick0)) {
    ++PV_curve_M->Timing.clockTickH0;
  }

  PV_curve_M->Timing.t[0] = rtsiGetSolverStopTime(&PV_curve_M->solverInfo);

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
    if (!(++PV_curve_M->Timing.clockTick1)) {
      ++PV_curve_M->Timing.clockTickH1;
    }

    PV_curve_M->Timing.t[1] = PV_curve_M->Timing.clockTick1 *
      PV_curve_M->Timing.stepSize1 + PV_curve_M->Timing.clockTickH1 *
      PV_curve_M->Timing.stepSize1 * 4294967296.0;
  }

  if (rtmIsMajorTimeStep(PV_curve_M) &&
      PV_curve_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PV_curve_M->Timing.clockTick2)) {
      ++PV_curve_M->Timing.clockTickH2;
    }

    PV_curve_M->Timing.t[2] = PV_curve_M->Timing.clockTick2 *
      PV_curve_M->Timing.stepSize2 + PV_curve_M->Timing.clockTickH2 *
      PV_curve_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void PV_curve_derivatives(void)
{
  XDot_PV_curve_T *_rtXdot;
  _rtXdot = ((XDot_PV_curve_T *) PV_curve_M->derivs);

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = PV_curve_B.Sum2_n;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = PV_curve_B.Sum2_d;

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = PV_curve_B.Sum2;
}

/* Model initialize function */
void PV_curve_initialize(void)
{
  /* Start for S-Function (sldrtqo): '<Root>/PWM Output' */

  /* S-Function Block: <Root>/PWM Output */

  /* no initial value should be set */

  /* InitializeConditions for Integrator: '<S7>/Integrator' */
  PV_curve_X.Integrator_CSTATE = PV_curve_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  PV_curve_X.Integrator_CSTATE_d = PV_curve_P.Integrator_IC_e;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  PV_curve_X.Integrator_CSTATE_h = PV_curve_P.Integrator_IC_d;
}

/* Model terminate function */
void PV_curve_terminate(void)
{
  /* Terminate for S-Function (sldrtqo): '<Root>/PWM Output' */

  /* S-Function Block: <Root>/PWM Output */

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
  PV_curve_output();
  UNUSED_PARAMETER(tid);
}

extern "C" void MdlUpdate(int_T tid)
{
  PV_curve_update();
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
  PV_curve_initialize();
}

extern "C" void MdlTerminate(void)
{
  PV_curve_terminate();
}

/* Registration function */
extern "C" RT_MODEL_PV_curve_T *PV_curve(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PV_curve_M->solverInfo,
                          &PV_curve_M->Timing.simTimeStep);
    rtsiSetTPtr(&PV_curve_M->solverInfo, &rtmGetTPtr(PV_curve_M));
    rtsiSetStepSizePtr(&PV_curve_M->solverInfo, &PV_curve_M->Timing.stepSize0);
    rtsiSetdXPtr(&PV_curve_M->solverInfo, &PV_curve_M->derivs);
    rtsiSetContStatesPtr(&PV_curve_M->solverInfo, (real_T **)
                         &PV_curve_M->contStates);
    rtsiSetNumContStatesPtr(&PV_curve_M->solverInfo,
      &PV_curve_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PV_curve_M->solverInfo,
      &PV_curve_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PV_curve_M->solverInfo,
      &PV_curve_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PV_curve_M->solverInfo,
      &PV_curve_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PV_curve_M->solverInfo, (boolean_T**)
      &PV_curve_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PV_curve_M->solverInfo, (&rtmGetErrorStatus
      (PV_curve_M)));
    rtsiSetRTModelPtr(&PV_curve_M->solverInfo, PV_curve_M);
  }

  rtsiSetSimTimeStep(&PV_curve_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PV_curve_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PV_curve_M->solverInfo, false);
  PV_curve_M->intgData.y = PV_curve_M->odeY;
  PV_curve_M->intgData.f[0] = PV_curve_M->odeF[0];
  PV_curve_M->intgData.f[1] = PV_curve_M->odeF[1];
  PV_curve_M->intgData.f[2] = PV_curve_M->odeF[2];
  PV_curve_M->contStates = ((real_T *) &PV_curve_X);
  PV_curve_M->contStateDisabled = ((boolean_T *) &PV_curve_XDis);
  PV_curve_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&PV_curve_M->solverInfo, static_cast<void *>
                    (&PV_curve_M->intgData));
  rtsiSetSolverName(&PV_curve_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap { PV_curve_M->Timing.sampleTimeTaskIDArray };

    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "PV_curve_M points to
       static memory which is guaranteed to be non-NULL" */
    PV_curve_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PV_curve_M->Timing.sampleTimes = (&PV_curve_M->Timing.sampleTimesArray[0]);
    PV_curve_M->Timing.offsetTimes = (&PV_curve_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PV_curve_M->Timing.sampleTimes[0] = (0.0);
    PV_curve_M->Timing.sampleTimes[1] = (0.0001);
    PV_curve_M->Timing.sampleTimes[2] = (0.001);

    /* task offsets */
    PV_curve_M->Timing.offsetTimes[0] = (0.0);
    PV_curve_M->Timing.offsetTimes[1] = (0.0);
    PV_curve_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(PV_curve_M, &PV_curve_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits{ PV_curve_M->Timing.sampleHitArray };

    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    PV_curve_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PV_curve_M, 10.0);
  PV_curve_M->Timing.stepSize0 = 0.0001;
  PV_curve_M->Timing.stepSize1 = 0.0001;
  PV_curve_M->Timing.stepSize2 = 0.001;

  /* External mode info */
  PV_curve_M->Sizes.checksums[0] = (3270267195U);
  PV_curve_M->Sizes.checksums[1] = (3051656788U);
  PV_curve_M->Sizes.checksums[2] = (2308355862U);
  PV_curve_M->Sizes.checksums[3] = (1559709037U);

  {
    static const sysRanDType rtAlwaysEnabled{ SUBSYS_RAN_BC_ENABLE };

    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    PV_curve_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PV_curve_M->extModeInfo,
      &PV_curve_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PV_curve_M->extModeInfo, PV_curve_M->Sizes.checksums);
    rteiSetTPtr(PV_curve_M->extModeInfo, rtmGetTPtr(PV_curve_M));
  }

  PV_curve_M->solverInfoPtr = (&PV_curve_M->solverInfo);
  PV_curve_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&PV_curve_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&PV_curve_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PV_curve_M->blockIO = ((void *) &PV_curve_B);
  (void) std::memset((static_cast<void *>(&PV_curve_B)), 0,
                     sizeof(B_PV_curve_T));

  /* parameters */
  PV_curve_M->defaultParam = ((real_T *)&PV_curve_P);

  /* states (continuous) */
  {
    real_T *x{ (real_T *) &PV_curve_X };

    PV_curve_M->contStates = (x);
    (void) std::memset(static_cast<void *>(&PV_curve_X), 0,
                       sizeof(X_PV_curve_T));
  }

  /* disabled states */
  {
    boolean_T *xdis{ (boolean_T *) &PV_curve_XDis };

    PV_curve_M->contStateDisabled = (xdis);
    (void) std::memset(static_cast<void *>(&PV_curve_XDis), 0,
                       sizeof(XDis_PV_curve_T));
  }

  /* states (dwork) */
  PV_curve_M->dwork = ((void *) &PV_curve_DW);
  (void) std::memset(static_cast<void *>(&PV_curve_DW), 0,
                     sizeof(DW_PV_curve_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    PV_curve_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  PV_curve_M->Sizes.numContStates = (3);/* Number of continuous states */
  PV_curve_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  PV_curve_M->Sizes.numY = (0);        /* Number of model outputs */
  PV_curve_M->Sizes.numU = (0);        /* Number of model inputs */
  PV_curve_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PV_curve_M->Sizes.numSampTimes = (3);/* Number of sample times */
  PV_curve_M->Sizes.numBlocks = (29);  /* Number of blocks */
  PV_curve_M->Sizes.numBlockIO = (11); /* Number of block outputs */
  PV_curve_M->Sizes.numBlockPrms = (21);/* Sum of parameter "widths" */
  return PV_curve_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
