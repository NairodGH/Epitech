/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Handle panel achievement events
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE bool can_open_achievements(ENGPANEL)
{
    panel_t *quest = get_panel_by_id(engine, GAME_QUESTS);
    panel_t *paninv = get_panel_by_id(engine, GAME_INVENTORY);
    panel_t *panplayer = get_panel_by_id(engine, GAME_PLAYERGUI);

    bool bar = (quest == NULL || !quest->visibility);
    bar = bar && (paninv == NULL || !paninv->visibility);
    bar = bar && (panplayer == NULL || !panplayer->visibility);
    bar = bar && !game->paused;
    return (bar);
}

void handle_panel_achievements_events(ENGPANEL)
{
    panel_t *pan = get_panel_by_id(engine, GAME_ACHIEVEMENTS);

    if (pan == NULL)
        return;
    if (pan->visibility) {
        close_panel_by_id(engine, game, GAME_ACHIEVEMENTS);
        return;
    }
    if (!can_open_achievements(engine, game, panel))
        return;
    show_panel_by_id(engine, game, GAME_ACHIEVEMENTS);
}