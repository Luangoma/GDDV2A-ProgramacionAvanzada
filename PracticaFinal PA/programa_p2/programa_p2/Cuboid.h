#pragma once
#include "Solid.h"
#include <GL/glut.h>

class Cuboid : public Solid
{
private:
    float length;
    float height;
    float width;
public:
    Cuboid() : length(0.2), height(0.2), width(0.2), Solid(Vector3D(), Color(0.2, 0.5, 0.1)) {}

    // Metodos virtuales de Solid y otros
    void Render();

    // Metodos propios de la clase
    // GETTERS
    inline float GetLength() const { return this->length; }
    inline float GetHeight() const { return this->height; }
    inline float GetWidth() const { return this->width; }

    // SETTERS
    inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
    inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
    inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

};
