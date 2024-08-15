/*
** EPITECH PROJECT, 2021
** sounds.h
** File description:
** Sounds prototypes
*/

#ifndef SOUNDS_H
#define SOUNDS_H

#include <engine.h>
#include <stdbool.h>
#include <SFML/Audio.h>

typedef struct engine_s engine_t;
typedef struct game_s game_t;

typedef struct sound_s {
    char *path;
    sfSound *sound;
    sfSoundBuffer *buffer;
    sfSoundStatus status;
    bool is_looped;
    float volume;
    float pitch;
} sound_t;

sound_t *create_sound(char *path, bool is_looped, float volume, float pitch);
void update_sound(sound_t *sound);
void delete_sound(sound_t *sound);
void register_sound(engine_t *eng, sound_t *sound);
void play_seffect(game_t *game, engine_t *eng, char *path);

char *get_sound_path(sound_t *sound);
sfsoundstatus_t get_sound_status(sound_t *sound);
float get_sound_volume(sound_t *sound);
float get_sound_pitch(sound_t *sound);

void set_sound_path(sound_t *sound, char *path);
void play_sound(sound_t *sound);
void pause_sound(sound_t *sound);
void stop_sound(sound_t *sound);
void set_sound_loop(sound_t *sound, bool is_looped);
void set_sound_volume(sound_t *sound, float volume);
void set_sound_pitch(sound_t *sound, float pitch);

void gc_sounds(engine_t *engine, bool force);

#endif //SOUNDS_H