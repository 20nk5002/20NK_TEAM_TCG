#pragma once
class Player_Mesu
{
private:
    int textur;
    int x_, y_, f_, x1_, y1_;



public:
    Player_Mesu();
    ~Player_Mesu();
    bool init();
    void update();
    void draw();
    void destroy();

};