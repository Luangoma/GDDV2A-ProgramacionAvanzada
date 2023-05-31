#pragma once
#include "Scene.h"
#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"

class SceneLevel : public Scene
{
private:
    

	Cuboid* meta;
	bool activo;

	
    int nivel;

	void checkBoundary();
public:

    SceneLevel(bool activoArgument = true) 
        : Scene(), activo(activoArgument) {}

    void Init();

	inline void SetNivel(const int& nivelToSet) { this->nivel = nivelToSet; };
	inline void SetMeta(Cuboid* metaToSet) { this->meta = metaToSet; }
	inline void SetActivo(bool activoToSet) { this->activo = activoToSet; }

    void Update(const float& timeIncrement);
    void checkColisiones();
    void ProcessKeyPressed(unsigned char key, int px, int py);

    void haPerdido();
	void haGanado();

};

