/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** grid_position
*/

#include <rpg/grid.h>

sfVector2f grid_absolute_pos(grid_t *grid, sfVector2f relative)
{
    sfVector2f absolute;

    if (grid == NULL)
        return (sfVector2f){0, 0};
    if (relative.x > grid->size.x)
        relative.x = grid->size.x;
    if (relative.y > grid->size.y)
        relative.y = grid->size.y;
    absolute.x = grid->scale.x * ((relative.x - 1) * grid->cell_size.x) \
    + grid->pos.x;
    absolute.y = grid->scale.y * ((relative.y - 1) * grid->cell_size.y) \
    + grid->pos.y;
    return absolute;
}

sfVector2i grid_relative_pos(grid_t *grid, sfVector2f absolute)
{
    sfVector2i relative = {0, 0};

    if (grid == NULL)
        return (sfVector2i){0, 0};
    for (int i = 0; i <= absolute.x; i += grid->scale.x * grid->cell_size.x)
        relative.x++;
    for (int i = 0; i <= absolute.y; i += grid->scale.x * grid->cell_size.y)
        relative.y++;
    return relative;
}