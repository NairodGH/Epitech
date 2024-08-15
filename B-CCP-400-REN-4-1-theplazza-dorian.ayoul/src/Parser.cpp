/*
** EPITECH PROJECT, 2022
** bootstrap.hpp
** File description:
** bootstrap
*/

#include "Parser.hpp"

using namespace plz;

Parser::Parser(int ac, char **av) : _nbPizzas(0), _args({0, 0, 0})
{
    if (ac != 4)
        throw Error("Bad syntax in arguments: there should be 3 arguments");
    for (size_t i = 1; i < ac; i++)
        if (!checkArg(std::string(av[i]), i == 1))
            throw Error("Bad syntax in arguments: \"" + std::string(av[i]) + "\" isn't a valid parameter");
    _args = std::make_tuple(std::atof(av[1]), std::atoi(av[2]), std::atoi(av[3]));
    if (std::get<0>(_args) == 0)
        throw Error("Bad syntax in arguments: cooking time multiplier can't be 0 (they won't cook)");
    if (std::get<1>(_args) == 0)
        throw Error("Bad syntax in arguments: number of cooks in a kitchen can't be 0");
}

bool Parser::checkArg(std::string arg, bool isDecimal)
{
    std::stringstream ss(arg);
    double d = 0;
    size_t s = 0;

    if (isDecimal)
        ss >> std::noskipws >> d;
    else
        ss >> std::noskipws >> s;
    if (d >= 0 && s >= 0 && ss.eof() && !ss.fail())
        return true;
    return false;
}

std::tuple<double, size_t, size_t> Parser::getArgs()
{
    return _args;
}

size_t Parser::parseParam(Pizza &tmp, std::string param)
{
    if (!tmp.getType()) {
        for (size_t i = 0; i < types.size(); i++)
            if (param == types[i])
                tmp.setType((PizzaType)(1 << i));
        if (!tmp.getType())
            std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: \"" + param + "\" isn't a valid pizza type" << std::endl;
        return 0;
    }
    if (!tmp.getSize()) {
        for (size_t i = 0; i < sizes.size(); i++)
            if (param == sizes[i])
                tmp.setSize((PizzaSize)(1 << i));
        if (!tmp.getSize())
            std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: \"" + param + "\" isn't a valid pizza size" << std::endl;
        return 0;
    }
    if (!tmp.getNbOrdered()) {
        if (param[0] != 'x')
            std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: \"" + param + "\" (number of pizza(s) to cook) should start with 'x'" << std::endl;
        param.erase(0, 1);
        for (size_t i = 0; param[i]; i++)
            if (!std::isdigit(param[i])) {
                std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: \"" + param + "\" isn't a valid number of pizza(s) to cook" << std::endl;
                return 0;
            }
        if (!param.empty())
            tmp.setNbOrdered(std::stoi(param));
        if (!tmp.getNbOrdered())
            std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: number of pizza(s) to cook shouldn't be 0" << std::endl;
        return tmp.getNbOrdered();
    }
    std::cerr <<  "\033[1;31m[ERROR]\033[0m Bad syntax in order: extra parameter \"" + param + "\" isn't needed" << std::endl;
    return 0;
}

std::vector<Pizza> Parser::parseOrder(std::string input)
{
    std::string orders;
    std::string params;
    std::vector<Pizza> pizzas;
    Pizza tmp;

    for (std::stringstream ss_orders(input); std::getline(ss_orders, orders, ';');) {
        for (std::stringstream ss_params(orders); std::getline(ss_params, params, ' ');)
            if (!params.empty())
                for (size_t i = parseParam(tmp, params); i; i--, _nbPizzas++) {
                    tmp.setId(_nbPizzas);
                    pizzas.push_back(tmp);
                }
        if (!tmp.getNbOrdered())
            std::cerr << "\033[1;31m[ERROR]\033[0m Bad syntax in order: \"" + orders + "\" isn't a valid order" << std::endl;
        tmp = Pizza();
    }
    return pizzas;
}