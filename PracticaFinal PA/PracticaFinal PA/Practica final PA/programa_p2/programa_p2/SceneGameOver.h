#pragma once
#include "Scene.h"
class SceneGameOver : public Scene
{
protected:
    Text *titulo;
    bool status;

public:
    SceneGameOver(bool statusToSet) : Scene(), status(statusToSet) {}

    void Init();
    void Update(const float &timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
};
