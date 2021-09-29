#include "Personagem.h"

Personagem::Personagem(void){}
Personagem::~Personagem(void){}

void Personagem::Initialize() {
	//Valores inicias para as variáveis de movimentação
	posx = 16;
	posy = floory;
	velx = 0;
	vely = 0;
	timeri = 0;
	dirR = true;
	jumping = false;
	ResetHasKey();
	isfinished = false;
	col.SetOnFloor();
}

void Personagem::Initialize(float x, float y) {
	posx = x;
	posy = y;
	velx = 0;
	vely = 0;
	timeri = 0;
	dirR = true;
	jumping = false;
	ResetHasKey();
	isfinished = false;
	col.SetOnFloor();
}

void Personagem::LoadContent() {
	if (base == NULL) {
		base = al_load_bitmap("Sprite_Base.png");
	}
	if (baseI == NULL) {
		baseI = al_load_bitmap("Sprite_BaseI.png");
	}
}

void Personagem::UnloadContent() {
	if (base) {
		al_destroy_bitmap(base);
	}
}

void Personagem::Update(ALLEGRO_EVENT event) {
	alive = true;
	if (vely == 0) {
		jumping = false;
	}
	if (input.IsKeyPressed(event, ALLEGRO_KEY_SPACE) && !jumping) {
		jumping = true;
		vely = -jumpspeed;
		posiy = posy;
		col.SetOnFloor();
	}
	if (event.type == ALLEGRO_EVENT_TIMER) {
		col.SetOnRoof();
		if (timeri < 60)
			timeri++;
		else
			timeri = 0;

		if (input.WhileKeyPressed(event, ALLEGRO_KEY_D) && !input.WhileKeyPressed(event, ALLEGRO_KEY_A)) {
			dirR = true;
			if (velx < maxspeed) {
				if (velx > 0) {
					velx += 2 * accel;
				}
				else {
					velx += accel;
				}
			}
			else
				velx = maxspeed;
		}else if (input.WhileKeyPressed(event, ALLEGRO_KEY_A) && !input.WhileKeyPressed(event, ALLEGRO_KEY_D)) {
			dirR = false;
			if (velx > -maxspeed) {
				if (velx > 0) {
					velx -= 2 * accel;
				}
				else {
					velx -= accel;
				}
			}
			else
				velx = -maxspeed;
		}
		else if (!input.WhileKeyPressed(event, ALLEGRO_KEY_A) && !input.WhileKeyPressed(event, ALLEGRO_KEY_D)) {
			if (velx != 0) {
				if (velx < 0) {
					velx += accel/2;
				}
				else {
					velx -= accel/2;
				}
			}
		}
		if (vely != jumpspeed) {
			vely += grav;
		}

		if (col.GetOnFloor()) {
			vely = 0;
		}
		if (col.GetOnRoof()) {
			vely = 0;
		}
		posx = col.GetColision(posx, posy, posx + velx, posy + vely)[0];
		posy = col.GetColision(posx, posy, posx + velx, posy + vely)[1];
		if (col.GetSpikCol(posx, posy)) {
			alive = false;
		}
		if(col.GetKeyCol(posx, posy))
			haskey = true;
		if (input.WhileKeyPressed(event, ALLEGRO_KEY_W) && col.GetDoorCol(posx, posy) && haskey) {
			isfinished = true;
		}
	}
}

void Personagem::Draw(ALLEGRO_DISPLAY* display) {
	if(dirR)
		al_draw_bitmap(base, posx, posy, NULL);
	else
		al_draw_bitmap(baseI, posx, posy, NULL);
}

float Personagem::Modu(float i) {
	if (i < 0) {
		return -i;
	}
	return i;
}

void Personagem::SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	col.SetItemsPosx(bpos, spos, kpos, dpos);
}

void Personagem::SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	col.SetItemsPosy(bpos, spos, kpos, dpos);
}

bool Personagem::GetLifeStatus() {
	return alive;
}

bool Personagem::GetKeyStatus() {
	return haskey;
	if(haskey)
		printf("tem");
}

bool Personagem::GetIsFinished() {
	return isfinished;
}

void Personagem::ResetHasKey() {
	haskey = false;
}