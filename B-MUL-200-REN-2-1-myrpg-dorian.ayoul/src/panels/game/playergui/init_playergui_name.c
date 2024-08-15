/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui save name
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_playergui_name(ENGPANEL)
{
    char *name;
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    name = game->player->save_name;
    pos = (sfVector2f) {418, 98};
    txt = create_text(font, name, pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 18);
    register_text(panel, txt);
}