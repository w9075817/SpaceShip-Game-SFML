//Librarys included:
#pragma once
#include "Entity.h"

class World;

//Child Class of the Entity Class
class enemyEntity :
    public Entity
{
public:
	//Constructor and Destructor for Enemy Entity Class
	~enemyEntity();
	enemyEntity(int enemyX, int enemyY, std::string filename, bool intelligent);

	//Class Functions for Enemy Entitys
	void Update(Visualisation& m_viz, World& m_world, int deltatime) override final;
	void setExplosionActive(bool active, int posX, int posY) override final;
	virtual std::string getSpriteName() override final;
	Side GetSide() const override { return Side::eEnemy; };
	void SetPostion(float posX, float posY) override final;

	//Declared Variables for Enemy Entitys
	bool AI;
	std::string spritename;
	std::string str2;
};

