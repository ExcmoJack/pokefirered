.equ LOCALID_VULPIX, 1
.equ LOCALID_HIKER, 2
.equ LOCALID_DUSCLOPS, 3

MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_InteriorEventTrigger::
	lockall
	setvar VAR_MAP_SCENE_MT_PYRE, 6
	setvar VAR_MAP_SCENE_MT_PYRE_EXTERIOR, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, MtPyre_6F_Movement_InteriorEventTrigger_Cam_1
	waitmovement 0
	applymovement LOCALID_HIKER, MtPyre_6F_Movement_InteriorEventTrigger_Hiker_1
	waitmovement 0
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	applymovement LOCALID_VULPIX, MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_1
	waitmovement 0
	waitmoncry
	delay 20
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtPyre_6F_Text_InteriorEventTrigger_Hiker_1
	closemessage
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_VULPIX, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_HIKER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox MtPyre_6F_Text_InteriorEventTrigger_Hiker_2
	closemessage
	playse SE_M_TELEPORT
	applymovement LOCALID_DUSCLOPS, Common_Movement_Appear
	waitmovement 0
	delay 30
	textcolor NPC_TEXT_COLOR_EVIL
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_ENCOUNTER
	msgbox MtPyre_6F_Text_InteriorEventTrigger_Dusclops
	closemessage
	waitmoncry
	waitmovement 0
	applymovement LOCALID_DUSCLOPS, MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_1
	waitmovement 0
	applymovement LOCALID_VULPIX, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_CAMERA, MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_2
	applymovement LOCALID_DUSCLOPS, MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_2
	applymovement LOCALID_HIKER, MtPyre_6F_Movement_InteriorEventTrigger_Hiker_2
	waitmovement 0
	applymovement LOCALID_VULPIX, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtPyre_6F_Text_InteriorEventTrigger_Hiker_3
	closemessage
	playse SE_M_TELEPORT
	removeobject LOCALID_HIKER
	applymovement LOCALID_DUSCLOPS, MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_3
	waitmovement 0
	applymovement LOCALID_DUSCLOPS, Common_Movement_Disappear
	waitmovement 0
	removeobject LOCALID_DUSCLOPS
	applymovement LOCALID_VULPIX, MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_2
	applymovement OBJ_EVENT_ID_PLAYER, MtPyre_6F_Movement_InteriorEventTrigger_Player
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, MtPyre_6F_Movement_InteriorEventTrigger_Cam_2
	waitmovement 0
	special RemoveCameraObject
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox MtPyre_6F_Text_InteriorEventTrigger_Vulpix
	closemessage
	waitmoncry
	applymovement LOCALID_VULPIX, MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_3
	waitmovement 0
	givemon SPECIES_VULPIX, 25, ITEM_CHARCOAL
	delay 20
	bufferspeciesname STR_VAR_1, SPECIES_VULPIX
	playfanfare MUS_EVOLVED
	message Text_PkmnJoinedTeam
	waitmessage
	waitfanfare
	closemessage
	applymovement LOCALID_VULPIX, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call MtPyre_6F_EventScript_InteriorEventTrigger_BlockExit
	delay 30
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	applymovement LOCALID_VULPIX, MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	waitmoncry
	msgbox MtPyre_6F_Text_InteriorEventTrigger_FollowVulpix
	closemessage
	applymovement LOCALID_VULPIX, MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_5
	waitmovement 0
	playse SE_FALL
	delay 30
	removeobject LOCALID_VULPIX
	setflag FLAG_HIDE_VULPIX_MT_PYRE_6F
	releaseall
	end

MtPyre_6F_EventScript_InteriorEventTrigger_BlockExit::
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	setmetatile 10, 10, 0x2C7, 1
	special DrawWholeMapView
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	setmetatile 10, 10, 0x2CF, 1
	setmetatile 10,  9, 0x2C7, 1
	special DrawWholeMapView
	delay 30
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	setmetatile 10, 10, 0x2D7, 1
	setmetatile 10,  9, 0x2CF, 1
	setmetatile 10,  8, 0x310, 1
	special DrawWholeMapView
	return

MtPyre_6F_Movement_InteriorEventTrigger_Cam_1::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Cam_2::
	walk_up
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_1::
	walk_left
	walk_left
	emote_smile
	delay_16
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_2::
	walk_fast_left
	walk_fast_down
	delay_16
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_3::
	jump_in_place_down
	jump_in_place_down_up
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_4::
	walk_left
	walk_up
	walk_in_place_left
	walk_in_place_left
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Vulpix_5::
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	delay_16
	set_invisible
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_1::
	disable_anim
	walk_slow_down
	delay_16
	walk_slow_down
	delay_16
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_2::
	restore_anim
	walk_slow_down
	delay_16
	walk_slow_down
	delay_16
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Dusclops_3::
	walk_slow_down
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Hiker_1::
	walk_in_place_fast_right
	delay_8
	emote_exclamation_mark
	delay_8
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Hiker_2::
	lock_facing_direction
	walk_faster_down
	walk_faster_down
	walk_in_place_faster_up
	walk_in_place_faster_up
	walk_in_place_faster_up
	walk_in_place_faster_up
	unlock_facing_direction
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Player::
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_down
	step_end

MtPyre_6F_Movement_InteriorEventTrigger_Roca::
	set_visible
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end