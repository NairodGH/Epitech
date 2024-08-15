/*
** EPITECH PROJECT, 2022
** SDL2.cpp
** File description:
** SDL2
*/

#include "SDL2.hpp"

// Unfortunately we did not succeed in the satanic image summonning rituals this graphic library gives us :(
void arc::SDL2::initDisplay(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
        return;
    this->_square = IMG_LoadTexture(this->_renderer, "graphicals/SFML/ressources/square.png");
    if (this->_square == NULL)
        return;
    this->_circle = IMG_LoadTexture(this->_renderer, "graphicals/SFML/ressources/circle.png");
    if (this->_circle == NULL)
        return;
    this->_cross = IMG_LoadTexture(this->_renderer, "graphicals/SFML/ressources/cross.png");
    if (this->_cross == NULL)
        return;
    this->_font = TTF_OpenFont("graphicals/SFML/ressources/LiberationSerif-Regular.ttf", 14);
    if (this->_font == NULL)
        return;
    this->_window = NULL;
    this->_window =  SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    if (this->_window == NULL)
        return;
    this->_color[0] = {0, 0, 0};
    this->_color[DisplayColor::D_RED] = {255, 0, 0};
    this->_color[DisplayColor::D_BLUE] = {0, 0, 255};
    this->_color[DisplayColor::D_GREEN] = {0, 128, 0};
    this->_color[DisplayColor::D_WHITE] = {255, 255, 255};
    this->_color[DisplayColor::D_ORANGE] = {255, 165, 0};
    this->_color[DisplayColor::D_CYAN] = {0, 255, 255};
    this->_color[DisplayColor::D_PURPLE] = {199, 21, 133};
    this->_color[DisplayColor::D_YELLOW] = {255, 255, 0};
    this->_color[DisplayColor::D_LIME] = {0, 255, 0};
    this->_color[DisplayColor::D_BROWN] = {139, 69, 19};
    this->_color[DisplayColor::D_PINK] = {255, 192, 203};
    this->_color[DisplayColor::D_GRAY] = {128, 128, 128};
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
}

void arc::SDL2::destroyDisplay(void)
{
    SDL_DestroyTexture(this->_square);
    SDL_DestroyTexture(this->_circle);
    SDL_DestroyTexture(this->_cross);
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void arc::SDL2::display(void)
{
    SDL_RenderClear(this->_renderer);
    SDL_RenderPresent(this->_renderer);
}

void arc::SDL2::drawSquare(unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Rect rect{static_cast<int>(posX), static_cast<int>(posY), 0, 0};

    SDL_SetTextureColorMod(this->_square, std::get<0>(_color[color]), std::get<1>(_color[color]), std::get<2>(_color[color]));
    SDL_RenderCopy(this->_renderer, this->_square, NULL, &rect);
}

void arc::SDL2::drawCircle(unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Rect rect{static_cast<int>(posX), static_cast<int>(posY), 0, 0};

    SDL_SetTextureColorMod(this->_circle, std::get<0>(_color[color]), std::get<1>(_color[color]), std::get<2>(_color[color]));
    SDL_RenderCopy(this->_renderer, this->_circle, NULL, &rect);
}

void arc::SDL2::drawCross(unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Rect rect{static_cast<int>(posX), static_cast<int>(posY), 0, 0};

    SDL_SetTextureColorMod(this->_cross, std::get<0>(_color[color]), std::get<1>(_color[color]), std::get<2>(_color[color]));
    SDL_RenderCopy(this->_renderer, this->_cross, NULL, &rect);
}

void arc::SDL2::drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY)
{
    SDL_Rect rect{static_cast<int>(posX), static_cast<int>(posY), 0, 0};
    char tmp[2] = "";
    std::sprintf(tmp, "%u", letter);
    tmp[1] = '\0';
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(this->_font, tmp, {std::get<0>(_color[color]), std::get<1>(_color[color]), std::get<2>(_color[color]), 255});
    SDL_Texture* Message = SDL_CreateTextureFromSurface(this->_renderer, surfaceMessage);

    SDL_RenderCopy(this->_renderer, Message, NULL, &rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}

std::vector<arc::DisplayKey> arc::SDL2::getKeys(void)
{
    std::vector<arc::DisplayKey> key;

    while (SDL_PollEvent(&this->_event)) {
        if (this->_event.type == SDL_QUIT)
            destroyDisplay();
        switch(this->_event.type ) {
        case SDLK_LEFT:
            key.push_back(arc::DisplayKey::D_LEFT_ARROW);
            break;
        case SDLK_RIGHT:
            key.push_back(arc::DisplayKey::D_RIGHT_ARROW);
            break;
        case SDL_KEYDOWN:
            key.push_back(arc::DisplayKey::D_DOWN_ARROW);
            break;
        case SDL_KEYUP:
            key.push_back(arc::DisplayKey::D_UP_ARROW);
            break;
        default:
            break;
        }
    }
    return key;
}