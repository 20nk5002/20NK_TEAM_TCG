#include"DxLib.h"
#include"kannatuban_ao.h"




Kannatu_Ao::Kannatu_Ao() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
}
Kannatu_Ao::~Kannatu_Ao() {

}

bool Kannatu_Ao::init( int map_Number_ ) {
    return true;
}

bool Kannatu_Ao::update( int player_is_where_ ) {
    return is_pressed_;

}
void Kannatu_Ao::draw() {

}
void Kannatu_Ao::destroy() {

}