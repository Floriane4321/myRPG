/*
** EPITECH PROJECT, 2021
** button_attack.c
** File description:
** fonction of each buttons attack
*/

#include "gdata.h"
#include "utility.h"
#include "m_event.h"
#include "button.h"
#include "music.h"

void swap_view_2(level_t *lvl, event_t *even, button_t *zip);

void attack_1(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.attack_id = 1;
    swap_view_2(lvl, even, but);
}

void attack_2(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.attack_id = 2;
    swap_view_2(lvl, even, but);
}

void attack_3(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.attack_id = 3;
    swap_view_2(lvl, even, but);
}

void attack_4(level_t *lvl, event_t *even, button_t *but)
{
    even->fight.attack_id = 4;
    swap_view_2(lvl, even, but);
}
