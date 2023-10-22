.equ LOCALID_MR_MIME, 4
.equ LOCALID_HAUNTER, 5

VermilionCity_Dungeon2_MapScripts::
	.byte 0

VermilionCity_Dungeon2_Trigger1::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Dungeon2_Movement_Player1
	waitmovement 0
	goto VermilionCity_Dungeon2_Trigger3
	end

VermilionCity_Dungeon2_Trigger2::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Dungeon2_Movement_Player2
	waitmovement 0
	goto VermilionCity_Dungeon2_Trigger3
	end

VermilionCity_Dungeon2_Trigger3::
	setvar VAR_TEMP_1, 1
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VermilionCity_Dungeon2_Text_Father
	closemessage
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox VermilionCity_Dungeon2_Text_Evil1
	closemessage
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox VermilionCity_Dungeon2_Text_Mother
	closemessage
	textcolor NPC_TEXT_COLOR_EVIL
	msgbox VermilionCity_Dungeon2_Text_Evil2
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Dungeon2_Movement_Player3
	waitmovement 0
	msgbox VermilionCity_Dungeon2_Text_Evil3
	closemessage
	applymovement LOCALID_HAUNTER, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_MR_MIME, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_MR_MIME, Common_Movement_Appear
	waitmovement 0
	msgbox VermilionCity_Dungeon2_Text_Evil4
	closemessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox VermilionCity_Dungeon2_Text_MrMime
	closemessage
	waitmoncry
	givemon SPECIES_MR_MIME, 18, ITEM_TWISTED_SPOON
	delay 20
	bufferspeciesname STR_VAR_1, SPECIES_MR_MIME
	playfanfare MUS_EVOLVED
	message Text_PkmnJoinedTeam
	waitmessage
	waitfanfare
	delay 20
	textcolor NPC_TEXT_COLOR_EVIL
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
	msgbox VermilionCity_Dungeon2_Text_Evil5
	closemessage
	waitmoncry
	setwildbattle SPECIES_HAUNTER, 24, ITEM_NONE
	dowildbattle
	setflag FLAG_GET_MR_MIME_CARMIN
	msgbox VermilionCity_Dungeon2_Text_Evil6
	closemessage
	applymovement LOCALID_HAUNTER, Common_Movement_Disappear
	waitmovement 0
	special HealPlayerParty
	textcolor NPC_TEXT_COLOR_MALE
	msgbox VermilionCity_Dungeon2_Text_Father2
	delay 20
	playse SE_THUNDERSTORM_STOP
	setvar VAR_0x8004, 0  @ Vertical pan
	setvar VAR_0x8005, 3  @ Horizontal pan
	setvar VAR_0x8006, 4  @ Num shakes
	setvar VAR_0x8007, 2  @ Shake delay
	special ShakeScreen
	msgbox VermilionCity_Dungeon2_Text_Father3
	closemessage
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
	setvar VAR_MAP_SCENE_LAVENDER_TOWN_HOUSE1, 2
	warpteleport MAP_LAVENDER_TOWN_HOUSE1, 255, 7, 6
	release
	end

VermilionCity_Dungeon2_Movement_Player1::
	walk_down
	walk_in_place_fast_left
	step_end

VermilionCity_Dungeon2_Movement_Player2::
	walk_down
	walk_left
	walk_in_place_fast_left
	step_end

VermilionCity_Dungeon2_Movement_Player3::
	walk_left
	step_end