/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Inventory events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE bool can_open_playergui(ENGPANEL)
{
    panel_t *panach = get_panel_by_id(engine, GAME_ACHIEVEMENTS);
    panel_t *panquests = get_panel_by_id(engine, GAME_QUESTS);
    panel_t *paninv = get_panel_by_id(engine, GAME_INVENTORY);

    bool bar = (panach == NULL || !panach->visibility);
    bar = bar && (panquests == NULL || !panquests->visibility);
    bar = bar && (paninv == NULL || !paninv->visibility);
    bar = bar && !game->paused;
    return (bar);
}

void handle_playergui_events(ENGPANEL)
{
    panel_t *pan = get_panel_by_id(engine, GAME_PLAYERGUI);

    if (pan == NULL)
        return;
    if (pan->visibility) {
        close_panel_by_id(engine, game, GAME_PLAYERGUI);
        return;
    }
    if (!can_open_playergui(engine, game, panel))
        return;
    show_panel_by_id(engine, game, GAME_PLAYERGUI);
}