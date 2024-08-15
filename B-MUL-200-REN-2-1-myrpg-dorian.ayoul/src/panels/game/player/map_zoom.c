/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

void zoom_map(engine_t *eng, sfEvent event)
{
    sfMouseWheelScrollEvent scroll = event.mouseWheelScroll;
    sfView *v;
    sfVector2f size;

    v = (sfView *) sfRenderWindow_getView(get_window(eng));
    size = sfView_getSize(v);
    if (scroll.delta < 0) {
        if (size.x > 1650)
            return;
        sfView_zoom(v, 1.05f);
        sfRenderWindow_setView(get_window(eng), v);
        return;
    }
    if (size.x < 400)
        return;
    sfView_zoom(v, 0.97f);
    sfRenderWindow_setView(get_window(eng), v);
}