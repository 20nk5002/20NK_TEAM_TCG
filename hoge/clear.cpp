// Include
#include"DxLib.h"
#include"clear.h"

Clear::Clear()
{
    transparent_ = 0;
}

bool Clear::init()
{
    transparent_ = 0;
    //�e�N�X�`���̓ǂݍ���
    if( (clear_texture_ = LoadGraph( "stageclear.png" )) == -1 ) {
        return false;
    }
    if( (sound_ = LoadSoundMem( "clear.wav" )) == -1 ) {
        return false;
    }
    PlaySoundMem( sound_, DX_PLAYTYPE_BACK );
    return true;
}
void Clear::update( int osu_Mesu_Hit_ )
{
    transparent_ = osu_Mesu_Hit_;
   
    if( transparent_ == 1 ) {
        transparent_ = 255;
    }
    else {
        transparent_ = 0;
    }
}
void Clear::draw()
{
    // �u�����h���[�h��ύX
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, transparent_ );
    DrawGraph( 0, 0, clear_texture_, 1 );
    // �u�����h���[�h��߂�
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}
void Clear::destroy()
{
    if( clear_texture_ != 0 ) {
        DeleteGraph( clear_texture_ );
        clear_texture_ = 0;

    }
    if( sound_ != 0 ) {
        DeleteSoundMem( sound_ );
    }
}