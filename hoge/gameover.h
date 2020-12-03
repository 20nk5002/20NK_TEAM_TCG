#pragma once

class Gameover
{
private:
	int gameover_texture_;
	int transparent_;
public:
	bool init();
	void update();
	void draw();
	void destroy();

};