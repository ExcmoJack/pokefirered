.equ LOCALID_PORTAL, 7


LavenderTown_VolunteerPokemonHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LavenderTown_VolunteerPokemonHouse_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavenderTown_VolunteerPokemonHouse_OnFrame
	.byte 0

LavenderTown_VolunteerPokemonHouse_OnLoad::
	goto_if_eq VAR_MAP_SCENE_LAVENDER_TOWN_VOLUNTEER_HOUSE, 2, LavenderTown_VolunteerPokemonHouse_OnLoad1
	end

LavenderTown_VolunteerPokemonHouse_OnLoad1::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	end

LavenderTown_VolunteerPokemonHouse_OnFrame::
	map_script_2 VAR_MAP_SCENE_LAVENDER_TOWN_VOLUNTEER_HOUSE, 2, LavenderTown_VolunteerPokemonHouse_EventScript_DesactivarPortal
	.2byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	goto_if_set FLAG_PORTAL_VOLUNTEER_HOUSE, LavenderTown_VolunteerPokemonHouse_EventScript_HistoriaFuji
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HistoriaVulpix3, MSGBOX_NPC
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	@ famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GET_VULPIX_MT_PYRE, LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy2::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug2
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_GET_VULPIX_MT_PYRE, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_VolunteerPokemonHouse_EventScript_HistoriaFuji::
	lock
	faceplayer
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE1, 1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HistoriaVulpix1
	closemessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HistoriaVulpix2
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	clearflag FLAG_PORTAL_VOLUNTEER_HOUSE
	textcolor NPC_TEXT_COLOR_MALE
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HistoriaVulpix3
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
	
	LavenderTown_VolunteerPokemonHouse_EventScript_SendPlayerToMtPyre::
	setrespawn SPAWN_MT_PYRE
	delay 20
	playse SE_THUNDER
	waitse
	warpteleport MAP_MT_PYRE_1F, 255, 12, 5
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_DesactivarPortal::
	lock
	setrespawn SPAWN_LAVENDER_TOWN
	addvar VAR_MAP_SCENE_LAVENDER_TOWN, 1
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_VOLUNTEER_HOUSE, 3
	playse SE_M_TELEPORT
	applymovement LOCALID_PORTAL, Common_Movement_Disappear
	waitmovement 0
	setflag FLAG_PORTAL_VOLUNTEER_HOUSE
	release
	end