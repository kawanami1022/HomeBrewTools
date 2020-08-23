#include "collision2D.h"
//-------------------------------------------------
//--------------Project by ------------------------
//----------------------koshiro kawanami-----------
//-------------------------------------------------

bool Collision2D::IsHitAABB(Rect A, Rect B)
{
	return(A.Left() < B.Right() && A.Right() < B.Left()
		&& A.Top() < B.Buttom() && A.Buttom() < B.Top());
}

bool Collision2D::IsHitABB(Position2 A, Rect B)
{
	return (B.Left() < A.x && A.x < B.Right()
		&& B.Top() < A.y&& A.y < B.Buttom());
}
