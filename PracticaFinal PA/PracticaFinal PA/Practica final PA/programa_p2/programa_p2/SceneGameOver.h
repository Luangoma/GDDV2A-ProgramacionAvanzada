#pragma once
#include "Scene.h"
class SceneGameOver : public Scene
{
protected:
    vector<Text*> titulos;
public:
    SceneGameOver() : Scene() {}

    void Init();
    void Update(const float& timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
};

