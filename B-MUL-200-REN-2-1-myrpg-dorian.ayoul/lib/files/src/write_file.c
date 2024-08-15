/*
** EPITECH PROJECT, 2021
** write_file.c
** File description:
** Write in file
*/

#include <file_utils.h>
#include <nep/nstring.h>

bool write_file(char *file, char *content)
{
    FILE *fl;

    if (file == NULL || content == NULL)
        return (false);
    fl = fopen(file, "w+");
    if (fl == NULL)
        return (false);
    fwrite(content, nstrlen(content), 1, fl);
    fclose(fl);
    return true;
}