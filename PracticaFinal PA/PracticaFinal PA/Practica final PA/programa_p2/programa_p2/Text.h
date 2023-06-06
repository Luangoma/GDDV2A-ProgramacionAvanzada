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

	inline string GetText() { return this->text; }
	inline void SetText(string textToSet) { this->text = textToSet; }

	void Render();
};
