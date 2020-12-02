#include"DxLib.h"
#include"player_mesu.h"
#include"keys.h"

Chip_::Chip_() {
    x_ = y_ = 0;
    trim_x_ = trim_y_ = 0;
    id = 0;
}



Player_Mesu::Player_Mesu() 
{
    init();
}

Player_Mesu::~Player_Mesu() 
{
    destroy();
}
bool Player_Mesu::init()
{

    FILE* fp;

    // テクスチャの読み込み

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

    textur = 0;
    x_ = x1_ = is_where_ % 20 * 64;
    y_ = y1_ = is_where_ / 20 * 64;
    f_ = 0;

    if( (textur = LoadGraph( "karichip.png" )) == -1 ) {

        return false;
    }
    return true;
}

void  Player_Mesu::update()
{
    //コントローラーの入力の取得
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
     const char* keys = Keyboard::getPressed();

     //右移動　フラグ　1
    if( keys[ KEY_INPUT_RIGHT ] == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_RIGHT ] && f_ == 0 )
    {
        if( f_ & 1 ) {

        }
        else {
            f_ += 1;
        }
    }
    //左移動　フラグ　2
    else  if( CheckHitKey( KEY_INPUT_LEFT ) == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_LEFT ] && f_ == 0 ) {

        if( f_ & 2 ) {

        }
    
        else {
            f_ += 2;
        }
    }

    //上移動　フラグ4
    else  if( CheckHitKey( KEY_INPUT_UP ) == 1 || xinput.Buttons[ XINPUT_BUTTON_DPAD_UP ] && f_ == 0 ) {

        if( f_ & 8 ) {

        }
        else {
            f_ += 8;
        }
    }

    //右移動
    if( f_ & 1 ) {
        if( x1_ + 64 != x_ ) {
            x_ += 4;
        }
        else {
            f_ -= 1;
            x1_ = x_;
        }
    }
    //左移動
    if( f_ & 2 ) {

        if( x1_ - 64 != x_ ) {
            x_ -= 4;
        }
        else {
            f_ -= 2;
            x1_ = x_;
        }

    }
    if( f_ & 4 ) {
      
        if( y1_ - 64 != y_ ) {
            y_ -= 4;
        }
        else {
            f_ -= 8;
            y1_ = y_;
        }
    }


}
void  Player_Mesu::draw()
{
    DrawRectGraph( x_, y_, 11 * 64, 0, 64, 64, textur, 1 );
    }
void  Player_Mesu::destroy()
{
    //グラフィックハンドルの開放
    if( textur != 0 ) {
        DeleteGraph( textur );
        textur = 0;

    }
}
