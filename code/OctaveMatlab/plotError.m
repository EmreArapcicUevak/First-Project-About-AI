Data = load('-ascii', '../../data/log.txt');
Data = Data';

close all;

t = linspace(0,1, length(Data));

plot(t,Data, 'r', 'linewidth', 2); grid on; grid minor on;
title('Cost/Error'); ylabel ('Error'); xlabel ('Training %');
set(gca, "fontsize", 15);
