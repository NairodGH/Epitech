/*
** EPITECH PROJECT, 2022
** panoramix.c
** File description:
** panoramix
*/

#include "panoramix.h"

bool drink(villager_t villager)
{
    pthread_mutex_lock(villager.mutex);
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    villager.id, (*(villager.pot)));
    if ((*(villager.pot)) == 0) {
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
        villager.id);
        (*(villager.pot))--;
        pthread_mutex_unlock(villager.mutex);
        return false;
    }
    (*(villager.pot))--;
    pthread_mutex_unlock(villager.mutex);
    return true;
}

void *villager_thread(void *addr)
{
    villager_t villager = *(villager_t *)addr;

    printf("Villager %d: Going into battle !\n", villager.id);
    while (1) {
        if ((*(villager.pot)) == -1 || !drink(villager))
            continue;
        sem_wait(villager.sem);
        villager.nb_fights--;
        printf("Villager %d: Take that roman scum! Only %d left\n",
        villager.id, villager.nb_fights);
        sem_post(villager.sem);
        if (villager.nb_fights == 0) {
            printf("Villager %d: I'm going to sleep now.\n", villager.id);
            return NULL;
        }
    }
}

void *druid_thread(void *addr)
{
    druid_t druid = *(druid_t *)addr;

    printf("Druid: I'm ready... but sleepy...\n");
    while (1) {
        if ((*(druid.pot)) == -1) {
            pthread_mutex_lock(druid.mutex);
            druid.nb_refills--;
            printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
            printf("Beware I can only make %d more refills after this one.\n",
            druid.nb_refills);
            (*(druid.pot)) = druid.pot_size;
            pthread_mutex_unlock(druid.mutex);
        }
        if (druid.nb_refills == 0) {
            printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
            return NULL;
        }
    }
}

int panoramix(villager_t *villagers, druid_t druid, size_t nb)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    sem_t sem;

    druid.pot_size = *druid.pot;
    druid.mutex = &mutex;
    for (size_t i = 0; i < nb; i++) {
        villagers[i].mutex = &mutex;
        villagers[i].sem = &sem;
    }
    CHECK(sem_init(&sem, 0, 1));
    CHECK(pthread_create(&(druid.thread), NULL, druid_thread, &druid));
    for (size_t i = 0; i < nb; i++)
        CHECK(pthread_create(&(villagers[i].thread), NULL, villager_thread,
        &villagers[i]));
    CHECK(pthread_join(druid.thread, NULL));
    for (size_t i = 0; i < nb; i++)
        CHECK(pthread_join(villagers[i].thread, NULL));
    CHECK(pthread_mutex_destroy(&mutex));
    CHECK(sem_destroy(&sem));
    return 0;
}

int main(int ac, char **av)
{
    char *check;
    size_t params[4];
    village_t village;

    if (ac != 5)
        return ARGS_ERROR;
    for (size_t i = 1; i < 5; i++)
        if (NEG_OR_0 || check == av[i] || *check != '\0')
            return ARGS_ERROR;
    if (VILLAGER_DEADLOCK || DRUID_DEADLOCK)
        return DEADLOCK_ERROR;
    village.villagers = malloc(sizeof(villager_t) * params[0]);
    for (size_t i = 0; i < params[0]; i++) {
        village.villagers[i].pot = &params[1];
        village.villagers[i].nb_fights = params[2];
        village.villagers[i].id = i;
    }
    village.druid.pot = &params[1];
    village.druid.nb_refills = params[3];
    return panoramix(village.villagers, village.druid, params[0]);
}
