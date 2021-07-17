/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** fonction list basic
*/

#include "mylist_obj.h"
#include "object.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

list_t *my_params_to_list(int ac, char *const *av)
{
    list_t *element;
    list_t *list = NULL;

    for (int i = ac - 1; i > 0; i--) {
        element = malloc(sizeof(list_t));
        element->data = av[i];
        element->next = list;
        list = element;
    }
    return (list);
}

int my_list_size(obj_const_t *begin)
{
    int i = 0;

    while (begin != NULL) {
        i++;
        begin = begin->next;
    }
    return (i);
}

void put_list(list_t *list)
{
    list_t *tmp = list;

    while (tmp != NULL)  {
        if (tmp->rdc != NULL)
            my_putstr(tmp->rdc);
        my_putstr(tmp->data);
        my_putchar(10);
        tmp = tmp->next;
    }
}

obj_const_t *create_cell(char *data, char *rdc)
{
    obj_const_t *cell = malloc(sizeof(obj_const_t));

    if (!cell)
        return (NULL);
    return (cell);
}

obj_const_t *addcell(obj_const_t *list, int i, char *data, char *rdc)
{
    obj_const_t *now = list;
    obj_const_t *element;
    obj_const_t *cell = create_cell(data, rdc);

    if (list == NULL)
        return (cell);
    element = now->next;
    if (i < 0 || my_list_size(list) <= i)
        return (add_end_obj(list, cell));
    if (i == 0) {
        cell->next = list;
        return (cell);
    }
    for (int j = 0; j < i; j++) {
        element = now;
        now = now->next;
    }
    element->next = cell;
    cell->next = now;
    return (list);
}
