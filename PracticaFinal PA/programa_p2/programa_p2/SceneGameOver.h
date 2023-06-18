#pragma once
#include "Scene.h"
#include <vector>
class SceneGameOver : public Scene
{
private:
    vector<Text *> titulos;
    bool status;

public:
    SceneGameOver(bool statusToSet) : Scene(), status(statusToSet) {}

    void Init();
    void Update(const float &timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
};
