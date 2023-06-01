#include "SceneLevel.h"
#include <iostream>


void SceneLevel::Init()
{
    Scene::Init();

    //El resto
    /**
    // // // //Primera escena
	std::cout << "Carga de la primera escena" << std::endl;
	SceneLevel* scene1 = new SceneLevel();
	scene1->SetDrawVertexes(false);
	scene1->SetDrawBox(true);
	scene1->Init();
	scene1->SetBoundary(Vector3D(50, 50, 100));
	scene1->SetNivel(1);
	scene1->SetActivo(true);
	// CAMARA EN CENITAL (60 grados)
	Camera* camara1 = new Camera();
	camara1->SetPosition(Vector3D(0, 4, 18));
	camara1->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	scene1->SetCamera(*camara1);
	// CARGAR MODELOS
	*viasTren = loaderVias->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.6, 0.3, 0.3));
	// // //NIVEL FACIL -> 3 vias.
	vector<Model*> arrayVias1;
	const int easyMode = 3;
	desplazamiento = 0.0;
	for (int i = 0; i < easyMode; i++) // Creamos las vias y las añadimos
	{
		viasTren = new Model();
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX(), viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() - desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias1.push_back(viasTren);
		desplazamiento += 7.0;
		scene1->AddGameObject(arrayVias1[i]);
	}
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene1->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene1->AddGameObject(meta);
	scene1->SetMeta(meta);
	for (int i = 0; i < easyMode; i++) // Creamos los trenes y los añadimos
	{
		// Posicion Inicial Aleatoria
		float randomX = ((rand() % int(scene1->GetBoundary().GetX())) - int(scene1->GetBoundary().GetX() / 2));
		std::cout << (randomX) << std::endl;

		trenLvl1 = new Model();
		*trenLvl1 = loaderLvl1->GetModel();
		trenLvl1->SetPosition(Vector3D(randomX, 1.7, -7.0 * i));
		trenLvl1->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
		trenLvl1->PaintColor(Color(0.1, 0.1, 0.1));
		trenLvl1->SetSpeed(Vector3D((i % 2 == 0) ? 0.1 : -0.1, 0.0, 0.0));

		scene1->AddTren(trenLvl1);
		scene1->AddGameObject(trenLvl1);
	}
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(0, 0.5, 5));
	personaje->SetOrientation(Vector3D(0.0, 180.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene1->AddGameObject(personaje);
	scene1->AddPersonaje(personaje);
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
		float randomX = ((rand() % int(boundary.GetX() / 2) + 10) + int(boundary.GetX() / 2) + 5);
		if (idx % 2 == 0)
		{
			randomX = -randomX;
		}
		// std::cout<<randomX<<std::endl;
		if (this->trenes[idx]->GetPosition().GetX() < -(this->boundary.GetX()) || this->trenes[idx]->GetPosition().GetX() > this->boundary.GetX())
		{
			std::cout << "Variando: " << randomX << std::endl;
			this->trenes[idx]->SetPosition(Vector3D(randomX, trenes[idx]->GetPosition().GetY(), trenes[idx]->GetPosition().GetZ()));
		}
	}
}

void SceneLevel::checkColisiones()
{

	Vector3D* dimensionesPersonaje = new Vector3D(1.78, 1.13, 3.73);
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

		Vector3D* dimensionesTren;

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
			//dimensionesTren = new Vector3D(90.5, 1.9, 2.03);
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
	this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.0));
}

void SceneLevel::haGanado()
{
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
	this->personajeActivo->SetSpeed(Vector3D(0.0, 0.0, 0.0));
}

void SceneLevel::Update(const float& timeIncrement){
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
		if (key == 'R' || key == 'r')
		{
			//REINICIAR EL JUEGO.
			this->activo = true;
			this->personajeActivo->SetPosition(Vector3D(0, 0.5, 5));
			this->personajeActivo->SetOrientation(Vector3D(0, 180, 0));
		}
	}
}