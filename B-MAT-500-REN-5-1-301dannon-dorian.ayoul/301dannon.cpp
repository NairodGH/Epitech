/*
** EPITECH PROJECT, 2022
** 301dannon.cpp
** File description:
** 301dannon
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>

typedef struct {
    std::vector<float> list;
    size_t comparisons;
} dannon;

dannon selection(dannon d)
{
    for (size_t i = 0; i < d.list.size(); i++) {
        size_t min = i;
        for (size_t j = i + 1; j < d.list.size(); d.comparisons++, j++)
            if (d.list[min] > d.list[j])
                min = j;
        if (min != i)
            std::swap(d.list[i], d.list[min]);
    }
    return d;
}

dannon insertion(dannon d)
{
    for (size_t i = 1; i < d.list.size(); i++) {
        for (size_t j = i; j > 0;) {
            d.comparisons++;
            if (d.list[j] >= d.list[j - 1]) {
                std::swap(d.list[j], d.list[j - 1]);
                j--;
            }
            else
                break;
        }
    }
    return d;
}

dannon bubble(dannon d)
{
    for (size_t i = 0; i < d.list.size(); i++)
        for (size_t j = 0; j < d.list.size() - i - 1; d.comparisons++, j++)
            if (d.list[i + 1] < d.list[i])
                std::swap(d.list[i + 1], d.list[i]);
    return d;
}

dannon quick(dannon d)
{
    if (d.list.size() <= 1)
        return (dannon){d.list, 0};
    std::vector<float> left, right;
    for (size_t i = 1; i < d.list.size(); d.comparisons++, i++) {
        if (d.list[i] >= d.list[0])
            left.push_back(d.list[i]);
        else
            right.push_back(d.list[i]);
    }
    dannon dl = quick((dannon){left, 0});
    dannon dr = quick((dannon){right, 0});
    dl.list.push_back(d.list[0]);
    dl.list.insert(dl.list.end(), dr.list.begin(), dr.list.end());
    return (dannon){dl.list, d.comparisons + dl.comparisons + dr.comparisons};
}

dannon merge(dannon d)
{
    if (d.list.size() <= 1)
        return (dannon){d.list, 0};
    std::vector<float> left, right;
    for (size_t i = 0; i < d.list.size(); i++) {
        if (i < d.list.size() / 2)
            left.push_back(d.list[i]);
        else
            right.push_back(d.list[i]);
    }
    dannon dl = merge((dannon){left, 0});
    dannon dr = merge((dannon){right, 0});
    d.list.clear();
    for(; !dl.list.empty() && !dr.list.empty(); d.comparisons++) {
        if (dl.list[0] < dr.list[0]) {
            d.list.push_back(dl.list[0]);
            dl.list.erase(dl.list.begin());
        }
        else {
            d.list.push_back(dr.list[0]);
            dr.list.erase(dr.list.begin());
        }
    }
    d.list.insert(d.list.end(), dl.list.begin(), dl.list.end());
    d.list.insert(d.list.end(), dr.list.begin(), dr.list.end());
    return (dannon){d.list, d.comparisons + dl.comparisons + dr.comparisons};
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    std::ifstream file(av[1]);

    dannon d = {std::vector<float>(), 0};
    if (file.is_open())
        for (std::string line; std::getline(file, line);) {
            for (size_t i = 0; i < line.size(); i++)
                if (!(line[i] >= '0' && line[i] <= '9' ||
                    line[i] == '-' && line[i + 1] >= '0' && line[i + 1] <= '9' ||
                    line[i] == '.' && i && line[i - 1] >= '0' && line[i - 1] <= '9'))
                    line[i] = ' ';
            std::istringstream iss(line);
            std::copy(std::istream_iterator<float>(iss), std::istream_iterator<float>(), std::back_inserter(d.list));
        }
    else
        return 84;
    if (d.list.empty())
        return 84;

    std::cout << d.list.size() << (d.list.size() > 1 ? " elements" : " element") << std::endl;
    std::cout << "Selection sort: " << selection(d).comparisons << " comparisons" << std::endl;
    std::cout << "Insertion sort: " << insertion(d).comparisons << " comparisons" << std::endl;
    std::cout << "Bubble sort: " << bubble(d).comparisons << " comparisons" << std::endl;
    std::cout << "Quicksort: " << quick(d).comparisons << " comparisons" << std::endl;
    std::cout << "Merge sort: " << merge(d).comparisons << " comparisons" << std::endl;
    return 0;
}