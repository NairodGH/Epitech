/*
** EPITECH PROJECT, 2022
** Circuit.hpp
** File description:
** Circuit
*/

#pragma once

#include "Component.hpp"

class Circuit {
    public:
        Circuit();
        virtual ~Circuit() = default;
        void display();
        void createDisplay(std::map<std::string, std::shared_ptr<IComponent>> components);
        void input(std::string input, Tristate value, std::map<std::string, std::shared_ptr<IComponent>> &components);
        void loop(std::map<std::string, std::shared_ptr<IComponent>> &components);
        void dump(std::map<std::string, std::shared_ptr<IComponent>> components);
        void simulate(std::map<std::string, std::shared_ptr<IComponent>> &components);
        static void signalHandler(int signum);
        std::string getDisplay();
    private:
        size_t _tick;
        std::string _save_display;
};