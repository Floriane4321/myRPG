/*
** EPITECH PROJECT, 2021
** button.c
** File description:
** button prime function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rpg.h"
#include "utility.h"

button_t *button_creat(sfIntRect r, sfTexture *t, sfVector2f ps, sfVector2f si)
{
    button_t *new = malloc(sizeof(button_t));

    new->button = sfSprite_create();
    sfSprite_setTexture(new->button, t, sfTrue);
    sfSprite_setTextureRect(new->button, r);
    sfSprite_setPosition(new->button, ps);
    sfSprite_setScale(new->button, si);
    new->pos = ps;
    new->status = 0;
    new->time = 0;
    new->base = r;
    new->print = 1;
    new->next = NULL;
    new->item = NULL;
    new->blink = NULL;
    return (new);
}

void button_destroy(button_t *button)
{
    sfSprite_destroy(button->button);
    free(button);
}

button_list_t *add_button(button_list_t *list, button_t *button)
{
    list->len++;
    button->next = list->first;
    list->first = button;
    return (list);
}
