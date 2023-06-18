#pragma once
#include "PowerUp.h"
#include "Obstacle.h"

class Ralenti : public PowerUp
{
private:
	vector<Obstacle*> obstacles;
public:
	Ralenti(Model modelToSet,
		vector<Obstacle*> obstaclesToSet,
		Vector3D positionToSet = Vector3D(0.0,0.0,0.0))
		: PowerUp(
		modelToSet,
		positionToSet, 
		Color(0.4, 0.4, 0.8)), 
		obstacles(obstaclesToSet)
	{
		/**
		cargador = new ModelLoader();
		cargador->LoadModel("..\\..\\3dModels\\Bolt.obj");
		model = cargador->GetModel();

		//Propiedades iniciales del personaje.
		SetPosition(positionToSet);
		model.SetPosition(Vector3D(positionToSet));
		model.SetOrientationSpeed(Vector3D(0, 1, 0));
		model.PaintColor(Color(0.8, 0.4, 0.4));
		//*/
	}

	void ApplyEffect();
};

