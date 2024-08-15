/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Create fight status text
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void create_fight_status_txt(panel_t *panel)
{
    txt_t *txt;
    sfVector2f pos = {22, 395};
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");

    if (font == NULL)
        return;
    txt = create_text(font, "It's your turn.. Select an attack skill", pos);
    set_text_size(txt, 22);
    set_text_color(txt, sfWhite);
    set_text_type(txt, TXT_FIGHT_STATUS);
    register_text(panel, txt);
}