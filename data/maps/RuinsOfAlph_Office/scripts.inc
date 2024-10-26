RuinsOfAlph_Office_MapScripts::
	.byte 0

RuinsOfAlph_Office_EventScript_PC::
	msgbox RuinsOfAlph_Office_Text_PC, MSGBOX_SIGN
	end

RuinsOfAlph_Office_EventScript_Printer::
	lockall
	msgbox RuinsOfAlph_Office_Text_Machine, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RuinsOfAlph_Office_EventScript_PrintParty
	end

RuinsOfAlph_Office_EventScript_PrintParty::
	setvar VAR_0x8004, MON_ICON_TINT_PINK
	playse MUS_PHOTO
	dofieldeffect FLDEFF_PHOTO_FLASH
	delay 60
	special UpdateTrainerCardPhotoIcons
	releaseall
	end

RuinsOfAlph_Office_EventScript_Scientist_1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Office_Text_Scientist_1, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, EventScript_OutOfCenterPartyHeal
	closemessage
	release
	end

RuinsOfAlph_Office_EventScript_Scientist_2::
	msgbox RuinsOfAlph_Office_Text_Scientist_2, MSGBOX_NPC
	end

RuinsOfAlph_Office_EventScript_Debug::
	setflag FLAG_HIDE_ENTEI_RUINS_OF_ALPH
	setflag FLAG_HIDE_FISHER_RUINS_OF_ALPH_EXT
	setflag FLAG_GENGAR_POKEMON_TOWER_B3F
	setflag FLAG_HIDE_LAPRAS_N_RUINS_OF_ALPH
	setflag FLAG_HIDE_LAPRAS_S_RUINS_OF_ALPH
	setflag FLAG_HIDE_UNOWN_EXCLAM_RUINS_OF_ALPH
	setflag FLAG_HIDE_UNOWN_QUESTION_RUINS_OF_ALPH
	setrespawn SPAWN_LAVENDER_TOWN
	end