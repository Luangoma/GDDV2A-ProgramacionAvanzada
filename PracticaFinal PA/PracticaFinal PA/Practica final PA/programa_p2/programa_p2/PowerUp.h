#pragma once
#include "Model.h"
class PowerUp : public Solid {
private:
    float multiplicador;
    Model modelo;
    
public:
    PowerUp(float multiplicadorToSet = 1.25) : multiplicador(multiplicadorToSet) {};

	// GETTERS
    inline float GetMultiplicador() const { return this->multiplicador; }
    inline Model GetModel() const { return this->modelo; }

	// SETTERS
	inline void SetMultiplicador(const float& multiplicadorToSet) { this->multiplicador = multiplicadorToSet; }
	inline void SetModel(const Model& modeloToSet) { this->modelo = modeloToSet; }

    void Update(const float& timeIncrement);
    void Init();
};

