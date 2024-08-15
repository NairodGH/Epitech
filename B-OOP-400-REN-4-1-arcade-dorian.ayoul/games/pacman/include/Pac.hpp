/*
** EPITECH PROJECT, 2022
** IGame.hpp
** File description:
** IGame
*/

#ifndef PAC_HPP
#define PAC_HPP

#include "includes.hpp"
#include "dir.hpp"

namespace arc
{
    class Pac
    {
        public:
            Pac() = default;
            ~Pac() = default;
            void createPac(void);
            std::pair<int, int> getPosPac();
            void movePac(Dir dir, std::vector<std::vector<int>> map);
            bool checkDeath(std::vector<std::vector<int>> map);
            Dir getLastDir();
        private:
            std::pair<int, int> _pos;
            Dir _headdir;
    };
}

#endif