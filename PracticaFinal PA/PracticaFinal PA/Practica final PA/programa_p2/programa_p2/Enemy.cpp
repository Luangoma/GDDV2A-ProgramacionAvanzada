#include "Enemy.h"

void Enemy::Render()
{
	modelo.Render();
}

void Enemy::Update(const float& timeIncrement)
{
	Model personaje; //, posicion del personaje para que le persiga
	// POR DEFINIR
	if (modelo.GetPosition().GetX() < personaje.GetPosition().GetX()) {
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (modelo.GetPosition().GetX() > personaje.GetPosition().GetX())
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() < personaje.GetPosition().GetY())
	{
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() > personaje.GetPosition().GetY())
	{
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
	}
	modelo.Update(timeIncrement);
}

void Enemy::Reset()
{
	modelo.SetPosition(GetPosition());
}