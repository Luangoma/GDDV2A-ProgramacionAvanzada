#include "Scene.h"
#include "ModelLoader.h"
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include <iostream>
#include "Text.h"

void Scene::Init()
{
	loaderLvl1 = new ModelLoader();
	loaderLvl2 = new ModelLoader();
	loaderLvl3 = new ModelLoader();
	loaderPersonaje = new ModelLoader();
	camera.SetPosition(Vector3D(this->boundary.GetX() / 2, this->boundary.GetY() / 2, this->boundary.GetZ() * 1.8));

	if (this->GetDrawVertexes())
	{
		/**
		Cube *point1 = new Cube();
		point1->SetColor(Color(0, 0, 1));
		point1->SetPosition(Vector3D(0, 0, 0));
		point1->SetSize(0.2);
		this->AddGameObject(point1);

		Cube *point2 = new Cube();
		point2->SetColor(Color(0, 0, 1));
		point2->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, 0));
		point2->SetSize(0.2);
		this->AddGameObject(point2);

		Cube *point3 = new Cube();
		point3->SetColor(Color(0, 0, 1));
		point3->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), 0));
		point3->SetSize(0.2);
		this->AddGameObject(point3);

		Cube *point4 = new Cube();
		point4->SetColor(Color(0, 0, 1));
		point4->SetPosition(Vector3D(0, this->GetBoundary().GetY(), 0));
		point4->SetSize(0.2);
		this->AddGameObject(point4);

		Cube *point5 = new Cube();
		point5->SetColor(Color(0, 0, 1));
		point5->SetPosition(Vector3D(0, this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point5->SetSize(0.2);
		this->AddGameObject(point5);

		Cube *point6 = new Cube();
		point6->SetColor(Color(0, 0, 1));
		point6->SetPosition(Vector3D(this->GetBoundary().GetX(), this->GetBoundary().GetY(), this->GetBoundary().GetZ()));
		point6->SetSize(0.2);
		this->AddGameObject(point6);

		Cube *point7 = new Cube();
		point7->SetColor(Color(0, 0, 1));
		point7->SetPosition(Vector3D(this->GetBoundary().GetX(), 0, this->GetBoundary().GetZ()));
		point7->SetSize(0.2);
		this->AddGameObject(point7);

		Cube *point8 = new Cube();
		point8->SetColor(Color(0, 0, 1));
		point8->SetPosition(Vector3D(0, 0, this->GetBoundary().GetZ()));
		point8->SetSize(0.2);
		this->AddGameObject(point8);
		//*/



	}

	// Carga de recursos base
	ModelLoader* loader = new ModelLoader();
	Cuboid* meta;

	// Carga del modelo 'viastren' (generico para los niveles)
	ModelLoader* loaderVias = new ModelLoader();
	Model* viasTren = new Model();
	loaderVias->LoadModel("..\\..\\3dModels\\viasTren.obj");

	// Carga del modelo 'TrenLvl1' (tren del nivel 1)
	ModelLoader* loaderLvl1 = new ModelLoader();
	Model* trenLvl1 = new Model();
	loaderLvl1->LoadModel("..\\..\\3dModels\\TrenLvl1.obj");

	// Carga del modelo 'TrenLvl2' (tren del nivel 2)
	ModelLoader* loaderLvl2 = new ModelLoader();
	Model* trenLvl2 = new Model();
	loaderLvl2->LoadModel("..\\..\\3dModels\\TrenLvl2.obj");

	// Carga del modelo 'TrenLvl3' (tren del nivel 3)
	ModelLoader* loaderLvl3 = new ModelLoader();
	Model* trenLvl3 = new Model();
	loaderLvl3->LoadModel("..\\..\\3dModels\\TrenLvl3.obj");

	// Carga del modelo 'Cop' (Jugador)
	ModelLoader* loaderPersonaje = new ModelLoader();
	Model* personaje = new Model();
	loaderPersonaje->LoadModel("..\\..\\3dModels\\Cop.obj");
}

void Scene::Update(const float& timeIncrement)
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
}

void Scene::ProcessMouseMovement(int x, int y)
{
	// cout << "Movimiento del mouse: " << x << ", " << y << endl;
}

void Scene::ProcessMouseClick(int button, int state, int x, int y)
{
	// cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;
}