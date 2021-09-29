#pragma once

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class LevelDrawer

{
private:
	ALLEGRO_BITMAP* floor = NULL, * tile = NULL, * tile5 = NULL, *tile5v = NULL		//Chão e Blocos
		, * spikes = NULL, * spikes5 = NULL, *spikes5v = NULL						//Spikes
		, * key = NULL, * door = NULL;												//Chaves e Portas
	ALLEGRO_FONT* font1, *font2;
	int itimer;

public:
	LevelDrawer(void);
	~LevelDrawer(void);

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT event);
	void FrameDrawer(ALLEGRO_DISPLAY* display);
	void BlocksDrawer(float x, float y, float dx, float dy, ALLEGRO_DISPLAY* display);
	void SpikesDrawer(float x, float y, float dx, float dy, bool common, ALLEGRO_DISPLAY* display);
	void KeysDrawer(float x, float y, ALLEGRO_DISPLAY* display);
	void DoorDrawer(float x, float y, ALLEGRO_DISPLAY* display);
	void SetFinishScreen(ALLEGRO_DISPLAY* display);
};

