#include"DxLib.h"
#include"kannatuban_ao.h"

Chips_2::Chips_2() {
    x_ = y_ = 0;
    trim_x_ = trim_y_ = 0;
    id = 0;
}

Kannatu_Ao::Kannatu_Ao() {
    is_pressed_ = false;
    kannatu_x_ = kannatu_y_ = 0;
    is_where_ = 0;
}
Kannatu_Ao::~Kannatu_Ao() {
    destroy();
}

bool Kannatu_Ao::init( int map_Number_ ) {
    if( (texture = LoadGraph( "karichip.png" )) == -1 ) {
        return false;
    }

    FILE* fp;

    char file_name[ _MAX_PATH ];
    sprintf( file_name, "stage%d.fmf", map_Number_ );
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
    chips = new Chips_2[ width_ * height_ ];

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
        if( chips[ i ].id == 7 ) {
            is_where_ = i;
        }
    }

    // �t�@�C�������
    fclose( fp );

    return true;
}

bool Kannatu_Ao::update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ ) {

    if( osu_is_where_ == is_where_ || mesu_is_where_ == is_where_ || hako_is_where_ == is_where_ ) {
        is_pressed_ = true;
    }
    else {
        is_pressed_ = false;
    }


    return is_pressed_;
}
void Kannatu_Ao::draw() {
/*    // �u�����h���[�h��ύX
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, transparent_);

    DrawRectGraph(ao_x, ao_y, 3 * 64, 0, 64, 64, texture, 0, 0, 0);
    DrawRectGraph(ao_x, ao_y, 4 * 64, 0, 64, 64, texture, 0, 0, 0);

    // �u�����h���[�h��߂�
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    DrawRectGraph(ao_x, ao_y, 2 * 64, 0, 64, 64, texture, 0, 0, 0);*/
}
void Kannatu_Ao::destroy() {
    delete[] chips;
    DeleteGraph( texture );
}