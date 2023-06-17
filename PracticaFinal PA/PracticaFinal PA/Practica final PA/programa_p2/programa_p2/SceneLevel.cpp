#include "SceneLevel.h"
#include <iostream>
#include "Enemy.h"
#include "Obstacle.h"

void SceneLevel::Init()
{
	Scene::Init();

	std::cout << "Carga de la escena " << nivel << std::endl
			  << std::endl;
	// // // // Escena
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(50 * nivel, 50 * nivel, 100));
	// CAMARA EN CENITAL (60 grados)
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(0, 2 + (3.75 * (nivel - 1)), 20 + (7.5 * (nivel - 1))));
	camara->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	SetCamera(*camara);
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

		tren = new Model();
		if (nivel == 1)
		{
			/**
			*tren = loaderLvl1->GetModel();
			tren->SetPosition(Vector3D(randomX, 1.7, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.1, 0.1, 0.1));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 0.1 : -0.1, 0.0, 0.0));
			/**/
			obstaculo = new Obstacle(
				loaderLvl1->GetModel(),
				Vector3D(randomX, 1.7, -incremento * i),
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0),
				Color(0.1, 0.1, 0.1),
				Vector3D((i % 2 == 0) ? 0.1 : -0.1, 0.0, 0.0));
			//*/
		}
		else if (nivel == 2)
		{
			/**
			*tren = loaderLvl2->GetModel();
			tren->SetPosition(Vector3D(randomX, 1.1, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.73, 0.56, 0.1));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 0.3 : -0.3, 0.0, 0.0));
			/**/
			obstaculo = new Obstacle(
				loaderLvl2->GetModel(),
				Vector3D(randomX, 1.1, -incremento * i),
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0),
				Color(0.73, 0.56, 0.1),
				Vector3D((i % 2 == 0) ? 0.3 : -0.3, 0.0, 0.0));
			//*/
		}
		else
		{
			/**
			*tren = loaderLvl3->GetModel();
			tren->SetPosition(Vector3D(randomX, 1, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.4, 0.4, 0.4));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 1 : -1, 0.0, 0.0));
			/**/
			obstaculo = new Obstacle(
				loaderLvl3->GetModel(),
				Vector3D(randomX, 1, -incremento * i),
				Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0),
				Color(0.4, 0.4, 0.4),
				Vector3D((i % 2 == 0) ? 1 : -1, 0.0, 0.0));
			//*/
		}
		/**
		AddObstaculo(tren);
		AddGameObject(tren);
		/**/
		AddObstaculo(obstaculo);
		AddGameObject(obstaculo);
		//*/
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
	jugador = new Player(loaderPersonaje->GetModel(), Vector3D(0.0, 0.5, 5.0));
	AddGameObject(jugador);

	// Enemigo
	enemigo = new Enemy(loaderPersonaje->GetModel(), jugador, Vector3D(GetBoundary().GetX() / 3, 0.5, GetBoundary().GetZ() / 3));
	AddGameObject(enemigo);
	//*/
}

void SceneLevel::checkBoundary()
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
	/**/
	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		float randomX = ((rand() % int(boundary.GetX() / 2) + boundary.GetX() / 4) + int(boundary.GetX() / 2) + 5);
		if (idx % 2 == 0)
		{
			randomX = -randomX;
		}
		if (this->obstaculos[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->obstaculos[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			std::cout << "Variando: " << randomX << std::endl;
			// this->obstaculos[idx]->SetPosition(Vector3D(randomX,obstaculos[idx]->GetPosition().GetY(),obstaculos[idx]->GetPosition().GetZ()));
			this->obstaculos[idx]->Repositioning(Vector3D(randomX, obstaculos[idx]->GetPosition().GetY(), obstaculos[idx]->GetPosition().GetZ()));
		}
	}
	//*/
}

void SceneLevel::checkColisiones()
{

	/**
	Vector3D *dimensionesPersonaje = new Vector3D(1.78, 1.13, 3.73);
	// La x, y & z del personaje estan en su centro, menos la z que est� en el suelo.

	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DE LAS COLISIONES.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	if (jugador->GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesPersonaje->SetZ(dimensionesPersonaje->GetZ());
		dimensionesPersonaje->SetX(dimensionesPersonaje->GetX());
	}
	else if (jugador->GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesPersonaje->SetZ(dimensionesPersonaje->GetZ());
		dimensionesPersonaje->SetX(dimensionesPersonaje->GetX());
	}
	else if (jugador->GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesPersonaje->SetZ(dimensionesPersonaje->GetX());
		dimensionesPersonaje->SetX(dimensionesPersonaje->GetZ());
	}
	else if (jugador->GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesPersonaje->SetZ(dimensionesPersonaje->GetX());
		dimensionesPersonaje->SetX(dimensionesPersonaje->GetZ());
	}
	//*/
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

		Vector3D *dimensionesTren;

		// CAMBIAR LAS DIMENSIONES DEL TREN DEPENDIENDO DEL NIVEL.
		// Cada nivel tiene un tren con dimensiones diferentes.
		if (nivel == 1)
		{
			dimensionesTren = new Vector3D(37.1, 3.58, 2.87);
		}
		else if (nivel == 2)
		{
			dimensionesTren = new Vector3D(66.7, 2.72, 2.25);
		}
		else
		{
			// dimensionesTren = new Vector3D(90.5, 1.9, 2.03);
			dimensionesTren = new Vector3D(90.5, 1.9, 2.03);
		}

		float minXTren, maxXTren, minYTren, maxYTren, minZTren, maxZTren;
		minXTren = this->obstaculos[i]->GetPosition().GetX() - dimensionesTren->GetX() / 2;
		maxXTren = this->obstaculos[i]->GetPosition().GetX() + dimensionesTren->GetX() / 2;
		minYTren = this->obstaculos[i]->GetPosition().GetY();
		maxYTren = this->obstaculos[i]->GetPosition().GetY() + dimensionesTren->GetY();
		minZTren = this->obstaculos[i]->GetPosition().GetZ() - dimensionesTren->GetZ() / 2;
		maxZTren = this->obstaculos[i]->GetPosition().GetZ() + dimensionesTren->GetZ() / 2;

		// DETECTAR COLISIONES
		bool colisiono = false;
		if ((minXPersonaje <= maxXTren && minXPersonaje >= minXTren) || (maxXPersonaje <= maxXTren && maxXPersonaje >= minXTren))
		{
			// Colisión en eI eje X
			colisiono = true;
			if ((minZPersonaje <= maxZTren && minZPersonaje >= minZTren) || (maxZPersonaje <= maxZTren && maxZPersonaje >= minZTren))
			{
				// Colisión en eI eje Z
				colisiono = true;
				if (colisiono)
				{
					// Ha colisionado
					std::cout << "Ha colisionado." << std::endl;
					haPerdido();
					this->activo = false;
				}
			}
		}
	}
	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DEL SEGUIMIENTO.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	Vector3D *dimensionesEnemy = new Vector3D(1.78, 1.13, 3.73);
	if (enemigo->GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesEnemy->SetZ(dimensionesEnemy->GetZ());
		dimensionesEnemy->SetX(dimensionesEnemy->GetX());
	}
	else if (enemigo->GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesEnemy->SetZ(dimensionesEnemy->GetZ());
		dimensionesEnemy->SetX(dimensionesEnemy->GetX());
	}
	else if (enemigo->GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesEnemy->SetZ(dimensionesEnemy->GetX());
		dimensionesEnemy->SetX(dimensionesEnemy->GetZ());
	}
	else if (enemigo->GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesEnemy->SetZ(dimensionesEnemy->GetX());
		dimensionesEnemy->SetX(dimensionesEnemy->GetZ());
	}

	float minXEnemy, maxXEnemy, minYEnemy, maxYEnemy, minZEnemy, maxZEnemy;
	minXEnemy = this->enemigo->GetPosition().GetX() - dimensionesEnemy->GetX() / 2;
	maxXEnemy = this->enemigo->GetPosition().GetX() + dimensionesEnemy->GetX() / 2;
	minYEnemy = this->enemigo->GetPosition().GetY();
	maxYEnemy = this->enemigo->GetPosition().GetY() + dimensionesEnemy->GetY();
	minZEnemy = this->enemigo->GetPosition().GetZ() - dimensionesEnemy->GetZ() / 2;
	maxZEnemy = this->enemigo->GetPosition().GetZ() + dimensionesEnemy->GetZ() / 2;

	bool colisiono = false;
	if ((minXPersonaje <= maxXEnemy && minXPersonaje >= minXEnemy) || (maxXPersonaje <= maxXEnemy && maxXPersonaje >= minXEnemy))
	{
		// Colisión en eI eje X
		colisiono = true;
		if ((minZPersonaje <= maxZEnemy && minZPersonaje >= minZEnemy) || (maxZPersonaje <= maxZEnemy && maxZPersonaje >= minZEnemy))
		{
			// Colisión en eI eje Z
			colisiono = true;
			if (colisiono)
			{
				// Ha colisionado
				std::cout << "Ha colisionado." << std::endl;
				haPerdido();
				this->activo = false;
			}
		}
	}
	float zMeta = this->meta->GetPosition().GetZ();
	if ((zMeta >= minZPersonaje) || (zMeta >= maxZPersonaje))
	{
		this->activo = false;
		haGanado();
	}
}

void SceneLevel::haPerdido()
{
	this->jugador->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	estadoPerder = true;

	/**
	Text* textoPerdido = new Text();
	Text* textoReiniciar = new Text();
	textoPerdido->SetText("HAS PERDIDO");
	textoReiniciar->SetText("PULSA 'R' PARA REINICIAR");
	if (nivel == 1)
	{
		textoPerdido->SetPosition(Vector3D(0, 4, 3));
		textoReiniciar->SetPosition(Vector3D(0, 4, 2));
	}
	else if (nivel == 2)
	{
		textoPerdido->SetPosition(Vector3D(0, 10, 3));
		textoReiniciar->SetPosition(Vector3D(0, 10, 2));
	}
	else if (nivel == 3)
	{
		textoPerdido->SetPosition(Vector3D(0, 15, 3));
		textoReiniciar->SetPosition(Vector3D(0, 15, 2));
	}
	textoPerdido->SetColor(Color(255, 0, 0));
	textoReiniciar->SetColor(Color(255, 0, 0));
	this->AddGameObject(textoPerdido);
	this->AddGameObject(textoReiniciar);
	//*/
}

void SceneLevel::haGanado()
{
	this->jugador->SetSpeed(Vector3D(0.0, 0.0, 0.0));
	estadoGanar = true;
	/**
	Text* textoGanado = new Text();
	textoGanado->SetText("HAS GANADO");
	if (nivel == 1)
	{
		textoGanado->SetPosition(Vector3D(0, 4, 3));
	}
	else if (nivel == 2)
	{
		textoGanado->SetPosition(Vector3D(0, 10, 3));
	}
	else
	{
		textoGanado->SetPosition(Vector3D(0, 15, 3));
	}
	textoGanado->SetColor(Color(255, 0, 0));
	this->AddGameObject(textoGanado);
	//*/
}

void SceneLevel::Update(const float &timeIncrement)
{
	Scene::Update(timeIncrement);
	this->checkBoundary();
	this->checkColisiones();
}

void SceneLevel::ProcessKeyPressed(unsigned char key, int px, int py)
{
	if (activo)
	{
		jugador->ProcessKeyPressed(key, px, py);
	}
	else
	{
		/**
		if (key == 'R' || key == 'r')
		{
			// REINICIAR EL JUEGO.
			this->estadoGanar = false;
			this->estadoPerder = false;
			this->activo = true;
			this->jugador->Reset();
		}
		//*/
	}
}

int SceneLevel::CheckStatus()
{
	// Devuelve un 0 si no pasa nada, un 1 si ha ganado y un 2 si ha perdido,
	// para poder cambiar a las escenas de Game Over en Game.cpp.
	if (estadoGanar)
	{
		return 1;
	}
	else if (estadoPerder)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

void SceneLevel::Reset()
{
	this->estadoGanar = false;
	this->estadoPerder = false;
	this->activo = true;
	this->jugador->Reset();
	this->enemigo->Reset();
	/**
	for (Obstacle *obstacul0 : obstaculos)
	{
		obstacul0->Reset();
	}
	for (int idx = 0; idx < this->obstaculos.size(); idx++)
	{
		float randomX = (rand() % int(GetBoundary().GetX()));
		if (idx % 2 == 0) { randomX = -randomX; }
		if (this->obstaculos[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->obstaculos[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			std::cout << "Reseteando / Variando: " << randomX << std::endl;
			// this->obstaculos[idx]->SetPosition(Vector3D(randomX,obstaculos[idx]->GetPosition().GetY(),obstaculos[idx]->GetPosition().GetZ()));
			this->obstaculos[idx]->Repositioning(Vector3D(randomX, obstaculos[idx]->GetPosition().GetY(), obstaculos[idx]->GetPosition().GetZ()));
		}
	}
	//*/
}
