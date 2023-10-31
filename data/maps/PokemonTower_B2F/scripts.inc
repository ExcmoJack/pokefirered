PokemonTower_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonTower_B2F_OnLoad
	.byte 0

PokemonTower_B2F_OnLoad::
	call_if_set FLAG_POKEMON_TOWER_B2F_BUTTON_1, PokemonTower_B2F_EventScript_Button1Action
	call_if_set FLAG_POKEMON_TOWER_B2F_BUTTON_2, PokemonTower_B2F_EventScript_Button2Action
	call_if_set FLAG_POKEMON_TOWER_B2F_BUTTON_3, PokemonTower_B2F_EventScript_Button3Action
	call_if_set FLAG_POKEMON_TOWER_B2F_BUTTON_4, PokemonTower_B2F_EventScript_Button4Action
	call_if_set FLAG_POKEMON_TOWER_B2F_BUTTON_5, PokemonTower_B2F_EventScript_Button5Action
	end

PokemonTower_B2F_EventScript_Button1::
	lock
	setflag FLAG_POKEMON_TOWER_B2F_BUTTON_1
	call PokemonTower_B2F_EventScript_ButtonFx
	call PokemonTower_B2F_EventScript_Button1Action
	release
	end

PokemonTower_B2F_EventScript_Button1Action::
	setvar VAR_TEMP_0, 14
	setvar VAR_TEMP_1, 18
	setvar VAR_TEMP_2, 15
	setvar VAR_TEMP_3, 18
	setvar VAR_TEMP_4, 14
	setvar VAR_TEMP_5, 19
	call PokemonTower_B2F_EventScript_ButtonActionCommon
	return
	end

PokemonTower_B2F_EventScript_Button2::
	lock
	setflag FLAG_POKEMON_TOWER_B2F_BUTTON_2
	call PokemonTower_B2F_EventScript_ButtonFx
	call PokemonTower_B2F_EventScript_Button2Action
	release
	end

PokemonTower_B2F_EventScript_Button2Action::
	setvar VAR_TEMP_0, 10
	setvar VAR_TEMP_1, 16
	setvar VAR_TEMP_2, 11
	setvar VAR_TEMP_3, 16
	setvar VAR_TEMP_4, 20
	setvar VAR_TEMP_5, 15
	call PokemonTower_B2F_EventScript_ButtonActionCommon
	return
	end

PokemonTower_B2F_EventScript_Button3::
	lock
	setflag FLAG_POKEMON_TOWER_B2F_BUTTON_3
	call PokemonTower_B2F_EventScript_ButtonFx
	call PokemonTower_B2F_EventScript_Button3Action
	release
	end

PokemonTower_B2F_EventScript_Button3Action::
	setvar VAR_TEMP_0, 6
	setvar VAR_TEMP_1, 14
	setvar VAR_TEMP_2, 7
	setvar VAR_TEMP_3, 14
	setvar VAR_TEMP_4, 17
	setvar VAR_TEMP_5, 8
	call PokemonTower_B2F_EventScript_ButtonActionCommon
	return
	end

PokemonTower_B2F_EventScript_Button4::
	lock
	setflag FLAG_POKEMON_TOWER_B2F_BUTTON_4
	call PokemonTower_B2F_EventScript_ButtonFx
	call PokemonTower_B2F_EventScript_Button4Action
	release
	end

PokemonTower_B2F_EventScript_Button4Action::
	setvar VAR_TEMP_0, 19
	setvar VAR_TEMP_1, 11
	setvar VAR_TEMP_2, 19
	setvar VAR_TEMP_3, 12
	setvar VAR_TEMP_4, 2
	setvar VAR_TEMP_5, 12
	call PokemonTower_B2F_EventScript_ButtonActionCommon
	return
	end

PokemonTower_B2F_EventScript_Button5::
	lock
	setflag FLAG_POKEMON_TOWER_B2F_BUTTON_5
	call PokemonTower_B2F_EventScript_ButtonFx
	call PokemonTower_B2F_EventScript_Button5Action
	clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	release
	end

PokemonTower_B2F_EventScript_Button5Action::
	setvar VAR_TEMP_0, 7
	setvar VAR_TEMP_1, 3
	setvar VAR_TEMP_2, 7
	setvar VAR_TEMP_3, 4
	setvar VAR_TEMP_4, 21
	setvar VAR_TEMP_5, 6
	call PokemonTower_B2F_EventScript_ButtonActionCommon
	return
	end

PokemonTower_B2F_EventScript_ButtonFx::
	addvar VAR_MAP_SCENE_POKEMON_TOWER_BASEMENT, 1
	playse SE_PIN
	waitse
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	return
	end

PokemonTower_B2F_EventScript_ButtonActionCommon::
	setmetatile VAR_TEMP_0, VAR_TEMP_1, 0x2D9, 0
	setmetatile VAR_TEMP_2, VAR_TEMP_3, 0x2D9, 0
	setmetatile VAR_TEMP_4, VAR_TEMP_5, 0x327, 0
	special DrawWholeMapView
	return
	end

PokemonTower_B2F_EventScript_Gastly::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	setwildbattle SPECIES_GASTLY, 25, ITEM_BRIGHT_POWDER
	dowildbattle
	applymovement VAR_LAST_TALKED Common_Movement_Disappear
	removeobject VAR_LAST_TALKED
	release
	end

PokemonTower_B2F_EventScript_Healing::
	lock
	faceplayer
	msgbox PokemonTower_B2F_Text_Healing_1
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox PokemonTower_B2F_Text_Healing_2
	closemessage
	release
	end
