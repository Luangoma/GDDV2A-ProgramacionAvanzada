#include "Vehicle.h"

void Vehicle::Render()
{
	model.Render();
}

void Vehicle::Update(const float &timeIncrement)
{
	SetPosition(model.GetPosition());
	SetOrientation(model.GetOrientation());
	model.Update(timeIncrement);
}

void Vehicle::Reset()
{
	model.SetPosition(initialPosition);
	model.SetOrientation(initialRotation);
	ActivarNormal();
}

Vector3D Vehicle::GetDimensions()
{
	Vector3D *dimensiones = new Vector3D(dimensions);
	if (GetOrientation().GetY() == 180.0) // FRENTE / S
	{
		dimensiones->SetZ(dimensiones->GetZ());
		dimensiones->SetX(dimensiones->GetX());
	}
	else if (GetOrientation().GetY() == 0.0) // ATRAS / S
	{
		dimensiones->SetZ(dimensiones->GetZ());
		dimensiones->SetX(dimensiones->GetX());
	}
	else if (GetOrientation().GetY() == 270.0) // IZQUIERDA / A
	{
		dimensiones->SetZ(dimensiones->GetX());
		dimensiones->SetX(dimensiones->GetZ());
	}
	else if (GetOrientation().GetY() == 90.0) // DERECHA / D
	{
		dimensiones->SetZ(dimensiones->GetX());
		dimensiones->SetX(dimensiones->GetZ());
	}
	return *dimensiones;
}

void Vehicle::ActivarRalenti()
{
	SetActualSpeed(GetActualSpeed() / 2);
	model.SetSpeed(Vector3D(
		model.GetSpeed().GetX() / 2,
		model.GetSpeed().GetY() / 2,
		model.GetSpeed().GetZ() / 2));
}

void Vehicle::ActivarAccelere()
{
	SetActualSpeed(GetActualSpeed() * 2);
	model.SetSpeed(Vector3D(
		model.GetSpeed().GetX() * 2,
		model.GetSpeed().GetY() * 2,
		model.GetSpeed().GetZ() * 2));
}

void Vehicle::ActivarNormal()
{
	SetActualSpeed(GetInitialSpeed());
	model.SetSpeed(Vector3D(
		GetInitialSpeed(), 0, 0));
}
