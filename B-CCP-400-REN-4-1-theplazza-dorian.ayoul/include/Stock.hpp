/*
** EPITECH PROJECT, 2022
** Stock.hpp
** File description:
** Stock
*/

#pragma once

#include "includes.hpp"
#include "Pizza.hpp"
#include "Condition.hpp"

namespace plz
{
    class Stock
    {
        enum ingredient {
            Steak,
            Doe,
            Tomato,
            Gruyere,
            Ham,
            Mushrooms,
            Eggplant,
            GoatCheese,
            ChiefLove
        };
        public:
            Stock(size_t timer, Condition *_cond);
            bool getIngredients(Pizza pizza);
            void checkRefill();
            bool checkStockFull();
            void print();
        private:
            size_t _timer;
            time_t _time;
            std::array<int, 9> _ingredients; //steak, doe, tomato, gruyere, ham, mushrooms, eggplant, goatCheese, chiefLove
            Condition *_cond;
    };
}