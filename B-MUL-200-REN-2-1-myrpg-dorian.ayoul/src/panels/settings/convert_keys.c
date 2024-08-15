/*
** EPITECH PROJECT, 2021
** handle key change
** File description:
** handle key
*/

#include <engine.h>
#include <panel.h>
#include <buttons.h>
#include <objects.h>
#include <envdata.h>
#include <rpg/rpg.h>
#include <SFML/Audio.h>

const size_t keyconv_count = 41;

const keyconv_t keyconvs[] = {
        {sfKeyA, 'A'},
        {sfKeyB, 'B'},
        {sfKeyC, 'C'},
        {sfKeyD, 'D'},
        {sfKeyE, 'E'},
        {sfKeyF, 'F'},
        {sfKeyG, 'G'},
        {sfKeyH, 'H'},
        {sfKeyI, 'I'},
        {sfKeyJ, 'J'},
        {sfKeyK, 'K'},
        {sfKeyL, 'L'},
        {sfKeyM, 'M'},
        {sfKeyN, 'N'},
        {sfKeyO, 'O'},
        {sfKeyP, 'P'},
        {sfKeyQ, 'Q'},
        {sfKeyR, 'R'},
        {sfKeyS, 'S'},
        {sfKeyT, 'T'},
        {sfKeyU, 'U'},
        {sfKeyV, 'V'},
        {sfKeyW, 'W'},
        {sfKeyX, 'X'},
        {sfKeyY, 'Y'},
        {sfKeyZ, 'Z'},
        {sfKeyNum0, '0'},
        {sfKeyNum1, '1'},
        {sfKeyNum2, '2'},
        {sfKeyNum3, '3'},
        {sfKeyNum4, '4'},
        {sfKeyNum5, '5'},
        {sfKeyNum6, '6'},
        {sfKeyNum7, '7'},
        {sfKeyNum8, '8'},
        {sfKeyNum9, '9'},
        {sfKeyEscape, '='},
        {sfKeyLeft, '<'},
        {sfKeyUp, '^'},
        {sfKeyRight, '>'},
        {sfKeyDown, 'v'}
};

char get_converted_key(sfKeyCode code)
{
    for (size_t i = 0; i < keyconv_count; ++i) {
        if (code == keyconvs[i].code)
            return (keyconvs[i].shown_key);
    }
    return ('\0');
}

sfkeycode_t get_key_code(char *str)
{
    if (!str)
        return (-1);
    for (size_t i = 0; i < keyconv_count; ++i) {
        if (str[0] == keyconvs[i].shown_key)
            return (keyconvs[i].code);
    }
    return (-1);
}