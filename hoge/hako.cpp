#include"DxLib.h"
#include"hako.h"

Hako::Hako() {
    texture = 0;
    box_x = box_y = 0;
}
Hako::~Hako() {

}

bool Hako::init() {
    if( texture = LoadGraph( "karichip.png" ) == -1 ) {
        return false;
    }
    return true;
}
void Hako::update() {

}
void Hako::draw() {
    DrawRectGraph( box_x * 64, box_y * 64, 128, 0, 64, 64, texture, 0, 0, 0 );
}
void Hako::destroy() {

}