#include "Field.h"

Field::Field()
{
	is_win = false;
	first_click = true;
	game_over = false;
	count_flag = 0;
}

Field::~Field()
{

}

void Field::draw_easy_grid(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == false)
	{
		SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
		SDL_RenderClear(screen);

		for (int i = 0; i < EASY_NUM_ROW; i++)
		{
			for (int j = 0; j < EASY_NUM_COL; j++)
			{
				EasyPlayGrid[i][j].SetRect(EASY_CELL_SIZE * (i + 1), EASY_CELL_SIZE * (j + 1));

				if (EasyPlayGrid[i][j].get_is_open() == true)
				{
					if (EasyPlayGrid[i][j].get_is_mine() == false)
					{
						EasyPlayGrid[i][j].count_mine_around_easy(EasyPlayGrid, i, j);
						if (EasyPlayGrid[i][j].get_count_mine_around() == 0)
							EasyPlayGrid[i][j].LoadImg("tile_empty_64.jpg", screen);
						if (EasyPlayGrid[i][j].get_count_mine_around() > 0)
						{
							switch (EasyPlayGrid[i][j].get_count_mine_around())
							{
							case 1:
								EasyPlayGrid[i][j].LoadImg("tile_1_64.jpg", screen);
								break;
							case 2:
								EasyPlayGrid[i][j].LoadImg("tile_2_64.jpg", screen);
								break;
							case 3:
								EasyPlayGrid[i][j].LoadImg("tile_3_64.jpg", screen);
								break;
							case 4:
								EasyPlayGrid[i][j].LoadImg("tile_4_64.jpg", screen);
								break;
							case 5:
								EasyPlayGrid[i][j].LoadImg("tile_5_64.jpg", screen);
								break;
							case 6:
								EasyPlayGrid[i][j].LoadImg("tile_6_64.jpg", screen);
								break;
							case 7:
								EasyPlayGrid[i][j].LoadImg("tile_7_64.jpg", screen);
								break;
							case 8:
								EasyPlayGrid[i][j].LoadImg("tile_8_64.jpg", screen);
								break;
							default:
								break;
							}
						}
					}
					else
					{
						EasyPlayGrid[i][j].LoadImg("tile_red_bomb_64.jpg", screen);
						game_over = true;
						is_win = false;
					}
				}
				else
				{
					if (EasyPlayGrid[i][j].get_is_flag() == false)
					{
						EasyPlayGrid[i][j].LoadImg("tile_64.jpg", screen);
					}
					else
					{
						EasyPlayGrid[i][j].LoadImg("tile_flag_64.jpg", screen);
					}
				}
				EasyPlayGrid[i][j].Render(screen);
			}
		}
		display_flag_easy(font, screen);
		check_for_game_over_easy();
	}
}

void Field::draw_medium_grid(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == false)
	{
		SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
		SDL_RenderClear(screen);

		for (int i = 0; i < MEDIUM_NUM_ROW; i++)
		{
			for (int j = 0; j < MEDIUM_NUM_COL; j++)
			{
				MediumPlayGrid[i][j].SetRect(MEDIUM_CELL_SIZE * (i + 1), MEDIUM_CELL_SIZE * (j + 1));

				if (MediumPlayGrid[i][j].get_is_open() == true)
				{
					if (MediumPlayGrid[i][j].get_is_mine() == false)
					{
						MediumPlayGrid[i][j].count_mine_around_medium(MediumPlayGrid, i, j);
						if (MediumPlayGrid[i][j].get_count_mine_around() == 0)
							MediumPlayGrid[i][j].LoadImg("tile_empty_48.jpg", screen);
						if (MediumPlayGrid[i][j].get_count_mine_around() > 0)
						{
							switch (MediumPlayGrid[i][j].get_count_mine_around())
							{
							case 1:
								MediumPlayGrid[i][j].LoadImg("tile_1_48.jpg", screen);
								break;
							case 2:
								MediumPlayGrid[i][j].LoadImg("tile_2_48.jpg", screen);
								break;
							case 3:
								MediumPlayGrid[i][j].LoadImg("tile_3_48.jpg", screen);
								break;
							case 4:
								MediumPlayGrid[i][j].LoadImg("tile_4_48.jpg", screen);
								break;
							case 5:
								MediumPlayGrid[i][j].LoadImg("tile_5_48.jpg", screen);
								break;
							case 6:
								MediumPlayGrid[i][j].LoadImg("tile_6_48.jpg", screen);
								break;
							case 7:
								MediumPlayGrid[i][j].LoadImg("tile_7_48.jpg", screen);
								break;
							case 8:
								MediumPlayGrid[i][j].LoadImg("tile_8_48.jpg", screen);
								break;
							default:
								break;
							}
						}
					}
					else
					{
						MediumPlayGrid[i][j].LoadImg("tile_red_bomb_48.jpg", screen);
						game_over = true;
						is_win = false;
					}
				}
				else
				{
					if (MediumPlayGrid[i][j].get_is_flag() == false)
					{
						MediumPlayGrid[i][j].LoadImg("tile_48.jpg", screen);
					}
					else
					{
						MediumPlayGrid[i][j].LoadImg("tile_flag_48.jpg", screen);
					}
				}
				MediumPlayGrid[i][j].Render(screen);
			}
		}
		display_flag_medium(font, screen);
		check_for_game_over_medium();
	}
}

void Field::draw_hard_grid(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == false)
	{
		SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
		SDL_RenderClear(screen);

		for (int i = 0; i < HARD_NUM_ROW; i++)
		{
			for (int j = 0; j < HARD_NUM_COL; j++)
			{
				HardPlayGrid[i][j].SetRect(HARD_CELL_SIZE * (i + 1), HARD_CELL_SIZE * (j + 1));

				if (HardPlayGrid[i][j].get_is_open() == true)
				{
					if (HardPlayGrid[i][j].get_is_mine() == false)
					{
						HardPlayGrid[i][j].count_mine_around_hard(HardPlayGrid, i, j);
						if (HardPlayGrid[i][j].get_count_mine_around() == 0)
							HardPlayGrid[i][j].LoadImg("tile_empty_32.jpg", screen);
						if (HardPlayGrid[i][j].get_count_mine_around() > 0)
						{
							switch (HardPlayGrid[i][j].get_count_mine_around())
							{
							case 1:
								HardPlayGrid[i][j].LoadImg("tile_1_32.jpg", screen);
								break;
							case 2:
								HardPlayGrid[i][j].LoadImg("tile_2_32.jpg", screen);
								break;
							case 3:
								HardPlayGrid[i][j].LoadImg("tile_3_32.jpg", screen);
								break;
							case 4:
								HardPlayGrid[i][j].LoadImg("tile_4_32.jpg", screen);
								break;
							case 5:
								HardPlayGrid[i][j].LoadImg("tile_5_32.jpg", screen);
								break;
							case 6:
								HardPlayGrid[i][j].LoadImg("tile_6_32.jpg", screen);
								break;
							case 7:
								HardPlayGrid[i][j].LoadImg("tile_7_32.jpg", screen);
								break;
							case 8:
								HardPlayGrid[i][j].LoadImg("tile_8_32.jpg", screen);
								break;
							default:
								break;
							}
						}
					}
					else
					{
						HardPlayGrid[i][j].LoadImg("tile_red_bomb_32.jpg", screen);
						game_over = true;
						is_win = false;
					}
				}
				else
				{
					if (HardPlayGrid[i][j].get_is_flag() == false)
					{
						HardPlayGrid[i][j].LoadImg("tile_32.jpg", screen);
					}
					else
					{
						HardPlayGrid[i][j].LoadImg("tile_flag_32.jpg", screen);
					}
				}
				HardPlayGrid[i][j].Render(screen);
			}
		}
		display_flag_hard(font, screen);
		check_for_game_over_hard();
	}
}


void Field::generate_mines_easy()
{
	std::vector<int> positions;
	for (int i = 0; i < EASY_NUM_ROW * EASY_NUM_COL; i++)
		positions.push_back(i);
	srand(unsigned(time(0)));
	std::random_shuffle(positions.begin(), positions.end());

	int x, y;
	SDL_GetMouseState(&x, &y);

	
	for (int i = 0; i < EASY_NUM_MINE; i++)
	{
		int pos = positions.at(i);
		if (EasyPlayGrid[pos / EASY_NUM_ROW][pos % EASY_NUM_COL].get_is_mine() == true or
			(pos / EASY_NUM_ROW == (x / EASY_CELL_SIZE - 1) and pos % EASY_NUM_COL == (y / EASY_CELL_SIZE - 1)))
		{
			std::random_shuffle(positions.begin() + i, positions.end());
			i--;
		}
		else
		{
			EasyPlayGrid[pos / EASY_NUM_ROW][pos % EASY_NUM_COL].set_is_mine(true);
		}
	}
}

void Field::generate_mines_medium()
{
	std::vector<int> positions;
	for (int i = 0; i < MEDIUM_NUM_ROW * MEDIUM_NUM_COL; i++)
		positions.push_back(i);
	srand(unsigned(time(0)));
	std::random_shuffle(positions.begin(), positions.end());

	int x, y;
	SDL_GetMouseState(&x, &y);


	for (int i = 0; i < MEDIUM_NUM_MINE; i++)
	{
		int pos = positions.at(i);
		if (MediumPlayGrid[pos / MEDIUM_NUM_ROW][pos % MEDIUM_NUM_COL].get_is_mine() == true or
			(pos / MEDIUM_NUM_ROW == (x / MEDIUM_CELL_SIZE - 1) and pos % MEDIUM_NUM_COL == (y / MEDIUM_CELL_SIZE - 1)))
		{
			std::random_shuffle(positions.begin() + i, positions.end());
			i--;
		}
		else
		{
			MediumPlayGrid[pos / MEDIUM_NUM_ROW][pos % MEDIUM_NUM_COL].set_is_mine(true);
		}
	}
}

void Field::generate_mines_hard()
{
	std::vector<int> positions;
	for (int i = 0; i < HARD_NUM_ROW * HARD_NUM_COL; i++)
		positions.push_back(i);
	srand(unsigned(time(0)));
	std::random_shuffle(positions.begin(), positions.end());

	int x, y;
	SDL_GetMouseState(&x, &y);


	for (int i = 0; i < HARD_NUM_MINE; i++)
	{
		int pos = positions.at(i);
		if (HardPlayGrid[pos / HARD_NUM_ROW][pos % HARD_NUM_COL].get_is_mine() == true or
			(pos / HARD_NUM_ROW == (x / HARD_CELL_SIZE - 1) and pos % HARD_NUM_COL == (y / HARD_CELL_SIZE - 1)))
		{
			std::random_shuffle(positions.begin() + i, positions.end());
			i--;
		}
		else
		{
			HardPlayGrid[pos / HARD_NUM_ROW][pos % HARD_NUM_COL].set_is_mine(true);
		}
	}
}


void Field::check_for_game_over_easy()
{
	int total_unopen_cells = 0;
	for (int i = 0; i < EASY_NUM_ROW; i++)
	{
		for (int j = 0; j < EASY_NUM_COL; j++)
		{
			if (EasyPlayGrid[i][j].get_is_open() == false)
				total_unopen_cells++;
			else if (EasyPlayGrid[i][j].get_is_mine() == true)
			{
				game_over = true;
				is_win = false;
				return;
			}
		}
	}
	if (EASY_NUM_MINE == total_unopen_cells)
	{
		game_over = true;
		is_win = true;
	}
}

void Field::check_for_game_over_medium()
{
	int total_unopen_cells = 0;
	for (int i = 0; i < MEDIUM_NUM_ROW; i++)
	{
		for (int j = 0; j < MEDIUM_NUM_COL; j++)
		{
			if (MediumPlayGrid[i][j].get_is_open() == false)
				total_unopen_cells++;
			else if (MediumPlayGrid[i][j].get_is_mine() == true)
			{
				game_over = true;
				is_win = false;
				return;
			}
		}
	}
	if (MEDIUM_NUM_MINE == total_unopen_cells)
	{
		game_over = true;
		is_win = true;
	}
}

void Field::check_for_game_over_hard()
{
	int total_unopen_cells = 0;
	for (int i = 0; i < HARD_NUM_ROW; i++)
	{
		for (int j = 0; j < HARD_NUM_COL; j++)
		{
			if (HardPlayGrid[i][j].get_is_open() == false)
				total_unopen_cells++;
			else if (HardPlayGrid[i][j].get_is_mine() == true)
			{
				game_over = true;
				is_win = false;
				return;
			}
		}
	}
	if (HARD_NUM_MINE == total_unopen_cells)
	{
		game_over = true;
		is_win = true;
	}
}


void Field::open_cell_easy(const int& x, const int& y)
{
	if (game_over == false)
	{
		if (x >= 0 and x < EASY_NUM_ROW and y >= 0 and y < EASY_NUM_COL)
		{
			if (first_click == true)
			{
				first_click = false;
				generate_mines_easy();
			}
			EasyPlayGrid[x][y].Open_easy(EasyPlayGrid, x, y);
		}
	}
}

void Field::open_cell_medium(const int& x, const int& y)
{
	if (game_over == false)
	{
		
		if (x >= 0 and x < MEDIUM_NUM_ROW and y >= 0 and y < MEDIUM_NUM_COL)
		{
			if (first_click == true)
			{
				first_click = false;
				generate_mines_medium();
			}
			MediumPlayGrid[x][y].Open_medium(MediumPlayGrid, x, y);
		}
	}
}

void Field::open_cell_hard(const int& x, const int& y)
{
	if (game_over == false)
	{
		if (x >= 0 and x < HARD_NUM_ROW and y >= 0 and y < HARD_NUM_COL)
		{
			if (first_click == true)
			{
				first_click = false;
				generate_mines_hard();
			}
			HardPlayGrid[x][y].Open_hard(HardPlayGrid, x, y);
		}
	}
}


void Field::flag_cell_easy(const int& x, const int& y)
{
	if (game_over == false and EasyPlayGrid[x][y].get_is_open() == false)
	{
		if (EasyPlayGrid[x][y].get_is_flag() == false)
			count_flag++;
		else
			count_flag--;
		EasyPlayGrid[x][y].Flag_easy(EasyPlayGrid, x, y);

	}
}

void Field::flag_cell_medium(const int& x, const int& y)
{
	if (game_over == false and MediumPlayGrid[x][y].get_is_open() == false)
	{
		if (MediumPlayGrid[x][y].get_is_flag() == false)
			count_flag++;
		else
			count_flag--;
		MediumPlayGrid[x][y].Flag_medium(MediumPlayGrid, x, y);

	}
}

void Field::flag_cell_hard(const int& x, const int& y)
{
	if (game_over == false and HardPlayGrid[x][y].get_is_open() == false)
	{
		if (HardPlayGrid[x][y].get_is_flag() == false)
			count_flag++;
		else
			count_flag--;
		HardPlayGrid[x][y].Flag_hard(HardPlayGrid, x, y);

	}
}


void Field::display_flag_easy(TTF_Font* font, SDL_Renderer* screen)
{
	Text text;
	text.SetColor(Text::BLACK_TEXT);

	std::string str_val = "Flags: ";
	int count = EASY_NUM_MINE - get_count_flag();
	std::string str_count_val = std::to_string(count);
	str_val += str_count_val;
	text.SetText(str_val);
	text.LoadFromRenderText(font, screen);
	text.RenderText(screen, FLAG_COUNT_X_POS, FLAG_COUNT_Y_POS);
}

void Field::display_flag_medium(TTF_Font* font, SDL_Renderer* screen)
{
	Text text;
	text.SetColor(Text::BLACK_TEXT);

	std::string str_val = "Flags: ";
	int count = MEDIUM_NUM_MINE - get_count_flag();
	std::string str_count_val = std::to_string(count);
	str_val += str_count_val;
	text.SetText(str_val);
	text.LoadFromRenderText(font, screen);
	text.RenderText(screen, FLAG_COUNT_X_POS, FLAG_COUNT_Y_POS);
}

void Field::display_flag_hard(TTF_Font* font, SDL_Renderer* screen)
{
	Text text;
	text.SetColor(Text::BLACK_TEXT);

	std::string str_val = "Flags: ";
	int count = HARD_NUM_MINE - get_count_flag();
	std::string str_count_val = std::to_string(count);
	str_val += str_count_val;
	text.SetText(str_val);
	text.LoadFromRenderText(font, screen);
	text.RenderText(screen, FLAG_COUNT_X_POS, FLAG_COUNT_Y_POS);
}


int Field::draw_button(SDL_Renderer* screen)
{
	button[0].SetRect(BUTTON_X_POS, BUTTON_Y_POS);
	if (button[0].get_is_pressed() == false)
		button[0].LoadImg("button.png", screen);
	else
	{
		button[0].LoadImg("pressed_button.jpg", screen);
		game_reset_easy();
		game_reset_medium();
		game_reset_hard();
	}

	button[1].SetRect(10, 10);
	if (button[1].get_is_pressed() == false)
		button[1].LoadImg("BackButton.png", screen);
	else
	{
		button[1].LoadImg("PressedBackButton.png", screen);
		button[1].Render(screen);
		return 0;
	}

	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
		button[i].Render(screen);
	return 1;
}

void Field::press_button(const int& x, const int& y)
{
	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
		button[i].Press(x, y);
}

void Field::unpress_button()
{
	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
		button[i].Unpress();
}


int Field::display_end_easy(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == true)
	{
		SDL_RenderPresent(screen);
		BaseObject game_message;
		game_message.SetRect(END_MESSAGE_X_POS, END_MESSGAE_Y_POS);
		if (is_win == true)
		{
			game_message.LoadImg("You_win.jpg", screen);
			game_message.Render(screen);
		}
		else
		{
			for (int i = 0; i < EASY_NUM_ROW; i++)
			{
				for (int j = 0; j < EASY_NUM_COL; j++)
				{
					if (EasyPlayGrid[i][j].get_is_mine() == true and EasyPlayGrid[i][j].get_is_open() == false)
					{
						EasyPlayGrid[i][j].set_is_open(true);
						EasyPlayGrid[i][j].LoadImg(tile_bomb_name, screen);
						EasyPlayGrid[i][j].Render(screen);
						SDL_RenderPresent(screen);
						srand(unsigned(time(0)));
						SDL_Delay(rand() % (5000 / EASY_NUM_MINE));

					}
				}
			}
			game_message.LoadImg("You_lose.jpg", screen);
			game_message.Render(screen);
		}
		SDL_RenderPresent(screen);
	}

	return 1;
}

int Field::display_end_medium(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == true)
	{
		SDL_RenderPresent(screen);
		BaseObject game_message;
		game_message.SetRect(END_MESSAGE_X_POS, END_MESSGAE_Y_POS);
		if (is_win == true)
		{
			game_message.LoadImg("You_win.jpg", screen);
			game_message.Render(screen);
		}
		else
		{
			for (int i = 0; i < MEDIUM_NUM_ROW; i++)
			{
				for (int j = 0; j < MEDIUM_NUM_COL; j++)
				{
					if (MediumPlayGrid[i][j].get_is_mine() == true and MediumPlayGrid[i][j].get_is_open() == false)
					{
						MediumPlayGrid[i][j].set_is_open(true);
						MediumPlayGrid[i][j].LoadImg("tile_bomb_48.jpg", screen);
						MediumPlayGrid[i][j].Render(screen);
						SDL_RenderPresent(screen);
						srand(unsigned(time(0)));
						SDL_Delay(rand() % (5000 / MEDIUM_NUM_MINE));

					}
				}
			}
			game_message.LoadImg("You_lose.jpg", screen);
			game_message.Render(screen);
		}
		SDL_RenderPresent(screen);
	}

	return 1;
}

int Field::display_end_hard(SDL_Renderer* screen, TTF_Font* font)
{
	if (game_over == true)
	{
		SDL_RenderPresent(screen);
		BaseObject game_message;
		game_message.SetRect(END_MESSAGE_X_POS, END_MESSGAE_Y_POS);
		if (is_win == true)
		{
			game_message.LoadImg("You_win.jpg", screen);
			game_message.Render(screen);
		}
		else
		{
			for (int i = 0; i < HARD_NUM_ROW; i++)
			{
				for (int j = 0; j < HARD_NUM_COL; j++)
				{
					if (HardPlayGrid[i][j].get_is_mine() == true and HardPlayGrid[i][j].get_is_open() == false)
					{
						HardPlayGrid[i][j].set_is_open(true);
						HardPlayGrid[i][j].LoadImg("tile_bomb_32.jpg", screen);
						HardPlayGrid[i][j].Render(screen);
						SDL_RenderPresent(screen);
						srand(unsigned(time(0)));
						SDL_Delay(rand() % (5000 / HARD_NUM_MINE));

					}
				}
			}
			game_message.LoadImg("You_lose.jpg", screen);
			game_message.Render(screen);
		}
		SDL_RenderPresent(screen);
	}

	return 1;
}


void Field::game_reset_easy()
{
	is_win = false;
	first_click = true;
	game_over = false;
	count_flag = 0;
	for (int i = 0; i < EASY_NUM_ROW; i++)
	{
		for (int j = 0; j < EASY_NUM_COL; j++)
		{
			EasyPlayGrid[i][j].set_is_flag(false);
			EasyPlayGrid[i][j].set_is_open(false);
			EasyPlayGrid[i][j].set_is_mine(false);
		}
	}
}

void Field::game_reset_medium()
{
	is_win = false;
	first_click = true;
	game_over = false;
	count_flag = 0;
	for (int i = 0; i < MEDIUM_NUM_ROW; i++)
	{
		for (int j = 0; j < MEDIUM_NUM_COL; j++)
		{
			MediumPlayGrid[i][j].set_is_flag(false);
			MediumPlayGrid[i][j].set_is_open(false);
			MediumPlayGrid[i][j].set_is_mine(false);
		}
	}
}

void Field::game_reset_hard()
{
	is_win = false;
	first_click = true;
	game_over = false;
	count_flag = 0;
	for (int i = 0; i < HARD_NUM_ROW; i++)
	{
		for (int j = 0; j < HARD_NUM_COL; j++)
		{
			HardPlayGrid[i][j].set_is_flag(false);
			HardPlayGrid[i][j].set_is_open(false);
			HardPlayGrid[i][j].set_is_mine(false);
		}
	}
}


void Field::clear_easy()
{
	for (int i = 0; i < EASY_NUM_ROW; i++)
	{
		for (int j = 0; j < EASY_NUM_COL; j++)
		{
			EasyPlayGrid[i][j].Free();
		}
	}
	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
	{
		button[i].Free();
	}
}

void Field::clear_medium()
{
	for (int i = 0; i < MEDIUM_NUM_ROW; i++)
	{
		for (int j = 0; j < MEDIUM_NUM_COL; j++)
		{
			MediumPlayGrid[i][j].Free();
		}
	}
	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
	{
		button[i].Free();
	}
}

void Field::clear_hard()
{
	for (int i = 0; i < HARD_NUM_ROW; i++)
	{
		for (int j = 0; j < HARD_NUM_COL; j++)
		{
			HardPlayGrid[i][j].Free();
		}
	}
	for (int i = 0; i < NUMBER_OF_FIELD_BUTTON; i++)
	{
		button[i].Free();
	}
}


bool Field::CheckMouseFocus(const int& x, const int& y, const int& text_x, const int& text_y, const int& text_w, const int& text_h)
{
	if (x >= text_x and x <= text_x + text_w and y >= text_y and y <= text_y + text_h)
		return true;
	return false;
}