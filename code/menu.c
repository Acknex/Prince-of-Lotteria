#ifndef _MENU_C_
#define _MENU_C_

#include "menu.h"

#include "achievements.h"
#include "game.h"

action acMenuSphere ()
{
	my->material = g_menuMtlFx;
}

void menu_open ()
{
	redness = 0;
	
	// fix
	g_bLvlTempleRunning = false;
	g_bLvlLavastageRunning = false;
	
	level_load("menu.wmb");
	
	setPpSwirl(0.4, 0.8, 0.5, 0.5, 0);
	
	char *str = "Press [SPACE] to start!";
	
	menuLen = strlen(str);
	menuTexts = sys_malloc(menuLen * sizeof(TEXT*));
	
	setHdr(LVL_MENU_HDR_STRENGTH, LVL_MENU_HDR_THRESHOLD, LVL_MENU_HDR_EXPOSURE);
	
	int i;
	for (i = 0; i < menuLen; i++)
	{
		menuTexts[i] = txt_create(1, 52);
		
		char s[2];
		s[0] = str[i];
		s[1] = 0;
		(menuTexts[i].pstring)[0] = str_create(s);
		menuTexts[i].font = menuFont;
		menuTexts[i].flags = OVERLAY | CENTER_Y | SHADOW | OUTLINE;
	}
	
	wait(3);
	
	snd_stopall(4);
	var menuLoop = snd_loop(menuBackgroundMusic, 100, 0);
	
	var tick = 0;
	var invert = 0;
	var tickdown = 0;
	var ksp_last = key_space;
	var kq_last = key_q;
	
	while (1)
	{
		if (tick > 1)
		{
			invert = 1 - invert;
			tick = 0;
		}
		
		menuTitle->scale_x = (screen_size.x * 0.5) / menuTitle->bmap->width;
		menuTitle->scale_y = menuTitle->scale_x;
		menuTitle.pos_x = 0.5 * (screen_size.x - bmap_width(menuTitle.bmap) * menuTitle.scale_x);
		menuTitle.pos_y = screen_size.y * 0.2 - (menuTitle->bmap->height/2 * menuTitle->scale_y);
		menuTitle.flags |= SHOW;
		
		int startOffset = 100;
		
		for (i = 0; i < menuLen; i++)
		{
			menuTexts[i].pos_x = cycle(32 * i - 16 * (total_ticks - startOffset), -0.5 * screen_size.x, 1.5 * screen_size.x);
			menuTexts[i].pos_y = menuTextsY * screen_size.y + menuTitle->scale_y * 32 * sinv(8 * total_ticks + 8 * i);
			menuTexts[i].flags |= SHOW;
		}
		
		menuInfo.flags |= SHOW;		
		menuInfo.pos_y = screen_size.y - menuInfo.font.dy - menuInfo.pos_x;
		
		if (ksp_last != key_space)
		{
			if (key_space)
			{
				tickdown = 16;
				break;
			}
			ksp_last = key_space;
		}
		
		if (kq_last != key_q)
		{
			if(key_q)
			{
				menu_close();
				achievementsExit();
				return;
			}
			
			kq_last = key_q;
		}
		
		wait(1);
	}
	
	if (menuTexts != NULL)
	{
		for (i = 0; i < menuLen; i++)
			if(menuTexts[i] != NULL)
				txt_remove(menuTexts[i]);
		
		sys_free(menuTexts);
		menuTexts = NULL;
	}
	
	menuTitle.flags &= ~SHOW;
	menuInfo.flags &= ~SHOW;
	
	snd_stopall(4);
	
	menu_close();
	game_start();
}

void menu_close ()
{
	menuTitle.flags &= ~SHOW;
	menuInfo.flags &= ~SHOW;
	
	if (menuTexts != NULL)
	{
		int i;
		for (i = 0; i < menuLen; i++)
		{
			if (menuTexts[i] != NULL)
			txt_remove(menuTexts[i]);
		}
		
		sys_free(menuTexts);
		menuTexts = NULL;
	}
}

#endif // #ifndef _MENU_C_