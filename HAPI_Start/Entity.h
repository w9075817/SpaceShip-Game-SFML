//Librarys Included int the Entity Class header
#pragma once
#include "Rectangle.h"
#include "Visualisation.h"
#include <HAPI_lib.h>
#include <unordered_map>
#include "Sprite.h"
using namespace HAPISPACE;
class Sprite;
class World;

//Declaring the Enum class Sides for the Entitys
enum class Side
{
	eNeutral,
	ePlayer,
	eEnemy
};

class Entity
{
public:
	//Constructor and Destructor for the Entity class
	Entity() = default;
	virtual ~Entity();

	//Functions for the Entity class
	virtual void Update(Visualisation& m_viz, World& m_world, int deltatime) = 0;
	bool checkCollision(Visualisation& m_viz, Entity& other);
	virtual void SetPostion(float posX, float posY) = 0;
	virtual void setExplosionActive(bool active, int posX, int posY) = 0;
	virtual std::string getSpriteName();
	virtual Side GetSide() const = 0;
	void setBulletActive(bool active);

	//Variables for the Entity class
	HAPI_TColour textCOL{ HAPI_TColour::GREEN };
	HAPI_TColour outlineCOL{ HAPI_TColour::GREEN };
	int score = 0;
	float volume = 0.2f;
	float posX = 0;
	float posY = 0;
	float ExplosionposX = 0;
	float ExplosionposY = 0;
	int health = 1;
	bool bulletIsActive = false;
	bool explosionIsActive = false;
	bool enemyDead = false;
};

