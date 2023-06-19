#pragma once
#include "PowerUp.h"
#include "Obstacle.h"

class Ralenti : public PowerUp
{
private:
	vector<Obstacle *> obstacles;

public:
	Ralenti(Model modelToSet,
			vector<Obstacle *> obstaclesToSet,
			Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0))
		: PowerUp(
			  modelToSet,
			  positionToSet,
			  Color(0.4, 0.4, 0.8)),
		  obstacles(obstaclesToSet) {}

	// Metodos propios de la clase
	void ApplyEffect();
};
