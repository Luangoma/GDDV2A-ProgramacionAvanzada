#pragma once
#include "Triangle.h"
#include <GL/glut.h>
#include <vector>

using namespace std;

class Model : public Solid
{
private:
	vector<Triangle> triangles;

public:
	Model() {}

	// Metodos virtuales de Solid y otros
	void Render();

	// Metodos propios de la clase
	void AddTriangle(Triangle triangle);
	void PaintColor(Color color);
	void Clear();
};
