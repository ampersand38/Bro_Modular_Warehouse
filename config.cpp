class CfgPatches
{
	class Bro_Modular_Warehouse
	{
		requiredAddons[] = {"A3_Structures_F"};
		requiredVersion = 0.1;
		units[] =
		{
			"Bro_MWH_Straight",
			"Bro_MWH_Window",
			"Bro_MWH_Corner",
			"Bro_MWH_Roof_Edge",
			"Bro_MWH_Roof_Corner",
			"Bro_MWH_Roof_Middle",
			"Bro_MWH_Door",
			"Bro_MWH_Garage",
			"Bro_MWH_Vents",
			"Bro_MWH_Straight_Tan",
			"Bro_MWH_Window_Tan",
			"Bro_MWH_Corner_Tan",
			"Bro_MWH_Roof_Edge_Tan",
			"Bro_MWH_Roof_Corner_Tan",
			"Bro_MWH_Roof_Middle_Tan",
			"Bro_MWH_Door_Tan",
			"Bro_MWH_Garage_Tan",
			"Bro_MWH_Vents_Tan"
		};
		weapons[] = {};
	};
};
class CfgEditorCategories
{
	class Bro_Objects
	{
		displayName = "Project America [Bromine]";
		priority = 1;
		side = 1;
	};
};
class CfgEditorSubcategories
{
	class MWH
	{
		displayName = "Modular Warehouse";
	};
};

class EventHandlers;
class CfgVehicles
{
// Base classes - Do not modify
	class HouseBase;
	class Ruins_F;
	class House_f : HouseBase
	{
		class DestructionEffects;
	};
	class Bro_MWH_Base: House_f
	{
		scope = 0;
		scopeCurator = 0;
		author = "Bromine";
		editorCategory = "Bro_Objects";
		editorPreview = "Bro_Modular_Warehouse\icon_ca.paa";
		icon = "Bro_Modular_Warehouse\icon_ca.paa";
		vehicleClass = "Structures";
		editorSubcategory = "MWH";
		destrType = "DestructNo";
		mapSize = 10;
		keepHorizontalPlacement = 1;
		numberOfDoors = 0;
		class EventHandlers: EventHandlers {
			dragged3DEN = "_this call compile preprocessFileLineNumbers 'Bro_Modular_Warehouse\snap.sqf';";
			registeredToWorld3DEN = "_this call compile preprocessFileLineNumbers 'Bro_Modular_Warehouse\snap.sqf';";
		};
	};
// Static - Walls
	class Bro_MWH_Straight: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Plain)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Straight.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Straight.jpg";
	};
	class Bro_MWH_Window: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Window)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Window.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Window.jpg";
	};
	class Bro_MWH_Corner: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Corner)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Corner.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Corner.jpg";
	};

// Static - Roofs
	class Bro_MWH_Roof_Edge: Bro_MWH_Base
	{
		displayName = "Green Warehouse Roof (Edge)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Roof_Edge.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Roof_edge.jpg";
	};
	class Bro_MWH_Roof_Corner: Bro_MWH_Base
	{
		displayName = "Green Warehouse Roof (Corner)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Roof_Corner.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Roof_Corner.jpg";
	};
	class Bro_MWH_Roof_Middle: Bro_MWH_Base
	{
		displayName = "Green Warehouse Roof (Middle)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Roof_Middle.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Roof_Middle.jpg";
	};

// Animated
	class Bro_MWH_Door: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Door)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Door.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Door.jpg";
		numberOfDoors = 1;
		class AnimationSources
		{
			class Door01
			{
				source = "user";
				animPeriod = 0.8;
				initPhase = 0;
				Sound = "MetalDoorsSound";
			};
		};
		class UserActions {
			class Door01_Open {
				displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\open_door_ca.paa' size='2' />";
				displayName = "Open Door";
				radius = 2.0;
				aiMaxRange=5.25;
				Sound = "MetalDoorsSound";
				position = "Door01_trigger";
				onlyForPlayer = 0;
				condition = (this animationPhase 'Door01') < 0.5;
				statement = ([this, 'Door01'] call BIS_fnc_DoorNoHandleOpen);
			};
			class Door01_Close: Door01_Open {
				displayName = "Close Door";
				condition = (this animationPhase 'Door01') >= 0.5;
				statement = ([this, 'Door01'] call BIS_fnc_DoorNoHandleClose);
			};
		};
	};
	class Bro_MWH_Garage: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Garage)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Garage.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Garage.jpg";
		numberOfDoors = 1;
		class AnimationSources
		{
			class Door01
			{
				source = "user";
				animPeriod = 5;
				initPhase = 0;
				SoundPosition = "Door01_trigger";
				Sound = "RollDoorsSound";
			};
			class Door02: Door01 {
				animPeriod = 5;
			};
			class Door03: Door01 {
				animPeriod = 5;
			};
			class Door04: Door01 {
				animPeriod = 5;
			};
		};
		class UserActions
		{
			class Door01_Open
			{
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\arrow_up_gs.paa' size='2' />";
			displayName = "Open Garage";
			radius = 4;
			aiMaxRange=5.25;
			position = "Door01_trigger";
			onlyForPlayer = 0;
			condition = (this animationPhase 'Door04') < 0.5;
			statement = "([this, 'Door01'] call BIS_fnc_DoorNoHandleOpen);([this, 'Door02'] call BIS_fnc_DoorNoHandleOpen);([this, 'Door03'] call BIS_fnc_DoorNoHandleOpen);([this, 'Door04'] call BIS_fnc_DoorNoHandleOpen);";
			};
			class Door01_Close: Door01_Open
			{
			displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\arrow_down_gs.paa' size='2' />";
			displayName = "Close Garage";
			condition = (this animationPhase 'Door04') >= 0.5;
			statement = "([this, 'Door01'] call BIS_fnc_DoorNoHandleClose);([this, 'Door02'] call BIS_fnc_DoorNoHandleClose);([this, 'Door03'] call BIS_fnc_DoorNoHandleClose);([this, 'Door04'] call BIS_fnc_DoorNoHandleClose);";
			};
		};
	};
	class Bro_MWH_Vents: Bro_MWH_Base
	{
		displayName = "Green Warehouse Wall (Vents)";
		scope = 2;
		scopeCurator = 2;
		model = "Bro_Modular_Warehouse\Bro_MWH_Vents.p3d";
		editorPreview = "Bro_Modular_Warehouse\previews\Bro_MWH_Vents.jpg";
		class AnimationSources
		{
			class Fan1
			{
				source = "::time";
				initPhase = 0;
			};
			class Fan2
			{
				source = "::time";
				initPhase = 0;
			};
		};
	};

// Tan variants
	class Bro_MWH_Straight_Tan: Bro_MWH_Straight
	{
		displayName = "Tan Warehouse Wall (Plain)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Straight_Tan.p3d";
	};
	class Bro_MWH_Window_Tan: Bro_MWH_Window
	{
		displayName = "Tan Warehouse Wall (Window)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Window_Tan.p3d";
	};
	class Bro_MWH_Corner_Tan: Bro_MWH_Corner
	{
		displayName = "Tan Warehouse Wall (Corner)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Corner_Tan.p3d";
	};
	class Bro_MWH_Roof_Edge_Tan: Bro_MWH_Roof_Edge
	{
		displayName = "Tan Warehouse Roof (Edge)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Roof_Edge_Tan.p3d";
	};
	class Bro_MWH_Roof_Corner_Tan: Bro_MWH_Roof_Corner
	{
		displayName = "Tan Warehouse Roof (Corner)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Roof_Corner_Tan.p3d";
	};
	class Bro_MWH_Roof_Middle_Tan: Bro_MWH_Roof_Middle
	{
		displayName = "Tan Warehouse Roof (Middle)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Roof_Middle_Tan.p3d";
	};
	class Bro_MWH_Door_Tan: Bro_MWH_Door
	{
		displayName = "Tan Warehouse Wall (Door)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Door_Tan.p3d";
	};
	class Bro_MWH_Garage_Tan: Bro_MWH_Garage
	{
		displayName = "Tan Warehouse Wall (Garage)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Garage_Tan.p3d";
	};
	class Bro_MWH_Vents_Tan: Bro_MWH_Vents
	{
		displayName = "Tan Warehouse Wall (Vents)";
		model = "Bro_Modular_Warehouse\data\tan\Bro_MWH_Vents_Tan.p3d";
	};
};
