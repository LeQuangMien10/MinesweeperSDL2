#pragma once
#ifndef BUTTON_H_
#define BUTTON_H_

#include "BaseObject.h"
#include "CommonFunction.h"

class Button :public BaseObject
{
public:
	Button();
	~Button();

	void Press(const int& x, const int& y);
	void Unpress();

	void set_is_pressed(bool is_pressed_) { is_pressed = is_pressed_; }
	bool get_is_pressed() const { return is_pressed; }

private:
	bool is_pressed;
};


#endif // !BUTTON_H_
