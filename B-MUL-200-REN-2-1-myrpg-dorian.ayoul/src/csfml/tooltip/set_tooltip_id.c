/*
** EPITECH PROJECT, 2021
** set_tooltip_id.c
** File description:
** Set tooltip id
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <stdlib.h>
#include <texts.h>

void set_tooltip_id(tooltip_t *tooltip, int id)
{
    if (tooltip == NULL)
        return;
    tooltip->id = id;
}