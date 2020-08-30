#include <DxLib.h>
#include "DxLib_Draw.h"

void DxLib_Draw::DrawBoxEOff(int x, int y, int offset_x, int offset_y,int color, bool FillFlag)
{
	DrawBox(x, y, x + offset_x, y + offset_y,color, FillFlag);
}

void DxLib_Draw::DrawBoxLineEOff(int x, int y, int offset_x, int offset_y, int color)
{
	DrawLineBox(x, y, x + offset_x, y + offset_y, color);
}

void DxLib_Draw::DrawExGraphEOff(int x, int y, int offset_x, int offset_y, int GrHdl)
{
	DrawExtendGraph(x, y, x + offset_x, y + offset_y, GrHdl,true);
}

