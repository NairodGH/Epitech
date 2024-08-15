/*
** EPITECH PROJECT, 2022
** SFML.hpp
** File description:
** SFML
*/

#pragma once

#include "IDisplay.hpp"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace arc
{
    class SFML : public virtual arc::IDisplay
    {
        public:
            virtual ~SFML() = default;
            virtual void initDisplay(void);
            virtual void destroyDisplay(void);
            virtual void display(void);
            virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY);
            virtual void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY);
            virtual std::vector<DisplayKey> getKeys(void);
        private:
            sf::RenderWindow _window;
            sf::Event _event;
            sf::Sprite _square;
            sf::Sprite _circle;
            sf::Sprite _cross;
            sf::Text _text;
            sf::Color _color[13];
            sf::Font _font;
            std::vector<DisplayKey> _keys;
    };
};