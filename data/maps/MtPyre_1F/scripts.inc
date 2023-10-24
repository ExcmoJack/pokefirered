.equ LOCALID_NURSE, 1
.equ LOCALID_VULPIX, 2
.equ LOCALID_HIKER, 3

MtPyre_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_1F_OnTransition
	.byte 0

MtPyre_1F_OnTransition::
	goto_if_eq VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 3, MtPyre_1F_OnTransition_1

MtPyre_1F_OnTransition_1::
	setobjectmovementtype LOCALID_HIKER, MOVEMENT_TYPE_FACE_UP
	end

MtPyre_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_MT_PYRE, 0, MtPyre_1F_OnFrame_EventScript_MoveVulpix
	map_script_2 VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 3, MtPyre_1F_OnFrame_EventScript_Ending
	.2byte 0

MtPyre_1F_EventScript_Healing::
	lock
	faceplayer
	msgbox MtPyre_1F_Text_Healing_1
	closemessage
	call EventScript_OutOfCenterPartyHeal
	msgbox MtPyre_1F_Text_Healing_2
	closemessage
	release
	end

MtPyre_1F_EventScript_BlockExteriorTrigger::
	lock
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_NURSE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MtPyre_1F_Text_BlockExteriorTrigger_1
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_1F_Movement_BlockExteriorTrigger_Player
	waitmovement 0
	msgbox MtPyre_1F_Text_BlockExteriorTrigger_2
	closemessage
	release
	end

MtPyre_1F_EventScript_UnblockExteriorTrigger::
	lock
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_NURSE, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MtPyre_1F_Text_UnblockExteriorTrigger_1
	closemessage
	setvar VAR_MAP_SCENE_MT_PYRE 7
	release
	end

MtPyre_1F_OnFrame_EventScript_MoveVulpix::
	lock
	setvar VAR_MAP_SCENE_MT_PYRE, 1
	playse SE_EXIT
	applymovement LOCALID_VULPIX, MtPyre_1F_Movement_Vulpix_1
	waitmovement 0
	applymovement LOCALID_VULPIX, MtPyre_1F_Movement_Vulpix_2
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_VULPIX, MtPyre_1F_Movement_Vulpix_3
	waitmovement 0
	removeobject LOCALID_VULPIX
	setflag FLAG_HIDE_VULPIX_MT_PYRE_1F
	release
	end

MtPyre_1F_OnFrame_EventScript_Ending::
	lock
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtPyre_1F_Text_HikerEnd
	closemessage
	delay 20
	applymovement LOCALID_HIKER, MtPyre_1F_Movement_Hiker
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_VULPIX, MtPyre_1F_Movement_Vulpix_3
	waitmovement 0
	removeobject LOCALID_HIKER
	delay 60
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	delay 10
	playse SE_THUNDER
	waitse
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 4
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_VOLUNTEER_HOUSE, 2
	warpteleport MAP_LAVENDER_TOWN_VOLUNTEER_POKEMON_HOUSE, 255, 10, 3
	release
	end

MtPyre_1F_Movement_BlockExteriorTrigger_Player::
	walk_right
	walk_in_place_fast_up
	step_end

MtPyre_1F_Movement_Vulpix_1::
	face_up
	set_visible
	step_end

MtPyre_1F_Movement_Vulpix_2::
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_1F_Movement_Vulpix_3::
	set_invisible
	step_end

MtPyre_1F_Movement_Hiker::
	walk_down
	walk_down
	step_end