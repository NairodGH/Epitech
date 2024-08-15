/*
** EPITECH PROJECT, 2022
** parse_ret.c
** File description:
** parse_ret
*/

#include "client.h"

static const char *commands[] = {"/login", "/logout", "/user", "/users",
    "/send", "/help", "/messages", "/use", "/create", "/subscribe",
    "/unsubscribe", "/subscribed", "/list", "/info", NULL};

char *send_message_buff_split(char *mess, char *new_mess, size_t *i, size_t *s)
{
    if (mess == NULL)
        return NULL;
    new_mess = malloc(sizeof(char) * (strlen(mess) + 10));
    if (mess[0] != '/') {
        printf("invalid command\n");
        return NULL;
    }
    new_mess[0] = '<';
    while (mess[*i] != '\n' && mess[*i] != ' ' && mess[*i] != '\0') {
        new_mess[*s] = mess[*i];
        (*i)++;
        (*s)++;
    }
    return new_mess;
}

static bool free_send_messag(
    client_t *client, char *temp, char *new_mess, char *arg)
{
    dprintf(client->sockfd, temp);
    if (arg != NULL)
        free(arg);
    if (new_mess != NULL)
        free(new_mess);
    return true;
}

bool send_message_buff(client_t *client, char *message)
{
    char *new_mess = NULL;
    char *arg = NULL;
    size_t i = 1;
    size_t s = 1;

    if (!is_in_list(message, commands) ||
        !(new_mess = send_message_buff_split(message, new_mess, &i, &s)))
        return false;
    new_mess[s] = '>';
    new_mess[s + 1] = '\0';
    if (message[i] != '\0') {
        arg = recup_arg(message, &i);
        if (!arg) {
            free(new_mess);
            printf("Bad arg\n");
            return true;
        }
        return (free_send_messag(client, strcat(new_mess, arg), new_mess, arg));
    } else
        return (free_send_messag(client, new_mess, new_mess, arg));
}

static void split_parse_return(char *buffer, char *message, int value, size_t i)
{
    size_t s = 0;
    char **arg = NULL;
    char *temp = my_itoa(value);

    for (; buffer[i] != '\0' && buffer[i] != '>'; s++, i++)
        message[s] = buffer[i];
    message[s] = '\0';
    arg = create_arg(message);
    for (int i = 0; com[i].cmd != NULL; i++) {
        if (strcmp(com[i].cmd, temp) == 0) {
            com[i].func_ptr(arg);
            free_char(buffer, message, temp, arg);
            return;
        }
    }
    free_char(buffer, message, temp, arg);
}

void parse_return(char *buffer)
{
    size_t i = 0;
    int value = atoi(buffer);
    char *message = malloc(sizeof(char) * strlen(buffer));

    if (!message || value == 500) {
        if (message)
            free(message);
        free(buffer);
        return;
    }
    while (buffer[i] != '\0' && buffer[i] != '<')
        i++;
    if (buffer[i] == '\0') {
        free(message);
        printf("Message reçu : [%s]\n", buffer);
        free(buffer);
        return;
    }
    split_parse_return(buffer, message, value, (i + 1));
}
