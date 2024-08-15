/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** event
*/

#ifndef RPG_EVENT_H
#define RPG_EVENT_H

#include <SFML/Graphics.h>

typedef struct game_s game_t;

void poll_event(game_t *game);

void event_buildin(game_t *game, sfEvent *event);

#endif