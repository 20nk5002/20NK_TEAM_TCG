#pragma once

// Include
#include"DxLib.h"
#include"map.h"
#include"player_mesu.h"
#include"player_osu.h"
#include"hako.h"
#include"keys.h"
#include"clear.h"
#include"gameover.h"

//　ゲームクラス
class Game
{
private:
    int hako_is_where_[6];
    int sin_hako_is_where_[ 6 ];
    int game_over_;
    bool handle_;
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Hako hako[ 6 ];
    Map map;
    Keyboard keboard;
    Clear clear;
    Gameover gameover;
   
public:
    bool init(int map_Number_);
    int update();
    void draw();
    void destroy();
};