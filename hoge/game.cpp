#include"DxLib.h"
#include"game.h"


bool Game::init() 
{
    if( map.init() == false )return false;
    if( player_Mesu.init() == false ) {
        return false;
    }
    if( player_Osu.init() == false ) {
        return false;
    }
    return true;

}
bool Game::update()
{
    map.update();
    player_Mesu.update();
    player_Osu.update();
    return true;
}
void Game::draw()
{
    map.draw();
    player_Mesu.draw();
    player_Osu.draw();
}
void Game::destroy()
{
    map.destroy();
    player_Mesu.destroy();
    player_Osu.destroy();
}