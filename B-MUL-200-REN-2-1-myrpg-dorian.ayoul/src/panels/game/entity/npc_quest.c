/*
** EPITECH PROJECT, 2021
** Init NPC quest
** File description:
** init npc quest
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

PRIVATE bool finished_quest(game_t *game, entity_t *npc)
{
    enum quest_type type = 0;
    int item_id = -1;

    if (game == NULL || npc == NULL || npc->quest == NULL)
        return (false);
    type = npc->quest->type;
    item_id = npc->quest->item_id;
    if (already_finished_quest(game, npc->id))
        return (true);
    if (game->player && game->player->quest_id != npc->id)
        return (false);
    if (type == GET_ITEM && get_itemstack(game, item_id) != NULL) {
        remove_item_from_id(game, item_id, npc->quest->item_count);
        handle_quest_end(game, npc);
        return (true);
    }
    return (false);
}

PRIVATE void handle_npc_quest_case(ENGPANEL, entity_t *npc)
{
    txt_t *tx1 = get_text_by_type(panel, TXT_NPC);

    if (npc == NULL || tx1 == NULL)
        return;
    if (finished_quest(game, npc)) {
        set_text_content(tx1, npc->quest->finished_text);
        return;
    }
    if (game->player != NULL && game->player->quest_id == npc->id) {
        set_text_content(tx1, npc->quest->started_text);
        return;
    }
    if (npc->next_time != -1)
        play_discuss_sound(engine, game, npc);
    set_text_content(tx1, get_quest_str(panel, game, npc));
}

PRIVATE void show_npc_quest_text(ENGPANEL)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);
    sfInt64 time = 0;

    if (npc == NULL || npc->discuss_clock == NULL || npc->quest == NULL)
        return;
    time = sfClock_getElapsedTime(npc->discuss_clock).microseconds / 1000.f;
    if (time < npc->next_time)
        return;
    handle_npc_quest_case(engine, game, panel, npc);
    sfClock_restart(npc->discuss_clock);
}

void display_npc_quest(ENGPANEL)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_MINIPANEL);
    button_t *btn1 = get_button_by_id(panel, BTN_NPC_DISCUSS);
    button_t *btn2 = get_button_by_id(panel, BTN_NPC_FIGHT);
    button_t *btn3 = get_button_by_id(panel, BTN_NPC_QUEST);
    txt_t *tx1 = get_text_by_type(panel, TXT_NPC);

    set_button_visible(btn1, false);
    set_button_visible(btn2, false);
    set_button_visible(btn3, false);
    set_text_visibility(tx1, true);
    set_obj_visibility(obj, true);
    show_npc_quest_text(engine, game, panel);
}