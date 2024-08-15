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

PRIVATE void show_npc_panel_buttons(ENGPANEL, bool show)
{
    obj_t *obj = get_obj_by_id(panel, OBJ_MINIPANEL);
    button_t *btn1 = get_button_by_id(panel, BTN_NPC_DISCUSS);
    button_t *btn2 = get_button_by_id(panel, BTN_NPC_FIGHT);
    button_t *btn3 = get_button_by_id(panel, BTN_NPC_QUEST);
    txt_t *tx1 = get_text_by_type(panel, TXT_NPC);

    set_button_visible(btn1, show);
    set_button_visible(btn2, show);
    set_button_visible(btn3, show);
    set_text_visibility(tx1, false);
    set_obj_visibility(obj, show);
}

PRIVATE void display_npc_panel(ENGPANEL, bool show)
{
    entity_t *npc = get_nearest_npc(engine, game, panel);

    if (npc == NULL || npc->state == WAITING_FOR_ACTION || !show) {
        if (npc != NULL)
            npc->state = WAITING_FOR_ACTION;
        show_npc_panel_buttons(engine, game, panel, show);
        return;
    }
    if (npc != NULL && npc->state == DISCUSS) {
        display_npc_discuss(engine, game, panel);
        return;
    }
    if (npc != NULL && npc->state == QUEST) {
        display_npc_quest(engine, game, panel);
        return;
    }
}

void check_npc_panel(ENGPANEL)
{
    bool show = get_nearest_npc(engine, game, panel) != NULL;
    panel_t *paninv = get_panel_by_id(engine, GAME_INVENTORY);
    panel_t *panquest = get_panel_by_id(engine, GAME_QUESTS);
    panel_t *panach = get_panel_by_id(engine, GAME_ACHIEVEMENTS);

    if (paninv != NULL && paninv->visibility)
        show = false;
    if (panquest != NULL && panquest->visibility)
        show = false;
    if (panach != NULL && panach->visibility)
        show = false;
    display_npc_panel(engine, game, panel, show);
}