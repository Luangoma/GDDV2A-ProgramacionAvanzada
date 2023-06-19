#pragma once
#include "Scene.h"
#include <vector>

class SceneMenu : public Scene
{
private:
    Cuboid *cielo;
    vector<Text *> titulos;

public:
    SceneMenu() : Scene() {}

    void Init();
};