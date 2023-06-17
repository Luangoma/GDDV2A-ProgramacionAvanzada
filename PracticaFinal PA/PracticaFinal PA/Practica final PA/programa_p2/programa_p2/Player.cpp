#include "Player.h"

void Player::Render()
{
	modelo.Render();
}

void Player::Update(const float &timeIncrement)
{
	SetPosition(modelo.GetPosition());
	SetOrientation(modelo.GetOrientation());
	modelo.Update(timeIncrement);
}

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'W':
	case 'w':
		// mover el personajeActivo hacia adelante
		modelo.SetSpeed(Vector3D(0.0, 0.0, -speed));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 'S':
	case 's':
		// mover el personajeActivo hacia atras
		modelo.SetSpeed(Vector3D(0.0, 0.0, speed));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'A':
	case 'a':
		// mover el personajeActivo hacia la izquierda
		modelo.SetSpeed(Vector3D(-speed, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'D':
	case 'd':
		// mover el personajeActivo hacia la derecha
		modelo.SetSpeed(Vector3D(speed, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	/**/
	case 'Z':
	case 'z':
		ActivarRalenti();
		break;
	case 'X':
	case 'x':
		ActivarNormal();
		break;
	case 'C':
	case 'c':
		ActivarAccelere();
		break;
	//*/
	default:
		// modelo.SetSpeed(Vector3D(0.0, 0.0, 0.0));
		break;
	}
}

void Player::Reset()
{
	modelo.SetPosition(position);
	modelo.SetOrientation(rotation);
	modelo.SetSpeed(Vector3D(0, 0, 0));
}

Vector3D Player::GetDimensions()
{
	Vector3D *dimensiones = new Vector3D(1.78, 1.13, 3.73);
	if (GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensiones->SetZ(dimensiones->GetZ());
		dimensiones->SetX(dimensiones->GetX());
	}
	else if (GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensiones->SetZ(dimensiones->GetZ());
		dimensiones->SetX(dimensiones->GetX());
	}
	else if (GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensiones->SetZ(dimensiones->GetX());
		dimensiones->SetX(dimensiones->GetZ());
	}
	else if (GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensiones->SetZ(dimensiones->GetX());
		dimensiones->SetX(dimensiones->GetZ());
	}
	return *dimensiones;
}

void Player::ActivarRalenti()
{
	modelo.SetSpeed(Vector3D(
		modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed / 2 : -speed / 2),
		modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed / 2 : -speed / 2),
		modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed / 2 : -speed / 2)));
}

void Player::ActivarAccelere()
{
	modelo.SetSpeed(Vector3D(
		modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed * 2 : -speed * 2),
		modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed * 2 : -speed * 2),
		modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed * 2 : -speed * 2)));
}

void Player::ActivarNormal()
{
	modelo.SetSpeed(Vector3D(
		modelo.GetSpeed().GetX() == 0 ? 0.0 : (modelo.GetSpeed().GetX() > 0 ? speed : -speed),
		modelo.GetSpeed().GetY() == 0 ? 0.0 : (modelo.GetSpeed().GetY() > 0 ? speed : -speed),
		modelo.GetSpeed().GetZ() == 0 ? 0.0 : (modelo.GetSpeed().GetZ() > 0 ? speed : -speed)));
}