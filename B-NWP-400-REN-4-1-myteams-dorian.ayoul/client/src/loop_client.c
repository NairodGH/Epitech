/*
** EPITECH PROJECT, 2022
** loop_client.c
** File description:
** loop_client
*/

#include "client.h"

bool *get_value(void)
{
    static bool value = false;
    
    return (&value);
}

void read_stdin(client_t *client, char *temp, char **buffer)
{
    bool first = (*buffer == NULL ? true : false);

    temp = get_inputs(buffer, &first);
    *buffer = realloc(*buffer,
        (*buffer == NULL ? 0 : strlen(*buffer)) + strlen(temp) + 1);
    if (first)
        (*buffer)[0] = '\0';
    if (send_message_buff(client, strcat(*buffer, temp))) {
        free(*buffer);
        *buffer = NULL;
    }
    free(temp);
}

bool split_loop_client(client_t *client, char **buffer)
{
    char *temp = NULL;

    if (FD_ISSET(STDIN_FILENO, &client->readfds)) {
        read_stdin(client, temp, buffer);
        return false;
    }
    if (FD_ISSET(client->sockfd, &client->readfds)) {
        temp = read_socket(client->sockfd);
        if (temp == NULL) {
            printf("Error malloc buffer\n");
            return true;
        }
        if (atoi(temp) == 100) {
            free(temp);
            return true;
        }
        parse_return(temp);
    }
    return false;
}

bool loop_client(client_t *client)
{
    int sel = 0;
    char *buffer = NULL;

    while (1) {
        FD_ZERO(&client->readfds);
        FD_ZERO(&client->writefds);
        FD_SET(STDIN_FILENO, &client->readfds);
        FD_SET(client->sockfd, &client->readfds);
        FD_SET(client->sockfd, &client->writefds);
        sel = select_fds(&client->readfds, &client->writefds);
        if (sel == -1 || *(get_value()))
            break;
        if (split_loop_client(client, &buffer))
            break;
    }
    if (buffer)
        free(buffer);
    return true;
}

int init_client(arg_t *arg)
{
    client_t *client = create_client(arg);

    if (connect(client->sockfd,
        (struct sockaddr *)&client->servaddr, sizeof(client->servaddr)) < 0) {
        printf("Error : Connect Failed \n");
        close(client->sockfd);
        free(client);
        free(arg);
        exit(84);
    }
    send_message(client, "200: <connected>");
    loop_client(client);
    send_message(client, "300: <disconnected>");
    close(client->sockfd);
    shutdown(client->sockfd, SHUT_RDWR);
    free(client);
    return 0;
}
