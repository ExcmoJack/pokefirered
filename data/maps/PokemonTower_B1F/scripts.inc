PokemonTower_B1F_MapScripts::
	.byte 0

PokemonTower_B1F_EventScript_Trigger::
	lock
	fadescreen FADE_TO_BLACK
	delay 10
	playse SE_M_YAWN
	waitse
	addvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_0, 5, PokemonTower_B1F_EventScript_TriggerBlackout
	fadescreen FADE_FROM_BLACK
	msgbox PokemonTower_B1F_Text_Trigger
	closemessage
	release
	end

PokemonTower_B1F_EventScript_TriggerBlackout::
	playse SE_M_SNORE
	waitse
	msgbox PokemonTower_B1F_Text_Trigger_2
	warpsilent MAP_POKEMON_TOWER_B1F, 255, 19, 2
	release
	end