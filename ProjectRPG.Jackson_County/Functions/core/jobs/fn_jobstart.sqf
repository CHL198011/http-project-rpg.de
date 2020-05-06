_player = _this select 0;
_jobtype = _this select 1;

//[player,objNull,3,format ["%1 fing an als %2 zu Arbeiten.", name player, _jobtype],_jobtype] remoteExec ["server_fnc_jobLog", 2];
if (str _jobtype find "Cop" > -1 || str _jobtype == "Cop") exitwith {
	[_player, getUnitLoadout _player] remoteexec ["Server_fnc_statSave",2];	
	[] call client_fnc_startCop;
	currentCop pushback getplayerUid _player;
	publicvariable "currentCop";
	["highthreat"] spawn client_fnc_setGear;
	//[player,objNull,10,format ["%1 begann seinen Polizeidienst", name player],""] remoteExec ["server_fnc_copLog", 2];
};

if (str _jobtype find "EMS" > -1 || str _jobtype == "EMS") exitwith {
	[_player, getUnitLoadout _player] remoteexec ["Server_fnc_statSave",2];		
	[] call client_fnc_startEMS;
	currentEMS pushback getplayerUid _player;
	publicvariable "currentEMS";
	["basic"] spawn client_fnc_setGear;
};

if (str _jobtype find "Fire" > -1 || str _jobtype == "Fire") exitwith {
	[_player, getUnitLoadout _player] remoteexec ["Server_fnc_statSave",2];		
	[] call client_fnc_startFire;
	currentFire pushback getplayerUid _player;
	publicvariable "currentFire";	
	["basic"] spawn client_fnc_setGear;
};

if (str _jobtype find "Mafia" > -1 || str _jobtype == "Mafia") exitwith {
	[] call client_fnc_startMafia;
	currentMafia pushback getplayerUid _player;
	publicvariable "currentMafia";
};

if(str _jobtype find "doughnuts" > -1 || str _jobtype == "doughnuts") exitWith {
	[] call client_fnc_startDoughnuts;
	currentDoughnuts pushback getplayerUid _player;
	publicVariable "currentDoughnuts";
};

if (str _jobtype find "Police Dispatch" > -1 || str _jobtype == "Police Dispatch") exitwith {   
	[] call client_fnc_startDispatch;
	currentPoliceDispatch pushback getplayerUid _player;
	publicvariable "currentPoliceDispatch";
};

if (str _jobtype find "Medic Dispatch" > -1 || str _jobtype == "Medic Dispatch") exitwith {
	[] call client_fnc_startDispatch;
	currentMedicDispatch pushback getplayerUid _player;
	publicvariable "currentMedicDispatch";	
};

if (str _jobtype find "Fire Dispatch" > -1 || str _jobtype == "Fire Dispatch") exitwith {
	[] call client_fnc_startDispatch;
	currentFireDispatch pushback getplayerUid _player;
	publicvariable "currentFireDispatch";	
};

if (str _jobtype find "mail" > -1 || str _jobtype == "mail") exitwith {
	[] call client_fnc_mailSystem;
	currentMailmen pushback getplayerUid _player;
	publicvariable "currentMailmen";	
};

if (str _jobtype find "taxi" > -1 || str _jobtype == "taxi") exitwith {
	[] call client_fnc_startTaxi;
	currentTaxiDrivers pushback getplayerUid _player;
	publicvariable "currentTaxiDrivers";
};

if (str _jobtype find "security" > -1 || str _jobtype == "security") exitwith {
	[] call client_fnc_startSecurity;
	currentsecurity pushback getplayerUid _player;
	publicvariable "currentSecurity";	
};

if (str _jobtype find "Legal Aid" > -1 || str _jobtype == "Legal Aid") exitwith {
	[] call client_fnc_startLegalAid;
	currentlegalaid pushback getplayerUid _player;
	publicvariable "currentLegalAid";	
};

if (str _jobtype find "Lawyer" > -1  || str _jobtype == "Lawyer") exitwith {
	[] call client_fnc_startLawyer;
	currentlawyers pushback getplayerUid _player;
	publicvariable "currentLawyers";
};

if (str _jobtype find "Judge" > -1  || str _jobtype == "Judge") exitwith {
	[] call client_fnc_startJudge;	
	currentJudges pushback getplayerUid _player;
	publicvariable "currentJudges";
};

if (str _jobtype find "Prosecutor" > -1  || str _jobtype == "Prosecutor") exitwith {
	[] call client_fnc_startProsecutor;	
	currentProsecutor pushback getplayerUid _player;
	publicvariable "currentProsecutor";
};

if (str _jobtype find "Tow Truck Driver" > -1  || str _jobtype == "Tow Truck Driver") exitwith {
	[] call client_fnc_startTowTruck;
	currentTowTruckDrivers pushback getplayerUid _player;
	publicvariable "currentTowTruckDrivers";
};

if (str _jobtype find "trashman" > -1 || str _jobtype == "trashman") exitwith {
	[] call client_fnc_startGarbage;
	currentTrashMan pushback getplayerUid _player;
	publicvariable "currentTrashman";	
};

if (str _jobtype find "reporter" > -1 || str _jobtype == "reporter") exitwith {
	[] call client_fnc_startNews;	
	currentNewsMan pushback getplayerUid _player;
	publicvariable "currentNewsMan";
};

if (str _jobtype find "repairman" > -1 || str _jobtype == "repairman") exitwith {	
	[] call client_fnc_startRepair;
	currentRepairmen pushback getplayerUid _player;
	publicvariable "currentRepairmen";	
};

if (str _jobtype find "pizza" > -1 || str _jobtype == "pizza") exitwith {	
	[] call client_fnc_startPizza;
	currentPizzaFicker pushback getplayerUid _player;
	publicvariable "currentPizzaFicker";	
};

if (str _jobtype find "busdriver" > -1 || str _jobtype == "busdriver") exitwith {	
	[] call client_fnc_startbusding;
	currentdimis pushback getplayerUid _player;
	publicvariable "currentdimis";	
};