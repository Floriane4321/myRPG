/*
** EPITECH PROJECT, 2021
** change_obj_1.c
** File description:
** change object 1
*/

#include "object.h"
#include "fight.h"
#include <stdio.h>
void obj_const_update_color(sfSprite *s, int stat, int max);

void change_obj_pv_player(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_1);

    obj->stat = get_pv(pok);
    obj->max = get_pv_max(pok);
    obj_const_update_display(obj->sprite, obj->rect, obj->stat, obj->max);
    obj_const_update_color(obj->sprite, obj->stat, obj->max);
}

void change_obj_pv_adv(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_2);

    obj->stat = get_pv(pok);
    obj->max = get_pv_max(pok);
    obj_const_update_display(obj->sprite, obj->rect, obj->stat, obj->max);
    obj_const_update_color(obj->sprite, obj->stat, obj->max);
}

void change_obj_name_pok_player(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_1);
    char *str = get_name_pok(pok);

    sfText_setString(obj->txt->text, str);
}

void change_obj_name_pok_adv(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_2);
    char *str = get_name_pok(pok);

    sfText_setString(obj->txt->text, str);
}

void change_obj_exp_pok(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_2);

    obj->stat = get_exp(pok);
    obj->max = get_exp_max(pok);
    obj_const_update_display(obj->sprite, obj->rect, obj->stat, obj->max);
}
