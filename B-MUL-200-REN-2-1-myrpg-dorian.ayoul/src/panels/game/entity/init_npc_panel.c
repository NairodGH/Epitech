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

PRIVATE void create_npc_texts(ENGPANEL)
{
    sfFont *font = sfFont_createFromFile("assets/fonts/ancientmoderntales.ttf");
    char *str = "";
    txt_t *txt = create_text(font, str, (sfVector2f){272, 427});

    if (font == NULL || txt == NULL)
        return;
    set_text_size(txt, 18);
    set_text_color(txt, sfBlack);
    set_text_type(txt, TXT_NPC);
    set_text_visibility(txt, false);
    register_text(panel, txt);
}

PRIVATE void create_npc_panel_buttons(ENGPANEL)
{
    char *btn_discuss = "assets/btns/discuss.png";
    char *btn_fight = "assets/btns/fight.png";
    char *btn_quest = "assets/btns/quest.png";
    sfIntRect brct = {0, 0, 120, 62};
    button_t *b1 = create_button(btn_discuss, brct, (V2F) {272, 427}, false);
    button_t *b2 = create_button(btn_fight, brct, (V2F) {412, 427}, false);
    button_t *b3 = create_button(btn_quest, brct, (V2F) {552, 427}, false);

    set_button_id(b1, BTN_NPC_DISCUSS);
    set_button_id(b2, BTN_NPC_FIGHT);
    set_button_id(b3, BTN_NPC_QUEST);
    set_button_events(b1, &on_npc_discuss);
    set_button_events(b2, &on_npc_fight);
    set_button_events(b3, &on_npc_quest);
    register_button(panel, b1);
    register_button(panel, b2);
    register_button(panel, b3);
}

void init_npc_panel(ENGPANEL)
{
    sfIntRect rct = {0, 0, 500, 137};
    sfVector2f pos = {230, 390};
    obj_t *b = create_object("assets/game/minipanel.png", rct, pos);

    set_obj_type(b, OBJ_MINIPANEL);
    set_obj_visibility(b, false);
    register_object(panel, b);
    create_npc_panel_buttons(engine, game, panel);
    create_npc_texts(engine, game, panel);
}