/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Parse cutscene
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

PRIVATE sfKeyCode parse_cutscene_flag(game_t *game, char *c)
{
    if (!c)
        return (sfKeyUnknown);
    if (!nstrcmp(c, "U"))
        return (game->settings->key_up);
    if (!nstrcmp(c, "D"))
        return (game->settings->key_down);
    if (!nstrcmp(c, "L"))
        return (game->settings->key_left);
    if (!nstrcmp(c, "R"))
        return (game->settings->key_right);
    return (sfKeyUnknown);
}

void start_cutscene_quest(engine_t *engine, panel_t *panel, game_t *game)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);

    if (npc == NULL)
        return;
    npc->state = DISCUSS;
    npc->line_id = 0;
    npc->discuss_itr = 1;
    npc->discuss_raw = get_discuss_chars(npc->discuss_lines, 0, 3);
}

void handle_cutscene_animation(ENGPANEL, cutscene_t *cutscene)
{
    char *c;
    sfKeyCode key;

    if (!cutscene || !cutscene->movements)
        return;
    c = cutscene->movements[cutscene->movement_index];
    if (!c) {
        end_cutscene(game);
        return;
    }
    key = parse_cutscene_flag(game, c);
    if (key == sfKeyUnknown) {
        start_cutscene_quest(engine, panel, game);
    } else {
        move_force_player(engine, panel, game, key);
    }
    ++cutscene->movement_index;
}

void handle_cutscene(ENGPANEL)
{
    cutscene_t *scene;
    sfInt64 clc;

    if (!game || !game->cutscene || !is_cutscene_started(game))
        return;
    scene = game->cutscene;
    if (!scene->clock)
        return;
    clc = sfClock_getElapsedTime(scene->clock).microseconds;
    if (clc < 16)
        return;
    handle_cutscene_animation(engine, game, panel, scene);
    sfClock_restart(scene->clock);
}