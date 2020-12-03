#include"DxLib.h"
#include"hako.h"

Hako::Hako() {
    texture = 0;
    box_x = box_y = 0;
}
Hako::~Hako() {

}

bool Hako::init( int n ) {

    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_Number_ );
    //sprintf( file_name, "hako.fmf" );
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
    chips = new Chip_[ width_ * height_ ];

    // メモリが確保できたか
    if( chips == NULL )
    {
        // エラー
        return false;
    }

    // fmfヘッダー部分をスキップ
    fseek( fp, 20L, SEEK_SET );

    // 全チップデータの格納
    for( int i = 0; i < width_ * height_; i++ )
    {
        fread( &chips[ i ].id, sizeof( char ), 1, fp );
        if( chips[ i ].id == 11 ) {
            is_where_ = i;
        }

        /*       // 描画範囲の指定
               chips[ i ].trim_x_ = chips[ i ].id % 12 * 64;
               chips[ i ].trim_y_ = chips[ i ].id / 12 * 64;
               // 座標の設定
               chips[ i ].x_ = 64 * (i % width_);
               chips[ i ].y_ = 64 * (i / width_);*/
    }
    // ファイルを閉じる
    fclose( fp );

    if( texture = LoadGraph( "karichip.png" ) == -1 ) {
        return false;
    }
    return true;
}
void Hako::update() {

}
void Hako::draw() {
    DrawRectGraph( box_x * 64, box_y * 64, 64 * 9, 0, 64, 64, texture, 0, 0, 0 );
}
void Hako::destroy() {

}