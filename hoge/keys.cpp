#include"DxLib.h"
#include"keys.h"

char Keyboard::held_[ 256 ];
char Keyboard::pressed_[ 256 ];
char Keyboard::released_[ 256 ];
bool Keyboard::save_key_[ 256 ];

void Keyboard::update() {
    GetHitKeyStateAll( held_ );

    for( int i = 0; i < 256; ++i ) {
        pressed_[ i ] = 0;
        released_[ i ] = 0;
        if( held_[ i ] ) {
            if( !save_key_[ i ] ) {
                pressed_[ i ] = 1;
                save_key_[ i ] = 1;
            }
        }
        else {
            if( save_key_[ i ] ) {
                released_[ i ] = 1;
            }
            save_key_[ i ] = 0;
        }
    }
}