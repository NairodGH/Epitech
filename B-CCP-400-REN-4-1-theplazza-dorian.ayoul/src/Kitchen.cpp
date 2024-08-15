/*
** EPITECH PROJECT, 2022
** Kitchen.cpp
** File description:
** Kitchen
*/

#include "Kitchen.hpp"

using namespace plz;

Kitchen::Kitchen(std::tuple<double, size_t, size_t> params, size_t id)
: _params(params), _cond(Condition()), _stock(Stock(std::get<2>(_params), &_cond)), _mutexes({Mutex()}),
_nbPizzas(0), _timer(std::time(nullptr)), _id(id)
{
}

void Kitchen::start()
{
    std::cout << "\033[1;34m[KITCHENS]\033[0m Kitchen " << _id << " created !" << std::endl;
    _messageQueue.create(_id, false);
    for (size_t i = 0; i < std::get<1>(_params); i++)
        _cooks.push_back(Cook(std::get<0>(_params), _messageQueue, {i, _id}, &_stock, &_mutexes, &_cond));
    while (1) {
        if (_stock.checkStockFull())
            _cond.signal();
        // if (inactive()) {
        //     std::cout << "\033[1;34m[KITCHEN]\033[0m Kitchen " << _id << " was inactive for too long and got destroyed" << std::endl;
        //     break;
        // }
    }
}

bool Kitchen::inactive()
{
    time_t time = std::time(nullptr);

    return (time - _timer > 5);
}

size_t Kitchen::getNbPizzas()
{
    return _nbPizzas;
}

void Kitchen::incrementNbPizzas()
{
    _nbPizzas++;
}

void Kitchen::status()
{
    std::cout << "\033[1;34m[KITCHENS]\033[0m Kitchen " << _id << " status:" << std::endl;
    std::cout << "\033[1;34m[KITCHENS]\033[0m " << _nbPizzas << " pizza(s) are being cooked by" << std::endl;
    std::cout << "\033[1;34m[KITCHENS]\033[0m " << (_nbPizzas < std::get<1>(_params) ? _nbPizzas : std::get<1>(_params)) << " cooks" << std::endl;
    _stock.print();
}