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

/*
    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_Number_ );;
    fp = fopen( file_name, "rb" );

    // NULLチェック
    if( fp == NULL )
    {
        // エラー
        return false;
    }

    fseek( fp, 8L, SEEK_SET );

    fread( &width_, sizeof( int ), 1, fp );
    fread( &height_, sizeof( int ), 1, fp );

    // 横幅*縦幅のメモリを確保
    chips = new Chip_4[ width_ * height_ ];

    // メモリが確保できたか
    if( chips == NULL )
    {
        // エラー
        return false;
    }

    // fmfヘッダー部分をスキップ
    fseek( fp, 20L, SEEK_SET );
    */
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

        /*       // 描画範囲の指定
               chips[ i ].trim_x_ = chips[ i ].id % 12 * 64;
               chips[ i ].trim_y_ = chips[ i ].id / 12 * 64;
               // 座標の設定
               chips[ i ].x_ = 64 * (i % width_);
               chips[ i ].y_ = 64 * (i / width_);*/

    }
    box_x = is_where_ % 20 * 64;
    box_y = is_where_ / 20 * 64;
    box_x1 = box_x = is_where_ % 20 * 64;
    box_y1 = box_y = is_where_ / 20 * 64;

    // ファイルを閉じる
  //  fclose( fp );
    f_ = 0;
    
    return true;
}
int Hako::update( int osu_is_where_, int mesu_is_where_, const bool handle, char space_or_A_held ) {
    
    if( (map->chips[ is_where_ + 20 ].id) == 0 ) {
        f_ = 16;

    }
    if( f_ & 16 ) {
        if( box_y1 + 64 != box_y ) {
            box_y += 4;
        }
        else {
            f_ -= 16;
            if( map->chips[ is_where_ ].id != 0 ) {
                map->chips[ is_where_ ].id = 0;
                box_y1 = box_y;
                is_where_ += 20;
            }
                map->chips[ is_where_ ].id = 9;
            
        }
    }
    //プレイヤーの位置
    int handling_character_is_where_ = (osu_is_where_ * (!handle)) + (mesu_is_where_ * handle);
    if( space_or_A_held == 1 ) {
 /*if( handling_character_is_where_ + 1 != 1 ) {*/
        if( is_where_ - 1 != 1 ) {
            if( handling_character_is_where_ - 1 == is_where_ ) {

                box_x -= 64;
                is_where_ -= 1;
                /* }*/
            }
        }
        if( is_where_ - 1 != 1 ) {
            if( handling_character_is_where_ + 1 == is_where_ ) {
                /* if( handling_character_is_where_ + 1 != 1 ) {*/
                box_x += 64;
                is_where_ += 1;
                /* }*/
            }
        }
    }
   
   
    
    return is_where_;
}
void Hako::draw() {
    
    DrawRectGraph( box_x, box_y, 9 * 64, 0, 64, 64, texture, 0, 0, 0 );
  //  DrawFormatString( box_x, box_y, GetColor( 255, 255, 255 ), ":%d:%d", (chips[ is_where_ + 20 ].id), (chips[ is_where_ ].id) );

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