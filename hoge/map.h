#pragma once

// チップ構造体
struct Chip
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;

    // コンストラクタ
    Chip();
};

// フィールドのクラス
class Map
{
private:
    int map_texture_;
    int width_, height_;
    int map_type_;
public:
    Chip* chips;
    Map();
    ~Map();
    bool init( int map_Number_ );
    void update();
    void draw();
    void destroy();
};