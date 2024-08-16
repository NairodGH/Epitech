#include "server.h"

int client_action_mng(server_tcp_t *server, client_t *client, char *msg)
{
    if (strncmp(msg, "EXIT", 4) == 0) {
        if (send_tcp_packet(client->sock, "Hello World from TCP", EOF_NETWORK) != 0)
            return 84;
        return 1;
    } else if (strncmp(msg, "LIFE", 4) == 0) {
        send_tcp_packet(atof(msg + 5), msg, EOF_NETWORK);
    } else if (strncmp(msg, "INFO", 4) == 0) {
        send_msg_to_all_cli_exepct_cli(server, client, msg);
    } else if (strncmp(msg, "BULLET", 6) == 0) {
        send_msg_to_all_cli_exepct_cli(server, client, msg);
    } else if (strncmp(msg, "ITEM", 4) == 0) {
        send_msg_to_all_cli_exepct_cli(server, client, msg);
    } else if (strncmp(msg, "KILL", 4) == 0) {
        send_tcp_packet(atof(msg + 5), msg, EOF_NETWORK);
    }
    return 0;
}