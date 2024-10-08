/*
** EPITECH PROJECT, 2022
** Mutex.hpp
** File description:
** Mutex
*/

#include "Mutex.hpp"

using namespace plz;

Mutex::Mutex()
{
    pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}