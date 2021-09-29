//Utilidades
#include <iostream>
#include <vector>
#include <string>

//Outras Classes
#include "InputManager.h"
#include "Telas.h"


//Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main()
{
	const int fps = 60;	//Frequência de atualização da tela
	//Inicialização do Allegro
	al_init();
	if (!al_init()) {
		al_show_native_message_box(NULL, "Erro", "Erro", "Allegro não iniciado", NULL, NULL);
		return -1;
	}

	//Definição do dislay
	ALLEGRO_DISPLAY* display;
	display = al_create_display(832, 512);
	if (!display) {
		al_show_native_message_box(NULL, "Erro", "Erro", "Display não iniciado", NULL, NULL);
		return -1;
	}

	//Inicializações
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / fps);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_EVENT event;

	//Eventos
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_display_event_source(display));

	//Variáveis auxiliares
	bool done = false;																//Variável de looping de jogo
	std::vector<int> keys;															//Vetor de teclas
	keys.push_back(ALLEGRO_KEY_ESCAPE);												//Tecla esc no vetor

	InputManager input;							//Intsância do teclado

	//Inicialização das classes
	Telas::GetInstance().Initialize();
	Telas::GetInstance().LoadContent();

	al_start_timer(timer);						//Temporizador iniciado
	while (!done) {								//Looping do jogo
		al_wait_for_event(queue, &event);		//Esperar por algum evento
		al_get_keyboard_state(&kbdstate);		//Atualizar o teclado

		if (input.IsKeyReleased(event, keys) || event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { 
			//Fecha o programa caso aperte esc ou feche o display
			done = true;
		}

		//Atualiza as classes e imprime as imagens 
		Telas::GetInstance().Update(event);
		Telas::GetInstance().Draw(display);
		al_flip_display();
	}
	Telas::GetInstance().UnloadContent();		//Descarrega os itens não encerrados
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(queue);
	return 0;
}
