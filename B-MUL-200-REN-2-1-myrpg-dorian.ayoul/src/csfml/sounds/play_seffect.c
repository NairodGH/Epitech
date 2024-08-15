/*
** EPITECH PROJECT, 2021
** play_seffect.c
** File description:
** Play sound effect once
*/

#include <nep/nmem.h>
#include <sounds.h>
#include <rpg/rpg.h>

void play_seffect(game_t *game, engine_t *eng, char *path)
{
    if (game == NULL || eng == NULL || game->settings == NULL)
        return;
    sound_t *sound = create_sound(path, false, game->settings->volume, 1.f);
    register_sound(eng, sound);
    play_sound(sound);
}