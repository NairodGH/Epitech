/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** finish_achievement
*/

#include <rpg/rpg.h>
#include <file_utils.h>
#include <dirent.h>
#include <sounds.h>
#include <errno.h>

bool finish_achievement(game_t *game, int npc_id, enum achievement_type type)
{
    achievement_t *ach = get_npc_achievement(game, npc_id, type);

    if (ach == NULL)
        return (false);
    if (already_finished_achievement(game, ach->id))
        return (false);
    save_achievement(game, ach->id);
    set_obj_visibility(ach->obj, true);
    sfClock_restart(ach->obj->clock);
    if (ach->reward_xp > 0) {
        add_player_xp(game, ach->reward_xp);
    }
    play_seffect(game, game->engine, "assets/sounds/achievement-get.ogg");
    return (true);
}