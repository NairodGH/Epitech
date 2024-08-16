#include "includes.h"

typedef struct {
    sound_e type;
    const char *path;
    float volume;
} relation_t;

static const relation_t relation[] = {
    {SOUND_WALK, "assets/sounds/walk.wav", 1.0f},
    {SOUND_HIT, "assets/sounds/hit.wav", 0.05f},
    {SOUND_SHOT, "assets/sounds/shot.wav", 0.5f},
    {SOUND_JUMP, "assets/sounds/jump.wav", 0.2f},
    {SOUND_AMMO, "assets/sounds/ammo.wav", 1.5f},
};

void initSounds(game_t *game)
{
    sound_t *sound = NULL;

    game->sound = list_create();
    for (size_t i = 0; i < sizeof(relation) / sizeof(relation_t); i++) {
        sound = calloc(1, sizeof(sound_t));
        sound->type = relation[i].type;
        sound->sound = LoadSound(relation[i].path);
        SetSoundVolume(sound->sound, relation[i].volume);
        list_push_data(game->sound, sound);
    }
}
