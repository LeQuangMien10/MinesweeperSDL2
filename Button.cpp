#include "Button.h"

Button::Button()
{
	is_pressed = false;
}

Button::~Button()
{

}

void Button::Press(const int& x, const int& y)
{
	if ((x >= rect_.x and x <= rect_.x + rect_.w) and (y >= rect_.y and y <= rect_.y + rect_.h))
	{
		is_pressed = true;
	}
}

void Button::Unpress()
{
	is_pressed = false;
}