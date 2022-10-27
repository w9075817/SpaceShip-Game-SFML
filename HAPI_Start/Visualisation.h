//Included Librarys
#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include <unordered_map>
#include "Sprite.h"
using namespace HAPISPACE;
class Sprite;

class Visualisation
{
public:
	//Constructor and Destructor for Visualisation
	Visualisation() = default;
	~Visualisation();
	
	//Functions for Visualisation
	bool CreateSprite(const std::string& spriteName, const std::string& filename);
	void RenderSprite(const std::string& spriteName, int posX, int posY);
	void RenderAnimation(const std::string& spriteName, int posX, int posY, int frameX, int frameY, int frameIndexX, int frameIndexY);
	bool Initialise();
	int Visualisation::getSpriteWidth(const std::string& spriteName);
	int Visualisation::getSpriteHeight(const std::string& spriteName);

private:
	//Variables for Visualisation
	BYTE* m_screen{nullptr};
	int width{ 1024 };
	int height{ 768 };
	//Map containing the Spritenames and Sprite entitys
	std::unordered_map<std::string, Sprite*> m_spriteMap;
};

