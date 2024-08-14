/*
** EPITECH PROJECT, 2020
** firtree
** File description:
** Function that displays a fir tree based on its given size
*/

#include <unistd.h>

int my_get_girth(int size)
{
    int i = 0;
    int branches = 1;
    int branch_height = 4;
    int girth_max = 1;

    while (i != size) {
        girth_max = girth_max + (2 * (branch_height - branches));
        branch_height++;
        if (i % 2 == 0)
            branches = branches + 1;
        i++;
    }
    return (girth_max);
}

int my_get_height(int size)
{
    int i = 0;
    int crown_height = 0;
    int branch_height = 4;

    while ( i != size ) {
        crown_height = crown_height + branch_height;
        branch_height++;
        i++;
    }
    return (crown_height);
}

int foliage(int branch)
{
    if (branch % 2 == 0)
        return (1);
    else
        return (0);
}

void my_draw_crown(int air, int leaf, int girth_max, int photo_air)
{
    air = 0;
    while (air != (girth_max / 2) - photo_air) {
        air++;
        my_putchar(' ');
    }
    leaf = 0;
    while (leaf != 1 + (photo_air * 2)) {
        leaf++;
        my_putchar('*');
    }
}

void my_create_crown(int size, int girth_max, int crown_height)
{
    int i = 0;
    int air;
    int leaf;
    int photo_air = 0;
    int branches = 0;
    int branch = 1;
    int twig = my_get_height(branch);

    while (i != crown_height) {
        if (i == twig) {
            branch = branch + 1;
            twig = my_get_height(branch);
            branches = branches + foliage(branch);
            photo_air = photo_air - (branches + 1);
        }
        my_draw_crown(air, leaf, girth_max, photo_air);
        i++;
        photo_air = photo_air + 1;
        my_putchar('\n');
    }
}

void my_draw_bole(int air, int bark, int girth_max, int trunk_width)
{
    air = 0;
    while (air != (girth_max / 2 - trunk_width / 2)) {
        air++;
        my_putchar(' ');
    }
    bark = 0;
    while (bark != trunk_width) {
        bark++;
        my_putchar('|');
    }
}

void my_create_bole(int size, int girth_max)
{
    int i = 0;
    int air;
    int bark;
    int trunk_width = size;
    int trunk_height = size;

    if (size % 2 == 0)
        trunk_width = trunk_width + 1;
    while (i != trunk_height) {
        my_draw_bole(air, bark, girth_max, trunk_width);
        i++;
        my_putchar('\n');
    }
}

void tree(int size)
{
    int girth_max = my_get_girth(size);
    int crown_height = my_get_height(size);

    if (size > 0) {
        my_create_crown(size, girth_max, crown_height);
        my_create_bole(size, girth_max);
    }
}