#pragma once

//構造体
class Title
{
private:
    int texrure_;//グラフハンドル
    int sound_;//ミュージックハンドル
public:
    ~Title();

    bool init();
    bool update();
    void draw();
    void desrroy();
};