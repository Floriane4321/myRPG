/*
** EPITECH PROJECT, 2021
** button_list.c
** File description:
** list_button
*/

#include "button.h"
#include <stdlib.h>

button_list_t *list_button_sup(button_list_t *list, button_t *but)
{
    if (list->first == but) {
        list->first = but->next;
        button_destroy(but);
        return (list);
    }
    for (button_t *start = list->first; start != NULL; start = start->next) {
        if (start->next == but) {
            start->next = but->next;
            button_destroy(but);
            return (list);
        }
    }
    return (list);
}

void list_button_destroy(button_list_t *list)
{
    button_t *tmp;
    button_t *curent;

    while (tmp != NULL) {
        tmp = curent;
        curent = curent->next;
        button_destroy(tmp);
    }
    free(list);
}

button_list_t *list_button_creat(void)
{
    button_list_t *new = malloc(sizeof(button_list_t));

    new->len = 0;
    new->first = NULL;
    return (new);
}
