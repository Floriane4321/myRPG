/*
** EPITECH PROJECT, 2021
** keyboard_seting.c
** File description:
** first file for set keyboard
*/

#include "gdata.h"
#include "utility.h"
#include "m_event.h"
#include "button.h"

void keybordset_left(level_t *lvl, event_t *even, button_t *but)
{
    even->keyseting = 1;
    even->numkey = KLEFT;
    even->set->but = but;
}

void keybordset_right(level_t *lvl, event_t *even, button_t *but)
{
    even->keyseting = 1;
    even->numkey = KRIGHT;
    even->set->but = but;
}

void keybordset_top(level_t *lvl, event_t *even, button_t *but)
{
    even->keyseting = 1;
    even->numkey = KTOP;
    even->set->but = but;
}

void keybordset_down(level_t *lvl, event_t *even, button_t *but)
{
    even->keyseting = 1;
    even->numkey = KDOWN;
    even->set->but = but;
}
