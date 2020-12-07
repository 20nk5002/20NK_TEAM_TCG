#pragma once

struct Chips_2
{
    int x_, y_;
    int trim_x_, trim_y_;
    int id;


    // �R���X�g���N�^
    Chips_2();
};

class Kannatu_Ao {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
    int width_ = 0; int height_ = 0;
    int is_where_;
    int transparent_;
    int texture;
    int ao_x;
    int ao_y;
   
public:
  
    Kannatu_Ao();
    ~Kannatu_Ao();

    Chips_2* chips;
    bool init( int map_Number_ );
    bool update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ );
    void draw();
    void destroy();
};