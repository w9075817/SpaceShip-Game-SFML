//Including the header in the bullet class
#include "bulletEntity.h"

//Destructor for the bulletEntity
bulletEntity::~bulletEntity()
{
}

//Constructor for the bulletEntity
bulletEntity::bulletEntity()
{
	spritename = "Bullet";
	health = 1;
}

//Main loop for the bullet entity class
void bulletEntity::Update(Visualisation& m_viz, World& m_world, int deltatime)
{
	//Move the bullet across the screen
	posX += (1 * deltatime);
	
	//If the bullet goes of the screen 
	if (posX > 1000)
	{
		//set the bullet active to false
		bulletIsActive = false;
	}
	
	//If the bullet is actibe
	if (bulletIsActive == true)
	{
		//render the sprite for the bullet
		m_viz.RenderSprite(spritename, posX, posY);
	}
}

//Set the position of the bullet relative to the player position
void bulletEntity::SetPostion(float PlayerposX, float PlayerposY)
{
	posX = PlayerposX + 100;
	posY = PlayerposY + 30;
}

//Funtion to set the bullet to be active
void bulletEntity::setBulletActive(bool active)
{
	bulletIsActive = active;
	score = 0;
}

//Returns Spritename
std::string bulletEntity::getSpriteName()
{
	return spritename;
}

//Not used for this class
void bulletEntity::setExplosionActive(bool active, int posX, int posY)
{
}
