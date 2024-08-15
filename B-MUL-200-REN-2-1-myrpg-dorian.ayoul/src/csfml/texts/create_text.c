/*
** EPITECH PROJECT, 2021
** create_object.c
** File description:
** Create a game object
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <texts.h>

PRIVATE void init_text_defaults(txt_t *txt)
{
    if (txt == NULL)
        return;

    txt->text = sfText_create();
    txt->size = 15;
    txt->color = sfWhite;
    txt->type = -1;
    txt->state = 0;
    txt->on_click = NULL;
}

txt_t *create_text(sfFont *font, char *content, sfVector2f pos)
{
    txt_t *txt;

    if (font == NULL || content == NULL)
        return (NULL);
    txt = ncalloc(1, sizeof(txt_t));
    if (txt == NULL)
        return (NULL);
    txt->font = font;
    txt->content = content;
    txt->pos = pos;
    init_text_defaults(txt);
    if (txt->text == NULL)
        return (NULL);
    update_text(txt);
    set_text_visibility(txt, true);
    return (txt);
}