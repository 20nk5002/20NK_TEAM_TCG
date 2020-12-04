// Include
#include"DxLib.h"
#include"gameover.h"

bool Gameover::init()
{
    transparent_ = 255;
    //�e�N�X�`���̓ǂݍ���
    if( (gameover_texture_ = LoadGraph( "gameover.png" )) == -1 ) {
        return false;
    }
    if( (sound_ = LoadSoundMem( "gameover.wav" ) == -1) ) {
        return false;
    }
    return true;
}
void Gameover::update()
{

    PlaySoundMem( sound_, DX_PLAYTYPE_LOOP );
  /*  if(�@���� == 1 ) {
        transparent_ = 255;
    }
    else {
        transparent_ = 0;
    }*/
}
void Gameover::draw()
{
    // �u�����h���[�h��ύX
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, transparent_ );
    DrawGraph( 0, 0, gameover_texture_, 1 );
    // �u�����h���[�h��߂�
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}
void Gameover::destroy()
{
    if( gameover_texture_ != 0 ) {
        DeleteGraph( gameover_texture_ );
        gameover_texture_ = 0;

    }
    if(sound_ != 0) {
        DeleteSoundMem( sound_ );
    }

}