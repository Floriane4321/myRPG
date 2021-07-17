/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** list_obs
*/

#include "map.h"

map_obs_t *list_obs_init(map_t **map)
{
    map_obs_t *prev = NULL;
    map_obs_t *first = NULL;

    for (int i = 0; map[i] != NULL; i++) {
        if (map[i]->obs != NULL && prev == NULL) {
            prev = map[i]->obs;
            first = prev;
            continue;
        }
        if (map[i]->obs != NULL && prev != NULL) {
            prev->next = map[i]->obs;
            prev = prev->next;
        }
    }
    return (first);
}