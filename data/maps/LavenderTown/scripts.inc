LavenderTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_OnTransition
	.byte 0

LavenderTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	end

LavenderTown_EventScript_LittleGirl::
	lock
	faceplayer
	msgbox LavenderTown_Text_DoYouBelieveInGhosts, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_EventScript_LittleGirlBelieve
	msgbox LavenderTown_Text_JustImaginingWhiteHand
	release
	end

LavenderTown_EventScript_LittleGirlBelieve::
	msgbox LavenderTown_Text_SoThereAreBelievers
	release
	end

LavenderTown_EventScript_WorkerM::
	msgbox LavenderTown_Text_TownKnownAsMonGraveSite, MSGBOX_NPC
	end

LavenderTown_EventScript_Boy::
	msgbox LavenderTown_Text_GhostsAppearedInTower, MSGBOX_NPC
	end

LavenderTown_EventScript_TownSign::
	msgbox LavenderTown_Text_TownSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_SilphScopeNotice::
	msgbox LavenderTown_Text_SilphScopeNotice, MSGBOX_SIGN
	end

LavenderTown_EventScript_VolunteerHouseSign::
	msgbox LavenderTown_Text_VolunteerPokemonHouse, MSGBOX_SIGN
	end

LavenderTown_EventScript_PokemonTowerSign::
	msgbox LavenderTown_Text_PokemonTowerSign, MSGBOX_SIGN
	end

LavenderTown_EventScript_TriggerEscape::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, LavenderTown_EventScript_TriggerEscapeSouth
	case DIR_NORTH, LavenderTown_EventScript_TriggerEscapeNorth
	case DIR_WEST, LavenderTown_EventScript_TriggerEscapeWest
	end
	
LavenderTown_EventScript_TriggerEscapeSouth::
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_Movement_PlayerTriggerEscapingSouth
	waitmovement 0
	goto LavenderTown_EventScript_TriggerEscapeEnd

LavenderTown_EventScript_TriggerEscapeNorth::
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_Movement_PlayerTriggerEscapingNorth
	waitmovement 0
	goto LavenderTown_EventScript_TriggerEscapeEnd

LavenderTown_EventScript_TriggerEscapeWest::
	applymovement OBJ_EVENT_ID_PLAYER, LavenderTown_Movement_PlayerTriggerEscapingWest
	waitmovement 0
	goto LavenderTown_EventScript_TriggerEscapeEnd

LavenderTown_EventScript_TriggerEscapeEnd::
	msgbox LavenderTown_Text_TriggerEscape
	closemessage
	fadescreen FADE_TO_BLACK
	delay 10
	addvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_0, 5, LavenderTown_EventScript_TriggerEscapeBlackout
	fadescreen FADE_FROM_BLACK
	msgbox LavenderTown_Text_TriggerEscape1
	closemessage
	release
	end

LavenderTown_EventScript_TriggerEscapeBlackout::
	msgbox LavenderTown_Text_TriggerEscapeBlackout
	warpsilent MAP_LAVENDER_TOWN_POKEMON_CENTER_1F, 255, 7, 4
	release
	end

LavenderTown_Movement_PlayerTriggerEscapingNorth::
	lock_facing_direction
	slide_down
	unlock_facing_direction
	step_end

LavenderTown_Movement_PlayerTriggerEscapingSouth::
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end

LavenderTown_Movement_PlayerTriggerEscapingWest::
	lock_facing_direction
	slide_right
	unlock_facing_direction
	step_end
