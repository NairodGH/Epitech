/*
** EPITECH PROJECT, 2021
** is_panel_visible.c
** File description:
** Is panel visible?
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <texts.h>

bool is_panel_visible(panel_t *panel)
{
    if (panel == NULL)
        return (false);

    return (panel->visibility);
}