#include <math.h>
#include "../Geometry/Geometry.h"
#include "collision2D.h"

bool IsHitAABB(const Rect A, const Rect B)
{
	if (A.Left() < B.Right()
		&& B.Left() < A.Right()
		&& A.Top() < B.Buttom()
		&& B.Top() < A.Buttom())
	{
		return true;
	}
	return false;
}

bool IsHitCircle(const Circle A, const Circle B)
{
	int diff_x = abs(A.x - B.x);
	int diff_y = abs(A.y - B.y);
	int radious = A.radious + B.radious;
	if (radious * radious > diff_x * diff_x + diff_y * diff_y)
	{
		return true;
	}
	return false;
}
