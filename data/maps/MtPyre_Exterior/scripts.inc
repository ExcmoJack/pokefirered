MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition::
	goto_if_eq VAR_MAP_SCENE_MT_PYRE_EXTERIOR_WEATHER, 1, MtPyre_Exterior_OnTransition1
	end

MtPyre_Exterior_OnTransition1::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	end


MtPyre_Exterior_EventScript_SetFog::
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR_WEATHER, 1
	end

MtPyre_Exterior_EventScript_SetSun::
	setweather WEATHER_NONE
	doweather
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR_WEATHER, 0
	end