_quantity = _this select 0;
_item = _this select 1;
_totalprice = _this select 2;
_type = _this select 3;
_shopcontent = _this select 4;

_lostprice = (_totalprice / 100) * taxRate;
_lostprice = round (_lostprice);
_totalprice = _totalprice - _lostprice;

//shopcontent wasnt updating properly here for some reason, may be fixed now, dno.
player setvariable ["shopcontent",_shopcontent,false];
shopcontent = _shopcontent;

if(player distance myshop < 50) then {
	hint format["Jemand kaufte %1x %2 fuer $%3 - wurde auf Ihr Konto eingezahlt - Sie haben $%4 Steuern bezahlt.",_quantity, _item, _totalprice,_lostprice];
	[player,objNull,1,format ["%1 Gekauft %2 Menge %3 fuer %4 $", name player, _item, _quantity, _totalPrice],_totalPrice, _item, _quantity] remoteExec ["server_fnc_economyLog", 2];
} else {
	_totalprice = _totalprice * 0.8;
	hint format["Gekauft %1x %2 fuer $%3 - Du hast 20% weniger bekommen(Du warst nicht in der Nähe Deines Ladens) - $%4 Steuer bezahlt.",_quantity, _item, _totalprice,_lostprice];
	[player,objNull,1,format ["%1 gekauft %2 Menge %3 fuer %4 $", name player, _item, _quantity, _totalPrice],_totalPrice, _item, _quantity] remoteExec ["server_fnc_economyLog", 2];
};	

if(_lostprice > 0) then {
	if(isNil "taxpayments") then { taxpayments = 0; };
	if(taxpayments == 0) then { taxpayments = taxpayments + _lostprice;	[_lostprice] spawn client_fnc_payMayor; } else { taxpayments = taxpayments + _lostprice; };
};

[_totalprice] call Client_fnc_sl_addBank_secure;