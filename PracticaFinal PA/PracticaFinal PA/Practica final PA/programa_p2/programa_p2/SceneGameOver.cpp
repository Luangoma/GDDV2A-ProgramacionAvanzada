#include "SceneGameOver.h"
#include <iostream>

void SceneGameOver::Init()
{
    // Scene::Init();

    std::cout << "Carga de la escena resultado" << std::endl << std::endl;
    // CAMARA
    Camera *camara = new Camera();
    camara->SetPosition(Vector3D(0.0, 0.0, 0.0));
    camara->SetOrientation(Vector3D(0.0, 0.0, 0.0));
    SetCamera(*camara);
    // Eleccion de texto
    string estado;
    if (status)
    {
        estado = "Ha ganado";
    }
    else
    {
        estado = "Ha perdido";
    }
    Text *titulo = new Text();
    titulo->SetText(estado);
    titulo->SetPosition(Vector3D(-0.1, 0.0, -1.0));
    titulos.push_back(titulo);
    titulo = new Text();
    titulo->SetText("Pulse R para volver al inicio");
    titulo->SetPosition(Vector3D(-0.25, -0.2, -1.0));
    titulos.push_back(titulo);

    for (int i = 0; i < titulos.size(); i++) // Añadimos los textos
    {
        titulos[i]->SetColor(Color(1, 1, 1));
        AddGameObject(titulos[i]);
    }
}

void SceneGameOver::Update(const float &timeIncrement)
{
}

void SceneGameOver::ProcessKeyPressed(unsigned char key, int px, int py)
{
}