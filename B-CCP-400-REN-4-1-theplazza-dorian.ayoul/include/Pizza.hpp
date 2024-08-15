/*
** EPITECH PROJECT, 2022
** Pizza.hpp
** File description:
** Pizza
*/

#pragma once

#include "includes.hpp"

namespace plz
{
    enum PizzaType
    {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };
    enum PizzaSize
    {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
    class Pizza
    {
        public:
            Pizza(PizzaType type = (PizzaType)0, PizzaSize size = (PizzaSize)0, size_t id = 0);
            PizzaType getType();
            void setType(PizzaType type);
            PizzaSize getSize();
            void setSize(PizzaSize size);
            size_t getNbOrdered();
            void setNbOrdered(size_t nbOrdered);
            size_t getId();
            void setId(size_t id);
        private:
            PizzaType _type;
            PizzaSize _size;
            size_t _nbOrdered;
            size_t _id;
    };
}