/*
** EPITECH PROJECT, 2022
** Menu.hpp
** File description:
** Menu
*/

#pragma once

#include "IGame.hpp"
#include "Utils.hpp"

namespace arc
{
    class Menu : public virtual arc::IGame
    {
        public:
            virtual ~Menu() = default;
            virtual void initGame(void);
            virtual void destroyGame(void);
            virtual void update(std::vector<arc::GameKey> keys);
            virtual void setGameState(arc::State state);
            virtual arc::State getGameState(void);
            virtual std::vector<std::vector<int>> getMap(void);
            virtual std::size_t getScore(void);
            virtual std::string getPlayerName(void);
            virtual void setPlayerName(std::string);
            virtual std::string getGameName(void);
        private:
            std::vector<std::string> _graphPathes;
            std::vector<std::string> _gamePathes;
            arc::State _state;
            std::size_t _score;
            std::string _gameName;
            std::string _playerName;
            std::vector<std::vector<int>> _map;
            size_t _pos;
    };
}