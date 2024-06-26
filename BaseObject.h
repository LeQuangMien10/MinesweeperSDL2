#pragma once
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunction.h"

class BaseObject
{

public:
	BaseObject();
	~BaseObject();

	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetObject() const { return p_texture_; }

	bool LoadImg(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des);
	void Free();
protected:
	SDL_Texture* p_texture_;
	SDL_Rect rect_;
};


#endif // !BASE_OBJECT_H_
