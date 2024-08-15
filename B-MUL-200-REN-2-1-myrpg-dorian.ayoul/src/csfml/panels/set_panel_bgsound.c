/*
** EPITECH PROJECT, 2021
** set_panel_bgsound.c
** File description:
** Set panel background sound
*/

#include <nep/nmem.h>
#include <nep/nctype.h>
#include <rpg/rpg.h>
#include <panel.h>

void set_panel_bgsound(engine_t *engine, panel_t *panel, char *sound)
{
    sound_t *sd;
    float vol = 0.0f;

    if (panel == NULL)
        return;
    if (sound == NULL) {
        panel->bg_sound = NULL;
        return;
    }
    if (engine->game != NULL && engine->game->settings != NULL)
        vol = engine->game->settings->volume * .5f;
    sd = create_sound(sound, true, vol, 1.0f);
    panel->bg_sound = sd;
    if (panel->visibility && panel->bg_sound)
        play_sound(panel->bg_sound);
}