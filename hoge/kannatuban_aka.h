#pragma once

struct Chip_
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;

    // コンストラクタ
    Chip_();
};

class Kannatu_Aka {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
    int width_ = 0; int height_ = 0;
    int is_where_;
   
public:
    Chip_* chips;
    Kannatu_Aka();
    ~Kannatu_Aka();

    bool init( int map_Number_ );
    bool update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ );
    void draw();
    void destroy();
};