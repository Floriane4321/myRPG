/*
** EPITECH PROJECT, 2020
** standar_mode02.c
** File description:
** gameset function
*/

#include "gdata.h"
#include "my.h"
#include "m_event.h"
#include "stdio.h"

void player_update(event_t *even, player_t *player, float delta);
void update_entity(event_t *even, list_entity_t *entity, float delta);
void update_obj_const(event_t *even, obj_const_t *obj, fight_data_t *fight);
void update_button(event_t *even, level_t *lvl, float delta);
void update_game(event_t *even, rpg_t *rpg, float delta, mod_t scene);

void gamemode_menu(event_t *even, rpg_t *data, float delta)
{
    update_button(even, &data->lvl[MENU], delta);
    update_entity(even, data->lvl[MENU].entity, delta);
    update_obj_const(even, data->lvl[MENU].obj_const, data->fight);
}

void gamemode_pause(event_t *even, rpg_t *data, float delta)
{
    update_entity(even, data->lvl[PAUSE].entity, delta);
    update_obj_const(even, data->lvl[PAUSE].obj_const, data->fight);
}

void gamemode_option(event_t *even, rpg_t *data, float delta)
{
    update_button(even, &data->lvl[OPTION], delta);
    update_entity(even, data->lvl[OPTION].entity, delta);
    update_obj_const(even, data->lvl[OPTION].obj_const, data->fight);
}

void game_sesion_one(event_t *even, rpg_t *data, float delta)
{
    sfVector2f new = sfSprite_getPosition(data->player->entity->sprite);

    new.x = new.x - 32;
    new.y = new.y - 32;
    update_game(even, data, delta, MODE1);
    update_entity(even, data->lvl[MODE1].entity, delta);
    update_obj_const(even, data->lvl[MODE1].obj_const, data->fight);
    sfView_setCenter(data->lvl[MODE1].game, new);
}

void game_end(event_t *even, rpg_t *data, float delta)
{
    update_obj_const(even, data->lvl[END].obj_const, data->fight);
    update_button(even, &data->lvl[END], delta);
}
