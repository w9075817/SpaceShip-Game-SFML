//Librarys included:
#pragma once
#include "Entity.h"
#include <HAPI_lib.h>
using namespace HAPISPACE;
class bulletEntity;
class World;

//Child class of the base class Entity
class playerEntity:
	public Entity
{
public:
	//Destructor and constructor for the player class
	~playerEntity();
	playerEntity(int playerX, int playerY, std::string address);

	//Functions for the player class
	void Update(Visualisation& m_viz, World& m_world, int deltatime) override final;
	void SetPostion(float posX, float posY) override final;
	virtual std::string getSpriteName() override final;
	void setExplosionActive(bool active, int posX, int posY) override final;
	Side GetSide() const override { return Side::ePlayer; };
	
	//Variables used for the player class
	float step = 1;
	std::string spritename;
	float stepDiagonally = 1 / sqrt(2 * step * step);
	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& GetControllerData(unsigned int controller);
	const HAPI_TControllerData& data = HAPI.GetControllerData(0);
	std::string str;
	bool keithMode = false;
};

