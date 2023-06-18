#include "Enemy.h"

void Enemy::Update(const float &timeIncrement)
{
	TrackPlayer();
	Vehicle::Update(timeIncrement);
}

void Enemy::TrackPlayer()
{

	// La x, y & z del personaje estan en su centro, menos la z que esta en el suelo.
	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DEL SEGUIMIENTO.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	
	Vector3D dimensionesPlayer = player->GetDimensions();
	/**
	if (player->GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesPlayer->SetZ(dimensionesPlayer->GetZ());
		dimensionesPlayer->SetX(dimensionesPlayer->GetX());
	}
	else if (player->GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesPlayer->SetZ(dimensionesPlayer->GetZ());
		dimensionesPlayer->SetX(dimensionesPlayer->GetX());
	}
	else if (player->GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesPlayer->SetZ(dimensionesPlayer->GetX());
		dimensionesPlayer->SetX(dimensionesPlayer->GetZ());
	}
	else if (player->GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesPlayer->SetZ(dimensionesPlayer->GetX());
		dimensionesPlayer->SetX(dimensionesPlayer->GetZ());
	}
	//*/
	float minXPlayer, maxXPlayer, minYPlayer, maxYPlayer, minZPlayer, maxZPlayer;
	minXPlayer = this->player->GetPosition().GetX() - dimensionesPlayer.GetX() / 2;
	maxXPlayer = this->player->GetPosition().GetX() + dimensionesPlayer.GetX() / 2;
	minYPlayer = this->player->GetPosition().GetY();
	maxYPlayer = this->player->GetPosition().GetY() + dimensionesPlayer.GetY();
	minZPlayer = this->player->GetPosition().GetZ() - dimensionesPlayer.GetZ() / 2;
	maxZPlayer = this->player->GetPosition().GetZ() + dimensionesPlayer.GetZ() / 2;

	/**
	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DEL SEGUIMIENTO.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	Vector3D *dimensionesEnemy = new Vector3D(1.78, 1.13, 3.73);
	if (GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesEnemy->SetZ(3.73);
		dimensionesEnemy->SetX(1.78);
	}
	else if (GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesEnemy->SetZ(3.73);
		dimensionesEnemy->SetX(1.78);
	}
	else if (GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesEnemy->SetZ(1.78);
		dimensionesEnemy->SetX(3.73);
	}
	else if (GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesEnemy->SetZ(1.78);
		dimensionesEnemy->SetX(3.73);
	}

	float minXEnemy, maxXEnemy, minYEnemy, maxYEnemy, minZEnemy, maxZEnemy;
	minXEnemy = GetPosition().GetX() - dimensionesEnemy->GetX() / 2;
	maxXEnemy = GetPosition().GetX() + dimensionesEnemy->GetX() / 2;
	minYEnemy = GetPosition().GetY();
	maxYEnemy = GetPosition().GetY() + dimensionesEnemy->GetY();
	minZEnemy = GetPosition().GetZ() - dimensionesEnemy->GetZ() / 2;
	maxZEnemy = GetPosition().GetZ() + dimensionesEnemy->GetZ() / 2;
	//*/
	// Logica de seguimiento
	// Logica priorizando la posicion en el eje Y
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
	/**
	// Logica de seguimiento
	// Logica priorizando la posicion en el eje X
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
	if (minXPlayer <= GetPosition().GetX() && maxXPlayer >= GetPosition().GetX())
	{
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
	}
	//*/
	/**
	if ((minXPlayer <= GetPosition().GetX() && maxXPlayer >= GetPosition().GetX()) || (maxXPlayer <= GetPosition().GetX() && maxXPlayer >= GetPosition().GetX()))
	{
		if (minXPlayer <= GetPosition().GetX() && minXPlayer >= GetPosition().GetX())
		{
			SetSpeed(Vector3D(0.1, 0.0, 0.0));
			SetOrientation(Vector3D(0.0, 90.0, 0.0));
		}
		else if (maxXPlayer <= GetPosition().GetX() && maxXPlayer >= GetPosition().GetX())
		{
			SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			SetOrientation(Vector3D(0.0, 270.0, 0.0));
		}
		if ((minZPlayer <= GetPosition().GetZ() && minZPlayer >= GetPosition().GetZ()) || (maxZPlayer <= GetPosition().GetZ() && maxZPlayer >= GetPosition().GetZ()))
		{
			if (minZPlayer <= GetPosition().GetZ() && minZPlayer >= GetPosition().GetZ())
			{
				SetSpeed(Vector3D(0.0, 0.0, 0.1));
				SetOrientation(Vector3D(0.0, 180.0, 0.0));
			}
			else if (maxZPlayer <= GetPosition().GetZ() && maxZPlayer >= GetPosition().GetZ())
			{
				SetSpeed(Vector3D(0.0, 0.0, -0.1));
				SetOrientation(Vector3D(0.0, 0.0, 0.0));
			}
		}
	}


	if (GetPosition().GetX() < personaje.GetPosition().GetX())	// Abajo
	{
		SetSpeed(Vector3D(0.0, 0.0, 0.1));
		SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (GetPosition().GetX() > personaje.GetPosition().GetX())	// Arriba
	{
		SetSpeed(Vector3D(0.0, 0.0, -0.1));
		SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	else if (GetPosition().GetY() < personaje.GetPosition().GetY())	// Derecha
	{
		SetSpeed(Vector3D(0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 270.0, 0.0));
	}
	else if (GetPosition().GetY() > personaje.GetPosition().GetY())	// Izquierda
	{
		SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		SetOrientation(Vector3D(0.0, 90.0, 0.0));
	}
	//*/
}