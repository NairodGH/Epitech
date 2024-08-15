/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init start texts
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void init_start_texts(game_t *game UNUSED, panel_t *panel)
{
    sfVector2f pos = {395, 160};
    sfFont *font = sfFont_createFromFile("assets/fonts/retro.ttf");
    txt_t *txt = create_text(font, "My RPG", pos);

    set_text_color(txt, sfBlack);
    set_text_size(txt, 34);
    register_text(panel, txt);
}