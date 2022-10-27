//Librarys included:
#include "enemyEntity.h"
#include "bulletEntity.h"

//Destructor for my Enemy Entity Class
enemyEntity::~enemyEntity()
{
}

//Constructor for my Enemy Entity Class
enemyEntity::enemyEntity(int enemyX, int enemyY, std::string address, bool intelligent)
{
	posX = enemyX;
	posY = enemyY;
	spritename = address;
	AI = intelligent;

	//Decides Based on the Spritename the amount of health
	if (spritename == "Asteroid")
	{
		health = 100;
	}
	else if (spritename == "Alien")
	{
		health = 2000;
	}
}

void enemyEntity::Update(Visualisation& m_viz, World& m_world, int deltatime)
{
	//If the enemy has 'Intelligence' It has a different set of characteristics to if it doesnt
	if (AI == true)
	{
		//If the Enemys alive:
		if (health > 0)
		{
			m_viz.RenderSprite(spritename, posX, posY);
			int randomY = rand() % 10;
			int randomX = rand() % 10;
			if (randomY > 5 && posY < 500)
			{
				posY += (0.2 * deltatime);
			}
			else if (randomY < 5 && posY > 200)
			{
				posY -= (0.2 * deltatime);
			}
			if (randomX > 5 && posX < 800)
			{
				posX += (0.2 * deltatime);
			}
			else if (randomX < 5 && posX > 600)
			{
				posX -= (0.2 * deltatime);
			}
		}

		str2 = std::to_string(score);
		HAPI.RenderText(935, 55, textCOL, outlineCOL, 1, str2, 50);

		//If the Enemys dies:
		if (health < 1)
		{
			posX = (rand() % 500) + 1000;
			posY = (rand() % 2000);
			health = 2000;
			score = score + 1;
		}
	}

	//If the enemy doesnt have 'Intelligence' It has a different set of characteristics to if it doesnt
	else if (AI == false)
	{
		//If the Enemys alive:
		posX -= (1 * deltatime);
		m_viz.RenderSprite(spritename, posX, posY);

		//If the Enemys is out of bounds or dies:
		if (posX <= -10)
		{
			posX = 1024;
			posY = (rand() % 700);
		}
		if (health < 1)
		{
			posX = 1024;
			posY = (rand() % 700);
			health = 100;
			score = score + 10;
		}
	}

}

//Unused Function for this class
void enemyEntity::setExplosionActive(bool active, int posX, int posY)
{
}

// Returns the Spritename
std::string enemyEntity::getSpriteName()
{
	return spritename;
}

//Unused Function for this class
void enemyEntity::SetPostion(float posX, float posY)
{
}