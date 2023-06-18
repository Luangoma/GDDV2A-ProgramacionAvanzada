#pragma once
#include "PowerUp.h"
#include "Player.h"

class Accelere : public PowerUp
{
private:
	Player* player;
public:
	Accelere(Model modelToSet,
		Player* playerToSet,
		Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0))
		: PowerUp(
		modelToSet,
		positionToSet,
		Color(0.8, 0.4, 0.4)),
		player(playerToSet) {}

	// Metodos propios de la clase
	void ApplyEffect();
};
