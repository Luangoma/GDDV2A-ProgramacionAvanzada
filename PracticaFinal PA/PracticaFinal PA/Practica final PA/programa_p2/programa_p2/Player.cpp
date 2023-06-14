#include "Player.h"

void Player::Render() 
{
    modelo.Render();
}

void Player::Update(const float& timeIncrement)
{
    modelo.Update(timeIncrement);
}

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'w':
		// mover el personajeActivo hacia adelante
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 's':
		// mover el personajeActivo hacia atras
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'a':
		// mover el personajeActivo hacia la izquierda
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'd':
		// mover el personajeActivo hacia la derecha
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	case 'W':
		// mover el objeto hacia adelante
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 'S':
		// mover el personajeActivo hacia atras
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'A':
		// mover el personajeActivo hacia la izquierda
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'D':
		// mover el personajeActivo hacia la derecha
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	default:
		//SetSpeed(Vector3D(0.0, 0.0, 0.0));
		break;
	}
}

void Player::Reset()
{
    modelo.SetPosition(GetPosition());
	modelo.SetOrientation(GetOrientation());
	modelo.SetSpeed(Vector3D(0, 0, 0));
}