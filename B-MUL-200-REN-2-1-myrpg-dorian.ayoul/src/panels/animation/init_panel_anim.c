/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init anim panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <rpg/rpg.h>

void on_anim_render(engine_t *eng, game_t *game, panel_t *panel)
{
    obj_t *obj;

    if (panel->objects == NULL)
        return;
    list_foreach(panel->objects, node) {
        obj = (obj_t *) node->value;
        if (obj->type == 0) {
            animate_background(obj);
            continue;
        }
        animate_pacman(eng, game, obj);
    }
}

void init_anim_menu(engine_t *eng UNUSED, game_t *game UNUSED, panel_t *panel)
{
    sfIntRect rct = {0, 0, 960, 540};
    sfVector2f pos = {0, 0};
    sfIntRect rct2 = {0, 0, 200, 200};
    sfVector2f pos2 = {400, 250};
    obj_t *b = create_object("assets/manim/animation.png", rct, pos);
    obj_t *b2 = create_object("assets/manim/pacman.png", rct2, pos2);

    register_object(panel, b);
    register_object(panel, b2);
    b2->type = -4;
    sfSprite_setColor(b->sprite, (sfColor){255, 255, 255, 0});
    sfSprite_setColor(b2->sprite, (sfColor){255, 255, 255, 35});
    set_panel_visibility(panel, true);
}

void on_anim_event(engine_t *eng, game_t *game, panel_t *pn, sfEvent ev)
{
    (void) pn;
    if (ev.type == sfEvtKeyPressed) {
        skip_anim(eng, game);
    }
}

void init_panel_anim(engine_t *eng, game_t *game)
{
    panel_t *panel = create_panel(START_ANIM);

    set_panel_initializer(panel, &init_anim_menu, NULL);
    set_panel_updater(panel, NULL, &on_anim_render);
    set_panel_events(panel, &on_anim_event);
    register_panel(eng, panel);
    show_panel(eng, game, panel);
}