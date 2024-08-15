/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** get_screenshot_name
*/

#include <rpg/rpg.h>
#include <dirent.h>

char *get_screenshot_name(void)
{
    int id = 1;
    DIR *dir = opendir("./screenshots/");
    struct dirent *info;
    char *name = "screencapture-";

    if (dir == NULL)
        return (NULL);
    for (; (info = readdir(dir)); ) {
        if (!str_endswith(info->d_name, ".png"))
            continue;
        ++id;
    }
    closedir(dir);
    name = append_str(append_str(name, int_to_str(id)), ".png");
    return (name);
}