#include "includes.h"

void add_back(menu_t *menu_st);
Model getModelbyModel_t(list_t *list, model_t *model);
bool isModel(node_t *node, model_e type);

void selection_menu_loop(menu_t *menu)
{
    BeginDrawing();

    DrawTextureEx(menu->title, (Vector2){GetScreenWidth() - menu->title.width / 2, 10}, 0.0f, 0.5f, WHITE);

    DrawRectangle(10, 50, 500, 150, BLACK);
    DrawRectangleLines(10, 50, 500, 150, WHITE);
    DrawText("Selection Menu:", 25, 80, 20, WHITE);
    DrawText("Press RIGHT to change selection", 70, 120, 20, WHITE);
    DrawText("Press SPACE to select", 70, 140, 20, WHITE);
    DrawText("Press BACKSPACE to go back", 70, 160, 20, WHITE);

    menu->mousePoint = GetMousePosition();
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    DrawTextureEx(menu->soleil, (Vector2){menu->mousePoint.x - 44, menu->mousePoint.y - 44}, 0.0f, 0.2f, WHITE);
    EndDrawing();

    if (isModel(menu->selection_menu->current, MODEL_BATARANG)
        || isModel(menu->selection_menu->current, MODEL_AMMO_BOX)) {
        if (menu->selection_menu->current->next != NULL)
            menu->selection_menu->current = menu->selection_menu->current->next;
        else
            menu->selection_menu->current = menu->selection_menu->elements->head;
    }

    menu->camera.target = (Vector3){ 20.0f, 0.0f, 0.0f };
    BeginMode3D(menu->camera);
    add_back(menu);
    Model model = getModelbyModel_t(menu->selection_menu->elements, ((model_t *)menu->selection_menu->current->data));
    DrawModelEx(model, (Vector3){ 3.0f, 0.0f, 0.0f }, (Vector3){ 0.0f, 1.0f, 0.0f }, 90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
    EndMode3D();

    if (IsKeyPressed(KEY_RIGHT)) {
        if (menu->selection_menu->current->next != NULL)
            menu->selection_menu->current = menu->selection_menu->current->next;
        else
            menu->selection_menu->current = menu->selection_menu->elements->head;
    }
}
