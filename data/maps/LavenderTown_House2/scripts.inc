.equ LOCALID_PORTAL, 2

LavenderTown_House2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavenderTown_House2_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavenderTown_House2_OnFrame
	.byte 0

LavenderTown_House2_OnLoad::
	goto_if_set FLAG_GET_MONS_ILEX_FOREST, LavenderTown_House2_OnLoad1
	end

LavenderTown_House2_OnLoad1::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	end

LavenderTown_House2_OnFrame::
	map_script_2 VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 2, LavenderTown_House2_EventScript_DesactivarPortal
	.2byte 0

LavenderTown_House2_EventScript_NameRater::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 1, LavenderTown_House2_EventScript_Inspector1
	goto_if_eq VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 3, LavenderTown_House2_EventScript_Inspector2
	msgbox LavenderTown_House2_Text_Inspector_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_InspectorHistoria
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_Inspector1::
	msgbox LavenderTown_House2_Text_Inspector_5, MSGBOX_NPC
	release
	end

LavenderTown_House2_EventScript_Inspector2::
	msgbox LavenderTown_House2_Text_Inspector_6, MSGBOX_NPC
	release
	end

LavenderTown_House2_EventScript_ChooseMon::
	msgbox LavenderTown_House2_Text_CritiqueWhichMonsNickname
	special ChoosePartyMon
	waitstate
	goto_if_lt VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_CheckCanRateMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_DontRateNickname::
	release
	end

LavenderTown_House2_EventScript_CheckCanRateMon::
	specialvar VAR_RESULT, GetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, LavenderTown_House2_EventScript_CantNicknameEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	specialvar VAR_RESULT, IsMonOTNameNotPlayers
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_CantNicknameTradeMon
	msgbox LavenderTown_House2_Text_GiveItANicerName, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LavenderTown_House2_EventScript_ChooseNewNickname
	goto_if_eq VAR_RESULT, NO, LavenderTown_House2_EventScript_DontRateNickname
	end

LavenderTown_House2_EventScript_CantNicknameEgg::
	msgbox LavenderTown_House2_Text_ThatIsMerelyAnEgg
	release
	end

LavenderTown_House2_EventScript_CantNicknameTradeMon::
	msgbox LavenderTown_House2_Text_TrulyImpeccableName
	release
	end

LavenderTown_House2_EventScript_ChooseNewNickname::
	msgbox LavenderTown_House2_Text_WhatShallNewNicknameBe
	call EventScript_ChangePokemonNickname
	specialvar VAR_RESULT, NameRaterWasNicknameChanged
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, LavenderTown_House2_EventScript_ChoseNewNickname
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsSameName
	release
	end

LavenderTown_House2_EventScript_ChoseNewNickname::
	msgbox LavenderTown_House2_Text_FromNowOnShallBeKnownAsName
	release
	end

LavenderTown_House2_EventScript_InspectorHistoria::
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox LavenderTown_House2_Text_Inspector_2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox LavenderTown_House2_Text_Inspector_Historia_Farfetchd
	closemessage
	textcolor NPC_TEXT_COLOR_MALE
	msgbox LavenderTown_House2_Text_Inspector_3
	closemessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox LavenderTown_House2_Text_Inspector_Historia_Celebi
	closemessage
	textcolor NPC_TEXT_COLOR_MALE
	msgbox LavenderTown_House2_Text_Inspector_4
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	clearflag FLAG_PORTAL_HOUSE2
	msgbox LavenderTown_House2_Text_Inspector_5
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	playse SE_M_TELEPORT
	addobject LOCALID_PORTAL
	applymovement LOCALID_PORTAL, Common_Movement_Appear
	waitmovement 0
	release
	end

LavenderTown_House2_EventScript_SendPlayerToIlexForest::
	lock
	delay 20
	playse SE_THUNDER
	waitse
	warpteleport MAP_ILLEX_FOREST, 255, 3, 38
	release
	end

LavenderTown_House2_EventScript_DesactivarPortal::
	lock
	addvar VAR_MAP_SCENE_LAVENDER_TOWN, 1
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE2, 3
	playse SE_M_TELEPORT
	applymovement LOCALID_PORTAL, Common_Movement_Disappear
	waitmovement 0
	setflag FLAG_PORTAL_HOUSE2
	call_if_eq VAR_MAP_SCENE_LAVENDER_TOWN, 2, LavenderTown_EventScript_UnblockTriggerCasaFuji
	release
	end