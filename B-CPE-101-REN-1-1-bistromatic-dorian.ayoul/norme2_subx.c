/*
** EPITECH PROJECT, 2020
** norme epitech
** File description:
** 2
*/

int *check_ret_subb(int *result, int z, int *tab2, int *tabg);

int my_strlen3_sub(int *tab)
{
    int i = 0;

    while (tab[i] != 'f')
        i++;
    return (i);
}

int my_strcmp_int(int *s1, int *s2)
{
    int i = 0;

    while (s1[i] != 'f' && s2[i] != 'f' && s1[i] == s2[i]) {
        i++;
    }
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    else
        return (0);
}

int *norme_equal(int *tab, int *tab2, int *result, int i)
{
    int z = i + 1;

    i = 0;
    while (tab2[i] != 'f') {
        result = check_ret_subb(result, z, tab2, tab);
        result[z] = result[z] + (tab[i] - tab2[i]);
        i++;
        z++;
    }
    result[z] = 'f';
    return (result);
}
