#include "PowerUp.h"
#include <chrono>
/**
void PowerUP::Init()
{
	//Cargar modelo del personaje.
	cargador = new ModelLoader();
	cargador->LoadModel("..\\..\\3dModels\\Bolt.obj");
	modelo = cargador->GetModel();
	//Propiedades iniciales del personaje.
	modelo.SetPosition(Vector3D(0, 0.5, 5));
	modelo.SetOrientationSpeed(Vector3D(0, 1, 0));
	modelo.PaintColor(Color(0.8, 0.3, 0.2));
}
//*/
void PowerUp::Render()
{
	if (GetStatus())
	{
		model.Render();
	}
}

void PowerUp::Update(const float &timeIncrement)
{
	model.Update(timeIncrement);
}

void PowerUp::Reset()
{
	//model.SetPosition(Vector3D(initialPosition));
	this->SetStatus(true);
}

void PowerUp::ApplyEffect()
{
}
