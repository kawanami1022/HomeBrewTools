#pragma once

template <class T >
struct RectTmp
{
	T left;
	T top;
	T hight;
	T width;
	T Left()const
	{
		return left;
	}
	T Top()const
	{
		return top;
	}
	T Right()const
	{
		return left + width;
	}
	T Buttom()const
	{
		return top + hight;
	}
};

using Rect = RectTmp<int>;
using RectS = RectTmp<short>;
using RectL = RectTmp<long>;
using RectF = RectTmp<float>;
using RectD = RectTmp<double>;

template <class T >
struct Circle
{
	T x, y;
	T radious;
};

