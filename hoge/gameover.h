#pragma once

class Gameover
{
private:
	int gameover_texture_;
	int transparent_;
	int sound_;//�~���[�W�b�N�n���h��
public:
	bool init();
	void update();
	void draw();
	void destroy();

};