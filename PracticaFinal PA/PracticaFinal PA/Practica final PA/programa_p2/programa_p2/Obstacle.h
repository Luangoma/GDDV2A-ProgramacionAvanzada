#pragma once
#include "Vehicle.h"
#include "Model.h"

class Obstacle : public Vehicle
{
    /**
private:
    Model modelo;
    float speed;
    //*/
public:
    Obstacle(Model modelToSet,
             Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
             Vector3D orientationToSet = Vector3D(0.0, 0.0, 0.0),
             Vector3D dimensions = Vector3D(0.0, 0.0, 0.0),
             Color colorToSet = Color(0.0, 0.0, 0.0),
             float speedToSet = 0.0)
        : Vehicle(
            modelToSet,
            positionToSet,
            orientationToSet,
            dimensions,
            colorToSet,
            speedToSet)
        //, modelo(modelToSet), speed(speedToSet)
    {
        /**
        if (nivelToSet==1)
        {

        }
        else if (nivelToSet == 2)
        {

        }
        else {

        }
        //*/

        /**
        SetPosition(positionToSet);
        model.SetPosition(positionToSet);
        model.SetOrientation(orientationToSet);
        model.PaintColor(colorToSet);
        model.SetSpeed(Vector3D(speedToSet, 0.0, 0.0));
        //*/
    }

    void Reset(); // Volver a ponerlo al principio del nivel.
    /**
    inline Vector3D GetPosition() { return modelo.GetPosition(); }
    inline Vector3D GetOrientation() { return modelo.GetOrientation(); }
    //*/
    inline void Repositioning(const Vector3D &repositionToSet) { this->SetPosition(repositionToSet); }
};
