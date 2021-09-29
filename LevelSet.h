#pragma once

//Utilidades
#include <vector>

//Outras classes
#include "TitleScreen.h"
#include "LevelDrawer.h"

class LevelSet
{
private:

	//Vari�veis
	struct itemspos {
		std::vector<float> x, y;
		std::vector<bool> common;
	};
	struct itemspos blocks, spikes, keys, doors;
	int level;						//N�vel atual do jogo
	bool isFinished;				//Vari�vel de conclus�o de n�vel
	bool haskey;

	InputManager input;				//Inst�ncia do teclado

	//Inst�ncias de n�veis:
	TitleScreen ts;
	LevelDrawer lvld;

public:
	LevelSet(void);
	~LevelSet(void);

	//Para os n�veis espec�ficos
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT event);
	void Draw(ALLEGRO_DISPLAY* display);

	//Para o controle do n�vel
	void SetLevelTitle();				//Define o n�vel como 0 no come�o
	void SetIsFinished();				//Define o n�vel como conclu�do
	void SetLevel(int i);				//Retorna o n�vel atual
	bool GetIsFinished();				//Retorna o estado de conclus�o de n�vel
	void SetHasKey(bool value);

	//Para os itens nos n�veis
	void SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsCommon(std::vector<bool> spos);
};

