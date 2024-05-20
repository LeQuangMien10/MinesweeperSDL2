#pragma once
#ifndef FIELD_H_
#define FIELD_H_


#include "CommonFunction.h"
#include "BaseObject.h"
#include "Cell.h"
#include "Text.h"
#include "Button.h"


class Field :public BaseObject
{
public:
	Field();
	~Field();

	void draw_easy_grid(SDL_Renderer* screen, TTF_Font* font);
	void draw_medium_grid(SDL_Renderer* screen, TTF_Font* font);
	void draw_hard_grid(SDL_Renderer* screen, TTF_Font* font);

	void generate_mines_easy();
	void generate_mines_medium();
	void generate_mines_hard();

	void check_for_game_over_easy();
	void check_for_game_over_medium();
	void check_for_game_over_hard();

	void open_cell_easy(const int& x, const int& y);
	void open_cell_medium(const int& x, const int& y);
	void open_cell_hard(const int& x, const int& y);

	void flag_cell_easy(const int& x, const int& y);
	void flag_cell_medium(const int& x, const int& y);
	void flag_cell_hard(const int& x, const int& y);

	void display_flag_easy(TTF_Font* font, SDL_Renderer* screen);
	void display_flag_medium(TTF_Font* font, SDL_Renderer* screen);
	void display_flag_hard(TTF_Font* font, SDL_Renderer* screen);

	bool get_game_over() const { return game_over; }
	bool get_is_win() const { return is_win; }
	int get_count_flag() const { return count_flag; }

	int draw_button(SDL_Renderer* screen);
	void press_button(const int& x, const int& y);
	void unpress_button();

	int display_end_easy(SDL_Renderer* screen, TTF_Font* font);
	int display_end_medium(SDL_Renderer* screen, TTF_Font* font);
	int display_end_hard(SDL_Renderer* screen, TTF_Font* font);

	void game_reset_easy();
	void game_reset_medium();
	void game_reset_hard();

	void clear_easy();
	void clear_medium();
	void clear_hard();

	bool CheckMouseFocus(const int& x, const int& y, const int& text_x, const int& text_y, const int& text_w, const int& text_h);
private:
	bool is_win;
	bool first_click;
	bool game_over;
	Cell EasyPlayGrid[EASY_NUM_ROW][EASY_NUM_COL];
	Cell MediumPlayGrid[MEDIUM_NUM_ROW][MEDIUM_NUM_COL];
	Cell HardPlayGrid[HARD_NUM_ROW][HARD_NUM_COL];
	Button button[NUMBER_OF_FIELD_BUTTON];
	int count_flag;


};

#endif // !FIELD_H_
