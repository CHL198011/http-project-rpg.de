/*
	File: fn_intoxTestReturn.sqf
	@Deo	
	Description:
	Returns the Intox Results.
*/

params [["_civ", Objnull, [Objnull]], ["_intox", 0, [0]]];

if(isNull _civ) exitWith {};

if(_intox > 0.08) then 
{
	[format["%1 Atemalkohlwert bei: %2 Wert unter dem Erlaubten",name _civ,_intox], false] spawn domsg;
} 
else 
{
	[format["%1 Anzahl der Promils in der Ausatemluft: %2",name _civ,_intox], false] spawn domsg;
};

/*if (_intox > 0.20) then 
{
	[getPlayerUID _civ,name _civ,"647"] remoteExec ["life_fnc_wantedAdd",2];
};*/