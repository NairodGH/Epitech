/*
** EPITECH PROJECT, 2021
** time_utils.c
** File description:
** Time utils
*/

#include <rpg/rpg.h>
#include <stdlib.h>

PRIVATE int convert_hours(char **time, int raw)
{
    int hours = 0;
    char *plural = " hours";
    char *singular = " hour";
    char *appender = NULL;

    if (raw >= 3600) {
        hours = raw / 3600;
        raw -= hours * 3600;
        appender = hours > 1 ? plural : singular;
        *time = append_str(int_to_str(hours), appender);
    }
    return (raw);
}

PRIVATE int convert_minutes(char **time, int raw)
{
    int min = 0;
    char *plural = " mins";
    char *singular = " min";
    char *appender = NULL;

    if (raw / 60 > 0) {
        if (*time != NULL) {
            *time = append_str(*time, ", ");
        }
        min = raw / 60;
        raw -= min * 60;
        appender = min > 1 ? plural : singular;
        *time = append_str(*time, append_str(int_to_str(min), appender));
    }
    return (raw);
}

PRIVATE int convert_seconds(char **time, int raw)
{
    int sc = 0;
    char *plural = " secs";
    char *singular = " sec";
    char *appender = NULL;

    if (raw > 0) {
        if (*time != NULL) {
            *time = append_str(*time, ", ");
        }
        sc = raw;
        raw = 0;
        appender = sc > 1 ? plural : singular;
        *time = append_str(*time, append_str(int_to_str(sc), appender));
    }
    return (raw);
}

char *get_seconds_to_time(int seconds)
{
    char *time = NULL;
    int raw = seconds;

    if (raw < 0)
        return ("0 second");
    raw = convert_hours(&time, raw);
    raw = convert_minutes(&time, raw);
    raw = convert_seconds(&time, raw);
    if (time == NULL)
        return ("0 second");
    return (time);
}