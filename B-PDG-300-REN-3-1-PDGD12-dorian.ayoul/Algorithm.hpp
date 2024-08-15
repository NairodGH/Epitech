/*
** EPITECH PROJECT, 2022
** Algorithm.hpp
** File description:
** Algorithm
*/

#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

template <typename T>
void swap(T &x, T &y)
{
    const T tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
const T &min(const T &x, const T &y)
{
    return x < y ? x : y;
}

template <typename T>
const T &max(const T &x, const T &y)
{
    return x < y ? y : x;
}

template <typename T>
const T &clamp(const T &x, const T &y, const T &z)
{
    return x < y ? y : z < x ? z : x;
}