#include <iostream>
#include "Player.h"

void Player::Init()
{
    //Cargar modelo del personaje.
	// Carga del modelo 'Cop' (Jugador)
	loader = new ModelLoader();
	loader->LoadModel("..\\..\\3dModels\\Cop.obj");
	std::cout << "Carga del personaje" << std::endl;
    modelo = loader->GetModel();
    //Propiedades iniciales del personaje.
    modelo.SetPosition(Vector3D(0, 0.5, 5));
    modelo.SetOrientation(Vector3D(0, 180, 0));
    modelo.SetColor(Color(0.2, 0.3, 0.8));
}

void Player::Render() 
{
    modelo.Render();
}

void Player::Update(const float& timeIncrement)
{
    modelo.Update(timeIncrement);
}

void Player::ProcessKeyPressed(unsigned char key, int px, int py)
{
	switch (key)
	{
	case 'w':
		// mover el personajeActivo hacia adelante
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 's':
		// mover el personajeActivo hacia atras
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'a':
		// mover el personajeActivo hacia la izquierda
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'd':
		// mover el personajeActivo hacia la derecha
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	case 'W':
		// mover el objeto hacia adelante
		modelo.SetSpeed(Vector3D(0.0, 0.0, -0.1));
		modelo.SetOrientation(Vector3D(0.0, 180.0, 0.0));
		break;
	case 'S':
		// mover el personajeActivo hacia atras
		modelo.SetSpeed(Vector3D(0.0, 0.0, 0.1));
		modelo.SetOrientation(Vector3D(0.0, 0.0, 0.0));
		break;
	case 'A':
		// mover el personajeActivo hacia la izquierda
		modelo.SetSpeed(Vector3D(-0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 270.0, 0.0));
		break;
	case 'D':
		// mover el personajeActivo hacia la derecha
		modelo.SetSpeed(Vector3D(0.1, 0.0, 0.0));
		modelo.SetOrientation(Vector3D(0.0, 90.0, 0.0));
		break;
	default:
		//SetSpeed(Vector3D(0.0, 0.0, 0.0));
		break;
	}
}

void Player::Parar()
{
    modelo.SetSpeed(Vector3D(0, 0, 0));
}

void Player::Reset()
{
    modelo.SetPosition(Vector3D(0, 0.5, 5));
    modelo.SetOrientation(Vector3D(0, 180, 0));
    Parar();
}