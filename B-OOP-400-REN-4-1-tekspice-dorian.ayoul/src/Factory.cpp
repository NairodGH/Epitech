/*
** EPITECH PROJECT, 2022
** Factory.cpp
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Chipset.hpp"

Factory::Factory()
{
    _fact["2716"] = &Factory::create2716;
    _fact["4001"] = &Factory::create4001;
    _fact["4008"] = &Factory::create4008;
    _fact["4011"] = &Factory::create4011;
    _fact["4013"] = &Factory::create4013;
    _fact["4017"] = &Factory::create4017;
    _fact["4030"] = &Factory::create4030;
    _fact["4040"] = &Factory::create4040;
    _fact["4069"] = &Factory::create4069;
	_fact["4071"] = &Factory::create4071;
	_fact["4081"] = &Factory::create4081;
    _fact["4094"] = &Factory::create4094;
    _fact["4512"] = &Factory::create4512;
    _fact["4514"] = &Factory::create4514;
    _fact["4801"] = &Factory::create4801;
    _fact["logger"] = &Factory::createLogger;
    _fact["input"] = &Factory::createInput;
    _fact["clock"] = &Factory::createClock;
    _fact["true"] = &Factory::createTrue;
    _fact["false"] = &Factory::createFalse;
	_fact["output"] = &Factory::createOutput;
}

std::unique_ptr<IComponent> Factory::createComponent(const std::string &type) const
{
    std::map<std::string, std::function<std::unique_ptr<IComponent>(Factory const &, std::string const &)>>::const_iterator it;

	it = this->_fact.find(type);
    if (it == _fact.end() && it->first != type)
        throw Error(it->first + "Is an unknown chipset");
    return it->second(*this, type);
}

std::unique_ptr<IComponent> Factory::create2716(const std::string &name) const
{
    return std::make_unique<C2716>(name);
}

std::unique_ptr<IComponent> Factory::create4001(const std::string &name) const
{
    return std::make_unique<C4001>(name);
}

std::unique_ptr<IComponent> Factory::create4008(const std::string &name) const
{
    return std::make_unique<C4008>(name);
}

std::unique_ptr<IComponent> Factory::create4011(const std::string &name) const
{
    return std::make_unique<C4011>(name);
}

std::unique_ptr<IComponent> Factory::create4013(const std::string &name) const
{
    return std::make_unique<C4013>(name);
}

std::unique_ptr<IComponent> Factory::create4017(const std::string &name) const
{
    return std::make_unique<C4017>(name);
}

std::unique_ptr<IComponent> Factory::create4030(const std::string &name) const
{
    return std::make_unique<C4030>(name);
}

std::unique_ptr<IComponent> Factory::create4040(const std::string &name) const
{
    return std::make_unique<C4040>(name);
}

std::unique_ptr<IComponent> Factory::create4069(const std::string &name) const
{
    return std::make_unique<C4069>(name);
}

std::unique_ptr<IComponent> Factory::create4071(const std::string &name) const
{
    return std::make_unique<C4071>(name);
}

std::unique_ptr<IComponent> Factory::create4081(const std::string &name) const
{
    return std::make_unique<C4081>(name);
}

std::unique_ptr<IComponent> Factory::create4094(const std::string &name) const
{
    return std::make_unique<C4094>(name);
}

std::unique_ptr<IComponent> Factory::create4512(const std::string &name) const
{
    return std::make_unique<C4512>(name);
}

std::unique_ptr<IComponent> Factory::create4514(const std::string &name) const
{
    return std::make_unique<C4514>(name);
}

std::unique_ptr<IComponent> Factory::create4801(const std::string &name) const
{
    return std::make_unique<C4801>(name);
}

std::unique_ptr<IComponent> Factory::createLogger(const std::string &name) const
{
    return std::make_unique<Logger>(name);
}

std::unique_ptr<IComponent> Factory::createInput(const std::string &name) const
{
    return std::make_unique<Input>(name);
}

std::unique_ptr<IComponent> Factory::createClock(const std::string &name) const
{
    return std::make_unique<Clock>(name);
}

std::unique_ptr<IComponent> Factory::createTrue(const std::string &name) const
{
    return std::make_unique<True>(name);
}

std::unique_ptr<IComponent> Factory::createFalse(const std::string &name) const
{
    return std::make_unique<False>(name);
}

std::unique_ptr<IComponent> Factory::createOutput(const std::string &name) const
{
    return std::make_unique<Output>(name);
}