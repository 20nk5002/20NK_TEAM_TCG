#pragma once


class Kannatu_Ao {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
    int is_where_;
    int transparent_;
    int texture;
    int ao_x;
    int ao_y;
   
public:
  
    Kannatu_Ao();
    ~Kannatu_Ao();

    bool init( int map_Number_ );
    bool update( int osu_is_where_, int mesu_is_where_, int hako_is_where_ );
    void draw();
    void destroy();
};