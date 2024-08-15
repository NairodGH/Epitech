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
#include <stdlib.h>
#include <texts.h>

PRIVATE sfText *init_tooltip_text(char *txt)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    sfText *text = sfText_create();

    if (text == NULL || txt == NULL || font == NULL)
        return (NULL);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 20);
    sfText_setString(text, txt);
    sfText_setColor(text, sfWhite);
    return (text);
}

PRIVATE void init_tooltip(tooltip_t *tool, char *text)
{
    sfText *txt = init_tooltip_text(text);
    sfFloatRect r;

    if (txt == NULL)
        return;
    tool->id = -1;
    tool->text = init_tooltip_text(text);
    r = get_tooltip_size(tool);
    tool->string = text;
    tool->pixels = malloc(sizeof(sfUint8) * (r.width * r.height * 4));
    tool->image = sfImage_createFromPixels(r.width, r.height, tool->pixels);
    tool->texture = sfTexture_createFromImage(tool->image, NULL);
    tool->sprite = sfSprite_create();
    sfSprite_setTexture(tool->sprite, tool->texture, sfFalse);
}

tooltip_t *create_tooltip(char *text)
{
    tooltip_t *tool;

    if (text == NULL)
        return (NULL);
    tool = ncalloc(1, sizeof(tooltip_t));
    if (tool == NULL)
        return (NULL);
    init_tooltip(tool, text);
    return (tool);
}

void set_tooltip(button_t *btn, char *text)
{
    tooltip_t *tooltip;

    if (btn == NULL || text == NULL)
        return;
    tooltip = create_tooltip(text);
    btn->tooltip = tooltip;
}