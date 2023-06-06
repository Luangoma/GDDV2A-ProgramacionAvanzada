#include "SceneLevel.h"
#include <iostream>

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
			*tren = loaderLvl1->GetModel();
			tren->SetPosition(Vector3D(randomX, 1.7, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.1, 0.1, 0.1));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 0.1 : -0.1, 0.0, 0.0));
		}
		else if (nivel == 2)
		{
			*tren = loaderLvl2->GetModel();
			tren->SetPosition(Vector3D(randomX, 1.1, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.73, 0.56, 0.1));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 0.3 : -0.3, 0.0, 0.0));
		}
		else
		{
			*tren = loaderLvl3->GetModel();
			tren->SetPosition(Vector3D(randomX, 1, -incremento * i));
			tren->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
			tren->PaintColor(Color(0.4, 0.4, 0.4));
			tren->SetSpeed(Vector3D((i % 2 == 0) ? 1 : -1, 0.0, 0.0));
		}

		AddTren(tren);
		AddGameObject(tren);
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
	personaje->SetPosition(Vector3D(0, 0.5, 5));
	personaje->SetOrientation(Vector3D(0.0, 180.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	AddGameObject(personaje);
	AddPersonaje(personaje);
	//*/
}

void SceneLevel::checkBoundary()
{
	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		if (this->gameObjects[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->gameObjects[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			this->gameObjects[idx]->SetPosition(
				Vector3D(-gameObjects[idx]->GetPosition().GetX(),
						 gameObjects[idx]->GetPosition().GetY(),
						 gameObjects[idx]->GetPosition().GetZ()));
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
	for (int idx = 0; idx < this->trenes.size(); idx++)
	{
		float randomX = ((rand() % int(boundary.GetX() / 2) + boundary.GetX() / 4) + int(boundary.GetX() / 2) + 5);
		if (idx % 2 == 0)
		{
			randomX = -randomX;
		}
		if (this->trenes[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->trenes[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			std::cout << "Variando: " << randomX << std::endl;
			this->trenes[idx]->SetPosition(Vector3D(randomX, trenes[idx]->GetPosition().GetY(), trenes[idx]->GetPosition().GetZ()));
		}
	}
}

void SceneLevel::checkColisiones()
{

	Vector3D *dimensionesPersonaje = new Vector3D(1.78, 1.13, 3.73);
	// La x, y & z del personaje estan en su centro, menos la z que est� en el suelo.

	// COMPROBAR ROTACION DEL PERSONAJE PARA EL CALCULO DE LAS COLISIONES.
	// Cuando el personaje rota las dimension se intercambian entre los ejes X y Z.
	if (personajeActivo->GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensionesPersonaje->SetZ(3.73);
		dimensionesPersonaje->SetX(1.78);
	}
	else if (personajeActivo->GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensionesPersonaje->SetZ(3.73);
		dimensionesPersonaje->SetX(1.78);
	}
	else if (personajeActivo->GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensionesPersonaje->SetZ(1.78);
		dimensionesPersonaje->SetX(3.73);
	}
	else if (personajeActivo->GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensionesPersonaje->SetZ(1.78);
		dimensionesPersonaje->SetX(3.73);
	}

	float minXPersonaje, maxXPersonaje, minYPersonaje, maxYPersonaje, minZPersonaje, maxZPersonaje;
	minXPersonaje = this->personajeActivo->GetPosition().GetX() - dimensionesPersonaje->GetX() / 2;
	maxXPersonaje = this->personajeActivo->GetPosition().GetX() + dimensionesPersonaje->GetX() / 2;
	minYPersonaje = this->personajeActivo->GetPosition().GetY();
	maxYPersonaje = this->personajeActivo->GetPosition().GetY() + dimensionesPersonaje->GetY();
	minZPersonaje = this->personajeActivo->GetPosition().GetZ() - dimensionesPersonaje->GetZ() / 2;
	maxZPersonaje = this->personajeActivo->GetPosition().GetZ() + dimensionesPersonaje->GetZ() / 2;

	for (int i = 0; i < this->trenes.size(); i++)
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
		minXTren = this->trenes[i]->GetPosition().GetX() - dimensionesTren->GetX() / 2;
		maxXTren = this->trenes[i]->GetPosition().GetX() + dimensionesTren->GetX() / 2;
		minYTren = this->trenes[i]->GetPosition().GetY();
		maxYTren = this->trenes[i]->GetPosition().GetY() + dimensionesTren->GetY();
		minZTren = this->trenes[i]->GetPosition().GetZ() - dimensionesTren->GetZ() / 2;
		maxZTren = this->trenes[i]->GetPosition().GetZ() + dimensionesTren->GetZ() / 2;

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
		float zMeta = this->meta->GetPosition().GetZ();
		if ((zMeta >= minZPersonaje) || (zMeta >= maxZPersonaje))
		{
			this->activo = false;
			haGanado();
		}
	}
}

void SceneLevel::haPerdido()
{
	this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.0));
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
	this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.0));
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
		switch (key)
		{
		case 'w':
			// mover el personajeActivo hacia adelante
			this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, -0.1));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 180.0, 0.0));
			break;
		case 's':
			// mover el personajeActivo hacia atras
			this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.1));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
			break;
		case 'a':
			// mover el personajeActivo hacia la izquierda
			this->personajeActivo->SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 270.0, 0.0));
			break;
		case 'd':
			// mover el personajeActivo hacia la derecha
			this->personajeActivo->SetSpeed(Vector3D(0.1, 0.0, 0.0));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 90.0, 0.0));
			break;
		case 'W':
			// mover el objeto hacia adelante
			this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, -0.1));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 180.0, 0.0));
			break;
		case 'S':
			// mover el personajeActivo hacia atras
			this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.1));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
			break;
		case 'A':
			// mover el personajeActivo hacia la izquierda
			this->personajeActivo->SetSpeed(Vector3D(-0.1, 0.0, 0.0));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 270.0, 0.0));
			break;
		case 'D':
			// mover el personajeActivo hacia la derecha
			this->personajeActivo->SetSpeed(Vector3D(0.1, 0.0, 0.0));
			this->personajeActivo->SetOrientation(Vector3D(0.0, 90.0, 0.0));
			break;
		default:
			break;
		}
	}
	else
	{
		/* if (key == 'R' || key == 'r')
		{
			// REINICIAR EL JUEGO.
			this->estadoGanar = false;
			this->estadoPerder = false;
			this->activo = true;
			this->personajeActivo->SetPosition(Vector3D(0, 0.5, 5));
			this->personajeActivo->SetOrientation(Vector3D(0, 180, 0));
		} */
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
	this->personajeActivo->SetPosition(Vector3D(0, 0.5, 5));
	this->personajeActivo->SetOrientation(Vector3D(0, 180, 0));
	this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.0));
}
