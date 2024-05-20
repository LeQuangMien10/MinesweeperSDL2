#include "OptionMenu.h"
#include "Game.h"

#undef main

int main(int argc, char* argv[])
{
	if (InitData() == false)
		return 0;
	bool main_loop = true;
	while (main_loop)
	{
		int option1 = ShowStartMenu();
		if (option1 == 0)
		{
			Close();
			return 0;
		}
		else if (option1 == 1)
		{
			start_menu.Free();
			is_running = true;
			int option2 = ShowPlayScreen();
			if (option2 == 0)
			{
				Close();
				return 0;
			}
			else if (option2 == -1)
			{
				is_running = false;
			}
		}
		else if (option1 == 2)
		{
			start_menu.Free();
			is_choosing = true;
			int option3 = ShowOptionMenu();
			if (option3 == 0)
			{
				Close();
				return 0;
			}
			else if (option3 == -1)
				is_choosing = false;
			else if (option3 == 1)
			{
				g_is_easy = true;
				g_is_medium = false;
				g_is_hard = false;
				is_choosing = false;
			}
			else if (option3 == 2)
			{
				g_is_easy = false;
				g_is_medium = true;
				g_is_hard = false;
				is_choosing = false;
			}
			else if (option3 == 3)
			{
				g_is_easy = false;
				g_is_medium = false;
				g_is_hard = true;
				is_choosing = false;
			}
		}

	}
	return 0;
}