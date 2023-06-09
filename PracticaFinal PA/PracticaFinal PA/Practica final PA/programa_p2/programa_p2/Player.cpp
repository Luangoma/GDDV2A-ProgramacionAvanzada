#include "Player.h"

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'w':
		// mover el personajeActivo hacia adelante
		SetSpeed(Vector3D(0.0, 0.0, -0.1));
		SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 's':
		// mover el personajeActivo hacia atras
		SetSpeed(Vector3D(0.0, 0.0, 0.1));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'a':
		// mover el personajeActivo hacia la izquierda
		SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'd':
		// mover el personajeActivo hacia la derecha
		SetSpeed(Vector3D(0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	case 'W':
		// mover el objeto hacia adelante
		SetSpeed(Vector3D(0.0, 0.0, -0.1));
		SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 'S':
		// mover el personajeActivo hacia atras
		SetSpeed(Vector3D(0.0, 0.0, 0.1));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'A':
		// mover el personajeActivo hacia la izquierda
		SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'D':
		// mover el personajeActivo hacia la derecha
		SetSpeed(Vector3D(0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	default:
        //SetSpeed(Vector3D(0.0, 0.0, 0.0));
		break;
	}
}

void Player::Parar()
{
	SetSpeed(Vector3D(0.0, 0.0, 0.0));
}

void Player::Reset()
{
	SetPosition(Vector3D(0, 0.5, 5));
	SetOrientation(Vector3D(0, 180, 0));
	Parar();
}

void Player::PaintPlayer(const Color& color)
{
	this->modelo.PaintColor(color);
}

void Player::Render()
{
	this->modelo.Render();
}

void Player::Update(const float& timeIncrement)
{

}