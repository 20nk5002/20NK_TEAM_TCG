#pragma once

// �N���X
class Allclear
{
private:
	int allclear_texture_;
	int transparent_;
public:
	bool init();
	void update();
	void draw();
	void destroy();
};