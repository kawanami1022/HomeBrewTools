#pragma once


struct Rect
{
	int left;
	int top;
	int hight;
	int width;
	int Left()const
	{
		return left;
	}
	int Top()const
	{
		return top;
	}
	int Right()const
	{
		return left + width;
	}
	int Buttom()const
	{
		return top + hight;
	}
};

struct Circle
{
	int x, y;
	int radious;
};