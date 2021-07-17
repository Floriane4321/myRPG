/*
** EPITECH PROJECT, 2021
** change_obj_2.c
** File description:
** change object 2
*/

#include "gdata.h"
#include "m_event.h"
#include "object.h"
#include "fight.h"

char *get_name_attack(pokemon_t *pok, int nb);

void change_obj_condition_pok_player(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_1);
    char *str = get_status(pok);

    sfText_setString(obj->txt->text, str);
}

void change_obj_condition_pok_adv(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_2);
    char *str = get_status(pok);

    sfText_setString(obj->txt->text, str);
}

void change_obj_pokemon_player(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_1);

    obj->status = 0;
    if (pok->type == obj->name)
        obj->status = 1;
}

void change_obj_pokemon_adv(obj_const_t *obj, fight_data_t *f_data)
{
    pokemon_t *pok = get_current_pok(f_data->trainer_2);

    obj->status = 0;
    if (pok->type == obj->name)
        obj->status = 1;
}

void change_obj_name_attack_1(obj_const_t *obj, fight_data_t *f_da, event_t *e)
{
    pokemon_t *pok = get_current_pok(f_da->trainer_1);
    char *str = get_name_attack(pok, 0);

    sfText_setString(obj->txt->text, str);
    if (e->fight.fight == 1)
        obj->status = 1;
    else
        obj->status = 0;
}
