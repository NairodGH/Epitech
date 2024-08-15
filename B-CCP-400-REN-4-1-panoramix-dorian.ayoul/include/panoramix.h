/*
** EPITECH PROJECT, 2022
** panoramix.h
** File description:
** panoramix
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct villager_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    sem_t *sem;
    long *pot;
    size_t nb_fights;
    size_t id;
} villager_t;

typedef struct druid_s {
    pthread_t thread;
    pthread_mutex_t *mutex;
    long *pot;
    size_t pot_size;
    size_t nb_refills;
} druid_t;

typedef struct village_s {
    villager_t *villagers;
    druid_t druid;
} village_t;

#define USAGE "./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>"
#define BAD_ARGS "Values must be >0."
#define NEG_OR_0 av[i][0] == '-' || !(params[i - 1] = strtol(av[i], &check, 10))
#define ARGS_ERROR fprintf(stderr, "USAGE: %s\n%s\n", USAGE, BAD_ARGS) * 0 + 84
#define DEADLOCK_ERROR fprintf(stderr, "Arguments would deadlock.\n") * 0 + 84
#define CHECK(func) if (func) return 84

#define TOTAL_FIGHTS params[0] * params[2]
#define TOTAL_SERVINGS params[1] * (params[3] + 1)
#define VILLAGER_DEADLOCK TOTAL_FIGHTS > TOTAL_SERVINGS
#define DRUID_DEADLOCK TOTAL_SERVINGS - TOTAL_FIGHTS >= params[1]