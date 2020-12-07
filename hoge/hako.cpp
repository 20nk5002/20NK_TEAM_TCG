#include"DxLib.h"
#include"hako.h"

Chip_4::Chip_4() {
    x_ = y_ = trim_x_ = trim_y_ = id = 0;
}

Hako::Hako() {
    texture = -1;
    box_x = box_y = 0;
    is_where_ = -1;
    width_ = 20;
        height_ = 12;
    chips = NULL;
}
Hako::~Hako() {

}

bool Hako::init( const int n , int map_Number_, Map* map ) {
    FILE* fp = 0;
    int n2 = n;

    this->map = map;

    if( (texture = LoadGraph( "karichip.png" )) == -1 ) {
        return false;
    }

    // 全チップデータの格納
    for( int i = 0; i < width_ * height_; i++ )
    {
       // fread( map->chips[ i ].id, sizeof( char ), 1, fp );
        if( map->chips[ i ].id == 9 ) {
            if( n2 == 0 ) {
                is_where_ = i;
                n2 -= 1;
            }
            else {
                n2 -= 1;
            }
        }
    }
    box_x = is_where_ % 20 * 64;
    box_y = is_where_ / 20 * 64;
    box_x1 = box_x = is_where_ % 20 * 64;
    box_y1 = box_y = is_where_ / 20 * 64;

    // ファイルを閉じる
 
    f_ = 0;
    sin_is_where_ = is_where_;
    return true;
}

int Hako::update( int osu_is_where_, int mesu_is_where_, const bool handle, char space_or_A_held, bool red_pressed, bool blue_pressed ) {

        if( ((map->chips[ is_where_ + 20 ].id) == 0) || ((map->chips[ is_where_ + 20 ].id) == 3) || ((map->chips[ is_where_ + 20 ].id) == 6) || ((map->chips[ is_where_ + 20 ].id) == 4&& !red_pressed) || ((map->chips[ is_where_ + 20 ].id) == 5 && !red_pressed) || ((map->chips[ is_where_ + 20 ].id) == 7 && !blue_pressed) || ((map->chips[ is_where_ + 20 ].id) == 8 && !blue_pressed) ) {
            f_ = 16;

        
    }
        if( f_ & 16 ) {
            if( box_y1 + 64 != box_y ) {
                box_y += 4;
            }
            else {
                f_ -= 16;

                if( map->chips[ is_where_ ].id == 9 ) {
                    map->chips[ is_where_ ].id = 0;
                }

                box_y1 = box_y;
                is_where_ += 20;

                // if( map->chips[ sin_is_where_ +20].id )
                if( map->chips[ is_where_ + 20 ].id != 0 ) {
                    map->chips[ is_where_ ].id = 9;
                }

            }
        }
    //プレイヤーの位置
    int handling_character_is_where_ = (osu_is_where_ * (!handle)) + (mesu_is_where_ * handle);
    if( space_or_A_held == 1 ) {
        if( is_where_ - 1 != 1 ) {
            if( handling_character_is_where_ - 1 == is_where_ ) {

                box_x -= 64;
                is_where_ -= 1;
            }
        }
        if( is_where_ - 1 != 1 ) {
            if( handling_character_is_where_ + 1 == is_where_ ) {
                box_x += 64;
                is_where_ += 1;
            }
        }
    }



    return is_where_;
}
void Hako::draw() {
    
    DrawRectGraph( box_x, box_y, 9 * 64, 0, 64, 64, texture, 0, 0, 0 );
}
void Hako::destroy() {
    if( texture != -1 ) {
        DeleteGraph( texture );
        texture = -1;
    }
    if( chips != NULL ) {
        delete[] chips;
        chips = NULL;
    }
}