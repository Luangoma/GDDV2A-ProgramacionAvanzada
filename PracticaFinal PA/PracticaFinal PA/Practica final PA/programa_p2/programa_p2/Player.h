#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class Player : public Solid
{
private:
    ModelLoader* loader;
    Model modelo;
    bool vivo;

public:
    Player()
    {
        vivo = true;
    }    

    //Siempre se debe ejecutar al crear el personaje.
    void Init();
    
    // Metodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
    
    void Parar();
    void Reset(); // Volver a ponerlo al principio del nivel.
    inline void SetModel(const Model& modelToSet) { modelo = modelToSet; }
};
