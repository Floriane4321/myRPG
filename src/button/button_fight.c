/*
** EPITECH PROJECT, 2021
** button_fight.c
** File description:
** button fight
*/

#include "gdata.h"
#include "utility.h"
#include "m_event.h"
#include "button.h"
#include "music.h"

void change_color_text(button_list_t *blist, mod_t scene)
{
    button_t *but = blist->first;

    if (scene == FIGHT) {
        while (but != NULL) {
            sfText_setFillColor(but->text, sfBlack);
            but = but->next;
        }
    }
}

void swap_view_2(level_t *lvl, event_t *even, button_t *zip)
{
    sfVector2f new = sfView_getCenter(lvl->ui);

    new.x = new.x - 1280;
    if (new.x <= -(1280 * 2) + 640)
        new.x = 640;
    sfView_setCenter(lvl->ui, new);
}

void pok_attack(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.fight = 1;
    swap_view_2(lvl, even, but);
}

void pok_choise(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.fight = 2;
}

void pok_escape(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.fight = 3;
}
