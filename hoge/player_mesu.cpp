#include"DxLib.h"
#include"player_mesu.h"
#include"keys.h"



Player_Mesu::Player_Mesu() 
{
    init();
}

Player_Mesu::~Player_Mesu() 
{
    destroy();
}
bool Player_Mesu ::init()
{
    textur = 0;
    x_ = x1_ = 0;
    y_ = y1_ = 0;
    f_ = 0;
   
    if( (textur = LoadGraph( "karichip.png" )) == -1 ) {
       
        return false;
    }
    return true;
    }
void  Player_Mesu::update()
{
    //コントローラーの入力の取得
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    // const char* keys[] = Keyboard::getPressed();

    //if( Keys[ KEY_INPUT_RIGHT ] == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_RIGHT ] )
    //{

    //}
}
void  Player_Mesu::draw()
{

    }
void  Player_Mesu::destroy()
{

    }
