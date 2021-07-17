/*
** EPITECH PROJECT, 2021
** button_item.c
** File description:
** item crator
*/
#include "my.h"
#include "button.h"
#include <stdlib.h>

void handel_crafting(event_t *even);

void click_craft(level_t *lvl, event_t *even, button_t *but)
{
    handel_crafting(even);
}

item_t *item_creat(button_t *but, char *name)
{
    item_t *new = malloc(sizeof(item_t));

    new->name = my_strdup(name);
    new->link = but;
    but->item = new;
    sfText_setCharacterSize(but->text, 32);
    sfText_setString(but->text, name);
    sfText_setColor(but->text, sfRed);
    return (new);
}

item_t *init_item(button_t *but, char *name)
{
    if (but->type == DRAG)
        return (item_creat(but, name));
    return (NULL);
}

void destroy_item(item_t *item)
{
    button_t *but = item->link;

    free(item->name);
    free(item);
}
