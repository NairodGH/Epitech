/*
** EPITECH PROJECT, 2021
** NPC events panel
** File description:
** events npc panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void on_npc_discuss(ENGPANEL, button_t *btn)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);

    (void) btn;
    if (npc == NULL)
        return;
    npc->state = DISCUSS;
    npc->line_id = 0;
    npc->discuss_itr = 1;
    npc->discuss_raw = get_discuss_chars(npc->discuss_lines, 0, 3);
}

void on_npc_fight(ENGPANEL, button_t *btn)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);

    (void) btn;
    if (npc == NULL)
        return;
    npc->state = FIGHT;
    start_display_fight(engine, game, panel, npc);
}

void on_npc_quest(ENGPANEL, button_t *btn)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);

    (void) btn;
    if (npc == NULL)
        return;
    npc->state = QUEST;
}