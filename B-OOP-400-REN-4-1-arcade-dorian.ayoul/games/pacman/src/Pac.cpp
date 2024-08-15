/*
** EPITECH PROJECT, 2022
** Pac.hpp
** File description:
** Pac
*/

#include "Pac.hpp"

void arc::Pac::createPac(void)
{
    this->_pos = std::pair<int, int>(14, 14);
}

std::pair<int, int> arc::Pac::getPosPac()
{
    return this->_pos;
}

void arc::Pac::movePac(Dir dir, std::vector<std::vector<int>> map)
{
    if (dir == Dir::North && this->_headdir != Dir::South && map[this->_pos.first][this->_pos.second + 1] == 0)
        this->_pos.second = this->_pos.second + 1;
    if (dir == Dir::South && this->_headdir != Dir::North && map[this->_pos.first][this->_pos.second - 1] == 0)
        this->_pos.second = this->_pos.second - 1;
    if (dir == Dir::Est && this->_headdir != Dir::West && map[this->_pos.first + 1][this->_pos.second] == 0)
        this->_pos.first = this->_pos.first + 1;
    if (dir == Dir::West && this->_headdir != Dir::Est && map[this->_pos.first - 1][this->_pos.second] == 0)
        this->_pos.first = this->_pos.first - 1;
    _headdir = dir;
}

bool arc::Pac::checkDeath(std::vector<std::vector<int>> map)
{
    if (map[_pos.first][_pos.second] == 4)
        return true;
    return false;
}

Dir arc::Pac::getLastDir()
{
    return this->_headdir;
}