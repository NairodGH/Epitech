/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "includes.h"

void free_everything(kidiot_t *kidiot)
{
    free_double_tab(kidiot->first_floor);
    free_double_tab(kidiot->second_floor);
    UnloadSound(kidiot->use);
    for (size_t i = 0; i != 4; UnloadTexture(kidiot->textures[i]), i++);
    free(kidiot->baby->bathtub);
    free(kidiot->baby->electric);
    free(kidiot->baby->oven);
    free(kidiot->baby->cactus);
    free(kidiot->baby->fridge);
    free(kidiot->baby->vacuum);
    free(kidiot->baby->microwave);
    free(kidiot->tp);
    free(kidiot->baby);
    free(kidiot->mom);
    free(kidiot);
}

static void get_keys(int *keys)
{
    if (IsKeyDown(KEY_RIGHT)) keys[0] = 1;
    if (IsKeyDown(KEY_LEFT)) keys[1] = 1;
    if (IsKeyDown(KEY_UP)) keys[2] = 1;
    if (IsKeyDown(KEY_DOWN)) keys[3] = 1;
    if (IsKeyDown(KEY_ENTER)) keys[4] = 1;
    if (IsKeyDown(KEY_D)) keys[5] = 1;
    if (IsKeyDown(KEY_A)) keys[6] = 1;
    if (IsKeyDown(KEY_W)) keys[7] = 1;
    if (IsKeyDown(KEY_S)) keys[8] = 1;
    if (IsKeyDown(KEY_SPACE)) keys[9] = 1;
}

int args_invalid(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-h")) {
        printf("%s[KIDIOT]%s\n\tBasically a 2D \"Who's your daddy\" ", Y, W);
        printf("coded in 2 days in C with the raylib.\n\tIt's an Epitech ");
        printf("GameJam (20/05/2022) project made by Dorian AYOUL and Xavier ");
        printf("TONNELLIER.\n\n%s[ARGUMENTS]%s\n\t-h\thelp\n\t[width] ", G, W);
        printf("[height] [gametime]\tstart the game with a valid screen ");
        printf("width/height/gametime\n\n%s[CONTROLS]%s\n\tBaby:\n\t", B, W);
        printf("Z\tgo up\n\tQ\tgo left\n\tS\tgo down\n\tD\tgo right\n\tSPACE");
        printf("\tinteract\n\n\tMom:\n\tUP ARROW\tgo up\n\tLEFT ARROW\tgo ");
        printf("left\n\tDOWN ARROW\tgo down\n\tRIGHT ARROW\tgo right\n\t");
        return printf("ENTER\tinteract\n\nCheck the readme for more info\n");
    }
    if (ac != 4)
        return fprintf(stderr, "%s[ERROR]%s Invalid number of args\n", R, W);
    for (size_t i = 1; i < 4; i++)
        for (size_t j = 0; av[i][j] != '\0'; j++)
            if (!isdigit(av[i][j]))
                return fprintf(stderr, "%s[ERROR]%s Invalid arg value\n", R, W);
    return 0;
}

void main_loop(kidiot_t *kidiot)
{
    int save_hp = kidiot->baby->hp;
    char *time = NULL;

    for (int keys[10] = {0}; !WindowShouldClose() || kidiot->game_time <= 0;) {
        get_keys(keys);
        kidiot->keys = keys;
        if (game_loop(kidiot, keys) || kidiot->game_time < 0)
            break;
        BeginDrawing();
        ClearBackground(BROWN);
        draw_map(kidiot, GetScreenHeight(), GetScreenWidth());
        DrawRectangle(15, GetScreenHeight() / 100, (int)kidiot->baby->hp,
            GetScreenHeight() / 25, GREEN);
        asprintf(&time, "game time left : %0.1fs", kidiot->game_time);
        DrawText(time, GetScreenWidth() / 2, GetScreenHeight() / 100,
            GetScreenHeight() / 20, WHITE);
        free(time);
        gest_clock(kidiot, keys);
        EndDrawing();
        for (size_t i = 0; i != 10; keys[i] = 0, i++);
    }
}

int main(int ac, char **av)
{
    int save_hp = 0;
    kidiot_t *kidiot;

    SetTraceLogLevel(LOG_NONE);
    if (args_invalid(ac, av))
        return 84;
    InitWindow(atoi(av[1]), atoi(av[2]), "Kidiot");
    InitAudioDevice();
    kidiot = init_kidiot(read_map("map/first_floor.txt"),
        read_map("map/second_floor.txt"), atoi(av[3]));
    SetTargetFPS(60);
    main_loop(kidiot);
    if (kidiot->game_time < 0)
        end_screen(0, kidiot, (Vector2){0, 0});
    else if (kidiot->baby->hp <= 0)
        end_screen(1, kidiot, (Vector2){0, 0});
    free_everything(kidiot);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}