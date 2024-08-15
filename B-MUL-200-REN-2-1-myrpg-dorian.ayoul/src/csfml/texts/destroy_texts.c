/*
** EPITECH PROJECT, 2021
** destroy_texts.c
** File description:
** Destroy texts
*/

#include <texts.h>
#include <stdlib.h>

void destroy_texts(list_t *list)
{
    txt_t *txt;

    if (list == NULL)
        return;
    list_foreach(list, node) {
        txt = (txt_t *) node->value;
        destroy_text(txt);
    }
}