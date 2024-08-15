/*
** EPITECH PROJECT, 2021
** delete_sound.c
** File description:
** Updates a sound
*/

#include <sounds.h>
#include <stdlib.h>

void delete_sound(sound_t *sound)
{
    if (sound == NULL)
        return;
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->buffer);
    free(sound);
}