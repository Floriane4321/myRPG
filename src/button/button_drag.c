/*
** EPITECH PROJECT, 2021
** button_drag.c
** File description:
** drag and click butoon
*/

#include "gdata.h"
#include "m_event.h"
#include "button.h"

void drag_click_swap(level_t *lvl, event_t *even, button_t *zip, sfVector2f pos)
{
    if (zip->blink == NULL && even->drag->blink == NULL) {
        even->drag->pos = sfSprite_getPosition(zip->button);
        zip->blink = even->drag;
        even->drag->blink = zip;
    } else if (zip->blink == NULL && even->drag->blink != NULL) {
        even->drag->pos = sfSprite_getPosition(zip->button);
        zip->blink = even->drag;
        even->drag->blink->blink = NULL;
        even->drag->blink = zip;
    }
}

void drag_click(level_t *lvl, event_t *even, button_t *zip)
{
    sfVector2f pos;

    if (even->drag != NULL) {
        pos = even->drag->pos;
        if (zip->blink != NULL && even->drag->blink == NULL) {
            even->drag->pos = sfSprite_getPosition(zip->button);
            zip->blink->pos = pos;
            zip->blink->blink = NULL;
            zip->blink = even->drag;
            even->drag->blink = zip;
        } else if (zip->blink != NULL && even->drag->blink != NULL) {
            even->drag->pos = sfSprite_getPosition(zip->button);
            zip->blink->pos = pos;
            zip->blink->blink = even->drag->blink;
            even->drag->blink->blink = zip->blink;
            zip->blink = even->drag;
            even->drag->blink = zip;
        }
        drag_click_swap(lvl, even, zip, pos);
    }
    even->drag = NULL;
}

void click_drag(level_t *lvl, event_t *even, button_t *but)
{
    even->drag = but;
    even->drag->pos = sfSprite_getPosition(even->drag->button);
}

void drag_craft_s1(level_t *lvl, event_t *even, button_t *ziip)
{
    sfVector2f pos;

    if (even->drag == NULL)
        return;
    drag_click(lvl, even, ziip);
    even->craft.item1 = ziip->blink->item;
}

void drag_craft_s2(level_t *lvl, event_t *even, button_t *ziip)
{
    if (even->drag == NULL)
        return;
    drag_click(lvl, even, ziip);
    even->craft.item2 = ziip->blink->item;
}
