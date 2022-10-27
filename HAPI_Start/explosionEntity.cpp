//Headeer included for the explosion class
#include "explosionEntity.h"

//Constructor for the explosion entity
explosionEntity::explosionEntity()
{
	spritename = "Explosion";
}

//Destructor for the explosion entity
explosionEntity::~explosionEntity()
{
}

//Main loop for the Explosions
void explosionEntity::Update(Visualisation& m_viz, World& m_world, int deltatime)
{
	//If the Explosion is active
	if (explosionIsActive == true)
	{
		//Setting the end counter
		end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;

		//If enough time has elpsed
		if (duration.count() > frametime)
		{
			start = std::chrono::high_resolution_clock::now();
			//Increment to the next frame
			frameIndexX++;
		}

		//If at the end of the row of the spritesheet start a new row
		if (frameIndexX > 3)
		{
			frameIndexX = 0;
			frameIndexY++;
		}
		//If at the end of the spritesheet start from the beggining
		if (frameIndexY > 3)
		{
			frameIndexX = 0;
			frameIndexY = 0;
			HAPI.PlaySound("Data\\explosion_x.wav", 0.01);
		}
		//Render animation then set the explosion acitve to false
		m_viz.RenderAnimation("Explosion", PosX, PosY, 64, 64, frameIndexX, frameIndexY);
		explosionIsActive = false;
	}
}

//Function to return spritename
std::string explosionEntity::getSpriteName()
{
	return spritename;
}

//Function to set the explosion as active
void explosionEntity::setExplosionActive(bool active, int posX, int posY)
{
	explosionIsActive = active;
	PosX = posX;
	PosY = posY;
}

//Unused by this class
void explosionEntity::SetPostion(float posX, float posY)
{
}