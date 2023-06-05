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

	if(key == 'R' || key == 'r'){
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
	// activeScene = sceneMenu;
	cout << "GAME INIT..." << endl;
	srand(time(NULL));

	SceneMenu *sceneMenu = new SceneMenu();
	sceneMenu->Init();
	this->scenes.push_back(sceneMenu);

	this->activeScene = this->scenes[0];

	SceneLevel *sceneLevelNivel1 = new SceneLevel(true, 1);
	sceneLevelNivel1->Init();
	this->scenes.push_back(sceneLevelNivel1);

	SceneLevel *sceneLevelNivel2 = new SceneLevel(true, 2);
	sceneLevelNivel2->Init();
	this->scenes.push_back(sceneLevelNivel2);

	SceneLevel *sceneLevelNivel3 = new SceneLevel(true, 3);
	sceneLevelNivel3->Init();
	this->scenes.push_back(sceneLevelNivel3);
	SceneCreditos *sceneFinal = new SceneCreditos();
	sceneFinal->Init();
	this->scenes.push_back(sceneFinal);
	/**/
	SceneGameOver* sceneOverWinner = new SceneGameOver(true);
	sceneOverWinner->Init();
	this->scenes.push_back(sceneOverWinner);

	SceneGameOver* sceneOverLoser = new SceneGameOver(false);
	sceneOverLoser->Init();
	this->scenes.push_back(sceneOverLoser);
	//*/

	/**
	// // // //Menú inicial
	Scene* scene0 = new Scene();
	scene0->SetDrawVertexes(false);
	scene0->SetDrawBox(true);
	scene0->Init();
	scene0->SetBoundary(Vector3D(100, 100, 100));
	scene0->SetNivel(0);
	scene0->SetActivo(false);
	// CAMARA PRESENTACION (60 grados)
	Camera* camara0 = new Camera();
	camara0->SetPosition(Vector3D(5, -2, 20));
	camara0->SetOrientation(Vector3D(15.0, 135.0, 0.0));
	scene0->SetCamera(*camara0);
	// CARGAR MODELOS
	viasTren = new Model();
	*viasTren = loader->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.3, 0.3, 0.3));
	// // // MENÚ
	vector<Model*> arrayVias0;
	desplazamiento = 0.0;
	for (int i = 0; i < 3; i++) // Creamos las vias y las añadimos
	{
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX() + 50, viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() + desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias0.push_back(viasTren);
		desplazamiento += 5.0;
		scene0->AddGameObject(arrayVias0[i]);
		viasTren = new Model();
	}
	// Tren del nivel 1
	Model* tren1M = new Model();
	*tren1M = loaderLvl1->GetModel();
	tren1M->SetPosition(Vector3D(15.0, 1.7, 0.0));
	tren1M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren1M->PaintColor(Color(0.1, 0.1, 0.1));
	scene0->AddTren(tren1M);
	scene0->AddGameObject(tren1M);
	// Tren del nivel 2
	Model* tren2M = new Model();
	*tren2M = loaderLvl2->GetModel();
	tren2M->SetPosition(Vector3D(25.0, 1.1, 5.0));
	tren2M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren2M->PaintColor(Color(0.73, 0.56, 0.1));
	scene0->AddTren(tren2M);
	scene0->AddGameObject(tren2M);
	// Tren del nivel 3
	Model* tren3M = new Model();
	*tren3M = loaderLvl3->GetModel();
	tren3M->SetPosition(Vector3D(30, 1.0, 10.0));
	tren3M->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	tren3M->PaintColor(Color(0.4, 0.42, 0.4));
	scene0->AddTren(tren3M);
	scene0->AddGameObject(tren3M);
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(-15, 0.5, -5));
	personaje->SetOrientation(Vector3D(0.0, 160.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene0->AddGameObject(personaje);
	scene0->AddPersonaje(personaje);
	// TEXTO
	desplazamiento = -1;
	Text* textoNombre = new Text();
	textoNombre->SetText("ESCAPE TRAIN");
	textoNombre->SetPosition(Vector3D(0, desplazamiento, -8));
	textoNombre->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoNombre);
	desplazamiento -= 1;
	Text* textoMenu = new Text();
	textoMenu->SetText("MENU - pulse 0");
	textoMenu->SetPosition(Vector3D(0, desplazamiento, -8));
	textoMenu->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoMenu);
	desplazamiento -= 1;
	Text* textoJugarNivel1 = new Text();
	textoJugarNivel1->SetText("Jugar Nivel 1 - pulse 1");
	textoJugarNivel1->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel1->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoJugarNivel1);
	desplazamiento -= 1;
	Text* textoJugarNivel2 = new Text();
	textoJugarNivel2->SetText("Jugar Nivel 2 - pulse 2");
	textoJugarNivel2->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel2->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoJugarNivel2);
	desplazamiento -= 1;
	Text* textoJugarNivel3 = new Text();
	textoJugarNivel3->SetText("Jugar Nivel 3 - pulse 3");
	textoJugarNivel3->SetPosition(Vector3D(0, desplazamiento, -8));
	textoJugarNivel3->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoJugarNivel3);
	desplazamiento -= 1;
	Text* textoCreditos = new Text();
	textoCreditos->SetText("Creditos - pulse 4");
	textoCreditos->SetPosition(Vector3D(0, desplazamiento, -8));
	textoCreditos->SetColor(Color(1, 1, 1));
	scene0->AddGameObject(textoCreditos);
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene0->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene0->AddGameObject(meta);
	scene0->SetMeta(meta);
	// Pared 1 / Cielo
	meta = new Cuboid();
	meta->SetPosition(Vector3D(scene0->GetBoundary().GetX(), scene0->GetBoundary().GetY() / 2, 0.0));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.0, 0.67, 0.89));
	meta->SetLength(0.2);
	meta->SetHeight(scene0->GetBoundary().GetY());
	meta->SetWidth(scene0->GetBoundary().GetZ());
	scene0->AddGameObject(meta);
	scene0->SetMeta(meta);
	// Pared 2 / Cielo
	meta = new Cuboid();
	meta->SetPosition(Vector3D(scene0->GetBoundary().GetX() / 3, scene0->GetBoundary().GetY() / 2, scene0->GetBoundary().GetZ() / 2));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.0, 0.67, 0.89));
	meta->SetLength(scene0->GetBoundary().GetX()*2);
	meta->SetHeight(scene0->GetBoundary().GetY());
	meta->SetWidth(0.2);
	scene0->AddGameObject(meta);
	scene0->SetMeta(meta);
	//*/

	/**
	// // // //Primera escena
	std::cout << "Carga de la primera escena" << std::endl;
	SceneLevel* scene1 = new SceneLevel();
	scene1->SetDrawVertexes(false);
	scene1->SetDrawBox(true);
	scene1->Init();
	scene1->SetBoundary(Vector3D(50, 50, 100));
	scene1->SetNivel(1);
	scene1->SetActivo(true);
	// CAMARA EN CENITAL (60 grados)
	Camera* camara1 = new Camera();
	camara1->SetPosition(Vector3D(0, 4, 18));
	camara1->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	scene1->SetCamera(*camara1);
	// CARGAR MODELOS
	*viasTren = loaderVias->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.6, 0.3, 0.3));
	// // //NIVEL FACIL -> 3 vias.
	vector<Model*> arrayVias1;
	const int easyMode = 3;
	desplazamiento = 0.0;
	for (int i = 0; i < easyMode; i++) // Creamos las vias y las añadimos
	{
		viasTren = new Model();
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX(), viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() - desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias1.push_back(viasTren);
		desplazamiento += 7.0;
		scene1->AddGameObject(arrayVias1[i]);
	}
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene1->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene1->AddGameObject(meta);
	scene1->SetMeta(meta);
	for (int i = 0; i < easyMode; i++) // Creamos los trenes y los añadimos
	{
		// Posicion Inicial Aleatoria
		float randomX = ((rand() % int(scene1->GetBoundary().GetX())) - int(scene1->GetBoundary().GetX() / 2));
		std::cout << (randomX) << std::endl;

		trenLvl1 = new Model();
		*trenLvl1 = loaderLvl1->GetModel();
		trenLvl1->SetPosition(Vector3D(randomX, 1.7, -7.0 * i));
		trenLvl1->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
		trenLvl1->PaintColor(Color(0.1, 0.1, 0.1));
		trenLvl1->SetSpeed(Vector3D((i % 2 == 0) ? 0.1 : -0.1, 0.0, 0.0));

		scene1->AddTren(trenLvl1);
		scene1->AddGameObject(trenLvl1);
	}
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(0, 0.5, 5));
	personaje->SetOrientation(Vector3D(0.0, 180.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene1->AddGameObject(personaje);
	scene1->AddPersonaje(personaje);
	//*/

	/**
	// // // //Segunda escena
	std::cout << "Carga de la segunda escena" << std::endl;
	Scene* scene2 = new Scene();
	scene2->SetDrawVertexes(false);
	scene2->SetDrawBox(true);
	scene2->Init();
	scene2->SetBoundary(Vector3D(90, 300, 300));
	scene2->SetNivel(2);
	scene2->SetActivo(true);
	// CAMARA EN CENITAL (60 grados)
	Camera* camara2 = new Camera();
	camara2->SetPosition(Vector3D(0, 4, 36));
	camara2->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	scene2->SetCamera(*camara2);
	// CARGAR MODELOS
	viasTren = new Model();
	*viasTren = loader->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.6, 0.3, 0.3));
	// // //NIVEL MEDIO -> 5 vias.
	vector<Model*> arrayVias2;
	const int mediumMode = 5;
	desplazamiento = 0.0;
	for (int i = 0; i < mediumMode; i++) // Creamos las vias y las añadimos
	{
		viasTren = new Model();
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX(), viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() - desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias2.push_back(viasTren);
		desplazamiento += 7.0;
		scene2->AddGameObject(arrayVias2[i]);
	}
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene2->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene2->AddGameObject(meta);
	scene2->SetMeta(meta);
	for (int i = 0; i < mediumMode; i++) // Creamos los trenes y los añadimos
	{
		// Posicion Inicial Aleatoria
		float randomX = ((rand() % int(scene2->GetBoundary().GetX())) - int(scene2->GetBoundary().GetX() / 2));
		std::cout << (randomX) << std::endl;

		trenLvl2 = new Model();
		*trenLvl2 = loaderLvl2->GetModel();
		trenLvl2->SetPosition(Vector3D(randomX, 1.1, -7.0 * i));
		trenLvl2->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
		trenLvl2->PaintColor(Color(0.73, 0.56, 0.1));
		trenLvl2->SetSpeed(Vector3D((i % 2 == 0) ? 0.3 : -0.3, 0.0, 0.0));

		scene2->AddTren(trenLvl2);
		scene2->AddGameObject(trenLvl2);
	}
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(0, 0.5, 5));
	personaje->SetOrientation(Vector3D(0.0, 180.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene2->AddGameObject(personaje);
	scene2->AddPersonaje(personaje);
	//*/

	/**
	// // // //Tercera escena
	std::cout << "Carga de la tercera escena" << std::endl;
	Scene* scene3 = new Scene();
	scene3->SetDrawVertexes(false);
	scene3->SetDrawBox(true);
	scene3->Init();
	scene3->SetBoundary(Vector3D(100, 300, 300));
	scene3->SetNivel(3);
	scene3->SetActivo(true);
	// CAMARA EN CENITAL (60 grados)
	Camera* camara3 = new Camera();
	camara3->SetPosition(Vector3D(0, 8, 40));
	camara3->SetOrientation(Vector3D(60.0, 0.0, 0.0));
	scene3->SetCamera(*camara3);
	// CARGAR MODELOS
	viasTren = new Model();
	*viasTren = loader->GetModel();
	viasTren->SetPosition(Vector3D(0, 0, 0));
	viasTren->PaintColor(Color(0.6, 0.3, 0.3));
	// // //NIVEL DIFICIL -> 7 vias.
	vector<Model*> arrayVias3;
	const int hardMode = 7;
	desplazamiento = 0.0;
	for (int i = 0; i < hardMode; i++) // Creamos las vias y las añadimos
	{
		viasTren = new Model();
		*viasTren = loaderVias->GetModel();
		viasTren->SetPosition(Vector3D(viasTren->GetPosition().GetX(), viasTren->GetPosition().GetY(), viasTren->GetPosition().GetZ() - desplazamiento));
		viasTren->PaintColor(Color(0.3, 0.3, 0.3));
		arrayVias3.push_back(viasTren);
		desplazamiento += 7.0;
		scene3->AddGameObject(arrayVias3[i]);
	}
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -desplazamiento));
	meta->SetOrientation(Vector3D(0.0, 0.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene3->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene3->AddGameObject(meta);
	scene3->SetMeta(meta);
	for (int i = 0; i < hardMode; i++) // Creamos los trenes y los añadimos
	{
		// Posicion Inicial Aleatoria
		float randomX = ((rand() % int(scene3->GetBoundary().GetX())) - int(scene3->GetBoundary().GetX() / 2));
		std::cout << (randomX) << std::endl;

		trenLvl3 = new Model();
		*trenLvl3 = loaderLvl3->GetModel();
		trenLvl3->SetPosition(Vector3D(randomX, 1, -7.0 * i));
		trenLvl3->SetOrientation(Vector3D(0.0, (i % 2 == 0) ? 180.0 : 0.0, 0.0));
		trenLvl3->PaintColor(Color(0.4, 0.4, 0.4));
		trenLvl3->SetSpeed(Vector3D((i % 2 == 0) ? 1 : -1, 0.0, 0.0));

		scene3->AddTren(trenLvl3);
		scene3->AddGameObject(trenLvl3);
	}
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(0, 0.5, 5));
	personaje->SetOrientation(Vector3D(0.0, 180.0, 0.0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene3->AddGameObject(personaje);
	scene3->AddPersonaje(personaje);
	//*/

	/**
	// // // //Creditos finales
	Scene* scene4 = new Scene();
	scene4->SetDrawVertexes(false);
	scene4->SetDrawBox(true);
	scene4->Init();
	scene4->SetBoundary(Vector3D(100, 100, 100));
	scene4->SetNivel(4);
	scene4->SetActivo(false);
	// CAMARA EN CENITAL (90 grados)
	Camera* camara4 = new Camera();
	camara4->SetPosition(Vector3D(-5, -5, 20));
	camara4->SetOrientation(Vector3D(90.0, 0.0, 0.0));
	scene4->SetCamera(*camara4);
	// // // CREDITOS
	for (int i = 0; i < 3; i++) // Creamos las vias y las añadimos
	{
		scene4->AddGameObject(arrayVias0[i]);
	}
	// Tren del nivel 1
	scene4->AddTren(tren1M);
	scene4->AddGameObject(tren1M);
	// Tren del nivel 2
	scene4->AddTren(tren2M);
	scene4->AddGameObject(tren2M);
	// Tren del nivel 3
	scene4->AddTren(tren3M);
	scene4->AddGameObject(tren3M);
	// Personaje
	personaje = new Model();
	*personaje = loaderPersonaje->GetModel();
	personaje->SetPosition(Vector3D(5, 0, -5));
	personaje->SetOrientation(Vector3D(0, -90, 0));
	personaje->PaintColor(Color(0.2, 0.3, 0.8));
	scene4->AddGameObject(personaje);
	scene4->AddPersonaje(personaje);
	// TEXTO
	desplazamiento = -2.5;
	Text* texto0 = new Text();
	texto0->SetText("Autores:");
	texto0->SetPosition(Vector3D(4, 0, desplazamiento - 1));
	texto0->SetColor(Color(1, 1, 1));
	scene4->AddGameObject(texto0);
	desplazamiento += 5;
	Text* texto1 = new Text();
	texto1->SetText("Juan Alessandro Vazquez Bustos");
	texto1->SetPosition(Vector3D(-2, 0, desplazamiento));
	texto1->SetColor(Color(1, 1, 1));
	scene4->AddGameObject(texto1);
	desplazamiento += 5;
	Text* texto2 = new Text();
	texto2->SetText("Monica Varas Garcia");
	texto2->SetPosition(Vector3D(-8, 0, desplazamiento));
	texto2->SetColor(Color(1, 1, 1));
	scene4->AddGameObject(texto2);
	desplazamiento += 5;
	Text* texto3 = new Text();
	texto3->SetText("Luis Antonio Gonzalez Martinez");
	texto3->SetPosition(Vector3D(-14, 0, desplazamiento));
	texto3->SetColor(Color(1, 1, 1));
	scene4->AddGameObject(texto3);
	desplazamiento += 5;
	// Meta
	meta = new Cuboid();
	meta->SetPosition(Vector3D(0, 0, -10));
	meta->SetOrientation(Vector3D(0.0, 45.0, 0.0));
	meta->SetColor(Color(0.8, 0.1, 0.1));
	meta->SetLength(scene4->GetBoundary().GetX() * 2);
	meta->SetHeight(0.2);
	meta->SetWidth(0.2);
	scene4->AddGameObject(meta);
	scene4->SetMeta(meta);
	//*/

	/**
	// GUARDADO DE ESCENAS
	std::cout << "Subida de escenas" << std::endl;
	this->scenes.push_back(scene0);
	this->scenes.push_back(scene1);
	this->scenes.push_back(scene2);
	this->scenes.push_back(scene3);
	this->scenes.push_back(scene4);
	std::cout << scenes.size() << std::endl;
	this->activeScene = this->scenes[0];
	//*/
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