#pragma once
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>


static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//Cells
const int EASY_CELL_SIZE = 64;
const int MEDIUM_CELL_SIZE = 48;
const int HARD_CELL_SIZE = 32;

//Screen
const int SCREEN_WIDTH = 768;
const int SCREEN_HEIGHT = 768;

const int EASY_NUM_ROW = 10;
const int EASY_NUM_COL = 10;
const int EASY_NUM_MINE = 10;

const int MEDIUM_NUM_ROW = 14;
const int MEDIUM_NUM_COL = 14;
const int MEDIUM_NUM_MINE = 19;

const int HARD_NUM_ROW = 22;
const int HARD_NUM_COL = 22;
const int HARD_NUM_MINE = 48;


//Game
static bool g_is_easy = true;
static bool g_is_medium = false;
static bool g_is_hard = false;
static int mouse_cell_x = 0;
static int mouse_cell_y = 0;

const int FLAG_COUNT_X_POS = 325;
const int FLAG_COUNT_Y_POS = 728;

const int NUMBER_OF_FIELD_BUTTON = 2;

const int BUTTON_WIDTH = 25;
const int BUTTON_HEIGHT = 25;
const int BUTTON_X_POS = (SCREEN_WIDTH - BUTTON_WIDTH) / 2;
const int BUTTON_Y_POS = (SCREEN_HEIGHT - BUTTON_HEIGHT) / 2 - 365;

//Fonts
static TTF_Font* g_font = NULL;
static char g_name_font[] = ("font.ttf");

static std::string tile_1_name = "tile_1_64.jpg";
static std::string tile_2_name = "tile_2_64.jpg";
static std::string tile_3_name = "tile_3_64.jpg";
static std::string tile_4_name = "tile_4_64.jpg";
static std::string tile_5_name = "tile_5_64.jpg";
static std::string tile_6_name = "tile_6_64.jpg";
static std::string tile_7_name = "tile_7_64.jpg";
static std::string tile_8_name = "tile_8_64.jpg";
static std::string tile_bomb_name = "tile_bomb_64.jpg";
static std::string tile_empty_name = "tile_empty_64.jpg";
static std::string tile_flag_name = "tile_flag_64.jpg";
static std::string tile_red_bomb_name = "tile_red_bomb_64.jpg";
static std::string tile_name = "tile_64.jpg";


//Start Menu
static bool is_quit = false;
static bool is_running = true;
const int NUMBER_OF_MENU_BUTTON = 3;

//Option Menu
const int NUMBER_OF_OPTION_BUTTON = 4;
static bool is_choosing = true;

//End Menu
const int END_MENU_SIZE = 640;
const int END_MESSAGE_WIDTH = 480;
const int END_MESSAGE_HEIGHT = 240;
const int END_MESSAGE_X_POS = (SCREEN_WIDTH - END_MESSAGE_WIDTH) / 2;
const int END_MESSGAE_Y_POS = (SCREEN_HEIGHT - END_MESSAGE_HEIGHT) / 2;


const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;


#endif // !COMMON_FUNCTION_H_
