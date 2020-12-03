#include"kannatuban.h"

Kannatu::Kannatu() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
}
Kannatu::~Kannatu() {

}

bool Kannatu::init() {
    return true;
}

bool Kannatu::update( int player_is_where_ ) {
    return is_pressed_;

}
void Kannatu::draw() {

}
void Kannatu::destroy() {

}