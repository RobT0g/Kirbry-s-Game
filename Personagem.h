#pragma once

//Utilidades
#include <stdio.h>
#include <vector>

//Outras Classes
#include "InputManager.h"
#include "Colision.h"

//Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Personagem

{
private:
	//Imagens
	ALLEGRO_BITMAP* base = NULL, * run = NULL, * down = NULL, * jump = NULL;
	ALLEGRO_BITMAP* baseI = NULL, * runI = NULL, * downI = NULL, * jumpI = NULL;

	InputManager input;		//Instância do teclado
	Colision col;

	//Variáveis locais
	float posx, posy;
	float posiy;
	float velx, vely, timeri;
	const float  accel = 0.5;
	const float grav = 0.8, jumpspeed = 18.0, maxspeed = 6.0;
	const int height = 512, width = 832;
	const int runspeed = (width-32) / 5;
	const int floory = height - 16 - 32;
	bool dirR, jumping, alive, haskey, isfinished;

public:
	Personagem(void);
	~Personagem(void);

	void Initialize();
	void Initialize(float x, float y);
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT event);
	void Draw(ALLEGRO_DISPLAY* display);
	float Modu(float i);
	void SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	bool GetLifeStatus();
	bool GetKeyStatus();
	bool GetIsFinished();
	void ResetHasKey();
};

