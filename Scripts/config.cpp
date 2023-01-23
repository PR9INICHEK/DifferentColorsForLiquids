
class CfgPatches
{
	class DifferentColorsForLiquids_Scripts
	{
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Scripts"};
	};
};

class CfgMods 
{
	class DZ_DifferentColorsForLiquids
	{
		name = "DifferentColorsForLiquids";
		dir = "DifferentColorsForLiquids";
		credits = "";
		author = "PR9INICHEK";
		type = "mod";
		dependencies[] =
		{
			"Mission"
		};
		class defs
		{
			class missionScriptModule 
			{
				value="";
				files[] = 
				{
					"DifferentColorsForLiquids/scripts/5_Mission"
				};
			};
		};
	};
};
