/*
** EPITECH PROJECT, 2021
** stumper
** File description:
** map
*/

#include "list.h"

#ifndef MAP_H
#define MAP_H

typedef struct {
    int x;
    int y;
} pos;

typedef struct {
    pos g;
    char **m;
    int le;
    int linele;
    list **tokens;
    int tokentot;
    int tokenfind;
    list **food;
    int movetot;
    int moves;
    pos goal;
    pos vec;
} map;

#endif

char map_at(map *m, pos p);

void destroy_map(map *m);
