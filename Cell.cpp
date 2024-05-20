#include "Cell.h"

Cell::Cell()
{
	flags_around = 0;
	mines_around = 0;
	is_open = false;
	is_mine = false;
	is_flag = false;
}

Cell::~Cell()
{

}

void Cell::Open_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_flag() == false)
	{
		if (Grid[x][y].get_is_open() == false)
		{
			Grid[x][y].set_is_open(true);
			Grid[x][y].count_mine_around_easy(Grid, x, y);
			if (Grid[x][y].get_count_mine_around() == 0 and Grid[x][y].get_is_mine() == 0)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == EASY_NUM_COL or j + y == EASY_NUM_ROW)
							continue;

						Grid[i + x][j + y].Open_easy(Grid, i + x, j + y);
					}
				}
			}
		}
		else
		{
			Grid[x][y].count_flag_around_easy(Grid, x, y);
			Grid[x][y].count_mine_around_easy(Grid, x, y);
			if (Grid[x][y].get_count_flag_around() == Grid[x][y].get_count_mine_around())
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == EASY_NUM_COL or j + y == EASY_NUM_ROW)
							continue;

						if (Grid[i + x][j + y].get_is_open() == false)
							Grid[i + x][j + y].Open_easy(Grid, i + x, j + y);
					}
				}

			}
		}
	}
}

void Cell::Open_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_flag() == false)
	{
		if (Grid[x][y].get_is_open() == false)
		{
			Grid[x][y].set_is_open(true);
			Grid[x][y].count_mine_around_medium(Grid, x, y);
			if (Grid[x][y].get_count_mine_around() == 0 and Grid[x][y].get_is_mine() == 0)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == MEDIUM_NUM_COL or j + y == MEDIUM_NUM_ROW)
							continue;

						Grid[i + x][j + y].Open_medium(Grid, i + x, j + y);
					}
				}
			}
		}
		else
		{
			Grid[x][y].count_flag_around_medium(Grid, x, y);
			Grid[x][y].count_mine_around_medium(Grid, x, y);
			if (Grid[x][y].get_count_flag_around() == Grid[x][y].get_count_mine_around())
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == MEDIUM_NUM_COL or j + y == MEDIUM_NUM_ROW)
							continue;

						if (Grid[i + x][j + y].get_is_open() == false)
							Grid[i + x][j + y].Open_medium(Grid, i + x, j + y);
					}
				}

			}
		}
	}
}

void Cell::Open_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_flag() == false)
	{
		if (Grid[x][y].get_is_open() == false)
		{
			Grid[x][y].set_is_open(true);
			Grid[x][y].count_mine_around_hard(Grid, x, y);
			if (Grid[x][y].get_count_mine_around() == 0 and Grid[x][y].get_is_mine() == 0)
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == HARD_NUM_COL or j + y == HARD_NUM_ROW)
							continue;

						Grid[i + x][j + y].Open_hard(Grid, i + x, j + y);
					}
				}
			}
		}
		else
		{
			Grid[x][y].count_flag_around_hard(Grid, x, y);
			Grid[x][y].count_mine_around_hard(Grid, x, y);
			if (Grid[x][y].get_count_flag_around() == Grid[x][y].get_count_mine_around())
			{
				for (int i = -1; i <= 1; i++)
				{
					for (int j = -1; j <= 1; j++)
					{
						if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
							or i + x == HARD_NUM_COL or j + y == HARD_NUM_ROW)
							continue;

						if (Grid[i + x][j + y].get_is_open() == false)
							Grid[i + x][j + y].Open_hard(Grid, i + x, j + y);
					}
				}

			}
		}
	}
}


void Cell::count_flag_around_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y)
{
	flags_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == EASY_NUM_COL or j + y == EASY_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_flag() == true)
				flags_around++;
		}
	}
}

void Cell::count_flag_around_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y)
{
	flags_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == MEDIUM_NUM_COL or j + y == MEDIUM_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_flag() == true)
				flags_around++;
		}
	}
}

void Cell::count_flag_around_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y)
{
	flags_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == HARD_NUM_COL or j + y == HARD_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_flag() == true)
				flags_around++;
		}
	}
}


void Cell::count_mine_around_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y)
{
	mines_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == EASY_NUM_COL or j + y == EASY_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_mine() == true)
				mines_around++;
		}
	}
}

void Cell::count_mine_around_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y)
{
	mines_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == MEDIUM_NUM_COL or j + y == MEDIUM_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_mine() == true)
				mines_around++;
		}
	}
}

void Cell::count_mine_around_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y)
{
	mines_around = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if ((i == 0 and j == 0) or i + x < 0 or j + y < 0
				or i + x == HARD_NUM_COL or j + y == HARD_NUM_ROW)
				continue;

			if (Grid[i + x][j + y].get_is_mine() == true)
				mines_around++;
		}
	}
}


void Cell::Flag_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_open() == false)
	{
		Grid[x][y].set_is_flag(!Grid[x][y].get_is_flag());
	}
}

void Cell::Flag_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_open() == false)
	{
		Grid[x][y].set_is_flag(!Grid[x][y].get_is_flag());
	}
}

void Cell::Flag_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y)
{
	if (Grid[x][y].get_is_open() == false)
	{
		Grid[x][y].set_is_flag(!Grid[x][y].get_is_flag());
	}
}
