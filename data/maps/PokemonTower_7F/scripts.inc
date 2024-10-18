.set LOCALID_GHOST, 2


PokemonTower_7F_MapScripts::
	.byte 0

PokemonTower_7F_EventScript_MrFuji::
	lock
	faceplayer
	setflag FLAG_HIDE_TOWER_FUJI
	clearflag FLAG_HIDE_POKEHOUSE_FUJI
	setflag FLAG_RESCUED_MR_FUJI
	setvar VAR_MAP_SCENE_POKEMON_TOWER, 1
	msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 20
	applymovement LOCALID_GHOST, PokemonTower_7F_Movement_GhostAppear
	waitmovement 0
	applymovement LOCALID_GHOST, Common_Movement_Appear
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox PokemonTower_7F_Text_EvilGhost
	closemessage
	textcolor NPC_TEXT_COLOR_MALE
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe_2
	closemessage
	giveitem ITEM_SILPH_SCOPE, 1
	msgbox PokemonTower_7F_Text_MrFujiThankYouFollowMe_3
	applymovement LOCALID_GHOST, PokemonTower_7F_Movement_GhostApproaches
	waitmovement 0
	playse SE_M_TELEPORT
	applymovement VAR_LAST_TALKED, Common_Movement_Disappear
	waitmovement 0
	waitse
	closemessage
	applymovement LOCALID_GHOST, Common_Movement_Disappear
	waitmovement 0
	removeobject VAR_LAST_TALKED
	removeobject LOCALID_GHOST
	delay 5
	playse SE_M_COSMIC_POWER
	msgbox PokemonTower_7F_Text_Ghost_0
	waitse
	closemessage
	setwildbattle SPECIES_MAROWAK, 30
	special StartMarowakBattle
	waitstate
	textcolor NPC_TEXT_COLOR_CREEPY
	msgbox PokemonTower_7F_Text_Ghost
	closemessage
	release
	end

PokemonTower_7F_Movement_GhostAppear::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

PokemonTower_7F_Movement_GhostApproaches::
	walk_down
	walk_down
	walk_down
	step_end