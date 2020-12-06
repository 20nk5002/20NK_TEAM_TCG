#include"DxLib.h"
#include"kannatuban_ao.h"




Kannatu_Ao::Kannatu_Ao() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
    is_where_ = 0;
}
Kannatu_Ao::~Kannatu_Ao() {

}

bool Kannatu_Ao::init( int map_Number_ ) {
    return true;
}

bool Kannatu_Ao::update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ ) {
    if( osu_is_where_ == is_where_ || mesu_is_where_ == is_where_ || hako_is_where_ == is_where_ ) {
       
        transparent_ = 255;
        is_pressed_ = true;
    }
    else {
        transparent_ = 0;
        is_pressed_ = false;
    }
    return is_pressed_;
}
void Kannatu_Ao::draw() {
    // ブレンドモードを変更
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparent_);

    DrawRectGraph(ao_x, ao_y, 3 * 64, 0, 64, 64, texture, 0, 0, 0);
    DrawRectGraph(ao_x, ao_y, 4 * 64, 0, 64, 64, texture, 0, 0, 0);

    // ブレンドモードを戻す
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawRectGraph(ao_x, ao_y, 2 * 64, 0, 64, 64, texture, 0, 0, 0);
}
void Kannatu_Ao::destroy() {

}