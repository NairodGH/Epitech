#include "includes.h"
#include "iencli.h"

char **splitMsg(char *msg, char *delim)
{
    char **tab = NULL;
    char *token = strtok(msg, delim);
    int i = 0;

    for (; token != NULL; i++) {
        tab = realloc(tab, sizeof(char *) * (i + 1));
        tab[i] = strdup(token);
        token = strtok(NULL, delim);
    }
    tab = realloc(tab, sizeof(char *) * (i + 1));
    tab[i] = NULL;
    return (tab);
}

void freeDoubleTab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

static player_t * createPlayer(int id, game_t *game, model_e type)
{
    player_t *player = calloc(1, sizeof(player_t));

    player->position = (Vector3){0, 0, 0};
    player->direction = (Vector3){0, 0, 0};
    player->isAlive = true;
    player->model.type = type;
    player->model.model = *getModel(game->model, player->model.type);
    printf("model: %d\n", player->model.type);
    player->id = id;
    player->stat.life = 100;
    player->stat.score = 0;
    return (player);
}

void addInfoPlayerToGame(game_t *game, char *msg)
{
    char **tab = splitMsg(msg, " ");
    int id = atoi(tab[0]);
    player_t *player = NULL;
    node_t *node = NULL;
    bool find = false;
    model_e type = atoi(tab[9]);

    foreach(game->player->head, node) {
        player = (player_t *)node->data;
        if (player->id == id) {
            find = true;
            break;
        }
    }
    if (!find) {
        player = createPlayer(id, game, type);
        list_push_data(game->player, player);
    }
    player->position.x = atof(tab[1]);
    player->position.y = atof(tab[2]);
    player->position.z = atof(tab[3]);
    player->direction.x = atof(tab[4]);
    player->direction.y = atof(tab[5]);
    player->direction.z = atof(tab[6]);
    player->stat.life = atoi(tab[7]);
    player->stat.score = atoi(tab[8]);
    player->idModel = type;
    freeDoubleTab(tab);
}

void removePlayerFromGame(game_t *game, int id)
{
    node_t *node = NULL;
    player_t *player = NULL;
    node_t *tmp = NULL;

    foreach_safe(game->player->head, node, tmp) {
        player = (player_t *)node->data;
        if (player->id == id) {
            list_remove_node(game->player, node);
            free(player);
            break;
        }
    }
}

static void checkDeath(game_t *game, int id)
{
    char *msg = NULL;

    if (game->stat->life <= 0) {
        game->camera.position = (Vector3){0, 0, 0};
        game->stat->life = 100;
        game->stat->score = 0;
        #ifndef _WIN32
        msg = calloc(1, 20);
        sprintf(msg, "DEAD %d", id);
        send_tcp_packet(game->socket, msg, EOF_NETWORK);
        #endif
    }
}

void updateKillPlayer(game_t *game, int id)
{
    game->stat->score += 1;
}

void updateLifePlayer(game_t *game, int id, int life)
{
    game->stat->life = game->stat->life + life;
    checkDeath(game, id);
}