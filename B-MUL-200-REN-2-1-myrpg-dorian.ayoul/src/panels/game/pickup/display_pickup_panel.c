/*
** EPITECH PROJECT, 2021
** Init PICKUP panel
** File description:
** init pickup panel
*/

#include <engine.h>
#include <panel.h>
#include <rpg/rpg.h>

void check_pickup_panel(ENGPANEL)
{
    get_item_nearest(panel, game->stage->map);
}