function [fitresult, gof] = createFit(VarName1, VarName2)
%CREATEFIT(VARNAME1,VARNAME2)
%  创建一个拟合。
%
%  要进行 '无标题拟合 1' 拟合的数据:
%      X 输入: 来自 XLS2 的 VarName1
%      Y 输出: 来自 XLS2 的 VarName2
%  输出:
%      fitresult: 表示拟合的拟合对象。
%      gof: 带有拟合优度信息的结构体。
%
%  另请参阅 FIT, CFIT, SFIT.

%  由 MATLAB 于 20-Oct-2023 13:16:57 自动生成


%% 拟合: '无标题拟合 1'。
[xData, yData] = prepareCurveData( VarName1, VarName2 );

% 设置 fittype 和选项。
ft = fittype( 'smoothingspline' );

% 对数据进行模型拟合。
[fitresult, gof] = fit( xData, yData, ft );

% 绘制数据拟合图。
figure( 'Name', '无标题拟合 1' );
h = plot( fitresult, xData, yData );
legend( h, 'VarName2 vs. VarName1', '无标题拟合 1', 'Location', 'NorthEast', 'Interpreter', 'none' );
% 为坐标区加标签
xlabel( 'VarName1', 'Interpreter', 'none' );
ylabel( 'VarName2', 'Interpreter', 'none' );
grid on


