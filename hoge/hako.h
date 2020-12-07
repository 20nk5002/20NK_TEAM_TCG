#pragma once
#include"map.h"

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
    int box_x, box_y, box_x1, box_y1;
    int is_where_;
    int width_;
    int height_;
    int f_;
    Map* map;

public:
    Hako();
    ~Hako();

    Chip_4* chips;
    bool init( int n , int map_Number_, Map* map );
    int update( int osu_is_where_, int mesu_is_where_, const bool handle, char space_or_A_held, bool red_pressed, bool blue_pressed );
    void draw();
    void destroy();
};