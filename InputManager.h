#pragma once

//Utilidades
#include <vector>
#include <string>

//Allegro
#include<allegro5/allegro.h>
#include<allegro5/keyboard.h>

class InputManager

{
private:
	ALLEGRO_KEYBOARD_STATE kbdstate;									//Estado do teclado

public:
	InputManager(void);
	~InputManager(void);												//Finaliza��o da classe

	//M�todos
	bool IsKeyPressed(ALLEGRO_EVENT event, int key);					//Momento em que uma tecla � pressionada
	bool IsKeyPressed(ALLEGRO_EVENT event, std::vector<int> keys);		//Momento em que diversas teclas s�o pressionadas
	bool IsKeyReleased(ALLEGRO_EVENT event, int key);					//Momento em que uma tecla � solta
	bool IsKeyReleased(ALLEGRO_EVENT event, std::vector<int> keys);		//Momento em que diversas teclas s�o soltas
	bool WhileKeyPressed(ALLEGRO_EVENT, int key);						//Retorna verdadeiro continuamente enquanto a tecla � pressionada
	bool WhileKeyPressed(ALLEGRO_EVENT, std::vector<int> keys);			//Retorna verdadeiro continuamente enquanto as teclas s�o pressionadas
};

