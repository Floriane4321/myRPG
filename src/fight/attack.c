/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-nicolas.saclier
** File description:
** attack
*/

#include "fight.h"

void copy_attack_data(attack_t *dest, attack_t *src)
{
    dest->power = src->power;
    dest->accuracy = src->accuracy;
    my_strcpy(dest->name, src->name);
    my_strcpy(dest->attype, src->attype);
    dest->type = src->type;
}

void create_attack(attack_t **list, attack_t *new, attackname_t name)
{
    for (int i = 0; list[i] != NULL; i++) {
        if (list[i]->type == name) {
            copy_attack_data(new, list[i]);
            return;
        }
    }
}

void attack_init(pokemon_t *pokemon, fight_data_t *fight)
{
    attack_t **list = fight->list_attack;

    parse_attacks_pt1(pokemon, list);
}
