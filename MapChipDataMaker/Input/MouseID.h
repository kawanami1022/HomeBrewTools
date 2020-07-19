#pragma once
enum class MOUSE_ID
{
	LEFT,
	RIGHT,
	MIDDLE,
	MAX
};

MOUSE_ID begin(MOUSE_ID) { return MOUSE_ID::LEFT; }
MOUSE_ID end(MOUSE_ID) { return MOUSE_ID::MAX; }
MOUSE_ID operator*(MOUSE_ID mouseID) { return mouseID; }
MOUSE_ID operator++(MOUSE_ID& mouseID) { return mouseID = MOUSE_ID(std::underlying_type<MOUSE_ID>::type(mouseID) + 1); }
