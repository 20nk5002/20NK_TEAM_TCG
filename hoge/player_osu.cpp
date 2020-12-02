#include"DxLib.h"
#include"player_osu.h"
#include"keys.h"

Chip_3::Chip_3() {
    x_ = y_ = 0;
    trim_x_ = trim_y_ = 0;
    id = 0;
}


Player_Osu::Player_Osu()
{
    init();
}

Player_Osu::~Player_Osu()
{
    destroy();
}
bool Player_Osu::init()
{
    FILE* fp;

    // �e�N�X�`���̓ǂݍ���

    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_type_ );
    //sprintf( file_name, "hako.fmf" );
    fp = fopen( file_name, "rb" );

    // NULL�`�F�b�N
    if( fp == NULL )
    {
        // �G���[
        return false;
    }

    fseek( fp, 8L, SEEK_SET );

    fread( &width_, sizeof( int ), 1, fp );
    fread( &height_, sizeof( int ), 1, fp );

    // ����*�c���̃��������m��
    chips = new Chip_3[ width_ * height_ ];

    // ���������m�ۂł�����
    if( chips == NULL )
    {
        // �G���[
        return false;
    }

    // fmf�w�b�_�[�������X�L�b�v
    fseek( fp, 20L, SEEK_SET );

    // �S�`�b�v�f�[�^�̊i�[
    for( int i = 0; i < width_ * height_; i++ )
    {
        fread( &chips[ i ].id, sizeof( char ), 1, fp );
        if( chips[ i ].id == 10 ) {
            is_where_ = i;
        }

        /*       // �`��͈͂̎w��
               chips[ i ].trim_x_ = chips[ i ].id % 12 * 64;
               chips[ i ].trim_y_ = chips[ i ].id / 12 * 64;
               // ���W�̐ݒ�
               chips[ i ].x_ = 64 * (i % width_);
               chips[ i ].y_ = 64 * (i / width_);*/
    }
    // �t�@�C�������
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
//�A�b�v�f�[�g�@�j
void Player_Osu::update()
{
    //�R���g���[���[�̓��͂̎擾
    XINPUT_STATE xinput;
    GetJoypadXInputState( DX_INPUT_PAD1, &xinput );
    const char* keys = Keyboard::getHeld();

    //�E�ړ��@�t���O�@1
    if( keys[ KEY_INPUT_RIGHT ]  || xinput.Buttons[ XINPUT_BUTTON_DPAD_RIGHT ] && f_ == 0 )
    {
        if( f_ & 1 ) {

        }
        else {
            f_ += 1;
        }
    }
    //���ړ��@�t���O�@2
    else  if( keys[ KEY_INPUT_LEFT ]  || xinput.Buttons[ XINPUT_BUTTON_DPAD_LEFT ] && f_ == 0 ) {

        if( f_ & 2 ) {

        }

        else {
            f_ += 2;
        }
    }

    //��ړ��@�t���O4
    else  if( keys[ KEY_INPUT_UP ]  || xinput.Buttons[ XINPUT_BUTTON_DPAD_UP ] && f_ == 0 ) {

        if( f_ & 4 ) {

        }
        else {
            f_ += 4;
        }
    }

    //�E�ړ�
    if( f_ & 1 ) {
        if( x1_ + 64 != x_ ) {
            x_ += 4;
        }
        else {
            f_ -= 1;
            x1_ = x_;
        }
    }
    //���ړ�
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
void Player_Osu:: draw()
{
    DrawRectGraph( x_, y_, 10 * 64, 0, 64, 64, textur, 0 );
    DrawFormatString( x_ + 30, y_, GetColor( 255, 255, 255 ), ":%6d:%d:%d", x_, y_, f_ );

}
void Player_Osu::destroy()
{
    //�O���t�B�b�N�n���h���̊J��
    if( textur != 0 ) {
        DeleteGraph( textur );
        textur = 0;

    }
}