/*
** EPITECH PROJECT, 2022
** 305construction.cpp
** File description:
** 305construction.cpp
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

typedef struct {
    int duration;
    std::vector<std::string> prerequisites;
    std::vector<std::vector<std::string>> fullPrerequisites;
    int begin;
    int end;
} infos;

void getFullPrerequisites(std::map<std::string, infos> &list, std::string task, std::string tmp)
{
    if (!list.count(tmp))
        exit(84);
    for (auto const &prerequisite: list[tmp].prerequisites) {
        if (prerequisite == task)
            exit(84);
        list[task].fullPrerequisites.back().push_back(prerequisite);
        getFullPrerequisites(list, task, prerequisite);
    }
    list[task].fullPrerequisites.push_back(std::vector<std::string>());
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;

    std::ifstream file(av[1]);
    std::map<std::string, infos> list;
    if (file.is_open()) {
        for (std::string line, current, tmp; std::getline(file, line);) {
            if (std::count(line.begin(), line.end(), ';') < 2 || list.count(current = line.substr(0, line.find(';'))))
                return 84;
            infos infos = {0, std::vector<std::string>(), std::vector<std::vector<std::string>>(), 0, 0};
            for (int offset = line.find(';') + 1, i = 0; line[offset - 1] == ';'; offset += tmp.size() + 1, i++) {
                if ((tmp = line.substr(offset, line.find(';', offset) - offset)).empty())
                    return 84;
                if (i == 1) {
                    for (auto const &value: tmp)
                        if (!(value >= '0' && value <= '9'))
                            return 84;
                    infos.duration = std::stoull(tmp);
                }
                else if (i)
                    infos.prerequisites.push_back(tmp);
            }
            infos.fullPrerequisites.push_back(std::vector<std::string>());
            list[current] = infos;
        }
        for (auto &pair: list) {
            getFullPrerequisites(list, pair.first, pair.first);
            pair.second.fullPrerequisites.erase(std::remove_if(pair.second.fullPrerequisites.begin(), pair.second.fullPrerequisites.end(), [](const std::vector<std::string> &x){return x.empty();}), pair.second.fullPrerequisites.end());
        }
        for (auto &pair: list) {
            int durationSum = 0, begin = 0;
            for (int i = 0; i < pair.second.fullPrerequisites.size(); i++, durationSum = 0) {
                for (auto const &prerequisite: pair.second.fullPrerequisites[i])
                    durationSum += list[prerequisite].duration;
                if (durationSum > begin)
                    begin = durationSum;
            }
            pair.second.begin = begin;
        }
        int totalDuration = 0;
        for (auto const &pair: list)
            if (pair.second.begin + pair.second.duration > totalDuration)
                totalDuration = pair.second.begin + pair.second.duration;
        for (auto &pair: list) {
            int deadline = totalDuration;
            for (auto const &pair2: list)
                if (deadline > pair2.second.begin &&
                    std::find(pair2.second.prerequisites.begin(), pair2.second.prerequisites.end(), pair.first) != pair2.second.prerequisites.end())
                    deadline = pair2.second.begin;
            if ((pair.second.end = deadline - (pair.second.begin + pair.second.duration)) < 0)
                pair.second.end = 0;
        }
        std::vector<std::pair<std::string, infos>> sorted;
        for (auto const &pair: list)
            sorted.push_back(pair);
        std::sort(sorted.begin(), sorted.end(), [](const std::pair<std::string, infos> &a, const std::pair<std::string, infos> &b) {return a.second.begin != b.second.begin ? a.second.begin < b.second.begin : a.second.duration != b.second.duration ? a.second.duration < b.second.duration : a.first < b.first;});
        std::cout << "Total duration of construction: " << totalDuration << " weeks\n\n";
        for (auto const &pair: sorted)
            std::cout << pair.first << " must begin " << (pair.second.end ? "between t=" + std::to_string(pair.second.begin) + " and t=" + std::to_string(pair.second.begin + pair.second.end) : "at t=" + std::to_string(pair.second.begin)) << std::endl;
        std::cout << std::endl;
        for (auto const &pair: sorted)
            std::cout << pair.first << "\t(" << pair.second.end << ")\t" << std::string(pair.second.begin, ' ') << std::string(pair.second.duration, '=') << std::endl;
    }
    else
        return 84;
    return 0;
}