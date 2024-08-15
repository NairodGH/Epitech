/*
** EPITECH PROJECT, 2022
** Picture.hpp
** File description:
** Picture
*/

#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

class Picture
{
    public:
        Picture(const std::string &file);
        Picture(const Picture &cpy);
        Picture();
        virtual ~Picture() = default;
        std::string data;
        bool getPictureFromFile(const std::string &file);
        Picture &operator=(const Picture &cpy);
    private:
};