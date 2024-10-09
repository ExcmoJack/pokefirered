.equ LOCALID_FARFETCHD, 1
.equ LOCALID_HAUNTER, 2
.equ LOCALID_CELEBI, 3
.equ LOCALID_CESAR, 6
.equ LOCALID_KARATEKA, 9
.equ LOCALID_GENGAR, 12

IllexForest_MapScripts::
	.byte 0


IllexForest_EventScript_Cesar::
	lock
	faceplayer
	call_if_unset FLAG_TALKED_CESAR, IllexForest_EventScript_Cesar_1
	msgbox IllexForest_Text_Cesar_3, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, EventScript_OutOfCenterPartyHeal
	msgbox IllexForest_Text_Cesar_4
	closemessage
	release
	end

IllexForest_EventScript_Cesar_1::
	setflag FLAG_TALKED_CESAR
	msgbox IllexForest_Text_Cesar_1
	closemessage
	msgbox IllexForest_Text_Cesar_2
	closemessage
	return

IllexForest_EventScript_Karateka::
	lock
	msgbox IllexForest_Text_Karateka_1, MSGBOX_NPC
	release
	end

IllexForest_EventScript_Gastly_1::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Gastly_1
	closemessage
	setwildbattle SPECIES_GASTLY, 10, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_Gastly_2::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Gastly_2
	closemessage
	setwildbattle SPECIES_GASTLY, 10, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_Gastly_3::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Gastly_3
	closemessage
	setwildbattle SPECIES_GASTLY, 15, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_Gastly_4::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Gastly_4
	closemessage
	setwildbattle SPECIES_GASTLY, 15, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_Gastly_5::
	lock
	faceplayer
	playmoncry SPECIES_GASTLY, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Gastly_5
	closemessage
	setwildbattle SPECIES_GASTLY, 15, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_Haunter::
	lock
	faceplayer
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox IllexForest_Text_Haunter
	closemessage
	setwildbattle SPECIES_HAUNTER, 15, ITEM_NONE
	dowildbattle
	call IllexForest_EventScript_CommonDisapearNpc
	release
	end

IllexForest_EventScript_CommonDisapearNpc::
	addvar VAR_MAP_SCENE_ILEX_FOREST, 1
	applymovement VAR_LAST_TALKED, Common_Movement_Disappear
	removeobject VAR_LAST_TALKED
	return

IllexForest_EventScript_Farfetchd::
	lock
	faceplayer
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox IllexForest_Text_Farfetchd_1
	closemessage
	waitmoncry
	givemon SPECIES_FARFETCHD, 26, ITEM_STICK
	call EventScript_GetGiftMonPartySlot
	call EventScript_ChangePokemonNickname
	delay 20
	checkpartymove MOVE_FURY_CUTTER
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	playfanfare MUS_EVOLVED
	message Text_PkmnJoinedTeam
	waitmessage
	waitfanfare
	delay 20
	removeobject LOCALID_FARFETCHD
	setflag FLAG_HIDE_FARFETCHD_ILEX_FOREST
	release
	end

IllexForest_EventScript_Gengar::
	lock
	faceplayer
	textcolor NPC_TEXT_COLOR_EVIL
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
	msgbox IllexForest_Text_Gengar_1
	closemessage
	waitmoncry
	setwildbattle SPECIES_GENGAR, 25
	dowildbattle
	msgbox IllexForest_Text_Gengar_2
	closemessage
	applymovement LOCALID_GENGAR, Common_Movement_Disappear
	waitmovement 0
	removeobject LOCALID_GENGAR
	playmoncry SPECIES_GENGAR, CRY_MODE_WEAK
	msgbox IllexForest_Text_Gengar_3
	closemessage
	waitmoncry
	setflag FLAG_HIDE_GENGAR_ILEX_FOREST
	addvar VAR_MAP_SCENE_ILEX_FOREST, 1
	release
	end

IllexForest_EventScript_Celebi::
	lock
	checkitem ITEM_GS_BALL, 1
	goto_if_eq VAR_RESULT, 1, IllexForest_EventScript_Celebi_HasGsBall
	msgbox IllexForest_Text_Celebi_NoGsBall, MSGBOX_SIGN
	closemessage
	release
	end

IllexForest_EventScript_Celebi_HasGsBall::
	goto_if_eq VAR_MAP_SCENE_ILEX_FOREST, 7, IllexForest_EventScript_Celebi_MustAppear
	msgbox IllexForest_Text_Celebi_NoGsBall, MSGBOX_SIGN
	closemessage
	release
	end

IllexForest_EventScript_Celebi_MustAppear::
	msgbox IllexForest_Text_Celebi_NoGsBall, MSGBOX_SIGN
	closemessage
	msgbox IllexForest_Text_Celebi_UseGsBall
	closemessage
	clearflag FLAG_HIDE_CELEBI_ILEX_FOREST
	addobject LOCALID_CELEBI
	applymovement LOCALID_CELEBI, IllexForest_Movement_Celebi_Appear
	waitmovement 0
	playmoncry SPECIES_CELEBI, CRY_MODE_NORMAL
	showmonpic SPECIES_CELEBI, 10, 3
	waitbuttonpress
	hidemonpic
	waitmoncry
	givemon SPECIES_CELEBI, 20, ITEM_LEFTOVERS
	delay 20
	bufferspeciesname STR_VAR_1, SPECIES_CELEBI
	playfanfare MUS_EVOLVED
	message Text_PkmnJoinedTeam
	waitmessage
	waitfanfare
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 20
	msgbox IllexForest_Text_Celebi_SendHome
	closemessage
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
	setflag FLAG_GET_MONS_ILEX_FOREST
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 2
	warpteleport MAP_LAVENDER_TOWN_HOUSE2, 255, 9, 4
	release
	end

IllexForest_EventScript_TriggerEscape::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, IllexForest_EventScript_TriggerEscapeSouth
	case DIR_NORTH, IllexForest_EventScript_TriggerEscapeNorth
	case DIR_EAST, IllexForest_EventScript_TriggerEscapeEast
	case DIR_WEST, IllexForest_EventScript_TriggerEscapeWest
	end
IllexForest_EventScript_TriggerEscapeSouth::
	applymovement OBJ_EVENT_ID_PLAYER, IllexForest_Movement_PlayerTriggerEscapingSouth
	waitmovement 0
	goto IllexForest_EventScript_TriggerEscapeEnd

IllexForest_EventScript_TriggerEscapeNorth::
	applymovement OBJ_EVENT_ID_PLAYER, IllexForest_Movement_PlayerTriggerEscapingNorth
	waitmovement 0
	goto IllexForest_EventScript_TriggerEscapeEnd

IllexForest_EventScript_TriggerEscapeEast::
	applymovement OBJ_EVENT_ID_PLAYER, IllexForest_Movement_PlayerTriggerEscapingEast
	waitmovement 0
	goto IllexForest_EventScript_TriggerEscapeEnd

IllexForest_EventScript_TriggerEscapeWest::
	applymovement OBJ_EVENT_ID_PLAYER, IllexForest_Movement_PlayerTriggerEscapingWest
	waitmovement 0
	goto IllexForest_EventScript_TriggerEscapeEnd

IllexForest_EventScript_TriggerEscapeEnd::
	msgbox LavenderTown_Text_TriggerEscape
	closemessage
	fadescreen FADE_TO_BLACK
	delay 10
	addvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_0, 5, IllexForest_EventScript_TriggerEscapeBlackout
	fadescreen FADE_FROM_BLACK
	msgbox LavenderTown_Text_TriggerEscape1
	closemessage
	release
	end

IllexForest_EventScript_TriggerEscapeBlackout::
	msgbox LavenderTown_Text_TriggerEscapeBlackout
	warpsilent MAP_ILLEX_FOREST, 255, 3, 38
	release
	end

IllexForest_EventScript_Cartel::
	msgbox IllexForest_Text_Cartel, MSGBOX_SIGN
	end

IllexForest_Movement_Celebi_Appear::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down

IllexForest_Movement_PlayerTriggerEscapingNorth::
	lock_facing_direction
	slide_down
	unlock_facing_direction
	step_end

IllexForest_Movement_PlayerTriggerEscapingSouth::
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end

IllexForest_Movement_PlayerTriggerEscapingEast::
	lock_facing_direction
	slide_left
	unlock_facing_direction
	step_end

IllexForest_Movement_PlayerTriggerEscapingWest::
	lock_facing_direction
	slide_right
	unlock_facing_direction
	step_end
	step_end