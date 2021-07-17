/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** place_map_flag
*/

#include "map.h"

int check_line_size(char *buffer, int i)
{
    int n = i;
    int line_size = 0;

    while (n > 0 && buffer[i] != '\n') {
        n--;
    }
    if (n != 0)
        n++;
    for (int x = n; buffer[x] != '\n' && buffer[x] != '\0'; x++) {
        if (buffer[x] == ';')
            line_size++;
    }
    return (line_size);
}

void flag_position(map_t **map, int i, char *buffer, obs_type_t type)
{
    int line_size = check_line_size(buffer, i);
    int pos_1 = i;
    int pos_2 = i + 1;
    int pos_3 = line_size + i;
    int pos_4 = line_size + (i + 1);

    map[pos_1]->obs_type = type;
    map[pos_2]->obs_type = type;
    map[pos_3]->obs_type = type;
    map[pos_4]->obs_type = type;
}

void parsing_map_flag(map_t **map, int i, map_obs_t *obs, char *buffer)
{
    if (obs->type == FENCE)
        map[i]->obs_type = FENCE;
    if (obs->type == THREE)
        flag_position(map, i, buffer, THREE);
    if (obs->type == HOUSE)
        flag_position(map, i, buffer, HOUSE);
    if (obs->type == HIGH_GRASS)
        map[i]->obs_type = HIGH_GRASS;
}

void place_map_flag(map_t **map, char *buffer)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (map[i]->obs != NULL) {
            parsing_map_flag(map, i, map[i]->obs, buffer);
        }
    }
}
