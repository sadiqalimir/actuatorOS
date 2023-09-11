TunedBlocks = {'Current PID','Speed PID'};
tLinearize = 0.5;  % linearize at t=0.5

TunedBlocks = {'Current PID','Speed PID'};
tLinearize = 0.5;  % linearize at t=0.5


TR = TuningGoal.Tracking('Speed Demand (rpm)','rpm',0.1);

ST1 = systune(ST0,TR);

T1 = getIOTransfer(ST1,'Speed Demand (rpm)',{'rpm','i'});
figure
step(T1,0.5)

writeBlockValue(ST1)

addPoint(ST0,'Current PID')

MG = TuningGoal.Gain('Speed Demand (rpm)','Current PID',0.001);

figure('Position',[100,100,560,550])
viewGoal([TR,MG],ST2)

T2 = getIOTransfer(ST2,'Speed Demand (rpm)',{'rpm','i'});
figure
step(T1,'b',T2,'g--',0.4)
legend('Initial tuning','Tuning with Gain Constraint')

showTunable(ST1)  % initial tuning

showTunable(ST2)  % retuning

writeBlockValue(ST2)

