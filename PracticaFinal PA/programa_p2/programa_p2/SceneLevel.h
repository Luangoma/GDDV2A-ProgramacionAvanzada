#pragma once
#include "Scene.h"
#include <vector>
#include "ModelLoader.h"
#include "Cuboid.h"
#include "PowerUp.h"
#include "Ralenti.h"
#include <iostream>
#include "Accelere.h"
class SceneLevel : public Scene
{
private:
    int nivel, maxLevel;
    Cuboid *meta;
    bool activo, estadoPartida;
    ModelLoader *loaderPower;
    Accelere *fastUp;
    Ralenti *slowUp;
    vector<PowerUp *> powerups;
    void CheckBoundary();

public:
    SceneLevel(int nivelToSet = 1, int maxLevelToSet = 3, bool activoArgument = true) : 
    Scene(), nivel(nivelToSet), maxLevel(maxLevelToSet), activo(activoArgument), estadoPartida(false) {}

    void Init();

    inline void SetNivel(const int &nivelToSet) { this->nivel = nivelToSet; }; // DEPRECATED - Revisar
    inline void SetMeta(Cuboid *metaToSet) { this->meta = metaToSet; }
    inline void SetActivo(bool activoToSet) { this->activo = activoToSet; }
    inline void SetStatus(bool statusToSet) { this->estadoPartida = statusToSet; }

    int CheckStatus();
    void Update(const float &timeIncrement);
    void CheckColisiones();
    void ProcessKeyPressed(unsigned char key, int px, int py);

    inline void AddPowerUp(PowerUp *powerup) { this->powerups.push_back(powerup); AddGameObject(powerup); };

    void Reset();
};
