#pragma once
#include "Scene.h"
class SceneCreditos : public Scene
{
protected:
    vector<Text *> titulos;

public:
    SceneCreditos() : Scene() {}

    void Init();
    void Update(const float &timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
};
