/*
** EPITECH PROJECT, 2022
** Cook.hpp
** File description:
** Cook
*/

#pragma once

#include "Pizza.hpp"
#include "Stock.hpp"
#include "Error.hpp"
#include "Mutex.hpp"
#include "IPC.hpp"
#include "Condition.hpp"

namespace plz
{
    class Cook
    {
        public:
            Cook(double multiplier, IPC &messageQueue, std::array<size_t, 2> ids, Stock *stock, std::array<Mutex, 3> *mutexes, Condition *cond);
        private:
            static void *helper(void *context);
            void *work();
            double _multiplier;
            Stock *_stock;
            std::array<Mutex, 3> *_mutexes;
            Condition *_cond;
            IPC _messageQueue;
            mqd_t _send;
            mqd_t _receive;
            size_t _id;
            size_t _kitchenId;
            std::vector<Pizza> _pizzas;
            pthread_t _thread;
    };
}