/*
** EPITECH PROJECT, 2021
** destroy_engine.c
** File description:
** Destroy engine
*/

#include <nep/nmem.h>
#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <stdlib.h>

void destroy_engine(engine_t *engine)
{
    if (engine == NULL)
        return;
    destroy_panels(engine->panels);
    engine->panels = NULL;
    gc_sounds(engine, true);
    destroy_window(engine->window);
}