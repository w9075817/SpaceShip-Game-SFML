//Librarys Included:
#include "playerEntity.h"
#include <HAPI_lib.h>
#include "World.h"
#include "bulletEntity.h"

//Destructor for the player entity
playerEntity::~playerEntity()
{
}

//Constructor for the player entity
playerEntity::playerEntity(int playerX, int playerY, std::string address)
{
	posX = playerX;
	posY = playerY;
	spritename = address;
	health = 5000;
}

//Main loop for the Player Entity
void playerEntity::Update(Visualisation& m_viz, World& m_world, int deltatime)
{
	//If player is alive:
	if (health > 0)
	{
		//Render text showing the health
		str = std::to_string(health);
		HAPI.RenderText(55, 55, textCOL, outlineCOL, 1, str, 50);

		//Checking for inputs
		if (KeyData.scanCode['W'] && posY - 1 > 0)
		{
			posY = posY - (0.5 * deltatime);
		}
		else if (KeyData.scanCode['S'] && posY + 1 < 768 - 76)
		{
			posY = posY + (0.5 * deltatime);
		}
		//else if (KeyData.scanCode['A'] && posX - 1 > 0)
		//{
		//	posX = posX - (0.3 * deltatime);
		//}
		//else if (KeyData.scanCode['D'] && posX + 1 < 1024 - 107)
		//{
		//	posX = posX + (0.3 * deltatime);
		//}
		if (KeyData.scanCode[HK_SPACE])
		{
			m_world.createPlayerbullet(posX, posY);
		}
		if (KeyData.scanCode['K'])
		{
			if (!keithMode)
			{
				keithMode = true;
			}
			else if (keithMode)
			{
				keithMode = false;
			}

		}
		
		//Function to render the sprite
		m_viz.RenderSprite(spritename, posX, posY);

		//Controller support
		posX += data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] / 10000;
		posY -= data.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] / 10000;
	}

	if (keithMode)
	{
		HAPI.RenderText(220, 10, textCOL, outlineCOL, 1, "Keith mode", 50);
	}

	//If the player is dead:
	if (health < 1)
	{
		if (!keithMode)
		{
			HAPI.RenderText(55, 55, textCOL, outlineCOL, 1, "0", 50);
			HAPI.RenderText(320, 200, textCOL, outlineCOL, 1, "You have died!", 50);
			HAPI.RenderText(280, 250, textCOL, outlineCOL, 1, "Press 'R' to restart", 50);
			//Check for the restart button to be pressed
			if (KeyData.scanCode['R'])
			{
				posX = 200;
				posY = 350;
				health = 5000;
			}
		}
		if (keithMode)
		{
			health = 100000;
		}

	}
}

//Returns the spritename
std::string playerEntity::getSpriteName()
{
	return spritename;
}

//Unused function for this class
void playerEntity::setExplosionActive(bool active, int posX, int posY)
{
}

//Unused function for this class
void playerEntity::SetPostion(float posX, float posY)
{
}