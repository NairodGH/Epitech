/*
** EPITECH PROJECT, 2022
** Utils.cpp
** File description:
** Utils
*/

#include "Utils.hpp"

bool arc::Utils::checkIfValid(std::vector<std::pair<int, int>> vector, std::pair<int, int> value,
    std::vector<int> obs, std::vector<std::vector<int>> map)
{
    if (std::count(obs.begin(), obs.end(), map[value.first][value.second]))
        return false;
    for (std::vector<std::pair<int, int>>::iterator it = vector.begin() ; it != vector.end(); ++it) {
        if(it->first == value.first && it->second == value.second)
            return false;
    }
    return true;
}

std::vector<std::pair<int, int>> arc::Utils::generateRand(std::vector<std::vector<int>> map, size_t number,
    std::vector<int> obs)
{
    std::vector<std::pair<int, int>> stock;
    std::pair<int, int> tmp;
    std::srand(std::time(nullptr));
    size_t nb_empty = 0;
    size_t x = 0;
    size_t max_s = 0;
    
    for (x = 0; x != map.size(); x++) {
        for (size_t y = 0; y != map[x].size(); y++) {
            if (map[x][y] == 0)
                nb_empty++;
            max_s = y;
        }
    }
    if (nb_empty < number)
        return {};
    while (stock.size() != number) {
        tmp.first = std::rand() % x;
        tmp.second = std::rand() % max_s;
        if (checkIfValid(stock, tmp, obs, map))
            stock.push_back(tmp);
    }
    return (stock);
}

int arc::Utils::changeCase(arc::GameColor color, arc::Shape shape)
{
    return ((color << 16) | (shape << 8));
}

std::vector<std::vector<int>> arc::Utils::convertMap(std::vector<std::vector<int>> map)
{
    for (size_t x = 0; x != map.size(); x++) {
        for (size_t y = 0; y != map[x].size(); y++) {
            if (map[x][y] == 0)
                map[x][y] = changeCase(arc::GameColor::G_WHITE, arc::Shape::SQUARE);
            else if (map[x][y] == 1)
                map[x][y] = changeCase(arc::GameColor::G_BROWN, arc::Shape::SQUARE);
            else if (map[x][y] == 2)
                map[x][y] = changeCase(arc::GameColor::G_BLUE, arc::Shape::CIRCLE);
            else if (map[x][y] == 3)
                map[x][y] = changeCase(arc::GameColor::G_GREEN, arc::Shape::CIRCLE);
            else if (map[x][y] == 4)
                map[x][y] = changeCase(arc::GameColor::G_LIME, arc::Shape::CIRCLE);
        }
    }
    return map;
}