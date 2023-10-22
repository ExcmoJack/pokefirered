.equ LOCALID_FERRY_SAILOR, 6
.equ LOCALID_MR_MIME, 4

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 1, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	msgbox VermilionCity_Text_DungeonUnblocked
	closemessage
	setvar VAR_MAP_SCENE_VERMILION_CITY, 2
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	end

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	trainerbattle_single TRAINER_PICNICKER_ISABELLE, VermilionCity_Text_WomanBattle, VermilionCity_Text_WomanBattle2
	msgbox VermilionCity_Text_BattleAfter
	release
	end

VermilionCity_EventScript_OldMan1::
	trainerbattle_single TRAINER_YOUNGSTER_YASU, VermilionCity_Text_BattleOldMan, VermilionCity_Text_BattleOldManWin
	msgbox VermilionCity_Text_BattleAfter
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTICHOICE_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTICHOICE_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTICHOICE_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 19, 5, MULTICHOICE_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

@ Unreachable
Vermilion_EventScript_Unused::
	release
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	trainerbattle_single TRAINER_SAILOR_TREVOR, VermilionCity_Text_SailorBattle, VermilionCity_Text_SailorBattle2
	msgbox VermilionCity_Text_BattleAfter
	release
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	trainerbattle_single TRAINER_YOUNGSTER_DAVE, VermilionCity_Text_BattleOldMan2, VermilionCity_Text_BattleOldMan2Win
	msgbox VermilionCity_Text_BattleAfter
	release
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	playse SE_M_TELEPORT
	applymovement LOCALID_MR_MIME, Common_Movement_Disappear
	waitmovement 0
	msgbox VermilionCity_Text_MachopStompingLandFlat
	closemessage
	setvar VAR_MAP_SCENE_VERMILION_CITY, 1
	removeobject LOCALID_MR_MIME
	release
	end

VermilionCity_EventScript_Gastly::
	msgbox VermilionCity_Text_BattleAfter, MSGBOX_NPC
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_EventScript_TriggerEscape::
	lock
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, VermilionCity_EventScript_TriggerEscapeSouth
	case DIR_NORTH, VermilionCity_EventScript_TriggerEscapeNorth
	case DIR_EAST, VermilionCity_EventScript_TriggerEscapeEast
	case DIR_WEST, VermilionCity_EventScript_TriggerEscapeWest
	end
	
VermilionCity_EventScript_TriggerEscapeSouth::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerTriggerEscapingSouth
	waitmovement 0
	goto VermilionCity_EventScript_TriggerEscapeEnd

VermilionCity_EventScript_TriggerEscapeNorth::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerTriggerEscapingNorth
	waitmovement 0
	goto VermilionCity_EventScript_TriggerEscapeEnd

VermilionCity_EventScript_TriggerEscapeEast::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerTriggerEscapingEast
	waitmovement 0
	goto VermilionCity_EventScript_TriggerEscapeEnd

VermilionCity_EventScript_TriggerEscapeWest::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerTriggerEscapingWest
	waitmovement 0
	goto VermilionCity_EventScript_TriggerEscapeEnd

VermilionCity_EventScript_TriggerEscapeEnd::
	msgbox LavenderTown_Text_TriggerEscape
	closemessage
	fadescreen FADE_TO_BLACK
	delay 10
	addvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_0, 5, VermilionCity_EventScript_TriggerEscapeBlackout
	fadescreen FADE_FROM_BLACK
	msgbox LavenderTown_Text_TriggerEscape1
	closemessage
	release
	end

VermilionCity_EventScript_TriggerEscapeBlackout::
	msgbox LavenderTown_Text_TriggerEscapeBlackout
	warpsilent MAP_VERMILION_CITY_POKEMON_CENTER_1F, 255, 7, 4
	release
	end

VermilionCity_Movement_PlayerTriggerEscapingNorth::
	lock_facing_direction
	slide_down
	unlock_facing_direction
	step_end

VermilionCity_Movement_PlayerTriggerEscapingSouth::
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end

VermilionCity_Movement_PlayerTriggerEscapingEast::
	lock_facing_direction
	slide_left
	unlock_facing_direction
	step_end

VermilionCity_Movement_PlayerTriggerEscapingWest::
	lock_facing_direction
	slide_right
	unlock_facing_direction
	step_end
