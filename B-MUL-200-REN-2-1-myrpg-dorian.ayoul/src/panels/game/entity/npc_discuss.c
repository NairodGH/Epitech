/*
** EPITECH PROJECT, 2021
** Init NPC panel
** File description:
** init npc panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>

void play_discuss_sound(engine_t *eng, game_t *game, entity_t *ent)
{
    sfInt64 time = 0;
    sfClock *clock;

    if (ent == NULL || ent->discuss_soundclock == NULL)
        return;
    clock = ent->discuss_soundclock;
    time = sfClock_getElapsedTime(clock).microseconds / 1000.f;
    if (time < 80)
        return;
    play_seffect(game, eng, "assets/sounds/blip.ogg");
    sfClock_restart(clock);
}

PRIVATE void show_npc_discuss_text(ENGPANEL)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);
    txt_t *tx1 = get_text_by_type(panel, TXT_NPC);
    sfInt64 time = 0;

    if (npc == NULL || npc->discuss_clock == NULL)
        return;
    time = sfClock_getElapsedTime(npc->discuss_clock).microseconds / 1000.f;
    if (time < npc->next_time)
        return;
    if (npc->next_time != -1)
        play_discuss_sound(engine, game, npc);
    set_text_content(tx1, get_discuss_str(game, npc));
    sfClock_restart(npc->discuss_clock);
}

void display_npc_discuss(ENGPANEL)
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
    show_npc_discuss_text(engine, game, panel);
}