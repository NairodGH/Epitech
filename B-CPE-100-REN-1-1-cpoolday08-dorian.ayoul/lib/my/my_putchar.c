/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** Puts a given char
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}