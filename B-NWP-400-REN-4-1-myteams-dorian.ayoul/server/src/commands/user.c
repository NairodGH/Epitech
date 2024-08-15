/*
** EPITECH PROJECT, 2022
** user.c
** File description:
** user
*/

#include "server.h"

size_t get_len_list(lcli_t *list)
{
    size_t i = 0;

    while (list != NULL) {
        i++;
        list = list->next;
    }
    return i;
}

static void split_user(lcli_t *list, char *id, char *name, char *login)
{
    strcat(id, list->client->id);
    strcat(id, "|");
    strcat(name, (list->client->user_name == NULL)
        ? "(null)" : list->client->user_name);
    strcat(name, "|");
    strcat(login, (list->client->is_login == true ? "1" : "0"));
    strcat(login, "|");
}

static void end_user(lcli_t *save, char *id, char *name, char *login)
{
    id[strlen(id) - 1] = '\0';
    name[strlen(name) - 1] = '\0';
    login[strlen(login) - 1] = '\0';
    dprintf(save->client->fd, "207: <[%s][%s][%s]>", id, name, login);
    free(id);
    free(name);
    free(login);
}

int users(lcli_t *list, __attribute__((unused)) char **arg)
{
    size_t len_list = get_len_list(list->head);
    char *id = calloc(len_list * UUID_STR_LEN + 1, sizeof(char));
    char *name = calloc(len_list * MAX_NAME_LENGTH + 1, sizeof(char));
    char *login = calloc(len_list * 2 + 1, sizeof(char));
    lcli_t *save = list;

    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        free(id);
        free(name);
        free(login);
        return 1;
    }
    for (list = list->head; list != NULL; list = list->next)
        if (list->client->id != NULL && list->client->user_name)
            split_user(list, id, name, login);
    end_user(save, id, name, login);
    return 0;
}

int user(lcli_t *list, char **arg)
{
    int save_fd = list->client->fd;

    if (get_len_arg(arg) != 1) {
        dprintf(list->client->fd, "500: <Error args>");
        return 1;
    }
    if (list->client->is_login == false) {
        dprintf(list->client->fd, "502: <[Not login]>");
        return 1;
    }
    for (list = list->head; list != NULL; list = list->next) {
        if (list->client->id && strcmp(list->client->id, arg[0]) == 0) {
            dprintf(save_fd, "206: <[%s][%s][%s]>", list->client->id,
                (!list->client->user_name ? "NULL" : list->client->user_name),
                list->client->is_login ? "1" : "0");
            return 0;
        }
    }
    dprintf(save_fd, "501: <[%s]>", arg[0]);
    return 0;
}
