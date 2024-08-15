/*
** EPITECH PROJECT, 2022
** Mutex.hpp
** File description:
** Mutex
*/

#pragma once

#include "includes.hpp"

namespace plz
{
    class Mutex
    {
        public:
            Mutex();
            ~Mutex();
            void lock();
            void unlock();
        private:
            pthread_mutex_t _mutex;
    };
}