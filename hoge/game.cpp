#include"DxLib.h"
#include"game.h"


bool Game::init( int map_Number_ )
{
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ ) == false ) {
        return false;
    }
    if( player_Osu.init( map_Number_ ) == false ) {
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