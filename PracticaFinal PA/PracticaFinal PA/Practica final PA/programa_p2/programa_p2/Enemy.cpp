#include "Enemy.h"

void Enemy::Render()
{
	modelo.Render();
}

void Enemy::Update(const float &timeIncrement)
{
	// La x, y & z del personaje estan en su centro, menos la z que esta en el suelo.
	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DEL SEGUIMIENTO.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	Vector3D *dimensionesPlayer = new Vector3D(1.78, 1.13, 3.73);
	if (player->GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesPlayer->SetZ(3.73);
		dimensionesPlayer->SetX(1.78);
	}
	else if (player->GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesPlayer->SetZ(3.73);
		dimensionesPlayer->SetX(1.78);
	}
	else if (player->GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesPlayer->SetZ(1.78);
		dimensionesPlayer->SetX(3.73);
	}
	else if (player->GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesPlayer->SetZ(1.78);
		dimensionesPlayer->SetX(3.73);
	}

	float minXPlayer, maxXPlayer, minYPlayer, maxYPlayer, minZPlayer, maxZPlayer;
	minXPlayer = this->player->GetPosition().GetX() - dimensionesPlayer->GetX() / 2;
	maxXPlayer = this->player->GetPosition().GetX() + dimensionesPlayer->GetX() / 2;
	minYPlayer = this->player->GetPosition().GetY();
	maxYPlayer = this->player->GetPosition().GetY() + dimensionesPlayer->GetY();
	minZPlayer = this->player->GetPosition().GetZ() - dimensionesPlayer->GetZ() / 2;
	maxZPlayer = this->player->GetPosition().GetZ() + dimensionesPlayer->GetZ() / 2;

	/**
	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DEL SEGUIMIENTO.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	Vector3D *dimensionesEnemy = new Vector3D(1.78, 1.13, 3.73);
	if (modelo.GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesEnemy->SetZ(3.73);
		dimensionesEnemy->SetX(1.78);
	}
	else if (modelo.GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesEnemy->SetZ(3.73);
		dimensionesEnemy->SetX(1.78);
	}
	else if (modelo.GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesEnemy->SetZ(1.78);
		dimensionesEnemy->SetX(3.73);
	}
	else if (modelo.GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesEnemy->SetZ(1.78);
		dimensionesEnemy->SetX(3.73);
	}

	float minXEnemy, maxXEnemy, minYEnemy, maxYEnemy, minZEnemy, maxZEnemy;
	minXEnemy = modelo.GetPosition().GetX() - dimensionesEnemy->GetX() / 2;
	maxXEnemy = modelo.GetPosition().GetX() + dimensionesEnemy->GetX() / 2;
	minYEnemy = modelo.GetPosition().GetY();
	maxYEnemy = modelo.GetPosition().GetY() + dimensionesEnemy->GetY();
	minZEnemy = modelo.GetPosition().GetZ() - dimensionesEnemy->GetZ() / 2;
	maxZEnemy = modelo.GetPosition().GetZ() + dimensionesEnemy->GetZ() / 2;
	//*/
	// Logica de seguimiento
	// Logica priorizando la posicion en el eje Y
	if (minZPlayer >= modelo.GetPosition().GetZ())
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (maxZPlayer <= modelo.GetPosition().GetZ())
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	if (minZPlayer <= modelo.GetPosition().GetZ() && maxZPlayer >= modelo.GetPosition().GetZ())
	{

		if (minXPlayer >= modelo.GetPosition().GetX())
		{
			modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
			modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		}
		else if (maxXPlayer <= modelo.GetPosition().GetX())
		{
			modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		}
	}
	/**
	// Logica de seguimiento
	// Logica priorizando la posicion en el eje X
	if (minXPlayer >= modelo.GetPosition().GetX())
	{
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
	}
	else if (maxXPlayer <= modelo.GetPosition().GetX())
	{
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
	}
	if (minXPlayer <= modelo.GetPosition().GetX() && maxXPlayer >= modelo.GetPosition().GetX())
	{
		if (minZPlayer >= modelo.GetPosition().GetZ())
		{
			modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
			modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		}
		else if (maxZPlayer <= modelo.GetPosition().GetZ())
		{
			modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
			modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		}
	}
	//*/
	/**
	if ((minXPlayer <= modelo.GetPosition().GetX() && maxXPlayer >= modelo.GetPosition().GetX()) || (maxXPlayer <= modelo.GetPosition().GetX() && maxXPlayer >= modelo.GetPosition().GetX()))
	{
		if (minXPlayer <= modelo.GetPosition().GetX() && minXPlayer >= modelo.GetPosition().GetX())
		{
			modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
			modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		}
		else if (maxXPlayer <= modelo.GetPosition().GetX() && maxXPlayer >= modelo.GetPosition().GetX())
		{
			modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		}
		if ((minZPlayer <= modelo.GetPosition().GetZ() && minZPlayer >= modelo.GetPosition().GetZ()) || (maxZPlayer <= modelo.GetPosition().GetZ() && maxZPlayer >= modelo.GetPosition().GetZ()))
		{
			if (minZPlayer <= modelo.GetPosition().GetZ() && minZPlayer >= modelo.GetPosition().GetZ())
			{
				modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
				modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
			}
			else if (maxZPlayer <= modelo.GetPosition().GetZ() && maxZPlayer >= modelo.GetPosition().GetZ())
			{
				modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
				modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
			}
		}
	}


	if (modelo.GetPosition().GetX() < personaje.GetPosition().GetX())	// Abajo
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (modelo.GetPosition().GetX() > personaje.GetPosition().GetX())	// Arriba
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() < personaje.GetPosition().GetY())	// Derecha
	{
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() > personaje.GetPosition().GetY())	// Izquierda
	{
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
	}
	//*/
	modelo.Update(timeIncrement);
}

void Enemy::Reset()
{
	modelo.SetPosition(position);
}