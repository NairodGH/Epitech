/*
** EPITECH PROJECT, 2022
** load_data.c
** File description:
** load_data
*/

#include "server.h"

static char *malloc_word(char *buffer, size_t *i)
{
    char *word = NULL;
    size_t s = 0;

    while ((buffer[*i] == ' ' || buffer[*i] == '\t' || buffer[*i] == '\n')
        && buffer[*i] != '\0')
        (*i)++;
    s = *i;
    while (buffer[s] != '\t' && buffer[s] != ' ' && buffer[s] != '\0')
        s++;
    word = malloc(sizeof(char) * (s - (*i) + 1));
    if (!word)
        return NULL;
    return word;
}

static char *get_one_word(char *buffer, size_t *i)
{
    char *word = malloc_word(buffer, i);
    size_t s = 0;

    while (buffer[*i] != '\t' && buffer[*i] != ' '
        && buffer[*i] != '\n' && buffer[*i] != '\0') {
        word[s] = buffer[*i];
        (*i)++;
        s++;
    }
    word[s] = '\0';
    if (strcmp("(null)", word) == 0) {
        free(word);
        return NULL;
    }
    return word;
}

static void split_load_data(
    int fd, char *buffer, struct stat stats, clients_t *list_clients)
{
    int ret = read(fd, buffer, stats.st_size);
    size_t i = 0;

    if (ret == -1) {
        free(buffer);
        close(fd);
        return;
    }
    buffer[ret] = '\0';
    for (; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    for (size_t max = 0; max != MAX_CLIENT; max++) {
        list_clients[max].id = get_one_word(buffer, &i);
        list_clients[max].user_name = get_one_word(buffer, &i);
        if (list_clients[max].id && strcmp(list_clients[max].id, "null") != 0)
            server_event_user_loaded(list_clients[max].id,
                list_clients[max].user_name);
    }
    free(buffer);
    close(fd);
}

void load_data(clients_t *list_clients)
{
    int fd = open("database/client.txt", O_RDONLY);
    struct stat stats;
    char *buffer = NULL;

    if (fd == -1)
        return;
    if (stat("database/client.txt", &stats) != 0) {
        close(fd);
        return;
    }
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (!buffer) {
        close(fd);
        return;
    }
    split_load_data(fd, buffer, stats, list_clients);
}
