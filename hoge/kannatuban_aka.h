#pragma once

class Kannatu {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
public:
    Kannatu();
    ~Kannatu();

    bool init();
    bool update( int player_is_where_ );
    void draw();
    void destroy();
};