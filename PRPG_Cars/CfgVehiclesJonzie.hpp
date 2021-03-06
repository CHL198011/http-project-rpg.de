class Jonzie_XB_1 : Jonzie_XB {
	maxSpeed = 194;
	enginePower = 315;
};
class Jonzie_XB_2 : Jonzie_XB {
	maxSpeed = 215;
	enginePower = 350;
	peakTorque = 710;
};
class Jonzie_Mini_Cooper_1 : Jonzie_Mini_Cooper {
	maxSpeed = 170;	// max speed on level road, km/h
	acceleration = 15.8;
	enginePower = 370;
};
class Jonzie_Mini_Cooper_2 : Jonzie_Mini_Cooper {
	maxSpeed = 190;	// max speed on level road, km/h
	acceleration = 18.8;
	enginePower = 395;
};
class Jonzie_Mini_Cooper_R_spec_1 : Jonzie_Mini_Cooper_R_spec {
	maxSpeed = 240;	// max speed on level road, km/h
	acceleration = 6.1;
	enginePower = 150;
};
class Jonzie_Mini_Cooper_R_spec_2 : Jonzie_Mini_Cooper_R_spec {
	maxSpeed = 270;	// max speed on level road, km/h
	acceleration = 8.1;
	enginePower = 220;
};
class Jonzie_Ceed_1 : Jonzie_Ceed {
	maxSpeed = 195;	// max speed on level road, km/h
	acceleration = 11.8;
	enginePower = 202;
};
class Jonzie_Ceed_2 : Jonzie_Ceed {
	maxSpeed = 215;	// max speed on level road, km/h
	acceleration = 13.4;
	enginePower = 222;
};
class Jonzie_30CSL_1 : Jonzie_30CSL {
	maxSpeed = 227;	// max speed on level road, km/h
	acceleration = 11.8;
	enginePower = 277;
};
class Jonzie_30CSL_2 : Jonzie_30CSL {
	maxSpeed = 257;	// max speed on level road, km/h
	acceleration = 13.8;
	enginePower = 297;
};
class Jonzie_Transit_1 : Jonzie_Transit {
	maxSpeed=175;
	acceleration=21;
	enginePower=132;
};
class Jonzie_Transit_2 : Jonzie_Transit {
	maxSpeed=200;
	acceleration=23;
	enginePower=152;
};
class Jonzie_Raptor_1 : Jonzie_Raptor {
	maxSpeed = 175;	// max speed on level road, km/h
	acceleration = 9;
	enginePower = 258;
	peakTorque = 554;
};
class Jonzie_Raptor_2 : Jonzie_Raptor {
	maxSpeed = 210;	// max speed on level road, km/h
	acceleration = 12;
	enginePower = 288;
	peakTorque = 554;
};
class Jonzie_Escalade_1 : Jonzie_Escalade {
	maxSpeed = 250;	// max speed on level road, km/h
	acceleration = 7.5;
	maxOmega = 1246.17;
	enginePower = 511;
	peakTorque = 765;
};
class Jonzie_Escalade_2 : Jonzie_Escalade {
	maxSpeed = 290;	// max speed on level road, km/h
	acceleration = 7.3;
	maxOmega = 1246.17;
	enginePower = 581;
	peakTorque = 765;
};
class Jonzie_Viper_1 : Jonzie_Viper {
	maxSpeed = 360;	// max speed on level road, km/h
	acceleration = 3.8;
	maxOmega = 1246.17;
	enginePower = 334;
};
class Jonzie_Viper_2 : Jonzie_Viper {
	maxSpeed = 400;	// max speed on level road, km/h
	acceleration = 4.2;
	maxOmega = 1246.17;
	enginePower = 354;
};
class PRPG_Jonzie_Ambulance1 : Jonzie_Ambulance {
	displayName = "Ambulance Red";
	class eventhandlers
	{
		init = "(_this select 0) setobjecttexture [0,""\PRPG_Cars\data\ems\ambulance1.paa""],[_this select 0] execVM ""\Jonzie_Code\functions\Ambulance\Init_Ambulance.sqf""";
	};
};
class PRPG_Jonzie_Ambulance2 : Jonzie_Ambulance {
	displayName = "Ambulance Blue";
	class eventhandlers
	{
		init = "(_this select 0) setobjecttexture [0,""\PRPG_Cars\data\ems\ambulance2.paa""],[_this select 0] execVM ""\Jonzie_Code\functions\Ambulance\Init_Ambulance.sqf""";
	};
};