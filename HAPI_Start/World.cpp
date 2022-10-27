//Librarys included:
#include "World.h"
#include "bulletEntity.h"
#include <time.h>
#include "explosionEntity.h"
using namespace HAPISPACE;

//World Destructor
World::~World()
{
	//Deleting memory after usage
	for (auto& p : m_entityVector)
		delete p;
}

//Main loop for the World
void World::Run()
{
	//Initialising the window
	m_Viz.Initialise();

	//Loading and playing the background track
	HAPI.PlaySound("Data\\background.wav", 0.1);

	while (HAPI.Update())
	{
		//Setting the clock so that the play is consistent no matter
		//the fps or the system being used to play it on
		float time = clock();
		DeltaTime = time - OldTime;
		OldTime = time;
		firedelay += (0.5 * DeltaTime);

		//The code for the scrolling backgrounds
		m_Viz.RenderSprite("Background", bposX, bposY);
		m_Viz.RenderSprite("Background", bposX2, bposY);
		if (bposX2 <= 0)
		{
			bposX = 0;
			bposX2 = background_width;
		}
		bposX -= (0.5 * DeltaTime);
		bposX2 -= (0.5 * DeltaTime);

		//Rendering Text
		HAPI.RenderText(10, 10, textCOL, outlineCOL, 1, "Health:", 50);
		HAPI.RenderText(600, 10, textCOL, outlineCOL, 1, "Enemy's Defeated:", 50);

		//Loop throught the entity vector and update all the entitys
		for (int index = 0; index < m_entityVector.size(); index++)
		{
			m_entityVector[index]->Update(m_Viz, *this, DeltaTime);
		}

		//Loop throught the entity vectors and check collisions between them both
		for (size_t i = 0; i < m_entityVector.size(); i++)
		{
			if (m_entityVector[i]->GetSide() != Side::eNeutral)
			{
				for (size_t j = i + 1; j < m_entityVector.size(); j++)
				{	 
					if ((m_entityVector[i]->GetSide() == Side::ePlayer && m_entityVector[j]->GetSide() == Side::ePlayer) || (m_entityVector[i]->GetSide() == Side::eEnemy && m_entityVector[j]->GetSide() == Side::eEnemy))
					{
					}
					else
					{
						if (m_entityVector[i]->checkCollision(m_Viz, *m_entityVector[j]))
						{
							//If collided set an explosion at the same position
							m_entityVector[explosionIndex]->setExplosionActive(true, (m_entityVector[i]->posX) + (m_Viz.getSpriteWidth(m_entityVector[i]->getSpriteName()) / 2) - 16, (m_entityVector[i]->posY) + (m_Viz.getSpriteHeight(m_entityVector[i]->getSpriteName()) / 2) - 16);
							explosionIndex++;
							if (explosionIndex == m_entityVector.size())
							{
								explosionIndex = 10;
							}
						}
					}
				}
			}
		}
	}
}

void World::LoadLevel()
{
	//Loading in all the sprites that are used and labeling
	if (!m_Viz.CreateSprite("Player", "Data\\Player_Sprite.png"))
		return;
	if (!m_Viz.CreateSprite("Bullet", "Data\\Bullet_Sprite.png"))
		return;
	if (!m_Viz.CreateSprite("Background", "Data\\BackgroundTexture.jpg"))
		return;
	if (!m_Viz.CreateSprite("Asteroid", "Data\\Asteroid_sprite.png"))
		return;
	if (!m_Viz.CreateSprite("Alien", "Data\\Alien_Sprite.png"))
		return;
	if (!m_Viz.CreateSprite("Explosion", "Data\\Explosion_Sprite.png"))
		return;

	//Creating all my entitys
	playerEntity* newPlayer = new playerEntity(100, 100, "Player");
	m_entityVector.push_back(newPlayer);
	enemyEntity* newEnemy = new enemyEntity(1024, 700, "Asteroid", false);
	m_entityVector.push_back(newEnemy);
	enemyEntity* newEnemy3 = new enemyEntity(1024, 600, "Asteroid", false);
	m_entityVector.push_back(newEnemy3);
	enemyEntity* newEnemy2 = new enemyEntity(1024, 500, "Alien", true);
	m_entityVector.push_back(newEnemy2);
	//Loops to create Bullets
	for (int i = 0; i < 7; i++)
	{
		bulletEntity* newBullet = new bulletEntity();
		m_entityVector.push_back(newBullet);
	}
	//Loops to create Explosions
	for (int i = 0; i < 7; i++)
	{
		explosionEntity* newExplosion = new explosionEntity();
		m_entityVector.push_back(newExplosion);
	}
}

void World::createPlayerbullet(float posx, float posy)
{
	//This is a function that spawns the bullets
	for (Entity* p : m_entityVector)
	{
		if (!p->bulletIsActive && firedelay > 50 && p->getSpriteName() == "Bullet")
		{
			p->SetPostion(posx, posy);
			p->setBulletActive(true);
			HAPI.PlaySound("Data\\laser.wav", 0.2f);
			firedelay = 0;
			break;
		}
	}
}
