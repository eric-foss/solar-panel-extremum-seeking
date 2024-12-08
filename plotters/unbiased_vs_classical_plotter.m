clc; clear;

% Prompt the user to select a .mat file from the "data-logging" directory
[filename, pathname] = uigetfile('../../data/*.mat', 'Select an unbiased seeking MAT file');
if isequal(filename, 0)
    disp('User selected Cancel');
    return;
else
    filepath = fullfile(pathname, filename);
end

unbiased_data = load(filepath);

% Prompt the user to select a .mat file from the "data-logging" directory
[filename, pathname] = uigetfile('../../data/*.mat', 'Select a classical seeking MAT file');
if isequal(filename, 0)
    disp('User selected Cancel');
    return;
else
    filepath = fullfile(pathname, filename);
end

classical_data = load(filepath);

% Prompt the user to select a .mat file from the "pv-curve-data" directory
[filename, pathname] = uigetfile('../../data/*.mat', 'Select a pv curve MAT file');
if isequal(filename, 0)
    disp('User selected Cancel');
    return;
else
    filepath = fullfile(pathname, filename);
end

curve_data = load(filepath);


%% 

%Unbiased Data Parsing
ub_duty = unbiased_data.raw_duty.signals.values;
ub_time = unbiased_data.filtered_power.time;
ub_power = unbiased_data.filtered_power.signals.values;
ub_power_uf = unbiased_data.power.signals.values;

%Classical Data Parsing
c_duty = classical_data.raw_duty.signals.values;
c_time = classical_data.filtered_power.time;
c_power = classical_data.filtered_power.signals.values;
c_power_uf = classical_data.power.signals.values;

%PV Curve Data Parsing
pv_duty = curve_data.duty.signals.values;
pv_power = curve_data.filtered_power.signals.values;
pv_power_uf = curve_data.power.signals.values;

% Filtered Extrema
[max_power, max_index] = max(pv_power);
max_power = max_power*ones(size(c_time));
max_duty = pv_duty(max_index);
max_duty = max_duty*ones(size(c_time));

%Unfiltered Extrema


%%PLOTS
%PV Plot
figure(1);
hold on;
title("Solar Panel Power Output vs. Applied PWM Duty Cycle");
plot(pv_duty*100, pv_power, '-r');
xlabel("Duty Cycle [%]"); ylabel("Power [W]");

%Real Time Filtered Plot
figure(2);
hold on;
title("Filtered Power Ouput of Classical vs. Unbiased Extremum Seeking")
plot(ub_time, ub_power, '-g'); 
plot(c_time, c_power, '--b');
plot(c_time, max_power, ':r');
xlabel("Time [s]"); ylabel("Power [W]");
legend("Unbiased", "Classical", "Maximum", "Location", "Southeast");

% Duty Plot
figure(3);
hold on;
title("Applied Duty Cycle of Classical vs. Unbiased Extremum Seeking");
plot(ub_time, ub_duty*100, '-g');
plot(c_time, c_duty*100, '--b');
plot(c_time, max_duty*100, ':r');
xlabel("Time [s]"); ylabel("Duty Cycle [%]");
legend("Unbiased", "Classical", "Maximum");


span = c_time(end);
time_uf = linspace(0, span, 1000*span+1)';
% Unfiltered Plot
figure(4);
hold on;
title("Unfiltered Power Output of Classical vs. Unbiased EXtremum Seeking");
plot(time_uf, ub_power_uf, '-g');
plot(time_uf, c_power_uf, '--b');
plot(c_time, max_power, ':r');
xlabel("Time [s]"); ylabel("Power [W]");
legend("Unbiased", "Classical", "Maximum", "Location", "Southeast");
ylim([0 7.5]);