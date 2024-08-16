#include <math.h>
#include "includes.h"

void selection_menu_loop(menu_t *menu);

static void put_dorian(menu_t *menu_st)
{
    DrawModelEx(menu_st->Dorion, (Vector3){-5.0f, 0.0f, -5.0f}, (Vector3){-1.0f , 1.0f, -1.0f}, menu_st->Spin_Dorion, (Vector3){1.0f , 1.0f, 1.0f}, WHITE);
    DrawModelEx(menu_st->Dorion, (Vector3){-5.0f, 0.0f, -27.0f}, (Vector3){-1.0f, 1.0f, -1.0f}, 105.0f, (Vector3){4.0f , 4.0f, 4.0f}, WHITE);
    DrawModelEx(menu_st->Dorion, (Vector3){-5.0f, 25.0f, 10.0f}, (Vector3){-2.0f , -2.0f, -2.0f}, 270.0f, (Vector3){5.0f , 5.0f, 5.0f}, WHITE);
    DrawModelEx(menu_st->Dorion, (Vector3){4.0f, 0.0f, 7.0f}, (Vector3){1.0f , -2.0f, -1.0f}, 80.0f, (Vector3){1.0f , 1.0f, 1.0f}, WHITE);
    DrawModelEx(menu_st->Dorion, (Vector3){5.0f, 0.0f, 5.0f}, (Vector3){0.0f , 0.0f, 0.0f}, 0.8f, (Vector3){1.0f , 1.0f, 1.0f}, WHITE);

    menu_st->Spin_Dorion += 1.0f;
}

static void menu_ui(menu_t *menu_st)
{
    BeginDrawing();
    DrawTextureRec(menu_st->button, menu_st->sourceRec, (Vector2){((GetMonitorWidth(GetCurrentMonitor()) / 2) - (menu_st->button.width / 3)),
    (GetMonitorHeight(GetCurrentMonitor()) - menu_st->button.height) - 50}, WHITE);

    if (CheckCollisionPointRec(menu_st->mousePoint, menu_st->btnBounds)) {
        menu_st->sourceRec.x = menu_st->button.width / 2;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu_st->selection_menu->selection = 1;
        }
    } else {
        menu_st->sourceRec.x = 0;
    }

    DrawTextureRec(menu_st->quit_button, menu_st->quit_sourceRec, (Vector2){menu_st->quit_position.x, menu_st->quit_position.y}, WHITE);
    DrawTextureEx(menu_st->soleil, (Vector2){menu_st->mousePoint.x - 44, menu_st->mousePoint.y - 44}, 0.0f, 0.2f, WHITE);

    if (CheckCollisionPointRec(menu_st->mousePoint, menu_st->quit_btnBounds)) {
        menu_st->quit_sourceRec.x = menu_st->quit_button.width / 2;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            menu_st->quit_position.x = rand() % (GetMonitorWidth(GetCurrentMonitor()) - menu_st->quit_button.width / 2);
            menu_st->quit_position.y = rand() % (GetMonitorHeight(GetCurrentMonitor()) - menu_st->quit_button.height);
            menu_st->quit_btnBounds = (Rectangle){menu_st->quit_position.x, menu_st->quit_position.y, menu_st->quit_button.width / 2, menu_st->quit_button.height};
        }
    } else {
        menu_st->quit_sourceRec.x = 0;
    }

    DrawTextureEx(menu_st->title, (Vector2){(GetMonitorWidth(GetCurrentMonitor()) - menu_st->title.width) / 2, 50}, 0.0f, 1.0f, WHITE);
    menu_st->mousePoint = GetMousePosition();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    EndDrawing();
}

void add_back(menu_t *menu_st)
{
    ClearBackground(SKYBLUE);

    DrawCubeTexture(menu_st->building, (Vector3){ 0.0f, 0.0f, -25.0f }, 50.0f, 20.0f, 0.1f, WHITE);
    DrawCubeTexture(menu_st->building, (Vector3){ 0.0f, 0.0f, 25.0f }, 50.0f, 20.0f, 0.1f, WHITE);
    DrawCubeTexture(menu_st->building, (Vector3){ -20.0f, 0.0f, 0.0f }, 0.1f, 20.0f, 50.0f, WHITE);
    DrawCubeTexture(menu_st->building, (Vector3){ 25.0f, 0.0f, 0.0f }, 0.1f, 20.0f, 50.0f, WHITE);
    DrawCubeTexture(menu_st->ground, (Vector3){ 0.0f, 0.0f, 0.0f }, 50.0f, 0.1f, 50.0f, WHITE);
}

static void check_mouse(void)
{
    if (GetMousePosition().x > GetScreenWidth())
        SetMousePosition(GetScreenWidth(), GetMousePosition().y);
    if (GetMousePosition().y > GetScreenHeight())
        SetMousePosition(GetMousePosition().x, GetScreenHeight());
    if (GetMousePosition().x < 0)
        SetMousePosition(0, GetMousePosition().y);
    if (GetMousePosition().y < 0)
        SetMousePosition(GetMousePosition().x, 0);
}

static void loopMusic(menu_t *menu_st)
{
    if (IsSoundPlaying(menu_st->music) == 0) {
        PlaySound(menu_st->music);
    }
}

int menu(menu_t *menu_st, float *x)
{
    check_mouse();

    loopMusic(menu_st);
    if (menu_st->selection_menu->selection == 0) {
        BeginMode3D(menu_st->camera);
        add_back(menu_st);
        put_dorian(menu_st);
        EndMode3D();
        menu_ui(menu_st);
        if (IsKeyPressed(KEY_ESCAPE)) {
            menu_st->is_menu = 0;
            return (1);
        }
        if (IsKeyPressed(KEY_SPACE))
            menu_st->selection_menu->selection = 1;
        menu_st->camera.target = (Vector3){sinf(*x) * 15.0f, 1.8f, cosf(*x) * 15.0f};
        (*x) += 0.01f;
    } else {
        selection_menu_loop(menu_st);
        if (IsKeyPressed(KEY_BACKSPACE))
            menu_st->selection_menu->selection = 0;
        if (IsKeyPressed(KEY_SPACE))
            menu_st->is_menu = 0;
    }
    return (0);
}
