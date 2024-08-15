/*
** EPITECH PROJECT, 2022
** IDisplay.hpp
** File description:
** IDisplay
*/

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "includes.hpp"

namespace arc
{
    enum DisplayColor {
        D_RED = 1,
        D_BLUE,
        D_GREEN,
        D_WHITE,
        D_ORANGE,
        D_CYAN,
        D_PURPLE,
        D_YELLOW,
        D_LIME,
        D_BROWN,
        D_PINK,
        D_GRAY,

        D_COLOR_SIZE
    };

    enum DisplayKey {
        D_ENTER,
        D_BACKSPACE,
        D_SPACE,
        D_ESCAPE,
        D_UP_ARROW,
        D_DOWN_ARROW,
        D_LEFT_ARROW,
        D_RIGHT_ARROW,
        D_KEY_A,
        D_KEY_B,
        D_KEY_C,
        D_KEY_D,
        D_KEY_E,
        D_KEY_F,
        D_KEY_G,
        D_KEY_H,
        D_KEY_I,
        D_KEY_J,
        D_KEY_K,
        D_KEY_L,
        D_KEY_M,
        D_KEY_N,
        D_KEY_O,
        D_KEY_P,
        D_KEY_Q,
        D_KEY_R,
        D_KEY_S,
        D_KEY_T,
        D_KEY_U,
        D_KEY_V,
        D_KEY_W,
        D_KEY_X,
        D_KEY_Y,
        D_KEY_Z,
        D_KEY_1,
        D_KEY_2,
        D_KEY_3,
        D_KEY_4,
        D_KEY_5,
        D_KEY_6,
        D_KEY_7,
        D_KEY_8,
        D_KEY_9,
        D_KEY_0,

        // Reserved to the core for changing libs/games
        D_F1,
        D_F2,
        D_F3,
        D_F4,
        D_F5,
        D_F6,
        D_F7,
        D_F8,
        D_F9,
        D_F10,
        D_F11,
        D_F12,

        D_KEY_SIZE
    };
    /// The main graphical interface responsible of getting user input and drawing the map as indicated by the core
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            /// Initialize the display (creates window and sets settings)
            virtual void initDisplay(void) = 0;
            /// Destroy the display (closes window)
            virtual void destroyDisplay(void) = 0;
            /// Refresh and display the map
            virtual void display(void) = 0;
            /// Draws a square of a given color at a given position
            virtual void drawSquare(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            /// Draws a circle of a given color at a given position
            virtual void drawCircle(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            /// Draws a cross of a given color at a given position
            virtual void drawCross(unsigned char color, std::size_t posX, std::size_t posY) = 0;
            /// Draws a letter of a given color at a given position
            virtual void drawLetter(unsigned char letter, unsigned char color, std::size_t posX, std::size_t posY) = 0;
            /// Get the list of player key inputs to process them
            virtual std::vector<DisplayKey> getKeys(void) = 0;
    };
} // namespace arc

#endif // DISPLAY_HPP
