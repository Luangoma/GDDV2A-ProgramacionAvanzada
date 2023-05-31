#pragma once
#include "Scene.h"
#include <vector>

class SceneMenu : public Scene
{
private:
    Cuboid* cielo;
protected:
    vector<Text*> titulos;
public:
    SceneMenu() : Scene() {}

    void Init();
    void Update(const float& timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
};

