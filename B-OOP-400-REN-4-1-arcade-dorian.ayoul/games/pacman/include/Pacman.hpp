/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "IGame.hpp"
#include "Utils.hpp"
#include "Ghost.hpp"
#include "Pac.hpp"

namespace arc
{
    class Pacman : public virtual arc::IGame
    {
        public:
            virtual ~Pacman() = default;
            virtual void initGame(void);
            virtual void destroyGame(void);
            virtual void update(std::vector<arc::GameKey>);
            virtual void setGameState(arc::State state);
            virtual arc::State getGameState(void);
            virtual std::vector<std::vector<int>> getMap(void);
            virtual std::size_t getScore(void);
            virtual std::string getPlayerName(void);
            virtual std::string getGameName(void);
            virtual void setPlayerName(std::string);
        private:
            void fillMap(std::ifstream &file);
            void putGhostInMap(void);
            void putGommeInMap(void);
            Pac _pac;
            Ghost _ghost[4];
            std::vector<std::vector<int>> _map;
            std::size_t _score;
            arc::State _state;
            std::vector<std::pair<int, int>> _gommePos;
            Utils _utils;
            std::string _gameName;
            std::string _playerName;
    };
}

#endif