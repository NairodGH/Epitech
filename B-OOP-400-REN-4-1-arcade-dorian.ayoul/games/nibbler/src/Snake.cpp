/*
** EPITECH PROJECT, 2022
** Snake.hpp
** File description:
** Snake
*/

#include "Snake.hpp"

void arc::Snake::createSnake()
{
    this->_pos.clear();
    this->_pos.push_back(std::pair<int, int>(8, 9));
    this->_pos.push_back(std::pair<int, int>(9, 9));
    this->_pos.push_back(std::pair<int, int>(10, 9));
    this->_pos.push_back(std::pair<int, int>(11, 9));
    this->_headdir = Dir::West;
    this->_lastTail.first = _pos[_pos.size() - 1].first;
    this->_lastTail.second = _pos[_pos.size() - 1].second;
}

std::vector<std::pair<int, int>> arc::Snake::getPosSnake()
{
    return this->_pos;
}

void arc::Snake::moveSnake(Dir dir)
{
    this->_lastTail.first = _pos[_pos.size() - 1].first;
    this->_lastTail.second = _pos[_pos.size() - 1].second;
    for (size_t i = (_pos.size() - 1); i != 0; i--) {
        _pos[i].first = _pos[i - 1].first;
        _pos[i].second = _pos[i - 1].second;
    }
    if (dir == Dir::North && _headdir != Dir::South)
        _pos[0].second = _pos[0].second + 1;
    if (dir == Dir::South && _headdir != Dir::North)
        _pos[0].second = _pos[0].second - 1;
    if (dir == Dir::Est && _headdir != Dir::West)
        _pos[0].first = _pos[0].first + 1;
    if (dir == Dir::West && _headdir != Dir::Est)
        _pos[0].first = _pos[0].first - 1;
    _headdir = dir;
}

void arc::Snake::growsSnake(void)
{
    _pos.push_back(std::pair<int, int>(_lastTail.first, _lastTail.second));
}

bool arc::Snake::checkDeath(std::vector<std::vector<int>> map)
{
    if (map[_pos.begin()->first][_pos.begin()->second] == 1)
        return true;
    return false;
}

Dir arc::Snake::getLastDir()
{
    return this->_headdir;
}