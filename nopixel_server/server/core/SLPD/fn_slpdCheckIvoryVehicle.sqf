/*
		Author: PRPG
		Date: 07.05.2020
			Params: 
			0 - player
			1 - plate
		Description: kenzeichen abfrage für ivory computer
		Return: vehicle data array
*/
private ["_vehInfo"];
_player = _this select 0;
_plate = _this select 1;

_checkstr = format ["existLicense:%1", _plate];
_check = [0, _checkstr] call ExternalS_fnc_ExtDBquery;
_plateexist = (_check select 0) select 0;

if (_plateexist) then {
	_query = format["getSLPDVehicle_plate:%1", _plate];
	_vehInfo = [_query,2] call ExternalS_fnc_ExtDBasync;
	_vehInfo = _vehInfo select 0;

	[_vehInfo,1] remoteexec ["client_fnc_slpd_checkplate",_player];
} else {
	_vehInfo = _plate;
	[_vehInfo,2] remoteexec ["client_fnc_slpd_checkplate",_player];
};