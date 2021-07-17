/*
** EPITECH PROJECT, 2021
** defender.c
** File description:
** list of entity
*/

#include "entity.h"
#include <stdlib.h>

void entity_destroy(list_entity_t *enti);

list_entity_t *list_entity_addbot(list_entity_t *list, entity_t *entity)
{
    list_entity_t *new = malloc(sizeof(list_entity_t));

    if (list != NULL)
        list->old = new;
    new->old = NULL;
    new->entity = entity;
    new->next = list;
    return (new);
}

void set_ptr(list_entity_t *tmp)
{
    if (tmp->next != NULL)
        tmp->next->old = tmp;
}

list_entity_t *test_antisegfault(list_entity_t * start)
{
    if (start->next == NULL)
        return (NULL);
    start->old = NULL;
    return (start->next);
}

list_entity_t *list_entity_sup(list_entity_t *list, entity_t *ref)
{
    list_entity_t *tmp = NULL;

    if (list == NULL || ref == NULL)
        return (list);
    for (list_entity_t *start = list; start != NULL; start = start->next) {
        if (start->entity == ref && tmp != NULL) {
            tmp = start->old;
            tmp->next = start->next;
            set_ptr(tmp);
            entity_destroy(start);
            break;
        } else if (start->entity == ref && tmp == NULL) {
            tmp = test_antisegfault(start);
            entity_destroy(start);
            return (tmp);
        }
        tmp = start;
    }
    return (list);
}
