#include "SceneCreditos.h"
#include "Scene.h"

void SceneCreditos::Init(){
    Scene::Init();
    
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
		AddGameObject(arrayVias[i]);
	}
	// Tren del nivel 1
    AddTren(tren1M);
	AddGameObject(tren1M);
    // Tren del nivel 2
	AddTren(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
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
	desplazamiento += 5;
	
}
void SceneCreditos::Update(const float& timeIncrement){

}

void SceneCreditos::ProcessKeyPressed(unsigned char key, int px, int py){

}