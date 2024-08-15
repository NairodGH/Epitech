/*
** EPITECH PROJECT, 2021
** check_assets.c
** File description:
** Check assets
*/

#include <rpg/rpg.h>
#include <nep/nstring.h>
#include <nep/nprintf.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <file_utils.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

PRIVATE bool is_file_and_exists(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat st;
    int st_callback = -1;

    if (fd < 0)
        return (false);
    st_callback = stat(path, &st);
    if (st_callback < 0)
        return (false);
    if (!S_ISREG(st.st_mode))
        return (false);
    close(fd);
    return (true);
}

bool check_assets(void)
{
    char *cont = read_file(".assets");
    char **files = my_strtok(cont, '\n');

    if (!cont || !files) {
        nprintf("File .assets not found. Cannot open the game.\n");
        return (false);
    }
    for (uint itr = 0; files[itr]; itr++) {
        if (!is_file_and_exists(files[itr])) {
            nprintf("Needed file '%s' doesn't exist.\n", files[itr]);
            nprintf("Can't open the game.\n");
            return (false);
        }
        free(files[itr]);
    }
    free(files);
    free(cont);
    return (true);
}