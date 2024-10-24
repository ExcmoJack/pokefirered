.set LOCALID_GASTLY_1,  1
.set LOCALID_GASTLY_2,  2
.set LOCALID_GASTLY_3,  3
.set LOCALID_GASTLY_4,  4
.set LOCALID_GASTLY_5,  5
.set LOCALID_GASTLY_6,  6
.set LOCALID_HAUNTER_1, 7
.set LOCALID_HAUNTER_2, 8
.set LOCALID_HAUNTER_3, 9
.set LOCALID_FISHER, 	10
.set LOCALID_LADY, 		11
.set LOCALID_FUJI, 		12
.set LOCALID_ENTEI,		13

RuinsOfAlph_MainChamber_MapScripts::
	.byte 0

RuinsOfAlph_MainChamber_EventScript_Fisherman::
	goto_if_set FLAG_HIDE_GHOSTS_1_RUINS_OF_ALPH, RuinsOfAlph_MainChamber_EventScript_SaveFisherman
	msgbox RuinsOfAlph_MainChamber_Text_Fisherman_1 MSGBOX_NPC
	end

RuinsOfAlph_MainChamber_EventScript_Lady::
	msgbox RuinsOfAlph_MainChamber_Text_Lady_1 MSGBOX_NPC
	end

RuinsOfAlph_MainChamber_EventScript_MrFuji::
	msgbox RuinsOfAlph_MainChamber_Text_MrFuji_1 MSGBOX_NPC
	end

RuinsOfAlph_MainChamber_EventScript_SaveFisherman::
	msgbox RuinsOfAlph_MainChamber_Text_Fisherman_2 MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_FISHER_RUINS_OF_ALPH
	clearflag FLAG_HIDE_FISHER_RUINS_OF_ALPH_EXT
	removeobject LOCALID_FISHER
	fadescreen FADE_FROM_BLACK
	end

RuinsOfAlph_MainChamber_EventScript_SaveLady::
	msgbox RuinsOfAlph_MainChamber_Text_Lady_2 MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_LADY_RUINS_OF_ALPH
	removeobject LOCALID_LADY
	fadescreen FADE_FROM_BLACK
	end

RuinsOfAlph_MainChamber_EventScript_SaveFuji::
	msgbox RuinsOfAlph_MainChamber_Text_MrFuji_2 MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_MR_FUJI_RUINS_OF_ALPH
	removeobject LOCALID_FUJI
	fadescreen FADE_FROM_BLACK
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBattle_1::
	lock
	call RuinsOfAlph_MainChamber_EventScript_GastlyBattle
	removeobject LOCALID_GASTLY_1
	removeobject LOCALID_GASTLY_2
	setflag FLAG_HIDE_GHOSTS_1_RUINS_OF_ALPH
	setvar VAR_MAP_SCENE_RUINS_OF_ALPH_STATUS, 1
	release
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBattle_2::
	lock
	call RuinsOfAlph_MainChamber_EventScript_GastlyBattle
	removeobject LOCALID_GASTLY_3
	removeobject LOCALID_GASTLY_4
	setflag FLAG_HIDE_GHOSTS_2_RUINS_OF_ALPH
	setvar VAR_MAP_SCENE_RUINS_OF_ALPH_STATUS, 2
	release
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBattle_3::
	lock
	call RuinsOfAlph_MainChamber_EventScript_GastlyBattle
	removeobject LOCALID_GASTLY_5
	removeobject LOCALID_GASTLY_6
	setflag FLAG_HIDE_GHOSTS_3_RUINS_OF_ALPH
	setvar VAR_MAP_SCENE_RUINS_OF_ALPH_STATUS, 3
	release
	end

RuinsOfAlph_MainChamber_EventScript_HaunterBattle::
	lock
	setwildbattle SPECIES_HAUNTER, 30, ITEM_SPELL_TAG
	dowildbattle
	setwildbattle SPECIES_HAUNTER, 30, ITEM_SPELL_TAG
	dowildbattle
	setwildbattle SPECIES_HAUNTER, 30, ITEM_SPELL_TAG
	dowildbattle
	removeobject LOCALID_HAUNTER_1
	removeobject LOCALID_HAUNTER_2
	removeobject LOCALID_HAUNTER_3
	setflag FLAG_HIDE_GHOSTS_4_RUINS_OF_ALPH
	setvar VAR_MAP_SCENE_RUINS_OF_ALPH_STATUS, 4
	release
	end

RuinsOfAlph_MainChamber_EventScript_EnteiEvent::
	lock
	setweather WEATHER_SANDSTORM
	doweather
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, RuinsOfAlph_MainChamber_Movement_Cam_1
	waitmovement OBJ_EVENT_ID_CAMERA
	clearflag FLAG_HIDE_ENTEI_RUINS_OF_ALPH
	addobject LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_Appear
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterUp
	waitmovement LOCALID_ENTEI
	playmoncry SPECIES_ENTEI, CRY_MODE_ECHO_START
	waitmoncry
	playmoncry SPECIES_ENTEI, CRY_MODE_ECHO_END
	waitmoncry
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	fadescreen FADE_TO_WHITE
	delay 1
	fadescreen FADE_FROM_WHITE
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_MainChamber_Movement_Cam_1
	waitmovement OBJ_EVENT_ID_PLAYER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox RuinsOfAlph_MainChamber_Text_Entei_1
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterUp
	waitmovement LOCALID_ENTEI
	playmoncry SPECIES_ENTEI, CRY_MODE_ECHO_START
	waitmoncry
	playmoncry SPECIES_ENTEI, CRY_MODE_ECHO_END
	waitmoncry
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	closemessage
	seteventmon SPECIES_ENTEI, 30
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	delay 2
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_ENTEI
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox RuinsOfAlph_MainChamber_Text_Entei_2
	delay 2
	closemessage
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement LOCALID_ENTEI
	applymovement LOCALID_ENTEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_ENTEI
	msgbox RuinsOfAlph_MainChamber_Text_Entei_3
	delay 20
	givemon SPECIES_ENTEI, 30, ITEM_KINGS_ROCK
	bufferspeciesname STR_VAR_1, SPECIES_ENTEI
	playfanfare MUS_EVOLVED
	message Text_PkmnJoinedTeam
	waitmessage
	waitfanfare
	delay 20
	msgbox RuinsOfAlph_MainChamber_Text_Entei_4
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 10
	playse SE_THUNDER
	waitse
	setvar VAR_MAP_SCENE_POKEMON_TOWER_B3F_TRIGGERS, 2
	warpteleport MAP_POKEMON_TOWER_B3F, 255, 8, 28
	release
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBattle::
	setwildbattle SPECIES_GASTLY, 30, ITEM_BRIGHT_POWDER
	dowildbattle
	setwildbattle SPECIES_GASTLY, 30, ITEM_BRIGHT_POWDER
	dowildbattle
	return
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBlock_North::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_Movement_PlayerTriggerEscapingNorth
	waitmovement 0
	msgbox RuinsOfAlph_MainChamber_Text_Blocking
	closemessage
	release
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBlock_South::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_Movement_PlayerTriggerEscapingSouth
	waitmovement 0
	msgbox RuinsOfAlph_MainChamber_Text_Blocking
	closemessage
	release
	end

RuinsOfAlph_MainChamber_EventScript_GastlyBlock_West::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, RuinsOfAlph_Movement_PlayerTriggerEscapingWest
	waitmovement 0
	msgbox RuinsOfAlph_MainChamber_Text_Blocking
	closemessage
	release
	end

RuinsOfAlph_MainChamber_Movement_Cam_1::
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RuinsOfAlph_MainChamber_Movement_Cam_2::
	walk_right
	step_end

RuinsOfAlph_Movement_PlayerTriggerEscapingNorth::
	lock_facing_direction
	slide_down
	unlock_facing_direction
	step_end

RuinsOfAlph_Movement_PlayerTriggerEscapingSouth::
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end

RuinsOfAlph_Movement_PlayerTriggerEscapingWest::
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end
