/*
** EPITECH PROJECT, 2021
** entity_col.c
** File description:
** test entity moveable
*/

#include "gdata.h"
#include "m_event.h"
#include "map.h"

obs_type_t map_check_cell(int x, int y, map_t **map, map_info_t *m_info);
void set_entity_dir(entity_t *entity, int dir);

int testing_map_cell(event_t *even, sfVector2i targ)
{
    obs_type_t res = map_check_cell(targ.x , targ.y , even->map, even->m_info);

    if (res == HIGH_GRASS || res == NOT_EXIST)
        return (0);
    return (1);
}

int player_is_move(event_t *even)
{
    if (even->player.moving == 1) {
        even->player.moving = 0;
        return (1);
    }
    return (0);
}

int is_amove(event_t *even, entity_t *entity)
{
    if (entity->etype == PNJ) {
        return (1);
    }
    if (entity->etype == PLAYER) {
        if (player_is_move(even) == 1) {
            set_entity_dir(entity, even->player.dir);
            return (1);
        }
    }
    return (0);
}

int is_arotat(event_t *even, entity_t *entity, sfVector2f old)
{
    if (entity->pos->dir.x == old.x && entity->pos->dir.y == old.y)
        return (0);
    return (1);
}
