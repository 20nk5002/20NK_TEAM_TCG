#include"DxLib.h"
#include"game.h"


bool Game::init() 
{
    if( map.init() == false )return false;
    return true;

}
void Game::update()
{
    map.update();
}
void Game::draw()
{
    map.draw();
}
void Game::destroy()
{
    map.destroy();
}