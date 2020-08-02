#pragma once
#include <type_traits>
enum class MouseID
{
	Left,
	Right,
	MIDDLE,
	Max
};

static MouseID begin(MouseID) { return MouseID::Left; };
static MouseID end(MouseID) { return MouseID::Max; };
static MouseID operator++(MouseID& state) { return (state = MouseID(std::underlying_type<MouseID>::type(state) + 1)); };
static MouseID operator*(MouseID state) { return state; }