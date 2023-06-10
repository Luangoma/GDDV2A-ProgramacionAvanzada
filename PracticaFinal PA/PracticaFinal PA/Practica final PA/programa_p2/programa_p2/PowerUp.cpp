#include "PowerUP.h"


void PowerUP::Init()
{
	//Cargar modelo del personaje.
	cargador = new ModelLoader();
	cargador->LoadModel("..\\..\\3dModels\\Bolt.obj");
	modelo = cargador->GetModel();
	//Propiedades iniciales del personaje.
	modelo.SetPosition(Vector3D(0, 0.5, 5));
	modelo.SetOrientationSpeed(Vector3D(0, 1, 0));
	modelo.SetColor(Color(0.8, 0.3, 0.2));
}

void PowerUP::Render()
{
	modelo.Render();
}

void PowerUP::Update(const float& timeIncrement)
{
	modelo.Update(timeIncrement);
}

void PowerUP::Reset()
{
	modelo.SetPosition(Vector3D(0, 0.5, 5));
}