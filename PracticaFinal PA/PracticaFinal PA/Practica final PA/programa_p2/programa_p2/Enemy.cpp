#include "Enemy.h"

void Enemy::Init()
{
	//Cargar modelo del personaje.
	cargador = new ModelLoader();
	cargador->LoadModel("..\\..\\3dModels\\Policia.obj");
	modelo = cargador->GetModel();
	//Propiedades iniciales del personaje.
	modelo.SetPosition(Vector3D(0, 0.5, 5));
	modelo.SetOrientation(Vector3D(0, 0, 0));
	modelo.SetColor(Color(0.8, 0.3, 0.2));
}

void Enemy::Render()
{
	modelo.Render();
}

void Enemy::Update(const float& timeIncrement)
{
	Model personaje; //, posicion del personaje para que le persiga
	// POR DEFINIR
	if (modelo.GetPosition().GetX() < personaje.GetPosition().GetX()) {
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
	}
	else if (modelo.GetPosition().GetX() > personaje.GetPosition().GetX())
	{
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() < personaje.GetPosition().GetY())
	{
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
	}
	else if (modelo.GetPosition().GetY() > personaje.GetPosition().GetY())
	{
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
	}
	modelo.Update(timeIncrement);
}

void Enemy::Reset()
{
	modelo.SetPosition(Vector3D(0, 0.5, 5));
	modelo.SetOrientation(Vector3D(0, 180, 0));
}