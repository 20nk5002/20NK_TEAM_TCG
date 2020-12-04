#pragma once

class Clear
{
private:
	int clear_texture_;
	int transparent_;
	int sound_;//ミュージックハンドル
public:
	Clear();
	bool init();
	void update( int osu_Mesu_Hit_ );
	void draw();
	void destroy();
};