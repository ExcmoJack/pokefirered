LavenderTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn SPAWN_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	lock
	faceplayer
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets
	closemessage
	warpteleport MAP_POKEMON_TOWER_B2F, 255, 18, 3
	release
	end

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_SendPlayerToRuins::
	lock
	setrespawn SPAWN_LAVENDER_TOWN
	delay 20
	playse SE_THUNDER
	waitse
	warpteleport MAP_RUINS_OF_ALPH_EXTERIOR, 0, 0, 0
	release
	end
