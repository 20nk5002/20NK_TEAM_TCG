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
    //�R���g���[���[�̓��͂̎擾
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
     const char* keys = Keyboard::getPressed();

     //�E�ړ��@�t���O�@1
    if( keys[ KEY_INPUT_RIGHT ] == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_RIGHT ] && f_ == 0 )
    {
        if( f_ & 1 ) {

        }
        else {
            f_ += 1;
        }
    }
    //���ړ��@�t���O�@2
    else  if( CheckHitKey( KEY_INPUT_LEFT ) == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_LEFT ] && f_ == 0 ) {

        if( f_ & 2 ) {

        }
    
        else {
            f_ += 2;
        }
    }

    //��ړ��@�t���O4
    else  if( CheckHitKey( KEY_INPUT_UP ) == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_UP ] && f_ == 0 ) {

        if( f_ & 8 ) {

        }
        else {
            f_ += 8;
        }
    }

    //�E�ړ�
    if( f_ & 1 ) {
        if( x1_ + 64 != x_ ) {
            x_ += 4;
        }
        else {
            f_ -= 1;
            x1_ = x_;
        }
    }
    //���ړ�
    if( f_ & 2 ) {

        if( x1_ - 64 != x_ ) {
            x_ -= 4;
        }
        else {
            f_ -= 2;
            x1_ = x_;
        }

    }
    if( f_ & 4 ) {
      
        if( y1_ - 64 != y_ ) {
            y_ -= 4;
        }
        else {
            f_ -= 8;
            y1_ = y_;
        }
    }


}
void  Player_Mesu::draw()
{
    DrawRectGraph( x_, y_, 12 * 64, 0, 64, 64, textur, 0 );
    }
void  Player_Mesu::destroy()
{
    //�O���t�B�b�N�n���h���̊J��
    if( textur != 0 ) {
        DeleteGraph( textur );
        textur = 0;

    }
}
