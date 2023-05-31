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
    Cuboid() : length(0.4), height(0.2), width(0.1), Solid(Vector3D(), Color(0.2, 0.5, 0.1)) {}

    inline float GetLength() const { return this->length; }
    inline void SetLength(const float& lengthToSet) { this->length = lengthToSet; }
    inline float GetHeight() const { return this->height; }
    inline void SetHeight(const float& heightToSet) { this->height = heightToSet; }
    inline float GetWidth() const { return this->width; }
    inline void SetWidth(const float& widthToSet) { this->width = widthToSet; }

    void Render();
};

