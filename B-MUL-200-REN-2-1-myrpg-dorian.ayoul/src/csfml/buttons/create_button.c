/*
** EPITECH PROJECT, 2021
** create_button.c
** File description:
** Create a button
*/

#include <nep/nmem.h>
#include <engine.h>
#include <buttons.h>

PRIVATE void init_button(button_t *button)
{
    if (button == NULL)
        return;
    button->is_hovered = false;
    button->is_clicked = false;
    button->tooltip = NULL;
    button->on_click = NULL;
    button->is_sticky = false;
    button->color = sfTransparent;
    button->id = -1;
}

button_t *create_button(char *path, sfIntRect rect, sfVector2f pos, bool vis)
{
    button_t *button;

    button = ncalloc(1, sizeof(button_t));
    if (button == NULL)
        return (NULL);
    button->path = path;
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(button->path, NULL);
    button->rect = rect;
    button->pos = pos;
    button->size = sfTexture_getSize(button->texture);
    button->is_visible = vis;
    init_button(button);
    update_button(button);
    return (button);
}