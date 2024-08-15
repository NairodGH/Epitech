/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "zappy_gui.h"

static const char *paths[] = {
    "gui/resources/fast.ttf",
    NULL
};

Font *get_font(void)
{
    static Font *fonts = NULL;
    size_t length = 0;

    if (!fonts) {
        for (; paths[length]; length++);
        fonts = malloc(sizeof(Font) * length);
        for (size_t i = 0; i < length; i++)
            fonts[i] = LoadFont(paths[i]);
    }
    return fonts;
}

void unload_fonts(Font *fonts)
{
    for (size_t i = 0; paths[i]; i++)
        UnloadFont(fonts[i]);
    free(fonts);
}
