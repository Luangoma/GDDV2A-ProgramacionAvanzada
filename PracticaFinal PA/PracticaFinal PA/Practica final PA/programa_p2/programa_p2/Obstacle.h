#pragma once
#include "Model.h"
#include "Solid.h"
class Obstacle : public Solid
{
private:
    Model modelo;
    float speed /** , incremento, i;
     float* randomX//*/
        ;

public:
    Obstacle(Model modelToSet, /* float* randomToSet, float incrementoToSet = 0.0, float iToSet = 0.0,*/
             Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
             Vector3D orientationToSet = Vector3D(0.0, 0.0, 0.0),
             Color colorToSet = Color(0.0, 0.0, 0.0),
             Vector3D speedToSet = Vector3D(0.0, 0.0, 0.0))
        : modelo(modelToSet)
    //, randomX(randomToSet), incremento(incrementoToSet), i(iToSet)
    {
        SetPosition(positionToSet);
        modelo.SetPosition(positionToSet);
        modelo.SetOrientation(orientationToSet);
        modelo.PaintColor(colorToSet);
        modelo.SetSpeed(speedToSet);
    }

    // Metodos virtuales de Solid
    void Render();
    void Update(const float &timeIncrement);

    // void Reset(); // Volver a ponerlo al principio del nivel.
    /**
    inline Vector3D GetPosition() { return modelo.GetPosition(); }
    inline Vector3D GetOrientation() { return modelo.GetOrientation(); }
    //*/
    inline void Repositioning(const Vector3D &repositionToSet) { this->modelo.SetPosition(repositionToSet); }

    void ActivarRalenti();
    void ActivarAccelere();
    void ActivarNormal();
};
