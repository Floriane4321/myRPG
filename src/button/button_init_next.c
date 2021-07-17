/*
** EPITECH PROJECT, 2021
** button_ini_next.c
** File description:
** fct button
*/

#include "gdata.h"
#include "utility.h"
#include "m_event.h"
#include "button.h"
#include "music.h"

void gt_mode_three(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = OPTION;
}

void gt_mode_inventory(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = INVENTORY;
}

void gt_mode_end(level_t *lvl, event_t *even, button_t *but)
{
    even->c_mode = END;
}

void play_music(level_t *lvl, event_t *even, button_t *but)
{
    if (but->print == 1) {
        even->music->play = 3;
        but->print = 0;
        but->status = 1;
    } else {
        even->music->play = 1;
        but->print = 1;
        but->status = 0;
    }
}

void vol_music(level_t *lvl, event_t *even, button_t *but)
{
    sfVector2f pos = sfSprite_getPosition(but->button);
    sfVector2f scale = sfSprite_getScale(but->button);
    int l = but->base.width * scale.x;
    int perc = 100 * (but->mouse.x - pos.x) / l;

    even->music->vol = perc;
    but->status = perc / 10;
    if (but->status >= 10)
        but->status = 9;
}
