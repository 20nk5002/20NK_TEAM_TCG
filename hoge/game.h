#pragma once

// Include
#include"DxLib.h"
#include"map.h"
#include"player_mesu.h"
#include"player_osu.h"
#include"keys.h"
#include"clear.h"

//　ゲームクラス
class Game
{
private:
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Map map;
    Keyboard keboard;
    Clear clear;
   
public:
    bool init(int map_Number_);
    bool update();
    void draw();
    void destroy();
};