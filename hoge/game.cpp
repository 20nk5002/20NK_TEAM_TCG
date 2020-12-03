#include"DxLib.h"
#include"game.h"
#include"keys.h"



bool Game::init( int map_Number_ )
{
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ ) == false )return false;
    if( player_Osu.init( map_Number_ ) == false )return false;
    if( clear.init() == false )return false;
    for( int i = 0; i < 6; i++ ) {
        if( hako[ i ].init( i, map_Number_ ) == false )return false;
    }
    return true;

}
int osumesuhit = 1;
int handole = 0;
bool Game::update()
{
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    const char* keys = Keyboard::getPressed();
    if( xinput.Buttons[ XINPUT_BUTTON_DPAD_DOWN ] == 1 || CheckHitKey( KEY_INPUT_DOWN ) == 1 )
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
        player_Osu.update();
    }
    else {
        player_Mesu.update();
    }
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
    for( int i = 0; i < 6; i++ ) {
        hako[ i ].draw();
    }
    clear.draw();
}
void Game::destroy()
{
    map.destroy();
    player_Mesu.destroy();
    player_Osu.destroy();
    clear.destroy();
}