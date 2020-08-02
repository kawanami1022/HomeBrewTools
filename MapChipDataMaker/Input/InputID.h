#pragma once


// ƒ{ƒ^ƒ“‚ÌŽí—Þ
enum class InputID
{
	Left,
	Right,
	MIDDLE,
	Max
};

static InputID begin(InputID) { return InputID::Left; };
static InputID end(InputID) { return InputID::Max; };
static InputID operator++(InputID& state) { return (state = InputID(std::underlying_type<InputID>::type(state) + 1)); };
static InputID operator*(InputID state) { return state; }