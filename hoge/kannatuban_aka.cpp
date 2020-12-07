#include"DxLib.h"
#include"kannatuban_aka.h"

Chips_::Chips_() {
    x_ = y_ = 0;
    trim_x_ = trim_y_ = 0;
    id = 0;
}

Kannatu_Aka::Kannatu_Aka() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
    is_where_ = 0;
    transparent_ = 0;
}
Kannatu_Aka::~Kannatu_Aka() {
    destroy();
}

bool Kannatu_Aka::init( int map_Number_ ) {
    if ((texture = LoadGraph("karichip.png")) == -1) {
        return false;
    }

    FILE* fp;

    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_Number_ );
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
    chips = new Chips_[ width_ * height_ ];

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
        if( chips[ i ].id == 3 ) {
            is_where_ = i;
        }
    }

    // ファイルを閉じる
    fclose( fp );

    return true;
}

bool Kannatu_Aka::update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ ) {

    if( osu_is_where_ == is_where_||mesu_is_where_==is_where_||hako_is_where_==is_where_ ){ 
        return true;
    }
    return false;

}
void Kannatu_Aka::draw() {

}
void Kannatu_Aka::destroy() {
    delete[] chips;
    DeleteGraph( texture );
}