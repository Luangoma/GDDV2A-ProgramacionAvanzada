#pragma once
#include "Solid.h"
#include <string>

using namespace std;

class Text : public Solid
{
private:
	string text;

public:
	Text(string textArgument = "==") : Solid(), text(textArgument) {}
	
	// Metodos virtuales de Solid y otros
	void Render();

	// GETTERS
	inline string GetText() { return this->text; }

	// SETTERS
	inline void SetText(string textToSet) { this->text = textToSet; }

};
