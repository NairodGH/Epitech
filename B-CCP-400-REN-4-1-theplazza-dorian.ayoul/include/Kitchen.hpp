/*
** EPITECH PROJECT, 2022
** Kitchen.hpp
** File description:
** Kitchen
*/

#pragma once

#include "includes.hpp"
#include "Stock.hpp"
#include "Cook.hpp"
#include "Error.hpp"
#include "Mutex.hpp"
#include "Condition.hpp"

namespace plz
{
    class Kitchen
    {
        public:
            Kitchen(std::tuple<double, size_t, size_t> params, size_t id);
            size_t getNbPizzas();
            void incrementNbPizzas();
            void start();
            void status();
        private:
            bool inactive();
            std::tuple<double, size_t, size_t> _params;
            std::vector<Cook> _cooks;
            Stock _stock;
            std::array<Mutex, 3> _mutexes;
            size_t _nbPizzas;
            IPC _messageQueue;
            time_t _timer;
            size_t _id;
            Condition _cond;
    };
}