#pragma once

//�\����
class Title
{
private:
    int texrure_;//�O���t�n���h��
    int sound_;//�~���[�W�b�N�n���h��
public:
    Title();
    ~Title();

    bool init();
    bool update();
    void draw();
    void desrroy();
};