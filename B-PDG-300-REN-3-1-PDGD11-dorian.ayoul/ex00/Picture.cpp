/*
** EPITECH PROJECT, 2022
** Picture.cpp
** File description:
** Picture
*/

#include "Picture.hpp"

Picture::Picture(const std::string &filename)
{
    getPictureFromFile(filename);
}

Picture::Picture()
{
    data = "";
}

bool Picture::getPictureFromFile(const std::string &filename)
{
    std::ifstream file(filename);

    if (file.is_open()) {
        std::getline(file, data, '\0');
        file.close();
        return true;
    }
    else {
        data = "ERROR";
        return false;
    }
}