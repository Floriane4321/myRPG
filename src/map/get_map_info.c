/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** get_map_info
*/

#include "map.h"

void get_map_info(char *buffer, map_info_t *map_info)
{
    map_info->cell_max = case_nbr(buffer);
    map_info->line_size = check_line_size(buffer, 0);
}