#pragma once
#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include "Text.h"
#include "Player.h"
#include "Enemy.h"
#include "Obstacle.h"

using namespace std;

class Scene
{
private:
	bool drawVertexes, drawBox;
	Camera camera;

protected:
	Vector3D boundary;
	vector<Solid *> gameObjects;
	float desplazamiento, incremento;
	ModelLoader *loaderVias, *loaderTren, *loaderPersonaje;
	Model *via;
	Player *jugador;
	Enemy *enemigo;
	Obstacle *obstaculo;
	vector<Obstacle *> obstaculos;

public:
	Scene(Vector3D boundaryArgument = Vector3D(10, 8, 10), bool drawVertexesArgument = false, bool drawBoxArgument = true) : 
	boundary(boundaryArgument), drawVertexes(drawVertexesArgument), drawBox(drawBoxArgument){};

	// Metodos virtuales de Solid y otros
	void Render();
	virtual void Update(const float &timeIncrement);

	// Metodos propios de la clase
	inline void AddGameObject(Solid *gameObject) { this->gameObjects.push_back(gameObject); }
	inline void AddObstaculo(Obstacle *obstaculo) { this->obstaculos.push_back(obstaculo); AddGameObject(obstaculo); }
	void LoadModelNvl1();
	void LoadModelNvl2();
	void LoadModelNvl3();

	// GETTERS
	inline Vector3D GetBoundary() const { return this->boundary; }
	inline bool GetDrawVertexes() const { return this->drawVertexes; }
	inline bool GetDrawBox() const { return this->drawBox; }
	inline Camera GetCamera() const { return this->camera; }

	// SETTERS
	inline void SetBoundary(const Vector3D &boundaryToSet) { this->boundary = boundaryToSet; }
	inline void SetDrawVertexes(const bool &drawVertexesToSet) { this->drawVertexes = drawVertexesToSet; }
	inline void SetDrawBox(const bool &drawBoxToSet) { this->drawBox = drawBoxToSet; }
	inline void SetCamera(const Camera &cameraToSet) { this->camera = cameraToSet; }

	void Init();
	virtual void Reset();
	virtual int CheckStatus();

	virtual void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};
