/*
** EPITECH PROJECT, 2022
** Stock.cpp
** File description:
** Stock
*/

#include "Stock.hpp"

using namespace plz;

Stock::Stock(size_t timer, Condition *cond) : _timer(timer), _time(std::time(nullptr)), _ingredients({5, 5, 5, 5, 5, 5, 5, 5, 5}), _cond(cond)
{
}

bool Stock::getIngredients(Pizza pizza)
{
    if (pizza.getType() == Margarita)
        for (size_t i = Doe; i <= Gruyere; i++) {
            if (!_ingredients[i])
                return false;
            _ingredients[i]--;
        }
    if (pizza.getType() == Regina)
        for (size_t i = Doe; i <= Mushrooms; i++) {
            if (!_ingredients[i])
                return false;
            _ingredients[i]--;
        }
    if (pizza.getType() == Americana)
        for (size_t i = Steak; i <= Gruyere; i++) {
            if (!_ingredients[i])
                return false;
            _ingredients[i]--;
        }
    if (pizza.getType() == Fantasia)
        for (size_t i = Doe; i <= ChiefLove; i++) {
            if (i != Ham && i != Mushrooms && !_ingredients[i])
                return false;
            _ingredients[i]--;
        }
    return true;
}

bool Stock::checkStockFull()
{
    for (size_t i = 0; i < _ingredients.size(); i++) {
        if (!_ingredients[i])
            return false;
        if (i == _ingredients.size() - 1)
            break;
    }
    return true;
}

void Stock::checkRefill()
{
    time_t tmp = std::time(nullptr);

    if (tmp - _time > _timer / 1000) {
        for (size_t i = 0; i < _ingredients.size(); i++)
            if (_ingredients[i] < 5)
                _ingredients[i]++;
        _time = tmp;
    }
}

void Stock::print()
{
    for (size_t i = 0; i < _ingredients.size(); i++)
        std::cout << "\033[1;35m[STOCK]\033[0m " << ingredients[i] << ": " << _ingredients[i] << std::endl;
}