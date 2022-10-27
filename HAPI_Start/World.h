//Librarys included:
#pragma once
#include <HAPI_lib.h>
#include <cmath>
#include "Rectangle.h"
#include "Visualisation.h"
#include "playerEntity.h"
#include "enemyEntity.h"
#include <vector>
class Entity;

class World
{
public:
	//Constructor and Destructor for the World class
	~World();
	World() = default;

	//Declaring Class functions for the World
	void Run();
	void LoadLevel();
	void createPlayerbullet(float posx, float posy);

	//Declaring Class Variables for the World
	//Variables for the time management:
	int DeltaTime = 0;
	int OldTime = 0;
	int firedelay = 0;
	//Variables for the scrolling background
	float bposX = 0;
	float bposX2 = 0;
	float bposY = 0;
	float background_width = 1024;
	//Variables for the Explosion
	int explosionIndex = 10;
	//Text Rendering
	HAPI_TColour textCOL{ HAPI_TColour::GREEN };
	HAPI_TColour outlineCOL{ HAPI_TColour::GREEN };
	//Declaring a Visualisation object and creating a vector of entitys
	Visualisation m_Viz;
	std::vector<Entity*> m_entityVector;

};

