/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Init action bar
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void init_action_bar(engine_t *engine, panel_t *panel)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/retro.ttf");
    txt_t *txt;

    if (!panel || !font)
        return;
    txt = create_text(font, "Welcome back.", (sfVector2f) {450, 370});
    if (!txt)
        return;
    set_text_size(txt, 19);
    center_text_x(engine, txt);
    set_text_type(txt, TXT_ACTION_BAR);
    set_text_color(txt, (sfColor) {231, 76, 60, 0});
    register_text(panel, txt);
}