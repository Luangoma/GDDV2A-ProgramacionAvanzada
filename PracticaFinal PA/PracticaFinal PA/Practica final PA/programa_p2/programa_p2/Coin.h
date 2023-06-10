#pragma once
#include "Model.h"
#include "ModelLoader.h"

class Coin
{
private:
    ModelLoader* cargador;
    Model modelo;

public:
    Coin() {}

    //Siempre se debe ejecutar al crear el personaje.
    void Init();

    // Metodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);

    void Reset(); // Volver a ponerlo al principio del nivel.
    inline void SetModel(const Model& modelToSet) { modelo = modelToSet; }
};


