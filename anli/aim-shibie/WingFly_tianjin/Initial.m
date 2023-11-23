%%�̶���
%%�ñ�����ļ�������cacheFolder�ļ����� 
clear
clc
udp_receive0 = 16000;
udp_send0 = 16001;
currentFolder = pwd;
cfg = Simulink.fileGenControl('getConfig');
cfg.CacheFolder = fullfile(currentFolder,'cacheFolder');
cfg.CodeGenFolder = fullfile(currentFolder,'cacheFolder');
Simulink.fileGenControl('setConfig', 'config', cfg);
cfg = Simulink.fileGenControl('getConfig');

routeNum = 17;
routedata_NEH = zeros(3,30);
%%��ͷ�������
% routedata_NEH(1,1:routeNum) = [0,  0,    0,     1500,  3000, 3000, 3000,    2000, 1000,    0,       0,   0];
% routedata_NEH(2,1:routeNum) = [0,  1000,  2000, 2400,  2000,  0,  -4000,  -4000, -5000,  -4000,   0,   500];
% routedata_NEH(3,1:routeNum) = [0,  0,    100,   100,    100,   100,    100,  100,  80,      50,   0,     0];

% %%��ͷ�������
% routedata_NEH(1,1:routeNum) = [0, 1000, 1500, 1500,  3000, 3000, 3000,  2000,  1000,   0,       0,   0];%����ı�������
% routedata_NEH(2,1:routeNum) = [0, 0,    0,    2400,  2000, 0,    -4000, -4000, -5000,  -4000,   0,   500];%����Ķ�������
% routedata_NEH(3,1:routeNum) = [0, 0,    100,  100,   100,  100,  100,   100,   80,     50,      0,   0];%����ĸ߶�

%%��ͷ�������
routedata_NEH(1,1:routeNum) = [0, 600, 1200,   1200,   0,     0,   600,  1200,  1200,    0,    0,  600,  1200,  1200,    0,  0,    0];%����ı�������
routedata_NEH(2,1:routeNum) = [0,  0,    0,    -400,  -400,   0,    0,    0,    -400,  -400,   0,  0,    0,    -400,  -400,  -200, 0];%����Ķ�������
routedata_NEH(3,1:routeNum) = [0, 100,  200,   200,   200,   200,  200,  200,   200,    200,  200, 200,  200,   200,   200,  100,  0];%����ĸ߶�



Lon0 = 30;Lat0 = 40;Alt0 = 0;
mulh0=[Lat0;Lon0;Alt0];    

figure(2)
plot3(routedata_NEH(1,1:routeNum),routedata_NEH(2,1:routeNum),routedata_NEH(3,1:routeNum),'LineWidth',1,'LineStyle','--','marker','*','Markersize',10);
for i = 1:routeNum
    text(routedata_NEH(1,i)+0.00001*randn(),routedata_NEH(2,i)+0.00001*randn(),routedata_NEH(3,i),num2str(i),'color','red');
end
hold on
% plot3([fenceLL(:,2);fenceLL(1,2)],[fenceLL(:,1);fenceLL(1,1)],zeros(5,1),'marker','*','Markersize',10)  %��Χ��
set(gca, 'XDir','reverse');
grid on
xlabel('Xn/m')
ylabel('Ye/m')
zlabel('�߶�/m')
title('�滮�ĺ���');

%% run simulink model
AFCS_MODEL1