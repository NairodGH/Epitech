/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** Move player
*/

#include <engine.h>
#include <panel.h>
#include <sounds.h>
#include <objects.h>
#include <rpg/rpg.h>

PRIVATE void play_related_footstep(panel_t *pan, game_t *gm)
{
    int tile = get_player_tile(gm->stage->map, get_player(pan));

    if (tile >= GRASS_1 && tile <= GRASS_3) {
        play_seffect(gm, gm->engine, "assets/sounds/footstep-grass.ogg");
        return;
    }
    if (tile >= SAND_1 && tile <= SAND_10) {
        play_seffect(gm, gm->engine, "assets/sounds/footstep.ogg");
        return;
    }
    if (tile >= SNOW_1 && tile <= SNOW_4) {
        play_seffect(gm, gm->engine, "assets/sounds/footstep-snow.ogg");
        return;
    }
    if (tile >= WOOD_1 && tile <= WOOD_3) {
        play_seffect(gm, gm->engine, "assets/sounds/footstep-wood.ogg");
        return;
    }
    play_seffect(gm, gm->engine, "assets/sounds/footstep-grass.ogg");
}

void play_footsteps(panel_t *panel, game_t *game, player_t *player)
{
    sfClock *clock = NULL;
    sfInt64 time = 0;

    if (game == NULL || player == NULL)
        return;
    clock = player->movement_soundclock;
    if (clock == NULL)
        return;
    time = sfClock_getElapsedTime(player->movement_soundclock).microseconds;
    time /= 1000;
    if (time < 230)
        return;
    play_related_footstep(panel, game);
    sfClock_restart(player->movement_soundclock);
}