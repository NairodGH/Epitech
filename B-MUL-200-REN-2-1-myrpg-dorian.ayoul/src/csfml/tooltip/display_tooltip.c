/*
** EPITECH PROJECT, 2021
** draw_panel.c
** File description:
** Draw a panel
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <panel.h>
#include <objects.h>
#include <buttons.h>
#include <texts.h>

static void update_tooltip(sfUint8 *pxl, sfFloatRect rect)
{
    sfColor cl = {48, 3, 66, 170};
    int idx;

    for (int y = 0; y < rect.height; ++y) {
        for (int x = 0; x < rect.width; ++x) {
            idx = x * 4 + (y * 4 * rect.width);
            pxl[idx] = cl.r;
            pxl[idx + 1] = cl.g;
            pxl[idx + 2] = cl.b;
            pxl[idx + 3] = cl.a;
        }
    }
}

void display_tooltip(engine_t *eng, sfVector2f pos, tooltip_t *tool)
{
    sfTexture *tx = tool->texture;
    sfUint8 *pxl = tool->pixels;
    sfFloatRect rct = get_tooltip_size(tool);
    sfVector2f newpos = get_tooltip_pos(tool, pos);
    sfVector2f txtpos = get_tooltip_text_pos(newpos);
    sfVector2f scale = get_window_scale(eng);

    update_tooltip(pxl, rct);
    txtpos.x = safe_scale(txtpos.x, scale.x);
    txtpos.y = safe_scale(txtpos.y, scale.y);
    sfText_setPosition(tool->text, txtpos);
    sfTexture_updateFromPixels(tx, pxl, rct.width, rct.height, 0, 0);
    newpos.x = safe_scale(newpos.x, scale.x);
    newpos.y = safe_scale(newpos.y, scale.y);
    sfSprite_setPosition(tool->sprite, newpos);
    sfRenderWindow_drawSprite(get_window(eng), tool->sprite, NULL);
    sfRenderWindow_drawText(get_window(eng), tool->text, NULL);
}