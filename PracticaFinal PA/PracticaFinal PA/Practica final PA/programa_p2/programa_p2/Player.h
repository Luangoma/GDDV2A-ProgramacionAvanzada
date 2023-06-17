#pragma once
#include "Solid.h"
#include "Model.h"

class Player : public Solid
{
private:
    Model modelo;
    bool vivo;
    float speed;
    Vector3D position, rotation;

public:
    Player(Model modelToSet,
           Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
           Vector3D rotationToSet = Vector3D(0.0, 180.0, 0.0),
           bool vivoToSet = true)
        : modelo(modelToSet), vivo(vivoToSet), position(positionToSet), rotation(rotationToSet), speed(0.1)
    {
        modelo.SetPosition(positionToSet);
        modelo.SetOrientation(rotationToSet);
        modelo.PaintColor(Color(0.2, 0.3, 0.8));
    }

    // Metodos virtuales de Solid
    void Render();
    void Update(const float &timeIncrement);
    void ProcessKeyPressed(unsigned char key, int px, int py);

    void Reset();             // Volver a ponerlo al principio del nivel.
    Vector3D GetDimensions(); // Devuelve el vector de dimensiones del personaje.
    /**
    inline Vector3D GetPosition() { return modelo.GetPosition(); }
    inline Vector3D GetOrientation() { return modelo.GetOrientation(); }
    //*/
    inline bool GetStatus() const { return this->vivo; }
    void ActivarRalenti();
    void ActivarAccelere();
    void ActivarNormal();
};
