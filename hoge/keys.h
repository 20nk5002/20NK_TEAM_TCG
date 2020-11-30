#pragma once

class Keyboard {
private:
    static char held_[ 256 ]; //押されているキー
    static char pressed_[ 256 ]; //一度だけ押されたキー
    static char released_[ 256 ]; //離されたキー
    static bool save_key_[ 256 ]; //前回押されたか

public:
    static void update();
    static const char* getHeld() {
        return held_;
    }
    static const char* getPressed() {
        return pressed_;
    }
    static const char* getReleased() {
        return released_;
    }
};