/*
** EPITECH PROJECT, 2022
** trade.hpp
** File description:
** trade
*/

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "Settings.hpp"

typedef struct candle_s {
    double high;
    double low;
    double open;
    double close;
    double volume;
} candle_t;