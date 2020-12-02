#pragma once
class Player_Osu
{
private:
    int textur;
    int x_, y_, f_, x1_, y1_;



public:
    Player_Osu();
    ~Player_Osu();
    bool init();
    void update();
    void draw();
    void destroy();

};