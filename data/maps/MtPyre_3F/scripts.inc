.equ LOCALID_VULPIX, 1

MtPyre_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MtPyre_3F_OnFrame
	.byte 0


MtPyre_3F_OnFrame::
	map_script_2 VAR_MAP_SCENE_MT_PYRE, 2, MtPyre_3F_OnFrame_EventScript_MoveVulpix
	.2byte 0

MtPyre_3F_OnFrame_EventScript_MoveVulpix::
	lock
	setvar VAR_MAP_SCENE_MT_PYRE, 3
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtPyre_3F_Movement_Cam_2
	waitmovement 0
	applymovement LOCALID_VULPIX, MtPyre_3F_Movement_Vulpix_1
	waitmovement 0
	playse SE_EXIT
	applymovement LOCALID_VULPIX, MtPyre_3F_Movement_Vulpix_2
	waitmovement 0
	removeobject LOCALID_VULPIX
	setflag FLAG_HIDE_VULPIX_MT_PYRE_3F
	applymovement OBJ_EVENT_ID_CAMERA, MtPyre_3F_Movement_Cam_1
	waitmovement 0
	special RemoveCameraObject
	release
	end

MtPyre_3F_Movement_Vulpix_1::
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_3F_Movement_Vulpix_2::
	set_invisible
	step_end

MtPyre_3F_Movement_Cam_1::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MtPyre_3F_Movement_Cam_2::
	walk_left
	walk_left
	walk_left
	walk_left
	step_end