#pragma once

// Include
#include"DxLib.h"
#include"map.h"
#include"player_mesu.h"
#include"player_osu.h"
#include"hako.h"
#include"keys.h"
#include"clear.h"

//�@�Q�[���N���X
class Game
{
private:
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Hako hako[ 6 ];
    Map map;
    Keyboard keboard;
    Clear clear;
   
public:
    bool init(int map_Number_);
    bool update();
    void draw();
    void destroy();
};