/*
** EPITECH PROJECT, 2022
** Reception.cpp
** File description:
** Reception
*/

#include "Reception.hpp"

using namespace plz;

Reception::Reception(Parser parser) : _parser(parser)
{
    std::cout << "\033[1;33m[INFO]\033[0m 🍕 The Plazza is ready to take your orders !" << std::endl;
    std::cout << "\033[1;33m[INFO]\033[0m Ordering syntax: TYPE SIZE NUMBER [; TYPE SIZE NUMBER]*" << std::endl;
    std::cout << "\033[1;33m[INFO]\033[0m TYPE = Regina | Margarita | Americana | Fantasia" << std::endl;
    std::cout << "\033[1;33m[INFO]\033[0m SIZE = S | M | L | XL | XXL" << std::endl;
    std::cout << "\033[1;33m[INFO]\033[0m NUMBER = x[1..9][0..9]*" << std::endl;
    for (std::string input; std::getline(std::cin, input);) {
        if (input == "status") {
            if (!_kitchens.size())
                std::cout << "\033[1;32m[RECEPTION]\033[0m Couldn't display the kitchens status as there aren't any" << std::endl;
            for (size_t i = 0; i < _kitchens.size(); i++)
                _kitchens[i].status();
            continue;
        }
        if (!(_pizzas = _parser.parseOrder(input)).empty()) {
            sendCommand();
            _pizzas.clear();
        }
    }
}

bool Reception::createKitchen(size_t id)
{
    pid_t pid;

    if (!_messageQueue.create(id, true))
        return false;
    _kitchens.push_back(Kitchen(_parser.getArgs(), id));
    if ((pid = fork()) == -1) {
        std::cerr << "\033[1;31m[ERROR]\033[0m Coudln't fork a new process for kitchen " + std::to_string(id) << std::endl;
        return false;
    }
    if (pid == 0) {
        _kitchens.back().start();
        exit(0);
    }
    return true;
}

void Reception::sendCommand()
{
    int bestKitchenId = -1;

    for (size_t i = 0; i < _pizzas.size(); i++, bestKitchenId = -1) {
        for (size_t j = 0, nbPizzas = std::get<1>(_parser.getArgs()) * 2; j < _kitchens.size(); j++)
            if (_kitchens[j].getNbPizzas() < nbPizzas) {
                bestKitchenId = j;
                nbPizzas = _kitchens[j].getNbPizzas();
            }
        if (bestKitchenId == -1 && !createKitchen(bestKitchenId = _kitchens.size()))
            break;
        _messageQueue.receptionToKitchen(bestKitchenId, _pizzas[i]);
        _kitchens[bestKitchenId].incrementNbPizzas();
    }
}