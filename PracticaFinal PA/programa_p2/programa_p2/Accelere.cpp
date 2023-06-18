#include "Accelere.h"

void Accelere::ApplyEffect()
{
	if (GetStatus())
	{
		SetStatus(false);
		player->ActivarAccelere();
	}
}
