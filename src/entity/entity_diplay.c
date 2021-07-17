/*
** EPITECH PROJECT, 2021
** entity_display.c
** File description:
** function for display my entity
*/

#include <SFML/Graphics.h>
#include "entity.h"

void enitity_find_and_display(sfRenderWindow *win, list_entity_t *list, int z)
{
    for (list_entity_t *start = list; start != NULL; start = start->next) {
        if (start->entity->z == z)
            sfRenderWindow_drawSprite(win, start->entity->sprite, NULL);
    }
}

void entity_display(sfRenderWindow *win, list_entity_t *list)
{
    for (int z = 0; z != 4; z++)
        enitity_find_and_display(win, list, z);
}
