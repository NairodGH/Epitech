#include "iencli.h"
#include "includes.h"

static void reset_fd(client_t *client)
{
    FD_ZERO(&client->read_fd);
    FD_ZERO(&client->write_fd);
    FD_SET(client->sock_tcp, &client->read_fd);
    FD_SET(client->sock_udp, &client->read_fd);
    FD_SET(client->sock_tcp, &client->write_fd);
    FD_SET(client->sock_udp, &client->write_fd);
}

static int loop_send_cli_tcp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 1};

    if (select(client->sock_tcp + 1, NULL,
        &client->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_tcp, &client->read_fd)) {
            if ((check = manage_tcp_send_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_send_cli_udp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_udp + 1, NULL,
        &client->write_fd, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_udp, &client->read_fd)) {
            if ((check = manage_udp_send_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_recv_cli_tcp(client_t *client, game_t *game)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_tcp + 1, &client->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_tcp, &client->read_fd)) {
            if ((check = manage_tcp_recv_actions(client, game)) != 0)
                return check;
        }
    }
    return check;
}

static int loop_recv_cli_udp(client_t *client)
{
    int check = 0;
    struct timeval timeout = {0, 100};

    if (select(client->sock_udp + 1, &client->read_fd,
        NULL, NULL, &timeout) >= 0) {
        if (FD_ISSET(client->sock_udp, &client->read_fd)) {
            if ((check = manage_udp_recv_actions(client)) != 0)
                return check;
        }
    }
    return check;
}

static char *sendInfoServer(game_t *game, char *msg)
{
    if (msg)
        free(msg);
    msg = malloc(sizeof(char) * 100);
    model_t *tempModel = game->menu->selection_menu->current->data;
    model_e model = getModelType(game->menu->selection_menu->elements, tempModel);
    sprintf(msg, "INFO %i %f %f %f %f %f %f %d %d %d", game->id,
        game->camera.position.x, game->camera.position.y - 2, game->camera.position.z,
        game->camera.target.x, game->camera.target.y, game->camera.target.z,
        game->stat->life, game->stat->score, model);
    return msg;
}

int loop_client(client_t *client, game_t *game)
{
    int check = 0;
    float x = 0;
    int time = 0;
    char *msg = NULL;
    game->socket = client->sock_tcp;

    while (!WindowShouldClose()) {
        if (game->menu->is_menu) {
            if (menu(game->menu, &x) == 1) {
                break;
            }
        } else {
            StopSound(game->menu->music);
            updateGame(game);
            drawGame(game);
            if (game->id != -1 && time % 3 == 0) {
                msg = sendInfoServer(game, msg);
                send_tcp_packet(client->sock_tcp, msg, EOF_NETWORK);
            }
        }
        reset_fd(client);
        if ((check = loop_recv_cli_tcp(client, game)) != 0)
            break;
        time++;
    }
    if (msg)
        free(msg);
    CloseWindow();
    return check;
}
