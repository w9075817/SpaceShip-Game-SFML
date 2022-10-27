#pragma once

//Class to create a rectangle
class Rectangle
{
public:
	//Decalare values for the rectangle
	int left{ 0 }, right, top, bottom;

	//constructor
	Rectangle() = default;

	//assign values to the constructor
	Rectangle(int l, int r, int t, int b) :
		left(l), right(r), top(t), bottom(b){}
	
	//create width and height for rectangle
	int Width() const { return right - left; }
	int Height() const { return bottom - top; }

	//create a function to translate the rectangle
	void Translate(int dx, int dy)
	{
		left += dx;
		right += dx;
		top += dy;
		bottom += dy;
	}

	//function to clip the rectangle to the screen/other rectangle
	void Rectangle::ClipTo(const Rectangle& other)
	{
		if (left < other.left)
			left = other.left;
		if (right > other.right)
			right = other.right;
		if (top < other.top)
			top = other.top;
		if (bottom > other.bottom)
			bottom = other.bottom;
	}

};
