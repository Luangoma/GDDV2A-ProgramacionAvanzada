#pragma once
#include "Scene.h"
#include "SceneLevel.h"
#include <chrono>
#include "Text.h"

using namespace std;
using namespace std::chrono;

class Game
{
private:
	vector<Scene*> scenes;
	Scene* activeScene;

	const float TIME_INCREMENT = 1; //Tiempo en el juego
	const long UPDATE_PERIOD = 0.01; //Tiempo real

	milliseconds initialMilliseconds;
	long lastUpdateTime;



public:
	Game() 
	{
		this->initialMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		this->lastUpdateTime = 0;
	}

	void Init();
	void Render();
	void Update();
	//void ResetearModelos();

	void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);

};

