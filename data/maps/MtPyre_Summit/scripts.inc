.equ LOCALID_DUSCLOPS, 1
.equ LOCALID_HIKER, 10

MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_Summit_OnFrame
	.byte 0

MtPyre_Summit_OnFrame::
	map_script_2 VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 2, MtPyre_Summit_EventScript_OnFrame_DusclopsDefeated
	.2byte 0

MtPyre_Summit_EventScript_Debug_HideHiker::
	removeobject LOCALID_HIKER
	setflag FLAG_HIDE_HIKER_MT_PYRE
	end

MtPyre_Summit_EventScript_Trigger_Dusclops::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_Player_1
	waitmovement 0
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox MtPyre_Summit_Text_Trigger_Dusclops_1, MSGBOX_YESNO
	closemessage
	switch VAR_RESULT
	case NO, MtPyre_Summit_EventScript_Trigger_Dusclops_Cancel
	applymovement LOCALID_DUSCLOPS, MtPyre_Summit_Movement_Dusclops_1
	waitmovement 0
	clearflag FLAG_HIDE_HIKER_MT_PYRE
	addobject LOCALID_HIKER
	applymovement LOCALID_HIKER, Common_Movement_Appear
	waitmovement 0
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	msgbox MtPyre_Summit_Text_Trigger_Dusclops_2
	closemessage
	waitmoncry
	applymovement LOCALID_HIKER, MtPyre_Summit_Movement_Hiker_1
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	trainerbattle_no_intro TRAINER_HIKER_ALAN, MtPyre_Summit_Text_Trigger_Dusclops_Defeated
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 2
	release
	end

MtPyre_Summit_EventScript_OnFrame_DusclopsDefeated::
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 3
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox MtPyre_Summit_Text_Trigger_Dusclops_3
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_GET_VULPIX_MT_PYRE
	removeobject LOCALID_DUSCLOPS
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	delay 30
	fadescreen FADE_FROM_BLACK
	release
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtPyre_Summit_Text_Trigger_Hiker_1
	closemessage
	warp MAP_MT_PYRE_1F, 255, 17, 15
	release
	end

MtPyre_Summit_EventScript_Trigger_Dusclops_Cancel::
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_Summit_Movement_Player_2
	waitmovement 0
	release
	end

MtPyre_Summit_Movement_Player_1::
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_Player_2::
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_Dusclops_1::
	lock_facing_direction
	walk_slow_up
	delay_16
	walk_slow_up
	delay_16
	unlock_facing_direction
	face_down
	step_end

MtPyre_Summit_Movement_Hiker_1::
	disable_anim
	walk_down
	restore_anim
	step_end
