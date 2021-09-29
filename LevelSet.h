#pragma once

//Utilidades
#include <vector>

//Outras classes
#include "TitleScreen.h"
#include "LevelDrawer.h"

class LevelSet
{
private:

	//Variáveis
	struct itemspos {
		std::vector<float> x, y;
		std::vector<bool> common;
	};
	struct itemspos blocks, spikes, keys, doors;
	int level;						//Nível atual do jogo
	bool isFinished;				//Variável de conclusão de nível
	bool haskey;

	InputManager input;				//Instância do teclado

	//Instâncias de níveis:
	TitleScreen ts;
	LevelDrawer lvld;

public:
	LevelSet(void);
	~LevelSet(void);

	//Para os níveis específicos
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT event);
	void Draw(ALLEGRO_DISPLAY* display);

	//Para o controle do nível
	void SetLevelTitle();				//Define o nível como 0 no começo
	void SetIsFinished();				//Define o nível como concluído
	void SetLevel(int i);				//Retorna o nível atual
	bool GetIsFinished();				//Retorna o estado de conclusão de nível
	void SetHasKey(bool value);

	//Para os itens nos níveis
	void SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsCommon(std::vector<bool> spos);
};

