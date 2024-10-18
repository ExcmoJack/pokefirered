.set LOCALID_TIP_LADY, 1

PokemonTower_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_B1F_OnTransition @ ON_TRANSITION no sirve
	.byte 0

PokemonTower_B1F_OnTransition::
	goto_if_set FLAG_HIDE_POKEMON_TOWER_B1F_TIP_LADY, PokemonTower_B1F_OnTransition_1
	end

PokemonTower_B1F_OnTransition_1::
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_FAILED, 3, PokemonTower_B1F_EventScript_OnFrame_TipLady_Appear
	end

PokemonTower_B1F_EventScript_Trigger::
	lock
	fadescreen FADE_TO_BLACK
	delay 10
	playse SE_M_YAWN
	waitse
	addvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_0, 5, PokemonTower_B1F_EventScript_TriggerBlackout
	fadescreen FADE_FROM_BLACK
	msgbox PokemonTower_B1F_Text_Trigger
	closemessage
	release
	end

PokemonTower_B1F_EventScript_TriggerBlackout::
	playse SE_M_SNORE
	waitse
	addvar VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_FAILED, 1
	msgbox PokemonTower_B1F_Text_Trigger_2
	warpsilent MAP_POKEMON_TOWER_B1F, 255, 19, 2
	release
	end

PokemonTower_B1F_EventScript_OnFrame_TipLady_Appear::
	lock
	addobject LOCALID_TIP_LADY
	playse SE_M_TELEPORT
	applymovement LOCALID_TIP_LADY, Common_Movement_Appear
	waitmovement 0
	clearflag FLAG_HIDE_POKEMON_TOWER_B1F_TIP_LADY
	release
	end

PokemonTower_B1F_EventScript_TipLady_CheckTimesAsked::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 0, PokemonTower_B1F_EventScript_TipLady_Intro
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 1, PokemonTower_B1F_EventScript_TipLady_Tip1
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 2, PokemonTower_B1F_EventScript_TipLady_Tip2
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 3, PokemonTower_B1F_EventScript_TipLady_Tip3
	end


PokemonTower_B1F_EventScript_TipLady_Intro::
	textcolor NPC_TEXT_COLOR_CREEPY
	msgbox PokemonTower_B1F_Text_TipLady_Intro
	closemessage
	msgbox PokemonTower_B1F_Text_TipLady_NeedTip
	closemessage
	msgbox PokemonTower_B1F_Text_TipLady_DoYouAgree, MSGBOX_YESNO
	closemessage
	goto_if_eq VAR_RESULT, YES, PokemonTower_B1F_EventScript_TipLady_ChooseAndRemove
	goto_if_eq VAR_RESULT, NO, PokemonTower_B1F_EventScript_TipLady_Ending
	release
	end

PokemonTower_B1F_EventScript_TipLady_ChooseAndRemove::
	msgbox PokemonTower_B1F_Text_TipLady_WhichPokemon
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, PokemonTower_B1F_EventScript_TipLady_Ending
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, PokemonTower_B1F_EventScript_TipLady_OnlyOneAliveMonInParty
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	fadeoutbgm 0
	playbgm MUS_ENCOUNTER_DEOXYS, 2
	playse SE_M_PERISH_SONG
	waitse
	playmoncry VAR_0x8005, CRY_MODE_FAINT
	waitmoncry
	setweather WEATHER_FOG_HORIZONTAL
	doweather
	msgbox PokemonTower_B1F_Text_TipLady_TakePokemon
	playse SE_M_ATTRACT2
	msgbox PokemonTower_B1F_Text_TipLady_TakePokemon_2
	waitse
	playse SE_M_DRAGON_RAGE
	waitse
	playse SE_M_WATERFALL
	waitse
	fadeoutbgm 5
	closemessage
	setweather WEATHER_NONE
	doweather
	setweather WEATHER_SHADE
	doweather
	delay 10
	playbgm MUS_MT_MOON, 1
	special StoreSelectedPokemonInDaycare
	addvar VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 1
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 1, PokemonTower_B1F_EventScript_TipLady_ShowTip1
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 2, PokemonTower_B1F_EventScript_TipLady_ShowTip2
	goto_if_eq VAR_MAP_SCENE_POKEMON_TOWER_B1F_TIMES_ASKED, 3, PokemonTower_B1F_EventScript_TipLady_ShowTip3
	release
	end

PokemonTower_B1F_EventScript_TipLady_Ending::
	msgbox PokemonTower_B1F_Text_TipLady_Ending
	release
	end

PokemonTower_B1F_EventScript_TipLady_OnlyOneAliveMonInParty::
	msgbox PokemonTower_B1F_Text_TipLady_OnlyOneAliveMonInParty
	release
	end

PokemonTower_B1F_EventScript_TipLady_NoMoreTips::
	msgbox PokemonTower_B1F_Text_TipLady_NoMoreTips
	release
	end

PokemonTower_B1F_EventScript_TipLady_Tip1::
	msgbox PokemonTower_B1F_Text_TipLady_NeedMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonTower_B1F_EventScript_TipLady_ChooseAndRemove
	goto PokemonTower_B1F_EventScript_TipLady_ShowTip1
	release
	end

PokemonTower_B1F_EventScript_TipLady_ShowTip1::
	setvar VAR_0x8008, 1
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end

PokemonTower_B1F_EventScript_TipLady_Tip2::
	msgbox PokemonTower_B1F_Text_TipLady_NeedMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonTower_B1F_EventScript_TipLady_ChooseAndRemove
	goto PokemonTower_B1F_EventScript_TipLady_ShowTip2
	release
	end

PokemonTower_B1F_EventScript_TipLady_ShowTip2::
	setvar VAR_0x8008, 2
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end

PokemonTower_B1F_EventScript_TipLady_Tip3::
	msgbox PokemonTower_B1F_Text_TipLady_NeedMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonTower_B1F_EventScript_TipLady_NoMoreTips
	goto PokemonTower_B1F_EventScript_TipLady_ShowTip3
	release
	end

PokemonTower_B1F_EventScript_TipLady_ShowTip3::
	setvar VAR_0x8008, 3
	delay 60
	goto_if_questlog EventScript_ReleaseEnd
	special ShowDiploma
	waitstate
	release
	end