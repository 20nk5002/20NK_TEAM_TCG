#pragma once

// Include
#include"DxLib.h"
#include"map.h"
#include"player_mesu.h"
#include"player_osu.h"
#include"keys.h"

//　ゲームクラス
class Game
{
private:
    Player_Mesu player_Mesu;
    Player_Osu player_Osu;
    Map map;
    Keyboard keboard;
   
public:
    bool init();
    void update();
    void draw();
    void destroy();
};