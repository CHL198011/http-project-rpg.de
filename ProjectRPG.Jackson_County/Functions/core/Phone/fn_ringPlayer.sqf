	CurrentCaller = _this select 0;
	_type = _this select 1;
	_haltphone = false;
	_radios = player call TFAR_fnc_radiosList;
	if(count _radios > 0) then {
		if(_type == 1) then {
			if( phoneDisabled ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Telefon ausgeschaltet)","Anonymous"], false] spawn domsg; };	
			if( callInProgress || PhonesRinging ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Besetzt) ","Anonymous"], false] spawn domsg; };	
			if( client_battery < 5 ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Ihr Akku ist fast leer) ","Anonymous"], false] spawn domsg; };
		} else {
			if( phoneDisabled ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Telefon ausgeschaltet)",name CurrentCaller], false] spawn domsg; };	
			if( callInProgress || PhonesRinging ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Besetzt) ",name CurrentCaller], false] spawn domsg; };	
			if( client_battery < 5 ) exitwith { _haltphone = true; currentCaller remoteExec ["fnc_busyAnswer",currentCaller]; [format["%1 hat versucht dich anzurufen! (Ihr Akku ist fast leer) ",name CurrentCaller], false] spawn domsg; };
		};
		PhonesRinging = true;
		_endme = 0;
		if(_haltphone) exitwith {};
		while{PhonesRinging} do {
			playSound "cgphone_call";
			if(_type == 1) then {
				[format["Eingehender Anruf von %1!","Unbekannte Nummer"], false] spawn domsg; 
			} else {
				[format["Eingehender Anruf von %1!",name currentcaller], false] spawn domsg; 
			};
			sleep 5;
			_endme = _endme + 5;
			if(_endme > 20) exitwith { ["Hat das Telefonat nicht entgegengenommen!", false] spawn domsg;  };
		};

		PhonesRinging = false;		
	} else {
		currentCaller remoteExec ["fnc_busyAnswer",currentCaller];
		["Du bist nicht ans Telefon gegangen.", false] spawn domsg; 
	};