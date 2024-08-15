/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Game pause event
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE bool game_event_escpanels(engine_t *eng)
{
    panel_t *panach = get_panel_by_id(eng, GAME_ACHIEVEMENTS);
    panel_t *panquests = get_panel_by_id(eng, GAME_QUESTS);
    panel_t *panplayer = get_panel_by_id(eng, GAME_PLAYERGUI);
    panel_t *paninv = get_panel_by_id(eng, GAME_INVENTORY);

    if (panach != NULL && is_panel_visible(panach))
        return (set_panel_visibility(panach, false));
    if (panquests != NULL && is_panel_visible(panquests))
        return (set_panel_visibility(panquests, false));
    if (panplayer != NULL && is_panel_visible(panplayer))
        return (set_panel_visibility(panplayer, false));
    if (paninv != NULL && is_panel_visible(paninv))
        return (set_panel_visibility(paninv, false));
    return (false);
}

PRIVATE void game_event_pause(engine_t *eng, game_t *game)
{
    game->paused = !game->paused;
    if (game->paused)
        show_panel_by_id(eng, game, PAUSE);
    else
        hide_panel(eng, PAUSE);
}

void game_event_escape(engine_t *eng, game_t *game, sfEvent ev)
{
    if (ev.key.code != sfKeyEscape)
        return;
    play_seffect(game, eng, "assets/sounds/punch.ogg");
    if (game_event_escpanels(eng))
        return;
    game_event_pause(eng, game);
}