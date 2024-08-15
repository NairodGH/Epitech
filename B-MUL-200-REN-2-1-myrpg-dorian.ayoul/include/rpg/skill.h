/*
** EPITECH PROJECT, 2021
** skill.h
** File description:
** RPG skill
*/

#ifndef RPG_SKILL_H
#define RPG_SKILL_H

typedef struct skill_s {
    char *name;
    char *type;
    int level;
    int usage;
    int attack;
} skill_t;

list_t *parse_skills(char const *xml);

list_t *load_skills(void);

#endif