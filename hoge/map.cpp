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

    // �e�N�X�`���̓ǂݍ���
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
    chips = new Chip[ width_ * height_ ];

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

        // �`��͈͂̎w��
        chips[ i ].trim_x_ = chips[ i ].id % 12 * 64;
        chips[ i ].trim_y_ = chips[ i ].id / 12 * 64;

        // ���W�̐ݒ�
        chips[ i ].x_ = 64 * (i % width_);
        chips[ i ].y_ = 64 * (i / width_);
    }

    // �t�@�C�������
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
        // �S�`�b�v�̕`��
        if( chips[ i ].id <= 8 ) {
            DrawRectGraph( chips[ i ].x_, chips[ i ].y_, chips[ i ].trim_x_, chips[ i ].trim_y_, 64, 64, map_texture_, true );
        }
        DrawFormatString( chips[ i ].x_, chips[ i ].y_, 0xFFFFFF, " %d\n", chips[ i ].id );
    }
}

void Map::destroy()
{
    // �O���t�B�b�N�n���h���̉��
    if( map_texture_ != 0 )
    {
        DeleteGraph( map_texture_ );
        map_texture_ = 0;
    }

    // �`�b�v�\���̂̃����������
    if( chips != NULL ) {
        delete[] chips;
        chips = NULL;
    }
    if( sound_ != 0 ) {
        DeleteSoundMem( sound_ );
    }
}