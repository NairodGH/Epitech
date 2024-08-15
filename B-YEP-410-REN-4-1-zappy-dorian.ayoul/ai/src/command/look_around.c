/*
** EPITECH PROJECT, 2022
** look_around.c
** File description:
** look_around ai
*/

#include "zappy_ai.h"

void fill_cell_map(map_t *map, char *content)
{
    reset_look_info(map);
    for (char *stone = NULL; (stone = get_one_word(content)); free(stone)) {
        if (strcmp(stone, "player") == 0)
            list_push_data(map->player, (create_player()));
        if (strcmp(stone, "food") == 0)
            map->inv->food++;
        if (strcmp(stone, "deraumere") == 0)
            map->inv->deraumere++;
        if (strcmp(stone, "linemate") == 0)
            map->inv->linemate++;
        if (strcmp(stone, "mendiane") == 0)
            map->inv->mendiane++;
        if (strcmp(stone, "phiras") == 0)
            map->inv->phiras++;
        if (strcmp(stone, "sibur") == 0)
            map->inv->sibur++;
        if (strcmp(stone, "thystame") == 0)
            map->inv->thystame++;
        content = go_next_chr(content, ' ');
    }
}

static size_t fix_dir(direction_e dir, size_t value, bool is_x)
{
    if (is_x) {
        if (dir == North || dir == South)
            return -(value);
        else
            return value;
    }
    if (dir == North)
        return -(value);
    else
        return value;
}

static void split_big_loop_look(
    client_t *client, size_t *save_x, size_t *save_y, int *count_x)
{
    direction_e dir = client->player->dir;
    size_t temp_x = ((dir == East || dir == West) ? *save_y : *save_x);
    size_t temp_y = ((dir == East || dir == West) ? *save_x : *save_y);
    size_t lvl = client->player->level;

    if ((int)(client->player->level * 2 + 1) == *count_x) {
        *save_y = change_pos(client, temp_y, fix_dir(dir, 1, false), false);
        *save_x = change_pos(client, temp_x, fix_dir(dir, 1 * lvl, true), true);
        *count_x = 0;
        client->player->level++;
    } else {
        (*count_x)++;
        if (dir == North || dir == South)
            *save_x = change_pos(client, temp_x, 1, true);
        else
            *save_y = change_pos(client, temp_x, fix_dir(dir, 1, true), true);
    }
}

static void big_loop_look(
    client_t *client, size_t *save_x, size_t *save_y, int *count_x)
{
    direction_e dir = client->player->dir;
    size_t temp_x = ((dir == East || dir == West) ? *save_y : *save_x);
    size_t temp_y = ((dir == East || dir == West) ? *save_x : *save_y);

    if (client->player->level == 1 && *count_x == -1) {
        *count_x = 0;
        if (dir == North || dir == South) {
            *save_x = change_pos(client, temp_x, fix_dir(dir, 1, true), true);
            *save_y = change_pos(client, temp_y, fix_dir(dir, 1, false), false);
        }
        else {
            *save_x = change_pos(client, temp_y, (dir == East ? 1 : -1), false);
            *save_y = change_pos(client, temp_y, fix_dir(dir, 1, false), false);
        }
        return;
    }
    split_big_loop_look(client, save_x, save_y, count_x);
}

int look_around(client_t *client, char *str)
{
    char *content = NULL;
    char *save = str;
    size_t save_level = client->player->level;
    size_t save_x = client->player->pos.x;
    size_t save_y = client->player->pos.y;

    client->player->level = 1;
    for (int count_x = -1; (content = get_cell(save)) != NULL; free(content)) {
        fill_cell_map(&client->map[save_y][save_x], content);
        big_loop_look(client, &save_x, &save_y, &count_x);
        if (save[0] == ',') {
            (char *)((size_t)save++);
            continue;
        }
        save = go_next_chr(save, ',');
        if (save)
            (char *)((size_t)save++);
    }
    client->player->level = save_level;
    return remove_false_player(client);
}
