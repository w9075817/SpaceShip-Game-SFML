//The Librarys included in the sprite header
#pragma once
#include <HAPI_lib.h>
using namespace HAPISPACE;
#include "Rectangle.h"

class Sprite
{
public:
	//Destructor for the sprite class
	~Sprite();

	//Functions for the sprite class
	bool Load(const std::string& filename);
	void Render(BYTE* screen, const Rectangle & screenRect, int posx, int posy);
	void RenderAnimation(BYTE* screen, const Rectangle& screenRect, int posx, int posy, int frameX, int frameY, int frameIndexX, int frameIndexY);
	void Close();
	int getHeight();
	int getWidth();

private:
	//Declaring the variables for the Sprite class
	BYTE* texture{ nullptr };
	int m_tWidth = 10;
	int m_tHeight = 10;
	int screenwidth{ 1024 };
	int screenheight{ 768 };
};

