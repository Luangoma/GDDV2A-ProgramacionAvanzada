#pragma once
#include "Solid.h"
#include "Model.h"
#include "Player.h"

class Enemy : public Solid
{
private:
    Model modelo;
    Player* player;
    Vector3D position;

public:
    Enemy(Model modelToSet, Player* playerToSet, Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0), bool vivoToSet = true)
        : modelo(modelToSet), player(playerToSet), position(positionToSet)
    {
        SetPosition(positionToSet);
        modelo.SetPosition(positionToSet);
        modelo.PaintColor(Color(0.8, 0.3, 0.2));
    }

    // Metodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);

    void Reset(); // Volver a ponerlo al principio del nivel.

    inline Vector3D GetPosition() { return modelo.GetPosition(); }
};

