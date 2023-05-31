#include "Triangle.h"

void Triangle::Render()
{
	glBegin(GL_TRIANGLES);

	glColor3f(this->color0.GetRed(), this->color0.GetGreen(), this->color0.GetBlue());
	glNormal3f(this->normal0.GetX(), this->normal0.GetY(), this->normal0.GetZ());
	glVertex3f(this->vertex0.GetX(), this->vertex0.GetY(), this->vertex0.GetZ());

	glColor3f(this->color1.GetRed(), this->color1.GetGreen(), this->color1.GetBlue());
	glNormal3f(this->normal1.GetX(), this->normal1.GetY(), this->normal1.GetZ());
	glVertex3f(this->vertex1.GetX(), this->vertex1.GetY(), this->vertex1.GetZ());

	glColor3f(this->color2.GetRed(), this->color2.GetGreen(), this->color2.GetBlue());
	glNormal3f(this->normal2.GetX(), this->normal2.GetY(), this->normal2.GetZ());
	glVertex3f(this->vertex2.GetX(), this->vertex2.GetY(), this->vertex2.GetZ());

	glEnd();
}
