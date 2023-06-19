#pragma once
#include "Scene.h"
class SceneGameOver : public Scene
{
private:
    vector<Text *> titulos;
    bool status;

public:
    SceneGameOver(bool statusToSet) : Scene(), status(statusToSet) {}

    void Init();
    void Update(const float &timeIncrement);
};