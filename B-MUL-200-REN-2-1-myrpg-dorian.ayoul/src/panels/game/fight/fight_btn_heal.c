/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Fight heal button
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void render_heal_button(ENGPANEL)
{
    button_t *btn = get_button_by_id(panel, BTN_FIGHT_HEAL);

    if (!btn)
        return;
    if (!get_itemstack(game, 1)) {
        if (btn->color.a != 120) {
            set_tooltip(btn, "You don't have any health potion.");
            set_button_color(btn, (sfColor) {120, 120, 120, 255});
        }
        return;
    }
    set_button_color(btn, sfTransparent);
}

void on_fight_heal(ENGPANEL, button_t *btn)
{
    itemstack_t *is = get_itemstack(game, 1);

    (void) btn;
    if (is == NULL) {
        play_seffect(game, engine, "assets/sounds/click-err.ogg");
        return;
    }
    if (remove_itemstack(game, is, 1))
        consume_itemstack(game, is);
}

void create_fight_heal_button(panel_t *panel)
{
    char *bpath = "assets/fight/heal.png";
    sfIntRect rct2 = {0, 0, 140, 69};
    sfVector2f btnpos = {790, 455};
    button_t *btn = create_button(bpath, rct2, btnpos, true);

    set_button_id(btn, BTN_FIGHT_HEAL);
    set_button_events(btn, &on_fight_heal);
    set_tooltip(btn, "Heal by using a potion");
    register_button(panel, btn);
}