// repair CurrentCursorTarget;

_object = _this select 0;

if(myjob == "repairman" || myjob == "ems") exitwith { _object setdamage 0; };
/*
if(_object gethit "motor" > 0.9 && _object iskindof "car") exitwith {

	_engines = {_x == "prpg_item_engine_kit"} count magazines player;
	if(_engines > 0) exitwith {
		_object setdamage 0;		
		player removeitem "prpg_item_engine_kit";
		hint "Du hast das RepairKit für den Motor während der Reparatur verbraucht.";
	};
	_repaired = false;
	_checkNear = nearestObjects [player, [], 30];
	{
		if(str _x find "tallerdepinturaabandonado" > -1) exitwith { _object setdamage 0; _repaired = true; };
	}foreach _checkNear;

	if(_repaired) exitwith {};

	hint "Du brauchst ein Motor Kit oder einen Mechaniker.";
};
*/
_wheels = {_x == "prpg_item_wheel_kit"} count magazines player;
if(_wheels > 0) exitwith {
	_object setdamage 0;
	["VehicleRepaired"] spawn mav_ttm_fnc_addExp;
	player removeItem "prpg_item_wheel_kit";
};
hint "Du benötigst ein Rad zum Reparieren.";




