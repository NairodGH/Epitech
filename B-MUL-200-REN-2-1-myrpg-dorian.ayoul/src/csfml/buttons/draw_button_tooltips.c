/*
** EPITECH PROJECT, 2021
** draw_button_tooltips.c
** File description:
** Draw game button tooltips
*/

#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <nep/nmem.h>
#include <nep/nctype.h>
#include <nep/nlist.h>

static void show_btn_tooltip(engine_t *eng, button_t *btn, sfVector2i mouse)
{
    sfVector2f pos = {mouse.x * 1.f, mouse.y * 1.f};

    if (btn == NULL || btn->tooltip == NULL)
        return;
    display_tooltip(eng, pos, btn->tooltip);
}

void draw_button_tooltips(engine_t *engine, list_t *list)
{
    button_t *btn;
    sfVector2i mouse;

    if (list == NULL || engine == NULL)
        return;
    mouse = sfMouse_getPositionRenderWindow(engine->window->window);
    list_foreach(list, node) {
        btn = (button_t *) node->value;
        if (btn == NULL || !btn->is_visible)
            continue;
        if (btn->is_hovered) {
            show_btn_tooltip(engine, btn, mouse);
        }
    }
}