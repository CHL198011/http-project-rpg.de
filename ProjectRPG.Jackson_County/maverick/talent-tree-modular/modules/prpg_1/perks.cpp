//Autocrafting
class perk_autocraft_1 {
	displayName = "Autocrafting I";
	requiredPerkPoints = 2;
	requiredLevel = 3;
	requiredPerk = "";
	subtitle = "Erforderliche Stufe 3, 2 Pkt. benötigt.";
	description = "Erlerne die Herstellung einfacher Fahrzeuge.";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_craftcar_1.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_autocraft_2 {
	displayName = "Autocrafting II";
	requiredPerkPoints = 3;
	requiredLevel = 5;
	requiredPerk = "perk_autocraft_1";
	subtitle = "Erforderliche Stufe 5, 3 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Fahrzeuge";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_craftcar_2.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_autocraft_3 {
	displayName = "Autocrafting III";
	requiredPerkPoints = 4;
	requiredLevel = 9;
	requiredPerk = "perk_autocraft_2";
	subtitle = "Erforderliche Stufe 9, 4 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Fahrzeuge";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_craftcar_3.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_autocraft_4 {
	displayName = "Autocrafting IV";
	requiredPerkPoints = 5;
	requiredLevel = 15;
	requiredPerk = "perk_autocraft_3";
	subtitle = "Erforderliche Stufe 15, 5 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Fahrzeuge";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_craftcar_4.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_autocraft_5 {
	displayName = "Autocrafting V";
	requiredPerkPoints = 10;
	requiredLevel = 22;
	requiredPerk = "perk_autocraft_4";
	subtitle = "Erforderliche Stufe 22, 10 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Fahrzeuge";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_craftcar_5.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

//Waffencrafting
class perk_waffencraft_1 {
	displayName = "Waffencrafting I";
	requiredPerkPoints = 2;
	requiredLevel = 3;
	requiredPerk = "";
	subtitle = "Erforderliche Stufe 3, 2 Pkt. benötigt.";
	description = "Erlerne die Herstellung einfacher Waffen.";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_weapon_1.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_waffencraft_2 {
	displayName = "Waffencrafting II";
	requiredPerkPoints = 3;
	requiredLevel = 5;
	requiredPerk = "perk_waffencraft_1";
	subtitle = "Erforderliche Stufe 5, 3 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Waffen";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_weapon_2.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_waffencraft_3 {
	displayName = "Waffencrafting III";
	requiredPerkPoints = 4;
	requiredLevel = 9;
	requiredPerk = "perk_waffencraft_2";
	subtitle = "Erforderliche Stufe 9, 4 Pkt. benötigt.";
	description = "Erlerne die Herstellung weiterer Waffen";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_weapon_3.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_waffencraft_4 {
	displayName = "Waffencrafting IV";
	requiredPerkPoints = 5;
	requiredLevel = 15;
	requiredPerk = "perk_waffencraft_3";
	subtitle = "Erforderliche Stufe 15, 5 Pkt. benötigt.";
	description = "Erlerne die Herstellung besserer Waffen";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_weapon_4.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};

class perk_waffencraft_5 {
	displayName = "Waffencrafting V";
	requiredPerkPoints = 10;
	requiredLevel = 22;
	requiredPerk = "perk_waffencraft_4";
	subtitle = "Erforderliche Stufe 22, 10 Pkt. benötigt.";
	description = "Erlerne die Herstellung größerer Waffen.";
	initScript = "maverick\talent-tree-modular\modules\prpg_1\functions\functions_weapon_5.sqf";
	limitToSides[] = {};
	color[] = {1,1,1,1};
};