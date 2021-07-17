/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** map_texture_init
*/

#include "map.h"

map_t *sprite_map_init(sfTexture *texture, float angle)
{
    map_t *background = malloc(sizeof(map_t));

    background->pos = (sfVector2f){0, 0};
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, texture, 0);
    sfSprite_setScale(background->sprite, (sfVector2f){2, 2});
    sfSprite_setOrigin(background->sprite, (sfVector2f){16, 16});
    sfSprite_setRotation(background->sprite, angle);
    background->obs = NULL;
    background->obs_type = NOT_EXIST;
    return (background);
}

map_obs_t *sprite_obs_init(sfTexture *texture, sfVector2f pos, obs_type_t obs)
{
    map_obs_t *background = malloc(sizeof(map_obs_t));

    background->sprite = sfSprite_create();
    background->pos = pos;
    background->type = obs;
    sfSprite_setTexture(background->sprite, texture, 0);
    sfSprite_setScale(background->sprite, (sfVector2f){2, 2});
    background->next = NULL;
    return (background);
}
