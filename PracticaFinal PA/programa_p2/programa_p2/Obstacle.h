#pragma once
#include "Vehicle.h"
#include "Model.h"

class Obstacle : public Vehicle
{
	/**
private:
	Model modelo;
	float speed;
	//*/
public:
	Obstacle(Model modelToSet,
			 Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
			 Vector3D orientationToSet = Vector3D(0.0, 0.0, 0.0),
			 Vector3D dimensions = Vector3D(0.0, 0.0, 0.0),
			 Color colorToSet = Color(0.0, 0.0, 0.0),
			 float speedToSet = 0.0)
		: Vehicle(
			modelToSet,
			positionToSet,
			orientationToSet,
			dimensions,
			colorToSet,
			speedToSet)
	{}

	// Metodos virtuales de Solid y otros
	void Reset();

	// Metodos propios de la clase
	inline void Repositioning(const Vector3D &repositionToSet) { this->SetPosition(repositionToSet); }
};
