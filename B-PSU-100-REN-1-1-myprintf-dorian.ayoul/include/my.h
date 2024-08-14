/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Header file containing all prototypes of libmy.a functions
*/

void my_putchar(char c, char **flags);
int my_strlen(char *str);
char *my_revstr(char *str);
void my_putstr(char *str, char unprintable, char **flags);
long signed_lengths(long nb, char **flags);
long signed_interactions(long nb, char **flags, char *res, int j);
void unsigned_lengths(unsigned long nb, char **flags, char *res, int i);
void alternate_form(char cases, char **flags, char *res);
void padding(char **flags, char *res);
void my_putint(int long nb, char **flags);
void my_putoct(unsigned long nb, char **flags);
void my_putuns(unsigned long nb, char **flags);
void my_puthex(unsigned long nb, char cases, char **flags);
void my_putbin(unsigned long nb, char **flags);