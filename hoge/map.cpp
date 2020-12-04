// Include
#include"map.h"
#include"DxLib.h"

Chip::Chip()
{
    x_ = y_ = 0;
    trim_x_ = trim_y_ = 0;
    id = 0;
};

Map::Map()
{
   // init();
}

Map::~Map()
{
    destroy();
}

bool Map::init( int map_Number_ )
{
    map_texture_ = 0;
    width_ = height_ = 0;
    map_type_ = map_Number_;
    chips = NULL;

    FILE* fp;

    // テクスチャの読み込み
    if( (map_texture_ = LoadGraph( "karichip.png" )) == -1 )
    {
        return false;
    }
    if( (sound_ = LoadSoundMem( "map.wav" ) == -1) ) {
        return false;
    }

    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_type_ );
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
    chips = new Chip[ width_ * height_ ];

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

        // 描画範囲の指定
        chips[ i ].trim_x_ = chips[ i ].id % 12 * 64;
        chips[ i ].trim_y_ = chips[ i ].id / 12 * 64;

        // 座標の設定
        chips[ i ].x_ = 64 * (i % width_);
        chips[ i ].y_ = 64 * (i / width_);
    }

    // ファイルを閉じる
    fclose( fp );

    return true;

}

void Map::update()
{
    PlaySoundMem( sound_, DX_PLAYTYPE_LOOP );
}

void Map::draw()
{

    for( int i = 0; i < width_ * height_; i++ )
    {
        // 全チップの描画
        if( chips[ i ].id <= 8 ) {
            DrawRectGraph( chips[ i ].x_, chips[ i ].y_, chips[ i ].trim_x_, chips[ i ].trim_y_, 64, 64, map_texture_, true );
        }
        DrawFormatString( chips[ i ].x_, chips[ i ].y_, 0xFFFFFF, " %d\n", chips[ i ].id );
    }
}

void Map::destroy()
{
    // グラフィックハンドルの解放
    if( map_texture_ != 0 )
    {
        DeleteGraph( map_texture_ );
        map_texture_ = 0;
    }

    // チップ構造体のメモリを解放
    if( chips != NULL ) {
        delete[] chips;
        chips = NULL;
    }
    if( sound_ != 0 ) {
        DeleteSoundMem( sound_ );
    }
}