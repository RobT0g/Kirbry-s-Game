#pragma once

//Utilidades
#include <vector>
#include <iostream>

//Outras classes

class Colision

{
private:
	//Colision(Colision const&);
	//Instâncias dos níveis
	//Variáveis
	struct positions
	{
		std::vector<float> x, y;
	};
	struct positions blocks, spikes, keys, doors;
	bool onFloor = false, onRoof = false;
	bool be, se, ke, de;
	std::vector<int> whereat;			//1 em cima, 2 esquerda, 3 em baixo, 4 direita

public:
	Colision();
	~Colision();

	//Blocks Colisions
	std::vector<float> GetColision(float x, float y, float nx, float ny);
	void WhereAt(float x, float y, int i);
	void SetOnFloor();
	void SetOnRoof();
	bool ColSoon(float x, float y, float nx, float ny, int i);
	bool GetOnFloor();
	bool GetOnRoof();

	//Spikes Colisions
	bool GetSpikCol(float x, float y);

	bool GetKeyCol(float x, float y);
	bool GetDoorCol(float x, float y);
	void SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
	void SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos);
};

