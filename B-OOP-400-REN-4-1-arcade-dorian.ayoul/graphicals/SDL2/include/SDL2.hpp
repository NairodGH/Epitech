/*
** EPITECH PROJECT, 2022
** SDL2.hpp
** File description:
** SDL2
*/

#pragma once

#include "IDisplay.hpp"
#include <tuple>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace arc
{
    class SDL2 : public virtual arc::IDisplay
    {
        public:
            virtual ~SDL2() = default;
            virtual void initDisplay(void);
            virtual void destroyDisplay(void);
            virtual void display(void);
            virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY);
            virtual std::vector<DisplayKey> getKeys(void);
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            SDL_Texture *_square;
            SDL_Texture *_circle;
            SDL_Texture *_cross;
            TTF_Font* _font;
            std::tuple<Uint8, Uint8, Uint8> _color[13];
    };
};