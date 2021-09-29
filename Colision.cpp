#include "Colision.h"

//Colision& Colision::GetInstance() {
//	static Colision instance;
//	return instance;
//}

Colision::Colision(){}
Colision::~Colision(){}

std::vector<float> Colision::GetColision(float x, float y, float nx, float ny) {
	std::vector<float> position = { nx, ny };
	if (!be) {
		for (int i = 0; i < blocks.x.size() / 2; i++) {
			WhereAt(x, y, i);
			if (whereat[i] == 2 && ColSoon(x, y, nx, ny, i)) {
				position[0] = blocks.x[2 * i] - 32;
				if (onFloor) {
					position[1] = y;
					SetOnFloor();
				}
			}
			else if (whereat[i] == 4 && ColSoon(x, y, nx, ny, i)) {
				position[0] = blocks.x[2 * i] + blocks.x[2 * i + 1];
				if (onFloor) {
					position[1] = y;
					SetOnFloor();
				}
			}
			else if (whereat[i] == 1 && ColSoon(x, y, nx, ny, i)) {
				position[1] = blocks.y[2 * i] - 32;
				onFloor = true;
			}
			else if (whereat[i] == 3 && ColSoon(x, y, nx, ny, i)) {
				position[1] = blocks.y[2 * i] + blocks.y[2 * i + 1] + 1;
				onRoof = true;
			}
			if (nx > 832 - 16 - 32) {
				position[0] = 832 - 16 - 32;
			}
			else if (nx - 1 < 16) {
				position[0] = 17;
			}
			if (ny > 512 - 16 - 32) {
				position[1] = 512 - 16 - 32;
				onFloor = true;
			}
			else if (ny - 1 < 16) {
				position[1] = 16;
				onRoof = true;
			}
		}
	}
	return position;
}

void Colision::WhereAt(float x, float y, int i) {
	if (x < blocks.x[2 * i] - 20) {
		if (y + 32 >= blocks.y[2*i] && y <= blocks.y[2 * i] +blocks.y[2*i+1]) {
			whereat[i] = 2;
		}
	}
	else if (x >= blocks.x[2 * i] - 20 && x + 10 <= blocks.x[2 * i] + blocks.x[2 * i + 1]) {
		if (y + 32 <= blocks.y[2*i]) {
			whereat[i] = 1;
		}
		else if (y+32 > blocks.y[2*i] && x+32 <= blocks.x[2*i]) {
			whereat[i] = 2;
		}
		else if (y + 32 > blocks.y[2 * i] && x >= blocks.x[2 * i] + blocks.x[2 * i + 1]) {
			whereat[i] = 4;
		}
		else {
			whereat[i] = 3;
		}
	}
	else {
		if (y + 32 >= blocks.y[2 * i] && y <= blocks.y[2 * i] + blocks.y[2 * i + 1]) {
			whereat[i] = 4;
		}
	}
}

void Colision::SetOnFloor() {
	onFloor = false;
}

void Colision::SetOnRoof() {
	onRoof = false;
}

bool Colision::GetOnFloor() {
	return onFloor;
}

bool Colision::GetOnRoof() {
	return onRoof;
}

bool Colision::ColSoon(float x, float y, float nx, float ny, int i) {
	if (nx + 32 >= blocks.x[2 * i] && nx - 1 <= blocks.x[2 * i] + blocks.x[2 * i + 1] || x + 31 >= blocks.x[2 * i] && x + 1 <= blocks.x[2 * i] + blocks.x[2 * i + 1]) {
		if (ny + 32 >= blocks.y[2 * i] && ny - 1 <= blocks.y[2 * i] + blocks.y[2 * i + 1] || y + 31 >= blocks.y[2 * i] && y + 1 <= blocks.y[2 * i] + blocks.y[2 * i + 1]) {
			//printf("bateu\n");
			return true;
		}
	}
	return false;
}

bool Colision::GetSpikCol(float x, float y) {
	if (!se) {
		for (int i = 0; i < spikes.x.size()/2; i++) {
			if (x + 32 >= spikes.x[2*i] && x <= spikes.x[2*i] + spikes.x[2*i+1] && y + 32 >= spikes.y[2*i] && y <= spikes.y[2*i] + spikes.y[2*i+1]) {
				return true;
			}
		}
	}
	return false;
}

bool Colision::GetKeyCol(float x, float y){
	if (!ke) {
		if (x+32 >= keys.x[0] && x <= keys.x[0] + keys.x[1] && y+32 >= keys.y[0] && y <= keys.y[0] + keys.y[1]) {
			return true;
		}
	}
	
	return false;
}

bool Colision::GetDoorCol(float x, float y){
	if (!de) {
		if (x + 32 >= doors.x[0] && x <= doors.x[0] + doors.x[1] && y + 32 >= doors.y[0] && y <= doors.y[0] + doors.y[1]) {
			return true;
		}
	}
	return false;
}

void Colision::SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	blocks.x.clear();
	spikes.x.clear();
	keys.x.clear();
	doors.x.clear();

	blocks.x = bpos;
	spikes.x = spos;
	keys.x = kpos;
	doors.x = dpos;

	if (blocks.x.empty())
		be = true;
	else
		be = false;
	if (spikes.x.empty())
		se = true;
	else
		be = false;
	if (keys.x.empty())
		ke = true;
	else
		be = false;
	if (doors.x.empty())
		de = true;
	else
		be = false;

	whereat.clear();
	whereat.resize(blocks.x.size() / 2);
}

void Colision::SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	blocks.y.clear();
	spikes.y.clear();
	keys.y.clear();
	doors.y.clear();

	blocks.y = bpos;
	spikes.y = spos;
	keys.y = kpos;
	doors.y = dpos;
}

