class CfgPatches
{
	class red_camaro_12_pu_config
	{
		units[]=
		{
			"red_camaro_12_p_state",
			"red_camaro_12_pu_state",
			"red_camaro_12_p_sheriff",
			"red_camaro_12_p_u_black",
			"red_camaro_12_p_u_aqua",
			"red_camaro_12_p_u_darkblue",
			"red_camaro_12_p_u_green",
			"red_camaro_12_p_u_red",
			"red_camaro_12_p_u_pink",
			"red_camaro_12_p_u_yellow",
			"red_camaro_12_p_u_orange",
			"red_camaro_12_p_u_white",
			"red_camaro_12_p_u_purple",
			"red_camaro_12_p_u_darkgreen",
			"red_camaro_12_p_u_darkred",
			"red_camaro_12_p_u_blue",
			"red_camaro_12_p_u_custom1",
			"red_camaro_12_p_u_custom2",
			"red_camaro_12_p_u_custom3",
			"red_camaro_12_p_u_custom4",
			"red_camaro_12_p_u_custom5"
		};
		weapons[]=
		{
			"red_horn_pullover",
			"red_horn_handsup",
			"red_horn_passenger"
		};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"red_camaro_12_pu"
		};
	};
};
class CfgEditorCategories
{
	class redvehicles
	{
		displayname="Red's Vehicles";
	};
};
class CfgEditorSubcategories
{
	class redpolice
	{
		displayName="Police";
	};
};
class cfgWeapons
{
	class SportCarHorn;
	class red_horn_pullover: SportCarHorn
	{
		displayname="Pull Over";
		reloadTime=4;
		drySound[]=
		{
			"red_sounds\horn\PullOver.wav",
			1,
			1
		};
		scope=2;
	};
	class red_horn_handsup: SportCarHorn
	{
		displayName="Hands Up";
		reloadtime=4;
		drysound[]=
		{
			"red_sounds\horn\HandsUp.wav",
			1,
			1
		};
		scope=2;
	};
	class red_horn_passenger: SportCarHorn
	{
		displayName="Passenger";
		reloadtime=4;
		drysound[]=
		{
			"red_sounds\horn\Passenger.wav",
			1,
			1
		};
		scope=2;
	};
};
class DefaultEventhandlers;
class cfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class HitPoints
		{
			class HitLFWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRF2Wheel;
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
		};
		class EventHandlers;
	};
	class red_camaro_12_p_u_base: Car_F
	{
		model="\red_mods\red_camaro_12_pu\red_camaro_12_p_u";
		picture="\red_base\textures\icon.paa";
		Icon="\red_base\textures\icon.paa";
		author="Redhotsteel";
		editorCategory="redvehicles";
		editorSubcategory="redpolice";
		weapons[]=
		{
			"red_horn_pullover",
			"red_horn_handsup",
			"red_horn_passenger"
		};
		hiddenSelections[]=
		{
			"camo1",
			"lb_1_b",
			"lb_2_b",
			"lb_3_b",
			"lb_4_b",
			"lb_1_r",
			"lb_2_r",
			"lb_3_r",
			"lb_4_r",
			"back_light",
			"back_light_1",
			"reverse_light_lb",
			"reverse_light_lb_2",
			"D1",
			"D2",
			"D3",
			"D4",
			"D5",
			"D6",
			"D7",
			"D8",
			"lock1",
			"lock2",
			"lock3",
			"target1",
			"target2",
			"target3",
			"patrol1",
			"patrol2",
			"patrol3"
		};
		terrainCoef=1;
		turnCoef=2.5;
		precision=10;
		fireResistance=5;
		armor=32;
		cost=50000;
		crew="C_man_1";
		transportMaxBackpacks=3;
		transportSoldier=3;
		extCameraPosition[]={0,1,-7.5};
		tf_hasLRradio=1;
		class eventhandlers
		{
			init="_this execVM ""red_mods\red_camaro_12_pu\scripts\init.sqf"";";
		};
		class UserActions
		{
			class lightbaroff
			{
				displayName="Lightbar Off";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 0.5";
				statement="this setVariable ['lightbar',0,true]; this setVariable ['directional',0,true];";
				onlyForplayer=0;
			};
			class lightbaron
			{
				displayName="Lightbar On";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 0";
				statement="this setVariable ['lightbar',0.5,true]; this setVariable ['directional',0.25,true];";
				onlyForplayer=0;
			};
			class directionalon
			{
				displayName="Directional On";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) == 0";
				statement="this setVariable ['directional',0.25,true]";
				onlyForplayer=0;
			};
			class directionalright
			{
				displayName="<t color='#ffff00'>Directional Right</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',0.50,true]";
				onlyForplayer=0;
			};
			class directionalleft
			{
				displayName="<t color='#ffff00'>Directional Left</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',0.75,true]";
				onlyForplayer=0;
			};
			class directionalflashing
			{
				displayName="<t color='#ffff00'>Directional Flashing</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',1,true]";
				onlyForplayer=0;
			};
			class directionaloff
			{
				displayName="Directional Off";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0";
				statement="this setVariable ['directional',0,true]";
				onlyForplayer=0;
			};
			class Reset
			{
				displayName="<t color='#ff0000'>Reset Lock/Fast</t>";
				position="drivewheel";
				radius=10;
				condition="player IN this";
				statement="this setobjecttextureglobal [21,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [22,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [23,'\red_base\textures\emergency\a0.paa']; Prevspeed = 0;";
				onlyForplayer=1;
			};
			class lower_laptop
			{
				displayName="Lower Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') < 0.5)";
				statement="this animate [""laptop_1_rot"",1]";
			};
			class raise_laptop
			{
				displayName="Raise Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') > 0.5)";
				statement="this animate [""laptop_1_rot"",0]";
			};
			class rotate_mount
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') < 0.5)";
				statement="this animate [""mount_1_rot"",1]";
			};
			class rotate_mount2
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') > 0.5)";
				statement="this animate [""mount_1_rot"",0]";
			};
		};
		class AnimationSources
		{
			class HitLFWheel
			{
				source="Hit";
				hitpoint="HitLFWheel";
				raw=1;
			};
			class HitLF2Wheel
			{
				source="Hit";
				hitpoint="HitLF2Wheel";
				raw=1;
			};
			class HitRFWheel
			{
				source="Hit";
				hitpoint="HitRFWheel";
				raw=1;
			};
			class HitRF2Wheel
			{
				source="Hit";
				hitpoint="HitRF2Wheel";
				raw=1;
			};
			class HitHull
			{
				source="Hit";
				hitpoint="HitHull";
				raw=1;
			};
			class HitGlass1
			{
				source="Hit";
				hitpoint="HitGlass1";
				raw=1;
			};
			class HitGlass2
			{
				source="Hit";
				hitpoint="HitGlass2";
				raw=1;
			};
			class HitGlass3
			{
				source="Hit";
				hitpoint="HitGlass3";
				raw=1;
			};
			class HitGlass4
			{
				source="Hit";
				hitpoint="HitGlass4";
				raw=1;
			};
			class HitGlass5
			{
				source="Hit";
				hitpoint="HitGlass5";
				raw=1;
			};
			class HitGlass6
			{
				source="Hit";
				hitpoint="HitGlass6";
				raw=1;
			};
			class laptop_1_rot
			{
				initPhase=0;
				animPeriod=1;
			};
			class mount_1_rot
			{
				initPhase=0;
				animPeriod=3;
			};
		};
		class HitPoints: HitPoints
		{
			class HitLFWheel: HitLFWheel
			{
				armor=1;
				passThrough=0;
				name="wheel_1_1_steering";
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				armor=1;
				passThrough=0;
				name="wheel_1_2_steering";
			};
			class HitRFWheel: HitRFWheel
			{
				armor=1;
				passThrough=0;
				name="wheel_2_1_steering";
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				armor=1;
				passThrough=0;
				name="wheel_2_2_steering";
			};
			class HitFuel: HitFuel
			{
				armor=0.5;
				name="fueltank";
				passThrough=0.5;
			};
			class HitEngine: HitEngine
			{
				armor=0.75;
				name="engine";
				passThrough=0.5;
			};
			class HitHull: HitHull
			{
				armor=1.75;
				name="body";
				passThrough=1;
			};
			class HitGlass1: HitGlass1
			{
				armor=0.0099999998;
				name="glass1";
			};
			class HitGlass2: HitGlass2
			{
				armor=0.0099999998;
				name="glass2";
			};
			class HitGlass3: HitGlass3
			{
				armor=0.0099999998;
				name="glass3";
			};
			class HitGlass4: HitGlass4
			{
				armor=0.0099999998;
				name="glass4";
			};
			class HitGlass5: HitGlass5
			{
				armor=0.0099999998;
				name="glass5";
			};
			class HitGlass6: HitGlass6
			{
				armor=0.0099999998;
				name="glass6";
			};
		};
		wheelDamageRadiusCoef=0.89999998;
		wheelDestroyRadiusCoef=0.40000001;
		maxFordingDepth=0.5;
		waterResistance=1;
		crewCrashProtection=0.25;
		driverLeftHandAnimName="drivewheel";
		driverRightHandAnimName="drivewheel";
		class Turrets
		{
		};
		driverAction="driver_offroad01";
		cargoAction[]=
		{
			"passenger_low01",
			"passenger_generic01_leanleft",
			"passenger_generic01_leanright"
		};
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		attenuationEffectType="CarAttenuation";
		soundGetIn[]=
		{
			"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door",
			"db-5",
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\vehicles\soft\Hatchback_01\Hatchback_01_door",
			"db-5",
			1,
			40
		};
		soundDammage[]=
		{
			"",
			"db-5",
			1
		};
		soundEngineOnInt[]=
		{
			"red_base\sounds\MUSCLE_V8\v8_int_start",
			0.39810717,
			1
		};
		soundEngineOnExt[]=
		{
			"red_base\sounds\MUSCLE_V8\v8_ext_start",
			2.5668361,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"red_base\sounds\MUSCLE_V8\v8_int_stop",
			0.39810717,
			1
		};
		soundEngineOffExt[]=
		{
			"red_base\sounds\MUSCLE_V8\v8_ext_stop",
			0.44668359,
			1,
			200
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_building_01",
			"db-3",
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_building_02",
			"db-3",
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_building_03",
			"db-3",
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_building_04",
			"db-3",
			1,
			200
		};
		soundBuildingCrash[]=
		{
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_01",
			"db-3",
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_02",
			"db-3",
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_03",
			"db-3",
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_04",
			"db-3",
			1,
			200
		};
		WoodCrash4[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_05",
			"db-3",
			1,
			200
		};
		WoodCrash5[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_mix_wood_06",
			"db-3",
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.16599999,
			"woodCrash1",
			0.16599999,
			"woodCrash2",
			0.16599999,
			"woodCrash3",
			0.16599999,
			"woodCrash4",
			0.16599999,
			"woodCrash5",
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_01",
			"db-3",
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_02",
			"db-3",
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_03",
			"db-3",
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\Sounds_F\vehicles\soft\noises\crash_vehicle_04",
			"db-3",
			1,
			200
		};
		soundArmorCrash[]=
		{
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		class Sounds
		{
			class Idle_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_idle",
					"db-7.4",
					1,
					150
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(400/6900),(700/6900)])* ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class Engine
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_1000",
					"db-11",
					1,
					200
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(870/6900),(1100/6900)])* ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_2000",
					"db-9",
					1,
					240
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(1250/6900),(2050/6900)])* ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_3000",
					"db-8",
					1,
					280
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(2250/6900),(3050/6900)])* ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_4000",
					"db-7",
					1,
					320
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(3250/6900),(4050/6900)])* ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_5000",
					"db-6",
					1,
					360
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)])*0.2";
				volume="engineOn*camPos*(((rpm/6900) factor[(4150/6900),(4800/6900)])* ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_6000",
					"db-5",
					1,
					420
				};
				frequency="0.95 + ((rpm/6900) factor[(5100/6900),(6900/6900)])*0.15";
				volume="engineOn*camPos*((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_1000",
					"db-6",
					1,
					200
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(400/6900),(700/6900)])* ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_2000",
					"db-5",
					1,
					250
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(870/6900),(1100/6900)])* ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_3000",
					"db-4",
					1,
					280
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(1250/6900),(2050/6900)])* ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_4000",
					"db-3",
					1,
					320
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(2250/6900),(3050/6900)])* ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_5000",
					"db-2",
					1,
					360
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(3250/6900),(4050/6900)])* ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_6000",
					"db0",
					1,
					400
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)])*0.3";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(4150/6900),(4800/6900)])* ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_ext_7000",
					"db2",
					1,
					450
				};
				frequency="0.9 + ((rpm/6900) factor[(5100/6900),(6900/6900)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_idle",
					"db-15",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(400/6900),(700/6900)])* ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_1000",
					"db-14",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(870/6900),(1100/6900)])* ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_2000",
					"db-12",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(1250/6900),(2050/6900)])* ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_3000",
					"db-11",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(2250/6900),(3050/6900)])* ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_4000",
					"db-10",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(3250/6900),(4050/6900)])* ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_5000",
					"db-9",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/6900) factor[(4150/6900),(4800/6900)])* ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_6000",
					"db-6",
					1
				};
				frequency="0.95 + ((rpm/6900) factor[(5100/6900),(6900/6900)])*0.15";
				volume="engineOn*(1-camPos)*((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_1000",
					"db-10",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(400/6900),(1150/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(400/6900),(700/6900)])* ((rpm/6900) factor[(1100/6900),(900/6900)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_2000",
					"db-9",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(900/6900),(2100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(870/6900),(1100/6900)])* ((rpm/6900) factor[(2100/6900),(1300/6900)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_3000",
					"db-8",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(1300/6900),(3100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(1250/6900),(2050/6900)])* ((rpm/6900) factor[(3100/6900),(2300/6900)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_4000",
					"db-7",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(2200/6900),(4100/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(2250/6900),(3050/6900)])* ((rpm/6900) factor[(4100/6900),(3300/6900)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_5000",
					"db-6",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(3300/6900),(4900/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(3250/6900),(4050/6900)])* ((rpm/6900) factor[(4870/6900),(4200/6900)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_6000",
					"db-5",
					1
				};
				frequency="0.8 + ((rpm/6900) factor[(4200/6900),(6200/6900)])*0.3";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/6900) factor[(4150/6900),(4800/6900)])* ((rpm/6900) factor[(6150/6900),(5150/6900)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"red_base\sounds\MUSCLE_V8\v8_int_7000",
					"db-4",
					1
				};
				frequency="0.9 + ((rpm/6900) factor[(5100/6900),(6900/6900)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/6900) factor[(5100/6900),(6100/6900)])";
			};
			class Movement
			{
				sound="soundEnviron";
				frequency="1";
				volume="0";
			};
			class TiresRockOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",
					"db-6",
					1,
					60
				};
				frequency="1";
				volume="camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3",
					"db-8",
					1,
					90
				};
				frequency="1";
				volume="camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",
					"db-6",
					1
				};
				frequency="1";
				volume="(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",
					"db-10",
					1
				};
				frequency="1";
				volume="(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",
					"db-10",
					1
				};
				frequency="1";
				volume="(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",
					"db-10",
					1
				};
				frequency="1";
				volume="(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",
					"db-10",
					1
				};
				frequency="1";
				volume="(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",
					"db-10",
					1
				};
				frequency="1";
				volume="(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					"db-13",
					1
				};
				frequency="1";
				volume="(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",
					"db+7",
					1,
					80
				};
				frequency=1;
				volume="engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					"db+7",
					1,
					80
				};
				frequency=1;
				volume="engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					"db+7",
					1,
					80
				};
				frequency=1;
				volume="engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					"db+7",
					1,
					80
				};
				frequency=1;
				volume="engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking",
					"db-15",
					1,
					60
				};
				frequency=1;
				volume="engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class acceleration_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration",
					"db-15",
					1,
					60
				};
				frequency=1;
				volume="engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",
					"db-15",
					1,
					60
				};
				frequency=1;
				volume="engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15])";
			};
			class turn_right_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt",
					"db-15",
					1,
					60
				};
				frequency=1;
				volume="engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15])";
			};
			class breaking_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
			class breaking_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15])";
			};
			class acceleration_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2])";
			};
			class turn_left_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15])";
			};
			class turn_right_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int",
					"db-10",
					1
				};
				frequency=1;
				volume="engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15])";
			};
		};
		class RenderTargets
		{
			class LeftMirror
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="PIP0_pos";
					pointDirection="PIP0_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
			class RearCam
			{
				renderTarget="rendertarget1";
				class CameraView1
				{
					pointPosition="PIP1_pos";
					pointDirection="PIP1_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
			class FrontCam
			{
				renderTarget="rendertarget2";
				class CameraView1
				{
					pointPosition="PIP2_pos";
					pointDirection="PIP2_dir";
					renderQuality=2;
					renderVisionMode=0;
					fov=0.69999999;
				};
			};
		};
		thrustDelay=0.1;
		brakeIdleSpeed=1.78;
		maxSpeed=325;
		fuelCapacity=45;
		wheelCircumference=2.277;
		antiRollbarForceCoef=2.4000001;
		antiRollbarForceLimit=2;
		antiRollbarSpeedMin=20;
		antiRollbarSpeedMax=80;
		idleRpm=900;
		redRpm=6400;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3.2309999,
				"N",
				0,
				"D1",
				4.4619999,
				"D2",
				3.5699999,
				"D3",
				2.5710001,
				"D4",
				1.97,
				"D5",
				1.601,
				"D6",
				0.89999998,
				"D7",
				0.64999998
			};
			TransmissionRatios[]=
			{
				"High",
				4.1110001
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
			transmissionDelay=0.0099999998;
		};
		simulation="carx";
		dampersBumpCoef=0.0099999998;
		differentialType="all_open";
		frontRearSplit=0.30000001;
		frontBias=1.5;
		rearBias=1.5;
		centreBias=2.5;
		clutchStrength=55;
		maxOmega=549.78003;
		enginePower=670;
		peakTorque=1000;
		dampingRateFullThrottle=0.029999999;
		dampingRateZeroThrottleClutchEngaged=0.34999999;
		dampingRateZeroThrottleClutchDisengaged=0.050000001;
		torqueCurve[]=
		{
			{0,0},
			{0.2,0.64999998},
			{0.30000001,0.80000001},
			{0.40000001,0.94999999},
			{0.60000002,1},
			{0.69999999,0.94999999},
			{0.89999998,0.89999998},
			{1,0.5}
		};
		changeGearMinEffectivity[]={0.94999999,0.15000001,0.94999999,0.94999999,0.94999999,0.94999999,0.94999999,0.94999999,0.94999999};
		switchTime=0.2;
		latency=0.80000001;
		class Wheels
		{
			class LF
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				mass=20;
				MOI=5.3000002;
				maxBrakeTorque=5000;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.177;
				mMaxDroop=0;
				sprungMass=273;
				springStrength=13650;
				springDamperRate=3860;
				longitudinalStiffnessPerUnitGravity=4800;
				latStiffX=25;
				latStiffY=220;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class LR: LF
			{
				boneName="wheel_1_2_damper";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
				steering=0;
				side="left";
				latStiffX=25;
				latStiffY=22000;
				maxHandBrakeTorque=2500;
			};
			class RF: LF
			{
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				steering=1;
				side="right";
				latStiffX=25;
				latStiffY=220;
			};
			class RR: RF
			{
				boneName="wheel_2_2_damper";
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
				maxHandBrakeTorque=2500;
				steering=0;
				side="right";
				latStiffX=25;
				latStiffY=22000;
			};
		};
		memoryPointTrackFLL="TrackFLL";
		memoryPointTrackFLR="TrackFLR";
		memoryPointTrackBLL="TrackBLL";
		memoryPointTrackBLR="TrackBLR";
		memoryPointTrackFRL="TrackFRL";
		memoryPointTrackFRR="TrackFRR";
		memoryPointTrackBRL="TrackBRL";
		memoryPointTrackBRR="TrackBRR";
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust1_pos";
				direction="exhaust1_dir";
				effect="ExhaustsEffect";
			};
			class Exhaust2
			{
				position="exhaust2_pos";
				direction="exhaust2_dir";
				effect="ExhaustsEffect";
			};
		};
		class Reflectors
		{
			class LightCarHeadL01
			{
				color[]={1550,1550,2000};
				ambient[]={5,5,5};
				position="LightCarHeadL01";
				direction="LightCarHeadL01_end";
				hitpoint="Light_L";
				selection="";
				size=1;
				innerAngle=10;
				outerAngle=200;
				coneFadeCoef=50;
				intensity=3;
				useFlare=1;
				dayLight=0;
				flareSize=1;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=0.25;
					hardLimitStart=30;
					hardLimitEnd=60;
				};
			};
			class LightCarHeadR01: LightCarHeadL01
			{
				position="LightCarHeadR01";
				direction="LightCarHeadR01_end";
				hitpoint="Light_R";
				selection="";
			};
		};
		class PlateInfos
		{
			name="letters";
			color[]={0,0,0,1};
			plateFont="RobotoCondensedBold";
			plateFormat="$$$####";
			plateLetters="ABCDEFHIKLMOPRSTVXYZ";
		};
	};
	class red_camaro_12_p_state: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (State Trooper)";
		model="\red_mods\red_camaro_12_pu\red_camaro_12_p_s";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\black.paa"
		};
		class UserActions
		{
			class lightbaroff
			{
				displayName="Lightbar Off";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 1";
				statement="this setVariable ['lightbar',0,true]; this setVariable ['directional',0,true];";
				onlyForplayer=0;
			};
			class lightbaron
			{
				displayName="Lightbar On";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 0";
				statement="this setVariable ['lightbar',1,true]; this setVariable ['directional',0.25,true];";
				onlyForplayer=0;
			};
			class directionalon
			{
				displayName="Directional On";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) == 0";
				statement="this setVariable ['directional',0.25,true]";
				onlyForplayer=0;
			};
			class directionalright
			{
				displayName="<t color='#ffff00'>Directional Right</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',0.50,true]";
				onlyForplayer=0;
			};
			class directionalleft
			{
				displayName="<t color='#ffff00'>Directional Left</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',0.75,true]";
				onlyForplayer=0;
			};
			class directionalflashing
			{
				displayName="<t color='#ffff00'>Directional Flashing</t>";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0.24";
				statement="this setVariable ['directional',1,true]";
				onlyForplayer=0;
			};
			class directionaloff
			{
				displayName="Directional Off";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['directional',0]) > 0";
				statement="this setVariable ['directional',0,true]";
				onlyForplayer=0;
			};
			class Reset
			{
				displayName="<t color='#ff0000'>Reset Lock/Fast</t>";
				position="drivewheel";
				radius=10;
				condition="player IN this";
				statement="this setobjecttextureglobal [21,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [22,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [23,'\red_base\textures\emergency\a0.paa']; Prevspeed = 0;";
				onlyForplayer=1;
			};
			class lower_laptop
			{
				displayName="Lower Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') < 0.5)";
				statement="this animate [""laptop_1_rot"",1]";
			};
			class raise_laptop
			{
				displayName="Raise Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') > 0.5)";
				statement="this animate [""laptop_1_rot"",0]";
			};
			class rotate_mount
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') < 0.5)";
				statement="this animate [""mount_1_rot"",1]";
			};
			class rotate_mount2
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') > 0.5)";
				statement="this animate [""mount_1_rot"",0]";
			};
		};
	};
	class red_camaro_12_pu_state: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (State Trooper)(Slicktop)";
		model="\red_mods\red_camaro_12_pu\red_camaro_12_p_su";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\black.paa"
		};
		class UserActions
		{
			class lightbaroff
			{
				displayName="Lightbar Off";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 1";
				statement="this setVariable ['lightbar',0,true]; this setVariable ['directional',0,true];";
				onlyForplayer=0;
			};
			class lightbaron
			{
				displayName="Lightbar On";
				position="drivewheel";
				radius=2;
				condition="driver this == player && (this getVariable ['lightbar',0]) == 0";
				statement="this setVariable ['lightbar',1,true]; this setVariable ['directional',0.25,true];";
				onlyForplayer=0;
			};
			class Reset
			{
				displayName="<t color='#ff0000'>Reset Lock/Fast</t>";
				position="drivewheel";
				radius=10;
				condition="player IN this";
				statement="this setobjecttextureglobal [21,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [22,'\red_base\textures\emergency\a0.paa']; this setobjecttextureglobal [23,'\red_base\textures\emergency\a0.paa']; Prevspeed = 0;";
				onlyForplayer=1;
			};
			class lower_laptop
			{
				displayName="Lower Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') < 0.5)";
				statement="this animate [""laptop_1_rot"",1]";
			};
			class raise_laptop
			{
				displayName="Raise Laptop";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'laptop_1_rot') > 0.5)";
				statement="this animate [""laptop_1_rot"",0]";
			};
			class rotate_mount
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') < 0.5)";
				statement="this animate [""mount_1_rot"",1]";
			};
			class rotate_mount2
			{
				displayName="Rotate Mount";
				position="drivewheel";
				radius=10;
				onlyForplayer="true";
				condition="myJob == 'Cop' && driver this == player && ((this animationPhase 'mount_1_rot') > 0.5)";
				statement="this animate [""mount_1_rot"",0]";
			};
		};
	};
	class red_camaro_12_p_sheriff: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Sheriff)";
		model="\red_mods\red_camaro_12_pu\red_camaro_12_p_p";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\black.paa"
		};
	};
	class red_camaro_12_p_u_black: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Black)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\black.paa"
		};
	};
	class red_camaro_12_p_u_aqua: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Aqua)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\aqua.paa"
		};
	};
	class red_camaro_12_p_u_darkblue: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Dark Blue)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\darkblue.paa"
		};
	};
	class red_camaro_12_p_u_green: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Green)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\green.paa"
		};
	};
	class red_camaro_12_p_u_red: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Red)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\red.paa"
		};
	};
	class red_camaro_12_p_u_pink: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Pink)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\pink.paa"
		};
	};
	class red_camaro_12_p_u_yellow: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Yellow)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\yellow.paa"
		};
	};
	class red_camaro_12_p_u_orange: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Orange)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\orange.paa"
		};
	};
	class red_camaro_12_p_u_white: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (White)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\white.paa"
		};
	};
	class red_camaro_12_p_u_purple: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Purple)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\purple.paa"
		};
	};
	class red_camaro_12_p_u_darkgreen: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Dark Green)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\darkgreen.paa"
		};
	};
	class red_camaro_12_p_u_darkred: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Dark Red)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\darkred.paa"
		};
	};
	class red_camaro_12_p_u_blue: red_camaro_12_p_u_base
	{
		scope=2;
		side=3;
		displayName="2012 Chevrolet Camaro ZL1 (Blue)(Undercover)";
		hiddenSelectionsTextures[]=
		{
			"red_base\colours\blue.paa"
		};
	};
	class red_camaro_12_p_u_custom1: red_camaro_12_p_u_base
	{
		scope=2;
		displayName="2012 Chevrolet Camaro ZL1 (Custom 1)(Undercover)";
		side=3;
		hiddenSelectionsTextures[]=
		{
			"red_config\red_camaro_12_pu\skins\custom1.paa"
		};
	};
	class red_camaro_12_p_u_custom2: red_camaro_12_p_u_base
	{
		scope=2;
		displayName="2012 Chevrolet Camaro ZL1 (Custom 2)(Undercover)";
		side=3;
		hiddenSelectionsTextures[]=
		{
			"red_config\red_camaro_12_pu\skins\custom2.paa"
		};
	};
	class red_camaro_12_p_u_custom3: red_camaro_12_p_u_base
	{
		scope=2;
		displayName="2012 Chevrolet Camaro ZL1 (Custom 3)(Undercover)";
		side=3;
		hiddenSelectionsTextures[]=
		{
			"red_config\red_camaro_12_pu\skins\custom3.paa"
		};
	};
	class red_camaro_12_p_u_custom4: red_camaro_12_p_u_base
	{
		scope=2;
		displayName="2012 Chevrolet Camaro ZL1 (Custom 4)(Undercover)";
		side=3;
		hiddenSelectionsTextures[]=
		{
			"red_config\red_camaro_12_pu\skins\custom4.paa"
		};
	};
	class red_camaro_12_p_u_custom5: red_camaro_12_p_u_base
	{
		scope=2;
		displayName="2012 Chevrolet Camaro ZL1 (Custom 5)(Undercover)";
		side=3;
		hiddenSelectionsTextures[]=
		{
			"red_config\red_camaro_12_pu\skins\custom5.paa"
		};
	};
};
