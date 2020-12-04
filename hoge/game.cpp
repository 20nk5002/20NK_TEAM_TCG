#include"DxLib.h"
#include"game.h"
#include"keys.h"



bool Game::init( int map_Number_ )
{
    game_over_ = 0;
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ ) == false )return false;
    if( player_Osu.init( map_Number_ ) == false )return false;
   // if( clear.init() == false )return false;
    for( int i = 0; i < 5; i++ ) {
        if( hako[ i ].init( i, map_Number_ ) == false )return false;
        else  hako_is_where_[ i ]= hako[ i ].init( i, map_Number_ );
    }
   // if( gameover.init() == false )return false;
    handle_ = 0;

    return true;

}

int mesu_Position;
int osu_Position;

int Game::update()
{
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    const char* keys = Keyboard::getPressed();
    if( xinput.Buttons[ XINPUT_BUTTON_DPAD_DOWN ] == 1 || keys[KEY_INPUT_DOWN] )
    {
        if( handle_ )
        {
            handle_ = false;
        }
        else
            handle_ = true;
    }
   
    osu_Position = player_Osu.update( !handle_, hako_is_where_ );
    mesu_Position = player_Mesu.update( handle_,hako_is_where_ );
    for( int i = 0; i < 5; i++ ) {
        hako[ i ].update( osu_Position, mesu_Position, handle_, xinput.Buttons[ XINPUT_BUTTON_A ] == 1 || keys[ KEY_INPUT_SPACE ] );
    }
    clear.update( 0 );
    if(mesu_Position == osu_Position)
    {
        map.update();
        if( clear.init() == false )return false;
        clear.update( 1 );
       return 1;
    }
    if( mesu_Position == -1 || osu_Position == -1 )
    {
       
        map.update();
        destroy();
        game_over_ = 1;
        return 2;
    }
    
    return 0;
}
void Game::draw()
{
    if( game_over_ == 0 ) {
        map.draw();
        for( int i = 0; i < 5; i++ ) {
            hako[ i ].draw();
        }
        player_Mesu.draw();
        player_Osu.draw();
        clear.draw();
    }
    else
        gameover.draw();
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