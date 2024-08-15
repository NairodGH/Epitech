/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "zappy_gui.h"

static const char *paths[] = {
    "gui/resources/grass.png",
    "gui/resources/chicken.png",
    "gui/resources/linemate.png",
    "gui/resources/deraumere.png",
    "gui/resources/sibur.png",
    "gui/resources/mendiane.png",
    "gui/resources/phiras.png",
    "gui/resources/thystame.png",
    "gui/resources/1.png",
    "gui/resources/2.png",
    "gui/resources/3.png",
    "gui/resources/4.png",
    "gui/resources/5.png",
    "gui/resources/6.png",
    "gui/resources/7.png",
    "gui/resources/sky.png",
    "gui/resources/incantation.png",
    "gui/resources/explosion.png",
    "gui/resources/smoke.png",
    NULL
};

void unclick_rest(client_t *client, pos_t tile)
{
    for (int y = 0; y < client->size_map.y; y++)
        for (int x = 0; x < client->size_map.x; x++)
            (!(y == tile.y && x == tile.x)) ?
                client->map[y][x].clicked = false : 0;
}

int levels_nb(client_t *client, pos_t pos, int level)
{
    int tmp = 0;

    for (node_t *k = client->map[pos.y][pos.x].player->head; k; k = k->next)
        if (((player_t *)k->data)->level == level)
            tmp++;
    return tmp;
}

int get_item(map_t tile, const char *name)
{
    if (!strcmp(name, "food"))
        return tile.inv->food;
    if (!strcmp(name, "linemate"))
        return tile.inv->linemate;
    if (!strcmp(name, "deraumere"))
        return tile.inv->deraumere;
    if (!strcmp(name, "sibur"))
        return tile.inv->sibur;
    if (!strcmp(name, "mendiane"))
        return tile.inv->mendiane;
    if (!strcmp(name, "phiras"))
        return tile.inv->phiras;
    if (!strcmp(name, "thystame"))
        return tile.inv->thystame;
    return 0;
}

Texture *get_textures(void)
{
    static Texture *textures = NULL;
    size_t length = 0;

    if (!textures) {
        for (; paths[length]; length++);
        textures = malloc(sizeof(Texture) * length);
        for (size_t i = 0; i < length; i++)
            textures[i] = LoadTexture(paths[i]);
    }
    return textures;
}

void unload_textures(Texture *textures)
{
    for (size_t i = 0; paths[i]; i++)
        UnloadTexture(textures[i]);
    free(textures);
}
