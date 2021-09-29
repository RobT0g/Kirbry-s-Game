#include "LevelDrawer.h"

LevelDrawer::LevelDrawer(void){}
LevelDrawer::~LevelDrawer(void){}

void LevelDrawer::LoadContent() {
	if (floor == NULL) {
		floor = al_load_bitmap("Floor1.png");
	}
	if (tile == NULL) {
		tile = al_load_bitmap("Single_Box.png");
	}
	if (tile5 == NULL) {
		tile5 = al_load_bitmap("5Box.png");
	}
	if (tile5v == NULL) {
		tile5v = al_load_bitmap("5VBox.png");
	}
	if (spikes == NULL) {
		spikes = al_load_bitmap("Spikes.png");
	}
	if (spikes5 == NULL) {
		spikes5 = al_load_bitmap("5Spikes.png");
	}
	if (spikes5v == NULL) {
		spikes5v = al_load_bitmap("5VSpikes.png");
	}
	if (key == NULL) {
		key = al_load_bitmap("Chave.png");
	}
	if (door == NULL) {
		door = al_load_bitmap("Porta.png");
	}
	if (font1 == NULL) {
		font1 = al_load_ttf_font("Fonte1.ttf", 70, NULL);
	}
	if (font2 == NULL) {
		font2 = al_load_ttf_font("Fonte1.ttf", 20, NULL);
	}
}

void LevelDrawer::UnloadContent() {
	if (floor) {
		al_destroy_bitmap(floor);
	}
	if (tile) {
		al_destroy_bitmap(tile);
	}
	if (tile5) {
		al_destroy_bitmap(tile5);
	}
	if (tile5v) {
		al_destroy_bitmap(tile5v);
	}
	if (spikes) {
		al_destroy_bitmap(spikes);
	}
	if (spikes5) {
		al_destroy_bitmap(spikes5);
	}
	if (spikes5v) {
		al_destroy_bitmap(spikes5v);
	}
	if (key) {
		al_destroy_bitmap(key);
	}
	if (door) {
		al_destroy_bitmap(door);
	}
	if (font1) {
		al_destroy_font(font1);
	}
	if (font2) {
		al_destroy_font(font2);
	}
}

void LevelDrawer::Update(ALLEGRO_EVENT event) {
	if (itimer < 59) {
		itimer++;
	}
	else {
		itimer = 0;
	}
}

void LevelDrawer::FrameDrawer(ALLEGRO_DISPLAY* display) {
	al_clear_to_color(al_map_rgba_f(0.529, 0.808, 0.922, 0));
	float floory = al_get_display_height(display) - 16;
	float width = al_get_display_width(display);
	al_draw_bitmap(floor, 0, -16, ALLEGRO_FLIP_VERTICAL);
	al_draw_rotated_bitmap(floor, 0, 0, 16, 16, 1.57, NULL);
	al_draw_rotated_bitmap(floor, 0, 0, width+16, 16, 1.57, ALLEGRO_FLIP_VERTICAL);
	al_draw_bitmap(floor, 0, floory, NULL);
}

void LevelDrawer::BlocksDrawer(float x, float dx, float y, float dy, ALLEGRO_DISPLAY* display) {
	if (dx <= 32) {
		if (dy <= 32) {
			al_draw_bitmap(tile, x, y, NULL);
		}
		else {
			al_draw_bitmap_region(tile5v, 0, 0, dx, dy, x, y, 0);
		}
	} else if (dy == 32) {
		al_draw_bitmap_region(tile5, 0, 0, dx, dy, x, y, 0);
	}
}

void LevelDrawer::SpikesDrawer(float x, float dx, float y, float dy, bool common, ALLEGRO_DISPLAY* display) {
	if (common) {
		if (dx <= 32) {
			if (dy <= 32) {
				al_draw_bitmap(spikes, x, y, NULL);
			}
			else {
				al_draw_bitmap_region(spikes5v, 0, 0, dx, dy, x, y, NULL);
			}
		}
		else {
			al_draw_bitmap_region(spikes5, 0, 0, dx, dy, x, y, NULL);
		}
	}
	else {
		if (dx <= 32) {
			if (dy <= 32) {
				al_draw_bitmap(spikes, x, y, ALLEGRO_FLIP_VERTICAL);
			}
			else {
				al_draw_bitmap_region(spikes5v, 0, 0, dx, dy, x, y, ALLEGRO_FLIP_HORIZONTAL);
			}
		}
		else {
			al_draw_bitmap_region(spikes5, 0, 0, dx, dy, x, y, ALLEGRO_FLIP_VERTICAL);
		}
	}
}

void LevelDrawer::KeysDrawer(float x, float y, ALLEGRO_DISPLAY* display) {
	if (itimer < 119)
		itimer++;
	else
		itimer = 0;

	al_draw_bitmap(key, x, y + (itimer / 60), NULL);
}

void LevelDrawer::DoorDrawer(float x, float y, ALLEGRO_DISPLAY* display){
	al_draw_bitmap(door, x, y, NULL);
}

void LevelDrawer::SetFinishScreen(ALLEGRO_DISPLAY* display) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font1, al_map_rgb(255, 255, 255), al_get_display_width(display) / 2, 100, ALLEGRO_ALIGN_CENTRE, "Game End");
	al_draw_text(font2, al_map_rgb(255, 255, 255), al_get_display_width(display) / 2, 200, ALLEGRO_ALIGN_CENTRE, "Thanks for playing!");
}
