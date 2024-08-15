/*
** EPITECH PROJECT, 2022
** commands.c
** File description:
** commands
*/

#include "ftp.h"

int quit(client_t *client)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    client->connected[0] = client->connected[1] = false;
    return dprintf(client->fd,
        "221 Service closing control connection.\r\n");
}

int cdup(client_t *client, char *home)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    strcpy(client->cwd, home);
    return dprintf(client->fd, "200 Command okay.\r\n");
}

int cwd(client_t *client, char *path)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (!path || strtok(NULL, " ") ||
        !(path[strlen(path) - 1] = '\0') && chdir(path) < 0)
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    strcpy(client->cwd, path);
    return dprintf(client->fd,
        "250 Requested file action okay, completed.\r\n");
}

int pass(client_t *client, char *password)
{
    if (!client->connected[0] && !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (client->connected[0] && client->connected[1] || !password ||
        strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    if (client->connected[1] && !strcmp(password, "\r") &&
        (client->connected[0] = true))
        return dprintf(client->fd, "230 User logged in, proceed.\r\n");
    client->connected[0] = client->connected[1] = false;
    return dprintf(client->fd, "530 Not logged in.\r\n");
}

int user(client_t *client, char *name)
{
    if (client->connected[0] && client->connected[1] || !name ||
        strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    if (!strcmp(name, "Anonymous\r")) {
        client->connected[0] = false;
        client->connected[1] = true;
    }
    else {
        client->connected[0] = true;
        client->connected[1] = false;
    }
    return dprintf(client->fd, "331 User name okay, need password.\r\n");
}