//Included Librarys
#include "Sprite.h"
#include "Rectangle.h"
#include "Visualisation.h"

//Sprite Destructor
Sprite::~Sprite()
{
	delete[]texture;
}

//Function to Load the Textures
bool Sprite::Load(const std::string& filename)
{
	if (!HAPI.LoadTexture(filename, &texture, m_tWidth, m_tHeight))
	{
		HAPI.UserMessage("Missing player texture", "Error");
		return false;
	}
	return true;
}

//Function to render the sprites
void Sprite::Render(BYTE* screen, const Rectangle& screenRect, int posx, int posy)
{
	Rectangle texRect(0, m_tWidth, 0, m_tHeight);

	Rectangle clippedRect(texRect);
	clippedRect.Translate(posx, posy);
	clippedRect.ClipTo(screenRect);
	clippedRect.Translate(-posx, -posy);

	if (posx < 0)
		posx = 0;
	if (posy < 0)
		posy = 0;

	int clipWidth = clippedRect.Width();

	BYTE* tempTexture{ texture + (clippedRect.left + clippedRect.top * texRect.Width()) * 4 };
	BYTE* tempScreen{ screen + (posx + posy * screenRect.Width()) * 4 };
	int increm = (screenRect.Width() - clippedRect.Width()) * 4;
	for (int y = 0; y < clippedRect.Height(); y++)
	{
		for (int x = 0; x < clipWidth; x++)
		{

			if (tempTexture[3] == 255)
			{
				tempScreen[0] = tempTexture[0];
				tempScreen[1] = tempTexture[1];
				tempScreen[2] = tempTexture[2];
			}
			else if (tempTexture[3] > 0)
			{
				float mod = tempTexture[3] / 255.0f;
				tempScreen[0] = tempTexture[0] * mod + tempScreen[0] * (1.0 - mod);
				tempScreen[1] = tempTexture[1] * mod + tempScreen[1] * (1.0 - mod);
				tempScreen[2] = tempTexture[2] * mod + tempScreen[2] * (1.0 - mod);
			}
			tempTexture += 4;
			tempScreen += 4;
		}
		tempScreen += increm;
		tempTexture += (m_tWidth - clippedRect.Width()) * 4;
	}
}

//Function to render the animations using a sprite sheet
void Sprite::RenderAnimation(BYTE* screen, const Rectangle& screenRect, int posx, int posy, int frameX, int frameY, int frameIndexX, int frameIndexY)
{
	Rectangle texRect(0, frameX, 0, frameY);
	Rectangle clippedRect(texRect);
	clippedRect.Translate(posx, posy);
	clippedRect.ClipTo(screenRect);
	clippedRect.Translate(-posx, -posy);
	
	//Apply the offset from the frames within the sprite sheet
	int Xoffset = frameX * frameIndexX;
	int Yoffset = frameY * frameIndexY;
	clippedRect.Translate(Xoffset, Yoffset);

	if (posx < 0)
		posx = 0;
	if (posy < 0)
		posy = 0;

	int clipWidth = clippedRect.Width();

	BYTE* tempTexture{ texture + (clippedRect.left + clippedRect.top * texRect.Width()) * 4 };
	BYTE* tempScreen{ screen + (posx + posy * screenRect.Width()) * 4 };
	int increm = (screenRect.Width() - clippedRect.Width()) * 4;
	for (int y = 0; y < clippedRect.Height(); y++)
	{
		for (int x = 0; x < clipWidth; x++)
		{

			if (tempTexture[3] == 255)
			{
				tempScreen[0] = tempTexture[0];
				tempScreen[1] = tempTexture[1];
				tempScreen[2] = tempTexture[2];
			}
			else if (tempTexture[3] > 0)
			{
				float mod = tempTexture[3] / 255.0f;
				tempScreen[0] = tempTexture[0] * mod + tempScreen[0] * (1.0 - mod);
				tempScreen[1] = tempTexture[1] * mod + tempScreen[1] * (1.0 - mod);
				tempScreen[2] = tempTexture[2] * mod + tempScreen[2] * (1.0 - mod);
			}
			tempTexture += 4;
			tempScreen += 4;
		}
		tempScreen += increm;
		tempTexture += (m_tWidth - clippedRect.Width()) * 4;
	}
}

//Deletes the sprites so there are no memory leaks
void Sprite::Close()
{
	delete[]texture;
}

//Returns the height of each sprite
int Sprite::getHeight()
{
	return m_tHeight;
}

//Returns the width of each sprite
int Sprite::getWidth()
{
	return m_tWidth;
}