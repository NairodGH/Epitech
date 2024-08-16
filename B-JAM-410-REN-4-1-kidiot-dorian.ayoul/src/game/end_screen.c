/*
** EPITECH PROJECT, 2022
** win_screen.c
** File description:
** win_screen
*/

#include "includes.h"

static void draw_mom_win(kidiot_t *kidiot, Vector2 orig)
{
    DrawText("Mom wins !",
        GetScreenWidth() / 2 - 10, GetScreenHeight() / 2, 20, GREEN);
    if ((int)(GetTime() * 5) % 2) {
        DrawTexturePro(kidiot->textures[0], (Rectangle){18, 103, 50, 80},
            (Rectangle){GetScreenWidth() - GetScreenWidth() / 3 * 2,
            GetScreenHeight() / 2, 50, 80}, orig, 0, RAYWHITE);
        DrawTexturePro(kidiot->textures[1], (Rectangle){35, 131, 34, 116},
            (Rectangle){GetScreenWidth() - GetScreenWidth() / 3,
            GetScreenHeight() / 2, 34, 116}, orig, 0, RAYWHITE);
    }
    else {
        DrawTexturePro(kidiot->textures[0], (Rectangle){19, 286, 62, 79},
            (Rectangle){GetScreenWidth() - GetScreenWidth() / 3 * 2,
            GetScreenHeight() / 2, 62, 79}, orig, 0, RAYWHITE);
        DrawTexturePro(kidiot->textures[1], (Rectangle){5, 392, 98, 116},
            (Rectangle){GetScreenWidth() - GetScreenWidth() / 3 - 30,
            GetScreenHeight() / 2, 98, 116}, orig, 0, RAYWHITE);
    }
}

static void draw_baby_win(kidiot_t *kidiot, Vector2 orig)
{
    DrawText("Maggie wins !",
        GetScreenWidth() / 2 - 10, GetScreenHeight() / 2, 20, RED);
    DrawTexturePro(kidiot->textures[0], (Rectangle){0 + (int)(GetTime() * 5)
        % 7 * 140, 640, 120, 100},
        (Rectangle){GetScreenWidth() - GetScreenWidth() / 3 * 2,
        GetScreenHeight() / 2, 120, 100}, orig, 0, RAYWHITE);
    DrawTexturePro(kidiot->textures[1], (Rectangle){0 + (int)(GetTime() * 5)
        % 9 * 140, 1020, 120, 125},
        (Rectangle){GetScreenWidth() - GetScreenWidth() / 3, GetScreenHeight()
        / 2, 120, 125}, orig, 0, RAYWHITE);
}

void end_screen(bool baby_win, kidiot_t *kidiot, Vector2 orig)
{
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        if (baby_win)
            draw_baby_win(kidiot, orig);
        else
            draw_mom_win(kidiot, orig);
        EndDrawing();
    }
}