#pragma once

class Hako {
private:
    int texture;
    int box_x, box_y;

public:
    Hako();
    ~Hako();

    bool init( int n , int map_Number_ );
    void update();
    void draw();
    void destroy();
};