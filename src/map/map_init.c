/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** map_init
*/

#include "map.h"

void place_texture_map(map_t **map, int col, int line, int n)
{
    map[n]->pos.x = (col * 64) + 32;
    map[n]->pos.y = (line * 64) + 32;
    sfSprite_setPosition(map[n]->sprite,
    map[n]->pos);
    if (map[n]->obs != NULL) {
        map[n]->obs->pos.x = (col * 64) + map[n]->obs->pos.x;
        map[n]->obs->pos.y = (line * 64) + map[n]->obs->pos.y;
        sfSprite_setPosition(map[n]->obs->sprite,
        map[n]->obs->pos);
    }
}

map_t **map_create(char *buffer, sfTexture **textures, map_t **map)
{
    int col = 0;
    int line = 0;
    int n = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n') {
            col = 0;
            line++;
            continue;
        }
        map[n] = parsing_map(textures, buffer, i, map[n]);
        if (map[n] != NULL && buffer[i] == ';') {
            place_texture_map(map, col, line, n);
            n++;
            col++;
        }
    }
    return (map);
}

int case_nbr(char *buffer)
{
    int case_nbr = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';')
            case_nbr++;
    }
    return (case_nbr);
}

map_t **map_init(char *buffer, sfTexture **textures, map_info_t *map_info)
{
    int len = my_strlen(buffer);
    map_t **map = NULL;

    len = case_nbr(buffer) + 1;
    map = malloc(sizeof(map_t *) * len);
    for (int i = 0; i < len; i++)
        map[i] = NULL;
    map = map_create(buffer, textures, map);
    place_map_flag(map, buffer);
    get_map_info(buffer, map_info);
    return (map);
}