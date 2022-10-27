//Librarys included in the Entity class
#include "Entity.h"
#include "World.h"

//Destructor for the entiy class
Entity::~Entity()
{
}

//The Update loop for the Entity class
void Entity::Update(Visualisation& m_viz, World& world, int deltatime)
{

}

//The function to check the collisions
bool Entity::checkCollision(Visualisation& m_viz, Entity& other)
{
	//Check the A.Right against B.Left or A.Left against B.Right or A.Bottom against B.Top or A.Top against B.bottom
	if (posX + m_viz.getSpriteWidth(this->getSpriteName()) < other.posX || posX > other.posX + m_viz.getSpriteWidth(other.getSpriteName()) || posY + m_viz.getSpriteHeight(this->getSpriteName()) < other.posY || posY > other.posY + m_viz.getSpriteHeight(other.getSpriteName()))
	{
		return false;
	}
	else
	{
		//Check if the thing collided was a bullet
		if (other.getSpriteName() == "Bullet")
		{
			other.score = score + 1;
			other.setBulletActive(false);
			//Setup an explosion if it was a bullet
			setExplosionActive(true, this->posX , this->posY );
		}
		//Remove health from the enemies at collision
		this->health = this->health - 1;
		other.health = other.health - 1;
		return true;
	}
}

//Unused for this class
void Entity::SetPostion(float posX, float posY)
{
}

//Sets the bullet as active
void Entity::setBulletActive(bool active)
{
	bulletIsActive = active;
}

//Unused for this class
std::string Entity::getSpriteName()
{
	return std::string();
}

//Unused for this class
Side Entity::GetSide() const
{
	return Side();
}
