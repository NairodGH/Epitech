/*
** EPITECH PROJECT, 2022
** includes.hpp
** File description:
** includes
*/

#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <tuple>
#include <chrono>

#include <mqueue.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define NB_PIZZAS 4
#define NB_SIZES 5
#define NB_INGREDIENTS 9

const std::array<std::string, NB_PIZZAS> types = {
    "Regina", "Margarita", "Americana", "Fantasia"
};

const std::array<std::string, NB_SIZES> sizes = {
    "S", "M", "L", "XL", "XXL"
};

const std::array<std::string, NB_INGREDIENTS> ingredients = {
    "Steak", "Doe", "Tomato", "Gruyere", "Ham", "Mushrooms", "Eggplant", "GoatCheese", "ChiefLove"
};