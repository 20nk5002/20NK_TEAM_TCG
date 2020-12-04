#include"DxLib.h"
#include"kannatuban_aka.h"

Kannatu_Aka::Kannatu_Aka() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
    is_where_ = 0;
}
Kannatu_Aka::~Kannatu_Aka() {

}

bool Kannatu_Aka::init( int map_Number_ ) {
    return true;
}

bool Kannatu_Aka::update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ ) {

    if( osu_is_where_ == is_where_||mesu_is_where_==is_where_||hako_is_where_==is_where_ ) {
        is_pressed_ = true;
    }
    else {
        is_pressed_ = false;
    }


    return is_pressed_;

}
void Kannatu_Aka::draw() {

}
void Kannatu_Aka::destroy() {

}