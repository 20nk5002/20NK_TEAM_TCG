#include"DxLib.h"
#include"fade.h"

// ������
void Fade::init()
{
    fade_ = 0;
    fadeout_ = 0;
}
// �X�V
int Fade::update()
{
    if( fade_ == 0 )
    {
        fadeout_ += 10;
        if( fadeout_ > 255 ) {
            fadeout_ = 255;
            fade_ = 1;
        }
    }
    else
    {
        fadeout_ -= 7;
        if( fadeout_ < 0 ) {
            fadeout_ = 0;
            fade_ = 0;
        }
    }
    return fadeout_;
}
// �`��
void Fade::draw()
{
    // �u�����h���[�h��ύX
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, fadeout_ );

    DrawBox( 0, 0, 1280, 720, 0x000000, 1 );

    // �u�����h���[�h��߂�
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );

}