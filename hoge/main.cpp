// Include
#include "DxLib.h"
#include "keys.h"
#include"game.h"
#include"title.h"
#include"fade.h"

// シーン管理列挙体
enum
{
    kTITLE_INIT,
    kTITLE_UPDATE,
    kGAME_INIT0,
    kGAME_INIT1,
    kGAME_INIT2,
    kGAME_INIT3,
    kGAME_UPDATE0,
    kGAME_UPDATE1,
    kGAME_UPDATE2,
    kGAME_UPDATE3,
    kFADE_UPDATE0,
    kFADE_UPDATE1,
    kFADE_UPDATE2,
    kFADE_UPDATE3,
    kFADE_UPDATE4,
    kFADE_UPDATE5,
    kFADE_UPDATE6,
    kFADE_UPDATE7,
    kFADE_UPDATE8,
    kFADE_UPDATE9,
    kGAME_CLEAR
};


// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    int map_Number_ = 2;

    SetOutApplicationLogValidFlag( false );//ログファイルを出力しない

    // DXライブラリの事前設定
    ChangeWindowMode( true );      // ウィンドウモード
    SetGraphMode( 1280, 720, 32 ); // 画面解像度の指定
    SetMainWindowText( "Game" );   // ウィンドウタイトルの変更
    SetWaitVSyncFlag( false );     // 垂直同期を無効

    // DXライブラリの初期化
    if( DxLib_Init() == -1 )
    {
        // エラー
        return 0;
    }

    // シーンの作成
    Title title;
    Game game;
    Fade fade;

    // 裏画面に描画
    SetDrawScreen( DX_SCREEN_BACK );

    int fps_counter = 0;    // FPSカウント用
    LONGLONG fps_timer = 0; // 時刻の保存
    LONGLONG prev_time = 0; // １ループ前の時刻

    // 作業番号数
    int work = kTITLE_INIT;


    // メインループ
    while( ProcessMessage() != -1 )
    {
        // 現在時刻を取得
        LONGLONG now_time = GetNowHiPerformanceCount();

        // １秒経過したか
        ++fps_counter;
        if( now_time - fps_timer > 1000000 )
        {
            // ウィンドウタイトルを作成する
            char name[ _MAX_PATH ];
            sprintf( name, "Game:%d", fps_counter );
            SetMainWindowText( name );

            fps_counter = 0; // カウンター初期化
            fps_timer = now_time; // 現在の時刻を最後に更新した時間として記憶

        }

        switch( work )
        {
        case kTITLE_INIT:  // タイトル初期化
            if( title.init() == false )
            {
                return 0;
            }
            work = kTITLE_UPDATE;
            break;
        case kTITLE_UPDATE:
            if( title.update() == false )
            {
                work = kFADE_UPDATE0;
                continue;
            }break;
        case kFADE_UPDATE0:
            if( fade.update() >= 255 )
            {
                work = kGAME_INIT0;
                continue;
            }break;
        case kGAME_INIT0:
            if( game.init( map_Number_ ) == false )
            {
                return 0;
            }
            map_Number_++;
            if( map_Number_ > 3 ) {
                work = kGAME_CLEAR;
            }
            work = kFADE_UPDATE1;
            break;
        case kFADE_UPDATE1:
            if( fade.update() <= 0 )
            {
                work = kGAME_UPDATE0;
                continue;
            }break;
        case kGAME_UPDATE0:
            if( game.update() == false )
            {
                work = kTITLE_INIT;
                game.destroy();
                continue;
            }break;
        case  kGAME_CLEAR:break;
        }

        Keyboard::update();
        const char* held = Keyboard::getReleased();

        // 画面初期化
        ClearDrawScreen();

      //  DrawGraph( x, y, texture, 0 );
        switch( work )
        {
        case kFADE_UPDATE0:
        case kFADE_UPDATE2:
        case kFADE_UPDATE4:
        case kFADE_UPDATE6:
        case kFADE_UPDATE8:
        case kTITLE_UPDATE:title.draw(); break;
        case kFADE_UPDATE1:
        case kFADE_UPDATE3:
        case kFADE_UPDATE5:
        case kFADE_UPDATE7:
        case kFADE_UPDATE9:
        case kGAME_UPDATE0: game.draw(); break;
        }
        fade.draw();
        // 裏画面に描画した内容を表示
        ScreenFlip();

        // 60FPS固定
        WaitTimer( 16 );
    }

    // DXライブラリの破棄
    DxLib_End();
    game.destroy();

    return 0;
}