#include "iencli.h"

void createProjectile(game_t *game, float speed, float size)
{
    projectile_t *new = calloc(1, sizeof(projectile_t));
    char *msg = calloc(300, sizeof(char));

    new->position = game->camera.position;
    new->direction = Vector3Normalize(Vector3Subtract((Vector3){game->camera.target.x, game->camera.target.y, game->camera.target.z}, new->position));
    new->speed = speed;
    new->size = size;
    new->model = *getModel(game->model, MODEL_BATARANG);
    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    new->id = game->id;
    list_push_data(game->projectile, new);
    game->stat->lastShoot = time(NULL);
    game->stat->ammo--;
    #ifndef _WIN32
    sprintf(msg, "BULLET %d %f %f %f %f %f %f %f %f", game->id, new->position.x, new->position.y, new->position.z,
                    new->direction.x, new->direction.y, new->direction.z, new->speed, new->size);
    send_tcp_packet(game->socket, msg, EOF_NETWORK);
    #endif
}

void createAmmoBox(game_t *game, Vector3 pos)
{
    item_t *new = calloc(1, sizeof(item_t));

    new->position = pos;
    new->model = *getModel(game->model, MODEL_AMMO_BOX);
    new->height = 1.0f;
    new->width = 1.0f;
    new->length = 1.0f;
    new->name = "ammoBox";
    new->isAlive = true;
    list_push_data(game->item, new);
}

void addProjectileToGame(game_t *game, char *msg)
{
    char **tab = splitMsg(msg, " ");
    int id = atoi(tab[0]);
    projectile_t *new = calloc(1, sizeof(projectile_t));

    new->id = id;
    new->position = (Vector3){atof(tab[1]), atof(tab[2]), atof(tab[3])};
    new->direction = (Vector3){atof(tab[4]), atof(tab[5]), atof(tab[6])};
    new->speed = atof(tab[7]);
    new->size = atof(tab[8]);
    new->model = *getModel(game->model, MODEL_BATARANG);
    new->model.transform = MatrixMultiply(new->model.transform, MatrixRotateY(atan2(new->direction.x, new->direction.z)));
    new->isAlive = true;
    list_push_data(game->projectile, new);
}