RuinsOfAlph_HooH_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_HooH_OnLoad
	.byte 0

RuinsOfAlph_HooH_OnLoad::
	call_if_set FLAG_RUINS_OF_ALPH_HOOH_DONE, RuinsOfAlph_HooH_EventScript_SetMetatiles
	end

RuinsOfAlph_HooH_EventScript_StartPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, PUZZLE_HO_OH
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_HooH_EventScript_PuzzleSolved
	end

RuinsOfAlph_HooH_EventScript_PuzzleSolved::
	lock
	call RuinsOfAlph_HooH_EventScript_SetMetatiles
	special DrawWholeMapView
	playse SE_UNLOCK
	setflag FLAG_RUINS_OF_ALPH_HOOH_DONE
	addvar VAR_MAP_SCENE_RUINS_OF_ALPH_UNOWN_AMOUNT, 1
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

RuinsOfAlph_HooH_EventScript_SetMetatiles::
	setmetatile 4, 30, 0x2F3, 0
	setmetatile 5, 30, 0x2F4, 0
	setmetatile 4, 31, 0x2FB, 0
	setmetatile 5, 31, 0x2FC, 0
	return

RuinsOfAlph_HooH_EventScript_Description::
	msgbox RuinsOfAlph_HooH_Text_Description, MSGBOX_SIGN
	end