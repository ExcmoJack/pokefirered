RuinsOfAlph_Aerodactyl_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_Aerodactyl_OnLoad
	.byte 0

RuinsOfAlph_Aerodactyl_OnLoad::
	call_if_set FLAG_RUINS_OF_ALPH_AERODACTYL_DONE, RuinsOfAlph_Aerodactyl_EventScript_SetMetatiles
	end

RuinsOfAlph_Aerodactyl_EventScript_StartPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, PUZZLE_AERODACTYL
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Aerodactyl_EventScript_PuzzleSolved
	end

RuinsOfAlph_Aerodactyl_EventScript_PuzzleSolved::
	lock
	call RuinsOfAlph_Aerodactyl_EventScript_SetMetatiles
	special DrawWholeMapView
	playse SE_UNLOCK
	setflag FLAG_RUINS_OF_ALPH_AERODACTYL_DONE
	waitse
	delay 10
	setvar VAR_0x8004, 1  @ Vertical pan
	setvar VAR_0x8005, 1  @ Horizontal pan
	setvar VAR_0x8006, 2  @ Num shakes
	setvar VAR_0x8007, 1  @ Shake delay
	special ShakeScreen
	warphole MAP_RUINS_OF_ALPH_MAIN_CHAMBER
	release
	end

RuinsOfAlph_Aerodactyl_EventScript_SetMetatiles::
	setmetatile 4, 21, 0x2F3, 0
	setmetatile 5, 21, 0x2F4, 0
	setmetatile 4, 22, 0x2FB, 0
	setmetatile 5, 22, 0x2FC, 0
	return

RuinsOfAlph_Aerodactyl_EventScript_Description::
	msgbox RuinsOfAlph_Aerodactyl_Text_Description, MSGBOX_SIGN
	end