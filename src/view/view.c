/*
** EPITECH PROJECT, 2021
** view.c
** File description:
** view fct
*/

#include "gdata.h"

void set_speview(level_t *lvl)
{
    sfVector2f new = {-640, 360};

    sfView_setCenter(lvl[MODE1].ui, new);
    lvl[OPTION].nb = 3;
}

void swap_view_l(level_t *lvl, event_t *even, button_t *zip)
{
    sfVector2f new = sfView_getCenter(lvl->ui);

    new.x = new.x - 1280;
    if (new.x <= -(1280 * lvl->nb) + 640)
        new.x = 640;
    sfView_setCenter(lvl->ui, new);
}

void swap_view_r(level_t *lvl, event_t *even, button_t *zip)
{
    sfVector2f new = sfView_getCenter(lvl->ui);

    new.x = new.x + 1280;
    if (new.x > 640)
        new.x = -(1280 * (lvl->nb - 1)) + 640;
    sfView_setCenter(lvl->ui, new);
}
