#pragma once
#include "Solid.h"
#include "Model.h"
class Vehicle : public Solid
{
private:
    Model model;
    float initialSpeed,actualSpeed;
    Vector3D initialPosition,initialRotation,dimensions;
public:
    Vehicle() = default;
    Vehicle(Model modelToSet,
        Vector3D positionToSet = Vector3D(0.0, 0.0, 0.0),
        Vector3D orientationToSet = Vector3D(0.0, 0.0, 0.0),
        Vector3D dimensionsToSet = Vector3D(0.0, 0.0, 0.0),
        Color colorToSet = Color(0.0, 0.0, 0.0),
        float initialSpeedToSet = 0.0)
        : model(modelToSet), 
        initialPosition(positionToSet), 
        initialRotation(orientationToSet),
        dimensions(dimensionsToSet),
        initialSpeed(initialSpeedToSet),
        actualSpeed(initialSpeedToSet)
    {
        SetPosition(positionToSet);
        model.SetPosition(positionToSet);
        model.SetOrientation(orientationToSet);
        model.PaintColor(colorToSet);
        model.SetSpeed(Vector3D(initialSpeedToSet, 0.0, 0.0));
    }

    // Metodos virtuales de Solid y otros
    void Render();
    void Update(const float& timeIncrement);
    void Reset();

    // SOBRECARGAS
    inline void SetPosition(const Vector3D& positionToSet) { Solid::SetPosition(positionToSet); this->model.SetPosition(positionToSet); }
    inline void SetOrientation(const Vector3D& orientationToSet) { Solid::SetOrientation(orientationToSet); this->model.SetOrientation(orientationToSet); }
    inline void SetSpeed(const Vector3D& speedToSet) { Solid::SetSpeed(speedToSet); this->model.SetSpeed(speedToSet); }

    // Metodos propios de la clase
    void ActivarRalenti();  // Ralentizar la velocidad al modelo
    void ActivarAccelere(); // Acelerar la velocidad al modelo
    void ActivarNormal();   // Normalizar la velocidad al modelo

    // GETTERS
    inline Model GetModel() const { return this->model; }
    inline Vector3D GetInitialPosition() const { return this->initialPosition; }
    inline Vector3D GetInitialRotation() const { return this->initialRotation; }
    inline float GetInitialSpeed() const { return this->initialSpeed; }
    inline float GetActualSpeed() const { return this->actualSpeed; }
    Vector3D GetDimensions(); // Devuelve el vector de dimensiones del enemigo.

    // SETTER
    inline void SetModel(const Model& modelToSet) { this->model = modelToSet; }
    inline void SetInitialPosition(const Vector3D& initialPositionToSet) { this->initialPosition = initialPositionToSet; }
    inline void SetInitialRotation(const Vector3D& initialRotationToSet) { this->initialPosition = initialRotationToSet; }
    inline void SetActualSpeed(const float& actualSpeedToSet) { this->actualSpeed = actualSpeedToSet; }
    inline void SetDimensions(const Vector3D& dimensionsToSet) { this->initialPosition = dimensionsToSet; }
};
