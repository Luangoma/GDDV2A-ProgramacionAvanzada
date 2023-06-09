#pragma once
#include "Model.h"
#include "ModelLoader.h"
#include "Solid.h"
class Tren //: public Model
{
private:
    ModelLoader loader;
    Model modelo;

public:
    Tren() : loader(), modelo() {}
    // Setters.
    inline void SetTrainLoader(const ModelLoader &loaderToSet) { this->loader = loaderToSet; }
    inline void SetTrainModel(const Model &modelToSet) { this->modelo = modelToSet; }
    inline void SetPosition(const Vector3D &positionToSet) { this->modelo.SetPosition(positionToSet); }
    inline void SetSpeed(const Vector3D &speedToSet) { this->modelo.SetSpeed(speedToSet); }
    // Getters.
    inline ModelLoader GetTrainLoader() const { return this->loader; }
    inline Model GetTrainModel() const { return this->modelo; }
    // METODOS COMUNES A TODOS LOS TRENES.
    void AddToScene();
    void Render();
};

class Enemy :
    public Solid
{
};
