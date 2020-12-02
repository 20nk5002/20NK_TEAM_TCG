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
    //テクスチャの読み込み
    if( (texrure_ = LoadGraph( "title.png" )) == -1 ) {
        return false;
    }

    return true;
}
bool Title::update()
{
    //コントローラーの入力の取得
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );

    const char* keys = Keyboard::getPressed();
    //Enterが押されたらタイトル終了
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