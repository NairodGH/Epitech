/*
** EPITECH PROJECT, 2022
** message.c
** File description:
** message
*/

#include "server.h"

char *list_to_string(messages_t *l_message)
{
    char *message = NULL;
    size_t s = 0;

    if (!l_message || !l_message->head)
        return NULL;
    l_message = l_message->head;
    while (l_message != NULL) {
        s += strlen(l_message->message) + 1;
        l_message = l_message->next;
    }
    l_message = l_message->head;
    message = malloc(sizeof(char) * (s + 1));
    while (l_message != NULL) {
        strcat(message, l_message->message);
        strcat(message, "\n");
        l_message = l_message->next;
    }
    strcat(message, "\0");
    l_message = l_message->head;
    return message;
}

char *get_word_message(char *buff, size_t *i)
{
    char *message = NULL;
    size_t s = 0;
    size_t len = 0;

    for (s = *i; buff[s] != ']' && buff[s] != '\n' && buff[s] != '\0';
        s++, len++);
    message = malloc(sizeof(char) * (len + 1));
    if (!message)
        return NULL;
    for (s = 0; buff[*i] != ']' && buff[*i] != '\n' && buff[*i] != '\0';) {
        message[s] = buff[*i];
        (*i)++;
        s++;
    }
    for (; buff[*i] != '[' && buff[*i] != '\n' && buff[*i] != '\0'; (*i)++);
    if (buff[*i] == '[')
        (*i)++;
    message[s] = '\0';
    return message;
}

static void fill_message(messages_t *message, char *buffer, size_t *i)
{
    char *body = get_word_message(buffer, i);
    char *sender = get_word_message(buffer, i);
    char *receiver = get_word_message(buffer, i);
    char *temp_time = get_word_message(buffer, i);

    add_message(message, body, sender, receiver);
    message->time = (time_t)atol(temp_time);
    free(temp_time);
}

static messages_t *get_message(char *buffer, size_t size, int fd)
{
    messages_t *message = create_empty_message();
    size_t ret = read(fd, buffer, size);
    size_t i = 0;

    if (ret < 13)
        return message;
    buffer[ret] = '\0';
    for (i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    if (buffer[i] == '\0' || buffer[i + 1] == '\0')
        return message;
    for (; buffer[i] != '[' && buffer[i] != '\0'; i++);
    if (buffer[i] == '[')
        i++;
    for (; buffer[i] != '\0'; i++) {
        fill_message(message, buffer, &i);
        for (; buffer[i] != '\n' && buffer[i] != '\0'; i++);
    }
    return message;
}

messages_t *load_message(void)
{
    int fd;
    struct stat stats;
    char *buffer = NULL;
    messages_t *message = NULL;

    if (stat("database/message.txt", &stats) != 0)
        return NULL;
    fd = open("database/message.txt", O_RDONLY);
    if (fd == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (stats.st_size + 1));
    if (!buffer) {
        close(fd);
        return NULL;
    }
    message = get_message(buffer, stats.st_size, fd);
    free(buffer);
    close(fd);
    return message;
}
