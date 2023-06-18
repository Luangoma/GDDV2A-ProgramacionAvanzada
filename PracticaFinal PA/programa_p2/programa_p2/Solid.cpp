#include "Solid.h"

void Solid::Update(const float& timeIncrement)
{
	this->SetPosition(this->GetPosition() + this->GetSpeed() * timeIncrement);
	this->SetOrientation(this->GetOrientation() + this->GetOrientationSpeed() * timeIncrement);
}
