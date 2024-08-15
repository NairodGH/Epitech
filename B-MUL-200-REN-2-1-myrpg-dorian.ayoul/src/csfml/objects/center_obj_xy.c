/*
** EPITECH PROJECT, 2021
** center_obj_xy.c
** File description:
** Center a game object in x & y axis on the screen. Weird function I know..
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <engine.h>
#include <objects.h>
#include <engine.h>

void center_obj_xy(engine_t *engine, obj_t *obj)
{
    center_obj_x(engine, obj);
    center_obj_y(engine, obj);
}