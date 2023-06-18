#pragma once
#include "Vehicle.h"
#include "Model.h"

class Player : public Vehicle
{
private:
    bool status;
public:
    Player(Model modelToSet,
           Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
           Vector3D orientationToSet = Vector3D(0.0, 180.0, 0.0),
           bool statusToSet = true,
           float speedToSet = 0.1
        )
        : Vehicle(
            modelToSet,
            positionToSet,
            orientationToSet,
            Vector3D(1.78, 1.13, 3.73),
            Color(0.2, 0.3, 0.8),
            speedToSet),
        status(statusToSet)
    {
        SetSpeed(Vector3D(0.0, 0.0, 0.0));
        /**
        GetModel().SetSpeed(Vector3D(0.0,0.0,0.0));

        modelo.SetPosition(positionToSet);
        modelo.SetOrientation(rotationToSet);
        modelo.PaintColor(Color(0.2, 0.3, 0.8));
        //*/
    }

    void ProcessKeyPressed(unsigned char key, int px, int py);

    void Reset();             // Volver a ponerlo al principio del nivel.

    inline void SetStatus(const bool& statusToSet) { this->status = statusToSet; }
    inline bool GetStatus() const { return this->status; }

    /**
    inline Vector3D GetPosition() { return modelo.GetPosition(); }
    inline Vector3D GetOrientation() { return modelo.GetOrientation(); }
    //*/

};
