#pragma once
#include "Solid.h"
#include "ModelLoader.h"
#include "Model.h"

class PowerUp : public Solid
{
protected:
    Model model;
    bool active;

public:
    PowerUp(Model modelToSet,
        Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
        Color colorToSet = Color(0.0, 0.0, 0.0),
        bool isActiveToSet = true)
        : model(modelToSet),
        active(isActiveToSet)
    {
        //Propiedades iniciales del personaje.
        SetPosition(positionToSet);
        model.SetPosition(Vector3D(positionToSet));
        model.SetOrientationSpeed(Vector3D(0, 4, 0));
        model.PaintColor(colorToSet);
    }
    // Metodos virtuales de Solid y otros
    void Render();
    void Update(const float& timeIncrement);
    void Reset();

    // GETTERS
    inline Model GetModel() const { return this->model; }
    inline bool GetStatus() const { return this->active; }

    // SETTERS
    inline void SetModel(const Model& modelToSet) { this->model = modelToSet; }
    inline void SetStatus(const bool& isActiveToSet) { this->active = isActiveToSet; }

    // Metodos propios de la clase
    virtual void ApplyEffect();
};

