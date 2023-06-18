#pragma once
#include "PowerUp.h"

class Coin : public PowerUp
{
public:
	Coin(Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0))
	{
		cargador = new ModelLoader();
		cargador->LoadModel("..\\..\\3dModels\\Coin.obj");
		model = cargador->GetModel();

		//Propiedades iniciales del personaje.
		SetPosition(positionToSet);
		model.SetPosition(Vector3D(positionToSet));
		model.SetOrientationSpeed(Vector3D(0, 1, 0));
		model.PaintColor(Color(0.8, 0.3, 0.2));
	}

	void ApplyEffect();
};

