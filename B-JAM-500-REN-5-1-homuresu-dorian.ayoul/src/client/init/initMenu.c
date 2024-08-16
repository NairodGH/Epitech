#include "includes.h"

static void initSelectionMenu(game_t *game)
{
    game->menu->selection_menu = calloc(1, sizeof(selection_menu_t));

    game->menu->selection_menu->elements = game->model;
    game->menu->selection_menu->current = game->menu->selection_menu->elements->head;

    game->menu->selection_menu->selection = 0;
}

void initMenu(game_t *game)
{
    game->menu = calloc(1, sizeof(menu_t));
    game->menu->button = LoadTexture("./resources/menu/button.png");
    game->menu->button.width *= 5;
    game->menu->button.height *= 5;
    game->menu->sourceRec = (Rectangle){ 0, 0, (float)game->menu->button.width / 2, game->menu->button.height};

    game->menu->music = LoadSound("resources/menu/menu_music.wav");
    SetSoundVolume(game->menu->music, 0.1f);

    game->menu->btnBounds = (Rectangle){ (GetMonitorWidth(GetCurrentMonitor()) / 2) - (game->menu->button.width / 3),
    (GetMonitorHeight(GetCurrentMonitor()) - game->menu->button.height) - 50, game->menu->button.width / 2, game->menu->button.height};

    game->menu->quit_button = LoadTexture("./resources/menu/quit_button.png");
    game->menu->quit_button.width *= 5;
    game->menu->quit_button.height *= 5;
    game->menu->quit_sourceRec = (Rectangle){ 0, 0, (float)game->menu->quit_button.width / 2, game->menu->quit_button.height};

    game->menu->quit_position = (Vector2){((GetMonitorWidth(GetCurrentMonitor()) - game->menu->quit_button.width / 2)),
    0};

    game->menu->quit_btnBounds = (Rectangle){game->menu->quit_position.x,
    game->menu->quit_position.y, game->menu->quit_button.width / 2, game->menu->quit_button.height};

    game->menu->mousePoint = (Vector2){ 0.0f, 0.0f };
    game->menu->camera = (Camera){ 0 };
    game->menu->camera.position = (Vector3){ 0.0f, 1.8f, 0.0f };
    game->menu->camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    game->menu->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    game->menu->camera.fovy = 60.0f;
    game->menu->camera.projection = CAMERA_PERSPECTIVE;

    game->menu->is_menu = 1;

    game->menu->title = LoadTexture("./resources/menu/title_homuresu.png");
    game->menu->title.width *= 4;
    game->menu->title.height *= 4;

    game->menu->windowSize = game->windowSize;

    game->menu->building = LoadTexture("./resources/immeuble/immeuble1.png");

    game->menu->ground = LoadTexture("./resources/menu/grass.png");

    game->menu->Dorion = LoadModel("resources/dorion/Dorion.glb");
    game->menu->Dorion.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("resources/dorion/Dorion2.png");
    game->menu->Spin_Dorion = 0.0f;

    game->menu->soleil = LoadTexture("./resources/menu/Soleil.png");
    initSelectionMenu(game);
}
