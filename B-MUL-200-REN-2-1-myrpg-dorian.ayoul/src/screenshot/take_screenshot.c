/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** game_init
*/

#include <rpg/rpg.h>
#include <sounds.h>

void take_screenshot(engine_t *engine)
{
    sfImage *screenshot;
    sfRenderWindow *win = get_window(engine);
    sfVector2f winsize = get_window_size(engine);
    sfTexture *text = sfTexture_create(winsize.x, winsize.y);
    char *name = get_screenshot_name();

    if (name == NULL || text == NULL)
        return;
    play_seffect(engine->game, engine, "assets/sounds/screenshot.ogg");
    sfTexture_updateFromRenderWindow(text, win, 0, 0);
    screenshot = sfTexture_copyToImage(text);
    name = append_str("screenshots/", name);
    if (screenshot == NULL || name == NULL)
        return;
    sfImage_saveToFile(screenshot, name);
    sfTexture_destroy(text);
    sfImage_destroy(screenshot);
}