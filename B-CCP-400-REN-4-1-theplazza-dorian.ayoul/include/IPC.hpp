/*
** EPITECH PROJECT, 2022
** IPC.hpp
** File description:
** Reception
*/

#pragma once

#include "includes.hpp"
#include "Error.hpp"
#include "Pizza.hpp"

namespace plz
{
    class IPC
    {
        public:
            ~IPC();
            mqd_t getSend();
            mqd_t getReceive();
            bool create(size_t id, bool unlink);
            void receptionToKitchen(size_t id, Pizza pizza);
            bool cookFromReception(mqd_t send, Pizza &pizza, size_t id, size_t kitchenId);
            bool cookToReception(mqd_t receive, Pizza pizza, size_t id, size_t kitchenId);
        private:
            std::string printPizza(Pizza pizza);
            std::vector<mqd_t> _sends;
            std::vector<mqd_t> _receives;
    };
}