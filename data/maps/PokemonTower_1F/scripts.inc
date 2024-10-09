PokemonTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnLoad::
	goto_if_lt VAR_MAP_SCENE_POKEMON_TOWER, 1, PokemonTower_1F_EventScript_HideStairs
	end

PokemonTower_1F_EventScript_HideStairs::
	setmetatile  9, 1, 0x2A0, 1
	setmetatile 10, 1, 0x2A0, 1
	setmetatile 11, 1, 0x2A0, 1
	setmetatile  9, 2, 0x292, 0
	setmetatile 10, 2, 0x284, 0
	setmetatile 11, 2, 0x284, 0
	setmetatile  9, 3, 0x28E, 0
	setmetatile 10, 3, 0x282, 0
	setmetatile 11, 3, 0x282, 0
	end

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	textcolor NPC_TEXT_COLOR_CREEPY
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end
