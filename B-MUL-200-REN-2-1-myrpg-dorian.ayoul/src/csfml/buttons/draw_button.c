/*
** EPITECH PROJECT, 2021
** draw_button.c
** File description:
** Draw a game button
*/

#include <SFML/Audio.h>
#include <engine.h>
#include <objects.h>
#include <buttons.h>
#include <sounds.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

bool is_button_transparent(sfColor c)
{
    if (c.a != sfTransparent.a || c.r != sfTransparent.r)
        return (false);
    return (c.g == sfTransparent.g && c.b == sfTransparent.b);
}

static bool handle_btn_hover(engine_t *eng, button_t *btn, sfVector2i mouse)
{
    bool hover = get_button_hovered(eng, btn, mouse);

    if (is_button_transparent(btn->color)) {
        if (hover || btn->is_clicked)
            sfSprite_setColor(btn->sprite, sfCyan);
        else
            sfSprite_setColor(btn->sprite, sfWhite);
    }
    if (hover) {
        if (!btn->is_hovered)
            play_seffect(eng->game, eng, "assets/sounds/b-hover.ogg");
        set_button_hovered(btn, true);
        return (true);
    }
    set_button_hovered(btn, false);
    return (false);
}

void draw_button(engine_t *engine, button_t *btn)
{
    sfRenderWindow *win;
    sfVector2i mouse;

    if (engine == NULL || btn == NULL || !btn->is_visible)
        return;
    win = get_window(engine);
    if (win == NULL)
        return;
    mouse = sfMouse_getPositionRenderWindow(engine->window->window);
    handle_btn_hover(engine, btn, mouse);
    sfRenderWindow_drawSprite(win, btn->sprite, NULL);
}