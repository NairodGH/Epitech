/*
** EPITECH PROJECT, 2021
** destroy_text.c
** File description:
** Destroy text
*/

#include <texts.h>
#include <stdlib.h>

void destroy_text(txt_t *txt)
{
    if (txt == NULL)
        return;

    if (txt->text != NULL) {
        sfText_destroy(txt->text);
        txt->text = NULL;
    }
}