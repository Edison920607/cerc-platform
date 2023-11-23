figure(3)
hold on
plot3(pos_uav(:,2),pos_uav(:,1),pos_uav(:,3),'LineWidth',1.5,'DisplayName','航迹');
legend();

%航线信息
xp = routedata_NEH(1,:);
yp = routedata_NEH(2,:);
zp = routedata_NEH(3,:);
plot3(yp,xp,zp-mulh0(3),'LineWidth',0.5,'LineStyle','--','marker','*','Markersize',5,'DisplayName','规划航线');
for i = 1:length(xp)
    text(yp(i)+1*(1*randn()-1),xp(i)+1*(1*randn()-1),zp(i)-mulh0(3),num2str(i),'color','red');
end

% set(gca, 'XDir','reverse');
grid on;legend();
xlabel('E/m')
ylabel('N/m')
zlabel('T/m')


