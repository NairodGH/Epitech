#include "iencli.h"

static char *set_send_opt(char const *msg, char const *eof)
{
    char *message = calloc(strlen(msg) + 3, sizeof(char));
    
    if (message == NULL)
        return NULL;
    strcpy(message, msg);
    strcat(message, eof);
    return message;
}

int send_tcp_packet(int sock, char const *msg, char const *eof)
{
    char *message = NULL;
    ssize_t write_size = 0;
    ssize_t size = 0;
    ssize_t current = 0;

    if (msg == NULL)
        return 84;
    if ((message = set_send_opt(msg, eof)) == NULL)
        return 84;
    size = strlen(message);
    do {
        write_size = write(sock, message + current, size - current);
        if (write_size == -1) {
            printf("Error: write failed\n");
            return 84;
        }
        current += write_size;
    } while (current < size);
    free(message);
    return 0;
}

int send_udp_packet(int sock, char const *msg, char const *eof, client_t *client)
{
    char *message = NULL;
    ssize_t write_size = 0;
    ssize_t size = 0;
    ssize_t current = 0;

    if (msg == NULL)
        return 84;
    if ((message = set_send_opt(msg, eof)) == NULL)
        return 84;
    size = strlen(message);
    do {
        write_size = sendto(sock, message + current, size - current, 0, (struct sockaddr *)&client->addr_udp, sizeof(client->addr_udp));
        if (write_size == -1) {
            printf("Error: write failed\n");
            return 84;
        }
        current += write_size;
    } while (current < size);
    free(message);
    return 0;
}