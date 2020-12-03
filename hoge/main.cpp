// Include
#include "DxLib.h"
#include "keys.h"
#include"game.h"
#include"title.h"
#include"fade.h"

// �V�[���Ǘ��񋓑�
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

    SetOutApplicationLogValidFlag( false );//���O�t�@�C�����o�͂��Ȃ�

    // DX���C�u�����̎��O�ݒ�
    ChangeWindowMode( true );      // �E�B���h�E���[�h
    SetGraphMode( 1280, 720, 32 ); // ��ʉ𑜓x�̎w��
    SetMainWindowText( "Game" );   // �E�B���h�E�^�C�g���̕ύX
    SetWaitVSyncFlag( false );     // ���������𖳌�

    // DX���C�u�����̏�����
    if( DxLib_Init() == -1 )
    {
        // �G���[
        return 0;
    }

    // �V�[���̍쐬
    Title title;
    Game game;
    Fade fade;

    // ����ʂɕ`��
    SetDrawScreen( DX_SCREEN_BACK );

    int fps_counter = 0;    // FPS�J�E���g�p
    LONGLONG fps_timer = 0; // �����̕ۑ�
    LONGLONG prev_time = 0; // �P���[�v�O�̎���

    // ��Ɣԍ���
    int work = kTITLE_INIT;


    // ���C�����[�v
    while( ProcessMessage() != -1 )
    {
        // ���ݎ������擾
        LONGLONG now_time = GetNowHiPerformanceCount();

        // �P�b�o�߂�����
        ++fps_counter;
        if( now_time - fps_timer > 1000000 )
        {
            // �E�B���h�E�^�C�g�����쐬����
            char name[ _MAX_PATH ];
            sprintf( name, "Game:%d", fps_counter );
            SetMainWindowText( name );

            fps_counter = 0; // �J�E���^�[������
            fps_timer = now_time; // ���݂̎������Ō�ɍX�V�������ԂƂ��ċL��

        }

        switch( work )
        {
        case kTITLE_INIT:  // �^�C�g��������
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

        // ��ʏ�����
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
        // ����ʂɕ`�悵�����e��\��
        ScreenFlip();

        // 60FPS�Œ�
        WaitTimer( 16 );
    }

    // DX���C�u�����̔j��
    DxLib_End();
    game.destroy();

    return 0;
}