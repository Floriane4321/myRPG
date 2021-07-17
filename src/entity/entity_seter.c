/*
** EPITECH PROJECT, 2021
** entity_seter.c
** File description:
** seter for set an entity
*/

#include "gdata.h"
#include "m_event.h"
#include "entity.h"

void set_entity_dir(entity_t *entity, int dir)
{
    entity->pos->dir.x = 0;
    entity->pos->dir.y = 0;
    if (dir == DOWN)
        entity->pos->dir.y = 1;
    if (dir == TOP)
        entity->pos->dir.y = -1;
    if (dir == RIGHT)
        entity->pos->dir.x = 1;
    if (dir == LEFT)
        entity->pos->dir.x = -1;
}

void set_entity_rotat(entity_t *entity)
{
    pos_t *pos = entity->pos;
    int statu = 0;

    if (pos->dir.y == 1)
        pos->col = 0;
    if (pos->dir.x == -1)
        pos->col = 1;
    if (pos->dir.x == 1)
        pos->col = 2;
    if (pos->dir.y == -1)
        pos->col = 3;
    entity->pos->rect.top = pos->col * entity->pos->mod.y;
}
