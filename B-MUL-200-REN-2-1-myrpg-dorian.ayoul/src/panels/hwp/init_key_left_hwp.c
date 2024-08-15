/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init left move key
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <sounds.h>
#include <rpg/rpg.h>

void init_txt_key_left(ENGPANEL)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    char *key = convert_key_char(engine->game->settings->key_left);
    txt_t *txt = create_text(font, key, (sfVector2f) {103, 246});

    set_text_size(txt, 22);
    register_text(panel, txt);
}