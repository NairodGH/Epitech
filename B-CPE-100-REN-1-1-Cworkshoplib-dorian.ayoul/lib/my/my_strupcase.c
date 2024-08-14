/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Puts every letter of a string in it in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ('a' <= str[i] && str[i] <= 'z') {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}