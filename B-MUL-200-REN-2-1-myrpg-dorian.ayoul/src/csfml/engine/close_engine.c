/*
** EPITECH PROJECT, 2021
** close_engine.c
** File description:
** Close engine
*/

#include <nep/nmem.h>
#include <engine.h>
#include <window.h>
#include <stdlib.h>

void close_engine(engine_t *engine)
{
    if (engine == NULL)
        return;
    engine->end = true;
    if (engine->window != NULL) {
        destroy_engine(engine);
        engine->window = NULL;
    }
    destroy_engine(engine);
}