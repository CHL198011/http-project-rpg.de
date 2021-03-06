/*
	File: fn_craftMenu.sqf

	array numbers are:
	["NP_Wood","np_copperbar1","np_ironbar1","np_silverbar1","CG_OilCanister"];
*/
disableSerialization;
private["_cost","_error","_materials","_n","_i","_WaffenClasses","_PricesWaffenClasses","_classStatus"];

_status = lbData[1113,lbCurSel (1113)];
_status = call compile format["%1", _status];

_mainMenus = ["Waffen","Visiere"];

_materials = ["NP_Wood","prpg_item_kupfer_bar","prpg_item_eisen_bar","prpg_item_aluminium_bar"];
_scopematerials = ["prpg_item_glas","prpg_item_kupfer_bar","prpg_item_eisen_bar"];


/*
if (mav_ttm_var_weaponcrafting == 0) then {
	_WaffenClasses = [
	];
};

if (mav_ttm_var_weaponcrafting == 1) then {
	_WaffenClasses = [
		"RH_python",
		"RH_gsh18",
		"RH_p226",
		"RH_fn57_t",
		"RH_tec9"
	];
};

if (mav_ttm_var_weaponcrafting == 2) then {
	_WaffenClasses = [
	"RH_python",
	"RH_gsh18",
	"RH_p226",
	"RH_fn57_t",
	"RH_tec9",
	"hlc_smg_mp5k",
	"hlc_smg_mp5a2"
	];
};

if (mav_ttm_var_weaponcrafting == 3) then {
	_WaffenClasses = [
	"RH_python",
	"RH_gsh18",
	"RH_p226",
	"RH_fn57_t",
	"RH_tec9",
	"hlc_smg_mp5k",
	"hlc_smg_mp5a2",
	"RH_bull"
	];
};

if (mav_ttm_var_weaponcrafting == 4) then {
	_WaffenClasses = [
	"RH_python",
	"RH_gsh18",
	"RH_p226",
	"RH_fn57_t",
	"RH_tec9",
	"hlc_smg_mp5k",
	"hlc_smg_mp5a2",
	"RH_bull",
	"hlc_rifleACR_SBR_cliffhanger",
	"hlc_rifle_honeybadger"
	];
};

if (mav_ttm_var_weaponcrafting == 5) then {
	_WaffenClasses = [
	"RH_python",
	"RH_gsh18",
	"RH_p226",
	"RH_fn57_t",
	"RH_tec9",
	"hlc_smg_mp5k",
	"hlc_smg_mp5a2",
	"RH_bull",
	"hlc_rifleACR_SBR_cliffhanger",
	"hlc_rifle_honeybadger",
	"RH_Deagles",
	"hlc_rifle_bcmblackjack",
	"hlc_rifle_bcmjack",
	"hlc_rifle_SAMR"
	];
};
*/

_WaffenClasses = [
	"RH_python",
	"RH_gsh18",
	"RH_p226",
	"RH_fn57_t",
	"RH_tec9",
	"hlc_smg_mp5k",
	"hlc_smg_mp5a2",
	"RH_bull",
	"hlc_rifleACR_SBR_cliffhanger",
	"hlc_rifle_honeybadger",
	"RH_Deagles",
	"hlc_rifle_bcmblackjack",
	"hlc_rifle_bcmjack",
	"hlc_rifle_SAMR",
	"hlc_rifle_Bushmaster300",
	"hlc_rifle_vendimus"
	];

_PricesWaffenClasses = [
	//RH_python
	[4,2,2,2],
	//RH_gsh18
	[4,2,2,2],
	//RH_p226
	[4,2,2,2],
	//RH_fn57_t
	[4,2,2,2],
	//RH_tec9
	[4,3,3,3],
	//hlc_smg_mp5k
	[4,3,3,3],
	//hlc_smg_mp5a2
	[4,5,5,5],
	//RH_bull
	[4,3,3,3],
	//hlc_rifleACR_SBR_cliffhanger
	[4,8,8,8],
	//hlc_rifle_honeybadger
	[4,8,8,8],
	//RH_Deagles
	[4,6,8,8],
	//hlc_rifle_bcmblackjack
	[4,8,10,8],
	//hlc_rifle_bcmjack
	[4,8,10,8],
	//hlc_rifle_SAMR
	[4,8,10,8],
	//hlc_rifle_Bushmaster300
	[4,8,16,12],
	//hlc_rifle_vendimus
	[4,8,16,12]
];

_WaffenMags = [0,2,2,0];

_ScopeClasses = [
	"RH_barska_rds",
	"rh_compm2",
	"rh_compm4s",
	"optic_arco_blk_f",
	"rh_ta31rco",
	"rh_eotech553mag",
	"rh_eothhs1",
	"rh_shortdot",
	"hlc_optic_atacr",
	"hlc_optic_atacr_offset"
];

_scopecosts = [
	[1,1,1],	//RH_barska_rds
	[1,1,1],	//rh_compm2
	[1,1,1],	//rh_compm4s
	[1,1,2],	//optic_arco_blk_f
	[1,1,2],	//rh_ta31rco
	[2,2,2],	//rh_shortdot	
	[3,2,2],	//rh_eotech553mag
	[3,2,2],	//rh_eothhs1
	[3,2,2],	//hlc_optic_atacr
	[3,2,2]		//hlc_optic_atacr_offset
];

uisleep 0.05;

_display = findDisplay 1111;

if((_this select 0) == "REFRESH") exitwith {

	if(isNil "_status") exitwith {};

	if(_status IN _WaffenClasses) then {
		_mySelect = 0;
		{
			if(_status == _x) exitwith {};
			_mySelect = _myselect + 1;
		} foreach _WaffenClasses;
		_selectedWeapon = (configfile >> "CfgWeapons" >> _status >> "displayName") call BIS_fnc_getCfgData;
		//ArmA 3 mag einfach keine Umlaute...
		if(_status == "hlc_smg_mp5k") then { _selectedWeapon = "MP5K" };
		if(_status == "hlc_smg_mp5a2") then { _selectedWeapon = "MP5A2" };
		
		if(isNil "_selectedWeapon") exitwith {}; //? how did we even get here.

		_myArray = _PricesWaffenClasses select _mySelect;
		_mags = _WaffenMags;
		_Btn4 = _display displayCtrl 1110;
		_Btn4 ctrlSetStructuredText parsetext format["<t color='#33CC33'> %1 <t color='#ffffff'> <br/> Holz: %2 <br/> Kupfer: %3 <br/> Eisen: %4 <br/> Aluminium: %5 <br/><t color='#33CC33'>Magazin Kosten <t color='#ffffff'> <br/> Holz: %6 <br/> Kupfer: %7 <br/> Eisen: %8 <br/> Aluminium: %9",_selectedWeapon,(_myArray select 0),(_myArray select 1),(_myArray select 2),(_myArray select 3),(_Mags select 0),(_Mags select 1),(_Mags select 2),(_Mags select 3)];
		_btn4 ctrlCommit 0;
	};

	if(_status IN _ScopeClasses) then {
		_mySelect = 0;
		{
			if(_status == _x) exitwith {};
			_mySelect = _myselect + 1;
		} foreach _ScopeClasses;
		_selectedWeapon = (configfile >> "CfgWeapons" >> _status >> "displayName") call BIS_fnc_getCfgData;
		
		if(isNil "_selectedWeapon") exitwith {}; //? how did we even get here.

		_myArray = _scopecosts select _mySelect;
		//_mags = _WaffenMags;
		_Btn4 = _display displayCtrl 1110;
		_Btn4 ctrlSetStructuredText parsetext format["<t color='#33CC33'> %1 <t color='#ffffff'> <br/> Glas: %2 <br/> Kupfer: %3 <br/> Eisen: %4 <br/>",_selectedWeapon,(_myArray select 0),(_myArray select 1),(_myArray select 2)];
		_btn4 ctrlCommit 0;
	};

};

_Btn2 = _display displayCtrl 1116;
_Btn3 = _display displayCtrl 1117;
_Btn5 = _display displayCtrl 1118;


_btn2 ctrlShow false;
_btn3 ctrlShow false;
_btn5 ctrlShow false;

_list = _display displayCtrl 1113;

lbClear _list;

if((_this select 0) == "FRESH") exitwith {

	_btn3 ctrlShow true;

	{
		_list lbAdd _x;
		_list lbSetdata [(lbSize _list)-1,str(_x)];
	} foreach _mainMenus;


};

if(isNil "_status") exitwith { ["Du musst auch etwas auswählen!", false] spawn domsg; };


	_btn2 ctrlShow true;
	_btn5 ctrlShow true;

if(_status == "Waffen") exitwith {

	{
		_selectedweapon = (configfile >> "CfgWeapons" >> _x >> "displayName") call BIS_fnc_getCfgData;
		_list lbAdd _selectedweapon;
		_list lbSetdata [(lbSize _list)-1,str(_x)];
	} foreach _WaffenClasses;

};

if(_status == "Visiere") exitwith {

	{
		_selectedweapon = (configfile >> "CfgWeapons" >> _x >> "displayName") call BIS_fnc_getCfgData;
		_list lbAdd _selectedweapon;
		_list lbSetdata [(lbSize _list)-1,str(_x)];
	} foreach _ScopeClasses;

};

if(isNil "shopholder") then {
	shopholder = "plp_ct_woodboxlightsmall" createVehicleLocal [0,0,0];
};

if((_this select 0) == "CRAFT") exitwith {

	if(_status IN _WaffenClasses) then {
		_count = _WaffenClasses FIND _status;
		_cost = _PricesWaffenClasses select _count;
	};

	if(_status IN _ScopeClasses) then {
		_count = _ScopeClasses FIND _status;
		_cost = _scopecosts select _count;
	};

	if (_status IN _WaffenClasses) then {
		_error = false;
		_n = 0;
		{

			_materialCheck = _materials select _n;
			_checkCost = _cost select _n;

			_amountcurrent = {_x == (_materials select _n)} count magazines player;
			if(_amountcurrent < _checkCost) exitwith { ["Dir fehlen Ressourcen!", false] spawn domsg; _error = true; };
			_n = _n + 1;

		} foreach _cost;

		if(_error) exitwith {};


		_n = 0;
		{
			_checkCost = _cost select _n;
			_i = _checkCost;

			while{ _i > 0 } do {
				player removeitem (_materials select _n);
				_i = _i - 1;
			};

			_n = _n + 1;
		} foreach _cost;

	} else {

		_error = false;
		_n = 0;
		{

			_materialCheck = _scopematerials select _n;
			_checkCost = _cost select _n;

			_amountcurrent = {_x == (_scopematerials select _n)} count magazines player;
			if(_amountcurrent < _checkCost) exitwith { ["Dir fehlen Ressourcen!", false] spawn domsg; _error = true; };
			_n = _n + 1;

		} foreach _cost;

		if(_error) exitwith {};


		_n = 0;
		{
			_checkCost = _cost select _n;
			_i = _checkCost;

			while{ _i > 0 } do {
				player removeitem (_scopematerials select _n);
				_i = _i - 1;
			};

			_n = _n + 1;
		} foreach _cost;
	};

	if(_error) exitwith {};

	playSound3D ["CG_Jobs\sounds\sawing\saw.ogg", player, false, getPosasl player, 4, 1, 15];
	if (_status IN _WaffenClasses) then {
		shopholder addWeaponCargoGlobal [_status,1];
	} else {
		shopholder addItemCargoGlobal [_status,1];
	};
	_classStatus = _status;
	_status = (configfile >> "CfgWeapons" >> _status >> "displayName") call BIS_fnc_getCfgData;

	player disablecollisionwith shopholder;
	shopholder setpos (getposATL player);
	
	[format["Du hast eine %1 hergestellt!",_status], true] spawn domsg;
	//hint format["Du hast eine %1 hergestellt",_status];
	[player,1,format ["%1 hat eine %2 hergestellt", name player, _status],_classStatus,_status] remoteExec ["server_fnc_craftLog", 1];
	closedialog 0;
};

if((_this select 0) == "CRAFTMAG") exitwith {

	if(_status IN _WaffenClasses) then {
		_count = _WaffenClasses FIND _status;
		_cost = _WaffenMags;
	};

	if(_status IN _ScopeClasses) exitwith {
		["Magazine für ein Visir? Überleg dir das nochmal!", false] spawn domsg;
		closedialog 0;
	};

	_error = false;
	_n = 0;
	{

		_materialCheck = _materials select _n;
		_checkCost = _cost select _n;

		_amountcurrent = {_x == (_materials select _n)} count magazines player;
		if(_amountcurrent < _checkCost) exitwith { ["Dir fehlen Ressourcen!", false] spawn domsg; _error = true; };
		_n = _n + 1;

	} foreach _cost;

	if(_error) exitwith {};


	_n = 0;
	{
		_checkCost = _cost select _n;
		_i = _checkCost;

		while{ _i > 0 } do {
			player removeitem (_materials select _n);
			_i = _i - 1;
		};

		_n = _n + 1;
	} foreach _cost;


	_magazines = getArray (configFile / "CfgWeapons" / _status / "magazines");
	_magazineClass = _magazines select 0;

	shopholder addmagazineCargoGlobal [_magazineclass,2];
	
	[format["Du hast 2 magazine fuer die %1 hergestellt!",_status], true] spawn domsg;
	//hint format["Du hast 2 magazine fuer die %1 hergestellt!",_status];
	[player,2,format ["%1 hat 2 Magazine fuer die Waffe %2 hergestellt", name player, _status],_magazineclass,_status] remoteExec ["server_fnc_craftLog", 2];
	closedialog 0;
	player disablecollisionwith shopholder;
	shopholder setpos (getpos player);
};

closedialog 0;
