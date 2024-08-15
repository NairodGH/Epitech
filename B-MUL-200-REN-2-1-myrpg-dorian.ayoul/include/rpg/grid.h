/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** grid
*/

#ifndef RPG_GRID_H
#define RPG_GRID_H

#include <SFML/Graphics.h>

typedef struct grid_s {
    sfVector2i size;
    sfVector2f pos;
    sfVector2f scale;
    sfVector2i cell_size;
} grid_t;

grid_t *grid_create(sfVector2i size, sfVector2f scale, sfVector2f pos,
sfVector2i cell_size);

sfVector2f grid_absolute_pos(grid_t *grid, sfVector2f relative);
sfVector2i grid_relative_pos(grid_t *grid, sfVector2f absolute);

#endif