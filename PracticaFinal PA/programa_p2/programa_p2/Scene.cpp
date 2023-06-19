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
		/**
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
	loaderVias->LoadModel("..\\..\\3dModels\\Vias.obj");
	std::cout << "- Carga de modelo - Vias" << std::endl;
	// Carga del modelo 'Cop' (Jugador)
	loaderPersonaje = new ModelLoader();
	loaderPersonaje->LoadModel("..\\..\\3dModels\\Cop.obj");
	std::cout << "- Carga de modelo - Jugador" << std::endl;
}

void Scene::Update(const float& timeIncrement)
{
	this->camera.Update(timeIncrement);

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Update(timeIncrement);
	}
}

void Scene::LoadModelNvl1()
{
	// Carga del modelo 'TrenLvl1' (tren del nivel 1)
	loaderTren = new ModelLoader();
	loaderTren->LoadModel("..\\..\\3dModels\\TrenLvl1.obj");
	std::cout << "- Carga de modelo - Tren de nivel 1" << std::endl;
}

void Scene::LoadModelNvl2()
{
	// Carga del modelo 'TrenLvl2' (tren del nivel 2)
	loaderTren = new ModelLoader();
	loaderTren->LoadModel("..\\..\\3dModels\\TrenLvl2.obj");
	std::cout << "- Carga de modelo - Tren de nivel 2" << std::endl;
}

void Scene::LoadModelNvl3()
{
	// Carga del modelo 'TrenLvl3' (tren del nivel 3)
	loaderTren = new ModelLoader();
	loaderTren->LoadModel("..\\..\\3dModels\\TrenLvl3.obj");
	std::cout << "- Carga de modelo - Tren de nivel 3" << std::endl;
}

void Scene::Render()
{
	this->camera.Render();

	for (int idx = 0; idx < this->gameObjects.size(); idx++)
	{
		this->gameObjects[idx]->Render();
	}
}

void Scene::ProcessKeyPressed(unsigned char key, int px, int py) {}

void Scene::ProcessMouseMovement(int x, int y) {}

void Scene::ProcessMouseClick(int button, int state, int x, int y) {}

void Scene::Reset() {}

int Scene::CheckStatus()
{
	return 0;
}
