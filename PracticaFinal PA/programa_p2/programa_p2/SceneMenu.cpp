#include "SceneMenu.h"
#include <iostream>

void SceneMenu::Init()
{
	std::cout << std::endl << "Carga de escena - Menu" << std::endl;

	Scene::Init();

	// // // // Menu inicial
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(100, 100, 100));

	// CAMARA PRESENTACION
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(5, -2, 20));
	camara->SetOrientation(Vector3D(15.0, 135.0, 0.0));
	SetCamera(*camara);

	desplazamiento = 0.0;
	incremento = 5.0;			// Definido en scene.h
	for (int i = 0; i < 3; i++) // Creamos las vias y las anadimos
	{
		via = new Model();
		*via = loaderVias->GetModel();
		via->SetPosition(Vector3D(via->GetPosition().GetX() + 50, via->GetPosition().GetY(), via->GetPosition().GetZ() + desplazamiento));
		via->PaintColor(Color(0.3, 0.3, 0.3));
		desplazamiento += incremento;
		AddGameObject(via);
	}

	LoadModelNvl1();
	obstaculo = new Obstacle(
		loaderTren->GetModel(),		// Modelo
		Vector3D(15.0, 1.7, 0.0),	// Posicion
		Vector3D(0.0, 0.0, 0.0),	// Rotacion
		Vector3D(37.1, 3.58, 2.87), // Dimensiones
		Color(0.1, 0.1, 0.1),		// Color
		0.0);						// Velocidad
	AddObstaculo(obstaculo);

	LoadModelNvl2();
	obstaculo = new Obstacle(
		loaderTren->GetModel(),		// Modelo
		Vector3D(25.0, 1.1, 5.0),	// Posicion
		Vector3D(0.0, 0.0, 0.0),	// Rotacion
		Vector3D(66.7, 2.72, 2.25), // Dimensiones
		Color(0.73, 0.56, 0.1),		// Color
		0.0);						// Velocidad
	AddObstaculo(obstaculo);

	LoadModelNvl3();
	obstaculo = new Obstacle(
		loaderTren->GetModel(),	   // Modelo
		Vector3D(30, 1.0, 10.0),   // Posicion
		Vector3D(0.0, 0.0, 0.0),   // Rotacion
		Vector3D(90.5, 1.9, 2.03), // Dimensiones
		Color(0.4, 0.4, 0.4),	   // Color
		0.0);					   // Velocidad
	AddObstaculo(obstaculo);

	// Personaje
	jugador = new Player(loaderPersonaje->GetModel(),
						 Vector3D(-15, 0.5, -5),
						 Vector3D(0.0, 160.0, 0.0));
	AddGameObject(jugador);

	// Texto
	desplazamiento = -1;
	Text *texto = new Text();
	texto->SetText("ESCAPE THE TRAIN");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("MENU - pulse 0");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Jugar Nivel 1 - pulse 1");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Jugar Nivel 2 - pulse 2");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Jugar Nivel 3 - pulse 3");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Creditos - pulse 4");
	titulos.push_back(texto);
	for (int i = 0; i < titulos.size(); i++) // Añadimos los textos
	{
		titulos[i]->SetPosition(Vector3D(0, desplazamiento, -8));
		titulos[i]->SetColor(Color(1, 1, 1));
		AddGameObject(titulos[i]);
		desplazamiento--;
	}

	// Decoracion - Cielo
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX(), GetBoundary().GetY() / 2, 0.0));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.13, 0.44, 0.7));
	cielo->SetLength(0.2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(GetBoundary().GetZ());
	AddGameObject(cielo);
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX() / 3, GetBoundary().GetY() / 2, GetBoundary().GetZ() / 2));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.13, 0.44, 0.7));
	cielo->SetLength(GetBoundary().GetX() * 2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(0.2);
	AddGameObject(cielo);
}