/*
** EPITECH PROJECT, 2021
** Init PICKUP panel
** File description:
** init pickup panel
*/

#include <engine.h>
#include <panel.h>
#include <rpg/rpg.h>

PRIVATE void create_texts(ENGPANEL)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/ancientmoderntales.ttf");
    char *str = "Press F to pickup";
    txt_t *txt = create_text(font, str, (sfVector2f){400, 450});

    if (font == NULL || txt == NULL)
        return;
    set_text_size(txt, 24);
    set_text_color(txt, sfWhite);
    set_text_type(txt, TXT_PICKUP);
    set_text_visibility(txt, false);
    register_text(panel, txt);
}

void init_pickup_panel(ENGPANEL)
{
    create_texts(engine, game, panel);
}