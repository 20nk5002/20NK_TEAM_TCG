#include"DxLib.h"
#include"title.h"


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
    //�X�y�[�X�L�[�������ꂽ��^�C�g���I��
    if( CheckHitKey( KEY_INPUT_RETURN ) ) {
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