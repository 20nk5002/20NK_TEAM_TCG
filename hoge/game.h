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

//　ゲームクラス
class Game
{
private:
   
public:
    Game();
    ~Game();
    bool init();
    void update();
    void draw();
    void destroy();
};