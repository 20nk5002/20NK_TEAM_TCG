#include"DxLib.h"
#include"game.h"


bool Game::init() 
{
    if( map.init() == false )return false;
    if( player_Mesu.init() == false ) {
        return false;
    }
    return true;

}
void Game::update()
{
    map.update();
    player_Mesu.update();
}
void Game::draw()
{
    map.draw();
    player_Mesu.draw();
}
void Game::destroy()
{
    map.destroy();
}