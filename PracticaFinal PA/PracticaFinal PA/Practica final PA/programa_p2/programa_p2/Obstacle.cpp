#include "Obstacle.h"

void Obstacle::Reset()
{
	Vehicle::Reset();
	SetSpeed(Vector3D(GetInitialSpeed(), 0, 0));
}