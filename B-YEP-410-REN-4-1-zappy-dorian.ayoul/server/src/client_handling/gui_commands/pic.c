/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main server
*/

#include "utils.h"
#include "core.h"

static char *put_uuid_in_buff(list_t *trant, char *buff)
{
    node_t *node = NULL;
    trantorian_t *trantorian = NULL;
    char *temp = NULL;

    foreach(trant->head, node) {
        trantorian = (trantorian_t *)node->data;
        temp = buff;
        if (asprintf(&buff, "%s %s", buff, trantorian->uuid) == -1) {
            fprintf(stderr, "[ERROR] GUI Can't malloc\n");
            return NULL;
        }
        free(temp);
    }
    temp = buff;
    if (asprintf(&buff, "%s\n", buff) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return NULL;
    }
    free(temp);
    return buff;
}

void command_pic(core_t *core, trantorian_t *trantorian, list_t *trant)
{
    char *buff = NULL;

    if (asprintf(&buff, "pic %ld %ld %ld",
            trantorian->pos.x,
            trantorian->pos.y,
            trantorian->level) == -1) {
        fprintf(stderr, "[ERROR] GUI Can't malloc\n");
        return;
    }
    buff = put_uuid_in_buff(trant, buff);
    if (buff == NULL)
        return;
    client_gui_broadcast_command(core->server, buff);
}
