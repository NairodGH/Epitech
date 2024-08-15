/*
** EPITECH PROJECT, 2021
** sandpile
** File description:
** sandpile structure
*/

#ifndef SAND_H
#define SAND_H

typedef struct pos_s {
    int x;
    int y;
} pos_t;

void addcase(char **map, pos_t max, pos_t pos, char *base);

void sandpile(char **map, int linenum, char *base, int iterations);

#endif
