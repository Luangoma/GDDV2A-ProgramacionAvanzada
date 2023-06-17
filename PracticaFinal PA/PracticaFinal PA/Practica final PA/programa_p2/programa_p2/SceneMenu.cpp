#include "SceneMenu.h"
#include <iostream>

void SceneMenu::Init()
{
	Scene::Init();

	std::cout << "Carga de la escena menu" << std::endl << std::endl;
	// // // // Menu inicial
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(100, 100, 100));
	// CAMARA PRESENTACION (60 grados)
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(5, -2, 20));
	camara->SetOrientation(Vector3D(15.0, 135.0, 0.0));
	SetCamera(*camara);
	// // // MENU
	desplazamiento = 0.0;
	for (int i = 0; i < 3; i++) // Creamos las vias y las anadimos
	{
		via = new Model();
		*via = loaderVias->GetModel();
		via->SetPosition(Vector3D(via->GetPosition().GetX() + 50, via->GetPosition().GetY(), via->GetPosition().GetZ() + desplazamiento));
		via->PaintColor(Color(0.3, 0.3, 0.3));
		AddVia(via);
		desplazamiento += 5.0;
		AddGameObject(vias[i]);
	}
	/**
	// Tren del nivel 1
	Model *tren1M = new Model();
	*tren1M = loaderLvl1->GetModel();
	tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	AddObstaculo(tren1M);
	AddGameObject(tren1M);
	// Tren del nivel 2
	Model *tren2M = new Model();
	*tren2M = loaderLvl2->GetModel();
	tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	AddObstaculo(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
	Model *tren3M = new Model();
	*tren3M = loaderLvl3->GetModel();
	tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	AddObstaculo(tren3M);
	AddGameObject(tren3M);
	tren = new Model();
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
		//*/
	
	// Personaje
	jugador = new Player(loaderPersonaje->GetModel(), Vector3D(-15, 0.5, -5), Vector3D(0.0, 160.0, 0.0), true);
	AddGameObject(jugador);
	//*/
	// TEXTO
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
	// Pared 1 / Cielo
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX(), GetBoundary().GetY() / 2, 0.0));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.13, 0.44, 0.7));
	cielo->SetLength(0.2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(GetBoundary().GetZ());
	AddGameObject(cielo);
	// Pared 2 / Cielo
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX() / 3, GetBoundary().GetY() / 2, GetBoundary().GetZ() / 2));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.13, 0.44, 0.7));
	cielo->SetLength(GetBoundary().GetX() * 2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(0.2);
	AddGameObject(cielo);
}
void SceneMenu::ProcessKeyPressed(unsigned char key, int px, int py)
{
	//Scene::ProcessKeyPressed(key,px,py);
}