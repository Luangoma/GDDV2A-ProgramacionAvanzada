#include "SceneCreditos.h"
#include <iostream>

void SceneCreditos::Init()
{
	Scene::Init();

	std::cout << "Carga de la escena creditos" << std::endl << std::endl;
	
	// // // // Creditos finales
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(100, 100, 100));

	// CAMARA PRESENTACION
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(-5, -5, 20));
	camara->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	SetCamera(*camara);

	// // // CREDITOS
	desplazamiento = 0.0;
	incremento = 5.0;			// Definido en scene.h
	for (int i = 0; i < 3; i++) // Creamos las vias y las a�adimos
	{
		via = new Model();
		*via = loaderVias->GetModel();
		via->SetPosition(Vector3D(via->GetPosition().GetX() + 50, via->GetPosition().GetY(), via->GetPosition().GetZ() + desplazamiento));
		via->PaintColor(Color(0.3, 0.3, 0.3));
		AddVia(via);
		AddGameObject(vias[i]);
		desplazamiento += incremento;
	}
	obstaculo = new Obstacle(
		loaderLvl1->GetModel(),		// Modelo
		Vector3D(15.0, 1.7, 0.0),	// Posicion
		Vector3D(0.0, 0.0, 0.0),	// Rotacion
		Vector3D(37.1, 3.58, 2.87), // Dimensiones
		Color(0.1, 0.1, 0.1),		// Color
		0.0);						// Velocidad
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);
	obstaculo = new Obstacle(
		loaderLvl2->GetModel(),		// Modelo
		Vector3D(25.0, 1.1, 5.0),	// Posicion
		Vector3D(0.0, 0.0, 0.0),	// Rotacion
		Vector3D(66.7, 2.72, 2.25), // Dimensiones
		Color(0.73, 0.56, 0.1),		// Color
		0.0);						// Velocidad
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);
	obstaculo = new Obstacle(
		loaderLvl3->GetModel(),		// Modelo
		Vector3D(30, 1.0, 10.0),	// Posicion
		Vector3D(0.0, 0.0, 0.0),	// Rotacion
		Vector3D(90.5, 1.9, 2.03),  // Dimensiones
		Color(0.4, 0.4, 0.4),		// Color
		0.0);						// Velocidad
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);

	// Personaje
	jugador = new Player(loaderPersonaje->GetModel(), 
		Vector3D(5, 0, -5), 
		Vector3D(0, -90, 0));
	AddGameObject(jugador);

	// Texto
	desplazamiento = -(incremento / 2);
	Text *texto = new Text();
	texto->SetText("Autores:");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Juan Alessandro Vazquez Bustos");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Monica Varas Garcia");
	titulos.push_back(texto);
	texto = new Text();
	texto->SetText("Luis Antonio Gonzalez Martinez");
	titulos.push_back(texto);

	float desplazamientoX = 4.0, incrementoX = -6.0;
	for (int i = 0; i < titulos.size(); i++) // Añadimos los textos
	{
		titulos[i]->SetPosition(Vector3D(desplazamientoX, 1, desplazamiento));
		titulos[i]->SetColor(Color(1, 1, 1));
		AddGameObject(titulos[i]);
		desplazamiento += incremento;
		desplazamientoX += incrementoX;
	}
}
void SceneCreditos::Update(const float &timeIncrement)
{
}

void SceneCreditos::ProcessKeyPressed(unsigned char key, int px, int py)
{
}