if(isnil "taskrunning") then { taskrunning = false; };

myjob = "EMS";
taskrunning = true;
[] call client_fnc_hudwork;

player setVariable ["coplevel", 1, false];
player setVariable ["ace_medical_medicClass", 2, true];


_items = getunitloadout player;
player setvariable ["lastsave",_items, false];
[] call client_fnc_ChangePolice;
//[] call client_fnc_jobEnd;
