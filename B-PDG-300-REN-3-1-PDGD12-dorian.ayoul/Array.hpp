/*
** EPITECH PROJECT, 2022
** Array.hpp
** File description:
** Array
*/

#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <functional>

template <typename Type, size_t Size>
class Array
{
    public:
        Array()
        {
            _array = new Type[Size];
        }
        Type &operator[](size_t i)
        {
            if (i >= Size)
                throw(std::runtime_error("Out of range"));
            return _array[i];
        }
        std::size_t size() const
        {
            return Size;
        }
        void forEach(const std::function <void(const Type &)>& task) const
        {
            for (size_t i = 0; i < Size; i++)
                task(_array[i]);
        }
        template <typename U>
        Array <U, Size> convert(const std::function<U(const Type &)>& converter) const
        {
            Array<U, Size> cpy;

            for (size_t i = 0; i < Size; i++)
                cpy[i] = converter((U)_array[i]);
            return cpy;
        }
    private:
        Type *_array;
};

template <typename Type, size_t Size>
std::ostream &operator<<(std::ostream &os, Array<Type, Size> arr)
{
    std::string str = "[";

    for (size_t i = 0; i < Size; i++) {
        str += std::to_string(arr[i]);
        if (i < Size - 1)
            str += ", ";
    }
    str += ']';
    return std::cout << str;
}