#pragma once
#ifndef OPTION_MENU_H_
#define OPTION_MENU_H_

#include "Menu.h"

bool LoadOptionBackground()
{
	bool ret_bg = option_menu.LoadImg(option_menu_name, g_screen);
	if (!ret_bg)
		return false;
	return true;
}

void DrawOptionButton()
{
	option_button[0].SetRect(135, 135);
	if (option_button[0].get_is_pressed() == false)
		option_button[0].LoadImg("EasyMode.jpg", g_screen);
	else
		option_button[0].LoadImg("ChosenEasyMode.jpg", g_screen);

	option_button[1].SetRect(435, 135);
	if (option_button[1].get_is_pressed() == false)
		option_button[1].LoadImg("MediumMode.jpg", g_screen);
	else
		option_button[1].LoadImg("ChosenMediumMode.jpg", g_screen);

	option_button[2].SetRect(285, 435);
	if (option_button[2].get_is_pressed() == false)
		option_button[2].LoadImg("HardMode.jpg", g_screen);
	else
		option_button[2].LoadImg("ChosenHardMode.jpg", g_screen);

	option_button[3].SetRect(40, 40);
	if (option_button[3].get_is_pressed() == false)
		option_button[3].LoadImg("BackButton.png", g_screen);
	else
		option_button[3].LoadImg("PressedBackButton.png", g_screen);

	for (int i = 0; i < NUMBER_OF_OPTION_BUTTON; i++)
		option_button[i].Render(g_screen);
}

int ShowOptionMenu()
{
	if (LoadOptionBackground() == false)
		return 0;
	start_menu.Free();
	SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
	SDL_RenderClear(g_screen);
	option_menu.Render(g_screen);
	DrawOptionButton();

	SDL_RenderPresent(g_screen);

	while (is_choosing)
	{
		while (SDL_PollEvent(&g_event) != 0)
		{
			if (g_event.type == SDL_QUIT)
			{
				is_choosing = false;
				is_quit = true;
				option_menu.Free();
				return 0;
			}
			else if (g_event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (g_event.button.button == SDL_BUTTON_LEFT)
				{
					for (int i = 0; i < NUMBER_OF_OPTION_BUTTON; i++)
					{
						option_button[i].Press(g_event.button.x, g_event.button.y);
					}
					DrawOptionButton();
					SDL_RenderPresent(g_screen);
				}
			}
			else if (g_event.type == SDL_MOUSEBUTTONUP)
			{
				if (g_event.button.button == SDL_BUTTON_LEFT)
				{
					for (int i = 0; i < NUMBER_OF_OPTION_BUTTON; i++)
					{
						if (option_button[i].get_is_pressed() == true)
						{
							option_button[i].Unpress();
							DrawOptionButton();
							SDL_RenderPresent(g_screen);
						}
					}
					if (g_event.button.x >= option_button[0].GetRect().x and g_event.button.x <= option_button[0].GetRect().x + option_button[0].GetRect().w
						and g_event.button.y >= option_button[0].GetRect().y and g_event.button.y <= option_button[0].GetRect().y + option_button[0].GetRect().h)
						return 1;
					else if (g_event.button.x >= option_button[1].GetRect().x and g_event.button.x <= option_button[1].GetRect().x + option_button[1].GetRect().w
						and g_event.button.y >= option_button[1].GetRect().y and g_event.button.y <= option_button[1].GetRect().y + option_button[1].GetRect().h)
						return 2;
					else if (g_event.button.x >= option_button[2].GetRect().x and g_event.button.x <= option_button[2].GetRect().x + option_button[2].GetRect().w
						and g_event.button.y >= option_button[2].GetRect().y and g_event.button.y <= option_button[2].GetRect().y + option_button[2].GetRect().h)
						return 3;
					else if (g_event.button.x >= option_button[3].GetRect().x and g_event.button.x <= option_button[3].GetRect().x + option_button[3].GetRect().w
						and g_event.button.y >= option_button[3].GetRect().y and g_event.button.y <= option_button[3].GetRect().y + option_button[3].GetRect().h)
					{
						option_menu.Free();
						return -1;
					}
				}
			}
		}
	}

	Close();
	return 0;
}

#endif // !OPTION_MENU_H_

