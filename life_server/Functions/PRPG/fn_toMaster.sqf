/*
	File: fn_toMaster.sqf
	Author: Marcel "VariatoX" Koch
	Server: project-rpg.de
	
	Description:
	Rate mal was es macht...
*/

params [
	["_player",ObjNull,[ObjNull]],
	["_type",-1,[0]]
];

if(isNull _player) exitWith {};
if(_type in [-1,0]) exitWith {};

private _tolog = "";

switch (_type) do {
	case 1: {_tolog = format["REMOTE SCRIPT EXECUTION > %1 (%2) startete fn_panicButton mit ungültigen Parametern!",name _player,getPlayerUID _player]};
};

diag_log _tolog;