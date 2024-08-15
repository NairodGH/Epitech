/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move force player
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

void move_force_player(engine_t *en, panel_t *pn, game_t *game, sfKeyCode ke)
{
    set_player_movement_asset(pn, game, ke);
    handle_map_movement(ke, en, game, pn);
}