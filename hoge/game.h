#pragma once

// Include
#include"DxLib.h"
#include"map.h"
#include"hasigo.h"
#include"kannatuban.h"
#include"hako.h"
#include"player_mesu.h"
#include"player_osu.h"
#include"keys.h"

//�@�Q�[���N���X
class Game
{
private:
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Map map;
    Keyboard keboard;
   
public:
    Game();
    ~Game();
    bool init();
    void update();
    void draw();
    void destroy();
};