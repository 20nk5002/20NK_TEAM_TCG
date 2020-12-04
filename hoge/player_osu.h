#pragma once

struct Chip_3
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;

    // コンストラクタ
    Chip_3();
};

class Player_Osu
{
private:
    int textur;
    int x_, y_, f_, x1_, y1_;
    int width_ = 0; int height_ = 0;
    int map_type_ = 0;
    int is_where_ = 0;
    int fall_;


public:
    Chip_3* chips;
    Player_Osu();
    ~Player_Osu();
    bool init( int map_Number_ );
    int update( bool handle );
    void draw();
    void destroy();

};