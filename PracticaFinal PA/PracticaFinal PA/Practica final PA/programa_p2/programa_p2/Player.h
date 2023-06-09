#pragma once
//#include "Solid.h"
#include "Model.h"
class Player : public Solid {

private:
    Model modelo;
    bool status;

public:
    Player(Vector3D position = Vector3D(0, 0.5, 5),Vector3D orientation = Vector3D(0,180,0),Color color = Color(0.2, 0.3, 0.8)) 
    {
        status = true;
        modelo.SetPosition(position);
        modelo.SetOrientation(orientation);
        modelo.PaintColor(color);
    }
    // Player(Vector3D position = Vector3D(0,0,0),Vector3D orientation = Vector3D(0,180,0),Color color = Color(0.2, 0.3, 0.8)) : 
    // modelo.SetPosition(position), modelo.SetOrientation(orientation), modelo.PaintColor(color){};
    
    void ProcessKeyPressed(unsigned char key, int px, int py);
    void Parar();
    void Reset();
    inline void SetModel(const Model &modelToSet) { modelo = modelToSet; }
    void PaintPlayer(const Color& color);

    //Métodos virtuales de Solid
    void Render();
    void Update(const float& timeIncrement);


};

