clc; clear;

% Prompt the user to select a .mat file from the "data-logging" directory
[filename, pathname] = uigetfile('./*.mat', 'Select a seeking MAT file');
if isequal(filename, 0)
    disp('User selected Cancel');
    return;
else
    filepath = fullfile(pathname, filename);
end

data = load(filepath);

% Prompt the user to select a .mat file from the "pv-curve-data" directory
[filename, pathname] = uigetfile('./*.mat', 'Select a pv curve MAT file');
if isequal(filename, 0)
    disp('User selected Cancel');
    return;
else
    filepath = fullfile(pathname, filename);
end

data_curve = load(filepath);

%% Raw Data

%Current
c_time = data.current.time;
c_data = data.current.signals.values;

%Voltage
v_time = data.voltage.time;
v_data = data.voltage.signals.values;

%Power
p_time = data.power.time;
p_data = data.power.signals.values;

%Duty Cycle
duty_time = data.raw_duty.time;
duty_data = data.raw_duty.signals.values;


%% Filtered Data

%Filtered Current
f_c_time = data.filtered_current.time;
f_c_data = data.filtered_current.signals.values;

%Filtered Voltage
f_v_time = data.filtered_voltage.time;
f_v_data = data.filtered_voltage.signals.values;

%Filtered Power
f_p_time = data.filtered_power.time;
f_p_data = data.filtered_power.signals.values;

%% PV Curve Data

duty_pv = data_curve.duty.signals.values;
duty_index = [1];

for i = 1:height(duty_pv)
    
    if mod(i, 10) == 0
        duty_index = [duty_index i];
    end
end



power_pv = data_curve.filtered_power.signals.values;




%% Plots

figure(1);
title("Raw Signals vs. Time");

subplot(2, 2, 1); plot(v_time, v_data);
xlabel("Time [s]"); ylabel("Voltage [V]");

subplot(2, 2, 2); plot(c_time, c_data);
xlabel("Time [s]"); ylabel("Current [A]");

subplot(2, 2, 3); plot(p_time, p_data);
xlabel("Time [s]"); ylabel("Power [W]");

subplot(2, 2, 4); plot(duty_time, duty_data*100);
xlabel("Time [s]"); ylabel("Duty Cycle [%]");

figure(2);
title("Filtered Data vs. Time");

subplot(1, 3, 1); plot(f_v_time, f_v_data);
xlabel("Time [s]"); ylabel("Voltage [V]");

subplot(1, 3, 2); plot(f_c_time, f_c_data);
xlabel("Time [s]"); ylabel("Current [A]");

subplot(1, 3, 3); plot(f_p_time, f_p_data);
xlabel("Time [s]"); ylabel("Power [W]");

%% Extremum Seeking Plots

figure(3); 

subplot(1, 3, 1); plot(duty_time, duty_data*100);
title("Duty Cycle");
xlabel("Time [s]"); ylabel("Duty Cycle [%]");

subplot(1, 3, 2); plot(f_p_time, f_p_data);
title("Filtered Solar Panel Power Output");
xlabel("Time [s]"); ylabel("Power [W]");

subplot(1, 3, 3); plot(duty_pv*100, power_pv);
title("Full PV Curve");
xlabel("Duty Cycle [%]"); ylabel("Power [W]");