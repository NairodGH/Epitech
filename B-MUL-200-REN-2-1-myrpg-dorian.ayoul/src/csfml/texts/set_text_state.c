/*
** EPITECH PROJECT, 2021
** set_text_state.c
** File description:
** Set text state
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_state(txt_t *txt, int state)
{
    if (txt == NULL)
        return;
    txt->state = state;
}