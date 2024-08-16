/*
** EPITECH PROJECT, 2022
** init_game.c
** File description:
** init_game
*/

#include "includes.h"

static void end_c(Vector2 *nb_cac, Vector2 *nb_cac_s, cactus_t *cac, size_t i)
{
    cac[i].floor = -1;
    free(nb_cac);
    free(nb_cac_s);
}

static void end_e(Vector2 *nb_cac, Vector2 *nb_cac_s, electric_t *el, size_t i)
{
    el[i].floor = -1;
    free(nb_cac);
    free(nb_cac_s);
}

electric_t *init_elec(kidiot_t *kidiot)
{
    size_t i = 0;
    Vector2 *nb_cac = find_all_cell(kidiot->first_floor, 'E');
    Vector2 *nb_cac_s = find_all_cell(kidiot->second_floor, 'E');
    electric_t *elec = malloc(sizeof(electric_t) *
        (get_len_vect(nb_cac) + get_len_vect(nb_cac_s) + 1));

    for (size_t v = 0; i != get_len_vect(nb_cac); i++, v++) {
        elec[i].pos = nb_cac[v];
        elec[i].time = 5;
        elec[i].is_fixed = false;
        elec[i].floor = 0;
    }
    for (size_t v = 0, nb = 0; nb != get_len_vect(nb_cac_s); i++, v++, nb++) {
        elec[i].pos = nb_cac_s[v];
        elec[i].time = 5;
        elec[i].is_fixed = false;
        elec[i].floor = 1;
    }
    end_e(nb_cac, nb_cac_s, elec, i);
    return elec;
}

cactus_t *init_cactus(kidiot_t *kidiot)
{
    size_t i = 0;
    Vector2 *nb_cac = find_all_cell(kidiot->first_floor, 'C');
    Vector2 *nb_cac_s = find_all_cell(kidiot->second_floor, 'C');
    cactus_t *cactus = malloc(sizeof(cactus_t) *
        (get_len_vect(nb_cac) + get_len_vect(nb_cac_s) + 1));

    for (size_t v = 0; i != get_len_vect(nb_cac); i++, v++) {
        cactus[i].pos = nb_cac[v];
        cactus[i].time = 2;
        cactus[i].is_cut = false;
        cactus[i].floor = 0;
    }
    for (size_t v = 0, nb = 0; nb != get_len_vect(nb_cac_s); i++, v++, nb++) {
        cactus[i].pos = nb_cac_s[v];
        cactus[i].time = 2;
        cactus[i].is_cut = false;
        cactus[i].floor = 1;
    }
    end_c(nb_cac, nb_cac_s, cactus, i);
    return cactus;
}