#include "SceneGameOver.h"

void SceneGameOver::Init()
{
    //Scene::Init();
    
    string estado;
    if (status)
    {
        estado = "Ha ganado";
    }
    else
    {
        estado = "Ha perdido";
    }
    Text* titulo = new Text();
	titulo->SetText(estado);
    titulo->SetPosition(Vector3D(-0.1,0.0,-1.0));
    titulo->SetColor(Color(1, 1, 1));
    titulos.push_back(titulo);
    Text* titulo1 = new Text();
	titulo1->SetText("Pulse R para volver al inicio");
    titulo1->SetPosition(Vector3D(-0.25,-0.2,-1.0));
    titulo1->SetColor(Color(1, 1, 1));
    titulos.push_back(titulo1);
    
    for (int i = 0; i < 2; i++) // Creamos las vias y las añadimos
	{
		AddGameObject(titulos[i]);
	}
    // CAMARA 
	Camera *camara = new Camera();
	camara->SetPosition(Vector3D(0.0,0.0,0.0));
	camara->SetOrientation(Vector3D(0.0,0.0,0.0));
	SetCamera(*camara);
    /*
    Text *textoJugarNivel2 = new Text();
	textoJugarNivel2->SetText("Jugar Nivel 2 - pulse 2");
	textoJugarNivel2->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel2->SetColor(Color(1, 1, 1));
	AddGameObject(textoJugarNivel2);
    */

}
void SceneGameOver::Update(const float &timeIncrement)
{
}

void SceneGameOver::ProcessKeyPressed(unsigned char key, int px, int py)
{
}