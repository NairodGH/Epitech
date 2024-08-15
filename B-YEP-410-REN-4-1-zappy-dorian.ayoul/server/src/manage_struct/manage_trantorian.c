/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "trantorian.h"

static char *trantorian_get_uuid(void)
{
    uuid_t temp = {0};
    char *buff = NULL;

    uuid_generate_time_safe(temp);
    buff = calloc(sizeof(unsigned char), UUID_STR_LEN);
    if (buff == NULL)
        return NULL;
    uuid_unparse(temp, buff);
    return buff;
}

static void trantorian_set_pos(trantorian_t *trantorian, size_t map_x,
    size_t map_y, bool rand_pos)
{
    if (rand_pos) {
        trantorian->pos.x = rand() % map_x;
        trantorian->pos.y = rand() % map_y;
    } else {
        trantorian->pos.x = map_x;
        trantorian->pos.y = map_y;
    }
}

trantorian_t *trantorian_create(team_t *team, size_t map_x, size_t map_y,
    bool rand_pos)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    if (!trantorian)
        return NULL;
    trantorian->uuid = trantorian_get_uuid();
    trantorian->team = team;
    trantorian_set_pos(trantorian, map_x, map_y, rand_pos);
    trantorian->inventory = inventory_create();
    if (trantorian->inventory == NULL || trantorian->uuid == NULL) {
        trantorian_destroy(trantorian);
        return NULL;
    }
    trantorian->inventory->food = TRANT_INIT_FOOD;
    trantorian->level = 1;
    trantorian->direction = rand() % DIR_SIZE;
    printf("[INFO] Trantorian %s created\n", trantorian->uuid);
    return trantorian;
}

void trantorian_destroy(trantorian_t *trantorian)
{
    if (trantorian == NULL)
        return;
    if (trantorian->uuid != NULL) {
        printf("[INFO] Trantorian %s destroyed\n", trantorian->uuid);
        free(trantorian->uuid);
    }
    if (trantorian->inventory)
        inventory_destroy(trantorian->inventory);
    free(trantorian);
}
