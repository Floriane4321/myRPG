/*
** EPITECH PROJECT, 2020
** m_event.c
** File description:
** file of struc my_event
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "gdata.h"
#include "m_event.h"
#include "my.h"
#include <stdio.h>
#include "m_view.h"

void test_button_clecked(level_t *lvl, sfVector2f mouse, event_t *even);
void test_keyboard(level_t *lvl, event_t *even, sfRenderWindow *window);
void test_click(level_t *lvl, event_t *even, gdata_t *data);
void fight_engine(fight_data_t *fight);
void ev_crafting(gdata_t *data, mctm_event_t *ev);
void test_released(level_t *lvl, event_t *even, gdata_t *data);
keyboard_set_t *creat_keyboard(void);
mctm_event_t *free_mctm_event(mctm_event_t *list);
void ev_entity_destroy(gdata_t *data, mctm_event_t *ev);
void test_hedel(level_t *lvl, event_t *even, gdata_t *data);
void swap_keyboard(event_t *even, gdata_t *data);
ev_fight_t ini_event_fight(void);

void update_data(event_t *even, gdata_t *data)
{
    if (even->close == 1)
        data->status = 1;
    if (even->c_mode != data->mode)
        data->mode = even->c_mode;
    while (even->ev_list != NULL) {
        if (even->ev_list->type == ENTITY_DESTROY)
            ev_entity_destroy(data, even->ev_list);
        if (even->ev_list->type == CRAFTING)
            ev_crafting(data, even->ev_list);
        even->ev_list = free_mctm_event(even->ev_list);
    }
    even->map = data->rpg->map;
    even->m_info = data->rpg->m_info;
    sfRenderWindow_setSize(data->window, even->win_size);
}

void update_event(event_t *even, gdata_t *data, level_t *lvl)
{
    sfRenderWindow *win = data->window;

    while (sfRenderWindow_pollEvent(win, &(even->even))) {
        if (even->even.type == sfEvtMouseButtonPressed)
            test_click(lvl, even, data);
        if (even->even.type == sfEvtMouseButtonReleased)
            test_released(lvl, even, data);
        if (even->even.type == sfEvtMouseMoved)
            test_hedel(lvl, even, data);
        if (even->even.type == sfEvtClosed)
            even->close = 1;
        if (even->keyseting == 1 && even->even.type == sfEvtKeyPressed)
            swap_keyboard(even, data);
        else if (even->even.type == sfEvtKeyPressed)
            test_keyboard(lvl, even, win);
    }
}

void m_event_update(event_t *even, gdata_t *data)
{
    update_event(even, data, &data->rpg->lvl[data->mode]);
    update_data(even, data);
    fight_engine(data->rpg->fight);
}

event_t *m_event_create(void)
{
    event_t *new = malloc(sizeof(struct event_s));

    new->close = 0;
    new->c_mode = MENU;
    new->ev_list = NULL;
    new->music = NULL;
    new->numkey = 0;
    new->keyseting = 0;
    new->set = creat_keyboard();
    new->drag = NULL;
    new->craft.item1 = NULL;
    new->craft.item2 = NULL;
    new->craft.res = NULL;
    new->fight = ini_event_fight();
    new->win_size = (sfVector2u){1280, 720};
    return (new);
}
