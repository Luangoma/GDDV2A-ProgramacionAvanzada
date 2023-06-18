#include "Player.h"

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'W':
	case 'w':
		// mover el personajeActivo hacia adelante
		SetSpeed(Vector3D(0.0, 0.0, -GetActualSpeed()));
		SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 'S':
	case 's':
		// mover el personajeActivo hacia atras
		SetSpeed(Vector3D(0.0, 0.0, GetActualSpeed()));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'A':
	case 'a':
		// mover el personajeActivo hacia la izquierda
		SetSpeed(Vector3D(-GetActualSpeed(), 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'D':
	case 'd':
		// mover el personajeActivo hacia la derecha
		SetSpeed(Vector3D(GetActualSpeed(), 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	default:
		break;
	}
}

void Player::Reset()
{
	Vehicle::Reset();
	SetSpeed(Vector3D(0, 0, 0));
	SetStatus(true);
}
