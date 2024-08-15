/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init settings panel
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <texts.h>
#include <rpg/rpg.h>

char *convert_key_char(sfKeyCode code)
{
    char c = get_converted_key(code);
    char *str;

    if (c == '\0')
        return ("");
    str = ncalloc(2, sizeof(char));
    if (str == NULL)
        return ("");
    str[0] = c;
    str[1] = '\0';
    return (str);
}

void update_key_texts(game_t *game, panel_t *panel)
{
    txt_t *txt;
    settings_t *settings;

    if (game->settings == NULL || panel == NULL || panel->texts == NULL)
        return;
    settings = game->settings;
    list_foreach(panel->texts, node) {
        txt = (txt_t *) node->value;
        if (txt->type < BTN_KEY_UP || txt->type > BTN_KEY_PICKUP)
            continue;
        set_text_content(txt, set_button_key(settings, txt->type));
    }
}

void create_key_text(game_t *game, panel_t *panel, gkey_t gkey)
{
    sfFont *font;
    txt_t *txt;
    sfVector2f pos;

    if (game == NULL || panel == NULL)
        return;
    font = sfFont_createFromFile("assets/fonts/arial.ttf");
    if (font == NULL)
        return;
    pos = (sfVector2f) {gkey.card_pos.x + 16, gkey.card_pos.y + 10};
    txt = create_text(font, get_assigned_key(game, gkey), pos);
    set_text_size(txt, 20);
    set_text_color(txt, sfBlack);
    set_text_type(txt, gkey.button_id);
    register_text(panel, txt);
}
