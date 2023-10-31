.equ LOCALID_PORTAL, 2

LavenderTown_House1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavenderTown_House1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavenderTown_House1_OnFrame
	.byte 0

LavenderTown_House1_OnLoad::
	goto_if_set FLAG_GET_MR_MIME_CARMIN, LavenderTown_House1_OnLoad1
	end

LavenderTown_House1_OnLoad1::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	end

LavenderTown_House1_OnFrame::
	map_script_2 VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE1, 2, LavenderTown_House1_EventScript_DesactivarPortal
	.2byte 0

LavenderTown_House1_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_unset FLAG_PORTAL_HOUSE1, LavenderTown_House1_EventScript_CooltrainerF_2
	goto_if_set FLAG_GET_MR_MIME_CARMIN, LavenderTown_House1_EventScript_CooltrainerF_3
	msgbox LavenderTown_House1_Text_HistoriaMrMime_1, MSGBOX_YESNO
	switch VAR_RESULT
	case YES LavenderTown_House1_EventScript_CooltrainerFGhostGone
	release
	end

LavenderTown_House1_EventScript_CooltrainerFGhostGone::
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE1, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox LavenderTown_House1_Text_HistoriaMrMime_2
	closemessage
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox LavenderTown_House1_Text_HistoriaMrMime_3
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	clearflag FLAG_PORTAL_HOUSE1
	msgbox LavenderTown_House1_Text_HistoriaMrMime_4
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

LavenderTown_House1_EventScript_SendPlayerToVermillion::
	setrespawn SPAWN_VERMILION_CITY
	delay 20
	playse SE_THUNDER
	waitse
	warpteleport MAP_VERMILION_CITY, 255, 23, 6
	release
	end

LavenderTown_House1_EventScript_DesactivarPortal::
	lock
	setrespawn SPAWN_LAVENDER_TOWN
	addvar VAR_MAP_SCENE_LAVENDER_TOWN, 1
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE1, 3
	playse SE_M_TELEPORT
	applymovement LOCALID_PORTAL, Common_Movement_Disappear
	waitmovement 0
	setflag FLAG_PORTAL_HOUSE1
	call_if_eq VAR_MAP_SCENE_LAVENDER_TOWN, 3, LavenderTown_EventScript_UnblockTriggerCasaFuji
	release
	end

LavenderTown_House1_EventScript_CooltrainerF_2::
	msgbox LavenderTown_House1_Text_HistoriaMrMime_4, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_CooltrainerF_3::
	msgbox LavenderTown_House1_Text_HistoriaMrMime_5, MSGBOX_NPC
	end

LavenderTown_House1_EventScript_Cubone::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CUBONE, CRY_MODE_NORMAL
	msgbox LavenderTown_House1_Text_Cubone
	waitmoncry
	release
	end