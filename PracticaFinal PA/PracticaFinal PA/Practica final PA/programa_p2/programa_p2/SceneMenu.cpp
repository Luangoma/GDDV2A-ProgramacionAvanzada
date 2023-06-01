#include "SceneMenu.h"

void SceneMenu::Init(){
    Scene::Init();
    
    // // // //Menú inicial
	SetDrawVertexes(false);
	SetDrawBox(true);
	SetBoundary(Vector3D(100, 100, 100));
	// CAMARA PRESENTACION (60 grados)
    Camera* camara = new Camera();
	camara->SetPosition(Vector3D(5, -2, 20));
	camara->SetOrientation(Vector3D(15.0, 135.0, 0.0));
	SetCamera(*camara); 
	// CARGAR MODELOS
	viasTren = new Model();
	*viasTren = loaderVias->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.3, 0.3, 0.3));
	// // // MENÚ
	vector<Model*> arrayVias;
	desplazamiento = 0.0;
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
	/**
	// Tren del nivel 1
	// Model* tren1M = new Model();
	// *tren1M = loaderLvl1->GetModel();
	// tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	// tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	// tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	AddTren(tren1M);
	AddGameObject(tren1M);
	// Tren del nivel 2
	// Model* tren2M = new Model();
	// *tren2M = loaderLvl2->GetModel();
	// tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	// tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	// tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	AddTren(tren2M);
	AddGameObject(tren2M);
	// Tren del nivel 3
	// Model* tren3M = new Model();
	// *tren3M = loaderLvl3->GetModel();
	// tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	// tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	// tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	AddTren(tren3M);
	AddGameObject(tren3M);
	// Personaje
	// personaje = new Model();
	// *personaje = loaderPersonaje->GetModel();
	// personaje->SetPosition(Vector3D(-15, 0.5, -5));
	// personaje->SetOrientation(Vector3D(0.0, 160.0, 0.0));
	// personaje->PaintColor(Color(0.2, 0.3, 0.8));
	AddGameObject(personaje);
	AddPersonaje(personaje);
	//*/
	// TEXTO
	desplazamiento = -1;
	Text* textoNombre = new Text();
	textoNombre->SetText("ESCAPE TRAIN");
	textoNombre->SetPosition(Vector3D(0, desplazamiento, -8));
	textoNombre->SetColor(Color(1, 1, 1));
	AddGameObject(textoNombre);
	desplazamiento -= 1;
	Text* textoMenu = new Text();
	textoMenu->SetText("MENU - pulse 0");
	textoMenu->SetPosition(Vector3D(0, desplazamiento, -8));
	textoMenu->SetColor(Color(1, 1, 1));
	AddGameObject(textoMenu);
	desplazamiento -= 1;
	Text* textoJugarNivel1 = new Text();
	textoJugarNivel1->SetText("Jugar Nivel 1 - pulse 1");
	textoJugarNivel1->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel1->SetColor(Color(1, 1, 1));
	AddGameObject(textoJugarNivel1);
	desplazamiento -= 1;
	Text* textoJugarNivel2 = new Text();
	textoJugarNivel2->SetText("Jugar Nivel 2 - pulse 2");
	textoJugarNivel2->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel2->SetColor(Color(1, 1, 1));
	AddGameObject(textoJugarNivel2);
	desplazamiento -= 1;
	Text* textoJugarNivel3 = new Text();
	textoJugarNivel3->SetText("Jugar Nivel 3 - pulse 3");
	textoJugarNivel3->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel3->SetColor(Color(1, 1, 1));
	AddGameObject(textoJugarNivel3);
	desplazamiento -= 1;
	Text* textoCreditos = new Text();
	textoCreditos->SetText("Creditos - pulse 4");
	textoCreditos->SetPosition(Vector3D(0, desplazamiento, -8));
	textoCreditos->SetColor(Color(1, 1, 1));
	AddGameObject(textoCreditos);
	// Pared 1 / Cielo
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX(), GetBoundary().GetY() / 2, 0.0));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.0, 0.67, 0.89));
	cielo->SetLength(0.2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(GetBoundary().GetZ());
	AddGameObject(cielo);
	// Pared 2 / Cielo
	cielo = new Cuboid();
	cielo->SetPosition(Vector3D(GetBoundary().GetX() / 3, GetBoundary().GetY() / 2, GetBoundary().GetZ() / 2));
	cielo->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	cielo->SetColor(Color(0.0, 0.67, 0.89));
	cielo->SetLength(GetBoundary().GetX()*2);
	cielo->SetHeight(GetBoundary().GetY());
	cielo->SetWidth(0.2);
	AddGameObject(cielo);

    
}
void SceneMenu::Update(const float& timeIncrement){

}

void SceneMenu::ProcessKeyPressed(unsigned char key, int px, int py){

}