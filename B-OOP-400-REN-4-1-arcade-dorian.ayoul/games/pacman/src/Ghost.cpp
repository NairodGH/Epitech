/*
** EPITECH PROJECT, 2022
** Ghost.hpp
** File description:
** Ghost
*/

#include "Ghost.hpp"

void arc::Ghost::createGhost(std::pair<int, int> pos)
{
    this->_pos = pos;
}

std::pair<int, int> arc::Ghost::getPosGhost()
{
    return this->_pos;
}

void arc::Ghost::moveGhost(std::vector<std::vector<int>> map)
{
    if (map[_pos.first + 1][_pos.second] == 0 && this->_headdir != Dir::Est && rand() % 2 == 0)
        this->_headdir = Dir::Est;
    else if (map[_pos.first - 1][_pos.second] == 0 && this->_headdir != Dir::West && rand() % 2 == 0)
        this->_headdir = Dir::West;
    else if (map[_pos.first][_pos.second - 1] == 0 && this->_headdir != Dir::North && rand() % 2 == 0)
        this->_headdir = Dir::North;
    else if (map[_pos.first][_pos.second + 1] == 0 && this->_headdir != Dir::South && rand() % 2 == 0)
        this->_headdir = Dir::South;
}

bool arc::Ghost::checkDeath(std::vector<std::vector<int>> map)
{
    if (map.size() > 0)
        return false;
    return true;
}

Dir arc::Ghost::getLastDir()
{
    return this->_headdir;
}