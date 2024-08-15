/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Handle panel quests events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE bool can_open_quests(ENGPANEL)
{
    panel_t *panach = get_panel_by_id(engine, GAME_ACHIEVEMENTS);
    panel_t *paninv = get_panel_by_id(engine, GAME_INVENTORY);
    panel_t *panplayer = get_panel_by_id(engine, GAME_PLAYERGUI);

    bool bar = (panach == NULL || !panach->visibility);
    bar = bar && (paninv == NULL || !paninv->visibility);
    bar = bar && (panplayer == NULL || !panplayer->visibility);
    bar = bar && !game->paused;
    return (bar);
}

void handle_panel_quests_events(ENGPANEL)
{
    panel_t *pan = get_panel_by_id(engine, GAME_QUESTS);

    if (pan == NULL)
        return;
    if (pan->visibility) {
        close_panel_by_id(engine, game, GAME_QUESTS);
        return;
    }
    if (!can_open_quests(engine, game, panel))
        return;
    show_panel_by_id(engine, game, GAME_QUESTS);
}