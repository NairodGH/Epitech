/*
** EPITECH PROJECT, 2022
** Parser.hpp
** File description:
** Parser
*/

#pragma once

#include "includes.hpp"
#include "Pizza.hpp"
#include "Error.hpp"

namespace plz
{
    class Parser
    {
        public:
            Parser(int ac, char **av);
            ~Parser() = default;
            std::tuple<double, size_t, size_t> getArgs();
            std::vector<Pizza> parseOrder(std::string input);
        private:
            bool checkArg(std::string arg, bool isDecimal);
            size_t parseParam(Pizza &tmp, std::string param);
            std::tuple<double, size_t, size_t> _args;
            size_t _nbPizzas;
    };
}