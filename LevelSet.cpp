#include "LevelSet.h"

LevelSet::LevelSet(void){}
LevelSet::~LevelSet(void){}

void LevelSet::LoadContent() {
	ts.LoadContents();
	lvld.LoadContent();
}

void LevelSet::UnloadContent() {
	ts.UnloadContents();
	lvld.UnloadContent();
}

void LevelSet::Update(ALLEGRO_EVENT event) {
	if (level == 0) {
		ts.UpdateTimer(event);
	}
	else if (level >= 1) {
		lvld.Update(event);
	}
}

void LevelSet::Draw(ALLEGRO_DISPLAY* display) {
	if (level == 0) {
		ts.GameTitle(display);
		ts.GameTitleChar(display);
	}
	else if (level >= 1 && level<6){
		lvld.FrameDrawer(display);
		if (!blocks.x.empty() || !blocks.y.empty()) {
			for (int i = 0; i < blocks.x.size() / 2; i++) {
				lvld.BlocksDrawer(blocks.x[2 * i], blocks.x[2 * i + 1], blocks.y[2 * i], blocks.y[2 * i + 1], display);
			}
		}
		if (!spikes.x.empty() || !spikes.y.empty() || !spikes.common.empty()) {
			for (int i = 0; i < spikes.x.size() / 2; i++) {
				lvld.SpikesDrawer(spikes.x[2 * i], spikes.x[2 * i + 1], spikes.y[2 * i], spikes.y[2 * i + 1], spikes.common[i], display);
			}
		}
		if ((!keys.x.empty() || !keys.y.empty()) && !haskey) {
			for (int i = 0; i < keys.x.size() / 2; i++) {
				lvld.KeysDrawer(keys.x[2 * i], keys.y[2 * i], display);
			}
		}
		if(!doors.x.empty() || !doors.y.empty())
			lvld.DoorDrawer(doors.x[0], doors.y[0], display);
	}
	else {
		if (level == 6) {
			lvld.SetFinishScreen(display);
		}
	}
}

void LevelSet::SetLevelTitle() {
	level = 0;
}

void LevelSet::SetIsFinished() {
	isFinished = false;
}

void LevelSet::SetLevel(int i) {
	level = i;
}

bool LevelSet::GetIsFinished() {
	return isFinished;
}

void LevelSet::SetHasKey(bool value) {
	haskey = value;
}

void LevelSet::SetItemsPosx(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	blocks.x.clear();
	spikes.x.clear();
	keys.x.clear();
	doors.x.clear();

	blocks.x = bpos;
	spikes.x = spos;
	keys.x = kpos;
	doors.x = dpos;
}

void LevelSet::SetItemsPosy(std::vector<float> bpos, std::vector<float> spos, std::vector<float> kpos, std::vector<float> dpos) {
	blocks.y.clear();
	spikes.y.clear();
	keys.y.clear();
	doors.y.clear();

	blocks.y = bpos;
	spikes.y = spos;
	keys.y = kpos;
	doors.y = dpos;
}

void LevelSet::SetItemsCommon(std::vector<bool> spos) {
	spikes.common.clear();
	spikes.common = spos;
}
