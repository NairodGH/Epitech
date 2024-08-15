/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef NIBBLER_HPP
#define NIBBLER_HPP

#include "IGame.hpp"
#include "Utils.hpp"
#include "Snake.hpp"

namespace arc
{
    class Nibbler : public virtual arc::IGame
    {
        public:
            virtual ~Nibbler() = default;
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
            void putSnakeInMap();
            Snake _snake;
            std::vector<std::vector<int>> _map;
            std::size_t _score;
            arc::State _state;
            size_t _fruit;
            Utils _utils;
            std::string _gameName;
            std::string _playerName;
    };
}

#endif