/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** parsing_map
*/

#include "map.h"

map_t *parsing_basic_textures(sfTexture **textures, char *buffer, int i,
                            map_t *map)
{
    if (buffer[i] == 'G')
        return (sprite_map_init(textures[TGRASS], 0));
    if (buffer[i] == 'C' && buffer[i + 1] == 'l')
        return (sprite_map_init(textures[TROAD], 180));
    if (buffer[i] == 'C' && buffer[i + 1] == 'r')
        return (sprite_map_init(textures[TROAD], 0));
    if (buffer[i] == 'C' && buffer[i + 1] == 'd')
        return (sprite_map_init(textures[TROAD], 90));
    if (buffer[i] == 'C' && buffer[i + 1] == 'u')
        return (sprite_map_init(textures[TROAD], 270));
    return (map);
}

map_t *parsing_road_textures(sfTexture **textures, char *buffer, int i,
                            map_t *map)
{
    if (buffer[i] == 'R' && buffer[i + 1] == 'l')
        return (sprite_map_init(textures[TROAD_TURN], 180));
    if (buffer[i] == 'R' && buffer[i + 1] == 'r')
        return (sprite_map_init(textures[TROAD_TURN], 0));
    if (buffer[i] == 'R' && buffer[i + 1] == 'd')
        return (sprite_map_init(textures[TROAD_TURN], 90));
    if (buffer[i] == 'R' && buffer[i + 1] == 'u')
        return (sprite_map_init(textures[TROAD_TURN], 270));
    return (map);
}

map_obs_t *parsing_obstacle(sfTexture **textures, char *buffer, int i,
                            map_obs_t *obs)
{
    if (buffer[i] == 'F' && (buffer[i + 1] == 'l' || buffer[i + 1] == 'r'))
        return (sprite_obs_init(textures[TFENCE_H], (sfVector2f){0, 0}, 2));
    if (buffer[i] == 'F' && (buffer[i + 1] == 'u' || buffer[i + 1] == 'd'))
        return (sprite_obs_init(textures[TFENCE_V], (sfVector2f){0, 0}, 2));
    if (buffer[i] == 'B')
        return (sprite_obs_init(textures[THGRASS], (sfVector2f){0, 0}, 5));
    if (buffer[i] == 'H')
        return (sprite_obs_init(textures[THOUSE], (sfVector2f){-34, -34}, 4));
    if (buffer[i] == 'T' && buffer[i + 1] != 's')
        return (sprite_obs_init(textures[TTHREE], (sfVector2f){0, -34}, 3));
    if (buffer[i] == 'T' && buffer[i + 1] == 's')
        return (sprite_obs_init(textures[TTHREE], (sfVector2f){-29, -34}, 3));
    return (obs);
}

map_t *parsing_map(sfTexture **textures, char *buffer, int i, map_t *map)
{
    if (map == NULL) {
        map = parsing_basic_textures(textures, buffer, i, map);
        map = parsing_road_textures(textures, buffer, i, map);
    }
    if (map != NULL) {
        map->obs = parsing_obstacle(textures, buffer, i, map->obs);
    }
    return (map);
}