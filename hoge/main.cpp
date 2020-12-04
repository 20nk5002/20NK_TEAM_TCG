// Include
#include "DxLib.h"
#include "keys.h"
#include"game.h"
#include"title.h"
#include"fade.h"
#include"allstageclear.h"
#include"gameover.h"
#include"clear.h"

// シーン管理列挙体
enum
{
    kTITLE_INIT,
    kTITLE_UPDATE,
    kGAME_INIT,
    kGAME_UPDATE,
    kFADE_UPDATE0,
    kFADE_UPDATE1,
    kFADE_UPDATE2,
    kGAME_CLEAR,
    kGAME_OVER,
    kSTOP_SCENE
};


// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
    int map_Number_ = 1;
    int scene_Change_ = 0;
    int check_Botan_ = 0;

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
    Allclear allclear;
    Clear clear;
    Gameover gameover;
   

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

    XINPUT_STATE xinput;
    GetJoypadXInputState(DX_INPUT_PAD1, &xinput);

        const char* keys = Keyboard::getReleased();
        if ( xinput.Buttons[ XINPUT_BUTTON_A ] == 1  || keys[KEY_INPUT_SPACE])
        {
            check_Botan_ = 1;
        }
        else
            check_Botan_ = 0;


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
                title.desrroy();
                work = kGAME_INIT;
                continue;
            }break;
        case kGAME_INIT:
            if( game.init( map_Number_ ) == false )
            {
                return 0;
            }
           
            work = kFADE_UPDATE1;
            break;
        case kFADE_UPDATE1:
            if( fade.update() <= 0 )
            {
                work = kGAME_UPDATE;
                continue;
            }break;
        case kGAME_UPDATE:
            if( xinput.Buttons[ XINPUT_BUTTON_A ] == 1&&xinput.Buttons[ XINPUT_BUTTON_A ] == 1 || keys[ KEY_INPUT_SPACE ]&& keys[ KEY_INPUT_DOWN ] )
            {
                work = kFADE_UPDATE2;
                continue;
            }
            scene_Change_ = game.update();
            if( scene_Change_ == 1 )
            {
                work = kSTOP_SCENE;
            }
            else if( scene_Change_ == 2 )
            {
                work = kGAME_OVER;
            }break;
        case  kGAME_CLEAR:
            if( allclear.init() == false )
            {
                return 0;
            }break;
        case kGAME_OVER:
            gameover.init();
            if (check_Botan_ == 1)
            {
                DxLib_End();
                game.destroy();
                allclear.destroy();
                gameover.destroy();
                clear.destroy();
                return 0;
            }
            break;
        case kSTOP_SCENE:
           
            if (check_Botan_ == 1)
            {
                if (map_Number_ > 3) {
                    work = kGAME_CLEAR;
                }
                else {
                    map_Number_++;
                    work = kTITLE_INIT;

                }
            }break;
        case kFADE_UPDATE2:
            if( fade.update() >= 255 )
            {
                work = kGAME_INIT;
                game.destroy();
                continue;
            }break;
        }
        
        Keyboard::update();
        const char* held = Keyboard::getReleased();

        // 画面初期化
        ClearDrawScreen();

      //  DrawGraph( x, y, texture, 0 );
        switch( work )
        {
        case kFADE_UPDATE0:
        case kTITLE_UPDATE:title.draw(); break;
        case kFADE_UPDATE1:
        case kFADE_UPDATE2:
        case kSTOP_SCENE:
        case kGAME_UPDATE: game.draw(); break;
        case kGAME_CLEAR:allclear.draw(); break;
        case kGAME_OVER:gameover.draw(); break;
        }
        clear.draw();
        fade.draw();
       
        // 裏画面に描画した内容を表示
        ScreenFlip();

        // 60FPS固定
        WaitTimer( 16 );
    }

    // DXライブラリの破棄
    DxLib_End();
    game.destroy();
    allclear.destroy();
    gameover.destroy();
    clear.destroy();

    return 0;
}