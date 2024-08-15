/*
** EPITECH PROJECT, 2022
** Utils.hpp
** File description:
** Utils
*/

#ifndef UTILS_HPP
#define UTILS_HPP

#include "IGame.hpp"

/// All classes of the project are in the arc (arcade) namespace
namespace arc
{
    /// A generalist utilities class that is used in different parts of the project
    class Utils
    {
        public:
            Utils() = default;
            ~Utils() = default;
            /// Generates a random position
            std::vector<std::pair<int, int>> generateRand(std::vector<std::vector<int>> map, size_t number,
                std::vector<int> obs);
            /// Converts the map into bitshifted characters containing the form + color
            std::vector<std::vector<int>> convertMap(std::vector<std::vector<int>> map);
        private:
            /// Checks if the position is valid
            bool checkIfValid(std::vector<std::pair<int, int>> vector, std::pair<int, int> value,
                std::vector<int> obs, std::vector<std::vector<int>> map);
            int changeCase(arc::GameColor color, arc::Shape shape);
    };
};

#endif