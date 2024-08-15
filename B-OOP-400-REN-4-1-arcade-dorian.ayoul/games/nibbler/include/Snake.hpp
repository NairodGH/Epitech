/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "includes.hpp"

enum class Dir {
    North,
    South,
    Est,
    West,
};

namespace arc
{
    class Snake
    {
        public:
            Snake() = default;
            ~Snake() = default;
            void createSnake(void);
            std::vector<std::pair<int, int>> getPosSnake();
            void moveSnake(Dir dir);
            void growsSnake(void);
            bool checkDeath(std::vector<std::vector<int>> map);
            Dir getLastDir();
        private:
            std::vector<std::pair<int, int>> _pos;
            std::pair<int, int> _lastTail;
            Dir _headdir;
    };
}

#endif