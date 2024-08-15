/*
** EPITECH PROJECT, 2022
** Condition.hpp
** File description:
** Condition
*/

#pragma once

#include "includes.hpp"

namespace plz
{
    class Condition
    {
        public:
            Condition();
            ~Condition();
            void signal();
            void wait();
        private:
            pthread_cond_t _cond;
    };
}