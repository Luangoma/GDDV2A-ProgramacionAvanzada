#include "Ralenti.h"

void Ralenti::ApplyEffect()
{
	if (GetStatus())
	{
		SetStatus(false);
		for (int idx = 0; idx < obstacles.size(); idx++)
		{
			obstacles[idx]->ActivarRalenti();
		}
	}
}