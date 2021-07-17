/*
** EPITECH PROJECT, 2020
** gdata.c
** File description:
** function gdata
*/

#include "gdata.h"
#include <stdlib.h>

gdata_t *gdata_create(void)
{
    gdata_t *data = malloc(sizeof(struct gdata_s) * 1);

    data->mode = MENU;
    data->window = NULL;
    data->origin = NULL;
    data->m_event = NULL;
    data->rpg = NULL;
    data->clock = NULL;
    data->delta.microseconds = 0;
    data->status = 0;
    return (data);
}

void gdata_destroy(gdata_t *data)
{
    gdata_t *new = data;

    sfClock_destroy(new->clock);
    rpg_destroy(new->rpg);
    sfRenderWindow_destroy(new->window);
    free(new);
    data = NULL;
}
