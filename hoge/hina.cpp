// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
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

    // 裏画面に描画
    SetDrawScreen( DX_SCREEN_BACK );

    int fps_counter = 0;    // FPSカウント用
    LONGLONG fps_timer = 0; // 時刻の保存
    LONGLONG prev_time = 0; // １ループ前の時刻

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


        // 画面初期化
        ClearDrawScreen();

        // 裏画面に描画した内容を表示
        ScreenFlip();

        // 60FPS固定
        WaitTimer( 16 );
    }

    // DXライブラリの破棄
    DxLib_End();

    return 0;
}