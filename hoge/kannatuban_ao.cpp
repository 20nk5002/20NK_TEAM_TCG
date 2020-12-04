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
        is_pressed_ = true;
    }
    else {
        is_pressed_ = false;
    }
}
void Kannatu_Ao::draw() {

}
void Kannatu_Ao::destroy() {

}