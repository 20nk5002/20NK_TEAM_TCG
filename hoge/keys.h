#pragma once

class Keyboard {
private:
    static char held_[ 256 ]; //������Ă���L�[
    static char pressed_[ 256 ]; //��x���������ꂽ�L�[
    static char released_[ 256 ]; //�����ꂽ�L�[
    static bool save_key_[ 256 ]; //�O�񉟂��ꂽ��

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