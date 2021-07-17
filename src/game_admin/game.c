/*
** EPITECH PROJECT, 2020
** standart_game01.c
** File description:
** function for game01
*/

#include "my.h"
#include "gdata.h"
#include "entity.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "utility.h"
#include "m_event.h"

void handel_entity_destroy(event_t *even, entity_t *entity);
void entity_display(sfRenderWindow *win, list_entity_t *list);
void display_obj_const(sfRenderWindow *window, obj_const_t *obj);

void spaun_creature(rpg_t *rpg, gdata_t *data);

void update_music(music_t *music, texture_t *drw);

void draw_game(gdata_t *data)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_setView(data->window, data->rpg->lvl[data->mode].game);
    if (data->mode == MODE1) {
        display_map(data->rpg->map, data->window);
        display_obs(data->rpg->obs_list, data->window);
    }
    entity_display(data->window, data->rpg->lvl[data->mode].entity);
    if (data->mode == FIGHT)
        display_obj_const(data->window, data->rpg->lvl[data->mode].obj_const);
    sfRenderWindow_setView(data->window, data->rpg->lvl[data->mode].ui);
    display_obj_const(data->window, data->rpg->lvl[data->mode].obj_const);
    button_draw(data->window, data->rpg->lvl[data->mode].blist);
    sfRenderWindow_drawSprite(data->window, data->m_event->cursor, NULL);
    sfRenderWindow_display(data->window);
    sfRenderWindow_setView(data->window, data->rpg->lvl[data->mode].ui);
}

void update_game(event_t *even, rpg_t *rpg, float delta, mod_t scene)
{
    update_music(even->music, rpg->drw);
}
