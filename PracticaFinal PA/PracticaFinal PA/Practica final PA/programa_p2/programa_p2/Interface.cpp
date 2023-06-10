#include "Interface.h"

void Interface::Render()
{
    //Render de cada texto en el vector.
    for (Text texto : textos)
    {
        texto.Render();
    }

}

void Interface::Update(const float& timeIncrement)
{
    //Update de cada texto en el vector.
    for (Text texto : textos)
    {
        texto.Update(timeIncrement);
    }
}

void Interface::Sort()
{
    float desplazamiento = 0.0;
    for (Text texto : textos)
    {
        texto.SetPosition(Vector3D(GetPosition().GetX(), GetPosition().GetY() + desplazamiento, GetPosition().GetZ()));
        desplazamiento++;
    }
}