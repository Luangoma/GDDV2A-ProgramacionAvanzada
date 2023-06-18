#include "Model.h"

void Model::AddTriangle(Triangle triangle)
{
	this->triangles.push_back(triangle);
}

void Model::Render()
{
	glPushMatrix();
	glTranslatef(GetPosition().GetX(), GetPosition().GetY(), GetPosition().GetZ());
	glColor3f(GetColor().GetRed(), GetColor().GetGreen(), GetColor().GetBlue());
	glRotatef(GetOrientation().GetX(), 1.0, 0.0, 0.0);
	glRotatef(GetOrientation().GetY(), 0.0, 1.0, 0.0);
	glRotatef(GetOrientation().GetZ(), 0.0, 0.0, 1.0);
	
	for (Triangle& triangle : this->triangles)
	{
		triangle.Render();
	}
	
	glPopMatrix();
}

void Model::PaintColor(Color color)
{
	for (Triangle& triangle : this->triangles)
	{
		triangle.SetColor0(color);
		triangle.SetColor1(color);
		triangle.SetColor2(color);
	}
}

void Model::Clear()
{
	this->triangles.clear();
}
