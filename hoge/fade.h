#pragma once

// �N���X
class Fade
{
private:
    int fade_, fadeout_;
public:
    void init();
    int update();
    void draw();
};