#include "iencli.h"

int client_action_mng(client_t *client, game_t *game, char *msg)
{
    if (strncmp(msg, "HELLO", 5) == 0) {
        game->id = atoi(msg + 6);
    } else if (strncmp(msg, "LIFE", 4) == 0) {
        updateLifePlayer(game, atoi(msg + 5), atoi(strchr(msg + 5, ' ') + 1));
    } else if (strncmp(msg, "KILL", 4) == 0) {
        updateKillPlayer(game, atoi(msg + 5));
    } else if (strncmp(msg, "BULLET", 6) == 0) {
        addProjectileToGame(game, msg + 7);
    } else if (strncmp(msg, "INFO", 4) == 0) {
        addInfoPlayerToGame(game, msg + 5);
    } else if (strncmp(msg, "DEAD", 4) == 0) {
        removePlayerFromGame(game, atoi(msg + 5));
    } else if (strncmp(msg, "ITEM", 4) == 0) {
        removeItemFromGame(game, atof(msg + 5), atof(strchr(msg + 5, ' ') + 1));
    }
    return 0;
}
