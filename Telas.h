#pragma once

//Outras classes
#include "InputManager.h"
#include "LevelSet.h"
#include "Personagem.h"


class Telas
{
private:
	Telas();								//Abertura da classe
	Telas(Telas const&);
	Personagem ps;							//Inst�ncia da classe do personagem
	Colision col;							//Inst�ncia da classe de colis�es
	LevelSet lvl;
	InputManager input;

	struct itemspos {
		std::vector<float> x, y;
		std::vector<bool> common;
	};
	struct itemspos blocks, spikes, keys, doors;
	const float width = 832.0, height = 512.0;
	int level;
	bool isFinished;

public:
	~Telas(void);							//Finaliza��o da classe
	static Telas& GetInstance();

	void Initialize();						//Inicializa��o 
	void LoadContent();						//Carregar o conte�do
	void UnloadContent();					//Descarregar o conte�do
	void Update(ALLEGRO_EVENT event);		//Atualizar
	void Draw(ALLEGRO_DISPLAY *display);	//Imprimir os itens
	void SetItemsPos();
	float DefHeight(int value);
	void LevelUp();
	void ResetHasKey();
};

