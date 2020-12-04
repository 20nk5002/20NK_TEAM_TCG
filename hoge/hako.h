#pragma once

struct Chip_4
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;

    // コンストラクタ
    Chip_4();
};

class Hako {
private:

    int texture;
    int box_x, box_y;
    int is_where_;

    int width_;
    int height_;

public:
    Hako();
    ~Hako();

    Chip_4* chips;
    bool init( int n , int map_Number_ );
    int update( int osu_is_where_, int mesu_is_where_, const bool handle, char space_or_A_held );
    void draw();
    void destroy();
};