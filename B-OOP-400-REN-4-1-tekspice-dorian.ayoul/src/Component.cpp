/*
** EPITECH PROJECT, 2022
** Component.cpp
** File description:
** Component
*/

#include "Component.hpp"
#include "Pin.hpp"
#include "Chipset.hpp"

Tristate Component::compute(size_t pin)
{
	if (_pins[pin]->getType() == Pin::Type::O) {
		if (_name == "2716")
            return dynamic_cast<C2716 *>(this)->compute(pin);
		if (_name == "4001")
            return dynamic_cast<C4001 *>(this)->compute(pin);
		if (_name == "4008")
            return dynamic_cast<C4008 *>(this)->compute(pin);
		if (_name == "4011")
            return dynamic_cast<C4011 *>(this)->compute(pin);
		if (_name == "4013")
            return dynamic_cast<C4013 *>(this)->compute(pin);
		if (_name == "4017")
            return dynamic_cast<C4017 *>(this)->compute(pin);
		if (_name == "4030")
            return dynamic_cast<C4030 *>(this)->compute(pin);
		if (_name == "4040")
            return dynamic_cast<C4040 *>(this)->compute(pin);
		if (_name == "4069")
            return dynamic_cast<C4069 *>(this)->compute(pin);
        if (_name == "4071")
            return dynamic_cast<C4071 *>(this)->compute(pin);
        if (_name == "4081")
            return dynamic_cast<C4081 *>(this)->compute(pin);
		if (_name == "C4094")
            return dynamic_cast<C4094 *>(this)->compute(pin);
		if (_name == "4512")
            return dynamic_cast<C4512 *>(this)->compute(pin);
		if (_name == "4514")
            return dynamic_cast<C4514 *>(this)->compute(pin);
		if (_name == "4801")
            return dynamic_cast<C4801 *>(this)->compute(pin);
		if (_name == "logger")
            return dynamic_cast<Logger *>(this)->compute(pin);
		
    }
    return _pins[pin]->getLink()->getState();
}

void Component::simulate(size_t tick)
{
	for (size_t i = 0; i != this->_pins.size(); i++) {
		if (_pins[i]->getLink() != nullptr && _pins[i]->getLink()->getClock() != nts::Tristate::UNDEFINED) {
			tick % 2 == (bool)_pins[i]->getLink()->getClock() ?
			_pins[i]->setState(_pins[i]->getLink()->getClock()) : _pins[i]->setState((Tristate)!(bool)(_pins[i]->getLink()->getClock()));
			_pins[i]->getLink()->setState(_pins[i]->getState());
		}
		if (_pins[i]->getType() == Pin::Type::I && _pins[i]->getLink() != nullptr) {
			_pins[i]->setState(Component::compute(i));
		}
	}
	for (size_t i = 0; i != this->_pins.size(); i++) {
		if (_pins[i]->getType() == Pin::Type::O && _pins[i]->getLink() != nullptr) {
			_pins[i]->setState(Component::compute(i));
			_pins[i]->getLink()->setState(_pins[i]->getState());
		}
	}
}

void Component::setLink(size_t pin, IComponent &other, size_t otherPin)
{
	if (pin - 1 > _pins.size() || otherPin - 1 > other.getPins().size())
		throw Error("Pin does not exist");
	_pins[pin - 1]->setLink(other.getPins()[otherPin - 1]);
}

void Component::dump() const
{
	size_t nb = 0;

	std::cout << "Name: " << _name << std::endl;
	std::cout << "Pins: " << std::endl;
	for (auto i : _pins) {
		std::cout << "\tPin number " << nb++ << std::endl;
		std::cout << "\t\tType: " << (!i->getType() ? "Input"
		: i->getType() == 1 ? "Output" : i->getType() == 2 ? "Unused" :
		i->getType() == 3 ? "True" : "False") << std::endl;
		std::cout << "\t\tStatus: " << (!i->getState() ? "Undefined"
		: i->getState() == 1 ? "On" : "Off") << std::endl;
	}
}

std::string Component::getName()
{
	return _name;
}

std::vector<std::shared_ptr<Pin>> &Component::getPins()
{
	return _pins;
}