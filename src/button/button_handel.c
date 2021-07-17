/*
** EPITECH PROJECT, 2020
** button_handel.c
** File description:
** button_update function
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "gdata.h"
#include "m_event.h"
#include "rpg.h"
#include "utility.h"
#include "button.h"

void button_draw(sfRenderWindow *window, button_list_t *list)
{
    button_t *button = list->first;

    while (button != NULL) {
        if (button->status != -1) {
            sfRenderWindow_drawSprite(window, button->button, NULL);
            sfRenderWindow_drawText(window, button->text, NULL);
        }
        button = button->next;
    }
}

void anim_button_manag(button_t *tmp, float delta)
{
    sfIntRect new = {0, 0, 0, 0};

    if (tmp->status >= tmp->nbr_anim)
        tmp->status = 0;
    new.left = tmp->base.left + tmp->status * tmp->base.width;
    new.top = tmp->base.top;
    new.width = tmp->base.width;
    new.height = tmp->base.height;
    sfSprite_setTextureRect(tmp->button, new);
}

void update_button(event_t *even, level_t *lvl, float delta)
{
    button_list_t *list = lvl->blist;
    button_t *tmp = list->first;
    sfIntRect new = {0, 0, 0, 0};
    sfVector2f tpos;

    while (tmp != NULL) {
        anim_button_manag(tmp, delta);
        if (tmp != even->drag) {
            sfSprite_setPosition(tmp->button, tmp->pos);
            tpos.x = tmp->pos.x + 10;
            tpos.y = tmp->pos.y + 5;
            sfText_setPosition(tmp->text, tpos);
        }
        tmp = tmp->next;
    }
}

void test_button_clecked(level_t *lvl, sfVector2f mouse, event_t *even)
{
    button_list_t *list = lvl->blist;
    button_t *tmp = list->first;
    sfFloatRect rect;

    while (tmp != NULL) {
        rect = sfSprite_getGlobalBounds(tmp->button);
        if (cmp_vector(mouse, rect) == 1 && tmp->type == FULL) {
            tmp->status = 2;
        }
        if (cmp_vector(mouse, rect) == 1 && (tmp->type == SPE ||
        tmp->type == DRAG)) {
            tmp->mouse = mouse;
            tmp->action(lvl, even, tmp);
        }
        tmp = tmp->next;
    }
}

void test_button_released(level_t *lvl, sfVector2f mouse, event_t *even)
{
    button_list_t *list = lvl->blist;
    button_t *tmp = list->first;
    sfFloatRect rect;

    while (tmp != NULL) {
        rect = sfSprite_getGlobalBounds(tmp->button);
        if (cmp_vector(mouse, rect) == 1 && tmp->type != SPE &&
        tmp->type != DRAG) {
            tmp->mouse = mouse;
            tmp->action(lvl, even, tmp);
            tmp->status = 0;
        }
        tmp = tmp->next;
    }
    if (even->drag != NULL) {
        sfSprite_setPosition(even->drag->button, even->drag->pos);
        even->drag = NULL;
    }
}

void test_button_hedel(level_t *lvl, sfVector2f mouse, event_t *even)
{
    button_list_t *list = lvl->blist;
    button_t *tmp = list->first;
    sfFloatRect rect;

    while (tmp != NULL) {
        if ((tmp->type != FULL && tmp->type != HEDEL) ||
            (tmp->type == FULL && tmp->status >= 2)) {
            tmp = tmp->next;
            continue;
        }
        rect = sfSprite_getGlobalBounds(tmp->button);
        if (cmp_vector(mouse, rect) == 1)
            tmp->status = 1;
        else if (tmp->status == 1) {
            tmp->status = 0;
        }
        tmp = tmp->next;
    }
}
