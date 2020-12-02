// Include
#include "DxLib.h"
#include "keys.h"
#include"game.h"
#include"title.h"

// �V�[���Ǘ��񋓑�
enum
{
    kTITLE_INIT,
    kTIRLE_UPDATE,
    kGAME_INIT,
    kGAME_UPDATE,
    kFADE_UPDATE1

};


// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
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

    
    Game game;

    if( game.init() == -1 )
    {
        return 0;
    }


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
                work = kFADE_UPDATE1;
                continue;
            }break;
        case kFADE_UPDATE1:
            if(fade.update()>=255)
        }

        Keyboard::update();
        const char* held = Keyboard::getReleased();

        // ��ʏ�����
        ClearDrawScreen();

      //  DrawGraph( x, y, texture, 0 );
        game.draw();

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