#pragma once
#include "Solid.h"
#include <vector>
#include "Text.h"

class Interface : public Solid
{
private:
    vector<Text> textos;
public:

    Interface() {}

    void Render();
    void Update(const float& timeIncrement);
    
    inline void AddText(const Text& textToSet) { textos.push_back(textToSet); }
    void Sort();
};

