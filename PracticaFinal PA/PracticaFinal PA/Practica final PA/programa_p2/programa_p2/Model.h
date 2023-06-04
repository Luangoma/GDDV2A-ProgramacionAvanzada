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

	void AddTriangle(Triangle triangle);
	void PaintColor(Color color);
	void Clear();

	void Render();
};
