/*
** EPITECH PROJECT, 2021
** get_text_state.c
** File description:
** Get text state
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

int get_text_state(txt_t *txt)
{
    if (txt == NULL)
        return (0);
    return (txt->state);
}