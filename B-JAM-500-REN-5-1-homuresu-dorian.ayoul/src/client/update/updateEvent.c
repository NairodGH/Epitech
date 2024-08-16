#include "includes.h"

typedef struct {
    KeyboardKey key;
    void (*func)(game_t *game, bool isPressed);
} keybind_t;

typedef struct {
    MouseButton button;
    void (*func)(game_t *game, bool isPressed);
} mousebind_t;

static const keybind_t keybinds[] = {
    {KEY_LEFT_SHIFT, sprint},
    {KEY_SPACE, jump},
    {KEY_W, walk},
    {KEY_A, walk},
    {KEY_S, walk},
    {KEY_D, walk}
};

static const mousebind_t mousebinds[] = {
    {MOUSE_BUTTON_LEFT, shoot},
};

static void updateBindings(game_t *game)
{
    for (size_t i = 0; i < sizeof(keybinds) / sizeof(keybinds[0]); i++) {
        if (IsKeyPressed(keybinds[i].key))
            keybinds[i].func(game, true);
        if (IsKeyReleased(keybinds[i].key))
            keybinds[i].func(game, false);
    }
    for (size_t i = 0; i < sizeof(mousebinds) / sizeof(mousebinds[0]); i++) {
        if (IsMouseButtonPressed(mousebinds[i].button))
            mousebinds[i].func(game, true);
        if (IsMouseButtonReleased(mousebinds[i].button))
            mousebinds[i].func(game, false);
    }
}

void updateEvent(game_t *game)
{
    updateBindings(game);
}
