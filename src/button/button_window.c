/*
** EPITECH PROJECT, 2021
** button_window.c
** File description:
** buton for risize the window
*/

#include "gdata.h"
#include "m_event.h"
#include "button.h"

void wind_resiz_low(level_t *lvl, event_t *even, button_t *but)
{
    even->win_size = (sfVector2u){640, 360};
}

void wind_resiz_med(level_t *lvl, event_t *even, button_t *but)
{
    even->win_size = (sfVector2u){1280, 720};
}

void wind_resiz_hig(level_t *lvl, event_t *even, button_t *but)
{
    even->win_size = (sfVector2u){1920, 1080};
}
