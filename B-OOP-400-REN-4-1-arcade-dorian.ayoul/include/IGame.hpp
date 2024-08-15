/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

/// All classes of the project are in the arc (arcade) namespace
namespace arc
{
    /// Shape of a form on the map to be displayed that can be associated to wall, enemy, player... (square by default)
    enum Shape {
        SQUARE = 1,
        CROSS,
        CIRCLE,
    };
    /// The color of a map tile to display (red by default)
    enum GameColor {
        G_RED = 1,
        G_BLUE,
        G_GREEN,
        G_WHITE,
        G_ORANGE,
        G_CYAN,
        G_PURPLE,
        G_YELLOW,
        G_LIME,
        G_BROWN,
        G_PINK,
        G_GRAY,

        G_COLOR_SIZE
    };
    /// The key inputed to be processed (can have an impact on the game)
    enum GameKey {
        G_ENTER,
        G_BACKSPACE,
        G_SPACE,
        G_ESCAPE,
        G_UP_ARROW,
        G_DOWN_ARROW,
        G_LEFT_ARROW,
        G_RIGHT_ARROW,
        G_KEY_A,
        G_KEY_B,
        G_KEY_C,
        G_KEY_D,
        G_KEY_E,
        G_KEY_F,
        G_KEY_G,
        G_KEY_H,
        G_KEY_I,
        G_KEY_J,
        G_KEY_K,
        G_KEY_L,
        G_KEY_M,
        G_KEY_N,
        G_KEY_O,
        G_KEY_P,
        G_KEY_Q,
        G_KEY_R,
        G_KEY_S,
        G_KEY_T,
        G_KEY_U,
        G_KEY_V,
        G_KEY_W,
        G_KEY_X,
        G_KEY_Y,
        G_KEY_Z,
        G_KEY_1,
        G_KEY_2,
        G_KEY_3,
        G_KEY_4,
        G_KEY_5,
        G_KEY_6,
        G_KEY_7,
        G_KEY_8,
        G_KEY_9,
        G_KEY_0,

        G_KEY_SIZE
    };
    /// The current state of the game
    enum State {
        STOP = 0,
        START = 1,
        PAUSE = 2
    };
    /// The main graphical interface responsible of processing received user input and changing the map to be handled by the core
    class IGame
    {
        public:
            virtual ~IGame() = default;
            /// Initializes the game (load and fill the map from .txt, set starting values)
            virtual void initGame(void) = 0;
            /// Destroy the game (delete the map)
            virtual void destroyGame(void) = 0;
            /// Updates the game (changes the map depending on the inputs received)
            virtual void update(std::vector<GameKey> keys) = 0;
            /// Sets the state of the game to running, stopped (menu) or paused
            virtual void setGameState(State state) = 0;
            /// Gets the stats of the game
            virtual State getGameState(void) = 0;
            /// Gets the map of the game to manipulate it
            virtual std::vector<std::vector<int>> getMap(void) = 0;
            /// Gets the player score
            virtual std::size_t getScore(void) = 0;
            /// Gets the player name
            virtual std::string getPlayerName(void) = 0;
            /// Sets the game name
            virtual void setPlayerName(std::string) = 0;
            /// Gets the game name
            virtual std::string getGameName(void) = 0;
    };
} // namespace arc

#endif // GAME_HPP
