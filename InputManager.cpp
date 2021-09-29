#include "InputManager.h"

InputManager::InputManager(void){} //Abertura da classe
InputManager::~InputManager(void){} //Finalização da classe

//Métodos
bool InputManager::IsKeyPressed(ALLEGRO_EVENT event, int key){
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		if (event.keyboard.keycode == key) {
			return true;
		}
	}
	return false;
}

bool InputManager::IsKeyPressed(ALLEGRO_EVENT event, std::vector<int> keys){
	if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
		for (int i = 0; i < keys.size(); i++) {
			if (event.keyboard.keycode == keys[i]) {
				return true;
			}
		}
	}
	return false;
}

bool InputManager::IsKeyReleased(ALLEGRO_EVENT event, int key){
	if (event.type == ALLEGRO_EVENT_KEY_UP) {
		if (event.keyboard.keycode == key) {
			return true;
		}
	}
	return false;
}

bool InputManager::IsKeyReleased(ALLEGRO_EVENT event, std::vector<int> keys){
	if (event.type == ALLEGRO_EVENT_KEY_UP) {
		for (int i = 0; i < keys.size(); i++) {
			if (event.keyboard.keycode == keys[i]) {
				return true;
			}
		}
	}
	return false;
}

bool InputManager::WhileKeyPressed(ALLEGRO_EVENT event, int key) {
	al_get_keyboard_state(&kbdstate);
	if (al_key_down(&kbdstate, key)) {
		return true;
	}
	return false;
}

bool InputManager::WhileKeyPressed(ALLEGRO_EVENT event, std::vector<int> keys) {
	al_get_keyboard_state(&kbdstate);
	for (int i = 0; i < keys.size(); i++) {
		if (al_key_down(&kbdstate, keys[i])) {
			return true;
		}
		return false;
	}
	return false;
}

