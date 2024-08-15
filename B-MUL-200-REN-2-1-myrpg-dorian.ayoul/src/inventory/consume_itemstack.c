/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** consume itemstack
*/

#include <rpg/rpg.h>
#include <rpg/inventory.h>
#include <panel.h>
#include <sounds.h>

void handle_consumption(game_t *game, consumption_t *consumption)
{
    panel_t *panel = NULL;

    if (!game || !consumption || !game->player)
        return;
    if (consumption->type == CONSUMPTION_HEALTH)
        add_player_health(game, consumption->value);
    if (consumption->type == CONSUMPTION_FOOD)
        add_player_food(game, consumption->value);
    if (game->engine != NULL && consumption->sound != NULL)
        play_seffect(game, game->engine, consumption->sound);
    if (game->engine != NULL && consumption->message != NULL) {
        panel = get_panel_by_id(game->engine, GAME);
        if (!panel || !panel->visibility)
            return;
        set_action_bar(game->engine, panel, consumption->message);
    }
}

bool consume_itemstack(game_t *game, itemstack_t *stack)
{
    consumption_t *consumption;

    if (!game || !stack)
        return (false);
    if (!stack->item || !stack->item->consumptions)
        return (false);
    list_foreach(stack->item->consumptions, node) {
        consumption = (consumption_t *) node->value;
        handle_consumption(game, consumption);
    }
    return (true);
}