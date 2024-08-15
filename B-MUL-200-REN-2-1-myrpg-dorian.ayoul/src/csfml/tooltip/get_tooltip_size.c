/*
** EPITECH PROJECT, 2021
** draw_panel.c
** File description:
** Draw a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <texts.h>

sfFloatRect get_tooltip_size(tooltip_t *tool)
{
    sfFloatRect rct = sfText_getGlobalBounds(tool->text);

    rct.width += 50;
    rct.height += 12;
    return (rct);
}