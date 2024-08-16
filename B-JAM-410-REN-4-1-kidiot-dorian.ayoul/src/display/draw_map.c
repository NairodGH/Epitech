/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "includes.h"

void draw_cactus(kidiot_t *kidiot, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    for (size_t i = 0; kidiot->baby->cactus[i].floor != -1; i++)
        if ((int)kidiot->baby->cactus[i].pos.x == (int)pos.pos.y
            && (int)kidiot->baby->cactus[i].pos.y == (int)pos.pos.x
            && kidiot->baby->cactus[i].floor == pos.floor) {
            if (kidiot->baby->cactus[i].is_cut) {
                dest.height /= 2;
                dest.y += dest.height;
                DrawTexturePro(kidiot->textures[2],
                    (Rectangle){658, 0, 12, 12}, dest, orig, 0, RAYWHITE);
            }
            else
                DrawTexturePro(kidiot->textures[2],
                    (Rectangle){731, 0, 16, 18}, dest, orig, 0, RAYWHITE);
        }
}

void draw_elec(kidiot_t *kidiot, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    for (size_t i = 0; kidiot->baby->electric[i].floor != -1; i++)
        if ((int)kidiot->baby->electric[i].pos.x == (int)pos.pos.y
            && (int)kidiot->baby->electric[i].pos.y == (int)pos.pos.x
            && kidiot->baby->electric[i].floor == pos.floor)
            if (!kidiot->baby->electric[i].is_fixed)
                DrawTexturePro(kidiot->textures[3], (Rectangle)
                    {0 + (int)(GetTime() * 10) % 5 * 104, 0, 107, 87},
                dest, orig, 0, RAYWHITE);
}

void draw_misc_split(kidiot_t *kidiot, char cell, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    if (cell == 'V')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {439, 0, 21, 31}, dest, orig, 0, RAYWHITE);
    if (cell == 'W') {
        if (kidiot->tp->is_open[pos.floor])
            DrawTexturePro(kidiot->textures[2], (Rectangle)
                {585, 0, 27, 38}, dest, orig, 0, RAYWHITE);
        else
            DrawTexturePro(kidiot->textures[2], (Rectangle)
                {512, 0, 27, 38}, dest, orig, 0, RAYWHITE);
    }
    if (cell == 'Z')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {804, 0, 27, 55}, dest, orig, 0, RAYWHITE);
}

void draw_misc_spl(kidiot_t *kidiot, char cell, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    if (cell == 'M') {
        dest.height /= 2;
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {147, 0, 25, 20}, dest, orig, 0, RAYWHITE);
    }
    if (cell == 'O')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {220, 0, 31, 40}, dest, orig, 0, RAYWHITE);
    if (cell == 'S')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {1023, 0, 59, 58}, dest, orig, 0, RAYWHITE);
    if (cell == 'T') {
        dest.width *= 3;
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {0, 0, 73, 39}, dest, orig, 0, RAYWHITE);
    }
    draw_misc_split(kidiot, cell, dest, pos);
}

void draw_misc(kidiot_t *kidiot, char cell, Rectangle dest, pos_t pos)
{
    Vector2 orig = {0, 0};

    if (cell == '#')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {950, 0, 73, 58}, dest, orig, 0, RAYWHITE);
    if (cell == 'B') {
        if (kidiot->baby->bathtub->is_full[pos.floor])
            DrawTexturePro(kidiot->textures[2], (Rectangle)
                {293, 0, 30, 58}, dest, orig, 0, RAYWHITE);
        else
            DrawTexturePro(kidiot->textures[2], (Rectangle)
                {366, 0, 30, 58}, dest, orig, 0, RAYWHITE);
    }
    if (cell == 'C')
        draw_cactus(kidiot, dest, pos);
    if (cell == 'E')
        draw_elec(kidiot, dest, pos);
    if (cell == 'F')
        DrawTexturePro(kidiot->textures[2], (Rectangle)
            {74, 0, 28, 48}, dest, orig, 0, RAYWHITE);
    draw_misc_spl(kidiot, cell, dest, pos);
}
