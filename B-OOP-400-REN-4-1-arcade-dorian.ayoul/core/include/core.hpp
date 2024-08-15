/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** Core
*/

#pragma once

#include "includes.hpp"
#include "IDisplay.hpp"
#include "IGame.hpp"
#include "Error.hpp"

/// All classes of the project are in the arc (arcade) namespace
namespace arc
{
    /// Core class responsible of loading libs, transmitting player inputs to the games and transmitting the map to the graphicals
    class Core
    {
        public:
            /// Core constructor that requires the path of the starting graphical library
            Core(const std::string &path);
            virtual ~Core() = default;
            /// Store the pathes of the game/graphic libs in ./lib/libs.config
            void getLibs();
            /// Main loop of the game
            void mainLoop();
            /// Loads the given lib with dlopen/dlsym
            void loadLib(const std::string &libPath, bool is_graph);
            /// Unloads the current used lib with dlclose
            void unloadLib(bool is_graph);
            /// Gets the username at the start of the arcade
            bool getUsername();
            /// Parses the map and asks the graphic lib to draw for each tile
            void readMap();
            /// Destroys the game and graphic libs (when pressing escape)
            void destroy();
            /// Change the lib if menu
            void changeLib();
            /// Change the lib if function key pressed
            void checkFunctionKey(std::vector<DisplayKey> dKeys);
            bool updateKeys(std::vector<DisplayKey> &dKeys, std::vector<GameKey> &gKeys);
            void displayScore();
            void waitClock(std::vector<DisplayKey> &dKeys);
        private:
            /// List of the graphical libs pathes
            std::vector<std::string> _graphPathes;
            /// List of the games libs pathes
            std::vector<std::string> _gamePathes;
            void *_graphHandle;
            void *_gameHandle;
            IDisplay *_graph;
            IGame *_game;
            std::string _username;
            std::chrono::steady_clock::time_point _timer;
            size_t _score;
            std::string _currentGame;
            size_t _selectedGame;
		    size_t _selectedGraph;
    };
} // namespace arc
