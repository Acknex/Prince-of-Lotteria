#ifndef lvlLottifant_h
#define lvlLottifant_h

#include "bmap.h"

// prototypes

	void lvlLfInit ();
	void lvlLfReset ();
	void lvlLfStart ();
	void lvlLfExit (BOOL bNextLevel);
	
	void on_exit_lotti ();
	
// defines

	#define LVL_LOTTIFANT_PX_GROUP_ALL 1
	#define LVL_LOTTIFANT_PX_GROUP_BALL 3
	#define LVL_LOTTIFANT_PX_GROUP_ROCKPIECE 4
	#define LVL_LOTTIFANT_PX_GROUP_PLAYER 5
	
	#define LVL_LOTTIFANT_WMB "lottifant.wmb"
	#define LF_LOTTI_FILE "zorroLotti_sit.mdl"
	
	BOOL g_lvlLfDeregister = false;
	
// hdr

	#define LVL_LOTTIFANT_HDR_THRESHOLD 55
	#define LVL_LOTTIFANT_HDR_STRENGTH 5
	#define LVL_LOTTIFANT_HDR_EXPOSURE 0	
	
// sounds

	// music
	SOUND* g_musicLottifant = "lottifantLoop.ogg";
	
	SOUND* g_sndLvlLfRockBreak = "rockBreakApart.ogg";
	
// sprites

	BmapBank* g_bbLfCollisionDust = NULL;

// globals

	var g_lvlLfGravity = 10;
	var g_lvlLfRideForce = 400;
	var g_lvlLfJumpForce = 38;
	var g_lvlLfSpeedMax = 30;
	var g_lvlLfDownForce = 480;

	var g_fhLvlLottifantSong = 0;
	
	var g_lvlLottifantCamArc = 85;
	var g_lvlLottifantCamDist = 1350;
	
	var g_lvlLfBallSpeedMax = 170;
	var g_lvlLfBallDownForce = 100;
	
	ENTITY* g_entLvlLfBall = NULL;
	VECTOR g_vecEntLvlBallLast;
	
	ENTITY* g_entLvlLfPlayer = NULL;
	
	EVENT on_exit_restore = NULL; // hack

#include "lvlLottifant.c"

#endif /* lvlLottifant_h */