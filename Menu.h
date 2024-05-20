#pragma once
#ifndef MENU_H_
#define MENU_H_

#include "BaseObject.h"
#include "Button.h"

BaseObject start_menu;
std::string start_menu_name = "Menu.png";
Button menu_button[NUMBER_OF_MENU_BUTTON];

BaseObject option_menu;
std::string option_menu_name = "OptionMenu.png";
Button option_button[NUMBER_OF_OPTION_BUTTON];

bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
		return false;

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Minesweeper", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (g_window == NULL)
		success = false;
	else
	{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL)
			success = false;
		else
		{
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) and imgFlags))
				success = false;
		}
	}

	if (TTF_Init() == -1)
		success = false;
	g_font = TTF_OpenFont(g_name_font, 20);
	if (g_font == NULL)
		success = false;


	return success;
}

void Close()
{
	start_menu.Free();
	option_menu.Free();

	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;

	SDL_DestroyWindow(g_window);
	g_window = NULL;

	IMG_Quit();
	SDL_Quit();
}

bool LoadMenuBackground()
{
	bool ret_bg = start_menu.LoadImg(start_menu_name, g_screen);
	if (!ret_bg)
		return false;
	return true;
}

void DrawMenuButton()
{
	menu_button[0].SetRect(235, 211);
	if (menu_button[0].get_is_pressed() == false)
		menu_button[0].LoadImg("PlayButton.png", g_screen);
	else
		menu_button[0].LoadImg("PressedPlayButton.png", g_screen);

	menu_button[1].SetRect(235, 361);
	if (menu_button[1].get_is_pressed() == false)
		menu_button[1].LoadImg("OptionButton.png", g_screen);
	else
		menu_button[1].LoadImg("PressedOptionButton.png", g_screen);
	
	menu_button[2].SetRect(235, 511);
	if (menu_button[2].get_is_pressed() == false)
		menu_button[2].LoadImg("ExitButton.png", g_screen);
	else
		menu_button[2].LoadImg("PressedExitButton.png", g_screen);

	for (int i = 0; i < NUMBER_OF_MENU_BUTTON; i++)
		menu_button[i].Render(g_screen);
}

int ShowStartMenu()
{
	if (LoadMenuBackground() == false)
		return 0;


	SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
	SDL_RenderClear(g_screen);
	start_menu.Render(g_screen);
	DrawMenuButton();

	SDL_RenderPresent(g_screen);

	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
				return 0;
			}
			else if (g_event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (g_event.button.button == SDL_BUTTON_LEFT)
				{
					for (int i = 0; i < 3; i++)
					{
						menu_button[i].Press(g_event.button.x, g_event.button.y);
					}
					DrawMenuButton();
					SDL_RenderPresent(g_screen);
				}
			}
			else if (g_event.type == SDL_MOUSEBUTTONUP)
			{
				if (g_event.button.button == SDL_BUTTON_LEFT)
				{
					for (int i = 0; i < 3; i++)
					{
						if (menu_button[i].get_is_pressed() == true)
						{
							menu_button[i].Unpress();
							DrawMenuButton();
							SDL_RenderPresent(g_screen);
						}
					}
					if (g_event.button.x >= menu_button[0].GetRect().x and g_event.button.x <= menu_button[0].GetRect().x + menu_button[0].GetRect().w
						and g_event.button.y >= menu_button[0].GetRect().y and g_event.button.y <= menu_button[0].GetRect().y + menu_button[0].GetRect().h)
						return 1;
					else if (g_event.button.x >= menu_button[1].GetRect().x and g_event.button.x <= menu_button[1].GetRect().x + menu_button[1].GetRect().w
						and g_event.button.y >= menu_button[1].GetRect().y and g_event.button.y <= menu_button[1].GetRect().y + menu_button[1].GetRect().h)
						return 2;
					else if (g_event.button.x >= menu_button[2].GetRect().x and g_event.button.x <= menu_button[2].GetRect().x + menu_button[2].GetRect().w
						and g_event.button.y >= menu_button[2].GetRect().y and g_event.button.y <= menu_button[2].GetRect().y + menu_button[2].GetRect().h)
						return 0;
				}
			}
		}

	}

	Close();
	return 0;
}

#endif // !MENU_H_
