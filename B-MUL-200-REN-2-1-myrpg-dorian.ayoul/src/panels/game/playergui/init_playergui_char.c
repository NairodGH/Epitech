/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init player gui background
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_playergui_char(ENGPANEL)
{
    char *hud_asset = "assets/textures/hud/hud.png";
    sfIntRect rect = {0, 0, 69, 85};
    sfVector2f pos = {422, 159};
    obj_t *obj = create_object(hud_asset, rect, pos);

    if (!obj || !game || !game->settings)
        return;
    obj->rect.left = 567 + game->settings->player * 69 - 69;
    sfSprite_setScale(obj->sprite, (sfVector2f) {0.6f, 0.6f});
    set_obj_rect(obj, obj->rect);
    register_object(panel, obj);
}