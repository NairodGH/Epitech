#include "includes.h"

#ifndef _WIN32
#include "iencli.h"

client_t *client = NULL;

static int init_client(client_t *client, game_t *game)
{
    int check = 0;

    if ((check = init_client_tcp(client)) != 0)
        return check;
    if ((check = init_client_udp(client)) != 0)
        return check;
    if ((check = loop_client(client, game)) != 0)
        return check;
    return check;
}

int withNetwork(int ac, char **av)
{
    game_t *game = calloc(1, sizeof(game_t));
    int check = 0;

    InitAudioDevice();
    client = init_struct();
    if (client == NULL) {
        printf("Error: Client structure initialization failed\n");
        return 84;
    }
    if (ac != 3) {
        printf("Usage: ./homuresu ip port\n");
        return 84;
    }
    client->ip = strdup(av[1]);
    client->port_tcp = atoi(av[2]);
    client->port_udp = client->port_udp + 1;
    initGame(game);
    if ((check = init_client(client, game)) != 0) {
        free_memory(client);
        return check;
    }
    free(game);
    return 0;
}
#endif

void withoutNetworkLoop(game_t *game)
{
    float x = 0;

    while (!WindowShouldClose()) {
        #ifdef _WIN32
        if (anticheat()) {
            printf("Dommage Julien ! ;D");
            break;
        }
        #endif
        if (game->menu->is_menu) {
            if (menu(game->menu, &x) == 1)
               break;
        } else {
            updateGame(game);
            drawGame(game);
        }
    }
    CloseWindow();
}

void withoutNetwork()
{
    game_t *game = calloc(1, sizeof(game_t));

    initGame(game);
    withoutNetworkLoop(game);
    free(game);
}

int main(int ac, char **av)
{
    #ifdef _WIN32
    withoutNetwork();
    #else
    withNetwork(ac, av);
    #endif
    return 0;
}
