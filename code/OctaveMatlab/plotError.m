Data = load('-ascii', '../../data/log.txt');
Data = Data';

t = linspace(0,1, length(Data));

plot(t,Data, '--r');
