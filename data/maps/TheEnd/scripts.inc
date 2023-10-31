TheEnd_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TheEnd_OnFrame
	.byte 0

TheEnd_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TheEnd_EventScript_Credits
	.2byte 0

TheEnd_EventScript_Credits::
	lockall
	waitbuttonpress
	special EnterHallOfFame
	waitstate
	releaseall
	end