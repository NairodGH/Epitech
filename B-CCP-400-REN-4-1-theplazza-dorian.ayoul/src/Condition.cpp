/*
** EPITECH PROJECT, 2022
** Condition.hpp
** File description:
** Condition
*/

#include "Condition.hpp"

using namespace plz;

Condition::Condition()
{
    pthread_cond_init(&_cond, NULL);
}

Condition::~Condition()
{
    pthread_cond_destroy(&_cond);
}

void Condition::signal()
{
    pthread_cond_signal(&_cond);
}

void Condition::wait()
{
    pthread_cond_wait(&_cond, NULL);
}