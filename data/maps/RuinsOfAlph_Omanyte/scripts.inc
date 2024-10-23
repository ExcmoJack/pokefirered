RuinsOfAlph_Omanyte_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RuinsOfAlph_Omanyte_OnLoad
	.byte 0

RuinsOfAlph_Omanyte_OnLoad::
	call_if_set FLAG_RUINS_OF_ALPH_OMANYTE_DONE, RuinsOfAlph_Omanyte_EventScript_SetMetatiles
	end

RuinsOfAlph_Omanyte_EventScript_StartPuzzle::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, PUZZLE_OMANYTE
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	waitstate
	goto_if_eq VAR_RESULT, TRUE, RuinsOfAlph_Omanyte_EventScript_PuzzleSolved
	end

RuinsOfAlph_Omanyte_EventScript_PuzzleSolved::
	lock
	call RuinsOfAlph_Omanyte_EventScript_SetMetatiles
	special DrawWholeMapView
	playse SE_UNLOCK
	setflag FLAG_RUINS_OF_ALPH_OMANYTE_DONE
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

RuinsOfAlph_Omanyte_EventScript_SetMetatiles::
	setmetatile 19, 29, 0x2F3, 0
	setmetatile 20, 29, 0x2F4, 0
	setmetatile 19, 30, 0x2FB, 0
	setmetatile 20, 30, 0x2FC, 0
	return

RuinsOfAlph_Omanyte_EventScript_Description::
	msgbox RuinsOfAlph_Omanyte_Text_Description, MSGBOX_SIGN
	end