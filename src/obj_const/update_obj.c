/*
** EPITECH PROJECT, 2021
** update_obj.c
** File description:
** fonction update object const
*/

#include "object.h"

void change_obj_pokemon_player(obj_const_t *obj, fight_data_t *f_data);
void change_obj_name_attack_1(obj_const_t *obj, fight_data_t *f_da,
                            event_t *e);
void change_obj_pokemon_adv(obj_const_t *obj, fight_data_t *f_data);

void obj_const_update_color(sfSprite *s, int stat, int max)
{
    sfColor color = {0, 0, 0, 255};
    int g_now = 255;
    int r_now = 0;
    float perc = stat * 100 / max;

    if (max != 0 && perc >= 80) {
        g_now = 255;
        r_now = (100 - perc) * 255 * 0.4 / 100;
    }
    if (max != 0 && perc < 80 && perc >= 30) {
        r_now = (80 - perc) * 255 * 1.94 / 100;
        g_now = 255 - ((80 - perc) * 255 * 1.06 / 100);
    }
    if (max != 0 && perc < 30) {
        g_now = (30 - perc) * 255 * 0.94 / 100;
        r_now = 255;
    }
    color.r = r_now;
    color.g = g_now;
    sfSprite_setColor(s, color);
}

void obj_const_update_display(sfSprite *s, sfIntRect rect, int stat, int max)
{
    sfColor color = {0, 255, 0, 255};
    int x = stat * rect.width / max;

    rect.width = x;
    sfSprite_setTextureRect(s, rect);
}

void check_type_obj_next(obj_const_t *now, fight_data_t *f_data, event_t *even)
{
    if (now->type == POK_PLY)
        change_obj_pokemon_player(now, f_data);
    if (now->type == POK_ADV)
        change_obj_pokemon_adv(now, f_data);
    if (now->type == NAME_ATT_1)
        change_obj_name_attack_1(now, f_data, even);
}

void check_type_obj(obj_const_t *now, fight_data_t *f_data, event_t *even)
{
    if (now->type == VIDE)
        return;
    if (now->type == PV_POK_PLY)
        change_obj_pv_player(now, f_data);
    if (now->type == PV_POK_ADV)
        change_obj_pv_adv(now, f_data);
    if (now->type == NAME_POK_PLY)
        change_obj_name_pok_player(now, f_data);
    if (now->type == NAME_POK_ADV)
        change_obj_name_pok_adv(now, f_data);
    if (now->type == BARRE_EXP)
        change_obj_exp_pok(now, f_data);
    if (now->type == ETAT_POK_PLY)
        change_obj_condition_pok_player(now, f_data);
    if (now->type == ETAT_POK_ADV)
        change_obj_condition_pok_adv(now, f_data);
    if (now->type == TEXT)
        change_obj_text(now, f_data);
    check_type_obj_next(now, f_data, even);
}

void update_obj_const(event_t *even, obj_const_t *obj, fight_data_t *fight)
{
    obj_const_t *tmp = obj;

    while (tmp != NULL) {
        check_type_obj(tmp, fight, even);
        tmp = tmp->next;
    }
}
