/*
** EPITECH PROJECT, 2021
** get_window.c
** File description:
** Get engine opened window
*/

#include <engine.h>
#include <window.h>

sfRenderWindow *get_window(engine_t *engine)
{
    if (engine == NULL)
        return (NULL);
    if (engine->window == NULL)
        return (NULL);
    if (engine->window->window == NULL)
        return (NULL);
    return (engine->window->window);
}