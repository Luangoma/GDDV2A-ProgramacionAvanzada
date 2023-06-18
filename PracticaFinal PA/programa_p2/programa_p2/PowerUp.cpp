#include "PowerUp.h"
#include <chrono>

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
	this->SetStatus(true);
}

void PowerUp::ApplyEffect()
{
}
