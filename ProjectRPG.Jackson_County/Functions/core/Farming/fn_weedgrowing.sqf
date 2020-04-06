/*
	Author: Unknown edit Kajetan "Kruk" Mruk
	Date: 22.01.2017 (Non-retard Units)

	Params:
		1 - Object - weed plant object
	Description: Function that simulates weed growing.
	Return: nothing
*/

WaterArray = ["Hinweis: Die Erde ist Trocken!","Hinweis: Die Pflanze welkt!","Hinweis: Die blätter hängen runter!"];
PruneArray = ["Hinweis: Da sind einige Kranke Blätter!","Hinweis: Einige Blätter verwelken!","Hinweis: Die Pflanze hat sehr viele Seitenzweige!"];
CoolArray2 = ["Hinweis: Die Pflanze stinkt!","Hinweis: Es sind 32°C","Hinweis: Es wird heiß!"];
HeatArray2 = ["Hinweis: Es ist recht Kalt!","Hinweis: Es sind 14°C!","Hinweis: Die Pflanze verrfärbt ihre Blätter!"];
TurnoverArray = ["Hinweis: Die Erde hat wenige Nährstoffe!","Hinweis: Die Erde ist verdichtet!","Hinweis: Perlite währen ganz gut!"];

params["_object"];

_object setVariable ["growing",true,true];
_object setVariable ["count",0];
_object setVariable ["quality",4];

_count = 0;
_random = round(random 7) + 8;
while{_count < _random && (_object getVariable ["growing",false])} do {
	_object setVariable ["checkFinish", true];
	_object setVariable ["actionPerformed", false];
	sleep round(random 15) + 15;
	_object setVariable ["checkFinish", false];
	_randomValue = round(random 5);
	if(_randomValue == 1 || _randomvalue == 0) then { _object setVariable["requiredOutput", "Water"];  };
	if(_randomValue == 2) then { _object setVariable["requiredOutput", "Prune"]; };
	if(_randomValue == 3) then { _object setVariable["requiredOutput", "Cool"];  };
	if(_randomValue == 4) then { _object setVariable["requiredOutput", "Heat"];  };
	if(_randomValue == 5) then { _object setVariable["requiredOutput", "Turnover"];  };
	sleep round(random 15) + 15;
	_count = _count + 1;
	_object setpos [(getpos _object select 0),(getpos _object select 1),(getpos _object select 2)+0.15];
	_skip = random(20);
	waitUntil{_object getVariable ["actionPerformed",false] || _skip < 5};
};
removeAllActions _object;
if(isNull _object) exitwith {};
_object setVariable ["ready",true,false];
