/*
** EPITECH PROJECT, 2021
** mouse_anim.c
** File description:
** animation for the mouse
*/

#include "gdata.h"
#include "m_event.h"

void update_mouse_cursor(event_t *even, sfVector2f new)
{
    if (even->drag != NULL) {
        sfSprite_setPosition(even->drag->button, new);
        sfSprite_setPosition(even->cursor, (sfVector2f){-1000, -1000});
    } else {
        new.x = new.x - 10;
        new.y = new.y - 10;
        sfSprite_setPosition(even->cursor, new);
    }
}
