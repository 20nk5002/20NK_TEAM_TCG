// Include
#include "DxLib.h"

// WinMain
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpcmdLine, int nCmdShow )
{
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

    // ����ʂɕ`��
    SetDrawScreen( DX_SCREEN_BACK );

    int fps_counter = 0;    // FPS�J�E���g�p
    LONGLONG fps_timer = 0; // �����̕ۑ�
    LONGLONG prev_time = 0; // �P���[�v�O�̎���

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


        // ��ʏ�����
        ClearDrawScreen();

        // ����ʂɕ`�悵�����e��\��
        ScreenFlip();

        // 60FPS�Œ�
        WaitTimer( 16 );
    }

    // DX���C�u�����̔j��
    DxLib_End();

    return 0;
}