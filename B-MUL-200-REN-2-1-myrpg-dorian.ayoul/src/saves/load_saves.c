/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** load_saves
*/

#include <rpg/rpg.h>
#include <envdata.h>
#include <dirent.h>
#include <errno.h>

PRIVATE int get_save_count(void)
{
    DIR *dir = opendir("./saves/");
    struct dirent *info;
    int count = 0;

    if (dir == NULL)
        return (0);
    for (; (info = readdir(dir)); ) {
        if (!str_endswith(info->d_name, ".xml"))
            continue;
        ++count;
    }
    closedir(dir);
    return (count);
}

PRIVATE save_t **fill_saves(game_t *game, save_t **saves)
{
    DIR *dir = opendir("./saves/");
    struct dirent *info;
    int itr = 0;

    for (; (info = readdir(dir)); ) {
        if (!str_endswith(info->d_name, ".xml"))
            continue;
        saves[itr] = read_save(game, info->d_name);
        ++itr;
    }
    saves[itr] = NULL;
    closedir(dir);
    return (saves);
}

save_t **load_saves(game_t *game)
{
    int count = get_save_count();

    if (count == 0)
        return (NULL);
    save_t **saves = malloc(sizeof(save_t) * (count + 1));
    if (saves == NULL)
        return (NULL);
    saves = fill_saves(game, saves);
    return (saves);
}