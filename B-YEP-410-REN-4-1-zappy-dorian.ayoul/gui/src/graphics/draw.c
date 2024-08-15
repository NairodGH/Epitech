/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

static const char *items[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame",
    NULL
};

void draw_player(map_t tile, int ratio, pos_t pos)
{
    Rectangle tmp;
    node_t *node;

    foreach (tile.player->head, node) {
        if (node->data == NULL)
            continue;
        if (((player_t *)node->data)->dir == North)
            tmp = (Rectangle){0 + (int)(GetTime() * 10) % 3 * 32,
                0 + ((int)(GetTime() * 10) % 3 == 1 ? 95 : 0), 25, 30};
        if (((player_t *)node->data)->dir == East)
            tmp = (Rectangle){32, 0 + (int)(GetTime() * 10) % 3 * 31, 25, 30};
        if (((player_t *)node->data)->dir == South)
            tmp = (Rectangle){64, 32 + (int)(GetTime() * 10) % 3 * 31, 25, 30};
        if (((player_t *)node->data)->dir == West)
            tmp = (Rectangle){4, 32 + (int)(GetTime() * 10) % 3 * 31, 25, 30};
        DrawTexturePro(get_textures()[7 + ((player_t *)node->data)->level],
        tmp, (Rectangle){pos.x + ratio / 10, pos.y + ratio / 12, ratio, ratio},
            (Vector2){0, 0}, 0, RAYWHITE);
    }
}

void check_click(client_t *client, pos_t map, pos_t edge)
{
    Vector2 pos = GetMousePosition();
    pos_t tile = {floorf((pos.x - edge.x) * client->size_map.x / map.x),
        floorf((pos.y - edge.y) * client->size_map.y / map.y)};

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (0 <= tile.x && tile.x < client->size_map.x &&
            0 <= tile.y && tile.y < client->size_map.y)
            client->map[tile.y][tile.x].clicked =
            !client->map[tile.y][tile.x].clicked;
        unclick_rest(client, tile);
    }
}

void draw_inventory(client_t *client, pos_t pos, pos_t map, pos_t edge)
{
    if (client->map[pos.y][pos.x].clicked) {
        DrawText(TextFormat("TILE [%d;%d]", pos.x, pos.y), 0, 0, 50, BLACK);
        DrawText(TextFormat("TILE [%d;%d]", pos.x, pos.y),
            edge.x + map.x, 0, 50, BLACK);
        for (int level = 1; level <= 7; level++) {
            DrawTexturePro(get_textures()[7 + level],
                (Rectangle){64, 32 + (int)(GetTime() * 10) % 3 * 31, 25, 30},
                (Rectangle){0, level * 30 * 3, 25 * 3, 30 * 3},
                (Vector2){0, 0}, 0, RAYWHITE);
            DrawText(TextFormat("x%d", levels_nb(client, pos, level)), 25 * 3,
                level * 30 * 3, 50, BLACK);
        }
        for (int item = 1; item <= 7; item++) {
            DrawTexturePro(get_textures()[item], (Rectangle){0, 0, 16, 16},
                (Rectangle){edge.x + map.x, item * 16 * 4, 16 * 4, 16 * 4},
                (Vector2){0, 0}, 0, RAYWHITE);
            DrawText(TextFormat("x%d", get_item(client->map[pos.y][pos.x],
            items[item - 1])), edge.x + map.x + 64, item * 64, 50, BLACK);
        }
    }
}

void draw_map(client_t *client, int ratio, pos_t edge)
{
    for (int y = 0; y < client->size_map.y; y++) {
        for (int x = 0; x < client->size_map.x; x++) {
            client->map[y][x].clicked == true ?
                DrawTexturePro(get_textures()[0], (Rectangle){0, 0, 16, 16},
            (Rectangle){edge.x + x * ratio, edge.y + y * ratio, ratio, ratio},
            (Vector2){0, 0}, 0, GRAY) :
                DrawTexturePro(get_textures()[0], (Rectangle){0, 0, 16, 16},
            (Rectangle){edge.x + x * ratio, edge.y + y * ratio, ratio, ratio},
            (Vector2){0, 0}, 0, RAYWHITE);
        }
    }
}

void display(client_t *client)
{
    pos_t size = {GetScreenWidth(), GetScreenHeight()};
    pos_t ratios = {size.x / client->size_map.x, size.y / client->size_map.y};
    int ratio = ratios.x < ratios.y ? ratios.x : ratios.y;
    pos_t map = {client->size_map.x * ratio, client->size_map.y * ratio};
    pos_t edge = {(size.x - map.x) / 2, (size.y - map.y) / 2};

    BeginDrawing();
    DrawTexture(get_textures()[15], 0, 0, WHITE);
    ClearBackground(RAYWHITE);
    check_click(client, map, edge);
    draw_map(client, ratio, edge);
    draw_misc(client, ratio, map, edge);
    EndDrawing();
}
