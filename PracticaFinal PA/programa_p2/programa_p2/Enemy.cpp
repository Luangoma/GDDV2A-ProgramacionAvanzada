#include "Enemy.h"

void Enemy::Update(const float &timeIncrement)
{
	TrackPlayer();
	Vehicle::Update(timeIncrement);
}

void Enemy::TrackPlayer()
{

	// La x, y & z del personaje estan en su centro, menos la z que esta en el suelo.
	// Se debe calcular la rotacion para un seguimiento correcto.
	// Cuando el personaje rota, las dimensiones se intercambian entre los ejes X y Z.
	Vector3D dimensionesPlayer = player->GetDimensions();
	float minXPlayer, maxXPlayer, minYPlayer, maxYPlayer, minZPlayer, maxZPlayer;
	minXPlayer = this->player->GetPosition().GetX() - dimensionesPlayer.GetX() / 2;
	maxXPlayer = this->player->GetPosition().GetX() + dimensionesPlayer.GetX() / 2;
	minYPlayer = this->player->GetPosition().GetY();
	maxYPlayer = this->player->GetPosition().GetY() + dimensionesPlayer.GetY();
	minZPlayer = this->player->GetPosition().GetZ() - dimensionesPlayer.GetZ() / 2;
	maxZPlayer = this->player->GetPosition().GetZ() + dimensionesPlayer.GetZ() / 2;

	// Logica de seguimiento - (priorizando la posicion en el eje Z)
	if (minZPlayer >= GetPosition().GetZ())
	{
		SetSpeed(Vector3D(0.0, 0.0, 0.1));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (maxZPlayer <= GetPosition().GetZ())
	{
		SetSpeed(Vector3D(0.0, 0.0, -0.1));
		SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	if (minZPlayer <= GetPosition().GetZ() && maxZPlayer >= GetPosition().GetZ())
	{

		if (minXPlayer >= GetPosition().GetX())
		{
			SetSpeed(Vector3D(0.1, 0.0, 0.0));
			SetOrientation(Vector3D(0.0, 90.0, 0.0));
		}
		else if (maxXPlayer <= GetPosition().GetX())
		{
			SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			SetOrientation(Vector3D(0.0, 270.0, 0.0));
		}
	}
}