if (myjob in ["Mafia"]) then {
	_veh = _this select 0;
	_player = _this select 1;
	if (isNil "_veh") exitwith {};
	_tracker1 = (_veh getVariable["tracker1",true]);
	_tracker2 = (_veh getVariable["tracker2",true]);
	_tracker3 = (_veh getVariable["tracker3",true]);
	_exit = false;

	if (player == _tracker1 || player == _tracker2 || player == _tracker3) exitwith {hint "Sie verfolgen dieses Fahrzeug bereits";};


	player playmove "AinvPknlMstpSnonWnonDnon_medic_1";

	_veh setvariable ["tracking",true,false];

	if (isNull _tracker1) then
	{
		_veh setvariable ["tracker1",_player,true];
	} else { if (isNull _tracker2) then
		{
		_veh setvariable ["tracker2",_player,true];
		}else {	if (isNull _tracker3) then
			{
			_veh setvariable ["tracker3",_player,true];
			} else {_exit = true;};};};



	if (_exit) exitwith {hint "Sie können maximal 3 Tracker anbringen!";};

	sleep 5;
	hint "Tracker angebracht";

	if (myjob == "cop") then {
		[player,objnull,15,format ["%1 Plaziert eine Wanze", name player],""] remoteExec ["server_fnc_copLog", 2];
	};

} else {
	hint "Ich bin nicht in der Mafia, ich kann keine Wanzen platzieren!";
};
