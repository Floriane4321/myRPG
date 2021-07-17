/*
** EPITECH PROJECT, 2021
** handel_entity.c
** File description:
** all function for creat even by entity
*/

#include "gdata.h"
#include "m_event.h"
#include "my.h"

mctm_event_t *add_mctm_event_top(mctm_event_t *first, mctm_event_t *new);
mctm_event_t *mctm_event_create(void);

void handel_entity_destroy(event_t *even, entity_t *entity)
{
    mctm_event_t *new = mctm_event_create();

    new->type = ENTITY_DESTROY;
    new->to_free = entity;
    even->ev_list = add_mctm_event_top(even->ev_list, new);
}

void handel_crafting(event_t *even)
{
    mctm_event_t *new = mctm_event_create();

    new->type = CRAFTING;
    new->to_free = NULL;
    even->ev_list = add_mctm_event_top(even->ev_list, new);
}
