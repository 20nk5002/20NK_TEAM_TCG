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
#include"kannatuban_aka.h"
#include"kannatuban_ao.h"

//　ゲームクラス
class Game
{
private:
    int hako_is_where_[6];
    int sin_hako_is_where_[ 6 ];
    int game_over_;
    bool handle_;
    bool kannatu_pressed_red = 0;
    bool kannatu_pressed_blue = 0;
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Hako hako[ 6 ];
    Map map;
    Keyboard keboard;
    Clear clear;
    Gameover gameover;
    Kannatu_Aka kannatuban_Aka;
    Kannatu_Ao kannatuban_Ao;

   
public:
    bool init(int map_Number_);
    int update();
    void draw();
    void destroy();
};