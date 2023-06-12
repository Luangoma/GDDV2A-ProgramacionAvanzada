#pragma once
#include "Scene.h"
#include <vector>
#include "Interface.h"

class SceneMenu : public Scene
{
private:
    Cuboid *cielo;

protected:
    vector<Text*> titulos;

public:
    SceneMenu() : Scene() {}

    void Init();
    void ProcessKeyPressed(unsigned char key, int px, int py);
};
