#ifndef _GAME_H_
#define _GAME_H_

var vGameMusicHandle = 0;

PANEL* panLoad = NULL;
PANEL* panLoadBar = NULL;
PANEL* panMute = NULL;

BMAP* bmapMute = "..\\images\\mute.tga";

var vDummy = 0;
var vDummy2 = 0;

void game_start ();
void game_restart ();
void level_load_ext (STRING* _lvl);
void game_hotkeys ();

// hdr

	#define LVL_INTRO_HDR_THRESHOLD 10
	#define LVL_INTRO_HDR_STRENGTH 25
	#define LVL_INTRO_HDR_EXPOSURE 10

// sounds

	SOUND* g_sndDoor = "door.ogg";

#include "game.c"

#endif // #ifndef _GAME_H_