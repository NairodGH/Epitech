/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** draw
*/

#ifndef RPG_DRAW_H
#define RPG_DRAW_H

typedef struct game_s game_t;
typedef struct map_s map_t;

void draw(game_t *game);

void draw_map(game_t *game, map_t *map);

#endif