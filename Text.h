#pragma once
#ifndef TEXT_H_
#define TEXT_H_

#include "CommonFunction.h"

class Text
{
public:
	Text();
	~Text();

	enum TextColor
	{
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		BLACK_TEXT = 2,
	};

	bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	void SetColor(int type);

	void RenderText(SDL_Renderer* screen, int xp, int yp,
		SDL_Rect* clip = NULL, double angle = 0.0,
		SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void SetRect(const int& x, const int& y) { rect_.x = x; rect_.y = y; }
	SDL_Rect GetRect() const { return rect_; }
	int GetWidth() const { return width_; }
	int GetHeight() const { return height_; }

	void SetText(const std::string& text) { str_val_ = text; }
	std::string GetText() const { return str_val_; }

private:
	std::string str_val_;
	SDL_Color text_color_;
	SDL_Texture* texture_;
	SDL_Rect rect_;
	int width_;
	int height_;

};


#endif // !TEXT_H_
