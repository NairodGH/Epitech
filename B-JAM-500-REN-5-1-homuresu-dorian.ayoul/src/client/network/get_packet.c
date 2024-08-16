#include "iencli.h"

static int check_eof(char *msg, ssize_t size)
{
    if (size >= 2 && memcmp(msg + size - 2, EOF_NETWORK, 2) == 0) {
        msg[size - 2] = '\0';
        return 1;
    }
    return 0;
}

char *get_tcp_packet(int sock)
{
    char *msg = NULL;
    char buffer[BUFFER_SIZE];
    ssize_t size_read = 0;
    ssize_t size = 0;

    while (true) {
        if ((size_read = read(sock, buffer, BUFFER_SIZE)) <= 0) {
            printf("Warning : Client read intterupted\n");
            return NULL;
        }
        if ((msg = realloc(msg, size + size_read + 1)) == NULL)
            return NULL;
        memcpy(msg + size, buffer, size_read);
        msg[size + size_read] = '\0';
        size += size_read;
        if (check_eof(msg, size) != 0)
            break;
    }
    return msg;
}

char *get_udp_packet(int sock)
{
    char *msg = NULL;
    char buffer[BUFFER_SIZE];
    ssize_t size_read = 0;
    ssize_t size = 0;

    while (true) {
        if ((size_read = recvfrom(sock, buffer, BUFFER_SIZE, MSG_DONTWAIT,
            NULL, NULL)) <= 0) {
            printf("Warning : Client read intterupted\n");
            return NULL;
        }
        if ((msg = realloc(msg, size + size_read + 1)) == NULL)
            return NULL;
        memcpy(msg + size, buffer, size_read);
        msg[size + size_read] = '\0';
        size += size_read;
        if (check_eof(msg, size) != 0)
            break;
    }
    return NULL;
}
