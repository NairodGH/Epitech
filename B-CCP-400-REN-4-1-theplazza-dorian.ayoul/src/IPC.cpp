/*
** EPITECH PROJECT, 2022
** IPC.cpp
** File description:
** Reception
*/

#include "IPC.hpp"

using namespace plz;

IPC::~IPC()
{
    for (mqd_t mqd : _receives)
        mq_close(mqd);
    for (mqd_t mqd : _sends)
        mq_close(mqd);
}

mqd_t IPC::getSend()
{
    return _sends.back();
}

mqd_t IPC::getReceive()
{
    return _receives.back();
}

bool IPC::create(size_t kitchenId, bool unlink)
{
    std::string name = "/send_" + std::to_string(kitchenId);
    mqd_t mqd;
    struct mq_attr attr;

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = BUFSIZ;
    if (unlink)
        mq_unlink(name.c_str());
    if ((mqd = mq_open(name.c_str(), O_CREAT | O_RDWR, 0777, &attr)) == -1) {
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Coudln't open a new message queue for " << name << std::endl;
        return false;
    }
    _sends.push_back(mqd);
    name = "/receive_" + std::to_string(kitchenId);
    if (unlink) {
        mq_unlink(name.c_str());
        attr.mq_flags = O_NONBLOCK;
    }
    if ((mqd = mq_open(name.c_str(), O_CREAT | O_RDWR, 0777, &attr)) == -1) {
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Coudln't open a new message queue for " << name << std::endl;
        return false;
    }
    _receives.push_back(mqd);
    return true;
}

void IPC::receptionToKitchen(size_t kitchenId, Pizza pizza)
{
    std::string tmp = std::to_string(pizza.getType()) + ":" + std::to_string(pizza.getSize()) + ":" + std::to_string(pizza.getId());

    if (mq_send(_sends[kitchenId], tmp.c_str(), tmp.size(), 0) == -1)
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Couldn't send order of pizza " << printPizza(pizza) <<
        " to kitchen " << std::to_string(kitchenId) << std::endl;
    std::cout << "\033[1;32m[RECEPTION]\033[0m Order of pizza " << printPizza(pizza)
    << " successfully sent to kitchen " << kitchenId << std::endl;
}

bool IPC::cookFromReception(mqd_t send, Pizza &pizza, size_t id, size_t kitchenId)
{
    char str[BUFSIZ];
    std::string tmp;

    if (mq_receive(send - 2, str, BUFSIZ, 0) == -1) {
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Cook " << std::to_string(id) << " from kitchen " <<
        std::to_string(kitchenId) << " coudln't receive the order from reception" << std::endl;
        return false;
    }
    tmp = std::string(str);
    pizza = Pizza(
        (PizzaType)std::stoul(tmp.substr(0, tmp.find_first_of(':'))),
        (PizzaSize)std::stoul(tmp.substr(tmp.find_first_of(':') + 1, tmp.find_last_of(':'))),
        std::stoul(tmp.substr(tmp.find_last_of(':') + 1))
    );
    std::cout << "\033[1;36m[COOKS]\033[0m Order of pizza " << printPizza(pizza) <<
    " successfully received from reception by cook " << id << " from kitchen " << kitchenId << std::endl;
    return true;
}

bool IPC::cookToReception(mqd_t receive, Pizza pizza, size_t id, size_t kitchenId)
{
    std::string tmp = std::to_string(pizza.getType()) + ":" + std::to_string(pizza.getSize()) + ":" + std::to_string(pizza.getId());

    if (mq_send(receive - 2, tmp.c_str(), tmp.size(), 0) == -1) {
        std::cerr <<  "\033[1;31m[ERROR]\033[0m Cook " << std::to_string(id) << " from kitchen " <<
        std::to_string(kitchenId) << " coudln't send pizza " << printPizza(pizza) << " to reception" << std::endl;
        return false;
    }
    std::cout << "\033[1;32m[RECEPTION]\033[0m Pizza " << printPizza(pizza) <<
    " successfully got received from cook " << id << " from kitchen " << kitchenId << ", waiters !" << std::endl;
    return true;
}

std::string IPC::printPizza(Pizza pizza)
{
    std::string tmp = std::to_string(pizza.getId()) + " (";

    for (size_t i = 0; i < NB_PIZZAS; i++)
        if (1 << i == pizza.getType())
            tmp += types[i] + " ";
    for (size_t i = 0; i < NB_SIZES; i++)
        if (1 << i == pizza.getSize())
            tmp += sizes[i] + ")";
    return tmp;
}