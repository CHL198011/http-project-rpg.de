if(myjob != "none") exitwith { hint "Du hast schon einen Job!"; };

if(isnil "taskrunning") then { taskrunning = false; };

myjob = "Prosecutor";
[] call client_fnc_hudwork;
private ["_warning","_JobBase"];
if(!taskrunning) then {

	[] spawn {
		playertasks = [];
		taskrunning = true;

		_warnings = 0;
		while{taskrunning && myjob == "Prosecutor"} do {
			uisleep 180;
			paycheck = paycheck + 180;
		};
		if(myjob == "Prosecutor") then { [] call client_fnc_jobEnd; };
	};
};
player setVariable ["coplevel", 1, false];