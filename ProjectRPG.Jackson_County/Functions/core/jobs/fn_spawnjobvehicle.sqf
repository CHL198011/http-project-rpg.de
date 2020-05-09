if(!taskrunning) exitwith {};

if(!isNil "vehspawned") then {
	if(!isNull vehspawned) then {
		_players = crew (vehspawned);
		if(count _players == 0) then {

			{
					detach _x;
					deletevehicle _x;
			} forEach attachedObjects vehspawned;

			deletevehicle vehspawned;
		};
	};
};

[25] call Client_fnc_sl_removeBank_secure;
["Ihnen wurden $25 für die Anmietung eines Firmenwagens berechnet.", true] spawn doquickmsg;

_jobType = myjob;

if (_jobType == "Mafia") exitwith {
	vehspawned = createVehicle ["VVV_Bentley_Arnage", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
};

if (_jobType == "Wood Logging") exitwith {
	vehspawned = createVehicle ["jonzie_log_truck", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	[vehspawned, ["white","Glossy"]] remoteexec ["client_fnc_initVehicle",2];
	current_cars pushback vehspawned; uisleep 1;
	vehspawned addItemCargo ["R_Uniform_worker_l",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "mail") exitwith {
	vehspawned = createVehicle ["nopixel_fedex", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
	vehspawned addItemCargo ["TRYK_U_B_PCUGs_gry_R",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "trashman") exitwith {
	vehspawned = createVehicle ["vvv_camionbasura", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
	vehspawned addItemCargo ["G_Uniform_worker_l",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "pizza") exitwith {
	vehspawned = createVehicle ["Jonzie_Transit", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
	[vehspawned, ["white","Glossy"]] call client_fnc_initVehicle;
	vehspawned addItemCargo ["PRPG_Cap_Pizza",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "busdriver") exitwith {
	vehspawned = createVehicle ["acj_bus", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
};

if (_jobType == "repairman") exitwith {
	vehspawned = createVehicle ["nopixel_mrfixit", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned, ["white","Glossy"]] spawn client_fnc_initVehicle;
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
	vehspawned addItemCargo ["G_Uniform_worker_l",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "security") exitwith {
	_veharr = ["ivory_rs4_security","ivory_isf_security"];
	_veh = _veharr call BIS_fnc_selectRandom;
	vehspawned = createVehicle [_veh, [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	[_vehicle, ["black","metallic"], "black", 10, 10] call client_fnc_IvoryInitVehicle;
	//[vehspawned] remoteexec ["ivory_fnc_initvehicle",2];
	current_cars pushback vehspawned; uisleep 1;
	//vehspawned addItemCargo ["vvv_character_agente_473",1];
	hint "Mit T kanns du die Lightbar nutzen.";
};

if (_jobType == "towtruck") exitwith {
	vehspawned = createVehicle ["Jonzie_Tow_Truck", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	current_cars pushback vehspawned; uisleep 1;
	vehspawned addItemCargo ["U_C_Mechanic_01_F",1];
	hint "Da liegt zeug in dem Auto, benutze es!";
	[vehspawned, ["burntorange","Glossy"]] call client_fnc_initVehicle;
};

if (_jobType == "NewsMan") exitwith {
	vehspawned = createVehicle ["nopixel_news_van_original", [0,0,(random(500) + 3)], [], 0, "NONE"];
	[vehspawned] spawn client_fnc_spawnvehicle;
	clearmagazinecargoGlobal (vehspawned);
	current_cars pushback vehspawned; uisleep 1;

	vehspawned addWeaponCargo ["Press_Cam_F",2];
	_microphone = ["Press_Mic_AAN_F", "Press_Mic_BBC_F", "Press_Mic_CNN_F", "Press_Mic_ARD_F", "Press_Mic_ZDF_F"] call BIS_fnc_selectRandom;
	vehspawned addWeaponCargo [_microphone,2];
	hint "Da liegt zeug in dem Auto, benutze es!";
};

if (_jobType == "taxi") exitwith {
	_taxichance = random (10);
	if(_taxichance > 9) then
	{
		vehspawned = createVehicle ["ivory_rs4_taxi", [0,0,(random(500) + 3)], [], 0, "NONE"];
	} else {
		vehspawned = createVehicle ["ivory_190e_taxi", [0,0,(random(500) + 3)], [], 0, "NONE"];
	};
	[vehspawned] spawn client_fnc_spawnvehicle;
	[vehspawned] remoteexec ["ivory_fnc_initvehicle",2];
	current_cars pushback vehspawned; uisleep 1;
	//vehspawned addItemCargo ["np_shirt_8",1];
	//hint "Da liegt zeug in dem Auto, benutze es!";
};
