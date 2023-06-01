#include "Scene.h"
#include "ModelLoader.h"
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include <iostream>
#include "Text.h"

void Scene::Init()
{
	loaderVias = new ModelLoader();
	loaderLvl1 = new ModelLoader();
	loaderLvl2 = new ModelLoader();
	loaderLvl3 = new ModelLoader();
	loaderPersonaje = new ModelLoader();
	personaje = new Model();
	tren1M = new Model();
	tren2M = new Model();
	tren3M = new Model();
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
	// Carga del modelo 'viastren' (generico para los niveles)
	loaderVias->LoadModel("..\\..\\3dModels\\viasTren.obj");
	std::cout<<"Carga de viasTren"<<std::endl;

	// Carga del modelo 'TrenLvl1' (tren del nivel 1)
	// Model* trenLvl1 = new Model();
	loaderLvl1->LoadModel("..\\..\\3dModels\\TrenLvl1.obj");
	std::cout<<"Carga de TrenLvl1"<<std::endl;

	// Carga del modelo 'TrenLvl2' (tren del nivel 2)
	// Model* trenLvl2 = new Model();
	loaderLvl2->LoadModel("..\\..\\3dModels\\TrenLvl2.obj");
	std::cout<<"Carga de TrenLvl2"<<std::endl;

	// Carga del modelo 'TrenLvl3' (tren del nivel 3)
	// Model* trenLvl3 = new Model();
	loaderLvl3->LoadModel("..\\..\\3dModels\\TrenLvl3.obj");
	std::cout<<"Carga de TrenLvl3"<<std::endl;

	// Carga del modelo 'Cop' (Jugador)
	// Model* personaje = new Model();
	loaderPersonaje->LoadModel("..\\..\\3dModels\\Cop.obj");
	std::cout<<"Carga de Cop"<<std::endl<<std::endl;
	*personaje = loaderPersonaje->GetModel();

	// Tren del nivel 1
	//Model* tren1M = new Model();
	*tren1M = loaderLvl1->GetModel();
	tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	AddTren(tren1M);
	AddGameObject(tren1M);
	// Tren del nivel 2
	//Model* tren2M = new Model();
	*tren2M = loaderLvl2->GetModel();
	tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	AddTren(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
	//Model* tren3M = new Model();
	*tren3M = loaderLvl3->GetModel();
	tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	AddTren(tren3M);
	AddGameObject(tren3M);
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(-15, 0.5, -5));
	personaje->SetOrientation(Vector3D(0.0, 160.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	AddGameObject(personaje);
	AddPersonaje(personaje);

	//Liberar los model loaders.
	//delete loader;
	//delete loaderLvl1;
	//delete loaderLvl2;
	//delete loaderLvl3;
	//delete loaderPersonaje;
	//delete loaderVias;
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