#pragma once


class Kannatu_Ao {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
   
   
public:
  
    Kannatu_Ao();
    ~Kannatu_Ao();

    bool init( int map_Number_ );
    bool update( int player_is_where_ );
    void draw();
    void destroy();
};