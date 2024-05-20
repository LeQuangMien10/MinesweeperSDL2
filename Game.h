#pragma once
#ifndef GAME_H_
#define GAME_H_

#include "Field.h"

int ShowPlayScreen()
{

	//Load Field
	Field game_field;
	if (g_is_easy and !g_is_medium and !g_is_hard)
		game_field.draw_easy_grid(g_screen, g_font);
	else if (!g_is_easy and g_is_medium and !g_is_hard)
		game_field.draw_medium_grid(g_screen, g_font);
	else if (!g_is_easy and !g_is_medium and g_is_hard)
		game_field.draw_hard_grid(g_screen, g_font);


	game_field.draw_button(g_screen);
	SDL_RenderPresent(g_screen);

	while (is_running)
	{

		//Handlde Event
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_is_easy and !g_is_medium and !g_is_hard)
			{
				mouse_cell_x = g_event.button.x / EASY_CELL_SIZE - 1;
				mouse_cell_y = g_event.button.y / EASY_CELL_SIZE - 1;
			}
			else if (!g_is_easy and g_is_medium and !g_is_hard)
			{
				mouse_cell_x = g_event.button.x / MEDIUM_CELL_SIZE - 1;
				mouse_cell_y = g_event.button.y / MEDIUM_CELL_SIZE - 1;
			}
			else if (!g_is_easy and !g_is_medium and g_is_hard)
			{
				mouse_cell_x = g_event.button.x / HARD_CELL_SIZE - 1;
				mouse_cell_y = g_event.button.y / HARD_CELL_SIZE - 1;
			}


			if (g_event.type == SDL_QUIT)
			{
				is_running = false;
				is_quit = true;
				game_field.clear_easy();
				game_field.clear_medium();
				game_field.clear_hard();
				game_field.Free();
				return 0;
			}
			else if (g_event.type == SDL_MOUSEMOTION)
			{

			}
			else if (g_event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (g_event.button.button == SDL_BUTTON_LEFT)
				{
					game_field.press_button(g_event.button.x, g_event.button.y);
					if (game_field.draw_button(g_screen) == 0)
					{
						game_field.unpress_button();
						SDL_RenderPresent(g_screen);
						game_field.clear_easy();
						game_field.clear_medium();
						game_field.clear_hard();
						game_field.Free();
						return -1;
					}
					SDL_RenderPresent(g_screen);
				}
			}
			else if (g_event.type == SDL_MOUSEBUTTONUP)
			{
				switch (g_event.button.button)
				{
				case SDL_BUTTON_LEFT:
					game_field.unpress_button();
					if (g_is_easy and !g_is_medium and !g_is_hard)
					{
						game_field.open_cell_easy(mouse_cell_x, mouse_cell_y);
						game_field.draw_easy_grid(g_screen, g_font);
					}
					else if (!g_is_easy and g_is_medium and !g_is_hard)
					{
						game_field.open_cell_medium(mouse_cell_x, mouse_cell_y);
						game_field.draw_medium_grid(g_screen, g_font);
					}
					else if (!g_is_easy and !g_is_medium and g_is_hard)
					{
						game_field.open_cell_hard(mouse_cell_x, mouse_cell_y);
						game_field.draw_hard_grid(g_screen, g_font);
					}

					game_field.draw_button(g_screen);
					SDL_RenderPresent(g_screen);
					if (game_field.get_game_over() == true)
					{
						if (g_is_easy and !g_is_medium and !g_is_hard)
							game_field.display_end_easy(g_screen, g_font);
						else if (!g_is_easy and g_is_medium and !g_is_hard)
							game_field.display_end_medium(g_screen, g_font);
						else if (!g_is_easy and !g_is_medium and g_is_hard)
							game_field.display_end_hard(g_screen, g_font);
					}
					break;
				case SDL_BUTTON_RIGHT:
					if (g_is_easy and !g_is_medium and !g_is_hard)
					{
						game_field.flag_cell_easy(mouse_cell_x, mouse_cell_y);
						game_field.draw_easy_grid(g_screen, g_font);
					}
					else if (!g_is_easy and g_is_medium and !g_is_hard)
					{
						game_field.flag_cell_medium(mouse_cell_x, mouse_cell_y);
						game_field.draw_medium_grid(g_screen, g_font);
					}
					else if (!g_is_easy and !g_is_medium and g_is_hard)
					{
						game_field.flag_cell_hard(mouse_cell_x, mouse_cell_y);
						game_field.draw_hard_grid(g_screen, g_font);
					}
					game_field.draw_button(g_screen);
					SDL_RenderPresent(g_screen);
					break;
				default:
					break;
				}
			}
		}
	}

	game_field.Free();
	return 0;
}

#endif // !GAME_H_
