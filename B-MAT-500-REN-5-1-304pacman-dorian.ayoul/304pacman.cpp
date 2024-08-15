/*
** EPITECH PROJECT, 2022
** 304pacman.cpp
** File description:
** 304pacman.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

typedef struct {
    int x;
    int y;
    size_t dist;
} pos_t;

bool check_pos(std::vector<std::vector<char>> &map, std::vector<pos_t> &previous_pos, pos_t pos)
{
    if (pos.y < 0 || pos.x >= map[pos.y].size() || pos.y >= map.size() || pos.x < 0)
        return false;
    if (map[pos.y][pos.x] == 'P')
        return true;
    if (map[pos.y][pos.x] != ' ')
        return false;
    map[pos.y][pos.x] = '0' + (pos.dist + 1) % 10;
    previous_pos.push_back(pos_t{pos.x, pos.y, pos.dist + 1});
    return false;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return 84;

    if (av[2][1] != '\0' || av[3][1] != '\0' || av[2][0] == av[3][0])
        return 84;
    std::ifstream file(av[1]);
    std::vector<std::vector<char>> map;
    pos_t f, p = f = {-1, -1, 0};
    std::string line;
    if (file.is_open()) {
        for (size_t i = 0, tmp; std::getline(file, line); i++) {
            if (!i)
                tmp = line.size();
            else if (line.size() != tmp && !line.empty())
                return 84;
            map.push_back(std::vector<char>());
            for (size_t j = 0; j < line.size(); j++) {
                switch (line[j]) {
                    case '0':
                        map[i].push_back(av[3][0]);
                        break;
                    case '1':
                        map[i].push_back(av[2][0]);
                        break;
                    case 'F':
                        if (f.x != -1)
                            return 84;
                        map[f.y = i].push_back(line[f.x = j]);
                        break;
                    case 'P':
                        if (p.x != -1)
                            return 84;
                        map[p.y = i].push_back(line[p.x = j]);
                        break;
                    default:
                        return 84;
                }
            }
        }
        if (f.x == -1 || p.x == -1)
            return 84;
        for (std::vector<pos_t> previous_pos = {f}, tmp_pos; !previous_pos.empty(); previous_pos = tmp_pos, tmp_pos.clear())
            for (auto const &pos: previous_pos)
                if (check_pos(map, tmp_pos, pos_t{pos.x, pos.y - 1, pos.dist}) ||
                check_pos(map, tmp_pos, pos_t{pos.x + 1, pos.y, pos.dist}) ||
                check_pos(map, tmp_pos, pos_t{pos.x, pos.y + 1, pos.dist}) ||
                check_pos(map, tmp_pos, pos_t{pos.x - 1, pos.y, pos.dist})) {
                    tmp_pos.clear();
                    break;
                }
        for (auto const &vector: map) {
            if (!vector.empty()) {
                for (auto const &value: vector)
                    std::cout << value;
                std::cout << std::endl;
            }
        }
    }
    else
        return 84;
    return 0;
}