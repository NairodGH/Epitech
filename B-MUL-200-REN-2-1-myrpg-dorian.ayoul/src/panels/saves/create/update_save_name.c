/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init save list panel
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <buttons.h>
#include <texts.h>
#include <objects.h>
#include <rpg/rpg.h>

char get_save_key(sfKeyCode code)
{
    if (code == sfKeySpace)
        return (' ');
    if (code == sfKeyBackspace)
        return ('<');
    if (code < sfKeyA || code > sfKeyZ)
        return ('\0');
    return ('a' + code);
}

char *append_char_to_str(char *str, char c)
{
    int nlen = 0;
    char *nstr;
    unsigned int itr = 0;

    if (str == NULL)
        return (NULL);
    nlen = nstrlen(str) + 2;
    nstr = ncalloc(nlen, sizeof(char));
    if (nstr == NULL)
        return (NULL);
    for (; str[itr]; ++itr)
        nstr[itr] = str[itr];
    nstr[itr] = c;
    nstr[++itr] = '\0';
    return (nstr);
}

void append_save_name_string(ENGPANEL, char c)
{
    txt_t *txt = NULL;
    char *str;
    char *nstr;

    list_foreach(panel->texts, node)
        txt = (txt_t *) node->value;
    if (txt == NULL)
        return;
    str = nstrdup(sfText_getString(txt->text));
    if (c == '<') {
        str[nstrlen(str) - 1] = '\0';
        sfText_setString(txt->text, str);
        return;
    }
    if (str == NULL || get_text_endpos(txt).x >= 600)
        return;
    nstr = append_char_to_str(str, c);
    sfText_setString(txt->text, nstr);
}

void on_save_create_events(ENGPANEL, sfEvent event)
{
    sfKeyCode code;
    char c;

    if (panel == NULL || panel->texts == NULL)
        return;
    if (event.type == sfEvtKeyPressed) {
        code = event.key.code;
        c = get_save_key(code);
        if (c == '\0')
            return;
        play_seffect(engine->game, engine, "assets/sounds/keypress.ogg");
        append_save_name_string(engine, game, panel, c);
    }
}