/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

void game_destroy_pos_to_look(pos_t **to_look)
{
    for (size_t i = 0; to_look[i]; i++) {
        free(to_look[i]);
    }
    free(to_look);
}

pos_t **game_init_pos_to_look(size_t amount)
{
    pos_t **to_look = NULL;


    to_look = calloc(amount + 1, sizeof(pos_t *));
    if (to_look == NULL)
        return (NULL);
    for (size_t i = 0; i < amount; i++) {
        to_look[i] = calloc(1, sizeof(pos_t));
        if (to_look[i] == NULL) {
            game_destroy_pos_to_look(to_look);
            return (NULL);
        }
    }
    return (to_look);
}

size_t game_get_tile_nbr(size_t level)
{
    size_t tile_nbr = 0;

    for (size_t i = 0; i < level; i++)
        tile_nbr += (i * 2) + 1;
    return (tile_nbr);
}

char *game_get_look_ressource_str(const char *ressource, size_t amount,
    char *str)
{
    char *temp = str;

    for (size_t i = 0; i < amount; i++) {
        temp = str;
        if (asprintf(&str, "%s%s ", temp, ressource) == -1) {
            fprintf(stderr, "[ERROR] Malloc failed\n");
            free(temp);
            return (NULL);
        }
        free(temp);
    }
    return str;
}

size_t game_look_filter_coord(ssize_t coord, size_t max_pos)
{
    if (coord < 0) {
        for (; coord < 0; coord += max_pos);
        return (size_t)coord;
    }
    return (size_t)(coord % max_pos);
}
