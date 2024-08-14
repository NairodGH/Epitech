/*
** EPITECH PROJECT, 2020
** norme
** File description:
** evalexpr
*/

int my_operator(int *stockint, int s, int *result, int a);

int my_operator_par(int *result, int a)
{
    int i = a;
    int *save = result;

    while (save[i] != 'f') {
        if (save[i] == 111111)
            result[a] = result[a] + save[i + 1];
        if (save[i] == 111112)
            result[a] = result[a] * save[i + 1];
        if (save[i] == 111113)
            result[a] = result[a] - save[i + 1];
        if (save[i] == 111114)
            result[a] = result[a] / save[i + 1];
        if (save[i] == 111115)
            result[a] = result[a] % save[i + 1];
        i++;
    }
    return (result[a]);
}

int my_calcul_par(int *stockint, int *result, int s, int a)
{
    int *me = stockint;
    int c = a;

    while (stockint[s] != 111117) {
        result[a] = me[s];
        if (stockint[s] == 111114 || stockint[s] == 111112
            || stockint[s] == 111115) {
            a--;
            stockint[s - 1] = result[a];
            result[a] = my_operator(stockint, s, result, a);
            s++;
        }
        a++;
        s++;
    }
    result[a] = 'f';
    result[a] = my_operator_par(result, c);
    return (result[a]);
}

int check_first(int z, int a)
{
    if (z > 0)
        a--;
    return (a);
}

int check_par(int *stockint, int s)
{
    int c = s;

    s++;
    while (stockint[s] != 111117) {
        if (stockint[s] == 111116) {
            c = c + 1;
            break;
        }
        s++;
    }
    s--;
    return (c);
}

int my_p(int *stockint, int s)
{
    int p = 0;
    int c = 0;

    c = s;
    s = check_par(stockint, s);
    if (s != c)
        return (1);
    return (0);
}
