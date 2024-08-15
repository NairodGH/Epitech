/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui health
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE void init_playergui_health_info(ENGPANEL)
{
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (!font)
        return;
    pos = (sfVector2f) {353, 220};
    txt = create_text(font, "Health: ", pos);
    if (!txt)
        return;
    set_text_color(txt, sfBlack);
    set_text_size(txt, 16);
    register_text(panel, txt);
}

PRIVATE sfColor get_health_color(int health)
{
    if (health >= 90)
        return ((sfColor) {39, 174, 96, 255});
    if (health >= 80)
        return ((sfColor) {46, 204, 113, 255});
    if (health >= 70)
        return ((sfColor) {41, 128, 185, 255});
    if (health >= 40)
        return ((sfColor) {241, 196, 15, 255});
    if (health >= 15)
        return ((sfColor) {231, 76, 60, 255});
    return ((sfColor) {192, 57, 43, 255});
}

PRIVATE void init_playergui_health_content(ENGPANEL)
{
    char *health;
    txt_t *txt;
    sfFont *font;
    sfVector2f pos;

    if (!game || !game->player)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    health = append_str(int_to_str(game->player->health), " %");
    pos = (sfVector2f) {415, 220};
    txt = create_text(font, health, pos);
    if (!txt)
        return;
    set_text_color(txt, get_health_color(game->player->health));
    set_text_size(txt, 16);
    register_text(panel, txt);
}

void init_playergui_health(ENGPANEL)
{
    init_playergui_health_info(engine, game, panel);
    init_playergui_health_content(engine, game, panel);
}