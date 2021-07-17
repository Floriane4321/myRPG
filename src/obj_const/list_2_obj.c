/*
** EPITECH PROJECT, 2020
** list_2.c
** File description:
** fonction base of list
*/

#include "mylist_obj.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "object.h"

void free_list(obj_const_t *list)
{
    obj_const_t *tmp = list;
    obj_const_t *now = tmp;

    while (tmp != NULL) {
        now = now->next;
        free(tmp);
        tmp = now;
    }
}

obj_const_t *free_cell(obj_const_t *list, int i)
{
    obj_const_t *now = list;
    obj_const_t *element = list;

    if (i < 0 || my_list_size(list) <= i)
        return (NULL);
    if (i == 0) {
        list = list->next;
        free(now);
        return (list);
    }
    for (int j = 0; j < i; j++) {
        element = now;
        now = now->next;
    }
    element->next = now->next;
    free(now);
    return (list);
}

obj_const_t *add_begin(obj_const_t *list, obj_const_t *cell)
{
    cell->next = list;
    return (cell);
}

obj_const_t *add_end_obj(obj_const_t *list, obj_const_t *cell)
{
    obj_const_t *tmp = list;

    cell->next = NULL;
    if (list == NULL)
        return (cell);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = cell;
    return (list);
}

obj_const_t *reverse(obj_const_t *list)
{
    obj_const_t *bef = NULL;
    obj_const_t *now = list;
    obj_const_t *next;

    while (now != NULL) {
        next = now;
        now = now->next;
        next->next = bef;
        bef = next;
    }
    now = bef;
    while (now != NULL)
        now = now->next;
    return (bef);
}
