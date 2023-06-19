#pragma once
#include "Scene.h"
class SceneCreditos : public Scene
{
private:
    vector<Text *> titulos;

public:
    SceneCreditos() : Scene() {}

    void Init();
    void Update(const float &timeIncrement);
};