/*
** EPITECH PROJECT, 2022
** groundhog.cpp
** File description:
** groundhog
*/

#include "groundhog.hpp"

groundhog::groundhog()
{
    _switches = 0;
}

const int groundhog::get_period() const
{
    return _period;
}

int groundhog::set_period(char *period)
{
    std::string str(period);
    std::istringstream iss(str);
    int i = 0;

    iss >> std::noskipws >> i;
    if (i > 0 && iss.eof() && !iss.fail())
        return (_period = i);
    return 0;
}

float groundhog::get_input(std::string input)
{
    std::istringstream iss(input);
    float f;

    iss >> std::noskipws >> f;
    if (iss.eof() && !iss.fail())
        return f;
    return __FLT_MIN__;
}

const size_t groundhog::get_switches() const
{
    return _switches;
}

void groundhog::set_switches(size_t switches)
{
    _switches = switches;
}

bool groundhog::add_input(float input)
{
    if (input == __FLT_MIN__)
        return false;
    _inputs.push_back(input);
    if (_inputs.size() > 1)
        _prev_diffs[std::abs(_inputs.back() - _inputs[_inputs.size() - 2])].push_back(_inputs.size() - 1);
    return true;
}

const float groundhog::get_input(size_t i) const
{
    return _inputs[i];
}

const size_t groundhog::pop_highest_diff()
{
    size_t ret = _prev_diffs.rbegin()->second.back();

    _prev_diffs.rbegin()->second.pop_back();
    if (_prev_diffs.rbegin()->second.size() == 0)
        _prev_diffs.erase(_prev_diffs.rbegin()->first);
    return ret;
}

const size_t groundhog::get_size() const
{
    return _inputs.size();
}

const float groundhog::get_evolution() const
{
    return _evolution;
}

const float groundhog::get_previous_evolution() const
{
    return _previous_evolution;
}

// https://en.wikipedia.org/wiki/Arithmetic_mean
float groundhog::temperature_increase_average()
{
    float positive_prev_diffs = 0.f;

    for (size_t i = _inputs.size() - _period; i != _inputs.size(); i++)
        positive_prev_diffs += (_inputs[i] - _inputs[i - 1] <= 0.f ? 0.f : _inputs[i] - _inputs[i - 1]);
    return positive_prev_diffs / _period;
}

// https://en.wikipedia.org/wiki/Relative_change_and_difference
float groundhog::relative_temperature_evolution()
{
    _previous_evolution = _evolution;
    _evolution = (_inputs.back() - _inputs[_inputs.size() - _period - 1]) / _inputs[_inputs.size() - _period - 1] * 100;
    return _evolution;
}

// https://en.wikipedia.org/wiki/Standard_deviation
float groundhog::standard_deviation()
{
    float mean = 0.f;
    float squared_mean_deviations = 0.f;

    for (size_t i = _inputs.size() - _period; i < _inputs.size(); i++)
        mean += _inputs[i];
    mean /= _period;
    for (size_t i = _inputs.size() - _period; i < _inputs.size(); i++)
        squared_mean_deviations += pow(_inputs[i] - mean, 2);
    squared_mean_deviations /= _period;
    return sqrt(squared_mean_deviations);
}