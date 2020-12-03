#include"DxLib.h"
#include"allstageclear.h"

bool Allclear::init()
{
    transparent_ = 255;
    //テクスチャの読み込み
    if( (allclear_texture_ = LoadGraph( "allstageclear.png" )) == -1 ) {
        return false;
    }
    return true;
}
void Allclear::update()
{
    /*  if(　引数 == 1 ) {
          transparent_ = 255;
      }
      else {
          transparent_ = 0;
      }*/
}
void Allclear::draw()
{
    // ブレンドモードを変更
    SetDrawBlendMode( DX_BLENDMODE_ALPHA, transparent_ );
    DrawGraph( 0, 0, allclear_texture_, 1 );
    // ブレンドモードを戻す
    SetDrawBlendMode( DX_BLENDMODE_NOBLEND, 0 );
}
void Allclear::destroy()
{
    if( allclear_texture_ != 0 ) {
        DeleteGraph( allclear_texture_ );
        allclear_texture_ = 0;

    }
}