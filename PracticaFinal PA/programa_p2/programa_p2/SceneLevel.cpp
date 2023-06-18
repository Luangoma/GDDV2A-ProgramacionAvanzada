#include "SceneLevel.h"
#include <iostream>
#include "Enemy.h"
#include "Obstacle.h"
#include "Ralenti.h"

void SceneLevel::Init()
{
	Scene::Init();

	std::cout << "Carga de la escena " << nivel << std::endl << std::endl;

	// // // // Escena
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(50 * nivel, 50 * nivel, 100));

	// CAMARA EN CENITAL (60 grados)
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(0, 2 + (3.75 * (nivel - 1)), 20 + (7.5 * (nivel - 1))));
	camara->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	SetCamera(*camara);

	// Creacion de nivel
	const int mode = 1 + (nivel * 2);
	desplazamiento = 0.0;
	incremento = 6.0;
	for (int i = 0; i < mode; i++) // Creamos las vias y los trenes y las añadimos
	{
		via = new Model();
		*via = loaderVias->GetModel();
		via->SetPosition(Vector3D(via->GetPosition().GetX(), via->GetPosition().GetY(), via->GetPosition().GetZ() - desplazamiento));
		via->PaintColor(Color(0.3, 0.3, 0.3));
		AddVia(via);
		AddGameObject(vias[i]);
		desplazamiento += incremento;

		// Posicion Inicial Aleatoria
		float randomX = (rand() % int(GetBoundary().GetX()));
		
		if (nivel == 1)
		{
			obstaculo = new Obstacle(
				loaderLvl1->GetModel(),							// Modelo
				Vector3D(randomX, 1.7, -incremento * i),		// Posicion
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0),	// Rotacion
				Vector3D(37.1, 3.58, 2.87),						// Dimensiones
				Color(0.1, 0.1, 0.1),							// Color
				(i % 2 == 0) ? 0.1 : -0.1);						// Velocidad
		}
		else if (nivel == 2)
		{
			obstaculo = new Obstacle(
				loaderLvl2->GetModel(),							// Modelo
				Vector3D(randomX, 1.1, -incremento * i),		// Posicion
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0), // Rotacion
				Vector3D(66.7, 2.72, 2.25),						// Dimensiones
				Color(0.73, 0.56, 0.1),							// Color
				(i % 2 == 0) ? 0.3 : -0.3);						// Velocidad
		}
		else
		{
			obstaculo = new Obstacle(
				loaderLvl3->GetModel(),							// Modelo
				Vector3D(randomX, 1.0, -incremento * i),		// Posicion
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0),	// Rotacion
				Vector3D(90.5, 1.9, 2.03),						// Dimensiones
				Color(0.4, 0.4, 0.4),							// Color
				(i % 2 == 0) ? 1 : -1);							// Velocidad
		}
		AddObstaculo(obstaculo);
		AddGameObject(obstaculo);
	}
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(GetBoundary().GetX() * 2 * nivel);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	AddGameObject(meta);
	SetMeta(meta);

	// Personaje
	jugador = new Player(loaderPersonaje->GetModel(), 
		Vector3D(0.0, 0.5, 5.0));
	AddGameObject(jugador);

	// Enemigo
	enemigo = new Enemy(loaderPersonaje->GetModel(), 
		jugador, 
		Vector3D(GetBoundary().GetX() / 3, 0.5, GetBoundary().GetZ() / 3));
	AddGameObject(enemigo);

	//PowerUPs
	/**
	fastUp = new Accelere(loaderPower->GetModel(), jugador);
	AddPowerUp(fastUp);
	AddGameObject(fastUp);
	slowUp = new Accelere(loaderPower->GetModel(), obstaculos);
	AddPowerUp(slowUp);
	AddGameObject(slowUp);
	//*/
}

void SceneLevel::CheckBoundary()
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		if (this->gameObjects[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->gameObjects[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			this->gameObjects[idx]->SetPosition(
				Vector3D(-1 * this->gameObjects[idx]->GetPosition().GetX(),
						 this->gameObjects[idx]->GetPosition().GetY(),
						 this->gameObjects[idx]->GetPosition().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetY() < -(this->boundary.GetY()) || this->gameObjects[idx]->GetPosition().GetY() > this->boundary.GetY())
		{
			this->gameObjects[idx]->SetSpeed(
				Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
						 -1 * this->gameObjects[idx]->GetSpeed().GetY(),
						 this->gameObjects[idx]->GetSpeed().GetZ()));
		}

		if (this->gameObjects[idx]->GetPosition().GetZ() < -(this->boundary.GetZ()) || this->gameObjects[idx]->GetPosition().GetZ() > this->boundary.GetZ())
		{
			this->gameObjects[idx]->SetSpeed(
				Vector3D(this->gameObjects[idx]->GetSpeed().GetX(),
						 this->gameObjects[idx]->GetSpeed().GetY(),
						 -1 * this->gameObjects[idx]->GetSpeed().GetZ()));
		}
	}

	// Cuando llegan los trenes al boundary, se generan nuevas posiciones aleatorias.
	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		float randomX = ((rand() % int(boundary.GetX() / 2) + boundary.GetX() / 4) + int(boundary.GetX() / 2) + 5);
		if (idx % 2 == 0)
		{
			randomX = -randomX;
		}
		if (this->obstaculos[idx]->GetPosition().GetX() < -(this->boundary.GetX()) ||
			this->obstaculos[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			std::cout << "Variando: " << randomX << std::endl;
			this->obstaculos[idx]->Repositioning(Vector3D(randomX, obstaculos[idx]->GetPosition().GetY(), obstaculos[idx]->GetPosition().GetZ()));
		}
	}
	//*/
}

void SceneLevel::CheckColisiones()
{
	// // // Colisiones con los obstaculos
	Vector3D dimensionesPersonaje = jugador->GetDimensions();
	float minXPersonaje, maxXPersonaje, minYPersonaje, maxYPersonaje, minZPersonaje, maxZPersonaje;
	minXPersonaje = this->jugador->GetPosition().GetX() - dimensionesPersonaje.GetX() / 2;
	maxXPersonaje = this->jugador->GetPosition().GetX() + dimensionesPersonaje.GetX() / 2;
	minYPersonaje = this->jugador->GetPosition().GetY();
	maxYPersonaje = this->jugador->GetPosition().GetY() + dimensionesPersonaje.GetY();
	minZPersonaje = this->jugador->GetPosition().GetZ() - dimensionesPersonaje.GetZ() / 2;
	maxZPersonaje = this->jugador->GetPosition().GetZ() + dimensionesPersonaje.GetZ() / 2;

	for (int i = 0; i < this->obstaculos.size(); i++)
	{
		// Dimensiones del personaje.
		Vector3D dimensionesTren = this->obstaculos[i]->GetDimensions();
		float minXTren, maxXTren, minYTren, maxYTren, minZTren, maxZTren;
		minXTren = this->obstaculos[i]->GetPosition().GetX() - dimensionesTren.GetX() / 2;
		maxXTren = this->obstaculos[i]->GetPosition().GetX() + dimensionesTren.GetX() / 2;
		minYTren = this->obstaculos[i]->GetPosition().GetY();
		maxYTren = this->obstaculos[i]->GetPosition().GetY() + dimensionesTren.GetY();
		minZTren = this->obstaculos[i]->GetPosition().GetZ() - dimensionesTren.GetZ() / 2;
		maxZTren = this->obstaculos[i]->GetPosition().GetZ() + dimensionesTren.GetZ() / 2;

		if (((minXPersonaje <= maxXTren && minXPersonaje >= minXTren) ||
			(maxXPersonaje <= maxXTren && maxXPersonaje >= minXTren)) &&
			((minZPersonaje <= maxZTren && minZPersonaje >= minZTren) ||
			(maxZPersonaje <= maxZTren && maxZPersonaje >= minZTren)))
		{
			jugador->SetStatus(false);
			this->activo = false;
			std::cout << "Ha colisionado." << std::endl;
		}
	}
	
	// DETECTAR COLISIONES CON EL ENEMIGO
	Vector3D dimensionesEnemy = enemigo->GetDimensions();
	float minXEnemy, maxXEnemy, minYEnemy, maxYEnemy, minZEnemy, maxZEnemy;
	minXEnemy = this->enemigo->GetPosition().GetX() - dimensionesEnemy.GetX() / 2;
	maxXEnemy = this->enemigo->GetPosition().GetX() + dimensionesEnemy.GetX() / 2;
	minYEnemy = this->enemigo->GetPosition().GetY();
	maxYEnemy = this->enemigo->GetPosition().GetY() + dimensionesEnemy.GetY();
	minZEnemy = this->enemigo->GetPosition().GetZ() - dimensionesEnemy.GetZ() / 2;
	maxZEnemy = this->enemigo->GetPosition().GetZ() + dimensionesEnemy.GetZ() / 2;

	if (((minXPersonaje <= maxXEnemy && minXPersonaje >= minXEnemy) || 
		(maxXPersonaje <= maxXEnemy && maxXPersonaje >= minXEnemy)) &&
		((minZPersonaje <= maxZEnemy && minZPersonaje >= minZEnemy) || 
		(maxZPersonaje <= maxZEnemy && maxZPersonaje >= minZEnemy)))
		{
			jugador->SetStatus(false);
			this->activo = false;
			std::cout << "Ha colisionado." << std::endl;
		}

	for (int i = 0; i < this->powerups.size(); i++)
	{
		if (minXPersonaje <= this->powerups[i]->GetPosition().GetX() && 
			maxXPersonaje >= this->powerups[i]->GetPosition().GetX() &&
			minZPersonaje <= this->powerups[i]->GetPosition().GetZ() && 
			maxZPersonaje >= this->powerups[i]->GetPosition().GetZ())
		{
		powerups[i]->ApplyEffect();
		}
	}

	float zMeta = this->meta->GetPosition().GetZ();
	if ((zMeta >= minZPersonaje) || (zMeta >= maxZPersonaje))
	{
		this->activo = false;
		this->jugador->SetSpeed(Vector3D(0.0, 0.0, 0.0));
		estadoPartida = true;
	}
}

void SceneLevel::Update(const float &timeIncrement)
{
	Scene::Update(timeIncrement);
	this->CheckBoundary();
	this->CheckColisiones();
}

void SceneLevel::ProcessKeyPressed(unsigned char key, int px, int py)
{
	if (activo)
	{
		jugador->ProcessKeyPressed(key, px, py);
	}
}

int SceneLevel::CheckStatus()
{
	// Devuelve un 0 si no pasa nada, un 1 si ha ganado y un 2 si ha perdido,
	// para poder cambiar a las escenas de Game Over en Game.cpp.
	/**/
	if (jugador->GetStatus())
	{
		if (estadoPartida)
		{
		return 1;
		}
		else
		{
		return 0;
		}
	}
	else
	{
		return 2;
	}
}

void SceneLevel::Reset()
{
	this->estadoPartida = false;
	this->activo = true;
	this->jugador->Reset();
	this->enemigo->Reset();
	for (Obstacle* obstaculo : obstaculos)
	{
		obstaculo->Reset();
	}	
	for (PowerUp* power : powerups)
	{
		power->Reset();
	}
}
