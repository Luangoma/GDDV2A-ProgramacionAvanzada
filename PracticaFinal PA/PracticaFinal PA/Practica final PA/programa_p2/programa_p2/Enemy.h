#pragma once
#include "Vehicle.h"
#include "Model.h"
#include "Player.h"

class Enemy : public Vehicle
{
private:
    Player* player;

public:
    Enemy(Model modelToSet, 
        Player* playerToSet, 
        Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0))
        : Vehicle(
            modelToSet,
            positionToSet,
            Vector3D(0.0,0.0,0.0),
            Vector3D(1.78, 1.13, 3.73),
            Color(0.8, 0.3, 0.2),
            0.1),
        player(playerToSet)
    {
        /**
        SetModel(modelToSet);
        SetPosition(positionToSet);
        GetModel().SetPosition(positionToSet);
        GetModel().SetOrientationSpeed(Vector3D(0.0,1.0,0.0));
        GetModel().PaintColor(Color(0.8, 0.3, 0.2));
        //*/
    }

    // Metodos virtuales de Solid
    void Update(const float& timeIncrement);

    void TrackPlayer(); // Seguir al jugador objetivo.
    inline Vector3D GetPosition() { return GetModel().GetPosition(); }

};

