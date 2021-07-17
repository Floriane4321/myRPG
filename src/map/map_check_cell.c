/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** map_check_cell
*/

#include "map.h"

obs_type_t map_check_cell(int x, int y, map_t **map, map_info_t *m_info)
{
    int cell = y * m_info->line_size + x;
    int check_out = 1;

    if (cell < 0 || cell > m_info->cell_max || check_out == 0)
        return (OUT);
//    my_putstr("\nres: ");
//  my_put_nbr(map[cell]->obs_type);
//    my_putstr(" \n");
    return (map[cell]->obs_type);
}
