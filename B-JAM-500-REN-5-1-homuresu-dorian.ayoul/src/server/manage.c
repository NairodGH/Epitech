#include "general.h"

static void send_death(server_tcp_t *server, client_t *client)
{
    char *msg = malloc(sizeof(char) * 100);

    sprintf(msg, "DEAD %i", client->sock);
    send_msg_to_all_cli_exepct_cli(server, client, msg);
    free(msg);
}

int manage_tcp_recv_actions(server_tcp_t *server, client_t *client)
{
    int check = 0;
    char *msg = get_tcp_packet(client->sock);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port);
        send_death(server, client);
        return 1;
    } else {
        printf("Message from %s:%i : %s\n", client->ip, client->port, msg);
        check = client_action_mng(server, client, msg);
    }
    free(msg);
    return check;
}

int manage_udp_recv_actions(server_udp_t *server, client_t *client)
{
    int check = 0;
    char *msg = get_udp_packet(server->sock);

    if (msg == NULL) {
        printf("-? %s:%i\n", client->ip, client->port);
        return 1;
    } else {
        printf("Message from %s:%i : %s\n", client->ip, client->port, msg);
        //! ACTION EN FONCTION DU MESSAGE UDP
        if (strcmp(msg, "hello") == 0) {
            if (send_udp_packet(client->sock, "Hello World from UDP", EOF_NETWORK, client) != 0)
                return 84;
        }
    }
    free(msg);
    return check;
}
