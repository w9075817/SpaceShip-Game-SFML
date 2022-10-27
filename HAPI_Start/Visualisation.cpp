//Included the Visualisation Header
#include "Visualisation.h"

//The destructor for the visualisation class
Visualisation::~Visualisation()
{
	for (auto& p : m_spriteMap)
		delete p.second;
}

//The function to createSprites
bool Visualisation::CreateSprite(const std::string& spriteName, const std::string& filename)
{
	//Creates a new instance of a sprite and then calls the load function
	Sprite* newSprite = new Sprite;
	if (!newSprite->Load(filename))
	{
		delete newSprite;
		return false;
	}

	//Adds the newSprite to the spritemap and labels it with the name of the sprite
	m_spriteMap[spriteName] = newSprite;

	return true;
}

// This is the renderSprite function
void Visualisation::RenderSprite(const std::string& spriteName, int posX, int posY)
{
	//checks that its a valid sprite
	if (m_spriteMap.find(spriteName) == m_spriteMap.end())
		return;
	
	//Creates a rectangle of the screen and passess it through into the sprite's render function
	Rectangle screenRect(0, width, 0, height);
	m_spriteMap[spriteName]->Render(m_screen, screenRect, posX, posY);
}

//This is the functiion to render animated sprites 
void Visualisation::RenderAnimation(const std::string& spriteName, int posX, int posY, int frameX, int frameY, int frameIndexX, int frameIndexY)
{
	//checks that its a valid sprite
	if (m_spriteMap.find(spriteName) == m_spriteMap.end())
		return;

	//Creates a rectangle of the screen and passess it through into the sprite's render function
	Rectangle screenRect(0, width, 0, height);
	m_spriteMap[spriteName]->RenderAnimation(m_screen, screenRect, posX, posY, frameX, frameY, frameIndexX, frameIndexY);
}

//Initialises HAPI
bool Visualisation::Initialise()
{
	if (!HAPI.Initialise(width, height))
	{
		return false;
	}

	//Returns a screen pointer and set the FPS show to be true
	m_screen = { HAPI.GetScreenPointer() };
	HAPI.SetShowFPS(true);
	return true;
}

//Function to return the Sprite Width
int Visualisation::getSpriteWidth(const std::string& spriteName)
{
	return m_spriteMap[spriteName]->getWidth();
}

//Function to return the Sprite Height
int Visualisation::getSpriteHeight(const std::string& spriteName)
{
	return m_spriteMap[spriteName]->getHeight();
}
