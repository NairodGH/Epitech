/*
** EPITECH PROJECT, 2021
** set_panel_visibility.c
** File description:
** Set panel visibility
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>
#include <engine.h>
#include <panel.h>

bool set_panel_visibility(panel_t *panel, bool visibility)
{
    if (panel == NULL)
        return (false);
    panel->visibility = visibility;
    return (true);
}