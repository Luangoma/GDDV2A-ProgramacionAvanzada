#include "Scene.h"
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
	// CAMARA EN CENITAL (90 grados)
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(-5, -5, 20));
	camara->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	SetCamera(*camara);
	// Vias
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
	/**
	// Tren del nivel 1
	tren = new Model();
	*tren = loaderLvl1->GetModel();
	tren->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren->PaintColor(Color(0.1, 0.1, 0.1));
	AddObstaculo(tren);
	AddGameObject(tren);
	// Tren del nivel 2
	tren = new Model();
	*tren = loaderLvl2->GetModel();
	tren->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren->PaintColor(Color(0.73, 0.56, 0.1));
	AddObstaculo(tren);
	AddGameObject(tren);
	// Tren del nivel 3
	tren = new Model();
	*tren = loaderLvl3->GetModel();
	tren->SetPosition(Vector3D(30, 1.0, 10.0));
	tren->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren->PaintColor(Color(0.4, 0.42, 0.4));
	AddObstaculo(tren);
	AddGameObject(tren);
	//*/
	obstaculo = new Obstacle(
		loaderLvl1->GetModel(),
		Vector3D(15.0, 1.7, 0.0),
		Vector3D(0.0, 0.0, 0.0),
		Color(0.1, 0.1, 0.1),
		Vector3D(0.0, 0.0, 0.0));
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);
	obstaculo = new Obstacle(
		loaderLvl2->GetModel(),
		Vector3D(25.0, 1.1, 5.0),
		Vector3D(0.0, 0.0, 0.0),
		Color(0.73, 0.56, 0.1),
		Vector3D(0.0, 0.0, 0.0));
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);
	obstaculo = new Obstacle(
		loaderLvl3->GetModel(),
		Vector3D(30, 1.0, 10.0),
		Vector3D(0.0, 0.0, 0.0),
		Color(0.4, 0.4, 0.4),
		Vector3D(0.0, 0.0, 0.0));
	AddObstaculo(obstaculo);
	AddGameObject(obstaculo);
	// Personaje
	jugador = new Player(loaderPersonaje->GetModel(), Vector3D(5, 0, -5), Vector3D(0, -90, 0));
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