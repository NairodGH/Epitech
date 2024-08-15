/*
** EPITECH PROJECT, 2021
** get_text_content.c
** File description:
** Get text content
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

char *get_text_content(txt_t *txt)
{
    if (txt == NULL)
        return (NULL);
    return (txt->content);
}