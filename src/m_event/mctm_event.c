/*
** EPITECH PROJECT, 2021
** mctm_event.c
** File description:
** my_custom event
*/

#include "gdata.h"
#include "m_event.h"
#include <stdlib.h>

mctm_event_t *mctm_event_create(void)
{
    mctm_event_t *new = malloc(sizeof(struct mctm_event_s));

    new->type = 0;
    new->to_free = NULL;
    new->next = NULL;
    return (new);
}

mctm_event_t *add_mctm_event_top(mctm_event_t *first, mctm_event_t *new)
{
    mctm_event_t *tmp = first;

    if (first == NULL)
        return (new);
    while (first->next != NULL)
        first = first->next;
    first->next = new;
    return (tmp);
}

mctm_event_t *free_mctm_event(mctm_event_t *list)
{
    mctm_event_t *tmp = list;

    if (list->next == NULL) {
        free(tmp);
        return (NULL);
    }
    list = list->next;
    free(tmp);
    return (list);
}
