/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_init
*/

#include <rpg/rpg.h>
#include <engine.h>

obj_t *init_push_quest_card(void)
{
    obj_t *obj;
    sfIntRect rct = {0, 0, 320, 64};
    sfVector2f pos = {640, -65};

    obj = create_object("assets/game/newquest.png", rct, pos);
    if (obj == NULL)
        return (NULL);
    set_obj_type(obj, OBJ_NEWQUEST);
    set_obj_visibility(obj, false);
    return (obj);
}

txt_t **init_hud_inventory_amount(void)
{
    size_t i = 0;
    sfFont *font = sfFont_createFromFile("assets/fonts/arial.ttf");
    txt_t **list = ncalloc(10, sizeof(txt_t));
    sfVector2f pos = {308, 518};

    if (!list || !font)
        return (NULL);
    for (; i < 10; ++i) {
        list[i] = create_text(font, "0", pos);
        if (!list[i] || !list[i]->text)
            continue;
        sfText_setStyle(list[i]->text, sfTextBold);
        pos.x += 40;
    }
    list[i] = NULL;
    return (list);
}

statics_t *init_statics(void)
{
    statics_t *statics = ncalloc(1, sizeof(statics_t));

    if (statics == NULL)
        return (NULL);
    statics->push_quest = init_push_quest_card();
    statics->hud_inv_amount = init_hud_inventory_amount();
    statics->basic_num = ncalloc(100, sizeof(char *));
    if (statics->basic_num) {
        for (unsigned int itr = 0; itr < 100; ++itr)
            statics->basic_num[itr] = int_to_str(itr);
        statics->basic_num[99] = NULL;
    }
    return (statics);
}