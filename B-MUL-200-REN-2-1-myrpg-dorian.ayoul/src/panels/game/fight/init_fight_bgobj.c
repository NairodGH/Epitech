/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init background fight object
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void init_fight_background(panel_t *panel)
{
    char *bg = "assets/fight/background.png";
    sfIntRect rc = {0, 0, 960, 540};
    obj_t *b = create_object(bg, rc, (sfVector2f){0, 0});

    set_obj_type(b, OBJ_FIGHT_BG);
    register_object(panel, b);
}