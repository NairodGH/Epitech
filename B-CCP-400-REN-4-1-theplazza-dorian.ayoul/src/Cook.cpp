/*
** EPITECH PROJECT, 2022
** Cook.cpp
** File description:
** Cook
*/

#include "Cook.hpp"

using namespace plz;

Cook::Cook(double multiplier, IPC &messageQueue, std::array<size_t, 2> ids, Stock *stock, std::array<Mutex, 3> *mutexes, Condition *cond)
: _multiplier(multiplier), _messageQueue(messageQueue), _send(messageQueue.getSend()), _receive(messageQueue.getReceive()),
_id(ids[0]), _kitchenId(ids[1]), _stock(stock), _mutexes(mutexes), _cond(cond)
{
    if (pthread_create(&_thread, NULL, helper, this) == -1)
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Cook " + std::to_string(_id) + "'s thread couldn't be created" << std::endl;
}

void *Cook::helper(void *context)
{
    return ((Cook *)context)->work();
}

void *Cook::work()
{
    std::cout << "\033[1;36m[COOKS]\033[0m Cook " << _id << " got created by kitchen " << std::to_string(_kitchenId) << std::endl;
    for (Pizza toCook;;) {
        (*_mutexes)[0].lock();
        if (!_messageQueue.cookFromReception(_send, toCook, _id, _kitchenId))
            break;
        _pizzas.push_back(toCook);
        (*_mutexes)[0].unlock();
        (*_mutexes)[1].lock();
        //_cond->wait();
        while (!_stock->getIngredients(toCook))
            _stock->checkRefill();
        (*_mutexes)[1].unlock();
        sleep((toCook.getType() >= Americana ? (toCook.getType() / 2) : toCook.getType()) *  _multiplier);
        (*_mutexes)[2].lock();
        std::cout << "\033[1;36m[COOKS]\033[0m Cook " << _id << " from kitchen " << std::to_string(_kitchenId) << " finished cooking pizza " <<
        toCook.getId() << " (";
        for (size_t j = 0; j < NB_PIZZAS; j++)
            if (1 << j == toCook.getType())
                std::cout << types[j] << " ";
        for (size_t j = 0; j < NB_SIZES; j++)
            if (1 << j == toCook.getSize())
                std::cout << sizes[j] << ")" << std::endl;
        if (!_messageQueue.cookToReception(_receive, toCook, _id, _kitchenId))
            break;
        (*_mutexes)[2].unlock();
    }
    return NULL;
}