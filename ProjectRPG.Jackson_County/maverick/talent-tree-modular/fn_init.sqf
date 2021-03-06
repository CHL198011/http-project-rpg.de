scriptName "fn_init";
#define __filename "fn_init.sqf"

[] spawn {
	if (isServer && !hasInterface) exitWith {};

	life_perksInitialized = false;
	life_currentExpPerks = (0 call mav_ttm_fnc_generateBasePerks);
	life_currentExpLevel = 0;
	life_currentExp = 0;
	life_currentPerkPoints = 0;
	mav_ttm_var_lockpickMultiplier = 1;
	mav_ttm_var_paycheckMultiplier = 1;
	mav_ttm_var_repairToReduce = 0;
	mav_ttm_var_mechanicRent = 1;
	mav_ttm_var_bonusExp = 0;
	mav_ttm_var_autocrafting = 0;
	mav_ttm_var_weaponcrafting = 0;

	// Wait until player is ready
	waitUntil {player == player};

	// Request data from server
	diag_log "Requesting experience data from server";
	[player] remoteExec ["mav_ttm_fnc_loadFromDatabase", 2];

	// Create auto-retry thread
	[] spawn {
		while {!life_perksInitialized} do
		{
			sleep 5;
			if (life_perksInitialized) exitWith {};
			diag_log "Requesting experience data from server (RETRY)";
			[player] remoteExec ["mav_ttm_fnc_loadFromDatabase", 2];
		};
	};

	// Load key bindings
	mav_ttm_keybindings_code = getNumber (missionConfigFile >> "Maverick_TTM" >> "Config" >> "keyCode");
	mav_ttm_keybindings_shift = getNumber (missionConfigFile >> "Maverick_TTM" >> "Config" >> "shift");
	mav_ttm_keybindings_ctrl = getNumber (missionConfigFile >> "Maverick_TTM" >> "Config" >> "ctrl");

	// Add handler to display
	waitUntil {!isNull (findDisplay 46)};
	(findDisplay 46) displayAddEventHandler ["KeyDown", {
		params [
			"_display",
			"_code",
			"_shift",
			"_ctrl",
			"_alt"
		];

		if (mav_ttm_keybindings_code != _code) exitWith {};
		if ((mav_ttm_keybindings_shift == 1) && !_shift) exitWith {};
		if ((mav_ttm_keybindings_ctrl == 1) && !_ctrl) exitWith {};

		if (!dialog && (diag_tickTime - (missionNamespace getVariable ["mav_ttm_lastOpenTime", 0]) > 3)) then {
			mav_ttm_lastOpenTime = diag_tickTime;
			createDialog "TTM_GUI_RscDisplayTalentOverview";
		};
	}];
};