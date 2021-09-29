#include "Telas.h"

Telas& Telas::GetInstance(){
	static Telas instance;
	return instance;
}

Telas::Telas(void){}
Telas::~Telas(void){}

void Telas::Initialize() {
	level = 0;
}

void Telas::LoadContent(){
	lvl.LoadContent();
	ps.LoadContent();
}

void Telas::UnloadContent(){
	lvl.UnloadContent();
	ps.UnloadContent();
}

void Telas::Update(ALLEGRO_EVENT event){
	if (level == 0 && input.IsKeyPressed(event, ALLEGRO_KEY_ENTER)) {
		LevelUp();
	}
	if (isFinished) {
		if (level == 5) {
			ps.Initialize(400.0, DefHeight(4));
		}
		else {
			ps.Initialize();
		}
		ResetHasKey();
		SetItemsPos();
		lvl.SetLevel(level);
		lvl.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
		lvl.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
		lvl.SetItemsCommon(spikes.common);
		ps.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
		ps.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
		isFinished = false;
	}
	lvl.SetHasKey(ps.GetKeyStatus());
	if (level == 4 && ps.GetKeyStatus()) {
		blocks.x[6] = 208.0;
		blocks.x[7] = 96.0;
		blocks.y[6] = DefHeight(6);
		lvl.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
		lvl.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
		ps.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
		ps.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
	}
	lvl.Update(event);
	if (level > 0 && level < 6) {
			ps.Update(event);
		if (ps.GetIsFinished()) {
			LevelUp();
		}
	}
	if (!ps.GetLifeStatus()) {
		lvl.SetHasKey(false);
		if (level == 5) {
			ps.Initialize(400.0, DefHeight(4));
		}
		else {
			ps.Initialize();
		}
		if (level == 4) {
			blocks.x[6] = 240.0;
			blocks.x[7] = 32.0;
			blocks.y[6] = DefHeight(5);
			lvl.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
			lvl.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
			ps.SetItemsPosx(blocks.x, spikes.x, keys.x, doors.x);
			ps.SetItemsPosy(blocks.y, spikes.y, keys.y, doors.y);
		}
		if (ps.GetKeyStatus())
			printf("tem");
	}
}

void Telas::Draw(ALLEGRO_DISPLAY* display){
	lvl.Draw(display);
	if (level > 0) {
		ps.Draw(display);
	}
}

void Telas::SetItemsPos() {
	if (level == 1) {
		blocks.x = { 320.0, 32.0, 480.0, 64.0, 608.0, 160.0};
		blocks.y = { 368.0, 128.0, 208.0, 32.0, 80.0, 32.0 };
		spikes.x = { 608.0, 32.0};
		spikes.y = {DefHeight(12), 32.0};
		spikes.common = { false };
		keys.x = {744, 8};
		keys.y = {DefHeight(14), 18};
		doors.x = {width - 64 - 16, 32};
		doors.y = {DefHeight(2), 64};
	}
	else if (level == 2) {
		blocks.x = { 48.0, 32.0, 48.0, 32, 48.0, 32.0, 496.0, 32.0, 496.0, 32, 624.0, 32.0, 624.0, 32.0 };
		blocks.y = { DefHeight(3), 32.0, DefHeight(8), 32.0, DefHeight(13), 32.0, DefHeight(3), 32.0, DefHeight(8), 32.0, DefHeight(5), 160.0, DefHeight(10), 160.0 };
		spikes.x = { 592.0, 32.0, 592.0, 32.0 };
		spikes.y = { DefHeight(5), 160.0, DefHeight(10), 160.0 };
		spikes.common = { false, false };
		keys.x = { 56.0, 8.0 };
		keys.y = { DefHeight(14), 18 };
		doors.x = { width - 64 - 16, 32 };
		doors.y = { DefHeight(2), 64 };
	}
	else if (level == 3) {
		blocks.x = { 208.0, 96.0, 304.0, 128.0, 400.0, 32.0, 272.0, 160.0, 176.0, 64.0,  16.0, 32.0
		, 432.0, 32.0, 560.0, 32.0, 176.0, 32.0, 592.0, 32.0 };
		blocks.y = { DefHeight(3), 32, DefHeight(4), 32.0, DefHeight(9), 160.0, DefHeight(10), 32.0, DefHeight(6), 32.0, DefHeight(10), 32.0 
		, DefHeight(6), 32.0, DefHeight(9), 160.0, DefHeight(2), 64.0, DefHeight(4), 128.0 };
		spikes.x = { 464.0, 64.0 };
		spikes.y = { DefHeight(1), 32.0 };
		spikes.common = { true };
		keys.x = { 208.0 + 8.0, 8.0 };
		keys.y = { DefHeight(1), 18 };
		doors.x = { width - 64 - 16, 32 };
		doors.y = { DefHeight(2), 64 };
	}
	else if (level == 4) {
		blocks.x = { 16.0, 160.0, 176.0, 32.0, 16.0, 32.0, 240.0, 32.0, 304.0, 32.0, 336.0, 160.0, 336.0, 32.0
		, 432.0, 32.0, 528.0, 32.0, 624.0, 32.0, 720.0, 32.0, 720.0, 32.0, 496.0, 160.0, 656.0, 96.0 };
		blocks.y = { DefHeight(6), 32.0, DefHeight(11), 160.0, DefHeight(11), 32.0, DefHeight(5), 32.0, DefHeight(11), 160.0, DefHeight(6), 32.0, DefHeight(12), 32.0
		, DefHeight(12), 32.0, DefHeight(12), 32.0, DefHeight(12), 32.0, DefHeight(12), 32.0, DefHeight(11), 160.0, DefHeight(6), 32.0, DefHeight(6), 32.0 };
		spikes.x = { 16.0, 160.0, 336.0, 160.0, 496.0, 160.0, 656.0, 64.0, 784.0, 32.0 };
		spikes.y = { DefHeight(7), 32.0, DefHeight(7), 32.0, DefHeight(7), 32.0, DefHeight(7), 32.0, DefHeight(1), 32.0 };
		spikes.common = { true, true, true, true, true };
		keys.x = { 56.0, 8.0 };
		keys.y = { DefHeight(14), 18 };
		doors.x = { 80.0, 32.0 };
		doors.y = { DefHeight(2), 64 };
	}
	else if (level == 5) {
		blocks.x = { 368.0, 96.0, 208.0, 32.0, 48.0, 32.0, 592.0, 32.0, 752.0, 32.0 };
		blocks.y = { DefHeight(3), 32.0, DefHeight(6), 32.0, DefHeight(10), 32.0, DefHeight(6), 32.0, DefHeight(10), 32.0 };
		spikes.x = { 16.0, 160.0, 176.0, 160.0, 336.0, 160.0, 496.0, 160.0, 656.0, 160.0 };
		spikes.y = { DefHeight(1), 32.0, DefHeight(1), 32.0, DefHeight(1), 32.0, DefHeight(1), 32.0, DefHeight(1), 32.0 };
		spikes.common = { true, true, true, true, true };
		keys.x = { 208.0+8.0, 8.0 };
		keys.y = { DefHeight(14), 18 };
		doors.x = { 752.0, 32.0 };
		doors.y = { DefHeight(12), 32.0 };
	}
	else if (level == 6) {
		blocks.x.clear();
		blocks.y.clear();
		spikes.x.clear();
		spikes.y.clear();
		spikes.common.clear();
		keys.x.clear();
		keys.y.clear();
		doors.x.clear();
		doors.y.clear();
	}
}

float Telas::DefHeight(int value) {
	return height - 16 - value*32;
}

void Telas::LevelUp() {
	level++;
	isFinished = true;
}

void Telas::ResetHasKey() {
	lvl.SetHasKey(false);
	ps.ResetHasKey();
}
