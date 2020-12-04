#include"DxLib.h"
#include"kannatuban_aka.h"

Kannatu_Aka::Kannatu_Aka() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
}
Kannatu_Aka::~Kannatu_Aka() {

}

bool Kannatu_Aka::init( int map_Number_ ) {
    return true;
}

bool Kannatu_Aka::update( int player_is_where_ ) {
    return is_pressed_;

}
void Kannatu_Aka::draw() {

}
void Kannatu_Aka::destroy() {

}