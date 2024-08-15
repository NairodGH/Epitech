/*
** EPITECH PROJECT, 2022
** commands3.c
** File description:
** commands3
*/

#include "ftp.h"

int list(client_t *client, char *path)
{
    DIR *d;

    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    dprintf(client->fd,
    "150 File status okay; about to open data connection.\r\n");
    if (!path)
        path = client->cwd;
    else
        path[strlen(path) - 1] = '\0';
    if (!(d = opendir(path)))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    for (struct dirent *dir; dir = readdir(d);)
        dprintf(client->fd, "%s\n", dir->d_name);
    closedir(d);
    return dprintf(client->fd, "226 Closing data connection.\r\n");
}

int stor(client_t *client, char *path)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (!path || strtok(NULL, " ") || !(path[strlen(path) - 1] = '\0')
        && access(strcat(strdup(client->cwd), basename(path)), F_OK))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    dprintf(client->fd,
    "150 File status okay; about to open data connection.\r\n");
    for (int fd[2] = {open(strcat(strdup(client->cwd), basename(path)), O_RDONLY
        ), open(path, O_CREAT | O_WRONLY, 0777)}, buff[BUFSIZ], size;;) {
        if (fd[0] < 0 || fd[1] < 0 || (size = read(fd[0], buff, BUFSIZ)) < 0)
            return dprintf(client->fd, "550 Requested action not taken.\r\n");
        if (!size) {
            close(fd[0]);
            close(fd[1]);
            break;
        }
        if (write(fd[1], buff, size) < 0)
            return dprintf(client->fd, "550 Requested action not taken.\r\n");
    }
    return dprintf(client->fd, "226 Closing data connection.\r\n");
}

int retr(client_t *client, char *path)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (!path || strtok(NULL, " ") ||
        !(path[strlen(path) - 1] = '\0') && access(path, F_OK))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    dprintf(client->fd,
    "150 File status okay; about to open data connection.\r\n");
    for (int fd[2] = {open(path, O_RDONLY), open(strcat(strdup(client->cwd),
        basename(path)), O_CREAT | O_WRONLY, 0777)}, buff[BUFSIZ], size;;) {
        if (fd[0] < 0 || fd[1] < 0 || (size = read(fd[0], buff, BUFSIZ)) < 0)
            return dprintf(client->fd, "550 Requested action not taken.\r\n");
        if (!size) {
            close(fd[0]);
            close(fd[1]);
            break;
        }
        if (write(fd[1], buff, size) < 0)
            return dprintf(client->fd, "550 Requested action not taken.\r\n");
    }
    return dprintf(client->fd, "226 Closing data connection.\r\n");
}

int noop(client_t *client)
{
    if (!client->connected[0] || !client->connected[1])
        return dprintf(client->fd, "530 Not logged in.\r\n");
    if (strtok(NULL, ""))
        return dprintf(client->fd, "550 Requested action not taken.\r\n");
    return dprintf(client->fd, "200 Command okay.\r\n");
}