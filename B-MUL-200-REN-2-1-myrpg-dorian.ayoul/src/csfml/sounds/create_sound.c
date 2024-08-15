/*
** EPITECH PROJECT, 2021
** create_sound.c
** File description:
** Create a sound
*/

#include <nep/nmem.h>
#include <sounds.h>

sound_t *create_sound(char *path, bool is_looped, float volume, float pitch)
{
    sound_t *sound;

    if (path == NULL)
        return (NULL);
    sound = ncalloc(1, sizeof(sound_t));
    if (sound == NULL)
        return (NULL);
    sound->path = path;
    sound->sound = sfSound_create();
    sound->buffer = sfSoundBuffer_createFromFile(sound->path);
    sound->status = sfStopped;
    sound->is_looped = is_looped;
    sound->volume = volume;
    sound->pitch = pitch;
    return (sound);
}