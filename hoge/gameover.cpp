// Include
#include"DxLib.h"
#include"gameover.h"

bool Gameover::init()
{
    transparent_ = 255;
    //テクスチャの読み込み
    if( (gameover_texture_ = LoadGraph( "gameover.png" )) == -1 ) {
        return false;
    }
    return true;
}
void Gameover::update()
{
  /*  if(　引数 == 1 ) {
        transparent_ = 255;
    }
    else {
        transparent_ = 0;
    }*/
}
void Gameover::draw()
{
    // ブレンドモードを変更
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, transparent_ );
    DrawGraph( 0, 0, gameover_texture_, 1 );
    // ブレンドモードを戻す
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}
void Gameover::destroy()
{
    if( gameover_texture_ != 0 ) {
        DeleteGraph( gameover_texture_ );
        gameover_texture_ = 0;

    }
}