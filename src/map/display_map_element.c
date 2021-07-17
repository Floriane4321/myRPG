/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** display_map_element
*/

#include "map.h"

void display_map(map_t **map, sfRenderWindow *window)
{
    for (int i = 0; map[i] != NULL; i++) {
        sfRenderWindow_drawSprite(window,
        map[i]->sprite, NULL);
    }
}

void display_obs(map_obs_t *obs, sfRenderWindow *window)
{
    for (map_obs_t *node = obs; node != NULL; node = node->next) {
            sfRenderWindow_drawSprite(window,
            node->sprite, NULL);
    }
}