#pragma once
#include "Vehicle.h"
#include "Model.h"
#include "Player.h"

class Enemy : public Vehicle
{
private:
    Player *player;

public:
    Enemy(Model modelToSet,
          Player *playerToSet,
          Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0))
        : Vehicle(
              modelToSet,
              positionToSet,
              Vector3D(0.0, 0.0, 0.0),
              Vector3D(1.78, 1.13, 3.73),
              Color(0.8, 0.3, 0.2),
              0.1),
          player(playerToSet) {}

    // Metodos virtuales de Solid y otros
    void Update(const float &timeIncrement);

    // Metodos propios de la clase
    void TrackPlayer(); // Seguir al jugador objetivo.
    inline Vector3D GetPosition() { return GetModel().GetPosition(); }
};
