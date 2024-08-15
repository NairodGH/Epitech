/*
** EPITECH PROJECT, 2022
** init_client.c
** File description:
** init_client gui
*/

#include "zappy_gui.h"

bool clock_update(size_t freq)
{
    static double elapsed = 0;
    static struct timeval last = {0};
    struct timeval actual = {0};
    bool ret = false;

    gettimeofday(&actual, NULL);
    if (last.tv_sec != 0 || last.tv_usec != 0) {
        elapsed += (double)(actual.tv_sec - last.tv_sec) * 1000 +
            (double)(actual.tv_usec - last.tv_usec) / 1000;
        if (elapsed >= 1000 / freq)
            ret = true;
        while (elapsed >= 1000 / freq) {
            elapsed -= 1000 / freq;
        }
    }
    last = actual;
    return ret;
}
