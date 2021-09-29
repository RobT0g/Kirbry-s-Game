#include "TitleScreen.h"

TitleScreen::TitleScreen(void){}
TitleScreen::~TitleScreen(void){}

void TitleScreen::LoadContents() {
	if (run == NULL) {
		InitializeVars();
		run = al_load_bitmap("Sprite_Run_Full.png");
	}
	if (font1 == NULL) {
		font1 = al_load_ttf_font("Fonte1.ttf", 70, NULL);
	}
	if (font2 == NULL) {
		font2 = al_load_ttf_font("Fonte1.ttf", 20, NULL);
	}
}

void TitleScreen::UnloadContents() {
	if (run) {
		al_destroy_bitmap(run);
	}
	if (font1) {
		al_destroy_font(font1);
	}
	if (font2) {
		al_destroy_font(font2);
	}
}

void TitleScreen::GameTitle(ALLEGRO_DISPLAY* display) {
	al_clear_to_color(al_map_rgba_f(1, 0.714, 0.757, 0));
	al_draw_text(font1, al_map_rgb(0, 0, 0), al_get_display_width(display) / 2, 100, ALLEGRO_ALIGN_CENTRE, "Kirbry's Game");
	al_draw_text(font2, al_map_rgb(0, 0, 0), al_get_display_width(display) / 2, 200, ALLEGRO_ALIGN_CENTRE, "Press Enter");
}

void TitleScreen::GameTitleChar(ALLEGRO_DISPLAY* display){
	posx = (160 * px) / 60;
	posy = al_get_display_height(display) - 20 - 50;
	if (timer % 30 >= 0 && timer % 30 < 30 / 5) {
		al_draw_bitmap_region(run, 0, 0, 44, 50, posx, posy, 0);
	}
	if (timer % 30 >= 30 / 5 && timer % 30 < 2 * 30 / 5) {
		al_draw_bitmap_region(run, 44, 0, 44, 50, posx, posy, 0);
	}
	if (timer % 30 >= 2 * 30 / 5 && timer % 30 < 3 * 30 / 5) {
		al_draw_bitmap_region(run, 88, 0, 44, 50, posx, posy, 0);
	}
	if (timer % 30 >= 3 * 30 / 5 && timer % 30 < 4 * 30 / 5) {
		al_draw_bitmap_region(run, 132, 0, 44, 50, posx, posy, 0);
	}
	if (timer % 30 >= 4 * 30 / 5 && timer % 30 < 5 * 30 / 5) {
		al_draw_bitmap_region(run, 176, 0, 44, 50, posx, posy, 0);
	}
}

void TitleScreen::UpdateTimer(ALLEGRO_EVENT event) {
	if (event.type == ALLEGRO_EVENT_TIMER) {
		if (timer < 60) {
			timer++;
		}
		else {
			timer = 0;
		}
		if (px > 300) {
			px = -17;
		}
		else {
			px++;
		}
	}
}

void TitleScreen::InitializeVars() {
	px = 0;
	timer = 0;
}

