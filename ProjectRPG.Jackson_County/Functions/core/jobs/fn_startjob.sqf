disableSerialization;
if(!dialog) then {	createdialog "job_update"; };
uisleep 0.05;
_display = findDisplay 9999;
_list = _display displayCtrl 9001;
lbClear _list;
_i = 0;
{
	if(isPlayer _x) then {
		_i = _i + 1;
	};
} forEach playableUnits;
_count = [2,2,2,2,4,4,2,2,2];
if(_i > 50) then {
	if(_i > 80) then {
		_count = [4,6,4,5,6,6,3,3,3];
	} else {
		_count = [4,6,4,5,6,6,3,3,3];
	};
};

_jobs = [];

if(count currentMailmen < (_count select 0)) then {
_Jobs pushback ["Fedex Kurier","mail"]; 
};

if(count currentSecurity < (_count select 1)) then {
_Jobs pushback ["Security","security"]; 
};

if(count currentTrashman < (_count select 2)) then {
_Jobs pushback ["Müllabfuhr","trashman"]; 
};

if(count currentNewsMan < (_count select 3)) then {
_Jobs pushback ["Reporter","reporter"]; 
};

if(count currentRepairmen < (_count select 4)) then {
_Jobs pushback ["Mechaniker","repairman"]; 
};

if(count currentTaxiDrivers < (_count select 5)) then {
_Jobs pushback ["Taxifahrer","taxi"]; 
};

if(count currentPizzaFicker < (_count select 6)) then {
_Jobs pushback ["Pizza Lieferant","pizza"]; 
};

if(count currentTowTruckDrivers < (_count select 7)) then {
_Jobs pushback ["Abschlepper","Tow Truck Driver"]; 
};
/*
if(count currentdimis < (_count select 8)) then {
_Jobs pushback ["Busfahrer","busdriver"]; 
};
*/


if(_jobs isequalto []) then { _jobs = ["Keine Arbeit verfügbar"]; };

{
	_list lbAdd format["Arbeit: %1",_x select 0];
	_list lbSetdata [(lbSize _list)-1,str(_x select 1)];
} foreach _jobs;

_list lbAdd "Arbeit: Holzfäller";
_job = "Wood Logging";
_list lbSetdata [(lbSize _list)-1,str(_job)];

hint "Die meisten Firmen stellen dir ein Firmenwagen zur Verfügung. Verwende die Interaktionstaste und wähle die entsprechende Option aus.";

