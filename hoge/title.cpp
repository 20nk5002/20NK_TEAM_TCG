#include"DxLib.h"
#include"title.h"
#include"keys.h"


Title::Title() {
    init();
}
Title::~Title() {
    desrroy();
}
bool Title::init()
{
    //�e�N�X�`���̓ǂݍ���
    if( (texrure_ = LoadGraph( "title.png" )) == -1 ) {
        return false;
    }

    return true;
}
bool Title::update()
{
    //�R���g���[���[�̓��͂̎擾
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );

    const char* keys = Keyboard::getPressed();
    //Enter�������ꂽ��^�C�g���I��
    if( keys[ KEY_INPUT_RETURN ]|| PAD_INPUT_A ) {
        return false;
    }
    return true;
}
void Title::draw()
{
    DrawGraph( 0, 0, texrure_, 0 );
}
void Title::desrroy()
{
    if( texrure_ != 0 ) {
        DeleteGraph( texrure_ );
        texrure_ = 0;

    }

}