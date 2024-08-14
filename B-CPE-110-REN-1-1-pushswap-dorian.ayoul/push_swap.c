/*
** EPITECH PROJECT, 2020
** push_swap
** File description:
** basically sorting a 10k list in 2sec with a 3 functions array program ;)
*/

#include <stdlib.h>
#include <unistd.h>

int buffer(char *c, char *str, int k)
{
    for (int i = 0; str[i] != '\0'; i++, k++)
        c[k] = str[i];
    return (k);
}

int push_swap(int *a, int *b, char *c, int ac)
{
    int j = 0;
    int k = 0;
    int s = ac / 4 * ac;
    int e = ac / 4 * ac + ac - 2;

    for (int m = 0, t = 0; e - s != 1;) {
        for (int i = s, min = 2147483647; i <= e; i++)
            (a[i] < min) && (min = a[i], m = i);
        while (s != m && m > s + (e - s) / 2) s--, t = a[s], a[s] = a[e],
            a[e] = t, (e == m) && (m = s), e--, k = buffer(c, "rra ", k);
        while (s != m && m <= s + (e - s) / 2)
            e++, t = a[s], a[s] = a[e], a[e] = t, s++, k = buffer(c, "ra ", k);
        t = a[s], a[s] = b[j], b[j] = t, j++, s++, k = buffer(c, "pb ", k);
    }
    for (int t = 0; a[s] > a[e] && t == 0;) t = a[s], a[s] = a[e], a[e] = t,
        j != 0 ? k = buffer(c, "sa ", k) : (k = buffer(c, "sa\n", k));
    for (int t = 0; j != 0;)
        s--, j--, t = a[s], a[s] = b[j], b[j] = t,
        j != 0 ? k = buffer(c, "pa ", k) : (k = buffer(c, "pa\n", k));
    return (k);
}

int main(const int ac, const char **av)
{
    int *a = malloc(ac < 50000 ? sizeof(int) * (ac / 2) * ac : 1);
    int *b = malloc(sizeof(int) * ac);
    char *c = malloc(ac < 50000 ? 4 * (ac / 2) * ac + ac + ac : 1);

    for (int i = 1; ac < 50000 && i != ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            (av[i][j] == '-') && (j++);
            a[i - 1 + ac / 4 * ac] *= 10;
            a[i - 1 + ac / 4 * ac] += av[i][j] - 48;
        }
        (av[i][0] == '-') && (a[i - 1 + ac / 4 * ac] *= -1);
    }
    for (int i = ac / 4 * ac; ac > 50000 || a[i] <= a[i + 1] || ac == 2; i++) {
        if (ac > 50000 || i + 1 == ac / 4 * ac + ac - 2 || ac == 2) {
            write(1, "\n", 1), free(a), free(b), free(c);
            return (0);
        }
    }
    write(1, c, push_swap(a, b, c, ac)), free(a), free(b), free(c);
    return (0);
}