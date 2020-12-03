#pragma once
//プレイアー

struct Chip_
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;

    // コンストラクタ
    Chip_();
};

class Player_Mesu
{
private:
    int textur;
    int x_, y_, f_, x1_, y1_;
    int width_ = 0; int height_ = 0;
    int map_type_ = 0;
    int is_where_ = 0;


public:
    Chip_* chips;
    Player_Mesu();
    ~Player_Mesu();
    bool init( int map_Number_ );
    int update();
    void draw();
    void destroy();

};