//Librarys inclded in the bullet entity header file
#pragma once
#include "Entity.h"
#include "World.h"

class bulletEntity :
    public Entity
{
public:
	//Destructor and constructor for bullet entity
	~bulletEntity();
	bulletEntity();
	
	//Functions for the bullet entity class
	void Update(Visualisation& m_viz, World& m_world, int deltatime) override final;
	void SetPostion(float posX, float posY) override final;
	void setBulletActive(bool active);
	virtual std::string getSpriteName() override final;
	Side GetSide() const override { return Side::ePlayer; };
	void setExplosionActive(bool active, int posX, int posY) override final;

	//Variable to hold the spritename
	std::string spritename;
};

