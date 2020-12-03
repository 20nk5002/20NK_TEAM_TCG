#include"DxLib.h"
#include"game.h"
#include"keys.h"



bool Game::init( int map_Number_ )
{
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ ) == false )return false;
    if( player_Osu.init( map_Number_ ) == false )return false;
    if( clear.init() == false )return false;
    for( int i = 0; i < 5; i++ ) {
        if( hako[ i ].init( i, map_Number_ ) == false )return false;
    }
    return true;

}
int osumesuhit = 0;
int handole = 0;
int mesu_Position;
int osu_Position;

bool Game::update()
{
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    const char* keys = Keyboard::getPressed();
    if( xinput.Buttons[ XINPUT_BUTTON_DPAD_DOWN ] == 1 || keys[KEY_INPUT_DOWN] )
    {
        if( handole == 0 )
        {
            handole = 1;
        }
        else
            handole = 0;
    }
    map.update();
    if(handole==0 ) {
         osu_Position = player_Osu.update();
    }
    else {
         mesu_Position = player_Mesu.update();
    }
    clear.update( osumesuhit );
    if(mesu_Position == osu_Position)
    {
       return false;
    }
    
    return true;
}
void Game::draw()
{
    map.draw();
    player_Mesu.draw();
    player_Osu.draw();
    for( int i = 0; i < 5; i++ ) {
        hako[ i ].draw();
    }
    clear.draw();
}
void Game::destroy()
{
    map.destroy();
    player_Mesu.destroy();
    player_Osu.destroy();
    for( int i = 0; i < 5; i++ ) {
        hako[ i ].destroy();
    }
    clear.destroy();
}