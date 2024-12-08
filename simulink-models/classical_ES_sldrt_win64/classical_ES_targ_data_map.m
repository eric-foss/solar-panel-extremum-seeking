    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (classical_ES_P)
        ;%
            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% classical_ES_P.a
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% classical_ES_P.k
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% classical_ES_P.w
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% classical_ES_P.PWMOutput_Frequency
                    section.data(4).logicalSrcIdx = 5;
                    section.data(4).dtTransOffset = 3;

                    ;% classical_ES_P.AnalogInputs_MaxMissedTicks
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 4;

                    ;% classical_ES_P.PWMOutput_MaxMissedTicks
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 5;

                    ;% classical_ES_P.AnalogInputs_YieldWhenWaiting
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 6;

                    ;% classical_ES_P.PWMOutput_YieldWhenWaiting
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% classical_ES_P.AnalogInputs_Channels
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% classical_ES_P.PWMOutput_Channels
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 2;

                    ;% classical_ES_P.AnalogInputs_RangeMode
                    section.data(3).logicalSrcIdx = 13;
                    section.data(3).dtTransOffset = 3;

                    ;% classical_ES_P.AnalogInputs_VoltRange
                    section.data(4).logicalSrcIdx = 14;
                    section.data(4).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% classical_ES_P.Constant_Value
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

                    ;% classical_ES_P.Integrator_IC
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% classical_ES_P.Gain1_Gain
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% classical_ES_P.Gain2_Gain
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 3;

                    ;% classical_ES_P.CutoffFrequencyrads_Value
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 4;

                    ;% classical_ES_P.Integrator_IC_l
                    section.data(6).logicalSrcIdx = 20;
                    section.data(6).dtTransOffset = 5;

                    ;% classical_ES_P.TransferFcn_A
                    section.data(7).logicalSrcIdx = 21;
                    section.data(7).dtTransOffset = 6;

                    ;% classical_ES_P.TransferFcn_C
                    section.data(8).logicalSrcIdx = 22;
                    section.data(8).dtTransOffset = 7;

                    ;% classical_ES_P.TransferFcn_D
                    section.data(9).logicalSrcIdx = 23;
                    section.data(9).dtTransOffset = 8;

                    ;% classical_ES_P.SineWave1_Bias
                    section.data(10).logicalSrcIdx = 24;
                    section.data(10).dtTransOffset = 9;

                    ;% classical_ES_P.SineWave1_Phase
                    section.data(11).logicalSrcIdx = 25;
                    section.data(11).dtTransOffset = 10;

                    ;% classical_ES_P.SineWave_Bias
                    section.data(12).logicalSrcIdx = 26;
                    section.data(12).dtTransOffset = 11;

                    ;% classical_ES_P.SineWave_Phase
                    section.data(13).logicalSrcIdx = 27;
                    section.data(13).dtTransOffset = 12;

                    ;% classical_ES_P.Integrator_IC_k
                    section.data(14).logicalSrcIdx = 28;
                    section.data(14).dtTransOffset = 13;

                    ;% classical_ES_P.Integrator_IC_e
                    section.data(15).logicalSrcIdx = 29;
                    section.data(15).dtTransOffset = 14;

                    ;% classical_ES_P.Gain_Gain
                    section.data(16).logicalSrcIdx = 30;
                    section.data(16).dtTransOffset = 15;

                    ;% classical_ES_P.Saturation_UpperSat
                    section.data(17).logicalSrcIdx = 31;
                    section.data(17).dtTransOffset = 16;

                    ;% classical_ES_P.Saturation_LowerSat
                    section.data(18).logicalSrcIdx = 32;
                    section.data(18).dtTransOffset = 17;

                    ;% classical_ES_P.TransferFcn1_A
                    section.data(19).logicalSrcIdx = 33;
                    section.data(19).dtTransOffset = 18;

                    ;% classical_ES_P.TransferFcn1_C
                    section.data(20).logicalSrcIdx = 34;
                    section.data(20).dtTransOffset = 19;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (classical_ES_B)
        ;%
            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% classical_ES_B.Product4
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% classical_ES_B.Product
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% classical_ES_B.Product4_j
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% classical_ES_B.Product4_f
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% classical_ES_B.AnalogInputs
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% classical_ES_B.Gain
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 6;

                    ;% classical_ES_B.Product_d
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 7;

                    ;% classical_ES_B.Sum2
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 8;

                    ;% classical_ES_B.Sum2_j
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 9;

                    ;% classical_ES_B.Sum2_b
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 10;

                    ;% classical_ES_B.Sum1
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 11;

                    ;% classical_ES_B.Saturation
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 12;

                    ;% classical_ES_B.TransferFcn1
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 13;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 1;
        sectIdxOffset = 1;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (classical_ES_DW)
        ;%
            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% classical_ES_DW.FilteredCurrent_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% classical_ES_DW.FilteredVoltage_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% classical_ES_DW.InputPowerFiltered_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% classical_ES_DW.AnalogInputs_PWORK
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% classical_ES_DW.RawInputCurrent_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

                    ;% classical_ES_DW.RawInputPower_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 5;

                    ;% classical_ES_DW.RawInputVoltage_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 6;

                    ;% classical_ES_DW.PWMOutput_PWORK
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 7;

                    ;% classical_ES_DW.RawDutyCycle_PWORK.LoggedData
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 8;

                    ;% classical_ES_DW.SaturatedDutyCycle_PWORK.LoggedData
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3895207995;
    targMap.checksum1 = 2227114686;
    targMap.checksum2 = 512526455;
    targMap.checksum3 = 4149387412;

