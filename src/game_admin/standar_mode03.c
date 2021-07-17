/*
** EPITECH PROJECT, 2021
** standar_mode03.c
** File description:
** gameset function 2
*/

#include "gdata.h"
#include "my.h"
#include "m_event.h"
#include "stdio.h"

void player_update(event_t *even, player_t *player, float delta);
void update_entity(event_t *even, list_entity_t *entity, float delta);
void update_pokemon(event_t *even, fight_data_t *fight);
void update_obj_const(event_t *even, obj_const_t *obj, fight_data_t *fight);
void update_button(event_t *even, level_t *lvl, float delta);

void gamemode_fight(event_t *even, rpg_t *data, float delta)
{
    update_obj_const(even, data->lvl[FIGHT].obj_const, data->fight);
    update_pokemon(even, data->fight);
}

void gamemode_inventory(event_t *even, rpg_t *data, float delta)
{
    update_button(even, &data->lvl[INVENTORY], delta);
}
