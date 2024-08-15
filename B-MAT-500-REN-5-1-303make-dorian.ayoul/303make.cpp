/*
** EPITECH PROJECT, 2022
** 303make.cpp
** File description:
** 303make.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

typedef struct {
    std::vector<bool> adjacency;
    std::vector<std::string> commands;
} infos;

int prev = -1;

void commands(std::map<std::string, infos> list, std::string key, size_t level) {
    if (!level && !list[key].commands.empty() &&
        prev != std::distance(std::begin(list), list.find(key))) {
        prev = std::distance(std::begin(list), list.find(key));
        for (auto const &cmd : list[key].commands)
            std::cout << cmd << std::endl;
    }
    for (size_t i = 0; i < list[key].adjacency.size(); i++) {
        if (list[key].adjacency[i]) {
            auto it = list.begin();
            std::advance(it, i);
            commands(list, it->first, --level);
        }
    }
}

void dependencies(std::map<std::string, infos> list, std::string key) {
    std::cout << " -> " << key;
    for (size_t i = 0; i < list[key].adjacency.size(); i++) {
        if (list[key].adjacency[i]) {
            auto it = list.begin();
            std::advance(it, i);
            dependencies(list, it->first);
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return 84;

    std::ifstream file(av[1]);
    std::map<std::string, infos> list;
    if (file.is_open()) {
        for (std::string line, current, tmp; std::getline(file, line);) {
            if (line.find(": ") != std::string::npos) {
                list[current = line.substr(0, line.find(": "))] = {std::vector<bool>(), std::vector<std::string>()};
                for (size_t offset = line.find(": ") + 2; line[offset - 1] == ' '; offset += tmp.size() + 1) {
                    if ((tmp = line.substr(offset, line.find(" ", offset) - offset)).empty())
                        continue;
                    list[tmp] = {std::vector<bool>(), std::vector<std::string>()};
                }
                continue;
            }
            if (!current.empty() && !line.empty())
                list[current].commands.push_back(line);
        }
        if (list.empty())
            return 84;
        file.clear();
        file.seekg(0);
        for (std::string line, current, tmp; std::getline(file, line);) {
            if (line.find(": ") != std::string::npos) {
                if (list[current = line.substr(0, line.find(": "))].adjacency.empty())
                    list[current].adjacency = std::vector<bool>(list.size(), 0);
                for (size_t offset = line.find(": ") + 2; line[offset - 1] == ' '; offset += tmp.size() + 1) {
                    if ((tmp = line.substr(offset, line.find(" ", offset) - offset)).empty())
                        continue;
                    if (list[tmp].adjacency.empty())
                        list[tmp].adjacency = std::vector<bool>(list.size(), 0);
                    list[tmp].adjacency[std::distance(std::begin(list), list.find(current))] = 1;
                }
            }
        }
        if (ac == 2) {
            for (auto const &pair: list) {
                std::cout << "[";
                for (size_t i = 0; i < pair.second.adjacency.size(); i++)
                    std::cout << pair.second.adjacency[i] << (i == pair.second.adjacency.size() - 1 ? "" : " ");
                std::cout << "]" << std::endl;
            }
            std::cout << std::endl;
            for (auto const &pair: list) {
                for (size_t i = 0; i < pair.second.adjacency.size(); i++) {
                    if (pair.second.adjacency[i]) {
                        auto it = list.begin();
                        std::advance(it, i);
                        std::cout << pair.first;
                        dependencies(list, it->first);
                        std::cout << std::endl;
                    }
                }
            }
        }
        else {
            if (!list.count(av[2]))
                return 84;
            if (std::all_of(list[av[2]].adjacency.begin(), list[av[2]].adjacency.end(), [](bool i) { return i == 0; }))
                std::cout << std::endl;
            for (size_t level = 0; level < list.size(); level++) {
                for (size_t i = 0; i < list[av[2]].adjacency.size(); i++) {
                    if (list[av[2]].adjacency[i]) {
                        auto it = list.begin();
                        std::advance(it, i);
                        commands(list, it->first, level);
                    }
                }
            }
        }
    }
    else
        return 84;
    return 0;
}