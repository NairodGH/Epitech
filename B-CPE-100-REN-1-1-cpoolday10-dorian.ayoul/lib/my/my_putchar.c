/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** puts a char depending on parameter
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}