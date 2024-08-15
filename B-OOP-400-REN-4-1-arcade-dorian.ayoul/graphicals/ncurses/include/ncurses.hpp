/*
** EPITECH PROJECT, 2022
** ncurses.hpp
** File description:
** ncurses
*/

#pragma once

#include "IDisplay.hpp"
#include <curses.h>

namespace arc
{
    class ncurses : public virtual arc::IDisplay
    {
        public:
            virtual ~ncurses() = default;
            virtual void initDisplay(void);
            virtual void destroyDisplay(void);
            virtual void display(void);
            virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY);
            virtual std::vector<DisplayKey> getKeys(void);
		private:
			std::vector<DisplayKey> _keys;
    };
};