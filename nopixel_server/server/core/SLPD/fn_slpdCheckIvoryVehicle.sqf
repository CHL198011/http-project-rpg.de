/*
		Author: Kajetan "Kruk" Mruk
		Date: 16.03.2017
		Params: 
			0 - Object, player object
			1 - UID, looked for player uid
		Description: Returns data to the client police computer with personal data
		Return: nothing
*/
_plate = _this select 0;
if(isNull _player) exitWith {};

_query = format["getSLPDVehicle_plate:%1", _plate];
_vehInfo = [_query,2] call ExternalS_fnc_ExtDBasync;
_return = _vehInfo select 0;


/*
_query = format ["getSLPDWantedVehicle_plate:%1", _plate];
_wanted = [_query,2] call ExternalS_fnc_ExtDBasync;
*/

_return;