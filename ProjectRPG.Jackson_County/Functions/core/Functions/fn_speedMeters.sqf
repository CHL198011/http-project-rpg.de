params["_ticket"];
speedMeter_last_ticket = false;
_lastPos = visiblePosition player;
_lastPos = (_lastPos select 0) + (_lastPos select 1);
_walkDis = 0;
for "_i" from 0 to 1 step 0 do {
	if (myjob in ["Cop","EMS","Fire"]) then {} else {
	    _vehicle = vehicle player;
		if(vehicle player != player && driver (vehicle player) isEqualTo player && ((_vehicle isKindOf "Car") || (_vehicle isKindOf "Motorcycle") || (_vehicle isKindOf "Bicycle") || (_vehicle isKindOf "Motorbike"))) then {
			_target = driver (vehicle player);
			_vel = speed _target;
			_text = "";
			_wanted_level = 1;
			_handle = false;
			if((player distance (getMarkerPos "speed_cam_1")) < 20 || (player distance (getMarkerPos "speed_cam_2")) < 20 || (player distance (getMarkerPos "speed_cam_3")) < 20 || (player distance (getMarkerPos "speed_cam_4")) < 20) then {
				_text = " in bebauten Gebieten";
				if(_vel > 74 && _vel < 85) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 500;
				};
				if(_vel > 84 && _vel < 130) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 750;
					//["Remove","license",1] call client_fnc_sustain;
				};
				if(_vel > 129) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 1000;
					//["Remove","license",1] call client_fnc_sustain;
				};
				uiSleep 4;
			};
			if((player distance (getMarkerPos "speed_cam_5")) < 20 || (player distance (getMarkerPos "speed_cam_6")) < 20 || (player distance (getMarkerPos "speed_cam_7")) < 20 || (player distance (getMarkerPos "speed_cam_8")) < 20 || (player distance (getMarkerPos "speed_cam_9")) < 20 || (player distance (getMarkerPos "speed_cam_10")) < 20 || (player distance (getMarkerPos "speed_cam_11")) < 20 || (player distance (getMarkerPos "speed_cam_12")) < 20 || (player distance (getMarkerPos "speed_cam_13")) < 20 || (player distance (getMarkerPos "speed_cam_14")) < 20 || (player distance (getMarkerPos "speed_cam_15")) < 20 || (player distance (getMarkerPos "speed_cam_16")) < 20 || (player distance (getMarkerPos "speed_cam_17")) < 20) then {
				_text = " außerhalb bebauter Gebiete.";
				if(_vel > 164 && _vel < 185) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 500;
				};
				if(_vel > 184 && _vel < 254) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 750;
					//["Remove","license",1] call client_fnc_sustain
				};
				if(_vel > 255) then {
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					uiSleep 0.1;
					"colorCorrections" ppEffectEnable true;
					"colorCorrections" ppEffectAdjust [1, 15, 0, [0.5, 0.5, 0.5, 0], [0.0, 0.5, 0.0, 0.6],[0.3, 0.3, 0.3, 0.05]];
					"colorCorrections" ppEffectCommit 0;
					uiSleep 0;
					"colorCorrections" ppEffectAdjust [1, 1, 0, [1, 1, 1, 0.0], [1, 1, 1, 0.6],  [1, 1, 1, 0.6]];
					"colorCorrections" ppEffectCommit 0.05;
					uiSleep 0.05;
					"colorCorrections" ppEffectEnable false;
					_handle = true;
					_ticket = 1000;
					//["Remove","license",1] call client_fnc_sustain;
				};
				uiSleep 4;
			};
			if(_handle) then {
				
				
				_information = _vehicle getVariable ["information",[]];
				_plate = _information select 0;
				_class = typeof _vehicle;
				_color = _information select 2;
				_color = getText(configFile >> "CfgIvoryTextures" >> _color >> "displayName");
				_vehName = getText(configFile >> "CfgVehicles" >> _class >> "displayName");
				_description = format["%1(%2)",_vehName,_color];
				_uid_officer = "901";
				_reason = format["Geschwindigkeit %1kmh%2",round(_vel),_text];
				_data = [_plate,_description,_uid_officer,_reason,_wanted_level];
				//["vehicle", _data] remoteExec ["server_fnc_slpdCaseAdd",2];
				
				_message = format["Du bist zu schnell gefahren! %2 Zulassungsnummer %1", toUpper(_plate), _reason];
				_message2 = format ["Strafgeld $%1", _ticket];

				uiSleep 0.1;
				[_message,true] spawn domsg;
				uiSleep 0.1;
				[_message2,true] spawn domsg;
				uiSleep 0.1;
				[_ticket] call Client_fnc_sl_removeBank_secure;
				};
			};
		};
	};

    if (!alive player) then {_walkDis = 0;} else {
        _curPos = visiblePosition player;
        _curPos = (_curPos select 0) + (_curPos select 1);
        if (!(_curPos isEqualTo _lastPos)) then {
            _walkDis = _walkDis + 1;
            if (_walkDis isEqualTo 900) then {
                _walkDis = 0;
                ["Distance"] spawn mav_ttm_fnc_addExp;
            };
        };
        _lastPos = visiblePosition player;
        _lastPos = (_lastPos select 0) + (_lastPos select 1);
    };
