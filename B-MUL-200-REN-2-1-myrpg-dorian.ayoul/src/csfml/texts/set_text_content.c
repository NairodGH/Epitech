/*
** EPITECH PROJECT, 2021
** set_text_color.c
** File description:
** Set text color
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

void set_text_content(txt_t *txt, char *str)
{
    if (txt == NULL || str == NULL)
        return;
    txt->content = str;
    sfText_setString(txt->text, txt->content);
}