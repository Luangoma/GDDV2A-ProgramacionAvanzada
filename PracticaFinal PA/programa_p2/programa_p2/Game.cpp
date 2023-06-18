#include "Game.h"
#include "SceneMenu.h"
#include "SceneLevel.h"
#include "SceneGameOver.h"
#include "SceneCreditos.h"
#include "Scene.h"
#include <iostream>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()

void Game::ProcessKeyPressed(unsigned char key, int px, int py)
{
	cout << "Tecla pulsada: " << key << endl;

	if (key == 'R' || key == 'r')
	{
		this->activeScene->Reset();
		this->activeScene = this->scenes[0];
	}

	int index = key - '0';

	if (index < this->scenes.size())
	{
		this->activeScene = this->scenes[index];
	}
	// Al hacer upcasting, usamos processKeyPressed como método virtual para que se ejecute el metodo mas derivado.
	activeScene->ProcessKeyPressed(key, px, py);
}

void Game::ProcessMouseMovement(int x, int y)
{
	cout << "Movimiento del mouse: " << x << ", " << y << endl;
	activeScene->ProcessMouseMovement(x, y);
}

void Game::ProcessMouseClick(int button, int state, int x, int y)
{
	cout << "Clic del mouse: " << button << " " << state << " " << x << " " << y << endl;
	activeScene->ProcessMouseClick(button, state, x, y);
}

void Game::Init()
{
	cout << "GAME INIT..." << endl;
	srand(time(NULL));

	SceneMenu *sceneMenu = new SceneMenu();
	sceneMenu->Init();
	this->scenes.push_back(sceneMenu);

	SceneLevel *sceneLevel;
	for (int i = 1; i <= 3; i++)
	{
		sceneLevel = new SceneLevel(i);
		sceneLevel->Init();
		this->scenes.push_back(sceneLevel);
	}
	SceneCreditos *sceneFinal = new SceneCreditos();
	sceneFinal->Init();
	this->scenes.push_back(sceneFinal);

	SceneGameOver *sceneOverWinner = new SceneGameOver(true);
	sceneOverWinner->Init();
	this->scenes.push_back(sceneOverWinner);

	SceneGameOver *sceneOverLoser = new SceneGameOver(false);
	sceneOverLoser->Init();
	this->scenes.push_back(sceneOverLoser);

	std::cout << "Escenas cargadas: "<< scenes.size() << std::endl;
	this->activeScene = this->scenes[0];
}

void Game::Render()
{
	if (this->activeScene != nullptr)
		this->activeScene->Render();
}

void Game::Update()
{
	milliseconds currenTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

	bool timeCondition = currenTime.count() - this->initialMilliseconds.count() - this->lastUpdateTime > UPDATE_PERIOD;

	if (timeCondition)
	{
		if (this->activeScene != nullptr)
			this->activeScene->Update(TIME_INCREMENT);
		this->lastUpdateTime = currenTime.count() - this->initialMilliseconds.count();
	}

	if (activeScene->CheckStatus() == 1)
	{
		// Ir a pantalla de ganar.
		this->activeScene->Reset();
		this->activeScene = this->scenes[scenes.size() - 2];
	}
	else if (activeScene->CheckStatus() == 2)
	{
		// Ir a pantalla de perder.
		this->activeScene->Reset();
		this->activeScene = this->scenes[scenes.size() - 1];
	}
}