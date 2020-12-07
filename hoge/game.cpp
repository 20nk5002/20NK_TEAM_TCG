#include"DxLib.h"
#include"game.h"
#include"keys.h"



bool Game::init( int map_Number_ )
{
    game_over_ = 0;
    if( map.init( map_Number_ ) == false )return false;
    if( player_Mesu.init( map_Number_ , &map) == false )return false;
    if( player_Osu.init( map_Number_,&map ) == false )return false;
    if( kannatuban_Aka.init( map_Number_ ) == false )return false;
    if( kannatuban_Ao.init( map_Number_ ) == false )return false;
   // if( clear.init() == false )return false;
    for( int i = 0; i < 5; i++ ) {
        if( hako[ i ].init( i, map_Number_, &map ) == false )return false;
        else  hako_is_where_[ i ]= hako[ i ].init( i, map_Number_ ,&map);
    }
   // •K‚¸Å‰‚Ì‘€ì‚ªƒIƒX‚É‚È‚é‚æ‚¤‚É‚·‚é‚½‚ß   
    handle_ = 0;
    
    clear.update(0);

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

    for( int i = 0; i < 6; i++ ) {
        if( kannatuban_Aka.update( osu_Position, mesu_Position, hako_is_where_[ i ] ) == true ) {
            kannatu_pressed_red = true;
            break;
        }
        kannatu_pressed_red = false;
    }
    for( int i = 0; i < 6; i++ ) {
        if( kannatuban_Ao.update( osu_Position, mesu_Position, hako_is_where_[ i ] ) == true ) {
            kannatu_pressed_blue = true;
            break;
        }
        kannatu_pressed_blue = false;
    }
  
    osu_Position = player_Osu.update( !handle_, hako_is_where_, kannatu_pressed_red, kannatu_pressed_blue );
    mesu_Position = player_Mesu.update( handle_, hako_is_where_, kannatu_pressed_red, kannatu_pressed_blue );
    for( int i = 0; i < 5; i++ ) {
        for( int j = 0; j < 5; j++ ) {

            hako_is_where_[ i ] = hako[ i ].update( osu_Position, mesu_Position, handle_, xinput.Buttons[ XINPUT_BUTTON_A ] == 1 || keys[ KEY_INPUT_SPACE ], kannatu_pressed_red, kannatu_pressed_blue );
        }
    }
    

 
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
    if (game_over_ == 0) {
        map.draw( kannatu_pressed_red, kannatu_pressed_blue );
        for (int i = 0; i < 5; i++) {
            hako[i].draw();

        }
        player_Mesu.draw();
        player_Osu.draw();
        if (mesu_Position == osu_Position)
        {
            clear.draw();
        }
    }
    else
        gameover.draw();
}
void Game::destroy()
{
    for( int i = 0; i < 5; i++ ) {
        hako_is_where_[ i ];
    }
    map.destroy();
    player_Mesu.destroy();
    player_Osu.destroy();
    for( int i = 0; i < 5; i++ ) {
        hako[ i ].destroy();
    }
    clear.destroy();
}