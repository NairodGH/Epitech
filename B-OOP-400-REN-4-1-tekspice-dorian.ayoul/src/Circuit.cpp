/*
** EPITECH PROJECT, 2022
** Circuit.cpp
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include "Chipset.hpp"

Circuit::Circuit()
{
    _tick = 0;
    _save_display = "";
}

std::string Circuit::getDisplay()
{
    return this->_save_display;
}

void Circuit::display()
{
    std::cout << this->_save_display;
}

void Circuit::createDisplay(std::map<std::string, std::shared_ptr<IComponent>> components)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;

    _save_display = "";
    _save_display += "tick: " + std::to_string(_tick);
    _save_display += "\ninput(s):\n";
    for (it = components.begin(); it != components.end(); it++) {
        if (it->second->getPins().size() == 1 && it->second->getPins()[0]->getType() == Pin::I)
            _save_display += "  " + it->first + ": " + (it->second->getPins()[0]->getState() == UNDEFINED ?
            "U\n" : std::to_string(it->second->getPins()[0]->getState()) + "\n");
    }
    _save_display = _save_display + "output(s):\n  ";
    for (it = components.begin(); it != components.end(); it++) {
        if (it->second->getPins().size() == 1 && it->second->getPins()[0]->getType() == Pin::O)
            _save_display += it->first + ": " + (it->second->getPins()[0]->getState() == UNDEFINED ?
            "U\n" : std::to_string(it->second->getPins()[0]->getState()) + "\n");
    }
}

void Circuit::input(std::string input, Tristate value, std::map<std::string, std::shared_ptr<IComponent>> &components)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;

    it = components.find(input);
    if (it == components.end() && it->first != input)
        throw Error("Input" + input + "doesn't exists.");
    it->second->getPins()[0]->setState(value);
    if (dynamic_cast<Component *>(it->second.get())->getName() == "clock")
        it->second->getPins()[0]->setClock(value);
}

void Circuit::simulate(std::map<std::string, std::shared_ptr<IComponent>> &components)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;

    for (it = components.begin(); it != components.end(); it++) {
        if (it->second->getPins().size() > 1)
            it->second.get()->simulate(_tick);
        else
            it->second->getPins()[0]->getLink()->setState(it->second->getPins()[0]->getState());
    }
    _tick++;
    createDisplay(components);
}

void Circuit::signalHandler(__attribute__((unused)) int signum)
{
}

void Circuit::loop(std::map<std::string, std::shared_ptr<IComponent>> &components)
{
    signal(SIGTSTP, Circuit::signalHandler);
    while (true) {
        simulate(components);
        display();
    }
    signal(SIGTSTP, SIG_DFL);
}

void Circuit::dump(std::map<std::string, std::shared_ptr<IComponent>> components)
{
    std::map<std::string, std::shared_ptr<IComponent>>::iterator it;

    for (it = components.begin(); it != components.end(); it++){
        if (dynamic_cast<Component *>(it->second.get())->getName() != "Input"
            && dynamic_cast<Component *>(it->second.get())->getName() != "Output")
            it->second->dump();
    }
}