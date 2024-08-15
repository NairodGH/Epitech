/*
** EPITECH PROJECT, 2021
** update_sound.c
** File description:
** Updates a sound
*/

#include <sounds.h>
#include <stdio.h>

void update_sound_status(sound_t *sound)
{
    sfSoundStatus st = sfSound_getStatus(sound->sound);

    if (sound->status == sfPlaying && st != sfPlaying) {
        sfSound_play(sound->sound);
        return;
    }
    if (sound->status == sfPlaying && st != sfPaused) {
        sfSound_pause(sound->sound);
        return;
    }
    if (sound->status == sfStopped && st != sfStopped) {
        sfSound_stop(sound->sound);
        return;
    }
}

void update_sound(sound_t *sound)
{
    if (sound == NULL || !sound->sound)
        return;
    sfSound_setBuffer(sound->sound, sound->buffer);
    sfSound_setLoop(sound->sound, sound->is_looped);
    sfSound_setVolume(sound->sound, sound->volume);
    sfSound_setPitch(sound->sound, sound->pitch);
    update_sound_status(sound);
}