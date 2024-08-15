/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** grid_create
*/

#include <rpg/grid.h>
#include <nep/nmem.h>

grid_t *grid_create(sfVector2i size, sfVector2f scale, sfVector2f pos,
sfVector2i cell_size)
{
    grid_t *grid = ncalloc(1, sizeof(grid_t));

    grid->size = size;
    grid->scale = scale;
    grid->pos = pos;
    grid->cell_size = cell_size;
    return grid;
}