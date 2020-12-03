#include"DxLib.h"
#include"game.h"


bool Game::init( int map_Number_ )
{
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ ) == false )return false;
    if( player_Osu.init( map_Number_ ) == false )return false;
    if( clear.init() == false )return false;
    return true;

}
int osumesuhit = 1;
bool Game::update()
{
    map.update();
    player_Mesu.update();
    player_Osu.update();
    clear.update( osumesuhit );
    /* ì‚è•û‚ÌŠî”Õ—á
    mesu_Position = uplayer_Mesu.update();
    osu_Position = player_Osu.update();
    if(mesu_Position == osu_Position)
    {
       return false;
    }
    */
    return true;
}
void Game::draw()
{
    map.draw();
    player_Mesu.draw();
    player_Osu.draw();
    clear.draw();
}
void Game::destroy()
{
    map.destroy();
    player_Mesu.destroy();
    player_Osu.destroy();
    clear.destroy();
}