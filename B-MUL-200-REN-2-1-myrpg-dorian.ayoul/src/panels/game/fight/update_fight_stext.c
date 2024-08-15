/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init fight panel
*/

#include <engine.h>
#include <panel.h>
#include <objects.h>
#include <sounds.h>
#include <rpg/rpg.h>
#include <rpg/inventory.h>

void update_fight_stext(panel_t *panel, char *str)
{
    txt_t *txt = NULL;

    if (!panel || !str)
        return;
    txt = get_text_by_type(panel, TXT_FIGHT_STATUS);
    if (!txt)
        return;
    set_text_content(txt, str);
}