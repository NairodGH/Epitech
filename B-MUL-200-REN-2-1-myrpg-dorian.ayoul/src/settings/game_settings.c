/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_settings
*/

#include <rpg/rpg.h>
#include <rpg/args.h>
#include <engine.h>

PRIVATE bool update_settings_with_args(settings_t *settings, list_t *args)
{
    char *vol_raw = get_arg(args, "v");
    char *fps_raw = get_arg(args, "f");

    if (settings == NULL || args == NULL)
        return (true);
    if (!update_volume(settings, vol_raw)) {
        nprintf("Unable to consider volume arg: invalid argument.\n");
    }
    if (!update_fps(settings, fps_raw)) {
        nprintf("Unable to consider fps arg: invalid argument.\n");
    }
    return (false);
}

PRIVATE void init_default_skeys(settings_t *settings)
{
    settings->key_up = sfKeyZ;
    settings->key_down = sfKeyQ;
    settings->key_left = sfKeyS;
    settings->key_right = sfKeyD;
    settings->key_inv = sfKeyF;
    settings->key_player = sfKeyP;
    settings->key_ach = sfKeyH;
    settings->key_quest = sfKeyN;
    settings->key_pickup = sfKeyE;
}

settings_t *init_settings(list_t *args)
{
    settings_t *settings = ncalloc(1, sizeof(settings_t));

    if (settings == NULL)
        return (NULL);
    settings->volume = 75;
    settings->fps = 60;
    settings->player = 1;
    init_default_skeys(settings);
    update_settings_with_args(settings, args);
    return (settings);
}