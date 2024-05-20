#pragma once
#ifndef CELL_H_
#define CELL_H_
#include "CommonFunction.h"
#include "BaseObject.h"


class Cell : public BaseObject
{
public:
	Cell();
	~Cell();

	void Open_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y);
	void Open_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y);
	void Open_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y);
	void set_is_open(const bool& is_open_) { is_open = is_open_; }
	bool get_is_open() const { return is_open; }

	void set_is_mine(const bool& is_mine_) { is_mine = is_mine_; }
	bool get_is_mine() const { return is_mine; }
	void count_mine_around_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y);
	void count_mine_around_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y);
	void count_mine_around_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y);
	int get_count_mine_around() const { return mines_around; }


	void Flag_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y);
	void Flag_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y);
	void Flag_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y);
	void set_is_flag(const bool& is_flag_) { is_flag = is_flag_; }
	bool get_is_flag() const { return is_flag; }
	void count_flag_around_easy(Cell Grid[][EASY_NUM_COL], const int& x, const int& y);
	void count_flag_around_medium(Cell Grid[][MEDIUM_NUM_COL], const int& x, const int& y);
	void count_flag_around_hard(Cell Grid[][HARD_NUM_COL], const int& x, const int& y);

	int get_count_flag_around() const { return flags_around; }

private:
	int flags_around;
	int mines_around;
	bool is_open;
	bool is_mine;
	bool is_flag;
};

#endif // !CELL_H_
