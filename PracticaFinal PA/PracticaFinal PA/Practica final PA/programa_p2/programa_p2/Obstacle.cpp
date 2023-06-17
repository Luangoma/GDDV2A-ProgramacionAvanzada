#include "Obstacle.h"

void Obstacle::Render()
{
    modelo.Render();
}

void Obstacle::Update(const float &timeIncrement)
{
    SetPosition(modelo.GetPosition());
    SetOrientation(modelo.GetOrientation());
    modelo.Update(timeIncrement);
}

void Obstacle::ActivarRalenti()
{
    modelo.SetSpeed(Vector3D(
        modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed / 2 : -speed / 2),
        modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed / 2 : -speed / 2),
        modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed / 2 : -speed / 2)));
}

void Obstacle::ActivarAccelere()
{
    modelo.SetSpeed(Vector3D(
        modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed * 2 : -speed * 2),
        modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed * 2 : -speed * 2),
        modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed * 2 : -speed * 2)));
}

void Obstacle::ActivarNormal()
{
    modelo.SetSpeed(Vector3D(
        modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed : -speed),
        modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed : -speed),
        modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed : -speed)));
}

/**
void Reset()
{
    modelo.SetPosition(Vector3D(randomX, 1.7, -incremento * i));
    modelo.SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
    modelo.SetSpeed(Vector3D(0, 0, 0));
}
//*/
