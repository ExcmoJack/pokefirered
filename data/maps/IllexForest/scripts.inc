.equ LOCALID_FARFETCHD, 1
.equ LOCALID_HAUNTER, 2
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
	addvar VAR_TEMP_A, 1
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

IllexForest_EventScript_Cartel::
	msgbox IllexForest_Text_Cartel, MSGBOX_SIGN
	end
