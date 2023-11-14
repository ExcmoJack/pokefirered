.equ LOCALID_MISSINGNO, 1
.equ LOCALID_REAL_PLAYER, 4

PokemonTower_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonTower_B3F_OnLoad
	.byte 0

PokemonTower_B3F_OnLoad::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, PokemonTower_B3F_OnLoad_1
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_BOY
	end

PokemonTower_B3F_OnLoad_1::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOMAN_2
	end

PokemonTower_B3F_EventScript_Gengar::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Gengar, MSGBOX_NPC
	end

PokemonTower_B3F_EventScript_Dusclops::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Dusclops, MSGBOX_NPC
	end

PokemonTower_B3F_EventScript_MissingNo_Trigger_R::
	lock
	setvar VAR_TEMP_0, 1
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_B3F_Movement_Player_1
	waitmovement 0
	goto PokemonTower_B3F_EventScript_MissingNo
	end

PokemonTower_B3F_EventScript_MissingNo_Trigger_L::
	lock
	setvar VAR_TEMP_0, 2
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_B3F_Movement_Player_2
	waitmovement 0
	goto PokemonTower_B3F_EventScript_MissingNo
	end

PokemonTower_B3F_EventScript_MissingNo::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoIntro_1
	msgbox PokemonTower_B3F_Text_MissingnoIntro_2
	msgbox PokemonTower_B3F_Text_MissingnoIntro_3
	setvar VAR_MAP_SCENE_POKEMON_TOWER_BASEMENT, 6
	closemessage
	applymovement LOCALID_MISSINGNO, Common_Movement_Disappear
	waitmovement 0
	playse SE_M_SCREECH
	applymovement LOCALID_MISSINGNO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MISSINGNO, Common_Movement_Appear
	waitmovement 0
	applymovement LOCALID_MISSINGNO, PokemonTower_B3F_Movement_MissingNoDown
	waitmovement 0
	msgbox PokemonTower_B3F_Text_MissingnoIntro_4
	msgbox PokemonTower_B3F_Text_MissingnoIntro_5
	closemessage
	applymovement LOCALID_MISSINGNO, Common_Movement_Disappear
	waitmovement 0
	playse SE_M_SCREECH
	applymovement LOCALID_MISSINGNO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_MISSINGNO, Common_Movement_Appear
	waitmovement 0
	applymovement LOCALID_MISSINGNO, PokemonTower_B3F_Movement_MissingNoUp
	waitmovement 0
	msgbox PokemonTower_B3F_Text_MissingnoIntro_6
	msgbox PokemonTower_B3F_Text_MissingnoIntro_7
	msgbox PokemonTower_B3F_Text_MissingnoIntro_8
	closemessage
	callnative SetPlayerNameAtOverworld
	applymovement LOCALID_REAL_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_REAL_PLAYER, Common_Movement_Appear
	waitmovement 0
	msgbox PokemonTower_B3F_Text_MissingnoIntro_9
	closemessage
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, PokemonTower_B3F_Movement_Player_3
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, PokemonTower_B3F_Movement_Cam
	waitmovement 0
	applymovement LOCALID_MISSINGNO, Common_Movement_Disappear
	waitmovement 0
	playse SE_M_SCREECH
	applymovement LOCALID_MISSINGNO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_MISSINGNO, Common_Movement_Appear
	waitmovement 0
	msgbox PokemonTower_B3F_Text_MissingnoIntro_10
	msgbox PokemonTower_B3F_Text_MissingnoIntro_11
	msgbox PokemonTower_B3F_Text_MissingnoIntro_12
	closemessage
	callnative ZeroPlayerPartyMons
	callnative GivePlayerUnownTeam
	callnative SaveGameSilently
	msgbox PokemonTower_B3F_Text_MissingnoIntro_13
	msgbox PokemonTower_B3F_Text_MissingnoIntro_14
	msgbox PokemonTower_B3F_Text_MissingnoIntro_15
	msgbox PokemonTower_B3F_Text_MissingnoIntro_16
	msgbox PokemonTower_B3F_Text_MissingnoIntro_17
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain
	release
	end

PokemonTower_B3F_EventScript_MissingNo_LoopMain::
	lock
	random 7
	switch VAR_RESULT
	case 0 PokemonTower_B3F_EventScript_MissingNo_Comment1
	case 1 PokemonTower_B3F_EventScript_MissingNo_Comment2
	case 2 PokemonTower_B3F_EventScript_MissingNo_Comment3
	case 3 PokemonTower_B3F_EventScript_MissingNo_Comment4
	case 4 PokemonTower_B3F_EventScript_MissingNo_Action1
	case 5 PokemonTower_B3F_EventScript_MissingNo_Action2
	case 6 PokemonTower_B3F_EventScript_MissingNo_Action3
	end

PokemonTower_B3F_EventScript_MissingNo_Comment1::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Comment_1
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain
	end

PokemonTower_B3F_EventScript_MissingNo_Comment2::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Comment_2
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain
	end

PokemonTower_B3F_EventScript_MissingNo_Comment3::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Comment_3
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain
	end

PokemonTower_B3F_EventScript_MissingNo_Comment4::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Comment_4
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain
	end

PokemonTower_B3F_EventScript_MissingNo_Action1::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_1
	random 82
	addvar VAR_RESULT, 264
	fadenewbgm VAR_RESULT
	delay 255
	fadeoutbgm 0
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_EventScript_MissingNo_Action2::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_2
	random SPECIES_HO_OH
	addvar VAR_RESULT, 1
	bufferspeciesname STR_VAR_1, VAR_RESULT
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_EventScript_MissingNo_Action3::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_3
	random SE_POKE_JUMP_SUCCESS
	addvar VAR_RESULT, 1
	playse VAR_RESULT
	waitse
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_Movement_Player_1::
	walk_up
	walk_up
	walk_left
	walk_up
	step_end

PokemonTower_B3F_Movement_Player_2::
	walk_up
	walk_up
	walk_up
	step_end

PokemonTower_B3F_Movement_MissingNoUp::
	lock_facing_direction
	walk_up
	walk_in_place_faster_up
	step_end

PokemonTower_B3F_Movement_MissingNoDown::
	lock_facing_direction
	walk_down
	walk_in_place_faster_down
	step_end

PokemonTower_B3F_Movement_MissingNoLeft::
	lock_facing_direction
	walk_left
	walk_in_place_faster_left
	step_end

PokemonTower_B3F_Movement_MissingNoRight::
	lock_facing_direction
	walk_right
	walk_in_place_faster_right
	step_end

PokemonTower_B3F_Movement_Player_3::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

PokemonTower_B3F_Movement_Cam::
	walk_right
	walk_up
	walk_up
	step_end
