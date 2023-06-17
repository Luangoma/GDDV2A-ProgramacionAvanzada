#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Player.h"

class PowerUP
{
private:
    ModelLoader* cargador;
    Model modelo;
    Player* player;
    vector<Solid*> trenes;

public:
    PowerUP(Player* playerToSet, vector<Solid*> trenToSet)
        : player(playerToSet),trenes(trenToSet) {}

    //Siempre se debe ejecutar al crear el personaje.
    void Init();

    // Metodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);

    void Reset(); // Volver a ponerlo al principio del nivel.
    inline void SetModel(const Model& modelToSet) { modelo = modelToSet; }
};

