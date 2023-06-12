#include "Text.h"
#include "Scene.h"
#include "ModelLoader.h"
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include <iostream>

void Scene::Init()
{
	camera.SetPosition(Vector3D(this->boundary.GetX() / 2, this->boundary.GetY() / 2, this->boundary.GetZ() * 1.8));

	if (this->GetDrawVertexes())
	{
		/**/
		Cuboid *point1 = new Cuboid();
		point1->SetColor(Color(0, 0, 1));
		point1->SetPosition(Vector3D(0, 0, 0));
		this->AddGameObject(point1);
		Cuboid *point2 = new Cuboid();
		point2->SetColor(Color(0, 0, 1));
		point2->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, 0));
		this->AddGameObject(point2);
		Cuboid *point3 = new Cuboid();
		point3->SetColor(Color(0, 0, 1));
		point3->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), 0));
		this->AddGameObject(point3);
		Cuboid *point4 = new Cuboid();
		point4->SetColor(Color(0, 0, 1));
		point4->SetPosition(Vector3D(0, this->GetBoundary().GetY(), 0));
		this->AddGameObject(point4);
		Cuboid *point5 = new Cuboid();
		point5->SetColor(Color(0, 0, 1));
		point5->SetPosition(Vector3D(0, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		this->AddGameObject(point5);
		Cuboid *point6 = new Cuboid();
		point6->SetColor(Color(0, 0, 1));
		point6->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		this->AddGameObject(point6);
		Cuboid *point7 = new Cuboid();
		point7->SetColor(Color(0, 0, 1));
		point7->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, this->GetBoundary().GetZ()));
		this->AddGameObject(point7);
		Cuboid *point8 = new Cuboid();
		point8->SetColor(Color(0, 0, 1));
		point8->SetPosition(Vector3D(0, 0, this->GetBoundary().GetZ()));
		this->AddGameObject(point8);
		//*/
	}

	// Carga de recursos base
	// Carga del modelo 'viastren' (generico para los niveles)
	loaderVias = new ModelLoader();
	loaderVias->LoadModel("..\\..\\3dModels\\viasTren.obj");
	std::cout << "Carga de las vias" << std::endl;

	// Carga del modelo 'TrenLvl1' (tren del nivel 1)
	loaderLvl1 = new ModelLoader();
	loaderLvl1->LoadModel("..\\..\\3dModels\\TrenLvl1.obj");
	std::cout << "Carga del tren de nivel 1" << std::endl;

	// Carga del modelo 'TrenLvl2' (tren del nivel 2)
	loaderLvl2 = new ModelLoader();
	loaderLvl2->LoadModel("..\\..\\3dModels\\TrenLvl2.obj");
	std::cout << "Carga del tren de nivel 2" << std::endl;

	// Carga del modelo 'TrenLvl3' (tren del nivel 3)
	loaderLvl3 = new ModelLoader();
	loaderLvl3->LoadModel("..\\..\\3dModels\\TrenLvl3.obj");
	std::cout << "Carga del tren de nivel 3" << std::endl;

	// Carga del modelo 'Cop' (Jugador)
	loaderPersonaje = new ModelLoader();
	loaderPersonaje->LoadModel("..\\..\\3dModels\\Cop.obj");

	// Inicializacion de tren
	tren = new Model();
	// Inicializacion de personaje
	//jugador = new Player();
	//jugador->Init();

	/**
	// Tren del nivel 1
	//Model* tren1M = new Model();
	tren1M = new Model();
	*tren1M = loaderLvl1->GetModel();
	tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	AddTren(tren1M);
	AddGameObject(tren1M);
	// Tren del nivel 2
	//Model* tren2M = new Model();
	tren2M = new Model();
	*tren2M = loaderLvl2->GetModel();
	tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	AddTren(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
	//Model* tren3M = new Model();
	tren3M = new Model();
	*tren3M = loaderLvl3->GetModel();
	tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	AddTren(tren3M);
	AddGameObject(tren3M);
	//*/
}

void Scene::Update(const float &timeIncrement)
{
	this->camera.Update(timeIncrement);

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(timeIncrement);
	}
}

void Scene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py)
{
	// cout << "Tecla pulsada: " << x << ", " << y << endl;
	jugador->ProcessKeyPressed(key,px,py);
}

void Scene::ProcessMouseMovement(int x, int y)
{
	// cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y)
{
	// cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;
}

void Scene::Reset()
{
}

int Scene::CheckStatus()
{
	return 0;
}