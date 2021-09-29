#pragma once

//Outras Classes
#include "InputManager.h"
//#include "Telas.h"

//Inclusões Allegro
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class TitleScreen
{
private:
	ALLEGRO_BITMAP* run = NULL;
	ALLEGRO_FONT *font1 = NULL, *font2 = NULL;
	float posx = 0;					//Variável local de posição x
	int px;							//Variável local de auxílio posição px
	float posy;						//Variável local de posição y
	int timer;

public:
	TitleScreen(void);
	~TitleScreen(void);
	void LoadContents();
	void UnloadContents();
	void GameTitle(ALLEGRO_DISPLAY* display);
	void GameTitleChar(ALLEGRO_DISPLAY* display);
	void UpdateTimer(ALLEGRO_EVENT event);
	void InitializeVars();
};

