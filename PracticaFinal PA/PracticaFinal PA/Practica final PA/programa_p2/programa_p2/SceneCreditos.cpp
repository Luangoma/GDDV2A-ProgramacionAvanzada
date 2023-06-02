#include "Scene.h"
#include "SceneCreditos.h"
#include <iostream>

void SceneCreditos::Init(){
    Scene::Init();

	std::cout << "Carga de la escena menu" << std::endl;
    // // // //Creditos finales
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(100, 100, 100));
	// CAMARA EN CENITAL (90 grados)
	Camera* camara = new Camera();
	camara->SetPosition(Vector3D(-5, -5, 20));
	camara->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	SetCamera(*camara);
	// // // CREDITOS
	for (int i = 0; i < 3; i++) // Creamos las vias y las añadimos
	{
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX() + 50, viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() + desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias.push_back(viasTren);
		desplazamiento += 5.0;
		AddGameObject(arrayVias[i]);
		viasTren = new Model();
	}
	// Tren del nivel 1
	Model* tren1M = new Model();
	*tren1M = loaderLvl1->GetModel();
	tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	AddTren(tren1M);
	AddGameObject(tren1M);
	// Tren del nivel 2
	Model* tren2M = new Model();
	*tren2M = loaderLvl2->GetModel();
	tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	AddTren(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
	Model* tren3M = new Model();
	*tren3M = loaderLvl3->GetModel();
	tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	AddTren(tren3M);
	AddGameObject(tren3M);
	// Personaje
	personaje->SetPosition(Vector3D(5, 0, -5));
	personaje->SetOrientation(Vector3D(0, -90, 0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	AddGameObject(personaje);
	AddPersonaje(personaje);
	// TEXTO
	desplazamiento = -2.5;
	Text* texto0 = new Text();
	texto0->SetText("Autores:");
	texto0->SetPosition(Vector3D(4, 0, desplazamiento - 1));
	texto0->SetColor(Color(1, 1, 1));
	AddGameObject(texto0);
	desplazamiento += 5;
	Text* texto1 = new Text();
	texto1->SetText("Juan Alessandro Vazquez Bustos");
	texto1->SetPosition(Vector3D(-2, 0, desplazamiento));
	texto1->SetColor(Color(1, 1, 1));
	AddGameObject(texto1);
	desplazamiento += 5;
	Text* texto2 = new Text();
	texto2->SetText("Monica Varas Garcia");
	texto2->SetPosition(Vector3D(-8, 0, desplazamiento));
	texto2->SetColor(Color(1, 1, 1));
	AddGameObject(texto2);
	desplazamiento += 5;
	Text* texto3 = new Text();
	texto3->SetText("Luis Antonio Gonzalez Martinez");
	texto3->SetPosition(Vector3D(-14, 0, desplazamiento));
	texto3->SetColor(Color(1, 1, 1));
	AddGameObject(texto3);
}
void SceneCreditos::Update(const float& timeIncrement){

}

void SceneCreditos::ProcessKeyPressed(unsigned char key, int px, int py){

}