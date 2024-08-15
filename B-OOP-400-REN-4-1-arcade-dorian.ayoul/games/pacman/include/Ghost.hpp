/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef GHOST_HPP
#define GHOST_HPP

#include "includes.hpp"
#include "dir.hpp"

namespace arc
{
    class Ghost
    {
        public:
            Ghost() = default;
            ~Ghost() = default;
            void createGhost(std::pair<int, int> pos);
            std::pair<int, int> getPosGhost();
            void moveGhost(std::vector<std::vector<int>> map);
            bool checkDeath(std::vector<std::vector<int>> map);
            Dir getLastDir();
        private:
            std::pair<int, int> _pos;
            Dir _headdir;
    };
}

#endif