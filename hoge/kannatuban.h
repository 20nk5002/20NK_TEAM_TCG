#pragma once

class Kannatu {
private:
    bool is_pressed_ = false;
    int kannatu_x_, kannatu_y_;
public:
    Kannatu();
    ~Kannatu();

    bool init();
    void update();
    void draw();
    void destroy();
};