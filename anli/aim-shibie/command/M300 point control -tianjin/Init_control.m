%%%  PosCtrl_tune
clear
path('./icon/',path);
Init;

%UDP
udp_receive0 = 15000;%%M300_00的接收控制指令端口与com-M300-pub.py中的localreceive0保持一致
udp_send0 = 15001;%%M300_00的发送位姿信息端口与com-M300-sub.py中的localsend0保持一致
udp_data0 = 15100;%%M300_00的数据
udp_receive1 = 15002;
udp_send1 = 15003;
udp_receive2 = 15004;
udp_send2 = 15005;

% constant value
RAD2DEG = 57.2957795;
DEG2RAD = 0.0174533;
% throttle when UAV is hovering
THR_HOVER = 0.609;
%% Initial condition
ModelInit_PosE = [0, 0, 0];
ModelInit_VelB = [0, 0, 0];
ModelInit_AngEuler = [0, 0, 0];
ModelInit_RateB = [0, 0, 0];
ModelInit_Rads = 557.142;

%% control parameter
% attitude PID parameters
Kp_PITCH_ANGLE = 6.5;
Kp_PITCH_AngleRate = 0.1;
Ki_PITCH_AngleRate = 0.02;
Kd_PITCH_AngleRate = 0.001;
Kp_ROLL_ANGLE = 6.5;
Kp_ROLL_AngleRate = 0.1;
Ki_ROLL_AngleRate = 0.02;
Kd_ROLL_AngleRate = 0.001;
Kp_YAW_AngleRate = 0.5;
Ki_YAW_AngleRate = 0.01;
Kd_YAW_AngleRate = 0.00;
% position PID parameters
Kpxp = 1.0;
Kpyp = 1.0;
Kpzp = 4.0;
Kvxp = 2.5; Kvxi = 0.4; Kvxd = 0.01;
Kvyp = 2.5; Kvyi = 0.4; Kvyd = 0.01;
Kvzp = 0.45; Kvzi = 0.01; Kvzd = 0.005;
% integral saturation
Saturation_I_RP_Max = 0.3;
Saturation_I_RP_Min = -0.3;
Saturation_I_Y_Max = 0.2;
Saturation_I_Y_Min = -0.2;
Saturation_I_ah = 3.43;
Saturation_I_az = 5;

% max control angle,default 35deg
MAX_CONTROL_ANGLE_ROLL = 35;
MAX_CONTROL_ANGLE_PITCH  = 35;
% max control angle rate,rad/s 
MAX_CONTROL_ANGLE_RATE_PITCH = 220;
MAX_CONTROL_ANGLE_RATE_ROLL = 220;
MAX_CONTROL_ANGLE_RATE_Y = 200;
% max control speed, m/s
MAX_CONTROL_VELOCITY_XY = 18;
MAX_CONTROL_VELOCITY_Z = 3;  %5
% throttle amplitude
MAX_MAN_THR = 0.9;
MIN_MAN_THR = 0.05;
%% run simulink model
PosCtrl_tune
%set_param('PosCtrl_tune','SimulationCommand','start')
