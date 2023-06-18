#pragma once
#include "Scene.h"
#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include "PowerUp.h"
#include "Ralenti.h"
#include <iostream>
#include "Accelere.h"
class SceneLevel : public Scene
{
private:
    int nivel;
    Cuboid *meta;
    bool activo, estadoPartida;
    Accelere* fastUp;
    Ralenti* slowUp;
    vector<PowerUp*> powerups;
    void CheckBoundary();

public:
    SceneLevel(bool activoArgument = true, int nivelToSet = 1) : 
    Scene(), activo(activoArgument), nivel(nivelToSet), estadoPartida(false)
    {
        std::cout << "Constructor del nivel " << nivel << std::endl;
    }

    void Init();

    inline void SetNivel(const int &nivelToSet) { this->nivel = nivelToSet; }; // DEPRECATED - Revisar
    inline void SetMeta(Cuboid *metaToSet) { this->meta = metaToSet; }
    inline void SetActivo(bool activoToSet) { this->activo = activoToSet; }
    inline void SetStatus(bool statusToSet) { this->estadoPartida = statusToSet; }

    int CheckStatus();
    void Update(const float &timeIncrement);
    void CheckColisiones();
    void ProcessKeyPressed(unsigned char key, int px, int py);

    inline void AddPowerUp(PowerUp* powerup) { this->powerups.push_back(powerup); };
    void haPerdido();
    void haGanado();

    void Reset();
};
