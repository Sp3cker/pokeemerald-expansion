# 1 "data/maps/VictoryRoad_1F/scripts.pory"

# 2 "data/maps/VictoryRoad_1F/scripts.pory"
.set LOCALID_WALLY_ENTRANCE, 4
# 3 "data/maps/VictoryRoad_1F/scripts.pory"

# 4 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_MapScripts::
# 5 "data/maps/VictoryRoad_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
# 6 "data/maps/VictoryRoad_1F/scripts.pory"
	.byte 0
# 7 "data/maps/VictoryRoad_1F/scripts.pory"

# 8 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_OnTransition:
# 9 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
# 10 "data/maps/VictoryRoad_1F/scripts.pory"
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
# 11 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 12 "data/maps/VictoryRoad_1F/scripts.pory"

# 13 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
# 14 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
# 15 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 16 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 17 "data/maps/VictoryRoad_1F/scripts.pory"

# 18 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
# 19 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
# 20 "data/maps/VictoryRoad_1F/scripts.pory"
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
# 21 "data/maps/VictoryRoad_1F/scripts.pory"
	return
# 22 "data/maps/VictoryRoad_1F/scripts.pory"

# 23 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger1::
# 24 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 25 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 26 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 1
# 27 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 28 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
# 29 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 31 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 32 "data/maps/VictoryRoad_1F/scripts.pory"

# 33 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyBattleTrigger2::
# 34 "data/maps/VictoryRoad_1F/scripts.pory"
	lockall
# 35 "data/maps/VictoryRoad_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
# 36 "data/maps/VictoryRoad_1F/scripts.pory"
	setvar VAR_0x8008, 2
# 37 "data/maps/VictoryRoad_1F/scripts.pory"
	addobject LOCALID_WALLY_ENTRANCE
# 38 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
# 39 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 40 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
# 41 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 42 "data/maps/VictoryRoad_1F/scripts.pory"

# 43 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_WallyEntranceBattle::
# 44 "data/maps/VictoryRoad_1F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 45 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmovement 0
# 46 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
# 47 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
# 48 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyGiftFromDad, MSGBOX_DEFAULT
# 49 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_SLAKITE
# 50 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_TYRANITARITE
# 51 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_SALAMENCITE
# 52 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_GARCHOMPITE
# 53 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_METAGROSSITE
# 54 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyTicketsFromDad, MSGBOX_DEFAULT
# 55 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_EON_TICKET
# 56 "data/maps/VictoryRoad_1F/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 57 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 58 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
# 59 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
# 60 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
# 61 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
# 62 "data/maps/VictoryRoad_1F/scripts.pory"
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
# 63 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
# 64 "data/maps/VictoryRoad_1F/scripts.pory"
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
# 65 "data/maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
# 66 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 67 "data/maps/VictoryRoad_1F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 68 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_0x8006, GetLevelCapForText
# 69 "data/maps/VictoryRoad_1F/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_0x8006
# 70 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox LevelCapIncreasedTo, MSGBOX_DEFAULT
# 71 "data/maps/VictoryRoad_1F/scripts.pory"
	waitfanfare
# 72 "data/maps/VictoryRoad_1F/scripts.pory"
	closemessage
# 73 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 74 "data/maps/VictoryRoad_1F/scripts.pory"
	releaseall
# 75 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 76 "data/maps/VictoryRoad_1F/scripts.pory"

# 77 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer1:
# 78 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 79 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 80 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 81 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 82 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 83 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 84 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 85 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 86 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 87 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 88 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 89 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 90 "data/maps/VictoryRoad_1F/scripts.pory"

# 91 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Movement_WallyApproachPlayer2:
# 92 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 93 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 94 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 95 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 96 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 97 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 98 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 99 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 100 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_left
# 101 "data/maps/VictoryRoad_1F/scripts.pory"
	walk_up
# 102 "data/maps/VictoryRoad_1F/scripts.pory"
	step_end
# 103 "data/maps/VictoryRoad_1F/scripts.pory"

# 104 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
# 105 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_EntranceWally::
# 106 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
# 107 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 108 "data/maps/VictoryRoad_1F/scripts.pory"

# 109 "data/maps/VictoryRoad_1F/scripts.pory"
@ This Wally appears and remains at the exit after the Hall of Fame is entered
# 110 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_ExitWally::
# 111 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 112 "data/maps/VictoryRoad_1F/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 113 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
# 114 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 115 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 116 "data/maps/VictoryRoad_1F/scripts.pory"

# 117 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_RematchWally::
# 118 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
# 119 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 121 "data/maps/VictoryRoad_1F/scripts.pory"

# 122 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Edgar::
# 123 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
# 124 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 126 "data/maps/VictoryRoad_1F/scripts.pory"

# 127 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Albert::
# 128 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
# 129 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 131 "data/maps/VictoryRoad_1F/scripts.pory"

# 132 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Hope::
# 133 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
# 134 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 136 "data/maps/VictoryRoad_1F/scripts.pory"

# 137 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Quincy::
# 138 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
# 139 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
# 140 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 141 "data/maps/VictoryRoad_1F/scripts.pory"

# 142 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_EventScript_Katelynn::
# 143 "data/maps/VictoryRoad_1F/scripts.pory"
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
# 144 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
# 145 "data/maps/VictoryRoad_1F/scripts.pory"
	end
# 146 "data/maps/VictoryRoad_1F/scripts.pory"

# 147 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
# 148 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}! You made it! I've been\n"
# 149 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "wandering around here doing more\l"
# 150 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "training, and I knew you'd show up\l"
# 151 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "eventually.\p"
# 152 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "After you beat me in Mauville and on\n"
# 153 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Route 110, I realized how weak I was,\l"
# 154 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "how little I knew about Pokémon…\p"
# 155 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Since then, I've become so much\n"
# 156 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "stronger.\p"
# 157 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've trained extremely hard in hopes of\n"
# 158 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "beating you one day, I even defeated\l"
# 159 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "all of the Gym Leaders here in Hoenn!\p"
# 160 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "However, I have one more goal before I\n"
# 161 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "can move on to the Pokémon League…\p"
# 162 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I have to beat you, {PLAYER}!\n"
# 163 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You inspired me to get stronger, so now\l"
# 164 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'll show you the results of my\l"
# 165 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "hard work!$"
# 166 "data/maps/VictoryRoad_1F/scripts.pory"

# 167 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyEntranceDefeat:
# 168 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "All my training, and it still wasn't\n"
# 169 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "enough… I won't give up, though! I'll\l"
# 170 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "keep training until I can beat you!$"
# 171 "data/maps/VictoryRoad_1F/scripts.pory"

# 172 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostEntranceBattle:
# 173 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I couldn't beat you this time,\n"
# 174 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "either…\p"
# 175 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "But one of these days,\n"
# 176 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, I'm going to catch up to you.\p"
# 177 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "And then I'll challenge the Pokémon\n"
# 178 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "League!$"
# 179 "data/maps/VictoryRoad_1F/scripts.pory"

# 180 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyGiftFromDad:
# 181 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That was a great battle, but I still\n"
# 182 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "clearly have more to learn…\p"
# 183 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Oh! I just remembered, your dad gave me\n"
# 184 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "a package with some items to give to\l"
# 185 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "you, {PLAYER}.\p"
# 186 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "He said to tell you he was sorry he\n"
# 187 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "didn't have that one Mega Stone ready\l"
# 188 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "when you defeated him, so he threw in\l"
# 189 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "some extras to make up for it.\p"
# 190 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Here you go, {PLAYER}.$"
# 191 "data/maps/VictoryRoad_1F/scripts.pory"

# 192 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyTicketsFromDad:
# 193 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Oh I almost forgot, he gave me these to\n"
# 194 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "give to you too.\p"
# 195 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm not sure where these tickets will\n"
# 196 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "take you, but your dad said you can go\l"
# 197 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to the ferry in Lilycove City and use\l"
# 198 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "the tickets there.$"
# 199 "data/maps/VictoryRoad_1F/scripts.pory"

# 200 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyIntro:
# 201 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Hi! {PLAYER}!\p"
# 202 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've gotten stronger since that last\n"
# 203 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "time! I wanted to show you, {PLAYER}!\p"
# 204 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay… Here I come!$"
# 205 "data/maps/VictoryRoad_1F/scripts.pory"

# 206 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyDefeat:
# 207 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Wow!\n"
# 208 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "{PLAYER}, you are strong, after all!$"
# 209 "data/maps/VictoryRoad_1F/scripts.pory"

# 210 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_WallyPostBattle:
# 211 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I couldn't beat you this time,\n"
# 212 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "too… But one of these days, {PLAYER},\l"
# 213 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'm going to catch up to you…\p"
# 214 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "And challenge the Pokémon LEAGUE!$"
# 215 "data/maps/VictoryRoad_1F/scripts.pory"

# 216 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarIntro:
# 217 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I've made it this far a couple times,\n"
# 218 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "but the last stretch is so long…$"
# 219 "data/maps/VictoryRoad_1F/scripts.pory"

# 220 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarDefeat:
# 221 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "My dream ends here again…$"
# 222 "data/maps/VictoryRoad_1F/scripts.pory"

# 223 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_EdgarPostBattle:
# 224 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You've made it this far. Keep the\n"
# 225 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "momentum going and become the\l"
# 226 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "CHAMPION! If anyone can, it's you!$"
# 227 "data/maps/VictoryRoad_1F/scripts.pory"

# 228 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertIntro:
# 229 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I didn't come all this way to lose now.\n"
# 230 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That possibility doesn't exist!$"
# 231 "data/maps/VictoryRoad_1F/scripts.pory"

# 232 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertDefeat:
# 233 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Impossible…\n"
# 234 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost?$"
# 235 "data/maps/VictoryRoad_1F/scripts.pory"

# 236 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_AlbertPostBattle:
# 237 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I lost here…\p"
# 238 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That means I lack the qualifications\n"
# 239 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the CHAMPION…$"
# 240 "data/maps/VictoryRoad_1F/scripts.pory"

# 241 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeIntro:
# 242 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This seemingly infinite and harsh road\n"
# 243 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "lives up to its name of VICTORY.$"
# 244 "data/maps/VictoryRoad_1F/scripts.pory"

# 245 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopeDefeat:
# 246 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Your battle style is fantastic…$"
# 247 "data/maps/VictoryRoad_1F/scripts.pory"

# 248 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_HopePostBattle:
# 249 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "You seem to have the potential for\n"
# 250 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "becoming the CHAMPION.$"
# 251 "data/maps/VictoryRoad_1F/scripts.pory"

# 252 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyIntro:
# 253 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "What is the VICTORY ROAD?\n"
# 254 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I'll tell you if you win!$"
# 255 "data/maps/VictoryRoad_1F/scripts.pory"

# 256 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyDefeat:
# 257 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Okay!\n"
# 258 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Well done!$"
# 259 "data/maps/VictoryRoad_1F/scripts.pory"

# 260 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_QuincyPostBattle:
# 261 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Getting through here safely--that's\n"
# 262 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "the final test for any TRAINER aiming\l"
# 263 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "to become the Pokémon CHAMPION.\p"
# 264 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "That's why it's called the VICTORY\n"
# 265 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "ROAD.$"
# 266 "data/maps/VictoryRoad_1F/scripts.pory"

# 267 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnIntro:
# 268 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I have nothing to say to anyone\n"
# 269 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "that's come this far. Come on!$"
# 270 "data/maps/VictoryRoad_1F/scripts.pory"

# 271 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnDefeat:
# 272 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "This is a disgrace…$"
# 273 "data/maps/VictoryRoad_1F/scripts.pory"

# 274 "data/maps/VictoryRoad_1F/scripts.pory"
VictoryRoad_1F_Text_KatelynnPostBattle:
# 275 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Humph, go right on ahead.\n"
# 276 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "See if I care.$"

VictoryRoad_1F_EventScript_PowerfulMonSummoner::
# 281 "data/maps/VictoryRoad_1F/scripts.pory"
	lock
# 282 "data/maps/VictoryRoad_1F/scripts.pory"
	faceplayer
# 283 "data/maps/VictoryRoad_1F/scripts.pory"
	goto_if_set FLAG_TEMP_1, VictoryRoad_1F_EventScript_PowerfulMonSummoner_2
# 289 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_SummonerIntro, MSGBOX_YESNO
VictoryRoad_1F_EventScript_PowerfulMonSummoner_1:
# 292 "data/maps/VictoryRoad_1F/scripts.pory"
	setflag FLAG_TEMP_1
# 294 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VictoryRoad_1F_EventScript_PowerfulMonSummoner_6
VictoryRoad_1F_EventScript_PowerfulMonSummoner_5:
# 299 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ChooseRoom
# 300 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_PowerfulMonSummoner_2:
# 285 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_SummonerIntroQuick, MSGBOX_YESNO
	goto VictoryRoad_1F_EventScript_PowerfulMonSummoner_1

VictoryRoad_1F_EventScript_PowerfulMonSummoner_6:
# 296 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_SummonWomanManNo
	goto VictoryRoad_1F_EventScript_PowerfulMonSummoner_5


VictoryRoad_1F_EventScript_ChooseRoom::
# 305 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WhichRoom, MSGBOX_DEFAULT
# 307 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_ChooseRoom_Text_0, 0
# 308 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_ChooseRoom_Text_1, 1
# 309 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_ChooseRoom_Text_2, 2
# 310 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_ChooseRoom_Text_3, MULTI_B_PRESSED
# 314 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
# 316 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq VictoryRoad_1F_EventScript_ChooseRoom_2
VictoryRoad_1F_EventScript_ChooseRoom_1:
# 321 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq VictoryRoad_1F_EventScript_ChooseRoom_5
VictoryRoad_1F_EventScript_ChooseRoom_4:
# 325 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_ChooseRoom_8
VictoryRoad_1F_EventScript_ChooseRoom_7:
# 329 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq VictoryRoad_1F_EventScript_ChooseRoom_11
VictoryRoad_1F_EventScript_ChooseRoom_10:
# 334 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_ChooseRoom_2:
# 318 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_SummonWomanManNo
	goto VictoryRoad_1F_EventScript_ChooseRoom_1

VictoryRoad_1F_EventScript_ChooseRoom_5:
# 323 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_EntranceRoom
	goto VictoryRoad_1F_EventScript_ChooseRoom_4

VictoryRoad_1F_EventScript_ChooseRoom_8:
# 327 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_InnerRoom
	goto VictoryRoad_1F_EventScript_ChooseRoom_7

VictoryRoad_1F_EventScript_ChooseRoom_11:
# 331 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_StairsRoom
	goto VictoryRoad_1F_EventScript_ChooseRoom_10


VictoryRoad_1F_EventScript_EntranceRoom::
# 339 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WhichPokemon, MSGBOX_DEFAULT
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_0, SPECIES_GREAT_TUSK
# 342 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_1, SPECIES_SCREAM_TAIL
# 343 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_2, SPECIES_BRUTE_BONNET
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_3, SPECIES_FLUTTER_MANE
# 345 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_4, SPECIES_SLITHER_WING
# 346 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_5, SPECIES_SANDY_SHOCKS
# 347 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_6, SPECIES_ROARING_MOON
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_7, SPECIES_WALKING_WAKE
# 349 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_8, SPECIES_GOUGING_FIRE
# 350 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_9, SPECIES_RAGING_BOLT
# 351 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_10, MULTI_B_PRESSED
# 355 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, SPECIES_GREAT_TUSK, DYN_MULTICHOICE_CB_NONE
# 357 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq VictoryRoad_1F_EventScript_EntranceRoom_2
VictoryRoad_1F_EventScript_EntranceRoom_1:
# 362 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ConfirmAndUseSummon
# 364 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_EntranceRoom_2:
# 359 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ChooseRoom
	goto VictoryRoad_1F_EventScript_EntranceRoom_1


VictoryRoad_1F_EventScript_InnerRoom::
# 370 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WhichPokemon, MSGBOX_DEFAULT
# 372 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_0, SPECIES_IRON_TREADS
# 373 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_1, SPECIES_IRON_BUNDLE
# 374 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_2, SPECIES_IRON_HANDS
# 375 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_3, SPECIES_IRON_JUGULIS
# 376 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_4, SPECIES_IRON_MOTH
# 377 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_5, SPECIES_IRON_THORNS
# 378 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_6, SPECIES_IRON_VALIANT
# 379 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_7, SPECIES_IRON_LEAVES
# 380 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_8, SPECIES_IRON_BOULDER
# 381 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_InnerRoom_Text_9, SPECIES_IRON_CROWN
# 382 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_10, MULTI_B_PRESSED
# 386 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, SPECIES_IRON_TREADS, DYN_MULTICHOICE_CB_NONE
# 388 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq VictoryRoad_1F_EventScript_InnerRoom_2
VictoryRoad_1F_EventScript_InnerRoom_1:
# 393 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ConfirmAndUseSummon
# 395 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_InnerRoom_2:
# 390 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ChooseRoom
	goto VictoryRoad_1F_EventScript_InnerRoom_1


VictoryRoad_1F_EventScript_StairsRoom::
# 401 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_WhichPokemon, MSGBOX_DEFAULT
# 403 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_0, SPECIES_NIHILEGO
# 404 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_1, SPECIES_GUZZLORD
# 405 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_2, SPECIES_XURKITREE
# 406 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_3, SPECIES_BUZZWOLE
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_4, SPECIES_BLACEPHALON
# 408 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_5, SPECIES_STAKATAKA
# 409 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_6, SPECIES_POIPOLE
# 410 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_7, SPECIES_PHEROMOSA
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_8, SPECIES_CELESTEELA
# 412 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_StairsRoom_Text_9, SPECIES_KARTANA
# 413 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultipush VictoryRoad_1F_EventScript_EntranceRoom_Text_10, MULTI_B_PRESSED
# 417 "data/maps/VictoryRoad_1F/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, SPECIES_NIHILEGO, DYN_MULTICHOICE_CB_NONE
# 419 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq VictoryRoad_1F_EventScript_StairsRoom_2
VictoryRoad_1F_EventScript_StairsRoom_1:
# 424 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ConfirmAndUseSummon
# 426 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_StairsRoom_2:
# 421 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_ChooseRoom
	goto VictoryRoad_1F_EventScript_StairsRoom_1


VictoryRoad_1F_EventScript_ConfirmAndUseSummon::
# 433 "data/maps/VictoryRoad_1F/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 434 "data/maps/VictoryRoad_1F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 435 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_ConfirmSummon, MSGBOX_YESNO
# 437 "data/maps/VictoryRoad_1F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq VictoryRoad_1F_EventScript_ConfirmAndUseSummon_2
VictoryRoad_1F_EventScript_ConfirmAndUseSummon_1:
# 442 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_Text_VeryWell, MSGBOX_DEFAULT
# 443 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 30
# 445 "data/maps/VictoryRoad_1F/scripts.pory"
	setwildbattle VAR_0x8005, 50
# 446 "data/maps/VictoryRoad_1F/scripts.pory"
	waitse
# 447 "data/maps/VictoryRoad_1F/scripts.pory"
	playmoncry VAR_0x8005, CRY_MODE_ENCOUNTER
# 448 "data/maps/VictoryRoad_1F/scripts.pory"
	delay 40
# 449 "data/maps/VictoryRoad_1F/scripts.pory"
	waitmoncry
# 450 "data/maps/VictoryRoad_1F/scripts.pory"
	dowildbattle
# 451 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end

VictoryRoad_1F_EventScript_ConfirmAndUseSummon_2:
# 439 "data/maps/VictoryRoad_1F/scripts.pory"
	goto VictoryRoad_1F_EventScript_SummonWomanManNo
	goto VictoryRoad_1F_EventScript_ConfirmAndUseSummon_1


VictoryRoad_1F_EventScript_SummonWomanManNo::
# 457 "data/maps/VictoryRoad_1F/scripts.pory"
	msgbox VictoryRoad_1F_SummonWomanDeclined, MSGBOX_DEFAULT
# 458 "data/maps/VictoryRoad_1F/scripts.pory"
	release
	end


VictoryRoad_1F_EventScript_ChooseRoom_Text_0:
# 307 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Entrance Room$"

VictoryRoad_1F_EventScript_ChooseRoom_Text_1:
# 308 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Inner Room$"

VictoryRoad_1F_EventScript_ChooseRoom_Text_2:
# 309 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Stairs Room$"

VictoryRoad_1F_EventScript_ChooseRoom_Text_3:
# 310 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Cancel$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_0:
# 341 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Great Tusk$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_1:
# 342 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Scream Tail$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_2:
# 343 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Brute Bonnet$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_3:
# 344 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Flutter Mane$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_4:
# 345 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Slither Wing$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_5:
# 346 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Sandy Shocks$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_6:
# 347 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Roaring Moon$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_7:
# 348 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Walking Wake$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_8:
# 349 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Gouging Fire$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_9:
# 350 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Raging Bolt$"

VictoryRoad_1F_EventScript_EntranceRoom_Text_10:
# 351 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Back$"

VictoryRoad_1F_EventScript_InnerRoom_Text_0:
# 372 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Treads$"

VictoryRoad_1F_EventScript_InnerRoom_Text_1:
# 373 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Bundle$"

VictoryRoad_1F_EventScript_InnerRoom_Text_2:
# 374 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Hands$"

VictoryRoad_1F_EventScript_InnerRoom_Text_3:
# 375 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Jugulis$"

VictoryRoad_1F_EventScript_InnerRoom_Text_4:
# 376 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Moth$"

VictoryRoad_1F_EventScript_InnerRoom_Text_5:
# 377 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Thorns$"

VictoryRoad_1F_EventScript_InnerRoom_Text_6:
# 378 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Valiant$"

VictoryRoad_1F_EventScript_InnerRoom_Text_7:
# 379 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Leaves$"

VictoryRoad_1F_EventScript_InnerRoom_Text_8:
# 380 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Boulder$"

VictoryRoad_1F_EventScript_InnerRoom_Text_9:
# 381 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Iron Crown$"

VictoryRoad_1F_EventScript_StairsRoom_Text_0:
# 403 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Nihilego$"

VictoryRoad_1F_EventScript_StairsRoom_Text_1:
# 404 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Guzzlord$"

VictoryRoad_1F_EventScript_StairsRoom_Text_2:
# 405 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Xurkitree$"

VictoryRoad_1F_EventScript_StairsRoom_Text_3:
# 406 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Buzzwole$"

VictoryRoad_1F_EventScript_StairsRoom_Text_4:
# 407 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Blacephalon$"

VictoryRoad_1F_EventScript_StairsRoom_Text_5:
# 408 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Stakataka$"

VictoryRoad_1F_EventScript_StairsRoom_Text_6:
# 409 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Poipole$"

VictoryRoad_1F_EventScript_StairsRoom_Text_7:
# 410 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Pheromosa$"

VictoryRoad_1F_EventScript_StairsRoom_Text_8:
# 411 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Celesteela$"

VictoryRoad_1F_EventScript_StairsRoom_Text_9:
# 412 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Kartana$"

VictoryRoad_1F_Text_SummonerIntro::
# 463 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Hello, young trainer.\p"
	.string "I've come to this remote location\n"
	.string "because I have learned a powerful\l"
	.string "technique that allows me to summon one\l"
	.string "Pokémon from a remote location.\p"
	.string "Would you like me to summon a Pokémon\n"
	.string "here so you can battle it?$"

VictoryRoad_1F_Text_SummonerIntroQuick::
# 473 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Would you like me to summon a Pokémon\n"
	.string "here so you can battle it?$"

VictoryRoad_1F_Text_WhichRoom::
# 478 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Which room would you like me to summon a\n"
	.string "Pokémon from?$"

VictoryRoad_1F_Text_WhichPokemon::
# 483 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Which Pokémon would you like me to\n"
	.string "summon so you can battle?$"

VictoryRoad_1F_Text_ConfirmSummon::
# 488 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "So you want me to summon a\n"
	.string "{STR_VAR_1} for you to battle?$"

VictoryRoad_1F_Text_VeryWell::
# 493 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "Very well, prepare yourself for battle.$"

VictoryRoad_1F_SummonWomanDeclined::
# 497 "data/maps/VictoryRoad_1F/scripts.pory"
	.string "I see. Let me know if you change\n"
	.string "your mind.$"
