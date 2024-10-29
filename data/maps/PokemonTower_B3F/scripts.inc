.equ LOCALID_MISSINGNO, 1
.equ LOCALID_GENGAR, 3
.equ LOCALID_REAL_PLAYER, 4
.equ LOCALID_PORTAL_1, 5
.equ LOCALID_OAK, 6

@ Personalizar sprites LAVENDER TALES
.equ PLAYER_OVERWORLD_MALE,     OBJ_EVENT_GFX_BOY
.equ PLAYER_OVERWORLD_FEMALE,   OBJ_EVENT_GFX_WOMAN_2

PokemonTower_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonTower_B3F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonTower_B3F_OnFrameTable
	.byte 0

PokemonTower_B3F_OnLoad::
	checkplayergender
	goto_if_eq VAR_RESULT, FEMALE, PokemonTower_B3F_OnLoad_1
	setvar VAR_OBJ_GFX_ID_0, PLAYER_OVERWORLD_MALE
	end

PokemonTower_B3F_OnLoad_1::
	setvar VAR_OBJ_GFX_ID_0, PLAYER_OVERWORLD_FEMALE
	end

PokemonTower_B3F_OnFrameTable::
	map_script_2 VAR_MAP_SCENE_POKEMON_TOWER_B3F_TRIGGERS, 2, PokemonTower_B3F_EventScript_Gengar_DesactivarPortal
	.2byte 0

PokemonTower_B3F_EventScript_Gengar::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Gengar_2, MSGBOX_NPC
	end

PokemonTower_B3F_EventScript_Gengar_Trigger::
	lock
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Gengar
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	clearflag FLAG_PORTAL_1_POKEMON_TOWER_B3F
	msgbox PokemonTower_B3F_Text_Gengar_1
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	playse SE_M_TELEPORT
	addobject LOCALID_PORTAL_1
	applymovement LOCALID_PORTAL_1, Common_Movement_Appear
	waitmovement 0
	applymovement LOCALID_GENGAR, PokemonTower_B3F_Movement_Gengar_1
	waitmovement 0
	applymovement LOCALID_GENGAR, Common_Movement_Disappear
	waitmovement 0
	removeobject LOCALID_GENGAR
	setflag FLAG_GENGAR_POKEMON_TOWER_B3F
	setvar VAR_MAP_SCENE_POKEMON_TOWER_B3F_TRIGGERS, 1
	release
	end

PokemonTower_B3F_EventScript_Gengar_SendPlayerToRuins::
	setrespawn SPAWN_LAVENDER_TOWN
	delay 20
	playse SE_THUNDER
	waitse
	warpteleport MAP_RUINS_OF_ALPH_EXTERIOR, 255, 26, 17
	release
	end

PokemonTower_B3F_EventScript_Gengar_DesactivarPortal::
	lock
	setrespawn SPAWN_LAVENDER_TOWN
	setvar VAR_MAP_SCENE_POKEMON_TOWER_B3F_TRIGGERS, 3
	playse SE_M_TELEPORT
	applymovement LOCALID_PORTAL_1, Common_Movement_Disappear
	waitmovement 0
	removeobject LOCALID_PORTAL_1
	setflag FLAG_PORTAL_1_POKEMON_TOWER_B3F
	release
	end

PokemonTower_B3F_EventScript_Dusclops_Trigger::
	lock
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Dusclops
	closemessage
	clearflag FLAG_POKEMON_TOWER_B3F_OAK
	addobject LOCALID_OAK
	applymovement LOCALID_OAK, Common_Movement_Appear
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PokemonTower_B3F_Text_Oak_1
	closemessage
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Oak_2
	textcolor NPC_TEXT_COLOR_MALE
	closemessage
	call_if_eq VAR_STARTER_MON, 2, PokemonTower_B3F_EventScript_BattleCharmander
	call_if_eq VAR_STARTER_MON, 1, PokemonTower_B3F_EventScript_BattleSquirtle
	call_if_eq VAR_STARTER_MON, 0, PokemonTower_B3F_EventScript_BattleBulbasaur
	setvar VAR_MAP_SCENE_POKEMON_TOWER_B3F_TRIGGERS, 4
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Dusclops_3
	closemessage
	playse SE_M_SWEET_SCENT
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PokemonTower_B3F_Text_Oak_3
	applymovement LOCALID_OAK, PokemonTower_B3F_Movement_Oak_4
	waitmovement LOCALID_OAK
	playse SE_FALL
	closemessage
	waitse
	removeobject LOCALID_OAK
	setflag FLAG_POKEMON_TOWER_B3F_OAK
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Dusclops_2
	closemessage
	release
	end

PokemonTower_B3F_EventScript_BattleSquirtle::
	trainerbattle_no_intro TRAINER_PROF_OAK_SQUIRTLE, PokemonTower_B3F_Text_Oak_3
	return
	end

PokemonTower_B3F_EventScript_BattleBulbasaur::
	trainerbattle_no_intro TRAINER_PROF_OAK_BULBASAUR, PokemonTower_B3F_Text_Oak_3
	return
	end

PokemonTower_B3F_EventScript_BattleCharmander::
	trainerbattle_no_intro TRAINER_PROF_OAK_CHARMANDER, PokemonTower_B3F_Text_Oak_3
	return
	end

PokemonTower_B3F_EventScript_Dusclops::
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_B3F_Text_Dusclops_2, MSGBOX_NPC
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
	random 82
	addvar VAR_RESULT, 264
	buffernumberstring 0, VAR_RESULT
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_1
	playbgm VAR_RESULT, 0
	delay 255
	playbgm MUS_NONE, 0
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_EventScript_MissingNo_Action2::
	textcolor NPC_TEXT_COLOR_EVIL
	random SPECIES_HO_OH
	addvar VAR_RESULT, 1
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_2
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	waitmoncry
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_EventScript_MissingNo_Action3::
	textcolor NPC_TEXT_COLOR_EVIL
	random SE_POKE_JUMP_SUCCESS
	addvar VAR_RESULT, 1
	buffernumberstring 0, VAR_RESULT
	msgbox PokemonTower_B3F_Text_MissingnoLoop_Intro_3
	playse VAR_RESULT
	waitse
	closemessage
	goto PokemonTower_B3F_EventScript_MissingNo_LoopMain

PokemonTower_B3F_Movement_Gengar_1::
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

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

PokemonTower_B3F_Movement_Oak_1::
PokemonTower_B3F_Movement_Oak_2::
PokemonTower_B3F_Movement_Oak_3::
PokemonTower_B3F_Movement_Oak_4::
	lock_facing_direction
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	slide_down
	slide_down
	slide_down
	slide_down
	set_invisible
	step_end