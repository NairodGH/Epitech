/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** display_entities
*/

#include <rpg/rpg.h>

float rfabs(float diff)
{
    if (diff < 0)
        return (-diff);
    return (diff);
}

float rfdiff(sfVector2f pos1, sfVector2f pos2)
{
    float diff = 0.f;

    diff += rfabs(pos1.x - pos2.x);
    diff += rfabs(pos1.y - pos2.y);
    return (diff / 16.f);
}

float get_entity_distance(panel_t *panel, game_t *game, sfVector2f epos)
{
    sfVector2f pos;
    obj_t *player;

    (void) game;
    player = get_player(panel);
    if (player == NULL)
        return (-1.f);
    pos = player->pos;
    return (rfdiff(pos, epos));
}