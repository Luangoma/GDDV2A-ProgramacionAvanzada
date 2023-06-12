#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class Player : public Solid
{
private:
    Model modelo;
    bool vivo;

public:
    Player(Model modelToSet, Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0), Vector3D rotationToSet = Vector3D(0.0, 180.0, 0.0), bool vivoToSet = true) 
        : modelo(modelToSet), vivo(vivoToSet)
    { 
        SetPosition(positionToSet);
        SetOrientation(rotationToSet);
        modelo.SetPosition(positionToSet);
        modelo.SetOrientation(rotationToSet);
        modelo.PaintColor(Color(0.2, 0.3, 0.8));
    }
    
    // Metodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);
    
    void Reset(); // Volver a ponerlo al principio del nivel.
    inline void SetModel(const Model modelToSet) { modelo = modelToSet; }

    inline Vector3D GetPosition() { return modelo.GetPosition(); }
    inline Vector3D GetOrientation() { return modelo.GetOrientation(); }
};
