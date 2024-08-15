/*
** EPITECH PROJECT, 2022
** groundhog.hpp
** File description:
** groundhog
*/

#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <math.h>

class groundhog
{
    public:
        groundhog();
        virtual ~groundhog() = default;
        const int get_period() const;
        int set_period(char *period);
        float get_input(std::string input);
        bool add_input(float input);
        const float get_input(size_t i) const;
        const size_t pop_highest_diff();
        const size_t get_size() const;
        const size_t get_switches() const;
        void set_switches(size_t switches);
        const float get_evolution() const;
        const float get_previous_evolution() const;
        float temperature_increase_average();
        float relative_temperature_evolution();
        float standard_deviation();
    private:
        int _period;
        std::vector<float> _inputs;
        std::map<float, std::vector<size_t>> _prev_diffs;
        size_t _switches;
        float _evolution;
        float _previous_evolution;
};