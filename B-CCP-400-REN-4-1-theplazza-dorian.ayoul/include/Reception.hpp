/*
** EPITECH PROJECT, 2022
** Reception.hpp
** File description:
** Reception
*/

#pragma once

#include "includes.hpp"
#include "Kitchen.hpp"
#include "Parser.hpp"
#include "IPC.hpp"

namespace plz
{
    class Reception
    {
        public:
            Reception(Parser parser);
        private:
            void sendCommand();
            bool createKitchen(size_t id);
            std::vector<Kitchen> _kitchens;
            std::vector<Pizza> _pizzas;
            IPC _messageQueue;
            Parser _parser;
    };
}