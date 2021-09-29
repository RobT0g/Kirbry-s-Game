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
	Personagem ps;							//Instância da classe do personagem
	Colision col;							//Instância da classe de colisões
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
	~Telas(void);							//Finalização da classe
	static Telas& GetInstance();

	void Initialize();						//Inicialização 
	void LoadContent();						//Carregar o conteúdo
	void UnloadContent();					//Descarregar o conteúdo
	void Update(ALLEGRO_EVENT event);		//Atualizar
	void Draw(ALLEGRO_DISPLAY *display);	//Imprimir os itens
	void SetItemsPos();
	float DefHeight(int value);
	void LevelUp();
	void ResetHasKey();
};

