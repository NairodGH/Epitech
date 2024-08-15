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

void init_playergui_bg(ENGPANEL)
{
    char *bgasset = "assets/mplayerinfo/bg.png";
    sfIntRect rect = {0, 0, 349, 449};
    sfVector2f pos = {275, 20};
    obj_t *obj = create_object(bgasset, rect, pos);

    if (!obj)
        return;
    register_object(panel, obj);
}