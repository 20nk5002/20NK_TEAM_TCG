#include"DxLib.h"
#include"fade.h"

// 初期化
void Fade::init()
{
    fade_ = 0;
    fadeout_ = 0;
}
// 更新
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
// 描画
void Fade::draw()
{
    // ブレンドモードを変更
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, fadeout_ );

    DrawBox( 0, 0, 1280, 720, 0x000000, 1 );

    // ブレンドモードを戻す
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );

}