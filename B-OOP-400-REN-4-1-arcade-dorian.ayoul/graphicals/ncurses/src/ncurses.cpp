/*
** EPITECH PROJECT, 2022
** ncurses.cpp
** File description:
** ncurses
*/

#include "ncurses.hpp"

static const std::map<int, arc::DisplayKey> KEYS = {
	{10, arc::D_ENTER},
	{KEY_BACKSPACE, arc::D_BACKSPACE},
	{' ', arc::D_SPACE},
	{27, arc::D_ESCAPE},
	{KEY_UP, arc::D_UP_ARROW},
	{KEY_DOWN, arc::D_DOWN_ARROW},
	{KEY_LEFT, arc::D_LEFT_ARROW},
	{KEY_RIGHT, arc::D_RIGHT_ARROW},
	{'a', arc::D_KEY_A},
	{'b', arc::D_KEY_B},
	{'c', arc::D_KEY_C},
	{'d', arc::D_KEY_D},
	{'e', arc::D_KEY_E},
	{'f', arc::D_KEY_F},
	{'g', arc::D_KEY_G},
	{'h', arc::D_KEY_H},
	{'i', arc::D_KEY_I},
	{'j', arc::D_KEY_J},
	{'k', arc::D_KEY_K},
	{'l', arc::D_KEY_L},
	{'m', arc::D_KEY_M},
	{'n', arc::D_KEY_N},
	{'o', arc::D_KEY_O},
	{'p', arc::D_KEY_P},
	{'q', arc::D_KEY_Q},
	{'r', arc::D_KEY_R},
	{'s', arc::D_KEY_S},
	{'t', arc::D_KEY_T},
	{'u', arc::D_KEY_U},
	{'v', arc::D_KEY_V},
	{'w', arc::D_KEY_W},
	{'x', arc::D_KEY_X},
	{'y', arc::D_KEY_Y},
	{'z', arc::D_KEY_Z},
	{'0', arc::D_KEY_0},
	{'1', arc::D_KEY_1},
	{'2', arc::D_KEY_2},
	{'3', arc::D_KEY_3},
	{'4', arc::D_KEY_4},
	{'5', arc::D_KEY_5},
	{'6', arc::D_KEY_6},
	{'7', arc::D_KEY_7},
	{'8', arc::D_KEY_8},
	{'9', arc::D_KEY_9},
	{'z', arc::D_KEY_Z},
	{KEY_F(1), arc::D_F1},
	{KEY_F(2), arc::D_F2},
	{KEY_F(3), arc::D_F3},
	{KEY_F(4), arc::D_F4},
	{KEY_F(5), arc::D_F5},
	{KEY_F(6), arc::D_F6},
	{KEY_F(7), arc::D_F7},
	{KEY_F(8), arc::D_F8},
	{KEY_F(9), arc::D_F9}
};

void arc::ncurses::initDisplay(void)
{
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_YELLOW, COLOR_BLACK);
    init_pair(9, COLOR_GREEN, COLOR_BLACK);
    init_pair(10, COLOR_RED, COLOR_BLACK);
    init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(12, COLOR_BLACK, COLOR_BLACK);
}

void arc::ncurses::destroyDisplay(void)
{
    endwin();
}

void arc::ncurses::display(void)
{
    refresh();
}

void arc::ncurses::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR((int)color));
    mvprintw(posY, posX, "O");
    attroff(COLOR_PAIR((int)color));
}

void arc::ncurses::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR((int)color));
    mvprintw(posY, posX, "X");
    attroff(COLOR_PAIR((int)color));
}

void arc::ncurses::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR((int)color));
    mvprintw(posY, posX, "#");
    attroff(COLOR_PAIR((int)color));
}

void arc::ncurses::drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY)
{
    attron(COLOR_PAIR((int)color));
    mvprintw(posY, posX, "%c", letter);
    attroff(COLOR_PAIR((int)color));
}

std::vector<arc::DisplayKey> arc::ncurses::getKeys(void)
{
	int c;

    _keys.clear();
    timeout(0);
    if ((c = getch()) > 0 && KEYS.find(c) != KEYS.end())
        _keys.push_back(KEYS.at(c));
    return _keys;
}