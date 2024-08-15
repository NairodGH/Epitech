/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

typedef struct {
    char **m;
    int h;
    int w;
} map;

int stat(map m, int mode);
int getnbr(char *str);
void putnbr(int nb);

int error(int ac, char **av);
int l_err(char *b, map m);
int m_err(char *b, int ln, map m, int n);

void ai(map m, int max);